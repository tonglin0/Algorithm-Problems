#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define MOD 1024
using namespace std;

struct mat{
	int h,w;
	int s[4][4];
	mat(){memset(s,0,sizeof(s));}
	mat(int h,int w):h(h),w(w){memset(s,0,sizeof(s));}
};

mat cheng(mat a,mat b)
{
  mat c(a.h,b.w);
  int i,j,k;
  for (i=1;i<=c.h;i++)
    for (j=1;j<=b.w;j++)
      for (k=1;k<=a.w;k++)
        c.s[i][j]=(c.s[i][j]+a.s[i][k]*b.s[k][j])%MOD;
  return c;
}

mat mat_pow(mat a,int b)
{
  mat t;t=a;
  mat ans(2,2);
  ans.s[1][1]=ans.s[2][2]=1;
  while(b)
  {
    if (b&1)
      ans=cheng(ans,t);
    t=cheng(t,t);
    b>>=1;
  }
  return ans;
}

int main()
{
  freopen("2256.in","r",stdin);
  freopen("2256.out","w",stdout);
  int ca,n,i,j,k,m;
  mat I(2,2);
  I.s[1][1]=I.s[2][2]=5;
  I.s[1][2]=12;I.s[2][1]=2;
  mat oi(2,1);
  oi.s[1][1]=5;oi.s[2][1]=2;
  scanf("%d",&ca);
  while(ca--)
  {
    scanf("%d",&n);
    mat t(2,2);
    t=mat_pow(I,n-1);
    mat ans(2,1);
    ans=cheng(t,oi);
    printf("%d\n",(ans.s[1][1]*2-1+MOD)%MOD);
  }
  return 0;
}
