#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#define lint long long
#define MOD 1000000007
using namespace std;

lint f[1009][1009];
bool vis[1009][1009];

lint find(lint i,lint j)
{
  if (vis[i][j]) 
    return f[i][j];
  vis[i][j]=true;
  if (i<=j)
    return f[i][j]=0;
  if (j==0)
    return f[i][j]=1;
  f[i][j]=(find(i-1,j)*(j+1)%MOD+find(i-1,j-1)*(i-j)%MOD)%MOD;
  return f[i][j];
}

int main()
{
  freopen("1485.in","r",stdin);
  freopen("1485.out","w",stdout);
  lint n,i,j,k,m;
  memset(vis,0,sizeof(vis));
  memset(f,0,sizeof(f));
  for (i=1;i<=1000;i++)
    for (j=0;j<=1000;j++)
      f[i][j]=find(i,j);
  while(scanf("%lld%lld",&n,&m)==2)
    printf("%lld\n",f[n][m]);
  return 0;
}
