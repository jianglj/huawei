/*����������

��������֪2��������·������AΪ���ߣ�BΪ��������·����·����˫��ġ�
������վ�����ֱ����£������߽���Ļ��˵���T1��T2��ʾ��
��д����������������վ�����ƣ������������������Ҫ�����ĳ�վ����
��������������յ㣬����վ��ֻ����һ�Σ���
������A�����ߣ�������վ��A1 A2 A3 A4 A5 A6 A7 A8 A9 T1 A10 A11 A12 A13 T2 A14 A15 A16 A17 A18
������B��ֱ�ߣ�������վ��B1 B2 B3 B4 B5 T1 B6 B7 B8 B9 B1!0 T2 B11 B12 B13 B14 B15

���룺����������ͬ��վ��

�������������վ��
*/

#include "stdafx.h"
#include <math.h>
#include <stdio.h>
#include <iostream>
using namespace std;

int a[19]={0},b[16]={0},t[3]={0};

int min(int a,int b)
{return (a>b)?b:a;}

int stepNext(char line,int num,int stations)
{
	cout<<line<<num<<" ";

	if(line=='a')
	{

		if(a[num]<stations && a[num]!=0)
		{
			return 1;
		}
		else 
		{
			a[num] =stations;
			switch(num)
			{
			case 9:
				return 1+min(stepNext('t',1,stations+1),stepNext('a',8,stations+1));
			case 10:
				return 1+min(stepNext('t',1,stations+1),stepNext('a',11,stations+1));
			case 13:
				return 1+min(stepNext('t',2,stations+1),stepNext('a',12,stations+1));
			case 14:
				return 1+min(stepNext('t',2,stations+1),stepNext('a',15,stations+1));
			case 1:
				return 1+min(stepNext('a',2,stations+1),stepNext('a',18,stations+1));
			case 18:
				return 1+min(stepNext('a',1,stations+1),stepNext('a',17,stations+1));
			default:
				return 1+min(stepNext(line,num-1,stations+1),stepNext(line,num+1,stations+1));
			}
		}
	}
	
	else if(line=='b')
	{
		if(b[num]<stations && b[num]!=0)
		{
			return 1;
		}
		else 
		{
			b[num] =stations;
			switch(num)
			{
			case 5:
				return 1+min(stepNext('b',4,stations+1),stepNext('t',1,stations+1));
			case 6:
				return 1+min(stepNext('b',7,stations+1),stepNext('t',1,stations+1));
			case 10:
				return 1+min(stepNext('b',9,stations+1),stepNext('t',2,stations+1));
			case 11:
				return 1+min(stepNext('b',12,stations+1),stepNext('t',2,stations+1));
			case 1:
				return 1+stepNext('b',2,stations+1);
			case 15:
				return 1+stepNext('b',14,stations+1);
			default:
				return 1+min(stepNext(line,num-1,stations+1),stepNext(line,num+1,stations+1));
			}
		}
	}

	else if(line=='t')
	{
		if(t[num]<stations && t[num]!=0)
		{
			return 1;
		}
		else 
		{
			t[num] =stations;
			switch(num)
			{
			case 1:
				return 1+min(min(stepNext('a',9,stations+1),stepNext('a',10,stations+1)),min(stepNext('b',5,stations+1),stepNext('b',6,stations+1)));
			case 2:
				return 1+min(min(stepNext('a',13,stations+1),stepNext('a',14,stations+1)),min(stepNext('b',10,stations+1),stepNext('b',11,stations+1)));
			default:
				return 0;
			}
		}
	}

	return 0;
}


int main_metro(int argc, _TCHAR* argv[])
{
	int stations=0;
		char x[4],y[4];
	int station1=0,station2=0;
	cin>>x>>y;
		for(int i=1;i<4;i++)
			if((int)x[i] != 0){
				station1=station1*10+((int)x[i]-48);
			}
			else
				break;

		cout<<x<<",station1="<<station1<<endl;

		
		for(int i=1;i<4;i++)
			if(y[i] != 0)
				station2=station2*10+((int)y[i]-48);
			else
				break;

		cout<<y<<",station2="<<station2<<endl;



	if(y[0]=='a' ||y[0]=='A')
	{
		y[0]='a';
		//a[station2] = 2;
	}
	else if(y[0]=='b' ||y[0]=='B')
	{
		y[0]='b';
		//b[station2] = 2;
	}
	else if(y[0]=='t' ||y[0]=='T')
	{
		y[0]='t';
		//t[station2] = 2;
	}
	else
	{
		printf("error station name!");
		return 0;
	}

		if(x[0]=='a' ||x[0]=='A')
	{
		x[0]='a';
		//a[station1] = true;
	}
	else if(x[0]=='b' ||x[0]=='B')
	{
		x[0]='b';
		//b[station1] = true;
	}
	else if(x[0]=='t' ||x[0]=='T')
	{
		x[0]='t';
		//t[station1] = true;
	}
	else
	{
		printf("error station name!");
		return 0;
	}

	stepNext(x[0],station1,1);

	cout<<endl;
	for(int i=1;i<19;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	for(int i=1;i<16;i++)
		cout<<b[i]<<" ";
	cout<<endl<<t[1]<<t[2];

/*	if(y[0]=='a')
	 cout<<a[station2];
	else if(y[0]=='b')
		cout<<b[station2];
	else cout<<t[station2];*/
	//cout<<stations<<endl;
	return 0;
}
