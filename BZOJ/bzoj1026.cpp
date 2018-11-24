#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#define lint long long
using namespace std;

lint f[14][12];
int c[12];

int find(int n)
{
	int len=0;
	while(n)
	{
		c[++len]=n%10;
		n/=10;
	}
	int ans=0;
	for (int i=1;i<len;i++)
		for (int j=1;j<=9;j++)
			ans+=f[i][j];
	for (int i=1;i<c[len];i++)
		ans+=f[len][i];
	for (int i=len-1;i>=1;i--)
	{
		for (int j=0;j<c[i];j++)
			if (abs(j-c[i+1])>=2)
				ans+=f[i][j];
		if (abs(c[i]-c[i+1])<2)
			break;
	}
	return ans;
}

int main()
{
	freopen("1026.in","r",stdin);
	freopen("1026.out","w",stdout);
	int l,r,i;
	memset(f,0,sizeof(f));
	for (i=0;i<10;i++)
		f[1][i]=1;
	for (i=2;i<=10;i++)
		for (int j=0;j<=9;j++)
			for (int k=0;k<=9;k++)
				if (abs(j-k)>=2)
					f[i][j]+=f[i-1][k];
	scanf("%d%d",&l,&r);
	printf("%d\n",find(r+1)-find(l));
	return 0;
}