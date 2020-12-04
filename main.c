#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#define size 80
int main()
{
    setlocale(LC_ALL,"Rus");
    char *str, *istr, *last, *str_copy, *str_copy_2, *str_copy_3;

    str_copy=(char*)malloc(sizeof(char)*size);
    last=(char*)malloc(sizeof(char)*size);
    str=(char*)malloc(sizeof(char)*size);
    str_copy_2=(char*)malloc(sizeof(char)*size);
    str_copy_3=(char*)malloc(sizeof(char)*size);

    printf("Введите строку\n");

    FILE *f;

    f=fopen("help.txt","w");
    fgets(str,size,stdin);
    fputs(str,f);
    fclose(f);

    f=fopen("help.txt", "r");
    fgets(str,size,f);

    strcpy(str_copy, str);
    strcpy(str_copy_2, str);
    strcpy(str_copy_3, str);

    printf("Строка без пробелов\n");
    istr=strtok(str," ");
    while (istr!= NULL)
    {
        fputs(istr, stdout);
        istr=strtok (NULL, " ");

    }

    printf("Строка без последнего слова\n");
    char *a=strtok(str_copy_2," .");
    while (a!=NULL)
    {
        last=a;
        a=strtok (NULL," .");
    }

    printf("last %s\n",last);

    char *p=strtok(str_copy_3," .");

    while (p!=NULL)
    {
        if (strcmp(p,last)!=0)
        {
            fputs(p, stdout);
        }
        p=strtok(NULL," .");
    }

    fclose(f);

    return 0;

}
