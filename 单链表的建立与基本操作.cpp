/*������Ľ������������*/
#include "iostream"
#include "malloc.h"
using namespace std;

typedef struct node
{
	int data;
	struct node *next;
}linklist;

linklist* creat(int n)//ͷ�巨������������ͷ���ǿգ�Ϊ��һ���ڵ�
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

void print(linklist*head)//�������Ԫ��ֵ
{
	while (head)
	{
		printf("%d ",head->data);
		head=head->next;
	}
}

linklist*Get(linklist*head,int i) //����Ų��������ֵ
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

linklist*Locate(linklist*head,int key) //��ֵ���ҵ���������
{
	linklist*p=head;     //Ҫ�ӵ�һ���ڵ㿪ʼ����,��ΪheadΪ��һ���ڵ㣨�ǿգ�
	while (p!=NULL&&p->data!=key)
		p=p->next;
	if(p==NULL) return NULL;
	else return p;
}


void InsertAfter(linklist*p,int x)//��ֵΪx���½ڵ����p�ڵ��
{
	linklist*s;
	s=(linklist*)malloc(sizeof(linklist));
	s->data=x;

	s->next=p->next; //�����ݲ������һ��Ԫ��֮���������𣿣�
	                 //�𣺲��ᣡ
	p->next=s;
}

void InsertBefore(linklist*head,linklist*p,int x)//��ֵΪx���½ڵ����p�ڵ�ǰ
{
	linklist*s,*q;
	s=(linklist*)malloc(sizeof(linklist));
	s->data=x;

	q=head;
	//�����ڵ�һ���ڵ�ǰ���������𣿣�
	//�𣺲��ܣ���Ϊ��һ���ڵ��ڴ�Ϊͷ��㣬��ͷ���û��ǰ���ڵ�
	//�����q->next��Ϊq����ô����ͷ������Ԫ��xʱ���γ������޵�ѭ�������ڵ���Ϊ2��head��s
	while(q->next!=p) 
		q=q->next;
	s->next=p;
	q->next=s;
}

void Delete(linklist*head,linklist*p)//ɾ������Ԫ��
{
	linklist*q;
	q=head;

	while (q->next!=p)//��ɾ�����һ�������ǲ���ɾ����һ�������ɺ�InsertBefore����
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
	cout<<"���봴��������Ľڵ����n:";
	cin>>n;
	cout<<"������������������ʾ��"<<endl;
	p=creat(n);
	print(p);
	cout<<endl;

	cout<<"���밴��Ų��ҷ���Ҫ���ҵ�Ԫ��,�������С�ڵ���"<<n<<endl;
	int m;
	cin>>m;
	q=Get(p,m);
	printf("���ҳɹ���Ԫ��Ϊ%d\n",q->data);
	
	r=q;
	cout<<"������������������Ԫ��ǰ���������"<<endl;
	int fn;
	cin>>fn;
	InsertBefore(p,r,fn);
	cout<<"�������ݺ��������Ϊ��"<<endl;
	print(p);
	cout<<endl;

	cout<<"��������������Ԫ��֮����������"<<endl;
	int an;
	cin>>an;
	InsertAfter(r,an);
	cout<<"�����������Ϊ��"<<endl;
	print(p);
	cout<<endl;

	cout<<"ɾ���������ҵ�Ԫ��"<<m<<endl;
	cout<<endl;

	Delete(p,r);
	cout<<"ɾ��������Ϊ"<<endl;
	print(p);
	cout<<endl;

	return 0;
}