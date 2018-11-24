#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

int a[4][109];
double p[104][104][104];
double f[3];

void init(int sig,int n)
{
  int i,j,k;
  for (i=1;i<=n;i++)
    for (j=1;j<=n;j++)
      for (k=1;k<=n;k++)
        if (k<=max(i,j)&&k>=min(i,j))
          a[sig][k]++;
}

void mat_pow(int b)
{
  double ans[3];
  ans[1]=1;ans[2]=0;
  double t[3];
  t[1]=f[1];t[2]=f[2];
  while(b)
  {
    if (b&1)
    {
      double tmp=ans[1]*t[1]+ans[2]*t[2];
      ans[2]=ans[1]*t[2]+ans[2]*t[1];
      ans[1]=tmp;
    }
    b>>=1;
    double tmp1=t[1]*t[1]+t[2]*t[2];
    double tmp2=t[1]*t[2]+t[2]*t[1];
    t[1]=tmp1;
    t[2]=tmp2;
  }
  f[1]=ans[1];f[2]=ans[2];
}

int main()
{
  freopen("11605.in","r",stdin);
  freopen("11605.out","w",stdout);
  int s1,s2,s3,n,t,ii,ca,i,j,k,m;
  scanf("%d",&ca);
  for (ii=1;ii<=ca;ii++)
  {
    scanf("%d%d%d%d",&s1,&s2,&s3,&t);
    memset(a,0,sizeof(a));
    init(0,s1);
    init(1,s2);
    init(2,s3);
    for (i=1;i<=s1;i++)
      for (j=1;j<=s2;j++)
        for (k=1;k<=s3;k++)
          p[i][j][k]=a[0][i]/(double)(s1*s1)*a[1][j]/(double)(s2*s2)*a[2][k]/(double)(s3*s3);
    double ans=0;
    for (i=1;i<=s1;i++)
      for (j=1;j<=s2;j++)
        for (k=1;k<=s3;k++)
        {
          double ti=p[i][j][k];
          f[1]=1-ti;
          f[2]=ti;
          mat_pow(t);
          ans+=f[2];
        }
    printf("Case %d: %.10lf\n",ii,ans);
  }
  return 0;
}
