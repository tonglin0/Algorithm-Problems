#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

int a[1055];

int main()
{
  int n,i,j,k,T;
  freopen("1833.in","r",stdin);
  freopen("1833.out","w",stdout);
  scanf("%d",&T);
  while(T--)
  {
    memset(a,0,sizeof(a));
    scanf("%d%d",&n,&k);
    for (i=1;i<=n;i++)
      scanf("%d",&a[i]);
    while(k--)
      next_permutation(a+1,a+n+1);
    for (i=1;i<=n;i++)
      printf("%d ",a[i]);
    printf("\n");
  }
  return 0;
}
