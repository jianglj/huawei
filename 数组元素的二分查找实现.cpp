//����Ԫ�صĶ��ֲ��ҷ�,��������������һ��ֵ��ָ�����С��Ȼ����������
#include "iostream"
#include "algorithm"
using namespace std;

int main()
{
	int n;
	cout<<"��������Ҫ�������ݵĸ�����"<<endl;
	cin>>n;
	int *a=new int [n];
	for (int i=0;i<n;i++)
	{
		cout<<"�������"<<i+1<<"�����֣�";
		cin>>a[i];
	}
	sort(a,a+n);

	int low,high,mid,index=-1;
	int m;
	low=0;
	high=n;
	cout<<"����Ҫ���ҵ�Ԫ��ֵ��";
	cin>>m;

	while (low<=high)
	{
		mid=(low+high)/2;
		if (a[mid]==m)
		{
			index=mid;
			break;
		}
		else if (a[mid]>m)
		{
			high=mid-1;
		}
		else
		{
			low=mid+1;
		}
	}
	if (index>=0)
	{
		cout<<"���ҵ�Ԫ���������еĵ�"<<index+1<<"��Ԫ��"<<endl;
	}
	else
		cout<<"û�в��ҵ�"<<endl;
	delete [] a;
	return 0;
}