#include<stdio.h>
#include<stdlib.h>
#include<getopt.h>
const struct option long_options[]={//长选项转换
    {"help",0,NULL,'h'},
    {"version",0,NULL,'k'},
    {NULL,0,NULL,0}
};

int main(int argc,char **argv)
{
   int b1,b2=1,w1=0,w2=0,i=0;
   if(argc==0)
   return 1;
   while((b1=getopt_long(argc,argv,"nevh",long_options,NULL))!= -1)
   switch(b2++,b1){
   case 'n': w1=1;break;
   case 'e': w2=1;break;
   case 'v': printf("版本信息\n");break;
   case 'h': printf("help message\n");break;
              return 1;//显示此帮助信息并离开
    default:break;
   }
   if(w1==1&&w2!=1)
       printf("%s\n",argv[argc-1]);
   else if(w1==0&&w2!=1)
            printf("%s",argv[argc-1]);
        else if(w2==1){ 
                 while(argv[argc-1]!=NULL){
                      if(argv[argc-1]=='"') ;
                      else    printf("%c",argv[argc-1]);
                  }
                    i++;
              }
        if(w1==1)printf("\n");
   }   
   return 0;
}
