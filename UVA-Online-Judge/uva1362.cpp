#include<cstdio>
#include<cstdlib>
#include<cstring>
#define lint long long
#define M 1000000000
using namespace std;

lint d[309][309];
bool vis[309][309];
char a[309];

lint find(int i,int j)
{
  if (vis[i][j])
    return d[i][j];
  vis[i][j]=true;
  if (i==j)
  {
    d[i][j]=1;
    return 1;
  }
  if (a[i]!=a[j])
  {
    d[i][j]=0;
    return 0;
  }
  for (int k=i+2;k<=j;k++)
    if (a[k]==a[i])
      d[i][j]=(d[i][j]+find(i+1,k-1)%M*(find(k,j)%M)%M)%M;
  return d[i][j];
}

int main()
{
  freopen("1362.in","r",stdin);
  freopen("1362.out","w",stdout);
  lint n,i,j,k,m;
  while(scanf("%s",a)==1)
  {
    memset(vis,0,sizeof(vis));
    memset(d,0,sizeof(d));
    printf("%lld\n",find(0,strlen(a)-1)%M);
  }
  return 0;
}
