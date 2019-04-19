#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>            
#define LEN sizeof(struct student)    //定义LEN为结构体长度
struct student//定义结构体
{
 int num;//学号
 char name[10];//姓名
 int score;//分数
 struct student *next;//尾指针
};
int n;          // 记录学生数 为全局变量 通用
struct student *creat()     // 定义函数 创建链表  

{
 struct student *head;//创建头指针
 struct student *p1,*p2;//创建指针变量怕p1p2
 p1=p2=(struct student *)malloc(LEN);//创建链表令p1p2只想链表头
 printf("请输入数据:\n");//提示信息
 printf("-学号---姓名---成绩-\n");
 scanf("%d%s%d",&p1->num,p1->name,&p1->score);  // 接受学生信息
 head=NULL;//初始化头指针
 n=0;//计学生人数 （判断是否为第一个链表，方便特殊处理）
 while(p1->num!=0) //为空结束循环
 {printf("-学号---姓名---成绩-\n");
  n=n+1; //计数+1，
  if(n==1) head=p1;//如果是第一个链表，令头指针指向p1
  else p2->next=p1;//第N个链表，将上一个链表与新建链表链接
  p2=p1;//两个指针指向新链表头
  p1=(struct student *)malloc(LEN);// 开一个新单元 把起始地址 给 p1
  scanf("%d%s%d",&p1->num,p1->name,&p1->score);
 }    //输入学生信息
 p2->next=NULL;  // p2为空 完成链表创建
printf("完成创建！\n");
 return(head);//返回头指针
}
void print(struct student *head)   //定义函数 输出学生成绩
{
 struct student *p; //定义指针p
 p=head;//p指向链表头
 if(head!=NULL)//如果链表存在，运行
 {
  printf("-学号---姓名---成绩-\n");
  while(p!=NULL)  //为空时结束输出
  {
   printf("%d  %s    %d\n",p->num,p->name,p->score);//输出学生信息
   p=p->next;//指向下一个链表
  }
 }
 else printf("查无此人 !\n");  //联表不存在， 没这个人
}
struct student *del(int num,struct student *head)  //定义删除函数
{
 int a=0; 
 struct student *p1,*p2; //定义两个指针
 do
 {
  p1=head;                 //p1指向头指针
  if(head==NULL)               // 如果链表为空 输出【查无此人】并结束
  {
  printf("查无此人 !\n");
  goto end;    }//跳到end（结束）
  while(p1->num!=num&&p1->next!=NULL)    //当学号不相等（没找到）且下一个链表不是空的时
  {
   p2=p1;p1=p1->next; //转到下一个链表（p2还在上一个链表）
  }
  if(p1->num==num) //找到
  {
   if(p1==head) head=p1->next;//如果第一个链表就是要找的将头指针指向下一个链表（删除本链表）
   else p2->next=p1->next;//第N个是要找的链表，将p2所指的链表与p1后的链表相连（删除p1的链表）
   printf("删除学号为N0.%d\n",num);  //删除完成
   n=n-1;  //学生数-1
   a++;   //删除+1
  }
 }while(p1->next!=NULL);  //从头到尾 输入0 完成删除
 if(a==0)
 printf("删除完成 !\n");
 end:
 return(head);
}
struct student *add(int num,char name[],int score,struct student *head)  //定义插入链表的函数
{
 struct student *p0,*p1,*p2;  //定义三个指针
 p0=(struct student *)malloc(LEN); //令p0指向新链表 
 p0->num=num,strcpy(p0->name,name),p0->score=score; //   更改学生信息
 p1=head;//p1指向链表头
 if(num==0) //输入学号为0退出
 return(head);
 if(head==NULL)  //如果链表是空的
 {
  head=p0;//将新建链表首地址赋给head
  p0->next=NULL;// 令新链表的next指向空 完成添加
 }
 while(p0->num>p1->num&&p1->next!=NULL)  // 寻找插入位置
 {
  p2=p1;//p2 p1同时指向表头
  p1=p1->next;//p1指向下一个链表表头
 }
 if(p0->num<=p1->num) //当找到位置时（新建学号到比他小的学号所在链表前）
 {
  if(p1==head) head=p0;//如果在表头，将p0赋给head
  else p2->next=p0;//不在表头时，将新创建的表与前表链接
  p0->next=p1;//再与后表链接
 }
 else
 {
  p1->next=p0;  //没找到位置时 ，一直后移直到最后一个 ，将其与前表链接
  p0->next=NULL;//最终将新表指向空 ，完成链接
 }
 printf("增加学号为:%d\n",num);
 n=n+1;//学生数加一
 return(head);
}
void num(struct student *head)    //定义·一个·实现查找功能的结构体函数
{
 int num,a=0;
 struct student *p;// 创建一个结构体指针
 printf("------请输入 \"0\" 结束输入--------\n");
 do//p指针指向链表的开头，判断学号是否存在
 {
  p=head;  //从头开始找寻 
  printf("请输入要查找的学号:");    //学号查找
  scanf("%d",&num);   //从键盘接受
  if(num!=0) //有这个个人
  printf("-学号---姓名---成绩-\n");
  while(p!=NULL) 
  {
   if(p->num==num)   //找到人
   {
    printf("%d  %s     %d\n",p->num,p->name,p->score);  //输出此人的学号姓名成绩
    a++;  
   }
   p=p->next;  //指向下一个
  }
  if(a==0&&num!=0) //很等于0 且 num 不等于0 则 没有这个人
  printf("查无此人!\n");
  a=0;
 }while(num!=0);
 system("cls");   //清屏操作
}
void search(struct student *head)  //查找函数 
{
 int a;
 struct student *p;
 p=head;
 do
 {
  printf("1.按学号查找\n2.退出\n");
  scanf("%d",&a);   //从键盘接受
  system("cls");  //清屏
  switch(a){
   case 1:num(p);break; //数字查找
   case 2:break;
  }//  名字查找
 }while(a!=2);  //判断程序是否执行完毕，如果执行完毕，直接按2结束该查找程序
}
struct student *sort(struct student *head)  //定义一个可以实行排序功能的函数
{
 struct student *p1,*p2;  //定义变量    指针
 int i,j;
 int num0,score0;
 char string[10];  //YOUXUJIHE 返回一个新的对象
 for(i=0;i<n-1;i++)  //用n记录人数
 {
  p1=head;   //p1从头开始
  for(j=n-1;j>0;j--)
  while(p1->next!=NULL) //不为空继续
  {
   p2=p1;p1=p1->next; //链接 顺序合适指针后移
   if(p2->score>p1->score) //比较大小2>1
   {
    num0=p1->num; //交换数值 
    p1->num=p2->num;
    p2->num=num0;
    strcpy(string,p1->name); //字符串的复制
    strcpy(p1->name,p2->name);  //把p2->name复制到p1->name后面
    strcpy(p2->name,string);
    score0=p1->score;  //分数的交换
    p1->score=p2->score;
    p2->score=score0;
   }
  }
 }
 return(head);
}
int main()  
{
 struct student *head=NULL;
 int num,score,a;
 char name[10];
 do
 {printf("\t\t欢迎使用学生信息管理系统\n");printf("\n");
  printf("1.录入学生信息\n\n2.删除学生信息\n\n3.增加学生信息\n\n4.查找学生信息\n\n5.成绩排序\n\n6.显示所有信息\n\n7.退出\n\n");
  scanf("%d",&a);
  system("cls");  //清屏 
  switch(a)   //switch 菜单
  {
   case 1:printf("------请输入 \"0 0 0\" 结束输入------\n");head=creat();print(head);getchar();printf("\n\n\n\n\n\n");break;
   case 2:printf("------请输入 \"0\" 结束输入--------\n");do{printf("请输入要删除记录的学号:");scanf("%d",&num);head=del(num,head);print(head);}while(num!=0);printf("\n\n\n\n\n\n");break;
   case 3:printf("------请输入 \"0 0 0\" 结束输入------\n");do{printf("请输入要增加的记录数据:\n");printf("-学号---姓名---成绩-\n");scanf("%d%s%d",&num,name,&score);head=add(num,name,score,head);print(head);}while(num!=0);printf("\n\n\n\n\n\n");break;
   case 4:search(head);printf("\n\n\n\n\n\n");break;
   case 5:head=sort(head);print(head);system("pause");getchar();printf("\n\n\n\n\n\n");break;
   case 6:print(head);system("pause");getchar();printf("\n\n\n\n\n\n");break;
  }
 }while(a!=7);
}

