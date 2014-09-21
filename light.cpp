#include <stdio.h>
#include <iostream>
using namespace std;


int main()
{
	int x,total=0;
	short light[65536]={0};  //0~x-1
	cin>>x;
	if( x>=1 && x<=65535 )
	{
		for(int i=1; i<=x; i++)
		{
			for(int j=i-1; j<x; j+=i)
			{
				light[j] = (light[j]==0)? 1:0;
			}
		}
		for(int i=0; i<x; i++)
		{
			cout<<light[i]<<" ";
			total += light[i];
		}
		cout<<"total="<<total<<endl;

	}
	else
		cout<<"error";
	cout<<endl<<"press 0+enter to exit";
	cin>>x;
	return 0;
}