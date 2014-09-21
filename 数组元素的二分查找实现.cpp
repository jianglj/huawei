//数组元素的二分查找法,其中数组是输入一个值来指定其大小，然后依次输入
#include "iostream"
#include "algorithm"
using namespace std;

int main()
{
	int n;
	cout<<"请输入想要输入数据的个数："<<endl;
	cin>>n;
	int *a=new int [n];
	for (int i=0;i<n;i++)
	{
		cout<<"请输入第"<<i+1<<"个数字：";
		cin>>a[i];
	}
	sort(a,a+n);

	int low,high,mid,index=-1;
	int m;
	low=0;
	high=n;
	cout<<"输入要查找的元素值：";
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
		cout<<"查找的元素是数列中的第"<<index+1<<"个元素"<<endl;
	}
	else
		cout<<"没有查找到"<<endl;
	delete [] a;
	return 0;
}