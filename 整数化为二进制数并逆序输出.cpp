/*������Ϊ2�����������������*/
#include "iostream"
using namespace std;

int main()
{
	int m;
	cout<<"����Ҫת������������";
	cin>>m;
	int a[32]={0},i=0,j;
	while (m>0)
	{
		a[i]=m%2; //���ת����16���ƣ����Խ�m��Ϊ
		         //M[m%16]�ı�M���д�0~F�ַ�
		         //����a[]ҲҪ�����char������
		i++;
		m/=2;
	}
	for (j=0;j<i;j++)
	{
		cout<<a[j];
	}
	cout<<"����Ϊ��";
	for (j=i-1;j>=0;j--)
	{
		cout<<a[j];
	}
	return 0;
}