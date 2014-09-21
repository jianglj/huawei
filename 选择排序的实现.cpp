/*函数实现选择法排序数组*/
#include "iostream"
using namespace std;

int main()
{
	void select_sort(int array[],int n);
	int a[10]={12,43,34,6,73,123,123,45,2354,2};
	select_sort(a,10);
	for (int i=0;i<10;i++)
	{
		cout<<a[i]<<endl;
	}
	return 0;
}

void select_sort(int array[],int n)
{
	int i,j,k,t;
	for (i=0;i<n-1;i++)
	{
		k=i;
		for (j=i+1;j<n;j++)
		{
			if(array[j]<array[k])
				k=j;
			t=array[k];
			array[k]=array[i];
			array[i]=t;
		}
	}
}