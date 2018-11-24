#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#define MN 103
#define INF (int)1e9
using namespace std;

int dis[MN];
int a[MN][MN];
struct edge{
	int v,w;
};
bool vis[MN];
vector<edge> g[MN];
struct node{
	int u,s;
	bool operator < (const node& b) const{
		return s>b.s;
	};
};
priority_queue<node> q;

int main()
{
	int n,i,j;
	scanf("%d",&n);
	int d;
	for (i=1;i<=n;i++)
		for (j=1;j<=n;j++)
		{
			scanf("%d",&d);
			if (i==j)continue;
			edge e;e.v=j;e.w=d;
			g[i].push_back(e);
		}
	int ans=0;
	for (i=0;i<=n;i++)
		dis[i]=INF;
	dis[1]=0;
	node st;st.u=1;st.s=0;
	q.push(st);
	while(!q.empty())
	{
		node t=q.top();q.pop();
		if (vis[t.u]) continue;
		vis[t.u]=true;
		ans+=t.s;
		int u=t.u;
		for (i=0;i<g[u].size();i++)
		{
			int v=g[u][i].v;
			if (g[u][i].w<dis[v])
			{
				dis[v]=g[u][i].w;
				node tmp;
				tmp.u=v;tmp.s=dis[v];
				q.push(tmp);
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
