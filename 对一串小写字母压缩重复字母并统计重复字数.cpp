/*ͨ����������һ��Сд��ĸ(a~z)��ɵ��ַ��������дһ���ַ���ѹ�����򣬽��ַ�����������ϯ���ظ���ĸ����ѹ����
�����ѹ������ַ�����
ѹ������
1. ��ѹ�������ظ����ֵ��ַ��������ַ���"abcbc"�����������ظ��ַ���ѹ������ַ�������"abcbc".
2. ѹ���ֶεĸ�ʽΪ"�ַ��ظ��Ĵ���+�ַ�"�����磺�ַ���"xxxyyyyyyz"ѹ����ͳ�Ϊ"3x6yz"

Ҫ��ʵ�ֺ����� 
void stringZip(const char *pInputStr, long lInputLen, char *pOutputStr);
�����롿 pInputStr�� �����ַ���
lInputLen�� �����ַ������� 
������� pOutputStr�� ����ַ������ռ��Ѿ����ٺã��������ַ����ȳ���
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
			count = 1;//ע����λ��
		}
	}
	*p_outstr = '\0';
}
void main()
{
	char *str = "cccddeccffgghhhhjhkk";
    printf("ѹ��֮ǰ���ַ���Ϊ��%s\n",str);
	int len = strlen(str);
	char * outstr = (char*)malloc(len*sizeof(char));
	stringZip(str,len,outstr);
	printf("ѹ��֮����ַ���Ϊ��%s\n",outstr);
	free(outstr);
	outstr = NULL;
}
