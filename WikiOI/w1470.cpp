#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cctype>
#include<ctime>
#include<queue>
#include<string>
#include<vector>
#include<map>
#define eps 1e-8
#define INF (int)1e9
#define MN 1009
#define lint long long
#define llu unsigned long long
using namespace std;

int tens[]={1,1,10,100,1000,10000,100000};
int a[MN],bk[MN];
int ct[11];

int getdigit(int x,int k)
{
  return x/tens[k]%10;
}

int main()
{
  freopen("1470.in","r",stdin);
  freopen("1470.out","w",stdout);
  int ca,n,i,j,k,m,ii=0;
  int ms=-INF;
  int mi=INF;
  scanf("%d",&n);
  int sum=0;
  for (i=1;i<=n;i++)
  {
    scanf("%d",&a[i]);
    ms=max(ms,a[i]);
    mi=min(mi,a[i]);
    sum+=a[i];
  }
  printf("%d\n%d\n%d\n",sum,ms,mi);
  for (i=0;i<=n+1;i++)
    bk[i]=0;
  int d=4;
  for (k=1;k<=d;k++)
  {
    memset(ct,0,sizeof(ct));
    for (i=1;i<=n;i++)
      ct[getdigit(a[i],k)]++;
    for (i=1;i<=9;i++)
      ct[i]+=ct[i-1];
    for (i=n;i>=1;i--)
      bk[ct[getdigit(a[i],k)]--]=a[i];
    for (i=1;i<=n;i++)
      a[i]=bk[i];
  }
  for (i=n;i>=1;i--)
    if (i==n||a[i]!=a[i+1])
      printf("%d\n",a[i]);
  return 0;
}

