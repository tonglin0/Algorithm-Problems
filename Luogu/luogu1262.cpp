#include<cstdio>
#include<cstring>
#include<stack>
#include<vector>
#include<algorithm>
#define INF (int)1e9
using namespace std;

bool cb[3003];
int mn[3003];
vector<int> g[3003];
int dfsclk=0,cnt=0;
int sccno[3003];
bool vis[3003];
int pre[3003],low[3003];
stack<int> s;
bool cb2[3003];
vector<int> g2[3003];
int ind[3003];
int mi[3003];

void dfs(int u)
{
	s.push(u);
	pre[u]=low[u]=++dfsclk;
	for (int i=0;i<g[u].size();i++)
	{
		int v=g[u][i];
		if (!pre[v])
		{
			dfs(v);
			low[u]=min(low[u],low[v]);
		}
		else if (!sccno[v])
			low[u]=min(low[u],pre[v]);
	}
	if (low[u]==pre[u])
	{
		++cnt;
		mi[cnt]=INF;
		int t=s.top();s.pop();
		while(t!=u)
		{
			sccno[t]=cnt;
			if (cb[t])
			{
				cb2[cnt]=true;
				mi[cnt]=min(mi[cnt],mn[t]);
			}
			t=s.top();s.pop();
		}
		sccno[u]=cnt;
		if (cb[u])
		{
			cb2[cnt]=true;
			mi[cnt]=min(mi[cnt],mn[u]);
		}
	}
}

void floodfill(int u)
{
	vis[u]=true;
	for (int i=0;i<g2[u].size();i++)
		if (!vis[g2[u][i]])
			floodfill(g2[u][i]);
}

int main()
{
	int n,i,j,p;
	scanf("%d%d",&n,&p);
	for (i=1;i<=p;i++)
	{
		int id;
		scanf("%d",&id);
		cb[id]=true;
		scanf("%d",&mn[id]);
	}
	int e;
	scanf("%d",&e);
	for (i=1;i<=e;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
	}
	for (i=1;i<=n;i++)
		if (!pre[i])
			dfs(i);
	for (i=1;i<=n;i++)
		for (j=0;j<g[i].size();j++)
		{
			if (sccno[i]==sccno[g[i][j]]) continue;
			g2[sccno[i]].push_back(sccno[g[i][j]]);
			ind[sccno[g[i][j]]]++;
		}
	int ans=0;
	bool flag=true;
	for (i=1;i<=cnt;i++)
		if (ind[i]==0)
		{
			if (cb2[i])
			{
				ans+=mi[i];
				floodfill(i);
			}
			else
			{
				flag=false;
			}
		}
	if (flag)
	{
		printf("YES\n%d\n",ans);
		return 0;
	}
	for (i=1;i<=cnt;i++)
		if (cb2[i])
			floodfill(i);
	for (i=1;i<=n;i++)
		if (!vis[sccno[i]])
		{
			printf("NO\n%d\n",i);
			return 0;
		}
}
