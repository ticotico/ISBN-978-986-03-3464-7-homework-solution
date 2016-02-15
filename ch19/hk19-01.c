#include <stdio.h>
#ifndef Date
typedef struct {
	int year;
	int month;
	int day;
}Date;
#endif //Date

#ifdef MMDDYY
  #ifndef print_date
    #define print_date(date) printf("%02d/%02d/%04d\n", date.month, date.day, date.year);
  #endif //print_date
#endif //MMDDYY

#ifdef DDMMYY
  #ifndef print_date
    #define print_date(date) printf("%02d/%02d/%04d\n", date.day, date.month, date.year);
  #endif //print_date
#endif //DDMMYY

#ifdef YYMMDD
  #ifndef print_date
    #define print_date(date) printf("%04d/%02d/%02d\n", date.year, date.month, date.day);
  #endif //print_date
#endif //YYMMDD

#ifndef print_date
  #define print_date(date) 0
#endif //print_date

int main (void)
{
	Date date;
	while (scanf("%d%d%d", &(date.year), &(date.month), &(date.day)) != EOF)
		print_date(date);
	
	return 0;
}
