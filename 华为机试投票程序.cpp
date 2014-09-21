#include <iostream>
#include <string>
#include <map>
#include "vector"
#include "algorithm"
using namespace std;

//此法可以按照不排序输出，符合题意
int main ()
{
	int invalid = 0;

	vector<pair<string,int>> VoteResult;
	vector<pair<string,int>>::iterator it;

	string str1 , str2 ;
	int i=0;
	int found=0;
	while(1)
	{
		cin >> str1;
		if ( str1 == "addCandidate" )
		{
			cin >> str2 ;
			for (it=VoteResult.begin();it!=VoteResult.end();it++)
			{
				if (it->first==str2)
				{
					found=1;
					break;
				}
			}
			if(found!=1)
				VoteResult.push_back(make_pair(str2,0));
		}
		else if( str1 == "vote")
		{
			cin >> str2 ;
			found=0;
			for (it=VoteResult.begin();it!=VoteResult.end();it++)
			{
				if (it->first==str2)
				{
					found=1;
					break;
				}
			}
			if (found==1)
				it->second+=1;
			else
				invalid += 1;
		}
		else if( str1 == "getVoteResult" )
		{
			for ( it = VoteResult.begin() ; it != VoteResult.end(); it++ )
				cout << (*it).first << " " << (*it).second << endl;
			cout << invalid <<endl;
			return 0;
		}
	}
	return 0;
}