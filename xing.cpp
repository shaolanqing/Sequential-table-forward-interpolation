
//˳���ǰ�壨�ڵ�i��Ԫ��ǰ����һ���µ�Ԫ�أ�

#include<stdio.h>    //��׼���������ͷ�ļ�
#include<malloc.h>   //��̬�洢�������Ҫ
#include<string.h>    //�ַ�����ĺ���ͷ�ļ�
#define maxnum 200
typedef struct 
{
	int list[maxnum];     //���Ա�
    int num;
 }qltype;           //���Ͷ���
void create(qltype *q)                       //��������
{
	int j,num;
	printf("input the count of numbers and the valus numbers:");
	scanf("%d",&num);
	for(j=0;j<num;j++)
	{
		scanf("%d",&(q->list[j]));
	    q->num++;                  //�������ж�����p->num=0;
	}
	printf("success!\n");
}
int insert(qltype *q,int i,int x)      //ǰ��
{    int j;
     if(i<0||i>q->num+1)    //i�������鷶Χ
	 {
		 printf("\n the value of i is wrong!");  
             return 0;
	 }
    if(q->num+1>=maxnum)
	{ 
		printf("\n overflow!");          //overflow��ʾ���       
        return 0;
	}
     for(j=q->num;j>=i;j--)     //�Ӻ��濪ʼ����,��i֮ǰ����           
         q->list[j+1]=q->list[j];   //��������Ųһ��λ��
         q->list[i]=x;              //��Ҫ��������������λ��
           q->num++;
           return 1;
}
void show(qltype *q)             //�������ʾ����
{
	for(int i=0;i<q->num;i++)
         printf("%d\t",q->list[i]);  
		printf("\n");
}      
int delet(qltype *q,int i)      //˳���ɾ��
{    
	if(i<0||i>q->num)         ////i�������鷶Χ
	{
		printf("\n the position is wrong!\n"); 
        return 0;
     }
     for(i;i<q->num;i++)
        q->list[i-1]=q->list[i];  //����������ϸ���ǰ��,ɾ����i����
      q->num--;
      return 1;
      
}


void main()
{
    qltype  *p;           //����һ��ָ��
	p=new qltype;
	p->num=0;	
    printf("create:\n");
	create(p);
	printf("insert:\n");
	insert(p,3,45);
	printf("show:\n");
	show(p);
	printf("delete:\n");
	delet(p,2);      //ɾ���˵�2����
	show(p);
	
}