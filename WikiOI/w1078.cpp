#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<queue>
using namespace std;

typedef pair<int,int> pii;
priority_queue<pii,vector<pii>,greater<pii> > q;
int dis[103];
bool v[103];
typedef struct {int v,w;}node;
vector<node> a[103];
int main()
{
  freopen("prim.in","r",stdin);
  freopen("prim.out","w",stdout);
  int w,n,i,j,s,t;
  scanf("%d",&n);
  for (i=0;i<n;i++)
    for (j=0;j<n;j++)
    {
      scanf("%d",&s);
      node k;
      k.v=j;
      k.w=s;
      if (i!=j) a[i].push_back(k);
    }
  memset(dis,127,sizeof(dis));
  dis[0]=0;
  memset(v,0,sizeof(v));
  int ans=0;
  q.push(make_pair(dis[0],0));
  while(!q.empty())
  {
    pii u;
    u=q.top();
    q.pop();
    int x=u.second;
    if (v[x]) continue;
    v[x]=true;
    ans+=u.first;
    int d=a[x].size();
    for (i=0;i<d;i++)
    {
      if (!v[a[x][i].v]&&a[x][i].w<dis[a[x][i].v])
      {
        dis[a[x][i].v]=a[x][i].w;
        q.push(make_pair(a[x][i].w,a[x][i].v));
      }
    }
  }
  printf("%d\n",ans);
  return 0;
}
