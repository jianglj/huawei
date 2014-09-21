/*在一组数据中找出含有指定字符的数据，并将这些数据升序输出*/
/*例如，一组数据为：[123,23,4231,231，1213,32],指定字符为23，则输出结果为：[23，123,231,4231]*/

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
	qsort(num,len,sizeof(int),compare);   //使用快速排序例程进行排序
	//sort(vec.begin(),vec,end())默认升序排序，若要降序可用
	//bool cmp(const int &a,const int &b){return a>b;}  sort(vec.begin(),vec.end(),cmp);
	//也可用sort升序排序完成后用，元素翻转函数reverse(vec.begin(),vec.end());
	int n=1,tmp=value;
	while(tmp!=0)  //求出tmp是几位数
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
	for( int i=0;i<data.size();i++)//这里完全是为了返回需要。。。主要是端口限制带来的麻烦
	{
		result[i] = data[i];
	}
	cout<<endl;
	vector<int>::iterator it;   //这是容器输出的一种方式，也可以用data[i]的方式输出
	for (it=data.begin();it!=data.end();it++)
	{
		cout<<*it<<endl;
	}
	return result; //只返回数组的首个元素或者首元素地址
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
