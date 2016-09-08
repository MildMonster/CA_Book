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

void CreateList(int n)            //��ϵͳ����ռ䣬��ʼ�����Ա�.
{
    int i;
    struct msg xx[M]={
        {"20133477","��˪","18227587925","14��110"},{"20133449","��Ԫ��","18227587927","11��509"},
        {"20133479","����","18227587902","14��111"},{"20133503","����","18227587891","14��112"},
        {"20133481","�ƴ���","18227587918","14��111"},{"20133461","��ΰ","18227587934","11��510"},
        {"20133523","������","18227587956","14��113"},{"20133495","����","18227587946","14��112"},
        {"20133525","��÷","18227587946","14��113"},{"20133467","������","18227587942","11��510"},
        {"20133475","��ΰ","18227587957","11��511"},{"20133491","������","18227587880","14��111"},
        {"20133521","��ϼ","18227587938","14��113"},{"20133453","���","18227587901","11��509"},
        {"20133457","����","18227587893","11��510"},{"20133485","��Т��","18227587926","14��111"},
        {"20133511","����","18227587922","14��113"},{"20133497","��ܿ","18227587903","14��112"},
        {"20133489","�޽���","18227587911","14��111"},{"20133471","֣ΰ","15390379350","11��511"},
        {"20133463","���","18227587941","11��510"},{"20133515","�Ƽ","18227587900","14��113"},
        {"20133527","�Ի�","18227587921","14��114"},{"20133459","����","18227587921","11��510",},
        {"20133473","�����","18227587937","11��511"},{"20133501","�Խ��","18227587952","14��112"},
        {"20133507","��С��","18227587895","14��112"},{"20133519","��˫��","18227587885","14��113"},
        {"20133447","����","18227587950","11��509"},{"20133483","����","18227587917","14��111"},
        {"20133451","��ΰ��","18227587931","11��509"},{"20133493","������","18227587929","14��111"},
        {"20133513","������","18227587904","14��113"},{"20133469","����","18227587954","11��510"},
        {"20133487","����ϼ","18227587949","14��111"},{"20133517","лӭ��","18227587933","14��112"},
        {"20133517","������","18227587945","14��113"},{"20133509","��Ƽ","18227587905","14��112"},
        {"20133505","κС��","18227587928","14��112"},{"20133455","��׿","18227587898","11��510"},
        {"20133465","��Ф��","18583770956","11��510"}
    };
    int size=sizeof(xx)/sizeof(xx[0]);            //size���ڴ�ŵ�ǰ�����е�ʵ��Ԫ�ظ���
    LinkList *r,*s;            //r���ڴ��β��㣬s���ڴ��������Ľ��
    H=(struct LNode *)malloc(sizeof(LinkList));
    r=H;
    for(i=0;i<=40;i++)
    {
        s=(struct LNode *)malloc(sizeof(LinkList));            //��ϵͳ�����½��
       	s->data=xx[i];
       	r->next=s;
       	r=r->next;
    }
    r->next=NULL;
}

ListEmpty(LinkList *H)            //�жϵ������Ƿ�Ϊ��,����1��ʾΪ�գ�����0��ʾ��Ϊ��
{
    return(H->next==NULL);
}

int DispList(LinkList *H)            //���������H(������е���Ϣ.)
{
    int i;
    if(ListEmpty(H))
    {
    	printf("\n\n\n�˱�Ϊ�ձ����ܽ����������!\n\n");
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

LinkList *FindList(LinkList *H,char x[10])            //����Ԫ��x��λ��
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

void FindR()            //findr(findrecord)���Ҽ�¼
{
    int c;            //C���ڴ����Ҫ���ҵ�����
    char in[10];            //i(input)����������Ϣ
    LinkList *e;
    printf("��������ʲô���в��ң�\n1.ѧ��        2.����\n");
    scanf("%d",&c);
    if(c==1 || c==2)
    {
    	printf("������:\n");
    	scanf("%s",in);
    	e=FindList(H,in);
    	if(e->next!=NULL)
    	{
            if(c==1)
            {
	        printf("\nѧ��Ϊ%s����Ϣ��:\n\n",in);
	        printf("ѧ��: %-10s\n",e->data.xh);
	        printf("����: %-10s\n",e->data.xm);
	        printf("�绰: %-15s\n",e->data.lxfs);
	        printf("����: %-10s\n",e->data.qs);
	    }
	    else
	    {
	        printf("\n����Ϊ%s����Ϣ��:\n\n",in);
	        printf("ѧ��: %-10s\n",e->data.xh);
	        printf("����: %-10s\n",e->data.xm);
		printf("�绰: %-15s\n",e->data.lxfs);
	        printf("����: %-10s\n",e->data.qs);
	    }
	    printf("/////////////////////////////////////////////");
	}
	else
	    printf("\n\n�Ҳ������������Ϣ�������²���!\n\n");
	}
	else
	    printf("\n����Ĵ����д������²���!\n");
	printf("\n\n");
}

void InsertList(LinkList *H,LinkList *l)            //�������β����Ԫ�ؽ��
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
        printf("ѧ��Ϊ:\n%s\n��¼�ڱ��м������ڡ�\n�����²���!\n",l->data.xh);
    else
    {
    	s->data=l->data;
    	s->next=NULL;
    	p->next=s;
    	printf("\n��¼��ӳɹ�!\n");
    }
}

void AddR()            //����½��
{
    LinkList *s;
    s=(LinkList *)malloc(sizeof(LinkList));
    printf("��������Ҫ��ӵ���Ϣ���Կո�ָ���:\n����:20130000 ���� 18227580000 11��111\n�����룺\n");
    scanf("%s%s%s%s",s->data.xh,s->data.xm,s->data.lxfs,s->data.qs);
    InsertList(H,s);
}

void DeleteList(LinkList *H,char xh[10])            //��ѧ��ɾ����Ԫ��
{
    int i;
    if(H->next!=NULL)            //�ж��Ƿ�Ϊ��
    {
        LinkList *p=H->next,*r;
        for(i=0;strcmp(p->next->data.xh,xh);i++)
            p=p->next;
        r=p->next;
        p->next=r->next;
        free(r);
        printf("ѧ��Ϊ%s�ļ�¼��\nɾ���ɹ�!\n",xh);
    }
    else
        printf("\n\n�˱�Ϊ�ձ�������ɾ����!\n");
}
void DeleteR()
{
    int num;
    char xh[10];
    printf("��������Ҫɾ����¼��ѧ��:");
    scanf("%s",xh);
    printf("��ȷ��Ҫɾ��������\n1.ɾ��       2.��ɾ��\n");
    scanf("%d",&num);
    if(num==1)
        DeleteList(H,xh);
    else
        printf("�����²���!\n");
}

void ReleaseList(LinkList *H)            //�ͷŵ�����/���ȫ��(ɾ�����еĵ绰��¼)
{
    LinkList *p,*q;
    while(H->next!=NULL)
    {
        p=H->next;
        q=p->next;
        H->next=q;
        free(p);
    }
    printf("\n\n���еļ�¼ɾ���ɹ�����ǰû���κμ�¼!\n");
}

void EditList(LinkList *H,char *n1,char *n2,int k)            //�޸ļ�¼�е���Ϣ
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
	        default :printf("���������Ϣ������Ҫ����������!\n");
	    }
	}
    }
    else
        printf("\n\n�Ҳ�����Ҫ�޸ĵļ�¼!");
}

void Edit()
{
    int n,k=0;            //k�������ڴ���޸ĵı��
    char num1[10],num2[15];            //num[1]��������������Ϣ,num[2]����Ҫ����������
    printf("��������Ҫ�༭��¼��������ѧ��:");
    scanf("%s",num1);
    printf("�㽫Ҫ�޸�ʲô��Ϣ��\n");
    printf("1.����     2.ѧ��     3.�绰����     4.���ҵ�ַ\n");
    scanf("%d",&n);
    printf("���������������ݣ�");
    scanf("%s",num2);
    EditList(H,num1,num2,n);
}

int main()
{
    int i=0;
    int num;         /*��ų�ʼʱ����Ĵ���*/
    CreateList(40);
    printf("********************************************************\n");
    printf("       *******************************************\n");
    printf("       *      �ƽ̣�2����  �����ѯ              *\n");
    printf("       *******************************************\n");
    printf("********************************************************\n");
    while(1)
    {
        printf("�������ţ�\n");
        printf("1.����           2.���           3.ɾ����¼\n");
        printf("4.�����޸�       5.��պ����     6.�鿴��ǰ�����м�¼\n");
        printf("7.�˳�����\n\n");
        printf("��������Ҫ�����Ĵ��ţ�\n");
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
            default:printf("\n\n����Ĵ��Ų���ʶ�����������룺");
        }
        printf("\n\n");
    }
    return 0;
}


