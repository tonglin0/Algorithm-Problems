#include<cstdio>
#include<cstring>
using namespace std;

const char id[]="0123456789ABCDEFGHIJ";
int a[103];

int main()
{
	int top=0,k,n,i;
	scanf("%d%d",&n,&k);
	printf("%d=",n);
	memset(a,0,sizeof(a));
	while(n)
	{
		a[++top]+=n%k;
		if (a[top]<0)
		{
			a[top]-=k;
			a[top+1]+=1;
		}
		while (a[top]>=-k)
		{
			a[top]+=k;
			a[top+1]--;
		}
		n/=k;
	}
	if (a[top+1]!=0) top++;
	while(1)
	{
		if (a[top]<0)
		{
			a[top]-=k;
			a[top+1]+=1;
			top++;
		}
		else if (a[top]>=-k)
		{
			a[top]+=k;
			a[top+1]--;
			top++;
		}
		else
			break;
	}
	for (i=top;i>=1;i--)
		printf("%c",id[a[i]]);
	printf("(base%d)\n",k);
	return 0;
}
