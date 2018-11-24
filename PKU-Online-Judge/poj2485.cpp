#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

int map[504][504];
int dis[504];
bool vis[504];
typedef pair<int,int> pii;

int main()
{
  int T;
  freopen("2485.in","r",stdin);
  freopen("2485.out","w",stdout);
  scanf("%d",&T);
  while(T--)
  {
    int n,i,j,k,m;
    scanf("%d",&n);
    memset(map,0,sizeof(map));
    for (i=1;i<=n;i++)
      for (j=1;j<=n;j++)
        scanf("%d",&map[i][j]);
    memset(dis,127,sizeof(dis));
    memset(vis,0,sizeof(vis));
    dis[1]=0;
    priority_queue<pii,vector<pii>,greater<pii> > q;
    q.push(make_pair(0,1));
    int ans=0;
    while(!q.empty())
    {
      pii x;
      x=q.top();q.pop();
      if (vis[x.second]) continue;
      vis[x.second]=true;
      ans=max(ans,x.first);
      for (j=1;j<=n;j++)
        if (!vis[j]&&j!=x.second&&map[x.second][j]<dis[j])
          q.push(make_pair(dis[j]=map[x.second][j],j));
    }
    printf("%d\n",ans);
  }
  return 0;
}

