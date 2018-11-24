#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<queue>
#define INF (int)1e9
using namespace std;

char a[18][18];
int st[227];
int dis[228][228];
bool vis[16][16];
struct node{
       int x,y,d;
};
int dp[16][(1<<15)+4];
bool isl[16];
queue<node> q;

node make_node(int x,int y,int d)
{
  node t;
  t.x=x;t.y=y;t.d=d;
  return t;
}

int main()
{
  freopen("3681.in","r",stdin);
  freopen("3681.out","w",stdout);
  int n,i,j,k,m;
  while(scanf("%d%d",&n,&m)==2&&(n+m))
  {
    for (i=1;i<=n;i++)
      scanf("%s",(a[i]+1));
    for (i=0;i<=n*m;i++)
      for (j=0;j<=n*m;j++)
        dis[i][j]=INF; 
    int S;
    int top=0;
    int alllight=0;
    memset(isl,0,sizeof(isl));
    for (i=1;i<=n;i++)
      for (j=1;j<=m;j++)
        if (a[i][j]=='Y'||a[i][j]=='G')
        {
          if (a[i][j]=='Y')
          {
            alllight|=(1<<top);
            isl[top]=true;
          }
          st[top++]=(i-1)*m+j;
        }
    if (alllight==0)
    {
      printf("0\n");
      continue;
    }
    for (i=1;i<=n;i++)
      for (j=1;j<=m;j++)
      {
        if (a[i][j]=='D')
          continue;
        memset(vis,0,sizeof(vis));
        node start;
        start.x=i;start.y=j;start.d=0;
        int id=(i-1)*m+j;
        if (a[i][j]=='F')
          S=id;
        q.push(start);
        while(!q.empty())
        {
          node t=q.front();q.pop();
          if (vis[t.x][t.y])
            continue;
          vis[t.x][t.y]=true;
          int tid=(t.x-1)*m+t.y;
          dis[id][tid]=t.d;
          int x=t.x,y=t.y;
          if (x+1<=n&&!vis[x+1][y]&&a[x+1][y]!='D')
            q.push(make_node(x+1,y,t.d+1));
          if (x-1>=1&&!vis[x-1][y]&&a[x-1][y]!='D')
            q.push(make_node(x-1,y,t.d+1));
          if (y+1<=m&&!vis[x][y+1]&&a[x][y+1]!='D')
            q.push(make_node(x,y+1,t.d+1));
          if (y-1>=1&&!vis[x][y-1]&&a[x][y-1]!='D')
            q.push(make_node(x,y-1,t.d+1));
        }
      }
    int full=(1<<top)-1;
    int l=1,r=n*m+2;
    while(l<r)
    {
      int mid=(l+r)>>1;
      for (i=0;i<=top;i++)
        for (j=0;j<=full;j++)
          dp[i][j]=-INF;
      for (i=0;i<top;i++)
        dp[i][1<<i]=mid-dis[S][st[i]];
      for (i=0;i<top;i++)
        if (!isl[i]&&dp[i][1<<i]>=0)
          dp[i][1<<i]=mid;
      int s;
      for (s=1;s<=full;s++)
        for (i=0;i<top;i++)
          if ((s&(1<<i))&&dp[i][s]>0)
            for (j=0;j<top;j++)
              if (!(s&(1<<j)))
              {
                dp[j][s|(1<<j)]=max(dp[j][s|(1<<j)],dp[i][s]-dis[st[i]][st[j]]);
                if(dp[j][s|(1<<j)]>=0&&(!isl[j]))
                  dp[j][s|(1<<j)]=mid;
              }
      bool flag=false;
      for (s=1;s<=full;s++)
        if ((s&alllight)==alllight)
          for (i=0;i<top;i++)
            if (dp[i][s]>=0)
            {
              flag=true;
              break;
            }
      if (flag)
        r=mid;
      else
        l=mid+1;
    }
    if (l==m*n+2)
      printf("-1\n");
    else
      printf("%d\n",l);
  }
  return 0;
}
