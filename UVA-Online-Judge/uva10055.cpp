#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;

int main()
{
  long long a,b;
  while (scanf("%lld%lld",&a,&b)==2)
    printf("%lld\n",abs(a-b));
  //system("pause");
  return 0;
}
