/*
�ַ���M������NΪ��λ�Ķ�
����m���ַ��� ��һ������n, ���ַ���M������NΪ��λ�ĶΣ������λ����0���롣
�� n=8 m=9 ��
123456789����Ϊ��12345678
90000000
123��Ϊ ��12300000
*/
#include "iostream"
using namespace std;

int main()
{
	int m,n;
	char str[100]={'\0'};
	int len;
	int yu,shang;
	
	printf("�����ַ����ַ�������");
	scanf("%d",&m);

	scanf("%s",&str);
	len=strlen(str);

	printf("����n��ֵ��");
	scanf("%d",&n);

	yu=len%n;
	for (int i=0;i<len;i++)
	{
		if(i%n==0)
			printf("\n%c",str[i]);
		else 
			printf("%c",str[i]);
	}
	if (yu==0)
		;
	else
	{
		for(int i=yu+1;i<=n;i++)
			printf("0");
		printf("\n");
	}
	return 0;
}