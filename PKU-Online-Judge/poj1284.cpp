#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

int phi(int n)
{
  int ans=n;
  int m=(int)sqrt(n+0.5);
  for (int i=2;i<=m;i++)
  {
    if (n%i==0)
    {
      ans=ans/i*(i-1);
      while(n%i==0)
        n/=i;
    }
  }
  if (n>1)
    ans=ans/n*(n-1);
  return ans;
}

int main()
{
  freopen("1284.in","r",stdin);
  freopen("1284.out","w",stdout);
  int n,i,j;
  while(scanf("%d",&n)==1)
    printf("%d\n",phi(n-1));
  return 0;
}
