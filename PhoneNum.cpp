******************************************************
* filename:PhoneNumber
* Author:Sunshine
* CreateTime:2014-2-18
* Des: Find the phone number of the classmates
******************************************************

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream.h>
#include<windows.h>

#define M 100
#define N 26

struct msg
{
    char xh[10];
    char xm[10];
    char lxfs[15];
    char qs[10];
};

typedef struct LNode
{
    struct msg data;
    struct LNode *next;
}LinkList;

LinkList *H;
void exit(int status);

void CreateList(int n)            //向系统申请空间，初始化线性表.
{
    int i;
    struct msg xx[M]={
        {"20133477","王霜","18227587925","14舍110"},{"20133449","王元东","18227587927","11舍509"},
        {"20133479","李琴","18227587902","14舍111"},{"20133503","龚蒙","18227587891","14舍112"},
        {"20133481","唐川梨","18227587918","14舍111"},{"20133461","熊伟","18227587934","11舍510"},
        {"20133523","周鑫悦","18227587956","14舍113"},{"20133495","曾心","18227587946","14舍112"},
        {"20133525","徐梅","18227587946","14舍113"},{"20133467","余正江","18227587942","11舍510"},
        {"20133475","朱伟","18227587957","11舍511"},{"20133491","陈秋敏","18227587880","14舍111"},
        {"20133521","杨霞","18227587938","14舍113"},{"20133453","李健桃","18227587901","11舍509"},
        {"20133457","何琪","18227587893","11舍510"},{"20133485","王孝容","18227587926","14舍111"},
        {"20133511","唐容","18227587922","14舍113"},{"20133497","李芸","18227587903","14舍112"},
        {"20133489","罗剑袂","18227587911","14舍111"},{"20133471","郑伟","15390379350","11舍511"},
        {"20133463","余成","18227587941","11舍510"},{"20133515","李含萍","18227587900","14舍113"},
        {"20133527","赵会","18227587921","14舍114"},{"20133459","唐明","18227587921","11舍510",},
        {"20133473","杨光旭","18227587937","11舍511"},{"20133501","赵金凤","18227587952","14舍112"},
        {"20133507","胡小凤","18227587895","14舍112"},{"20133519","邓双惠","18227587885","14舍113"},
        {"20133447","张育","18227587950","11舍509"},{"20133483","宋琼","18227587917","14舍111"},
        {"20133451","夏伟腾","18227587931","11舍509"},{"20133493","吴宗丽","18227587929","14舍111"},
        {"20133513","梁秋林","18227587904","14舍113"},{"20133469","周涛","18227587954","11舍510"},
        {"20133487","张玉霞","18227587949","14舍111"},{"20133517","谢迎香","18227587933","14舍112"},
        {"20133517","曾明林","18227587945","14舍113"},{"20133509","廖萍","18227587905","14舍112"},
        {"20133505","魏小草","18227587928","14舍112"},{"20133455","黄卓","18227587898","11舍510"},
        {"20133465","穆肖洋","18583770956","11舍510"}
    };
    int size=sizeof(xx)/sizeof(xx[0]);            //size用于存放当前数组中的实际元素个数
    LinkList *r,*s;            //r用于存放尾结点，s用于存放新申请的结点
    H=(struct LNode *)malloc(sizeof(LinkList));
    r=H;
    for(i=0;i<=40;i++)
    {
        s=(struct LNode *)malloc(sizeof(LinkList));            //向系统申请新结点
       	s->data=xx[i];
       	r->next=s;
       	r=r->next;
    }
    r->next=NULL;
}

ListEmpty(LinkList *H)            //判断单链表是否为空,返回1表示为空，返回0表示不为空
{
    return(H->next==NULL);
}

int DispList(LinkList *H)            //输出单链表H(输出所有的信息.)
{
    int i;
    if(ListEmpty(H))
    {
    	printf("\n\n\n此表为空表，不能进行输出操作!\n\n");
    	return(-1);
    }
    LinkList *p=H->next;
    for(i=0;p!=NULL;i++)
    {
        printf("%10s",p->data.xh);
        printf("%9s",p->data.xm);
        printf("%15s",p->data.lxfs);
        printf("%9s",p->data.qs);
        printf("\n");
        p=p->next;
    }
    printf("\n");
    return 0;
}

LinkList *FindList(LinkList *H,char x[10])            //查找元素x的位置
{
    int i;
    LinkList *p=H->next;
    if(x[0]>='0' && x[0]<='9')
    {
    	for(i=0;strcmp(p->data.xh,x) && p->next!=NULL;i++)
        p=p->next;
    }
    else
    {
    	for(i=0;strcmp(p->data.xm,x) && p->next!=NULL;i++)
    	    p=p->next;
    }
    return(p);
}

void FindR()            //findr(findrecord)查找记录
{
    int c;            //C用于存放你要查找的依据
    char in[10];            //i(input)存放输入的信息
    LinkList *e;
    printf("您将输入什么进行查找：\n1.学号        2.姓名\n");
    scanf("%d",&c);
    if(c==1 || c==2)
    {
    	printf("请输入:\n");
    	scanf("%s",in);
    	e=FindList(H,in);
    	if(e->next!=NULL)
    	{
            if(c==1)
            {
	        printf("\n学号为%s的信息是:\n\n",in);
	        printf("学号: %-10s\n",e->data.xh);
	        printf("姓名: %-10s\n",e->data.xm);
	        printf("电话: %-15s\n",e->data.lxfs);
	        printf("寝室: %-10s\n",e->data.qs);
	    }
	    else
	    {
	        printf("\n姓名为%s的信息是:\n\n",in);
	        printf("学号: %-10s\n",e->data.xh);
	        printf("姓名: %-10s\n",e->data.xm);
		printf("电话: %-15s\n",e->data.lxfs);
	        printf("寝室: %-10s\n",e->data.qs);
	    }
	    printf("/////////////////////////////////////////////");
	}
	else
	    printf("\n\n找不到你输入的信息，请重新操作!\n\n");
	}
	else
	    printf("\n输入的代号有错，请重新操作!\n");
	printf("\n\n");
}

void InsertList(LinkList *H,LinkList *l)            //在链表表尾插入元素结点
{
    int i,k=0;
    LinkList *p=H->next,*s;
    for(i=0;p->next!=NULL;i++)
    {
        if(!(strcmp(p->data.xh,l->data.xh)))
        k=1;
        p=p->next;
    }
    s=(struct LNode *)malloc(sizeof(LinkList));
    if(k==1)
        printf("学号为:\n%s\n记录在表中己经存在。\n请重新操作!\n",l->data.xh);
    else
    {
    	s->data=l->data;
    	s->next=NULL;
    	p->next=s;
    	printf("\n记录添加成功!\n");
    }
}

void AddR()            //添加新结点
{
    LinkList *s;
    s=(LinkList *)malloc(sizeof(LinkList));
    printf("请输入你要添加的信息（以空格分隔）:\n例如:20130000 张三 18227580000 11舍111\n请输入：\n");
    scanf("%s%s%s%s",s->data.xh,s->data.xm,s->data.lxfs,s->data.qs);
    InsertList(H,s);
}

void DeleteList(LinkList *H,char xh[10])            //按学号删除第元素
{
    int i;
    if(H->next!=NULL)            //判断是否为空
    {
        LinkList *p=H->next,*r;
        for(i=0;strcmp(p->next->data.xh,xh);i++)
            p=p->next;
        r=p->next;
        p->next=r->next;
        free(r);
        printf("学号为%s的记录。\n删除成功!\n",xh);
    }
    else
        printf("\n\n此表为空表，不能再删除了!\n");
}
void DeleteR()
{
    int num;
    char xh[10];
    printf("请输入你要删除记录的学号:");
    scanf("%s",xh);
    printf("你确定要删除数据吗？\n1.删除       2.不删除\n");
    scanf("%d",&num);
    if(num==1)
        DeleteList(H,xh);
    else
        printf("请重新操作!\n");
}

void ReleaseList(LinkList *H)            //释放单链表/清空全表(删除所有的电话记录)
{
    LinkList *p,*q;
    while(H->next!=NULL)
    {
        p=H->next;
        q=p->next;
        H->next=q;
        free(p);
    }
    printf("\n\n所有的记录删除成功，当前没有任何记录!\n");
}

void EditList(LinkList *H,char *n1,char *n2,int k)            //修改记录中的信息
{
    int i,m=0;
    LinkList *p=H;
    for(i=0;p->next!=NULL;i++)
    {
        if((!(strcmp(p->next->data.xh,n1))) || (!(strcmp(p->next->data.xm,n1))))
            m=1;
        p=p->next;
    }
    p=H->next;
    if(m==1)
    {
        if(n1[0]>='0' && n1[0]<='9')
        {
            for(i=0;strcmp(p->data.xh,n1);i++)
                p=p->next;
        }
    	else
    	{
            for(i=0;strcmp(p->data.xm,n1);i++)
                p=p->next;
	}
    	for(i=0;i<10;i++)
	{
            switch(k)
            {
	        case 1: p->data.xm[i]=n2[i];        break;
	        case 2: p->data.xh[i]=n2[i];        break;
   	        case 3: p->data.lxfs[i]=n2[i],
	    		p->data.lxfs[10]=n2[10];    break;
	        case 4: p->data.qs[i]=n2[i];        break;
	        default :printf("你输入的信息不符合要改正的内容!\n");
	    }
	}
    }
    else
        printf("\n\n找不到你要修改的记录!");
}

void Edit()
{
    int n,k=0;            //k变量用于存放修改的编号
    char num1[10],num2[15];            //num[1]保存输入的相关信息,num[2]保存要改正的内容
    printf("请输入你要编辑记录的姓名或学号:");
    scanf("%s",num1);
    printf("你将要修改什么信息？\n");
    printf("1.姓名     2.学号     3.电话号码     4.寝室地址\n");
    scanf("%d",&n);
    printf("请输入改正后的内容：");
    scanf("%s",num2);
    EditList(H,num1,num2,n);
}

int main()
{
    int i=0;
    int num;         /*存放初始时输入的代号*/
    CreateList(40);
    printf("********************************************************\n");
    printf("       *******************************************\n");
    printf("       *      计教（2）班  号码查询              *\n");
    printf("       *******************************************\n");
    printf("********************************************************\n");
    while(1)
    {
        printf("操作代号：\n");
        printf("1.查找           2.添加           3.删除记录\n");
        printf("4.条件修改       5.清空号码表     6.查看当前的所有记录\n");
        printf("7.退出程序\n\n");
        printf("请输入你要操作的代号：\n");
        scanf("%d",&num);
        switch(num)
        {
            case 1: FindR();           break;
            case 2: AddR();            break;
            case 3: DeleteR();         break;
            case 4: Edit();            break;
            case 5: ReleaseList(H);    break;
            case 6: DispList(H);       break;
            case 7: exit (1);          break;
            default:printf("\n\n输入的代号不能识别，请重新输入：");
        }
        printf("\n\n");
    }
    return 0;
}


