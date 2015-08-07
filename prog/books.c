#include "stdio.h"
#include "string.h"
#define N sizeof(struct book)/*N����ṹ��Ŀռ��С*/
int num3=0;/*num3������¼�ļ��д洢���鱾����Ŀ*/



/*�ṹ�����ڴ洢ͼ����Ϣ*/
struct book
{
  char sort[16];/*������*/
  char name[16];/*����*/
  char author[16];/*������Ϣ*/
  long numble;/*���*/ 
  long numble2;/*�����˽���֤��*/
  int lend;/*lend�������ͼ���Ƿ񱻽�,1Ϊ����, 0Ϊδ�裬2Ϊ����*/
  long time1;/*����ʱ��*/
  long time2;/*����ʱ��*/
  struct book *next;/*���ڲ�ָͬ��֮�������*/
}*head;/*�����ﶨ��һ����Ϊhead�Ľṹ�壬��headΪȫ�ֱ���*/

/*�������*/ 
printfs(struct book *p1)/*���Ĺ��ܾ��ǽ�����ָ��ָ��ṹ����������*/
{
   printf("  ���:%-11s  ����:%-11s  ����:%-11s  ���:%-ld\n�����˽���֤��:%ld �ѽ�:%d  ��������:%ld  ��������:%ld\n",p1->sort,p1->name,p1->author,p1->numble,p1->numble2,p1->lend,p1->time1,p1->time2);
}



/*��ȡģ��*/
struct book *read(fp)/*���ļ��ж�ȡ���ݣ�����ֵ������Ľṹ��ռ���*/
{ 
   struct book *p1,*p2,*p3;
   FILE *fp2;

   fp2=fp;
   head=NULL;
   while(!feof(fp2))/*���������ļ��е�ָ�����ļ�ĩβʱ����ִ��while�ڵ����*/
   {  
     if(num3==0)
	 { 
	     head=p3=p2=p1=(struct book *)malloc(N);/*head,p1,p2ָ�׽��*/
         fscanf(fp2,"%s%s%s%ld%ld%d%ld%ld ",p1->sort,p1->name,p1->author,&p1->numble,&p1->numble2,&p1->lend,&p1->time1,&p1->time2);
         printf("  ���:%-11s  ����:%-11s  ����:%-11s  ���:%-ld\n  �����˽���֤��:%ld�ѽ�:%d  �������ڣ�%ld  ��������:%ld\n\n",p1->sort,p1->name,p1->author,p1->numble,p1->numble2,p1->lend,p1->time1,p1->time2);
		 /*fp2Ϊ�ļ��ڲ�ָ��*/
 		 num3=1;/*num3��ֵ�ڵ�һ��ִ������Ϊ1���Ժ�ִ��else�����䣬����head�����ָ������ĵ�һ����ַ*/
	 }
	 else
	 {
	     p1=(struct book *)malloc(N);/*head,p1,p2ָ�׽��*/
         fscanf(fp2,"%s%s%s%ld%ld%d%ld%ld ",p1->sort,p1->name,p1->author,&p1->numble,&p1->numble2,&p1->lend,&p1->time1,&p1->time2);
     	 printf("  ���:%-11s  ����:%-11s  ����:%-11s  ���:%-ld\n  �����˽���֤��:%ld�ѽ�:%d  �������ڣ�%ld  ��������:%ld\n\n",p1->sort,p1->name,p1->author,p1->numble,p1->numble2,p1->lend,p1->time1,p1->time2);
		 p2->next=p1;
         p2=p1;
		 num3++;
	 }
   }
   p2->next=NULL;/*���һ������ĵ�ַ��nextָ��յ�ַNULL*/

}
reads()
{   
    FILE *fp;
    if((fp=fopen("newbook.txt","rt"))==NULL)/*rb��ʾֻ����һ���ı��ļ���ֻ���������*/
    {
       printf("\n���ܴ򿪴��ļ�����������˳�!");
       getch();/*getch()��������ʱprintf���������ͣ������Ļ��*/
       exit(1);
    }
    read(fp);
    fclose(fp);/*��ȡ���ر��ļ�*/
	return fp;/*���ļ�ָ�뷵�أ����ں�߽������ݸ���*/
}



/*����ģ��*/
save()
{
	FILE *fp;
    struct book *p1;
    if((fp=fopen("newbook.txt","wt"))==NULL)/*wt��ʾֻ�򿪻��Ž���һ���ļ���ֻ����д����*/
    {
       printf("\n���ܴ򿪴��ļ�����������˳�!");
       getch();
       exit(1);
    }

	p1=head;     
	while(p1!=NULL)/*�����ڴ��нṹ���е����ݵ��ļ���p11=NULLʱp1ָ��ṹ���β������ʱ��������*/
	{
		fprintf(fp,"%s %s %s %ld %ld %d %ld %ld ",p1->sort,p1->name,p1->author,p1->numble,p1->numble2,p1->lend,p1->time1,p1->time2);
       /* printf("  ���:%-11s  ����:%-11s  ����:%-11s  ���:%-ld\n�����˽���֤��:%ld  �ѽ�:%d  ��������:%ld  ��������:%ld\n",p1->sort,p1->name,p1->author,p1->numble,p1->numble2,p1->lend,p1->time1,p1->time2);*/
		p1=p1->next;/*ÿ�θ�ֵ��󣬽�ָ�����һ��*/

	}  
    
	fclose(fp);/*�������ļ��ر��ļ�*/
}





/*�������ģ��*/
struct book *creat()
{  struct book *p1,*p2,*p3,*head2;
   int i,j,k,a=0;/*a���������������Ƿ����ͼ������е�һ��*/
   char sorts[][16]={"leader","literature","foreignlang","computer","math","magazine","other"};
   printf("����������鱾����:");/*������Ҫ������������*/
   scanf("%d",&k);
   head2=NULL;/*�ȶ���ṹ��Ϊ��*/
   if(k>0)/*������Ϊ0ʱ,��������ռ�,ֱ�ӷ��ؿ�ָ��*/
   {
      head2=p2=p1=(struct book *)malloc(N);/*head,p1,p2ָ�׽��*/
      printf("�������1��������(���:leader  ����:literature  ����:foreignlang\n�����:computer  ��ѧ:math  ��־:magazine  ����:other)�����������ߡ����\n");
      scanf("%s%s%s%ld",p1->sort,p1->name,p1->author,&p1->numble);
   	  p1->numble2=0;/*�������ʱû�б�Ҫ���н���֤���������ڡ��������ڵ����룬����ϵͳĬ��Ϊ0����ʾ����δ����*/
	  p1->lend=0;
	  p1->time1=0;
	  p1->time2=0;
	 
/*�����forѭ���������������ͼ������ںϷ���Χ�����:leader  ����:literature  ����:foreignlang\n�����:computer  ��ѧ:math  ��־:magazine  ����:other����*/
      for(;a!=1;)
          {
              for(i=0;i<7;i++)
                 if(!strcmp(sorts[i],p1->sort))
        		 {
                   a=1;
                   break;  
            	 }   
                 if(a!=1)  
        		 {
                   printf("���������(���:leader  ����:literature  ����:foreignlang\n�����:computer  ��ѧ:math  ��־:magazine  ����:other)����!!\n�������������:\n");       
                   scanf("%s",p1->sort);
        		 }
          } 
      for(i=1;i<k;i++)
      {  
          printf("�������%d�����������������ߡ����\n",i+1);
          p1=(struct book *)malloc(N);/*p1ָ��������Ľ��*/
          scanf("%s%s%s%ld",p1->sort,p1->name,p1->author,&p1->numble);
          p1->numble2=0;
	      p1->lend=0;
	      p1->time1=0;
	      p1->time2=0;
          a=0;/*��a��ԭΪ��ʼֵ0���Ա�������ͼ�������м��*/
          /*�����forѭ���������������ͼ������ںϷ���Χ�����:leader  ����:literature  ����:foreignlang\n�����:computer  ��ѧ:math  ��־:magazine  ����:other����*/
		  for(;a!=1;)
          {
              for(j=0;j<7;j++)
                 if(!strcmp(sorts[j],p1->sort))
        		 {
                   a=1;
                   break;  
            	 }   
                 if(a!=1)  /*�������������ںϷ���Χ��ʱ����ʾ�û�������ȷͼ������*/
        		 {
                   printf("���������(���:leader  ����:literature  ����:foreignlang\n�����:computer  ��ѧ:math  ��־:magazine  ����:other)����!!\n�������������:\n");       
                   scanf("%s",p1->sort);
        		 }
          } 
          p2->next=p1;
          p2=p1;
      }   
      p2->next=NULL;/*���һ������Ŀռ䣬ָ��NULL*/
   }
   if(head==NULL)
	   head=head2;
   p3=head;
   while(p3->next!=NULL)/*���洢�ļ�ԭ����Ϣ�Ľṹ����洢��¼��ͼ��Ľṹ��������һ��*/
   {
       p3=p3->next; 
   }
   p3->next=head2;
   return head;/*���洢ͼ����Ϣ�Ľṹ���ͷָ�뷵��*/
}




/*������ģ��*/
clean()
{  
     long num;/*����һ�������ͱ��������ڴ洢�������ţ������ļ��е������Ƚϣ��Ӷ��ó�Ҫɾ������ָ��*/
     struct book *p,*p0;
     if(head==NULL) return 0;
     printf("������Ҫɾ������ţ�");
     scanf("%ld",&num);
     p0=head;
     if(p0->numble==num)
	 {
        head=p->next;
        free(p0);
        return 1;
	 }
     p=p0->next;
     while(p!=NULL)
	 {
       if(p->numble==num)
	   {
          p0->next=p->next;
          free(p);
          return 1;
	   }
       p0=p;
       p=p->next;
	 }
  return 0;
}





/*Ȩ����֤ģ��*/
validate()
{  
   int b=0,i;
   char password[16],passwords[16];
   FILE *fp;
   if((fp=fopen("passwords.txt","rt"))==NULL)/*�ȴ��ı��ļ��ж���ϵͳ������*/
   {
       printf("\n���ܴ򿪴��ļ�����������˳�!");
       getch();
       exit(1);
    }
   fscanf(fp,"%s",&passwords);/*Ҫ���û���������*/    
   fclose(fp);
   printf("\n����������:");
   scanf("%s",&password);
   for(i=0;i<3;i++)
   {
       
       if(strcmp(password,passwords))/*���û������������洢���ı��ļ��е�ϵͳ����˶ԣ���ͬʱִ�й������*/
       {printf("��������������!!\n");
        if(i==2)/*��������ʱ�������û������˳�����*/
            printf("��ϵͳ�ܷ��ɱ������벻Ҫ�������!!!");	   	   
        if(i<2)
        {printf("����������:\n");
         scanf("%s",&password);
    	}
       }
       else
       {printf("���Ѿ��ɹ���½!\n");/*������ȷʱ����ʾ�û��ɹ���½��*/
       b=1;
       break;
       }
   }
   if(b==1)
   return(b);
}


    




/*�����趨ģ��*/
passwords()
{
	char passwords[16],passwordss[16];
	FILE *fp1;
    if((fp1=fopen("passwords.txt","wt"))==NULL)/*�ȴ��ı��ļ��ж���ϵͳ������*/
	{
      printf("\n���ܴ򿪴��ļ�����������˳�!");
      getch();
      exit(0);
	}
  loop4:printf("\t�����������룺");/*��ʾ�û�����������*/
  scanf("%s",&passwords);
  printf("\t���ٴ����������룺");/*��ʾ�û��ٴ�����������*/
  scanf("%s",&passwordss);
  if(strcmp(passwords,passwordss))/*���û���������������к˶ԣ��������벻һ��ʱ����ʾ�û������趨����*/
  {printf("�������������벻һ��!�������趨!\n");
  goto loop4;
  }
  else
  {fprintf(fp1,"%s",passwords);
   printf("��ϲ��!�����趨�ɹ�!\n");/*�趨����ɹ��󣬶��û�������ʾ*/
   fclose(fp1);
  }
}





/*����Ų�ѯ*/
num_find(long num)/*numΪ�����ļ�ʱ��������*/
{ 
	struct book *p;
     p=head;
     while(p!=NULL)
	 {
        if(p->numble==num) return p;
        p=p->next;
	 }
    return NULL;
}



name_finds()
{
    
     char name[16];
	 struct book *p;
     printf("������Ҫ���ҵ�������");/*��ʾ�û�����Ҫ���ҵ�����*/
     scanf("%s",&name);
	 p=head;
     while(p!=NULL)
	 {
        if(!strcmp(p->name,name)) return p;
        p=p->next;
	    
	 }
     
     return NULL;
}



/*�����߲�ѯ*/
author_find()
{
     char author[16];
	 struct book *p;
     printf("������Ҫ���ҵ����ߣ�");/*��ʾ�û�����Ҫ���ҵ�����*/
     scanf("%s",&author);
	 p=head;
     while(p!=NULL)
	 {
        if(!strcmp(p->author,author)) return p;
        p=p->next;
	    
	 }
     
     return NULL;
}




/*�����������߲�ѯ*/
name_author()
{
     char author[16];
	 char name[16];
	 struct book *p;
     printf("������Ҫ���ҵ�����������:");/*��ʾ�û�����Ҫ���ҵ�����������*/
     scanf("%s%s",&name,&author);
	 p=head;
     while(p!=NULL)
	 {
        if(!strcmp(p->author,author)&&!strcmp(p->name,name)) return p;
        p=p->next;
	    
	 }
     return NULL;
}




/*����ģ��*/
lend()
{
    long num1,num2;
	struct book *p;
    printf("��������ţ�");/*��ʾ�û�����Ҫ��������*/
	scanf("%ld",&num1);
    p=num_find(num1);
	if(p->lend==1)/*�ж�������ŵ����Ƿ񱻽���*/
		printf("�����ѱ�����!");/*��ʾ�û����鱻����*/
	else
	{
	  p->lend=1;
	  printf("���������֤����:");/*��ʾ�û��������֤��*/
	  scanf("%ld",&num2);
	  printf("�������������:");/*��ʾ�û������������*/
	  scanf("%ld",&p->time1);
	  printf("�����뻹������:");/*��ʾ�û����뻹������*/
	  scanf("%ld",&p->time2);

	  p->numble2=num2;
	  printf("������ɹ�!\n");
	
	}

}



/*ͳ��ͬһ�����������*/
author_book()
{
     char author[16];
	 struct book *p;
     int i=0;
	 printf("������Ҫͳ�Ƶ����ߣ�");/*��ʾ�û�����Ҫͳ�Ƶ�����*/
     scanf("%s",&author);
	 p=head;
     while(p!=NULL)
	 {
        if(!strcmp(p->author,author))  i++;
        p=p->next;
	   
	 }
     
     printf("%d",i);
}




/*ͳ��������ͬ�������*/
name_book()
{
     char name[16];
	 struct book *p;
     int i=0;
	 printf("������Ҫͳ�Ƶ�������");/*��ʾ�û�����Ҫͳ�Ƶ�����*/
     scanf("%s",&name);
	 p=head;
     while(p!=NULL)
	 {
        if(!strcmp(p->name,name))  i++;
        p=p->next;
	    
	 }
     
     printf("%d",i);
}


/*ͳ��ĳѧ���Ľ���*/
lend_book()
{
     long num2;
	 struct book *p;
     int i=0;
	 printf("������Ҫͳ��ѧ���Ľ���֤��:");/*��ʾ�û�����Ҫͳ�Ƶ�ѧ���Ľ���֤��*/
     scanf("%ld",&num2);
	 p=head;
	 printf("�������:");
     while(p!=NULL)
	 {
        if(p->numble2==num2) 
		{
		    i++;
			printf("%s  ",p->name);/*���û���������������Ļ��*/
        }  
		p=p->next;/*�ƶ�ָ��*/
		
	 }
     
     printf("����%d���顣",i);/*���û����������������*/
}



/*����ģ��*/
get_back()
{
   long num1,num2;
	struct book *p;
    printf("��������ţ�");/*��ʾ�û�����Ҫ����������*/
	scanf("%ld",&num1);
    p=num_find(num1);
	p->numble2=0;
	p->lend=0;
	p->time1=0;
    p->time2=0;
	 
	printf("������ɹ���\n");/*��ʾ�û�����ɹ�*/


}



/*����ģ��*/
go_on()
{
    long num1,num2;
	struct book *p;
    printf("��������ţ�");/*��ʾ�û�����ҪҪ�����������*/
	scanf("%ld",&num1);
    p=num_find(num1);
	
	
	if(p->lend==2)/*�ж�������ŵ����Ƿ������*/
		printf("���Ѿ��������!�������ɹ�\n");
	else
	{
		p->lend=2;
	    printf("�����뻹������:");/*��ʾ�û������µĻ�������*/
	    scanf("%ld",&p->time2);
	    printf("������ɹ���\n");/*��ʾ�û�����ɹ�*/
	
	} 

}



/*����Ŵ�С��������*/
num1_()
{
   struct book *q,*s,*p,*t=NULL;
   int i,j,n;
   p=q=s=head;
   n=num3;

   for(i=0;i<n;i++)
   {

      for(j=i;j<n;j++)
      {
        if(q->numble>p->numble)
           q=p;
           p=p->next;
      }
      *t=*s;
      *s=*q;
      *q=*t;
      t->next=s->next;
      s->next=q->next;
      q->next=t->next;
      s=s->next;
      q=p=s;
   }

}




  face()/*����ѡȡ����ģ��*/
{ 
    int a,b;/*a��������¼�û���ѡģ��Ĳ���*/
	FILE *fp;
    do
    {  

       fp=reads(); /*ÿ������ʱ���Ƚ��ļ����ͼ����Ϣ�����ڴ���*/ 
	   printf("%d",num3);
       printf("\n\n\n\n*******************************ͼ�����ϵͳ************************************\n\n\n\n");
       printf("\t\t\t1.���Ϲ���(��������������)\n\n\t\t\t2.��Ϣ��ѯ(�鱾��Ϣ��ѯ.ͳ�ƺͽ�����Ϣ����)\n\n\t\t\t3.����\n\n\t\t\t4.����\n\n\t\t\t5.����\n\n\t\t\t0.�˳�ϵͳ\n");
       printf("\n\n��ע������ͼ�������������9�趨���룡����ʼ����Ϊcomputer\n\n\n\n\n\t������(0-5):");
       scanf("%d",&a);
       /*clrscr();*/
  loop:switch(a)/*switch���������ã�ʹ�û������Լ���ѡ��ģ����о���Ĳ���*/
       {
          case 1:if(validate()==1)/*������֤����ʹ��Ҫ���ϵĹ�����߰�ȫ��*/
        		 {  
                     printf("���ѽ������Ϲ���ģ�飡1.�������  2.������\n");
                     printf("������1-2:");
                     scanf("%d",&b);
                     switch(b)
        			 {
                        case 1:creat();
							   break;
                        case 2:clean();
							   break;
                        		 
        			 }
                 }
                 break;/*���û�����1ʱ���������Ϲ���ģ�飬break��������switch*/
          case 2:printf("���ѽ�����Ϣ��ѯ.ͳ��ģ��!\n\t1.�鱾��Ϣ��ѯ.ͳ��\t2.����Ŵ�С��������\t\n");
                 printf("\t������(1-2):");
                 scanf("%d",&b);
           loop2:switch(b)
        		 { 
                    case 1:printf("���ѽ����鱾��Ϣ��ѯ.ͳ��ģ��\n\t1.��������ѯ       2.�����߲�ѯ        3.�����������߲�ѯ\n  4.ͳ��ͬһ���ߵ���\t5.ͳ��ͬһ��������\t6.ͳ��ĳѧ������\n");
						   printf("������1-6��");
						   scanf("%d",&b);
						   switch(b)
						   {
						       case 1:printfs(name_finds(fp));break;/*ִ�а��������Һ����󽫷��ص�ָ��ָ��ṹ������������*/
						       case 2:printfs(author_find(fp));break;/*ִ�а����߲��Һ����󽫷��ص�ָ��ָ��ṹ������������*/
						       case 3:printfs(name_author(fp));break;/*ִ�а����������߲��Һ����󽫷��ص�ָ��ָ��ṹ������������*/
						       case 4:author_book();break;/*ͳ��ͬһ���ߵ���*/
						       case 5:name_book();break;/*ͳ��ͬһ��������*/
						       case 6:lend_book();break;/*ͳ��ĳѧ������*/
						    
						   }
					      break;
                    case 2:num1_();/*����Ŵ�С��������*/
					      break;
                    default:printf("�������!����������:");scanf("%d",&b);goto loop2;/*����������ֲ�����1-2ʱ����ʾ������󣬲�Ҫ����������*/
        		 }
                 break;
          case 3:printf("���ѽ������ģ��");
			     lend();
				 break;
          case 4:printf("���ѽ��뻹��ģ��");
			     get_back();
				 break;
          case 5:printf("���ѽ�������ģ��");
			     go_on();
				 break;
          case 9:passwords();/*�趨����ģ��*/
          case 0:break;
          default:printf("�����������������:\n");scanf("%d",&a);goto loop;/*����������ֲ�����0��9ʱ����ʾ������󣬲�Ҫ����������*/
       }
       getch();/*getch()��������ʱprintf���������ͣ������Ļ��*/
       save();/*ÿ�θ��������Ϻ󣬶������ݽ��д���*/
	   num3=0;/*ÿ�β�����num3�ָ�Ϊ0�����´β���ʱ���ļ����鱾�����ļ�¼*/
    }while(a!=0);/*���г����ֻ������aʱ�˳�ϵͳ*/
   
	reads();/*�˳�ϵͳʱ����󱣴�������������Ļ*/

}


void main()
{   
	
    face();/*����һ�����溯������ϵͳ�����в������ڴ˺����н���*/
	
}
