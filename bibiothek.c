//Funktion für die Eingabe der Daten
int input_date(int *dayz1,int *monthz2,int *yearz3)
{
    printf("Geben Sie das Jahr ein:");
    scanf("%i",yearz3);

    printf("Geben Sie den Monat ein:");
    scanf("%i",monthz2);

    printf("Geben Sie den Tag ein:");
    scanf("%i",dayz1);

}

//Funktion zur Berechnung des Tag des Jahres und
// ob das Angegebene Daten existiert
int day_of_the_year(int day, int month, int year)
{
    int schaltjahr = 0;
    int ret = 0;

    //Wenn Das Datum nicht existiert wird -1 zurückgegeben
    if(exists_date(day, month, year)== 0)
    {
        return -1;
    }

    ret += day;


    for (int i = 1; i < month ; i++)
    {
        ret += get_days_for_month(i, year); // get_per_month
    }


    int Number_of_day = ret;

    return Number_of_day;
}

//Funktion zur Berechnung des Schaltjahres
int is_leapyear(int year)
{
    if(year % 4 == 0)
    {
        if(year % 100 == 0)
        {
            if(year % 400 == 0)
            {
            }
        }
        //Hier wird 1 zurückgegeben und in der Funktion
        //day_of_the_year gegebenenfalls dazuaddiert
        return 1;
    }
    else
    {
        if(year % 4 == 0)
        {
            if(year % 100 != 0)
            {

            }
            return 1;
        }
        else
        {
            if(year < 1582)
            {
                //Hier wird der Wert -1 an die Funktion get_days_for_month
                //übergeben
                return -1;
            }
            else
            {
                return 0;
            }
        }
    }
}

//Funktion zum Übergeben der Anzahl der Tage des
//jeweiligen Monats
int get_days_for_month(int month, int year)
{
    int anzahl_von_tagen = 0;
    int schaltjahr = 0;

    schaltjahr = is_leapyear(year);
    int tage_pro_monat[] = {31,28,31,30,31,30,31,31,30,31,30,31};

    if(schaltjahr == 1)
    {
        tage_pro_monat[1] = 29;
    }
    else
    {
        //Übergabewert der Funktion is_leapyyear
        if(schaltjahr == -1)
        {
            printf("ungueltiges Jahr");
        }
    }

    anzahl_von_tagen += tage_pro_monat[month-1];

    return anzahl_von_tagen;

}

//Funktion zur Berechnung ob das Datum existiert und im Rahmen ist
int exists_date(int day, int month, int year)
{

    if(year > 1581 && year < 2401)
    {
        if(month >= 1 && month <= 12)
        {
            if(day >= 1 && day <= get_days_for_month(month, year))
            {
                return 1;
            }
        }
    }
    return 0;

}

