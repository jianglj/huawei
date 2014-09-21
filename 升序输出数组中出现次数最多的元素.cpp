/*统计一个数组中元素出现的次数，并按升序输出出现次数最多的元素*/
/*如输入[2,,3,6,4,4,4,9,9,9,10],则输出4,9*/

#include "iostream"
#include "algorithm"
#include "vector"
#include "map"
using namespace std;
vector <int> calcTimes(int num[], int len)
{
	vector<int> result;
	map<int,int> sum;

	map<int,int>::iterator it;
	//get the num's count
	for(int i=0;i<len;i++)
	{
		it = sum.find(num[i]);
		if(it != sum.end())
		{
			int t = it->second;
			sum.erase(it); //因为map中第一个int为关键之，具有唯一性，如果重复则不能插入，故而当检查到
			              //重复关键字时要先擦除这个位置的map，然后再插入才有效
			             //也可以用数组形式的插入，它没有这一限制：如sum[int1]=int2;即可
			sum.insert(pair<int,int>(num[i],t+1));
		}
		else
			sum.insert(pair<int,int>(num[i],1));
	}
	//get the element
	it = sum.begin();
	
	int max = INT_MIN; //int 的最小值，使用前应包含#include"limits.h"
	for(;it != sum.end();it++)
	{
		if(it->second > max)
		{
			max = it->second;
			result.clear();
			result.push_back(it->first);
		}
		else if(it->second == max)
		{
			result.push_back(it->first);
		}
	}
//	sort(result.begin(),result.end());//可以不用对vector排序，因为map已经自动排序了
	return result; //容器返回的是全部元素
}
int main()
{
//	int a[10]={1,1,3,4,4,4,9,9,9,10};  //静态的测试数据
	int n;                   //动态的输入n个数据进行测试
	cout<<"输入数据个数n：";
	cin>>n;
	int *a=new int [n];
	cout<<"输入n个整型数据：";
	for (int i=0;i<n;i++)   cin>>a[i];

	vector <int> jieguo;  //结果输出函数
	jieguo=calcTimes(a,n);
	vector <int>::iterator itt=jieguo.begin();
	for (itt=jieguo.begin();itt!=jieguo.end();itt++)
		cout<<*itt<<endl;
	return 0;
}