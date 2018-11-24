#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

int MOD;

struct mat{
	int h,w;
	int s[4][4];
	mat(){memset(s,0,sizeof(s));}
	mat(int h,int w):h(h),w(w){memset(s,0,sizeof(s));}
};

void debug(mat a)
{
  for (int i=1;i<=a.h;i++)
  {
    for (int j=1;j<=a.w;j++)
      printf("%d ",a.s[i][j]);
    printf("\n");
  }
}

mat cheng(mat a,mat b)
{
  int i,j,k;
  mat c(a.h,b.w);
  for (i=1;i<=a.h;i++)
    for (j=1;j<=b.w;j++)
      for (k=1;k<=a.w;k++)
        c.s[i][j]=(c.s[i][j]+a.s[i][k]*b.s[k][j])%MOD;
  return c;
}

mat mat_pow(mat a,int b)
{
  mat t(2,2);t=a;
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
  freopen("2855.in","r",stdin);
  freopen("2855.out","w",stdout);
  int n,i,j,k,m;
  mat I(2,2);
  I.s[1][2]=I.s[2][1]=I.s[2][2]=1;
  mat oi(2,1);
  oi.s[2][1]=1;
  int ca;
  scanf("%d",&ca);
  while(ca--)
  {
  	scanf("%d%d",&n,&MOD);
    mat t(2,1);
    //debug(mat_pow(I,2*n));
    //return 0;
    t=cheng(mat_pow(I,2*n),oi);
    printf("%d\n",t.s[1][1]);
  }
  return 0;
}
