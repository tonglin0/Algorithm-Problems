#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;

double f[1004][1004];

int main()
{
  freopen("2096.in","r",stdin);
  freopen("2096.out","w",stdout);
  int n,s,i,j,k;
  scanf("%d%d",&n,&s);
  f[n][s]=0;
  for (i=n-1;i>=0;i--)
    f[i][s]=(f[i+1][s]*(n-i)+n)/(double)(n-i);
  for (i=s-1;i>=0;i--)
    f[n][i]=(f[n][i+1]*(s-i)+s)/(double)(s-i);
  for (i=n-1;i>=0;i--)
    for (j=s-1;j>=0;j--)
      f[i][j]=((f[i+1][j]*(n-i)*j+f[i][j+1]*i*(s-j)+f[i+1][j+1]*(n-i)*(s-j)+(double)n*s))/((double)(n*s-i*j));
  printf("%.4lf\n",f[0][0]);
  return 0;
}
