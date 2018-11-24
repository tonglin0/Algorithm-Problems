#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define lint long long
using namespace std;

struct mat{
	int h,w;
	lint s[4][4];
	mat(){memset(s,0,sizeof(s));}
	mat(int h,int w):h(h),w(w){memset(s,0,sizeof(s));}
};

lint MOD;
mat I(2,2);

mat cheng(mat a,mat b)
{
  mat c(a.h,b.w);
  int i,j,k;
  for (i=1;i<=c.h;i++)
    for (j=1;j<=c.w;j++)
      for (k=1;k<=a.w;k++)
        c.s[i][j]=(c.s[i][j]+a.s[i][k]*b.s[k][j])%MOD;
  return c;
}

mat jia(mat a,mat b)
{
  mat c(a.h,a.w);
  for (int i=1;i<=a.h;i++)
    for (int j=1;j<=a.w;j++)
      c.s[i][j]=(a.s[i][j]+b.s[i][j])%MOD;
  return c;
}

mat jian(mat a,mat b)
{
  mat c(a.h,a.w);
  for (int i=1;i<=a.h;i++)
    for (int j=1;j<=a.w;j++)
      c.s[i][j]=(a.s[i][j]-b.s[i][j]+MOD)%MOD;
  return c;
}

mat mat_pow(mat a,int b)
{
  mat t;t=a;
  mat ans(a.h,a.h);
  for (int i=1;i<=a.h;i++)
    ans.s[i][i]=1;
  while(b)
  {
    if (b&1)
      ans=cheng(ans,t);
    t=cheng(t,t);
    b>>=1;
  }
  return ans;
}

mat work(mat t,lint l,lint r)
{
  if (l==r)
    return mat_pow(t,l);
  int mid=(l+r)>>1;
  mat tmp(2,2);
  tmp=work(t,l,mid);
  if (((r+1)&1)==0)
    return jia(cheng(mat_pow(t,mid+1),tmp),tmp);
  else
    return jia(jian(cheng(mat_pow(t,mid),tmp),mat_pow(t,mid)),tmp);
} 

void debug(mat a)
{
  int i,j;
  for (i=1;i<=a.h;i++)
  {
    for (j=1;j<=a.w;j++)
      printf("%lld ",a.s[i][j]);
    printf("\n");
  }
}

int main()
{
  freopen("1588.in","r",stdin);
  freopen("1588.out","w",stdout);
  lint n,i,j,k,b,m;
  char ss[]="%I64d";
  char ssn[]="%I64d\n";
  I.s[1][1]=0;
  I.s[1][2]=I.s[2][1]=I.s[2][2]=1;
  mat oi(2,1);
  oi.s[1][1]=0;oi.s[2][1]=1;
  while(scanf(ss,&k)==1)
  {
    scanf(ss,&b);scanf(ss,&n);scanf(ss,&MOD);
    mat a(2,1);
    a=cheng(mat_pow(I,b),oi);
    mat t(2,2);
    t=mat_pow(I,k);
    mat tmp(2,2);
    tmp=work(t,0,n-1);
    a=cheng(tmp,a);
    printf(ssn,a.s[1][1]);
  }
  return 0;
}
