/*
字串转换
问题描述：
将输入的字符串（字符串仅包含小写字母'a'到'z'），按照如下规则，循环转换后输出：a->b,b->c,…,y->z,z->a；
若输入的字符串连续出现两个字母相同时，后一个字母需要连续转换2次。
例如：aa 转换为 bc，zz 转换为 ab；当连续相同字母超过两个时，第三个出现的字母按第一次出现算。
要求实现函数：
void convert(char *input,char* output)
【输入】 char *input , 输入的字符串
【输出】 char *output ，输出的字符串
【返回】 无
*/

#include<iostream>
#include<string.h>
#include<stdlib.h>

void convert(char* input,char* output)
{
	if(input==NULL)
		return;
	char temp='\0';
	int len_input=strlen(input);
	int i;
	int flag=0;

	for(i=0;i<len_input;i++)
	{
		if(input[i]!=temp)
		{
			output[i]=(input[i]-'a'+1)%26+'a';
			temp=input[i];
			flag=1;
		}
		else
		{
			if(flag==1)
			{
				output[i]=(input[i]-'a'+2)%26+'a';
				temp=input[i];
				flag=0;
			}
			else
			{
				output[i]=(input[i]-'a'+1)%26+'a';
				temp=input[i];
				flag=1;
			}
		}
	}
	output[i]='\0';
}

void main()
{
	char *input="xyzabbcdeee";
		
	char output[256];
	convert(input,output);
	printf("%s\n",input);
	printf("%s\n",output);
}
