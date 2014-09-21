/*
�ִ�ת��
����������
��������ַ������ַ���������Сд��ĸ'a'��'z'�����������¹���ѭ��ת���������a->b,b->c,��,y->z,z->a��
��������ַ�����������������ĸ��ͬʱ����һ����ĸ��Ҫ����ת��2�Ρ�
���磺aa ת��Ϊ bc��zz ת��Ϊ ab����������ͬ��ĸ��������ʱ�����������ֵ���ĸ����һ�γ����㡣
Ҫ��ʵ�ֺ�����
void convert(char *input,char* output)
�����롿 char *input , ������ַ���
������� char *output ��������ַ���
�����ء� ��
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
