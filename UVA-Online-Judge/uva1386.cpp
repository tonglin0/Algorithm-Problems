#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
//#define lint long long
using namespace std;

struct mat{
	int n;
	int s[505];
	mat(){memset(s,0,sizeof(s));}
	mat(int n):n(n){memset(s,0,sizeof(s));}
};

int MOD;

mat cheng(mat a,mat b)
{
  mat c(a.n);
  int j,k;
  for (j=1;j<=a.n;j++)
    for (k=1;k<=a.n;k++)
      c.s[j]=((long long)c.s[j]+(long long)b.s[(j-k+a.n)%a.n+1]*a.s[k])%MOD;
  return c;
}

mat mat_pow(mat a,int b)
{
  mat t;t=a;
  mat ans(a.n);
  ans.s[1]=1;
  while(b)
  {
    if (b&1)
      ans=cheng(ans,a);
    a=cheng(a,a);
    b>>=1;
  }
  return ans;
}

int main()
{
  freopen("1386.in","r",stdin);
  freopen("1386.out","w",stdout);
  int d,n,i,j,k,m;
  while(scanf("%d%d%d%d",&n,&MOD,&d,&k)==4)
  {
    mat a(n);
    mat ans(n);
    for (i=1;i<=n;i++)
      if (min(i-1,n-i+1)<=d)
        a.s[i]=1;
    for (i=1;i<=n;i++)
      scanf("%d",&ans.s[i]);
    ans=cheng(ans,mat_pow(a,k));
    printf("%d",ans.s[1]);
    for (i=2;i<=n;i++)
      printf(" %d",ans.s[i]);
    printf("\n");
  }
  return 0;
}
