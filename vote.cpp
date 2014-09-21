#include "iostream"
#include "cstring"//字符串操作函数
#include "string" //可以定义string类
using namespace std;


struct Result 
{
	string candidate;
	int cnt;
}voteResult[100];

int main1struct()
{
	string s1;
	string s2;
	int i=0;
	int err=0;

	while (1)
	{
		cin>>s1;
		if (s1=="addCandidate")
		{
			cin>>s2;
			voteResult[i++].candidate=s2;
		}
		else if (s1=="vote")
		{
			cin>>s2;
			for (int j=0;j<i;j++)
			{
				if (voteResult[j].candidate==s2)
				{
					voteResult[j].cnt++;
					break;
				}
				if(j==i-1)
					err++;
			}
		}
		else if (s1=="getVoteResult")
		{
			for (int k=0;k<i;k++)
			{
				cout<<voteResult[k].candidate<<" "<<voteResult[k].cnt<<endl;
			}
			cout<<err<<endl;
			return 0;
		}
	}
	
	return 0;
}
