#include<cstdio>
#include<cstdlib>
#include<cmath>
#define lint long long
using namespace std;

lint phi[80009];

int main()
{
  freopen("2190.in","r",stdin);
  freopen("2190.out","w",stdout);
  lint n,i,j,k,m,ans;
  scanf("%I64d",&n);
  if (n==1)
  {
    printf("0\n");
    return 0;
  }
  else if (n==2)
  {
    printf("3\n");
    return 0;
  }
  else if (n==3)
  {
    printf("5\n");
    return 0;
  }
  ans=0;
  n--;
  phi[1]=1;
  for (i=2;i<=n;i++)
    phi[i]=0;
  for (i=2;i<=n;i++)
    if (!phi[i])
      for (j=i;j<=n;j+=i)
      {
        if (!phi[j])
          phi[j]=j;
        phi[j]=phi[j]/i*(i-1);
      }
  for (i=1;i<=n;i++)
    ans+=phi[i];
  ans=ans<<1;
  printf("%I64d\n",ans+1);
  return 0;
}
