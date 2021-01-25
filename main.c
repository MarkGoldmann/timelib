//Autor: Mark Goldmann
//Erstelldatum: 11.01.21
//Text: Tag des Jahres


#include <stdio.h>
#include <stdlib.h>


int main()
{
    int tage_pro_monat[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int monat = 0;
    int jahr = 0;
    int tag = 0;

    printf("Geben Sie das Jahr ein:");
    scanf("%i",&jahr);

    printf("Geben Sie den Monat ein:");
    scanf("%i",&monat);

    printf("Geben Sie den Tag ein:");
    scanf("%i",&tag);


    int schaltjahr = 0;

    if(jahr % 4 == 0)
    {
        if(jahr % 100 == 0)
        {
            if(jahr % 400 == 0)
            {
            }
        }
        schaltjahr = 1;
    }
    else
    {
        if(jahr % 4 == 0)
        {
            if(jahr % 100 != 0)
            {

            }
            schaltjahr = 1;
        }
    }

    int ret = 0;
    ret += tag;

    for (int i = 0; i < monat -1; i++)
    {
        ret += tage_pro_monat[i];
    }

    if(schaltjahr == 1 && monat >= 3)
    {
        ret += schaltjahr;
    }


    if(tag > tage_pro_monat[monat - 1])
    {
        printf("ungueltige Eingabe.");
    }
    else
    {
        printf("Heute ist der %i Tag des Jahres.", ret);
    }


    return 0;
}
