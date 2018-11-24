#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

int s[12];
int a,b;
int ans[2000000];
int top=0;

bool isprime(int x)
{
	if (x==1) return false;
	int m=(int)(sqrt(x)+0.01);
	for (int i=2;i<=m;i++)
		if (x%i==0)
			return false;
	return true;
}

void work(int k,int n)
{
	int i;
	int sum=0;
	if (n==0)
	{
		for (i=1;i<=k;i++)
			sum=sum*10+s[i];
		for (i=k;i>=1;i--)
			sum=sum*10+s[i];
		if (sum>=a&&sum<=b&&isprime(sum))
			ans[++top]=sum;
		return ;
	}
	if (n==1)
	{
		for (i=1;i<=k;i++)
			sum=sum*10+s[i];
		int tmp=sum;
		if (k!=0)
		{
			for (int j=0;j<=9;j++)
			{
				sum=tmp*10+j;
				for (i=k;i>=1;i--)
					sum=sum*10+s[i];
				if (sum>=a&&sum<=b&&isprime(sum))
					ans[++top]=sum;
			}
		}
		else
		{
			for (int j=1;j<=9;j++)
			{
				sum=tmp*10+j;
				if (sum>=a&&sum<=b&&isprime(sum))
					ans[++top]=sum;
			}
		}
		return ;
	}
	if (k!=0)
	{
		for (i=0;i<=9;i++)
		{
			s[k+1]=i;
			work(k+1,n-2);
		}
	}
	if (k==0)
	{
		for (i=1;i<=9;i++)
		{
			s[k+1]=i;
			work(k+1,n-2);
		}
	}
}

int main()
{
	int i,n;
	freopen("1217.out","w",stdout);
	scanf("%d%d",&a,&b);
	memset(s,0,sizeof(s));
	for (i=1;i<=8;i++)
		work(0,i);
	sort(ans+1,ans+top+1);
	for (i=1;i<=top;i++)
		printf("%d\n",ans[i]);
	return 0;
}
