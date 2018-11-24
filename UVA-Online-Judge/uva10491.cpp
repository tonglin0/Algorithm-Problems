#include<cstdio>
#include<cstdlib>
#include<cmath>
#define eps 1e-10
using namespace std;

int main()
{
  freopen("10491.in","r",stdin);
  freopen("10491.out","w",stdout);
  double a,b,c;
  while(scanf("%lf%lf%lf",&a,&b,&c)==3)
    printf("%.5lf\n",a*b/((a+b)*(a+b-c-1))+b*(b-1)/((a+b)*(a+b-1-c))+eps);
  return 0;
}
