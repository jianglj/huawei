/*找出2~200之间的素数*/
#include "iostream"
#include "iomanip"
using namespace std;

int main()
{
	const int M=200;
	const int N=((M+1)/2);
	int i,j,a[N];
	a[0]=2;
	for (i=0;i<(N-1);i++)
	{
		a[i]=2*i+1;
	}
	for (i=1;i<(N-1);i++)
		if(a[i]!=0)
			for(j=i+1;j<N;j++)
				if(a[j]%a[i]==0)
					a[j]=0;
	cout<<"the primer are [2-"<<M<<"]:\n";
	for (i=0;i<N;i++)
	{
		if(a[i]!=0)
			cout<<setw(5)<<a[i];
	}
}