#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

int MOD;
int pre[17];

struct mat{
	int h,w;
	int s[16][16];
	mat(){memset(s,0,sizeof(s));}
	mat(int h,int w):h(h),w(w){memset(s,0,sizeof(s));}
};

mat cheng(mat a,mat b)
{
  mat c(a.h,b.w);
  for (int i=0;i<a.h;i++)
    for (int j=0;j<b.w;j++)
      for (int k=0;k<a.w;k++)
        c.s[i][j]=(c.s[i][j]+a.s[i][k]*b.s[k][j])%MOD;
  return c;
}

mat mat_pow(mat a,int b)
{
  mat t;t=a;
  mat ans(a.h,a.w);
  for (int i=0;i<a.h;i++)
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

bool ok(int s)
{
  int cnt=0;
  while(s)
  {
    if (s&1)
      cnt++;
    else
    {
      if (cnt&1)
        return false;
      cnt=0;
	}
	s>>=1;
  }
  if (cnt&1)
    return false;
  return true;
}

int main()
{
  freopen("3420.in","r",stdin);
  freopen("3420.out","w",stdout);
  int n,i,j,k,m;
  int full=15;
  for (i=0;i<=full;i++)
    if (ok(i))
      pre[i]=true;
    else
      pre[i]=false;
  mat t(16,16);
  for (i=0;i<16;i++)
    for (j=0;j<16;j++)
      if (((i|j)==full)&&pre[i&j])
        t.s[i][j]=1;
  mat oi(16,1);
  for (i=0;i<16;i++)
    if (pre[i])
      oi.s[i][0]=1;
  while(scanf("%d%d",&n,&MOD)==2&&MOD)
    printf("%d\n",cheng(mat_pow(t,n-1),oi).s[15][0]);
  return 0;
}
