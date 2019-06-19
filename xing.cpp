
//顺序表前插（在第i号元素前插入一个新的元素）

#include<stdio.h>    //标准的输入输出头文件
#include<malloc.h>   //动态存储分配的需要
#include<string.h>    //字符数组的函数头文件
#define maxnum 200
typedef struct 
{
	int list[maxnum];     //线性表
    int num;
 }qltype;           //类型定义
void create(qltype *q)                       //创建数组
{
	int j,num;
	printf("input the count of numbers and the valus numbers:");
	scanf("%d",&num);
	for(j=0;j<num;j++)
	{
		scanf("%d",&(q->list[j]));
	    q->num++;                  //主函数中定义了p->num=0;
	}
	printf("success!\n");
}
int insert(qltype *q,int i,int x)      //前插
{    int j;
     if(i<0||i>q->num+1)    //i超出数组范围
	 {
		 printf("\n the value of i is wrong!");  
             return 0;
	 }
    if(q->num+1>=maxnum)
	{ 
		printf("\n overflow!");          //overflow表示溢出       
        return 0;
	}
     for(j=q->num;j>=i;j--)     //从后面开始遍历,在i之前插入           
         q->list[j+1]=q->list[j];   //将数往后挪一个位置
         q->list[i]=x;              //将要插入的数放在这个位置
           q->num++;
           return 1;
}
void show(qltype *q)             //插入后显示出来
{
	for(int i=0;i<q->num;i++)
         printf("%d\t",q->list[i]);  
		printf("\n");
}      
int delet(qltype *q,int i)      //顺序表删除
{    
	if(i<0||i>q->num)         ////i超出数组范围
	{
		printf("\n the position is wrong!\n"); 
        return 0;
     }
     for(i;i<q->num;i++)
        q->list[i-1]=q->list[i];  //后面的数不断覆盖前面,删除第i个数
      q->num--;
      return 1;
      
}


void main()
{
    qltype  *p;           //定义一个指针
	p=new qltype;
	p->num=0;	
    printf("create:\n");
	create(p);
	printf("insert:\n");
	insert(p,3,45);
	printf("show:\n");
	show(p);
	printf("delete:\n");
	delet(p,2);      //删除了第2个数
	show(p);
	
}