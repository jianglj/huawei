/*ͳ��һ��������Ԫ�س��ֵĴ�������������������ִ�������Ԫ��*/
/*������[2,,3,6,4,4,4,9,9,9,10],�����4,9*/

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
			sum.erase(it); //��Ϊmap�е�һ��intΪ�ؼ�֮������Ψһ�ԣ�����ظ����ܲ��룬�ʶ�����鵽
			              //�ظ��ؼ���ʱҪ�Ȳ������λ�õ�map��Ȼ���ٲ������Ч
			             //Ҳ������������ʽ�Ĳ��룬��û����һ���ƣ���sum[int1]=int2;����
			sum.insert(pair<int,int>(num[i],t+1));
		}
		else
			sum.insert(pair<int,int>(num[i],1));
	}
	//get the element
	it = sum.begin();
	
	int max = INT_MIN; //int ����Сֵ��ʹ��ǰӦ����#include"limits.h"
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
//	sort(result.begin(),result.end());//���Բ��ö�vector������Ϊmap�Ѿ��Զ�������
	return result; //�������ص���ȫ��Ԫ��
}
int main()
{
//	int a[10]={1,1,3,4,4,4,9,9,9,10};  //��̬�Ĳ�������
	int n;                   //��̬������n�����ݽ��в���
	cout<<"�������ݸ���n��";
	cin>>n;
	int *a=new int [n];
	cout<<"����n���������ݣ�";
	for (int i=0;i<n;i++)   cin>>a[i];

	vector <int> jieguo;  //����������
	jieguo=calcTimes(a,n);
	vector <int>::iterator itt=jieguo.begin();
	for (itt=jieguo.begin();itt!=jieguo.end();itt++)
		cout<<*itt<<endl;
	return 0;
}