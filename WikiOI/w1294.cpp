#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int a[13];

int main()
{
  freopen("1294.in","r",stdin);
  freopen("1294.out","w",stdout);
  int n,i,j;
  scanf("%d",&n);
  int m=1;
  for (i=2;i<=n;i++)
    m*=i;
  for (i=1;i<=n;i++)
    a[i]=i;
  for (i=1;i<=m;i++)
  {
    for (j=1;j<=n;j++)
      printf("%d ",a[j]);
    printf("\n");
    next_permutation(a+1,a+n+1);
  }
  return 0;
}
