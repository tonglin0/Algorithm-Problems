#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;

bool vis[20003];
int s[10003]; 

int main()
{
	int top=0,n,i,j,k;
	scanf("%d",&n);
	for (i=0;i<=n;i++)
		vis[i]=false;
	int m=(int)(sqrt(n+0.5));
	for (i=2;i<=m;i++)
		if (!vis[i])
		{
			s[++top]=i;
			for (j=i*i;j<=n;j+=i)
				vis[j]=true;
		}
	for (i=1;i<=top;i++)
		for (j=1;j<=top;j++)
			if (!vis[n-s[i]-s[j]])
			{
				printf("%d %d %d\n",s[i],s[j],n-s[i]-s[j]);
				return 0;
			}
}

