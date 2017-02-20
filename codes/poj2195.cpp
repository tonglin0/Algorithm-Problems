#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<queue>
#include<vector>
#define INF (int)1e9
using namespace std;

struct edge{int from,to,c,f,cost;};
struct node{int no,x,y;};
vector<node> hs;
vector<node> ms;
vector<edge> es;
int a[203],p[203],dis[203];
vector<int> g[203];
char ch[103];
bool ins[203];
int t=201,n,flow=0,cost=0;

void addedge(int from,int to,int c,int cost)
{
  edge e;
  e.from=from;
  e.to=to;
  e.c=c;
  e.f=0;
  e.cost=cost;
  es.push_back(e);
  e.from=to;
  e.to=from;
  e.cost=-cost;
  e.c=0;
  es.push_back(e);
  int m=es.size();
  g[from].push_back(m-2);
  g[to].push_back(m-1);
}

bool bellmanford()
{
  memset(p,0,sizeof(p));
  memset(ins,0,sizeof(ins));
  for (int i=1;i<=n;i++) dis[i]=INF;
  dis[t]=INF;
  dis[0]=0;a[0]=INF;ins[0]=true;
  queue<int> q;
  q.push(0);
  while(!q.empty())
  {
    int u=q.front();q.pop();
    ins[u]=false;
    for(int i=0;i<g[u].size();i++)
    {
      edge e=es[g[u][i]];
      if(e.f<e.c&&dis[u]<dis[e.to]-e.cost)
      {
        dis[e.to]=dis[u]+e.cost;
        p[e.to]=g[u][i];
        a[e.to]=min(a[u],e.c-e.f);
        if (!ins[e.to]){ins[e.to]=true;q.push(e.to);}
      }
    }
  }
  if (dis[t]==INF) return false;
  flow+=a[t];
  cost+=dis[t]*a[t];
  int u=t;
  while(u!=0)
  {
    es[p[u]].f+=a[t];
    es[p[u]^1].f-=a[t];
    u=es[p[u]].from;
  }
  return true;
}

int main()
{
  freopen("2195.in","r",stdin);
  freopen("2195.out","w",stdout); 
  int h,nn,m,i,j,k;
  scanf("%d%d",&nn,&m);
  while(!(nn==0&&m==0))
  {
    hs.clear();
    ms.clear();
    es.clear();
    flow=cost=0;
    n=h=0;
    for (i=0;i<202;i++) g[i].clear();
    for (i=1;i<=nn;i++)
    {
      scanf("%s",ch);
      for (j=0;j<m;j++)
      {
        if (ch[j]=='H')
        {
          node x;
          x.x=i;
          x.y=j+1;
          x.no=++n;
          hs.push_back(x);
          addedge(n,t,1,0);
        }
        else if (ch[j]=='m')
        {
          node x;
          x.x=i;
          x.y=j+1;
          x.no=++n;
          ms.push_back(x);
          addedge(0,n,1,0); 
          /*n++;
          addedge(0,n,1,0);
          for (k=0;k<hs.size();k++)
          {
            int x=hs[k].x,y=hs[k].y;
            int d=abs(x-i)+abs(y-(j+1));
            addedge(n,hs[k].no,1,d);
          }*/
        }
      }
    }
    for (i=0;i<ms.size();i++)
    {
      int x=ms[i].x,y=ms[i].y;
      for (j=0;j<hs.size();j++)
      {
        int d=abs(hs[j].x-x)+abs(hs[j].y-y);
        addedge(ms[i].no,hs[j].no,1,d);
      }
    }
    while(bellmanford());
    printf("%d\n",cost); 
    scanf("%d%d",&nn,&m);
  }
  return 0;  
} 
