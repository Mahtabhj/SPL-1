#include <stdio.h>
#include <stdlib.h>
#include<string.h>
typedef struct{
 char method_name[100];
 char variables_name[100][100];
 char return_type[100];
 char call_function[100][100];
}funtion_ast[100];

      char *intf="int";
      char *charf = "char";
      char *doublef = "double";
      char *floatf = "float";
      char *semicolon=";";
      char *bracket1 ="(";
      char *bracket2 = ")";
int line = 0;
int menu[100];
char filestring[100][100];
char function_name[100][100];
int findfunction();
void findvariable();
int findstart();
int findend();
void find_returntype();
void function_parameter();
void find_loop();
void called();
void function_menu();

void function_menu(char name[100])
{
    int s=findstart(name);
    int end=findend(name,s);


}
void called(int name)
{
    int i=findstart(name);
    int end = findend(name,i);
    printf("\n");
    for(i=i+1;i<end;i++)
    {
        int j=0;
        for(;j<2;j++)
        {
            if(strstr(filestring[i],function_name[j])!=NULL)
            {
                char news[100];
                strcpy(news,function_name[j]);
                strcat(news,"(");

                if(strstr(filestring[i],news)!=NULL)
                {
                    printf("%s\n",function_name[j]);
                }
                menu[i]=3;
            }
        }
    }
}

void find_loop(int starting,int ending)
{
     int i=0,end=ending;
    char *bri="(";
    char *brf=")";
    int count =0;
    for(i=starting;i<end;i++)
    {

      if(strstr(filestring[i], "else if")!=NULL&& strstr(filestring[i], "(")!=NULL && strstr(filestring[i], ")")!=NULL&& strstr(filestring[i], ";")==NULL)
      {
          menu[i]=2;
          printf("\nelse if condition : ");
          for(int j=0;;j++)
          {
              if(filestring[i][j]=='(')
              {
                  int k=j;
                  for(;;k++)
                  {
                      if(filestring[i][k]=='\0')
                      {
                          break;
                      }
                      printf("%c",filestring[i][k]);
                  }
              }
              else if(filestring[i][j]=='\0')
              {
                  break;
              }

          }
           printf("\n");
      }
      else if(strstr(filestring[i], "if")!=NULL&& strstr(filestring[i], "(")!=NULL && strstr(filestring[i], ")")!=NULL&& strstr(filestring[i], ";")==NULL)
      {
          menu[i]=2;
          printf("\nif condition : ");
          for(int j=0;;j++)
          {
              if(filestring[i][j]=='(')
              {
                  int k=j;
                  for(;;k++)
                  {
                      if(filestring[i][k]=='\0')
                      {
                          break;
                      }
                      printf("%c",filestring[i][k]);
                  }
              }
              else if(filestring[i][j]=='\0')
              {
                  break;
              }

          }
           printf("\n");
      }
      else if(strstr(filestring[i], "while")!=NULL&& strstr(filestring[i], "(")!=NULL && strstr(filestring[i], ")")!=NULL)
      {
          menu[i]=2;
          char news[100];
                strcpy(news,"while");
                strcat(news,"(");
                if(strstr(filestring[i],news)!=NULL)
                {
                   printf("\nwhile condition : ");
          for(int j=0;;j++)
          {
             if(filestring[i][j]=='(')
              {
                  int k=j;
                  for(;;k++)
                  {
                      if(filestring[i][k]=='\0')
                      {
                          break;
                      }
                      printf("%c",filestring[i][k]);
                  }
              }
              else if(filestring[i][j]=='\0')
              {
                  break;
              }

          }
           printf("\n");
                }

      }


}
}
void function_parameter(int number)
{

           char c[100];
           char intp[100][100];
           int int_count=0,j=0;
           int i=0;
           strcpy(c,filestring[number]);
           printf("%s",c);
           for(i=0;;i++)
       {
           if(c[i]=='(')
           {
               break;
           }
       }
      for(;;i++)
      {
          if(c[i]==')')
        {
            break;
        }
          if(c[i]=='i'&&c[i+1]=='n'&&c[i+2]=='t')
          {
              i=i+4;
              for(;;i++)
              {
                  if(c[i]==',')
                  {
                      break;
                  }
                  if(c[i]==')')
                  {
                      i--;
                      break;
                  }

                  intp[int_count][j]=c[i];
                  j++;
              }
              int_count++;
              j=0;
          }
      }
      printf("Integer parameters are = ");
      for(i=0;i<int_count;i++)
      {
          printf("\n%s\n",intp[i]);
      }
}
void find_returntype(int starting)
{
    char type[20];
    char c[100];
    strcpy(c,filestring[starting]);
    if(strstr(c, intf) != NULL&& strstr(c, semicolon)== NULL && strstr(c, bracket1)!= NULL&&strstr(c, bracket2)!=NULL)
    {
        strcpy(type,"int");

    }
    else if(strstr(c, charf) != NULL&& strstr(c, semicolon)== NULL && strstr(c, bracket1)!= NULL&&strstr(c, bracket2)!=NULL)
    {
        strcpy(type,"char");
    }
    else if(strstr(c, doublef) != NULL&& strstr(c, semicolon)== NULL && strstr(c, bracket1)!= NULL&&strstr(c, bracket2)!=NULL)
    {
        strcpy(type,"double");
    }
    else if(strstr(c, floatf) != NULL&& strstr(c, semicolon)== NULL && strstr(c, bracket1)!= NULL&&strstr(c, bracket2)!=NULL)
    {
        strcpy(type,"float");
    }
    printf("\n%s",type);

}
void findvariable(int starting, int ending)
{

   char ch,str[1000];
   char c[100];
   char *v1="int";
   char *v2 = "char";
   char *v3 = "double";
   char *v4 = "float";
   char *v=";";
   char *vp ="(";
   int ci=0,cc=0,cd=0,cf=0;
   int k=0,kc=0,kd=0,kf=0;
   int i=0,end=0;
   int iterator=0;
   char vname[500],vcname[500],vdname[500],vfname[500];

    for(iterator=starting;iterator<=ending;iterator++)
    {
       strcpy(c,filestring[iterator]);

      if(strstr(c, v1) != NULL&& strstr(c, v)!= NULL && strstr(c, vp)== NULL) {
            menu[iterator]=1;

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
           if(c[i]==' ')
            continue;

           if(c[i]==';')
           {
             break;
           }

           if(c[i]==',')
           {
               vname[k]='/';
               k++;
               ci++;
               continue;
           }
           if(c[i]=='=')
           {
               for(;;i++)
               {
                   if(c[i]==',')
                   {
                       vname[k]='/';
                        k++;
                        ci++;
                        i++;
                        break;

                   }
                   if(c[i]==';')
                     {
                      end = 1;
                      i--;
                      break;
                     }
               }
           }

             if(end==1)
             {
                 end=0;
                 break;
             }
           vname[k]= c[i];
           k++;
       }
       vname[k]='/';
       k++;
       ci=ci+1;
      }
       else if(strstr(c, v2) != NULL&& strstr(c, v)!= NULL && strstr(c, vp)== NULL)
        {

        menu[iterator]=1;
      for(i=0;;i++)
       {
           if(c[i]=='c'&&c[i+1]=='h'&&c[i+2]=='a'&&c[i+3]=='r'&&c[i+4]==' ')
           {
               i=i+4;
               break;
           }
       }
            for(i=i+1;;i++)
       {
           if(c[i]==' ')
            continue;

           if(c[i]==';')
           {
             break;
           }
           if(c[i]==',')
           {
               vcname[kc]='/';
               kc++;
               cc++;
               continue;
           }
           if(c[i]=='=')
           {
               for(;;i++)
               {
                   if(c[i]==',')
                   {
                       vcname[k]='/';
                        kc++;
                        cc++;
                        i++;
                        break;

                   }
                   if(c[i]==';')
                     {
                      end = 1;
                      i--;
                      break;
                     }
               }
           }

             if(end==1)
             {
                 end=0;
                 break;
             }
           vcname[kc]= c[i];
           kc++;
       }
       vcname[kc]='/';
       kc++;
       cc=cc+1;
    }
    }
     printf("Integer variables are = ");
    for(int i=0;i<=k-1;i++)
    {
        if(vname[i]=='/')
        {
            printf(" , ");
            continue;
        }
        printf("%c",vname[i]);
    }

    printf("\n\n");
      printf("char variables are = ");
     for(int i=0;i<=kc-1;i++)
    {
        if(vcname[i]=='/')
        {
            printf(" , ");
            continue;
        }
        printf("%c",vcname[i]);
    }
   printf("\n");
}

int findstart(char name[100])
{

    int i=0,start=0;
    for(i=0;;i++)
    {

      if(strstr(filestring[i], intf) != NULL&& strstr(filestring[i], semicolon)== NULL && strstr(filestring[i], bracket1)!= NULL&&strstr(filestring[i], bracket2)!=NULL&&strstr(filestring[i], name))
      {
         start = i;
         break;
      }

    }
    return start;
}

int findend(char name[100], int start)
{
    int i=0,end=0;
    char *bri="{";
    char *brf="}";
    int count =0;
    for(i=start;i<line;i++)
    {

      if(strstr(filestring[i], "{")!=NULL&& strstr(filestring[i], ";")==NULL && strstr(filestring[i], "(")==NULL)
      {
          count++;

      }
      else if(strstr(filestring[i], "}")!=NULL&& strstr(filestring[i], ";")==NULL && strstr(filestring[i], "(")==NULL)
      {
          count--;
          if(count==0)
          {
              end=i;

              break ;
          }
      }
      else continue;


    }
    return end;
}

int findfunction()
{
      FILE *fptr;
      char c[100];

      fptr = fopen("i.txt","r");
      if(fptr == NULL)
   {
      printf("Error!");

   }

     int i,k=0,si=0;
     char intfunction[100];
      while(fgets(c, sizeof(c), fptr))
    {
        line++;
        strcpy(filestring[si],c);
        si++;
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
    fclose(fptr);
    printf("Integers funtions are = ");
    int fi=0,l=0;
    for(i=0;i<k;i++)
    {
        if(intfunction[i]=='/')
        {
            fi++;
            l=0;
            continue;
        }
         function_name[fi][l]=intfunction[i];
         l++;
    }
    for(i=0;i<fi;i++)
    {
        printf("%s ,",function_name[i]);
    }
}
int main()
{
    findfunction();
    for(int i=0;i<100;i++)
   {
       menu[i]=0;
   }
   int s = findstart(function_name[0]);
   int e = findend(function_name[0],s);
   findvariable(s,e);

   function_parameter(s);
   find_returntype(s);
   called(function_name[1]);
   find_loop(s,e);
   printf("\n%d\n%d",s,e);
}
