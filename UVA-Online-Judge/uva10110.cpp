#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;

int main()
{
  long long n,i;
  while(scanf("%lld",&n)==1)
  {
    if (n==0)
      break;
	if (((long long)sqrt(n+0.5)*(long long)sqrt(n+0.5))==n)
      printf("yes\n");
    else
      printf("no\n");
  }
  return 0;
}
