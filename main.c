#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#define size 80
int main()
{
    setlocale(LC_ALL,"Rus");
    char *str, *istr, *last, *str_copy, *str_copy_2, *str_copy_3, *str_copy_4, *tikva;

    str_copy=(char*)malloc(sizeof(char)*size);
    last=(char*)malloc(sizeof(char)*size);
    str=(char*)malloc(sizeof(char)*size);
    str_copy_2=(char*)malloc(sizeof(char)*size);
    str_copy_3=(char*)malloc(sizeof(char)*size);
    str_copy_4=(char*)malloc(sizeof(char)*size);
    tikva=(char*)malloc(sizeof(char)*size);

    printf("Введите строку\n");

    FILE *f;

    f=fopen("help.txt","w");
    fgets(str,size,stdin);
    fputs(str,f);
    fclose(f);

    f=fopen("help.txt", "r");
    fscanf(f,"%[^\n]",str);

    strcpy(str_copy, str);
    strcpy(str_copy_2, str);
    strcpy(str_copy_3, str);

    printf("Строка без пробелов\n");
    istr=strtok(str," ");

    while (istr!= NULL)
    {
        fputs(istr, stdout);
        istr=strtok (NULL, " ");
        if (istr!=NULL && strcmp(".",istr)!=0)
        {
            printf(" ");
        }
    }

    printf("\n Строка без последнего слова\n");
    char *a=strtok(str_copy_2," .");
    while (a!=NULL)
    {
        last=a;
        a=strtok (NULL," .");
    }

    char *p=strtok(str_copy_3," .");
    int h=0;
    while (p!=NULL)
    {
        if (strcmp(p,last)!=0)
        {
            fprintf(stdout,"%s ",p);
            for(int i=0; i<strlen(p); i++)
            {
                str_copy_4[h]=p[i];
                h++;

            }
            str_copy_4[h]=' ';
            h++;
        }
        p=strtok(NULL," .");
    }
    str_copy_4[h]='\0';


    printf("\n Строка со словами без повторов первой буквы \n");

    int i=1,k=0;
    char *c=strtok(str_copy_4," .");
    while (c!= NULL)
    {
        tikva[k]=c[0];
        for(i=1; i<strlen(c); i++)
        {
            if (c[i]!=c[0])
            {
                k++;
                tikva[k]=c[i];
            }

        }
        tikva[k+1] =' ';
        k+=2;
        c=strtok (NULL, " .");
    }
    tikva[k]='\0';
    fprintf(stdout,"%s",tikva);

    fclose(f);

    return 0;

}
