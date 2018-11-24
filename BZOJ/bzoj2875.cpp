#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<ctime>
#include<vector>
#include<queue>
#define eps 1e-8
#define lint long long
#define INF (int)1e9
#define MOD m
using namespace std;

struct mat{
	int h,w;
	lint s[3][3];
	mat(){memset(s,0,sizeof(s));}
	mat(int h,int w):h(h),w(w){memset(s,0,sizeof(s));}
};
lint m;

lint mul(lint a,lint b)
{
  lint ans=0,t=a%MOD;
  while(b)
  {
    if (b&1)
      ans=(ans+t)%MOD;
    t=(t+t)%MOD;
    b>>=1;
  }
  return ans;
}

mat cheng(mat a,mat b)
{
  mat c(a.h,b.w);
  for (int i=1;i<=a.h;i++)
    for (int j=1;j<=b.w;j++)
      for (int k=1;k<=a.w;k++)
        //c.s[i][j]=(c.s[i][j]+a.s[i][k]*b.s[k][j])%MOD;
		c.s[i][j]=(c.s[i][j]+mul(a.s[i][k],b.s[k][j]))%MOD;
  return c;
}

mat mat_pow(mat a,lint b)
{
  mat ans(a.h,a.w);
  ans.s[1][1]=ans.s[2][2]=1;
  ans.s[2][1]=ans.s[1][2]=0;
  mat t(a.h,a.w);t=a;
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
  freopen("2875.in","r",stdin);
  freopen("2875.out","w",stdout);
  int i,j,k,ca;
  lint a,c,x0,n,g;
  cin>>m>>a>>c>>x0>>n>>g;
  //x0%=MOD;a%=MOD;c%=MOD;
  mat ori(2,1);
  ori.s[1][1]=1;ori.s[2][1]=x0;
  mat t(2,2);
  t.s[1][1]=1;t.s[1][2]=0;t.s[2][1]=c;t.s[2][2]=a;
  lint ans=cheng(mat_pow(t,n),ori).s[2][1];
  cout<<ans%g<<endl;
  //printf("%I64d\n",(cheng(mat_pow(t,n),ori).s[2][1])%g);
  return 0;
}

