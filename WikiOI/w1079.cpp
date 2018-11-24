#include<cstdlib>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;

typedef pair<int,int> pii;
typedef struct{int w;int v;}node;
priority_queue<pii,vector<pii>,greater<pii> > q;
vector<node> g[200];
int dis[200];
bool vis[200];
char ch[10];

int main()
{
  freopen("1079.in","r",stdin);
  freopen("1079.out","w",stdout);
  int n,m,i,j,k;
  scanf("%d",&m);
  for (i=1;i<=m;i++)
  {
    int d1,d2,d;
    scanf("%s",ch);
    d1=ch[0];
    scanf("%s",ch);
    d2=ch[0];
    scanf("%d",&d);
    node x;
    x.v=d2;
    x.w=d;
    g[d1].push_back(x);
    x.v=d1;
    g[d2].push_back(x);
  }
  memset(dis,127,sizeof(dis));
  memset(vis,0,sizeof(vis));
  dis['Z']=0;
  q.push(make_pair(0,'Z'));
  while (!q.empty())
  {
    pii x=q.top();q.pop();
    if (vis[x.second]) continue;
    int u=x.second;
    vis[u]=true;
    int d=g[u].size();
    for (i=0;i<d;i++)
      if (!vis[g[u][i].v]&&dis[u]<dis[g[u][i].v]-g[u][i].w)
        q.push(make_pair(dis[g[u][i].v]=dis[u]+g[u][i].w,g[u][i].v));
  }
  int min=100000000,minj;
  for (i='A';i<='Y';i++)
    if (dis[i]<min)
    {
      min=dis[i];
      minj=i;
    }
  printf("%c ",minj);
  printf("%d\n",min);
  return 0;
}
