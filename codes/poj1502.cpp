#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

int dis[104][104];
char s[100];

int main()
{
  freopen("1502.in","r",stdin);
  freopen("1502.out","w",stdout);
  int n,i,j,m;
  scanf("%d",&n);
  memset(dis,0,sizeof(dis));
  for (i=2;i<=n;i++)
    for (j=1;j<i;j++)
    {
      scanf("%s",s);
      if (atoi(s)!=0) dis[i][j]=dis[j][i]=atoi(s);
    }
  int k;/*
  for(i=1;i<=n;i++)
    for (j=1;j<=n;j++)
      dis[i][j]=dis[j][i]=max(dis[i][j],dis[j][i]);*/
  for (k=1;k<=n;k++)
    for (i=1;i<=n;i++)
      for (j=1;j<=n;j++)
        if (dis[i][k]&&dis[k][j]&&(!dis[i][j]||dis[i][k]+dis[k][j]<dis[i][j]))
          dis[i][j]=dis[i][k]+dis[k][j];
  int ans=0;
  for (i=2;i<=n;i++)
    ans=max(ans,dis[1][i]);
  printf("%d\n",ans);
  return 0;     
}
