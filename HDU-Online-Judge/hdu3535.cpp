#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define INF (int)1e9
using namespace std;

struct node{
       int v,w;
};
int p[103];
node s[103][103];
int f[103][103]; 

int main()
{
  freopen("3535.in","r",stdin);
  freopen("3535.out","w",stdout);
  int n,i,j,k,m,cnt;
  while(scanf("%d%d",&cnt,&m)==2)
  {
    memset(s,0,sizeof(s));
    for (i=1;i<=cnt;i++)
    {
      scanf("%d%d",&s[i][0].v,&p[i]);
      for (j=1;j<=s[i][0].v;j++)
        scanf("%d%d",&s[i][j].v,&s[i][j].w);
    }
    memset(f[0],0,sizeof(f[0]));
    //for (i=1;i<=m;i++)
      //f[0][i]=-INF;
    //f[0][0]=0;
    for (int ii=1;ii<=cnt;ii++)
      if (p[ii]==0)
      {
        for (i=0;i<=m;i++)
          f[ii][i]=-INF;
        for (i=1;i<=s[ii][0].v;i++)
          for (j=m;j>=s[ii][i].v;j--)
            f[ii][j]=max(f[ii][j],max(f[ii][j-s[ii][i].v]+s[ii][i].w,f[ii-1][j-s[ii][i].v]+s[ii][i].w));
      }
      else if (p[ii]==1)
      {
        for (i=0;i<=m;i++)
          f[ii][i]=f[ii-1][i];
        for (j=m;j>=0;j--)
          for (i=1;i<=s[ii][0].v;i++)
            if (j>=s[ii][i].v)
              f[ii][j]=max(f[ii][j],f[ii-1][j-s[ii][i].v]+s[ii][i].w);
      }
      else
      {
        for (i=0;i<=m;i++)
          f[ii][i]=f[ii-1][i];
        for (i=1;i<=s[ii][0].v;i++)
          for (j=m;j>=s[ii][i].v;j--)
            f[ii][j]=max(f[ii][j],max(f[ii-1][j-s[ii][i].v]+s[ii][i].w,f[ii][j-s[ii][i].v]+s[ii][i].w));
      }
    int ans=-1;
    for (i=0;i<=m;i++)
      ans=max(ans,f[cnt][i]);
    if (ans<0)
      printf("-1\n");
    else
      printf("%d\n",ans);
  }
  return 0;
}
