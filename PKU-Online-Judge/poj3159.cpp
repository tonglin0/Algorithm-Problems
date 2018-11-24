#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define MN 50005
#define INF (int)1e9
#define M 150009
#include<queue>
using namespace std;

int hv[M],hw[M];
int dis[MN];
int top=0;
bool vis[MN];
int head[MN],next[M];
typedef pair<int,int> pii;

void addedge(int u,int v,int w)
{
	hv[top]=v;
	hw[top]=w;
	next[top]=head[u];
	head[u]=top++;
}

int main()
{
	freopen("3159.in","r",stdin);
	freopen("3159.out","w",stdout);
	int n,m,i;
	memset(head,-1,sizeof(head));
	scanf("%d%d",&n,&m);
	while(m--)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		addedge(u,v,w);
	}
	priority_queue<pii,vector<pii>,greater<pii> > q;
	for (i=1;i<=n;i++)
		dis[i]=INF;
	memset(vis,0,sizeof(vis));
	dis[1]=0;
	pii x;
	x.first=0;x.second=1;
	q.push(x);
	while(!q.empty())
	{
		x=q.top();q.pop();
		if (vis[x.second])
			continue;
		int u=x.second;
		vis[u]=true;
		for (i=head[u];i!=-1;i=next[i])
		{
			int v=hv[i];
			if (dis[u]+hw[i]<dis[v])
				q.push(pii(dis[v]=dis[u]+hw[i],v));
		}
	}
	printf("%d\n",dis[n]);
	return 0;
}