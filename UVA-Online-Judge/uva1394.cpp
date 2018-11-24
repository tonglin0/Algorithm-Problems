#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

int f[10004];

int main()
{
  freopen("1394.in","r",stdin);
  freopen("1394.out","w",stdout);
  int n,i,j,k,m;
  while(scanf("%d%d%d",&n,&k,&m)==3&&(n+k+m))
  {
    f[1]=0;
    for (i=2;i<n;i++)
      f[i]=(f[i-1]+k)%i;
    f[n]=(f[n-1]+m)%n;
    f[n]=f[n]+1;
    if (f[n]<=0)
      f[n]+=n;
    printf("%d\n",f[n]);
  }
  return 0;
}
