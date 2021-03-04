//Autor: Mark Goldmann
//Erstelldatum: 11.01.21
//Text: Day of the Year


#include <stdio.h>
#include <stdlib.h>
#include "bibiothek.h"


int main()
{
    struct date values;


    printf("*** Day of the year ***\n");

    //Aufruf der Funktion aus der Bibiothek.c
    //und speichern in eine Variable
    values = input_date();

    //Kontrolle ob das Datum existiert
    if(exists_date(values) == 0)
    {
        printf("Date is invalid.\n");
    }
    else
    {
        //Übergabewert der Funktion day_of_the_year
        int day_of_year = day_of_the_year(values);
        printf("Today is the %i day of the year.", day_of_year);
    }

    return 0;
}

