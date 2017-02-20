#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define INF (int)1e9
using namespace std;

int map[103][103];

int main()
{
  //freopen("1125.in","r",stdin);
  //freopen("1125.out","w",stdout);
  int n,i,m,j,k;
  scanf("%d",&n);
  while(n!=0)
  {
    memset(map,0,sizeof(map));
    for (i=1;i<=n;i++)
    {
      scanf("%d",&m);
      for (j=1;j<=m;j++)
      {
        int u,d;
        scanf("%d%d",&u,&d);
        map[i][u]=d;
      }
    }
    for (k=1;k<=n;k++)
      for (i=1;i<=n;i++)
        for (j=1;j<=n;j++)
          if (i!=j&&map[i][k]&&map[k][j]&&(map[i][j]==0||map[i][k]+map[k][j]<map[i][j]))
            map[i][j]=map[i][k]+map[k][j];
    int ans=INF,s=0,d;
    bool flag=true;
    for (i=1;i<=n;i++)
    {
      s=0;flag=true;
      for (j=1;j<=n;j++)
      {
        if (i==j) continue;
        if (!map[i][j]) {flag=false;break;}
        s=max(s,map[i][j]);
      }
      if (flag) if (s<ans){ans=s;d=i;}
    }
    if (ans==INF) printf("disjoint\n");
      else printf("%d %d\n",d,ans);
    scanf("%d",&n);
  }
  return 0;
}
