/*
ͨ����������һ��Сд��ĸ(a~z)��ɵ��ַ��������дһ���ַ������˳������ַ����г��ֶ����ͬ���ַ��������״γ��ֵ��ַ����˵���
�����ַ���"abacacde"���˽��Ϊ"abcde"��
Ҫ��ʵ�ֺ����� 
void stringFilter(const char *pInputStr, long lInputLen, char *pOutputStr);
�����롿 pInputStr�� �����ַ���
lInputLen�� �����ַ������� 
������� pOutputStr�� ����ַ������ռ��Ѿ����ٺã��������ַ����ȳ���
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
	char  *str = "cccddecc";//���ܶ���Ϊchar*str[]����Ϊ���ܽ�char*str[n]��ֵ��const char*�ͱ���
	cout<<"ѹ��ǰ�ַ���Ϊ��"<<str<<endl;

	int len = strlen(str);	
		char * outstr = (char *)malloc(len*sizeof(char));
	stringFilter(str,len,outstr);
	cout<<"ѹ�����ַ���Ϊ��";
	printf("%s\n",outstr);
	free(outstr);
	outstr = NULL;
}
