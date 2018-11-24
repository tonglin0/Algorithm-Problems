#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define MOD 1000000007
#define lint long long
using namespace std;

struct mat{
	int h,w;
	lint s[7][7];
	mat(){memset(s,0,sizeof(s));}
	mat(int h,int w):h(h),w(w){memset(s,0,sizeof(s));}
};

mat cheng(mat a,mat b)
{
  mat c(a.h,b.w);
  int i,j,k;
  for (i=1;i<=a.h;i++)
    for (j=1;j<=b.w;j++)
      for (k=1;k<=a.w;k++)
        c.s[i][j]=(c.s[i][j]+a.s[i][k]*b.s[k][j])%MOD;
  return c;
}

mat mat_pow(mat a,lint b)
{
  mat t;t=a;
  mat ans(a.h,a.w);
  for (int i=1;i<=a.h;i++)
    ans.s[i][i]=1;
  while(b)
  {
    if (b&1)
      ans=cheng(t,ans);
    b>>=1;
    t=cheng(t,t);
  }
  return ans;
}

int main()
{
  freopen("4686.in","r",stdin);
  freopen("4686.out","w",stdout);
  lint n,i,j,k,m,a,b,xa,ya,xb,yb;
  while(scanf("%I64d%I64d%I64d%I64d%I64d%I64d%I64d",&n,&a,&xa,&ya,&b,&xb,&yb)==7)
  {
    mat t(5,5);
    t.s[1][1]=xa*xb%MOD;
    t.s[1][2]=xa*yb%MOD;
    t.s[1][3]=xb*ya%MOD;
    t.s[1][4]=ya*yb%MOD;
    t.s[2][2]=xa%MOD;
    t.s[2][4]=ya%MOD;
    t.s[3][3]=xb%MOD;
    t.s[3][4]=yb%MOD;
    t.s[4][4]=1;
    t.s[5][1]=t.s[5][5]=1;
    t=mat_pow(t,n);
    mat oi(5,1);
    oi.s[1][1]=a*b%MOD;
    oi.s[2][1]=a%MOD;
    oi.s[3][1]=b%MOD;
    oi.s[4][1]=1;
    oi=cheng(t,oi);
    printf("%I64d\n",oi.s[5][1]);
  }
  return 0;
}
