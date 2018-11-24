#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;

int main()
{
  freopen("11538.in","r",stdin);
  freopen("11538.out","w",stdout);
  unsigned long long n,m;
  while(scanf("%llu%llu",&n,&m)==2)
  {
    if (n==0&&m==0) break;
    if (n>m) swap(n,m);
	printf("%llu\n",(m*n*(m+n-2))+(2*n*(n-1)*(2*n-1)/3+2*n*(n-1)*(m-n)));
  }
  return 0;
}
