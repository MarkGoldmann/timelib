//Autor: Mark Goldmann
//Erstelldatum: 27.02.2021
//Text: Funktionsprototypen & struktur

#ifndef BIBIOTHEK_H_INCLUDED
#define BIBIOTHEK_H_INCLUDED

//Initialisierung der Struktur
struct date
{
    int year;
    int month;
    int day;
};

//Funktionsprototypen
int exists_date(struct date x);
int day_of_the_year(struct date x);
int is_leapyear(int year);
int get_days_for_month(int month, int year);
struct date input_date();


#endif // BIBIOTHEK_H_INCLUDED
