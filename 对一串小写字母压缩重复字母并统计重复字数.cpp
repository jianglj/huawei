/*通过键盘输入一串小写字母(a~z)组成的字符串。请编写一个字符串压缩程序，将字符串中连续出席的重复字母进行压缩，
并输出压缩后的字符串。
压缩规则：
1. 仅压缩连续重复出现的字符。比如字符串"abcbc"由于无连续重复字符，压缩后的字符串还是"abcbc".
2. 压缩字段的格式为"字符重复的次数+字符"。例如：字符串"xxxyyyyyyz"压缩后就成为"3x6yz"

要求实现函数： 
void stringZip(const char *pInputStr, long lInputLen, char *pOutputStr);
【输入】 pInputStr： 输入字符串
lInputLen： 输入字符串长度 
【输出】 pOutputStr： 输出字符串，空间已经开辟好，与输入字符串等长；
*/
#include <stdio.h>
#include<string.h>
#include<malloc.h>

void stringZip(const char *p_str, long len, char *p_outstr)
{
	int count=1;
	for(int i=0;i<len;i++)
	{
		if(p_str[i]==p_str[i+1])
		{
			count++;
		}
		else
		{
			if(count>1)
			{
				*p_outstr++ = count +'0';
				*p_outstr++ =p_str[i];
			}
			else
			{
				*p_outstr++ =p_str[i];
			}
			count = 1;//注意其位置
		}
	}
	*p_outstr = '\0';
}
void main()
{
	char *str = "cccddeccffgghhhhjhkk";
    printf("压缩之前的字符串为：%s\n",str);
	int len = strlen(str);
	char * outstr = (char*)malloc(len*sizeof(char));
	stringZip(str,len,outstr);
	printf("压缩之后的字符串为：%s\n",outstr);
	free(outstr);
	outstr = NULL;
}
