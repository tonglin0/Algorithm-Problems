#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<vector>
#include<queue>
#include<string>
#include<map>
#include<cctype>
#include<algorithm>
#define INF (int)1e9
#define lint long long
#define llu unsigned long long
#define eps 1e-8

using namespace std;

double a[3005],c[3005];
double s[3005];

int main()
{
  freopen("2601.in","r",stdin);
  freopen("2601.out","w",stdout);
  int n,i,j,k,m;
  scanf("%d",&n);
  scanf("%lf%lf",&a[0],&a[n+1]);
  for (i=1;i<=n;i++)
    scanf("%lf",&c[i]);
  s[0]=0;
  for (i=1;i<=n;i++)
    s[i]=s[i-1]+c[i];
  double ans=0;
  for (i=1;i<=n;i++)
    ans=ans-2.0*s[i];
  printf("%.2lf\n",(n*a[0]+a[n+1]+ans)/(double)(n+1));
  return 0;
}

