#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> g[10003];
bool vis[10003];
int a[10003];
int t[2];

bool dfs(int u,int col)
{
	vis[u]=true;
	a[u]=col;
	t[col]++;
	for (int i=0;i<g[u].size();i++)
	{
		int v=g[u][i];
		if (vis[v]&&a[v]==a[u])
			return false;
		else if (!vis[v])
		{
			bool flag=dfs(v,(col+1)&1);
			if (!flag)
				return false;
		}
	}
	return true;
}

int main()
{
	int n,m,i,j;
	scanf("%d%d",&n,&m);
	for (i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int ans=0;
	for (i=1;i<=n;i++)
		if (!vis[i])
		{
			t[0]=t[1]=0;
			bool flag=dfs(i,0);
			if (!flag)
			{
				printf("Impossible\n");
				return 0;
			}
			ans+=min(t[0],t[1]);
		}
	printf("%d\n",ans);
	return 0;
}
