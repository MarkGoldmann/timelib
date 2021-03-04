//Autor: Mark Goldmann
//Erstelldatum: 27.03.2021
//Text: Funktionsbibiothek


#include "bibiothek.h"


//Funktion für die Eingabe der Daten
struct date input_date()
{
    struct date x;

    printf("Enter the year:");
    scanf("%i",&x.year);

    printf("Enter the month:");
    scanf("%i",&x.month);

    printf("Enter the day:");
    scanf("%i",&x.day);

    return x;

}

//Funktion zur Berechnung des Tag des Jahres und
// ob das Angegebene Daten existiert
int day_of_the_year(struct date x)
{
    int leapyear = 0;
    int ret = 0;

    //Wenn Das Datum nicht existiert wird -1 zurückgegeben
    if(exists_date(x)== 0)
    {
        return -1;
    }

    ret += x.day;


    for (int i = 1; i < x.month ; i++)
    {
        //Die Tage der Monate werden dazu addiert in eine Variable
        ret += get_days_for_month(i, x.year);
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
        //day_of_the_year gegebenenfalls dazu addiert
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
    int amount_of_days = 0;
    int leapyear = 0;

    leapyear = is_leapyear(year);
    int days_a_month[] = {31,28,31,30,31,30,31,31,30,31,30,31};

    if(leapyear == 1)
    {
        days_a_month[1] = 29;
    }
    else
    {
        //Übergabewert der Funktion is_leapyyear
        if(leapyear == -1)
        {
            printf("incorrent year");
        }
    }

    amount_of_days += days_a_month[month-1];

    return amount_of_days;

}

//Funktion zur Berechnung ob das Datum existiert und im Rahmen ist
int exists_date(struct date x)
{

    if(x.year > 1581 && x.year < 2401)
    {
        if(x.month >= 1 && x.month <= 12)
        {
            if(x.day >= 1 && x.day <= get_days_for_month(x.month, x.year))
            {
                return 1;
            }
        }
    }
    return 0;

}

