/*单链表的建立与基本操作*/
#include "iostream"
#include "malloc.h"
using namespace std;

typedef struct node
{
	int data;
	struct node *next;
}linklist;

linklist* creat(int n)//头插法建立单链表，即头结点非空，为第一个节点
{
	linklist*head,*New,*tail;
	head=NULL;
	tail=NULL;
	for (int i=1;i<=n;i++)
	{
		New=(linklist*)malloc(sizeof(linklist));
		New->data=i;

		if(head==NULL) head=New;
		else tail->next=New;
		tail=New;
	}
	if(tail!=NULL) tail->next=NULL;
	return head;
}

void print(linklist*head)//输出链表元素值
{
	while (head)
	{
		printf("%d ",head->data);
		head=head->next;
	}
}

linklist*Get(linklist*head,int i) //按序号查找链表的值
{
	int j=1;
	linklist*p=head;
	while (p!=NULL&&j<i)
	{
		p=p->next;
		j++;
	}
	if(i==j) return p;
	else return NULL;
}

linklist*Locate(linklist*head,int key) //按值查找单链表数据
{
	linklist*p=head;     //要从第一个节点开始查找,因为head为第一个节点（非空）
	while (p!=NULL&&p->data!=key)
		p=p->next;
	if(p==NULL) return NULL;
	else return p;
}


void InsertAfter(linklist*p,int x)//将值为x的新节点插入p节点后
{
	linklist*s;
	s=(linklist*)malloc(sizeof(linklist));
	s->data=x;

	s->next=p->next; //将数据插入最后一个元素之后会出问题吗？？
	                 //答：不会！
	p->next=s;
}

void InsertBefore(linklist*head,linklist*p,int x)//将值为x的新节点插入p节点前
{
	linklist*s,*q;
	s=(linklist*)malloc(sizeof(linklist));
	s->data=x;

	q=head;
	//不能在第一个节点前插入数据吗？？
	//答：不能，因为第一个节点在此为头结点，而头结点没有前驱节点
	//如果将q->next改为q，那么当在头结点插入元素x时就形成了无限的循环链表，节点数为2：head和s
	while(q->next!=p) 
		q=q->next;
	s->next=p;
	q->next=s;
}

void Delete(linklist*head,linklist*p)//删除链表元素
{
	linklist*q;
	q=head;

	while (q->next!=p)//能删除最后一个，但是不能删除第一个，理由和InsertBefore类似
		q=q->next;
	q->next=p->next;
	free(p);
}

int main()
{
	linklist*p=(linklist*)malloc(sizeof(linklist));
	linklist*q=(linklist*)malloc(sizeof(linklist));
	linklist*r=(linklist*)malloc(sizeof(linklist));

	int n;
	cout<<"输入创建单链表的节点个数n:";
	cin>>n;
	cout<<"建立的新链表如下所示："<<endl;
	p=creat(n);
	print(p);
	cout<<endl;

	cout<<"输入按序号查找法想要查找的元素,输入序号小于等于"<<n<<endl;
	int m;
	cin>>m;
	q=Get(p,m);
	printf("查找成功：元素为%d\n",q->data);
	
	r=q;
	cout<<"输入在链表上述查找元素前插入的数据"<<endl;
	int fn;
	cin>>fn;
	InsertBefore(p,r,fn);
	cout<<"插入数据后的新链表为："<<endl;
	print(p);
	cout<<endl;

	cout<<"在链表上述查找元素之后插入的数据"<<endl;
	int an;
	cin>>an;
	InsertAfter(r,an);
	cout<<"插入后新链表为："<<endl;
	print(p);
	cout<<endl;

	cout<<"删除上述查找的元素"<<m<<endl;
	cout<<endl;

	Delete(p,r);
	cout<<"删除后链表为"<<endl;
	print(p);
	cout<<endl;

	return 0;
}