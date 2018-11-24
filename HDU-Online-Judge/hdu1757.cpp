#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

struct mat{
	int h,w;
	int s[13][13];
	mat(int h,int w):h(h),w(w){memset(s,0,sizeof(s));};
};

int MOD;
int aa[12];

mat cheng(mat a,mat b)
{
  mat c(a.h,b.w);
  for (int i=1;i<=c.h;i++)
    for (int j=1;j<=c.w;j++)
      for (int k=1;k<=a.w;k++)
        c.s[i][j]=(c.s[i][j]+a.s[i][k]*b.s[k][j])%MOD;
  return c;
}

mat mat_pow_mod(mat a,int b,int c)
{
  mat t=a;
  mat ans(a.h,a.w);
  for (int i=1;i<=a.h;i++)
    ans.s[i][i]=1;
  while(b)
  {
    if (b&1)
      ans=cheng(ans,t);
    b>>=1;
    t=cheng(t,t);
  }
  return ans;
}

int main()
{
  freopen("1757.in","r",stdin);
  freopen("1757.out","w",stdout);
  int n,i,j,k,m;
  while(scanf("%d%d",&k,&MOD)==2)
  {
    for(i=1;i<=10;i++)
      scanf("%d",&aa[i]);
    if (k<=9)
    {
      printf("%d\n",k%MOD);
      continue;
	}
	mat ans(10,1);
	//ans.h=10;ans.w=1;
	for (i=1;i<=10;i++)
	  ans.s[i][1]=i-1;
	mat a(10,10);
	for (i=1;i<=9;i++)
	  a.s[i][i+1]=1;
	for (i=1;i<=10;i++)
	  a.s[10][i]=aa[10-i+1];
	a=mat_pow_mod(a,k,MOD);
	ans=cheng(a,ans);
	printf("%d\n",ans.s[1][1]);
  }
  return 0;
} 
