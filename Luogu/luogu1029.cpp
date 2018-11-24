#include<cstdio>
#include<cmath>
using namespace std;

bool vis[1000009];
int c[1000000];
int a[1000000];

int main()
{
	int p,q,i,j;
	scanf("%d%d",&p,&q);
	for (i=0;i<=q;i++)
		vis[i]=0;
	int top=0;
	int m=(int)sqrt(q+0.5);
	for (i=2;i<=q;i++)
		if (!vis[i])
		{
			c[++top]=i;
			if (i<=m)
			{
				for (j=i*i;j<=q;j+=i)
					vis[j]=true;
			}
		}
	for (i=1;i<=top;i++)
	{
		while(q%c[i]==0)
		{
			a[i]++;
			q/=c[i];
		}
		while(p%c[i]==0)
		{
			a[i]--;
			p/=c[i];
		}
	}
	int n=0;
	for (i=1;i<=top;i++)
		if (a[i]>0)
			n++;
		else if (a[i]<0)
		{
			printf("0\n");
			return 0;
		}
	printf("%d\n",1<<n);
	return 0;
}
