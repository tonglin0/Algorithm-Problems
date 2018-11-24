#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

int st[1029];
int f[1029];
int v[13];
bool vis[1039];
int top,n;

void dfs(int k,int s1,int s2,int s)
{
  if (k>=n)
  {
    if (!vis[s])
    {
      st[++top]=s;
      vis[s]=true;
    }
    return ;
  }
  if (s1>=v[k])
    dfs(k+1,s1-v[k],s2,s|(1<<k));
  if (s2>=v[k])
    dfs(k+1,s1,s2-v[k],s|(1<<k));
  dfs(k+1,s1,s2,s);
}

int main()
{
  freopen("2923.in","r",stdin);
  freopen("2923.out","w",stdout);
  int s1,s2,ca,ii,i,j,k,m;
  scanf("%d",&ca);
  for (ii=1;ii<=ca;ii++)
  {
    scanf("%d%d%d",&n,&s1,&s2);
    printf("Scenario #%d:\n",ii);
    for (i=0;i<n;i++)
      scanf("%d",&v[i]);
    memset(vis,0,sizeof(vis));
    top=0;
    dfs(0,s1,s2,0);
    for (i=1;i<=1<<n;i++)
      f[i]=(int)1e9;
    f[0]=0;
    for (i=0;i<(1<<n);i++)
      for (j=1;j<=top;j++)
      {
        int s=st[j];
        if (s&i)
          continue;
        f[s|i]=min(f[s|i],f[i]+1);
      }
    printf("%d\n\n",f[(1<<n)-1]);
  }
  return 0;
}
