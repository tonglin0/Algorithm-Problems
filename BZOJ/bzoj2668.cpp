#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cctype>
#include<ctime>
#include<queue>
#include<string>
#include<vector>
#include<map>
#define eps 1e-8
#define INF (int)1e9
#define lint long long
#define llu unsigned long long
#define MN 1209
using namespace std;

int a1[24][24],a2[24][24];
int c[24][24];
char st[30];
int dx[]={-1,-1,-1,0,1,1,1,0};
int dy[]={-1,0,1,1,1,0,-1,-1};

int S,T,cost=0;
struct edge{
	int from,to,c,f,cost;
};
int dis[MN];
int p[MN],a[MN];
int flow=0;
bool vis[MN],ins[MN];
vector<edge> es;
vector<int> g[MN];

void addedge(int from,int to,int c,int cost)
{
  edge x;
  x.from=from;x.to=to;x.c=c;x.f=0;x.cost=cost;
  es.push_back(x);
  x.from=to;x.to=from;x.c=0;x.cost=-cost;
  es.push_back(x);
  int m=es.size();
  g[from].push_back(m-2);
  g[to].push_back(m-1);
}

bool spfa()
{
  for (int i=S;i<=T;i++)
    dis[i]=INF,ins[i]=false;
  queue<int> q;
  p[S]=0;
  a[S]=INF;
  dis[S]=0;
  q.push(S);
  while(!q.empty())
  {
    int u=q.front();q.pop();
    ins[u]=false;
    for (int i=0;i<g[u].size();i++)
    {
      edge e=es[g[u][i]];
      if (e.c>e.f&&dis[e.to]>dis[u]+e.cost)
      {
        dis[e.to]=dis[u]+e.cost;
        p[e.to]=g[u][i];
        a[e.to]=min(a[u],e.c-e.f);
        if(!ins[e.to])
        {
          ins[e.to]=true;
          q.push(e.to);              
        }
      }
    }
  }
  if (dis[T]==INF) return false;
  cost+=a[T]*dis[T];
  flow+=a[T];
  int u=T;
  while(u!=S)
  {
    es[p[u]].f+=a[T];
    es[p[u]^1].f-=a[T];
    u=es[p[u]].from;
  }
  return true;
}


bool hefa(int x,int y,int n,int m)
{
  if (x<1||y<1)
    return false;
  if (x>n||y>m)
    return false;
  return true;
}

int main()
{
  freopen("2668.in","r",stdin);
  freopen("2668.out","w",stdout);
  int ca,n,i,j,k,m,ii=0;
  int cnt1=0,cnt2=0;
  scanf("%d%d",&n,&m);
  for (i=1;i<=n;i++)
  {
    scanf("%s",st);
    for (j=0;j<m;j++)
      if (st[j]=='0')
        a1[i][j+1]=0;
      else
        a1[i][j+1]=1,cnt1++;
  }
  for (i=1;i<=n;i++)
  {
    scanf("%s",st);
    for (j=0;j<m;j++)
      a2[i][j+1]=st[j]-'0',cnt2+=a2[i][j+1]==1?1:0;
  }
  if (cnt1!=cnt2)
  {
    printf("-1\n");
    return 0;
  }
  for (i=1;i<=n;i++)
  {
    scanf("%s",st);
    for (j=0;j<m;j++)
      c[i][j+1]=st[j]-'0';
  }
  int N=n*m;
  int askflow=0;
  S=0;T=N+N+N+1;
  for (i=1;i<=n;i++)
    for (j=1;j<=m;j++)
    {
      int a=(i-1)*m+j;
      int b=a+N;
      int cc=b+N;
      if (a1[i][j]==1&&a2[i][j]==0)
      {
      	addedge(S,b,1,0);
      	askflow++;
        addedge(a,b,c[i][j]/2,0);
        addedge(b,cc,(c[i][j]+1)/2,0);
	  }
	  else if (a1[i][j]==0&&a2[i][j]==1)
	  {
	    addedge(b,T,1,0);
	    addedge(a,b,(c[i][j]+1)/2,0);
	    addedge(b,cc,c[i][j]/2,0);
	  }
	  else
	  {
	    addedge(a,b,c[i][j]/2,0);
	    addedge(b,cc,c[i][j]/2,0);
	  }
	  for (k=0;k<8;k++)
	  {
	    int x=i+dx[k];
	    int y=j+dy[k];
	    if (!hefa(x,y,n,m))
	      continue;
	    addedge(cc,(x-1)*m+y,INF,1);
	  }
	}
  while(spfa());
  if (flow<askflow)
    printf("%d\n",-1);
  else
    printf("%d\n",cost);
  return 0;
}

