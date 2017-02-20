#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

int a[1000009];
int q[2000009];
int mi[1000009],ma[1000009];

int main()
{
  freopen("2823.in","r",stdin);
  freopen("2823.out","w",stdout);
  int n,i,j,k,m;
  scanf("%d%d",&n,&k);
  for (i=1;i<=n;i++)
    scanf("%d",&a[i]);
  int r=0,f=1;
  for (i=1;i<=min(k,n);i++)
  {
    while(r>=f&&a[q[r]]>=a[i])
      r--;
    q[++r]=i;
  }
  mi[1]=a[q[f]];
  for (i=2;i<=n-k+1;i++)
  {
    while(r>=f&&a[q[r]]>=a[i+k-1])
      r--;
    q[++r]=i+k-1;
    while(r>=f&&q[f]<i)
      f++;
    mi[i]=a[q[f]];
  }
  bool first=true;
  for (i=1;i<=n-k+1;i++)
    if (first)
    {
      printf("%d",mi[i]);
      first=false;
    }
    else
      printf(" %d",mi[i]);
  printf("\n");
  r=0;f=1;
  for (i=1;i<=min(n,k);i++)
  {
    while(r>=f&&a[q[r]]<=a[i])
      r--;
    q[++r]=i;
  }
  ma[1]=a[q[f]];
  for (i=2;i<=n-k+1;i++)
  {
    while(r>=f&&a[q[r]]<=a[i+k-1])
      r--;
    q[++r]=i+k-1;
    while(r>=f&&q[f]<i)
      f++;
    ma[i]=a[q[f]];
  }
  first=true;
  for (i=1;i<=n-k+1;i++)
    if (first)
    {
      printf("%d",ma[i]);
      first=false;
    }
    else
      printf(" %d",ma[i]);
  printf("\n");
  return 0;
}
