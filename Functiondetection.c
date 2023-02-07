#include<stdio.h>
#include<string.h>

int main()
{
      FILE *fptr;
      char c[100];
      char *intf="int";
      char v;
      char *charf = "char";
      char *doublef = "double";
      char *floatf = "float";
      char *semicolon=";";
      char *bracket1 ="(";
      char *bracket2 = ")";
      fptr = fopen("i.txt","r");
      if(fptr == NULL)
   {
      printf("Error!");

   }

     int i,k=0;
     char intfunction[100];
      while(fgets(c, sizeof(c), fptr))
    {
      if(strstr(c, intf) != NULL&& strstr(c, semicolon)== NULL && strstr(c, bracket1)!= NULL&&strstr(c, bracket2)!=NULL)
      {
          for(i=0;;i++)
       {
           if(c[i]=='i'&&c[i+1]=='n'&&c[i+2]=='t'&&c[i+3]==' ')
           {
               i=i+3;
               break;
           }
       }
       for(i=i+1;;i++)
       {
           if(c[i]=='(')
           {
               intfunction[k]='/';
               k++;
               break;
           }
           intfunction[k]=c[i];
           k++;
       }
      }

    }

    printf("Integers funtions are = ");
    for(i=0;i<k;i++)
    {

        if(intfunction[i]=='/')
        {

            printf(" , ");
            continue;
        }
         printf("%c",intfunction[i]);
    }
    fclose(fptr);
}
