#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>            
#define LEN sizeof(struct student)    //����LENΪ�ṹ�峤��
struct student//����ṹ��
{
 int num;//ѧ��
 char name[10];//����
 int score;//����
 struct student *next;//βָ��
};
int n;          // ��¼ѧ���� Ϊȫ�ֱ��� ͨ��
struct student *creat()     // ���庯�� ��������  

{
 struct student *head;//����ͷָ��
 struct student *p1,*p2;//����ָ�������p1p2
 p1=p2=(struct student *)malloc(LEN);//����������p1p2ֻ������ͷ
 printf("����������:\n");//��ʾ��Ϣ
 printf("-ѧ��---����---�ɼ�-\n");
 scanf("%d%s%d",&p1->num,p1->name,&p1->score);  // ����ѧ����Ϣ
 head=NULL;//��ʼ��ͷָ��
 n=0;//��ѧ������ ���ж��Ƿ�Ϊ��һ�������������⴦��
 while(p1->num!=0) //Ϊ�ս���ѭ��
 {printf("-ѧ��---����---�ɼ�-\n");
  n=n+1; //����+1��
  if(n==1) head=p1;//����ǵ�һ��������ͷָ��ָ��p1
  else p2->next=p1;//��N����������һ���������½���������
  p2=p1;//����ָ��ָ��������ͷ
  p1=(struct student *)malloc(LEN);// ��һ���µ�Ԫ ����ʼ��ַ �� p1
  scanf("%d%s%d",&p1->num,p1->name,&p1->score);
 }    //����ѧ����Ϣ
 p2->next=NULL;  // p2Ϊ�� ���������
printf("��ɴ�����\n");
 return(head);//����ͷָ��
}
void print(struct student *head)   //���庯�� ���ѧ���ɼ�
{
 struct student *p; //����ָ��p
 p=head;//pָ������ͷ
 if(head!=NULL)//���������ڣ�����
 {
  printf("-ѧ��---����---�ɼ�-\n");
  while(p!=NULL)  //Ϊ��ʱ�������
  {
   printf("%d  %s    %d\n",p->num,p->name,p->score);//���ѧ����Ϣ
   p=p->next;//ָ����һ������
  }
 }
 else printf("���޴��� !\n");  //�������ڣ� û�����
}
struct student *del(int num,struct student *head)  //����ɾ������
{
 int a=0; 
 struct student *p1,*p2; //��������ָ��
 do
 {
  p1=head;                 //p1ָ��ͷָ��
  if(head==NULL)               // �������Ϊ�� ��������޴��ˡ�������
  {
  printf("���޴��� !\n");
  goto end;    }//����end��������
  while(p1->num!=num&&p1->next!=NULL)    //��ѧ�Ų���ȣ�û�ҵ�������һ�������ǿյ�ʱ
  {
   p2=p1;p1=p1->next; //ת����һ������p2������һ������
  }
  if(p1->num==num) //�ҵ�
  {
   if(p1==head) head=p1->next;//�����һ���������Ҫ�ҵĽ�ͷָ��ָ����һ������ɾ��������
   else p2->next=p1->next;//��N����Ҫ�ҵ�������p2��ָ��������p1�������������ɾ��p1������
   printf("ɾ��ѧ��ΪN0.%d\n",num);  //ɾ�����
   n=n-1;  //ѧ����-1
   a++;   //ɾ��+1
  }
 }while(p1->next!=NULL);  //��ͷ��β ����0 ���ɾ��
 if(a==0)
 printf("ɾ����� !\n");
 end:
 return(head);
}
struct student *add(int num,char name[],int score,struct student *head)  //�����������ĺ���
{
 struct student *p0,*p1,*p2;  //��������ָ��
 p0=(struct student *)malloc(LEN); //��p0ָ�������� 
 p0->num=num,strcpy(p0->name,name),p0->score=score; //   ����ѧ����Ϣ
 p1=head;//p1ָ������ͷ
 if(num==0) //����ѧ��Ϊ0�˳�
 return(head);
 if(head==NULL)  //��������ǿյ�
 {
  head=p0;//���½������׵�ַ����head
  p0->next=NULL;// ���������nextָ��� ������
 }
 while(p0->num>p1->num&&p1->next!=NULL)  // Ѱ�Ҳ���λ��
 {
  p2=p1;//p2 p1ͬʱָ���ͷ
  p1=p1->next;//p1ָ����һ�������ͷ
 }
 if(p0->num<=p1->num) //���ҵ�λ��ʱ���½�ѧ�ŵ�����С��ѧ����������ǰ��
 {
  if(p1==head) head=p0;//����ڱ�ͷ����p0����head
  else p2->next=p0;//���ڱ�ͷʱ�����´����ı���ǰ������
  p0->next=p1;//����������
 }
 else
 {
  p1->next=p0;  //û�ҵ�λ��ʱ ��һֱ����ֱ�����һ�� ��������ǰ������
  p0->next=NULL;//���ս��±�ָ��� ���������
 }
 printf("����ѧ��Ϊ:%d\n",num);
 n=n+1;//ѧ������һ
 return(head);
}
void num(struct student *head)    //���塤һ����ʵ�ֲ��ҹ��ܵĽṹ�庯��
{
 int num,a=0;
 struct student *p;// ����һ���ṹ��ָ��
 printf("------������ \"0\" ��������--------\n");
 do//pָ��ָ������Ŀ�ͷ���ж�ѧ���Ƿ����
 {
  p=head;  //��ͷ��ʼ��Ѱ 
  printf("������Ҫ���ҵ�ѧ��:");    //ѧ�Ų���
  scanf("%d",&num);   //�Ӽ��̽���
  if(num!=0) //���������
  printf("-ѧ��---����---�ɼ�-\n");
  while(p!=NULL) 
  {
   if(p->num==num)   //�ҵ���
   {
    printf("%d  %s     %d\n",p->num,p->name,p->score);  //������˵�ѧ�������ɼ�
    a++;  
   }
   p=p->next;  //ָ����һ��
  }
  if(a==0&&num!=0) //�ܵ���0 �� num ������0 �� û�������
  printf("���޴���!\n");
  a=0;
 }while(num!=0);
 system("cls");   //��������
}
void search(struct student *head)  //���Һ��� 
{
 int a;
 struct student *p;
 p=head;
 do
 {
  printf("1.��ѧ�Ų���\n2.�˳�\n");
  scanf("%d",&a);   //�Ӽ��̽���
  system("cls");  //����
  switch(a){
   case 1:num(p);break; //���ֲ���
   case 2:break;
  }//  ���ֲ���
 }while(a!=2);  //�жϳ����Ƿ�ִ����ϣ����ִ����ϣ�ֱ�Ӱ�2�����ò��ҳ���
}
struct student *sort(struct student *head)  //����һ������ʵ�������ܵĺ���
{
 struct student *p1,*p2;  //�������    ָ��
 int i,j;
 int num0,score0;
 char string[10];  //YOUXUJIHE ����һ���µĶ���
 for(i=0;i<n-1;i++)  //��n��¼����
 {
  p1=head;   //p1��ͷ��ʼ
  for(j=n-1;j>0;j--)
  while(p1->next!=NULL) //��Ϊ�ռ���
  {
   p2=p1;p1=p1->next; //���� ˳�����ָ�����
   if(p2->score>p1->score) //�Ƚϴ�С2>1
   {
    num0=p1->num; //������ֵ 
    p1->num=p2->num;
    p2->num=num0;
    strcpy(string,p1->name); //�ַ����ĸ���
    strcpy(p1->name,p2->name);  //��p2->name���Ƶ�p1->name����
    strcpy(p2->name,string);
    score0=p1->score;  //�����Ľ���
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
 {printf("\t\t��ӭʹ��ѧ����Ϣ����ϵͳ\n");printf("\n");
  printf("1.¼��ѧ����Ϣ\n\n2.ɾ��ѧ����Ϣ\n\n3.����ѧ����Ϣ\n\n4.����ѧ����Ϣ\n\n5.�ɼ�����\n\n6.��ʾ������Ϣ\n\n7.�˳�\n\n");
  scanf("%d",&a);
  system("cls");  //���� 
  switch(a)   //switch �˵�
  {
   case 1:printf("------������ \"0 0 0\" ��������------\n");head=creat();print(head);getchar();printf("\n\n\n\n\n\n");break;
   case 2:printf("------������ \"0\" ��������--------\n");do{printf("������Ҫɾ����¼��ѧ��:");scanf("%d",&num);head=del(num,head);print(head);}while(num!=0);printf("\n\n\n\n\n\n");break;
   case 3:printf("------������ \"0 0 0\" ��������------\n");do{printf("������Ҫ���ӵļ�¼����:\n");printf("-ѧ��---����---�ɼ�-\n");scanf("%d%s%d",&num,name,&score);head=add(num,name,score,head);print(head);}while(num!=0);printf("\n\n\n\n\n\n");break;
   case 4:search(head);printf("\n\n\n\n\n\n");break;
   case 5:head=sort(head);print(head);system("pause");getchar();printf("\n\n\n\n\n\n");break;
   case 6:print(head);system("pause");getchar();printf("\n\n\n\n\n\n");break;
  }
 }while(a!=7);
}

