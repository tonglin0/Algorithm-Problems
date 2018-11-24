#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#define MOD 10086
#define lint long long
using namespace std;

int a[100005];
char ch;

void read(int &x)
{
	while(ch=getchar(),ch<'0'||ch>'9');
	x=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9') x=x*10+ch-'0';
}

int gause(int n,int m)
{
	int i=1,j=1;
	while(i<=n&&j<=m)
	{
		int r=i;
		for (int u=i;u<=n;u++)
			if (a[u]&(1<<(31-j)))
			{
				r=u;
				break;
			}
		if (a[r]&(1<<(31-j)))
		{
			if (r!=i)
				swap(a[i],a[r]);
			for (int k=1;k<=n;k++)
				if (k!=i&&(a[k]&(1<<(31-j))))
					a[k]^=a[i];
			i++;
		}
		j++;
	}
	return i-1;
}

int main()
{
	freopen("2844.in","r",stdin);
	freopen("2844.out","w",stdout);
	int n,m,i;
	read(n);
	for (i=1;i<=n;i++)
		read(a[i]);
	read(m);
	int r=gause(n,31);
	int cur=0;
	int ans=0;
	for (i=1;i<=r;i++)
		if ((cur^a[i])<=m)
		{
			cur^=a[i];
			ans=(ans+(1<<(r-i)))%MOD;
			if (cur==m)
				break;
		}
	for (i=1;i<=n-r;i++)
		ans=ans*2%MOD;
	printf("%d\n",(ans+1)%MOD);
	return 0;
}