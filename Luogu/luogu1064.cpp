#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

int a[63],b[63],c[63];
vector<int> g[63];
int f[3203];
int vi[203],wi[203];
int st[63][3];

int main()
{
	int n,i,j,v;
	scanf("%d%d",&v,&n);
	v/=10;
	for (i=1;i<=n;i++)
	{
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
		a[i]/=10;
		if (c[i]!=0)
			g[c[i]].push_back(i);
	}
	int top=0,ns=0;
	for (i=1;i<=n;i++)
		if (c[i]==0)
		{
			ns++;
			st[ns][1]=top+1;
			if (g[i].size()==0)
			{
				vi[++top]=a[i];
				wi[top]=a[i]*b[i];				
			}
			else if (g[i].size()==1)
			{
				vi[++top]=a[i];
				wi[top]=a[i]*b[i];
				vi[++top]=a[i]+a[g[i][0]];
				wi[top]=a[i]*b[i]+a[g[i][0]]*b[g[i][0]];
			}
			else if (g[i].size()==2)
			{
				vi[++top]=a[i];
				wi[top]=a[i]*b[i];
				for (j=0;j<=1;j++)
				{
					vi[++top]=a[i]+a[g[i][j]];
					wi[top]=a[i]*b[i]+a[g[i][j]]*b[g[i][j]];
				}
				vi[++top]=a[i]+a[g[i][0]]+a[g[i][1]];
				wi[top]=a[i]*b[i]+a[g[i][0]]*b[g[i][0]]+a[g[i][1]]*b[g[i][1]];
			}
			st[ns][2]=top;
		}
	for (i=1;i<=ns;i++)
		for (j=v;j>=0;j--)
			for (int k=st[i][1];k<=st[i][2];k++)
				if (j>=vi[k])
					f[j]=max(f[j],f[j-vi[k]]+wi[k]);
	printf("%d\n",f[v]*10);
	return 0;
}

