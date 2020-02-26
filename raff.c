#include<stdio.h>
#include<string.h>



int main()
{

   char ch,str[1000];
   FILE *fptr;
   char c[100];
   char *v1="int";
   char *v2 = "char";
   char *v3 = "double";
   char *v4 = "float";
   char *v=";";
   char *vp ="(";
   int ci=0,cc=0,cd=0,cf=0;
   int k=0,kc=0,kd=0,kf=0;
   int i=0;
   fptr = fopen("i.txt","r");
   if(fptr == NULL)
   {
      printf("Error!");

   }
   char vname[500],vcname[500],vdname[500],vfname[500];
   while(fgets(c, sizeof(c), fptr))
    {
      if(strstr(c, v1) != NULL&& strstr(c, v)!= NULL && strstr(c, vp)== NULL) {

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

           vname[k]= c[i];
           k++;
       }
       vname[k]='/';
       k++;
       ci=ci+1;
      }
       else if(strstr(c, v2) != NULL&& strstr(c, v)!= NULL && strstr(c, vp)== NULL) {

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

           vcname[kc]= c[i];
           kc++;
       }
       vcname[kc]='/';
       kc++;
       cc=cc+1;




    }


    }
     printf("Integer variacles are %d = ",ci);
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
      printf("char variacles are %d = ",cc);
     for(int i=0;i<=kc-1;i++)
    {
        if(vcname[i]=='/')
        {
            printf(" , ");
            continue;
        }
        printf("%c",vcname[i]);
    }

    fclose(fptr);
}

