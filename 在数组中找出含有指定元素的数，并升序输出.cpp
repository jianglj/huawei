/*��һ���������ҳ�����ָ���ַ������ݣ�������Щ�����������*/
/*���磬һ������Ϊ��[123,23,4231,231��1213,32],ָ���ַ�Ϊ23����������Ϊ��[23��123,231,4231]*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<climits>
using namespace std;
int compare (const void * a, const void * b)
{
	return ( *(int*)a - *(int*)b );
}

int *calcTimes(int num[], int len,int value)
{
	vector<int> data;
	qsort(num,len,sizeof(int),compare);   //ʹ�ÿ����������̽�������
	//sort(vec.begin(),vec,end())Ĭ������������Ҫ�������
	//bool cmp(const int &a,const int &b){return a>b;}  sort(vec.begin(),vec.end(),cmp);
	//Ҳ����sort����������ɺ��ã�Ԫ�ط�ת����reverse(vec.begin(),vec.end());
	int n=1,tmp=value;
	while(tmp!=0)  //���tmp�Ǽ�λ��
	{
		n*=10;
		tmp/=10;
	}
	int reminder=0;
	for(int i=0;i<len;i++)
	{
		if(num[i] < n && num[i] != value)
			continue;
		else if(num[i] == value)
		{
			data.push_back(num[i]);
		}
		else
		{
			tmp = num[i];
			while(tmp >= value)
			{
				reminder = tmp%n;
				if(reminder == value)
				{
					data.push_back(num[i]);
					break;
				}
				else
				{
					tmp/=10;
				}

			}
		}
	}
	int *result = new int[data.size()];
	for( int i=0;i<data.size();i++)//������ȫ��Ϊ�˷�����Ҫ��������Ҫ�Ƕ˿����ƴ������鷳
	{
		result[i] = data[i];
	}
	cout<<endl;
	vector<int>::iterator it;   //�������������һ�ַ�ʽ��Ҳ������data[i]�ķ�ʽ���
	for (it=data.begin();it!=data.end();it++)
	{
		cout<<*it<<endl;
	}
	return result; //ֻ����������׸�Ԫ�ػ�����Ԫ�ص�ַ
}
int main()
{
	int len,value;
	cout<<"enter len and value";
	cin>>len>>value;
	int *data = new int[len];
	cout<<"enter len numbers of data[len]";
	for(int i=0;i<len;i++)
	{
		cin>>data[i];
	}
	int *result = calcTimes(data,len,value);
	delete[] data;
	return 0;
}
