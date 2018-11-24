#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

int g[12][103][103];
int f[103][103];
bool vis[14];
int v[13];

int main()
{
  freopen("2923.in","r",stdin);
  freopen("2923.out","w",stdout);
  int n,i,j,k,m,ii=0,ca,m1,m2;
  scanf("%d",&ca);
  for (ii=1;ii<=ca;ii++)
  {
    printf("Scenario #%d:\n",ii);
    memset(vis,0,sizeof(vis));
    scanf("%d%d%d",&n,&m1,&m2);
    int s=0;
    for (i=1;i<=n;i++)
    {
      scanf("%d",&v[i]);
      s+=v[i];
    }
    int ans=0;
    while(s>0)
    {
      memset(g,0,sizeof(g));
      memset(f,0,sizeof(f));
      for (i=1;i<=n;i++) if (!vis[i])
        for (j=m1;j>=0;j--)
          for (k=m2;k>=0;k--)
          {
            g[i][j][k]=0;
            if (j-v[i]>=0&&f[j-v[i]][k]+v[i]>f[j][k]&&(k<v[i]||f[j-v[i]][k]>f[j][k-v[i]]))
            {
              f[j][k]=f[j-v[i]][k]+v[i];
              g[i][j][k]=1;
            }
            else if (k-v[i]>=0&&f[j][k-v[i]]+v[i]>f[j][k]&&(j<v[i]||f[j][k-v[i]]>f[j-v[i]][k]))
            {
              f[j][k]=f[j][k-v[i]]+v[i];
              g[i][j][k]=2;
            }
          }
      ans++;
      s-=f[m1][m2];
      i=n;j=m1;k=m2;
      while(i>0)
      {
        if (g[i][j][k]==0)
          i--;
        else if (g[i][j][k]==1)
        {
          vis[i]=true;
          j-=v[i];
          i--;
        }
        else
        {
          vis[i]=true;
          k-=v[i];
          i--;
        }
      }
    }
    printf("%d\n\n",ans);
  }
  return 0;
}
