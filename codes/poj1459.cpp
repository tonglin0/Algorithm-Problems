#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<queue>
#define INF 1000000000
using namespace std;

queue<int> q;
int a[103],f[103][103],c[103][103],p[103];
void read()
{
  char ch;
  ch=getchar();
  while(ch!='(') ch=getchar();
}
int main()
{
  freopen("1459.in","r",stdin);
  freopen("1459.out","w",stdout);
  int n,np,nc,m,k,i,j,s,u,v,w,t;
  while (scanf("%d",&n)==1)
  {
    scanf("%d%d%d",&np,&nc,&m);
    memset(c,0,sizeof(c));
    memset(f,0,sizeof(f));
    for (i=1;i<=m;i++)
    {
      read();
      scanf("%d,%d)%d",&u,&v,&w);
      c[u][v]=w;
    }
    s=n;
    t=++n;
    for (i=1;i<=np;i++)
    {
      read();
      scanf("%d)%d",&u,&w);
      c[s][u]=w;
    }
    for (i=1;i<=nc;i++)
    {
      read();
      scanf("%d)%d",&u,&w);
      c[u][t]=w;
    }
    int ans=0;
    for (;;)
    {
      memset(a,0,sizeof(a));
      memset(p,0,sizeof(p));
      q.push(s);
      a[s]=INF;
      while(!q.empty())
      {
        u=q.front();q.pop();
        for (i=0;i<=n;i++)
          if (!a[i]&&c[u][i]>f[u][i])
          {
            q.push(i);
            p[i]=u;
            a[i]=min(a[u],c[u][i]-f[u][i]);
          }
      }
      if (a[t]==0) break;
      for (i=n;i!=n-1;i=p[i])
      {
        f[p[i]][i]+=a[n];
        f[i][p[i]]-=a[n];
      }
      ans+=a[n];
    }
    printf("%d\n",ans);
  }
  return 0;
}

