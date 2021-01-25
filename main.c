//Autor: Mark Goldmann
//Erstelldatum: 11.01.21
//Text: Tag des Jahres


#include <stdio.h>
#include <stdlib.h>


int main()
{
    int month = 0;
    int year= 0;
    int day = 0;


    printf("Geben Sie das Jahr ein:");
    scanf("%i",&year);

    printf("Geben Sie den Monat ein:");
    scanf("%i",&month);

    printf("Geben Sie den Tag ein:");
    scanf("%i",&day);

    if (exists_date(day, month, year) == 0)
    {
        printf("Datum ist ungueltig.\n");
    }
    else
    {
        int tag_des_jahres = day_of_the_year(day, month, year);

        printf("Heute ist der %i Tag des Jahres.", tag_des_jahres);

    }





}

int day_of_the_year(int day, int month, int year, int Number_of_day)
{
    int schaltjahr = 0;
    int ret = 0;
    int tage_pro_monat[] = {31,28,31,30,31,30,31,31,30,31,30,31};

    schaltjahr = is_leapyear(year);
    ret += day;


    for (int i = 0; i < month -1; i++)
    {
        ret += tage_pro_monat[i];
    }

    if(schaltjahr == 1 && month >= 3)
    {
        ret += schaltjahr;
    }
    else
    {
        if(schaltjahr == -1)
        {
            printf("ungueltiges Jahr");
        }
    }


    if(day > tage_pro_monat[month - 1])
    {
        printf("ungueltiger Tag.\n");
        return 0;
    }
    Number_of_day = ret;

    return Number_of_day;
}

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
                return -1;
            }
            else
            {
                return 0;
            }
        }
    }
}
//MUss noch überarbeitet werden
int get_days_for_month(int month, int year)
{
  int anzahl_von_tagen = 0;

  int schaltjahr = is_leapyear(year);
  int tage_pro_monat[] = {31,28,31,30,31,30,31,31,30,31,30,31};

  if(schaltjahr == 1)
  {
      tage_pro_monat[1] = 29;
  }

  anzahl_von_tagen += tage_pro_monat[month];

  return anzahl_von_tagen;

}

int exists_date(int day, int month, int year)
{

  if(year > 1581 && year < 2401)
  {
      return 1;
  }
  else
  {
      return 0;
  }
}
