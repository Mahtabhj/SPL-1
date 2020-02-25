#include<stdio.h>
#include<string.h>

int main()
{

   char ch,str[1000];
   FILE *fptr;

   fptr = fopen("i.txt","r");
   if(fptr == NULL)
   {
      printf("Error!");
      exit(1);
   }
   int i=0,j=0;
     while ((ch = fgetc(fptr)) != EOF)
        {
           str[i]=ch;
           printf("%c",str[i]);
           i++;
        }

        int c=0;
   for(i =0 ;i<strlen(str);i++)
   {
       if(str[i]=='i'&&str[i+1]=='n'&&str[i+2]=='t'&&str[i+3]==' ')
       {

           for(j=i+3;str[j]!=';';j++)
           {
               if(str[j]=='('&&str[j+1]==')')
               {
                   break;
                   i=i+3;
               }
               if(str[j]==',')
               {
                    c = c+1;
               }
           }
           c=c+1;
             if(str[j]=='('&&str[j+1]==')')
               {
                   c=c-1;
               }
           i=i+5;
       }

       else if(str[i]=='c'&&str[i+1]=='h'&&str[i+2]=='a'&&str[i+3]=='r'&&str[i+4]==' ')
       {
             for(j=i+3;str[j]!=';';j++)
           {
               if(str[j]=='('&&str[j+1]==')')
               {
                   break;
                   i=i+3;
               }
               if(str[j]==',')
               {
                    c = c+1;
               }
           }
           c=c+1;
           if(str[j]=='('&&str[j+1]==')')
               {
                   c=c-1;
               }
           i=i+5;
       }
       else if(str[i]=='d'&&str[i+1]=='o'&&str[i+2]=='u'&&str[i+3]=='b'&&str[i+4]=='l'&&str[i+5]=='e'&&str[i+6]==' ')
       {
             for(j=i+3;str[j]!=';';j++)
           {
               if(str[j]=='('&&str[j+1]==')')
               {
                   break;
                   i=i+3;
               }
               if(str[j]==',')
               {
                    c = c+1;
               }
           }
           c=c+1;
             if(str[j]=='('&&str[j+1]==')')
               {
                   c=c-1;
               }
           i=i+5;
       }
        else if(str[i]=='f'&&str[i+1]=='l'&&str[i+2]=='o'&&str[i+3]=='a'&&str[i+4]=='t'&&str[i+5]==' ')
       {
             for(j=i+3;str[j]!=';';j++)
           {
               if(str[j]=='('&&str[j+1]==')')
               {
                   break;
                   i=i+3;
               }
               if(str[j]==',')
               {
                    c = c+1;
               }
           }
           c=c+1;
             if(str[j]=='('&&str[j+1]==')')
               {
                   c=c-1;
               }
           i=i+5;
       }

   }
   printf("\n%d",c);
   fclose(fptr);
}
