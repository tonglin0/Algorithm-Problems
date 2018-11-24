#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

struct mat{
       int h,w;
       int s[3][3];};

mat cheng(mat a,mat b)
{
  mat c;
  c.h=a.h;c.w=b.w;
  memset(c.s,0,sizeof(c.s));
  for (int i=1;i<=c.h;i++)
    for (int j=1;j<=c.w;j++)
      for (int k=1;k<=a.w;k++)
        c.s[i][j]=(c.s[i][j]+a.s[i][k]*b.s[k][j])%10000;
  return c;
}

int main()
{
  freopen("3070.in","r",stdin);
  freopen("3070.out","w",stdout);
  int n,i,j,k,m;
  mat o;
  o.h=2;o.w=2;
  o.s[1][1]=o.s[1][2]=o.s[2][1]=1;
  o.s[2][2]=0;
  while(scanf("%d",&n)==1&&(n!=-1))
  {
    if (n==0)
    {
      printf("0\n");
      continue;
    }
    else if (n==1)
    {
      printf("1\n");
      continue;
    }
    mat ans;
    ans.h=ans.w=2;
    ans.s[1][1]=ans.s[2][2]=1;
    ans.s[1][2]=ans.s[2][1]=0;
    mat t;
    t=o;
    while(n>0)
    {
      if (n&1) ans=cheng(ans,t);
      t=cheng(t,t);
      n>>=1;
    }
    mat tmp;
    tmp.h=2;tmp.w=1;
    tmp.s[1][1]=0;tmp.s[2][1]=1;
    tmp=cheng(ans,tmp);
    printf("%d\n",tmp.s[1][1]);
  }
  return 0;
}
