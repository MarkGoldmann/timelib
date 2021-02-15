//Autor: Mark Goldmann
//Erstelldatum: 11.01.21
//Text: Tag des Jahres


#include <stdio.h>
#include <stdlib.h>
#include "bibiothek.h"


int main()
{
    //Deklaration der Variablen
    int day = 0;
    int month = 0;
    int year = 0;

    printf("*** Tag des Jahres ***\n");

    //Aufruf der Funktion aus der Bibiothek.c
    input_date(&day,&month,&year);

    //Kontrolle ob das Datum existiert
    if(exists_date(day, month, year) == 0)
    {
        printf("Datum ist ungueltig.\n");
    }
    else
    {
        int tag_des_jahres = day_of_the_year(day, month, year);
        printf("Heute ist der %i Tag des Jahres.", tag_des_jahres);
    }

    return 0;
}

