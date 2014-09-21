/*
ͨ��������������һ���ַ������У��ַ������ܰ�������Ӵ����Ӵ��Կո�ָ���
���дһ�������Զ�����������Ӵ�����ʹ��','����ָ������������Ҳ����һ��','�����Ӵ��洢�� 
�������"abc def gh i        d"���������abc,def,gh,i,d, 
 
Ҫ��ʵ�ֺ�����   
void DivideString(const char *pInputStr, long lInputLen, char *pOutputStr); 
�����롿  pInputStr��  �����ַ��� 
          lInputLen��  �����ַ�������                   
�������  pOutputStr��  ����ַ������ռ��Ѿ����ٺã��������ַ����ȳ��� 
��ע�⡿ֻ��Ҫ��ɸú��������㷨���м䲻��Ҫ���κ�IO ��������� 
ʾ��   
���룺"abc def gh i        d"
�����"abc,def,gh,i,d,"
*/
#include "iostream"
#include "cstring"
#include "malloc.h"
using namespace std;

void DivideString(const char* pInputStr , long lInputLen , char* pOutputStr)  
{  
  int i , j;  
  bool flag;  
    for(i = 0 ; pInputStr[i] == ' ' ; ++i)   //�����ַ���ǰ��Ŀո�  
        ;  
	    flag = true;  
	    for(j = 0 ; i < lInputLen ; ++i)  
	    {  
        if(pInputStr[i] != ' ')  
       {  
	            if(!flag)  
               flag = true;  
	            pOutputStr[j++] = pInputStr[i];    //�������Ӵ����뱣������  
        }  
	        else  
       {  
            if(flag)  
	                pOutputStr[j++] = ',';  
            flag = false;  
	        }  
	    }  
	    pOutputStr[j++] = ',';  
	    pOutputStr[j++] = '\0';  
}  

int main()
{
	char *input="abcd efg hijkl mn opq      china";
	int len=strlen(input);
	char* output=(char*)malloc(len*sizeof(char));
	DivideString(input,len,output);
	cout<<output<<endl;
	return 0;
}
