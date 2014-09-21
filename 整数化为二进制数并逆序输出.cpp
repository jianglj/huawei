/*整数化为2进制数，并逆序输出*/
#include "iostream"
using namespace std;

int main()
{
	int m;
	cout<<"输入要转化的正整数：";
	cin>>m;
	int a[32]={0},i=0,j;
	while (m>0)
	{
		a[i]=m%2; //如果转换成16进制，可以将m改为
		         //M[m%16]的表，M表中存0~F字符
		         //并且a[]也要定义成char型数据
		i++;
		m/=2;
	}
	for (j=0;j<i;j++)
	{
		cout<<a[j];
	}
	cout<<"正序为：";
	for (j=i-1;j>=0;j--)
	{
		cout<<a[j];
	}
	return 0;
}