#include <stdio.h>
#define N 30

int main()
{
	int a[N],n=0,i,temp,min,max;
	char c='0';
	max = 0;
	min = 100;

	while(c != '\n')
	{
		scanf("%d",&temp);
		a[n] = temp;
		if(temp > max) max = temp;
		if(temp < min) min = temp;
		n++;
		scanf("%c",&c);
	}
	temp = 0;

	for(i=0;i<n;i++)
	{
			printf("%d ",a[i]);

		if(a[i]<max && a[i]>min)
			temp++;
	}
	printf("%d",temp);
	scanf("%c",&c);
	return 0;
}