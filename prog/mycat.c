//mycat����

#include<stdio.h>
#include<stdlib.h>
#include<getopt.h>
const struct option long_options[]={//��ѡ��ת��
    {"help",0,NULL,'h'}, 
    {"version",0,NULL,'k'}, 
    {NULL,0,NULL,0} 
};

int main(int argc,char **argv)
{
   FILE *fp;//�����ļ�ָ��
      char a[1],a1[90];//������ʱ��Ŵ��ļ��ж�ȡ���ַ�����
      int b1,b2=1,b3=0,i=0,line=1,line2=1;
   int bb=0,EE=0,nn=0,ss=0,TT=0,vv=0; 
   if(argc==0)
       return 1; 
   if(argc==1)
   for(;;){
       scanf("%s",a);
       puts(a);
   }
   while((b1=getopt_long(argc,argv,"AbeEnstTuvh",long_options,NULL))!= -1)
       switch(b2++,b1){ 
       case 'k':printf(" mycat(GUN coreutils)5.99\nCopyright (C)2006 Free Software Foundation,Inc.\n������������������԰���GUN GPLЭ��< http://www.gnu.org/licenses/gp1/html>�������ٷ���������ĸ������������޷���֤��ط��ɲ�����һ���ν������ơ�\n\n��China Xi'an Instatute of Post & Communication �׽�����д��\n");return 1; 
       case 'A':vv=1;EE=1;TT=1;break;//�ȼ��� -vET 
       case 'b':bb=1;break;//�Էǿ�����б��
              case 'e':vv=1;EE=1;break;//�ȼ��� -vE
       case 'E':EE=1;break;//��ÿ�н�������ʾ $
       case 'n':nn=1;break;//������������б��
              case 's':ss=1;break;//��������п��� 
              case 't':vv=1;TT=1;break;//�� -vT 
       case 'T':TT=1;break;//�ȼ۽������ַ���ʾΪ ^I
       case 'u':;break;//(������)
       case 'v':vv=1;break;//ʹ�� ^ �� M- ���ã����� LFD �� TAB ֮��
              case 'h':printf("�÷��� mycat [ѡ��] [�ļ�]...\n��[�ļ�]���׼��������������׼�����\n\n  -A, --show-all           �ȼ��� -vET\n\n  -b, --number-nonblank    �Էǿ�����б��\n  -e                       �ȼ��� -vE\n  -E, --show-ends          ��ÿ�н�������ʾ $\n  -n, --number             ������������б��\n  -s, --squeeze-blank      ��������п���\n  -t                       �� -vT �ȼ�\n  -T, --show-tabs          �������ַ���ʾΪ ^I\n  -u                       (������)\n  -v, --show-nonprinting   ʹ�� ^ �� M- ���ã����� LFD �� TAB ֮��\n      --help     ��ʾ�˰�����Ϣ���˳�\n      --version  ����汾��Ϣ���˳�\n\n���[�ļ�]ȱʡ������[�ļ�]Ϊ - �����ȡ��׼���롣\n\nʾ����\n  cat f - g  ����� f �����ݣ�Ȼ�������׼��������ݣ������� g �����ݡ�\n  mycat        ����׼��������ݸ��Ƶ���׼�����\n\n���� < bug-coreutils@gnu.org> �������\n"); 
              return 1;//��ʾ�˰�����Ϣ���뿪
              default:break;
    } 
    if((fp=fopen(*(argv+b2),"rb"))==NULL){
        printf("\nCan't open %s!\n",*(argv+b2)); 
        return 1;
        } 
    while(!feof(fp)){        //ָ�뵽���ļ���βǰ��ִ��ѭ��    
                fscanf(fp,"%c",&a1[i]); 
    i++;
    }
    i=0;
    while(a1[i]!=(int)NULL){
        if(a1[i]!='\n'&&i==0&&(bb==1||nn==1))//��ѡ���ڵ�һ��ͷ����к�1 
            printf("     1  ");        
        if(a1[i]=='\n'){ 
            line++;
            line2++;
        }
        if(bb==1&&a1[i]=='\n'&&a1[i+1]=='\n') 
            line2--; 
        if(a1[i]=='\t'&&TT==1) //�������ַ���ʾΪ ^I 
            printf("^I"); 
        else{ 
            if(ss==1&&a1[i]=='\n'&&a1[i+1]=='\n'){    //ѹ�������Ϊһ 
                                for(;a1[i+1]=='\n';i++); 
                    if(EE==1&&a1[i-1]=='\n') printf("$");
                printf("\n"); 
            }        
            if(EE==1&&a1[i]=='\n')   printf("$"); 
            if(vv==0)    printf("%c",a1[i]); 
            else{
                if(a[i]<32) printf("^%c",a[i]+64); 
                else{
                     if(a[i]<127)    printf("%c",a[i]); 
                     else{
                          if(a[i]==127)  printf("^?");
                          else   printf("M-%c",a[i]-128); 
                       } 
                  }  
            }
            if(nn==1&&a1[i]=='\n'&&a1[i+1]!=(int)NULL) 
                 printf("     %d  ",line);
            if(a1[i]=='\n'&&bb==1&&a1[i+1]!=(int)NULL&&a1[i+1]!='\n') 
                 printf("     %d  ",line2);     
        }
        i++;
    }
    fclose(fp);
    return 0;