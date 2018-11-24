#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

int MOD;

struct mat{
	int h,w;
	int s[6][6];
	mat(){memset(s,0,sizeof(s));}
	mat(int h,int w):h(h),w(w){memset(s,0,sizeof(s));}
};

mat cheng(mat a,mat b)
{
  mat c(a.h,a.w);
  int i,j,k;
  for (i=1;i<=a.h;i++)
    for (j=1;j<=b.w;j++)
      for (k=1;k<=a.w;k++)
        c.s[i][j]=(c.s[i][j]+a.s[i][k]*b.s[k][j])%MOD;
  return c;
}

mat mat_pow(mat a,int b)
{
  mat t;t=a;
  mat ans(a.h,a.w);
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

int main()
{
  freopen("2604.in","r",stdin);
  freopen("2604.out","w",stdout);
  int n,i,j,k,m;
  mat t(4,4);
  t.s[1][1]=t.s[1][3]=t.s[2][1]=t.s[3][2]=t.s[4][2]=t.s[3][4]=1;
  mat ans(4,1);
  for (i=1;i<=4;i++) 
    ans.s[i][1]=1;
  while(scanf("%d%d",&n,&MOD)==2)
  {
    if (n==0)
      printf("0\n");
    else if (n==1)
      printf("2\n");
    else
    {
      int f=0;
      mat tmp;
      tmp=cheng(mat_pow(t,n-2),ans);
      for (i=1;i<=4;i++)
        f=(f+tmp.s[i][1])%MOD;
      printf("%d\n",f);
	}
  }
  return 0;
}
