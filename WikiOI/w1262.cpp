#include<cstdlib>
#include<cstdio>
using namespace std;

int main()
{
  int ans,n;
  scanf("%d",&n);
  ans=(n-1)*(n-2)*(n-3)/6;
  printf("%d\n",ans);
  return 0;
}
