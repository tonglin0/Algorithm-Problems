#include<cstdio>
#include<cstdlib>
using namespace std;

int main()
{
  freopen("4349.in","r",stdin);
  freopen("4349.out","w",stdout);
  int n,i,j,ans;
  while(scanf("%d",&n)==1)
  {
    ans=0;
    while(n)
    {
      if (n&1)
        ans++;
      n>>=1;
    }
    printf("%d\n",1<<ans);
  }
  return 0;
}
