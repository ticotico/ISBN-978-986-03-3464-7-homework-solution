/*
以下整理第 11 章中的字串處理函式原型。
請思考哪些 char * 參數前可以加上 const
，那些不行。
*/
int strlen (const char *string);
char *strcpy (char *dest, const char *source);
char *strcat (char *dest, const char *source);
char *strncpy (char *dest, const char *source, const int i);
char *strncat (char *dest, const char *source, const int i);
int strcmp (const char *str1, const char *str2);
int strncmp (const char *str1, const char * str2, const int i);
char *strchr (const char *string, const int c);
char *strrchr (const char *string, const int c);
char *strspn (const char *string, const char *chars);
char *strcspn (const char *string, const char *chars);
char *strstr (const char *string1, const char *string2);
char *strtok (char *string, const char delimeters);
