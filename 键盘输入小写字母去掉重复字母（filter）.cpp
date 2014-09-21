/*
通过键盘输入一串小写字母(a~z)组成的字符串。请编写一个字符串过滤程序，若字符串中出现多个相同的字符，将非首次出现的字符过滤掉。
比如字符串"abacacde"过滤结果为"abcde"。
要求实现函数： 
void stringFilter(const char *pInputStr, long lInputLen, char *pOutputStr);
【输入】 pInputStr： 输入字符串
lInputLen： 输入字符串长度 
【输出】 pOutputStr： 输出字符串，空间已经开辟好，与输入字符串等长；
*/
#include <stdio.h>
#include<string.h>
#include<malloc.h>
#include "iostream"
using namespace std;

void stringFilter(const char *p_str, long len, char *p_outstr)
{
 int array[256]={0}; 
 const char *tmp = p_str;
 for(int j=0;j<len;j++)
 {
	 if(array[tmp[j]]==0)
		*p_outstr++= tmp[j];
	 array[tmp[j]]++;
 }
	*p_outstr = '\0';
	//cout<<*p_outstr<<endl;
}
void main()
{
	char  *str = "cccddecc";//不能定义为char*str[]，因为不能讲char*str[n]赋值给const char*型变量
	cout<<"压缩前字符串为："<<str<<endl;

	int len = strlen(str);	
		char * outstr = (char *)malloc(len*sizeof(char));
	stringFilter(str,len,outstr);
	cout<<"压缩后字符串为：";
	printf("%s\n",outstr);
	free(outstr);
	outstr = NULL;
}
