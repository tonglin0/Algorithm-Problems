#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#define N 1299709
#define MN 100010
using namespace std;

bool vis[N+100];
int c[MN];
int t=0;

int find(int x)
{
  int l=1,r=t;
  while(l<r)
  {
    int mid=(l+r)>>1;
    if (c[mid]>x)
      r=mid;
    else
      l=mid+1;
  }
  return l-1;
}

int main()
{
  freopen("3518.in","r",stdin);
  freopen("3518.out","w",stdout);
  int n,i,j,k,m;
  memset(vis,0,sizeof(vis));
  m=(int)sqrt(N+0.5);
  for (i=2;i<=m;i++)
    if (!vis[i])
      for (j=i*i;j<=N;j+=i)
        vis[j]=true;
  for (i=2;i<=N;i++)
    if (!vis[i])
      c[++t]=i;
  while((scanf("%d",&n)==1)&&n)
  {
    if (!vis[n])
      printf("0\n");
    else
    {
      int l=find(n);
      printf("%d\n",c[l+1]-c[l]);
    }
  }
  return 0;
}
