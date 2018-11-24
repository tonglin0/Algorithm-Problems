#include<cstdio>
#include<cstdlib>
using namespace std;

int main()
{
  freopen("3146.in","r",stdin);
  freopen("3146.out","w",stdout);
  int p,n,i,j,k,ans,ii=0;
  while(scanf("%d%d",&p,&n)==2&&(n+p))
  {
    ans=1;
    ii++;
    while(n)
    {
      ans=(ans*(n%p+1))%10000;
      n/=p;
    }
    printf("Case %d: ",ii);
    if (ans>=100&&ans<1000)
      printf("0");
    else if (ans<100&&ans>=10)
      printf("00");
    else if (ans<10)
      printf("000");
    printf("%d\n",ans);
  }
  return 0;
}
