#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

int a[15];

struct mat{
	int h,w;
	double s[4][4];
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
        c.s[i][j]+=a.s[i][k]*b.s[k][j];
  return c;
}

mat mat_pow(mat a,int b)
{
  mat t;t=a;
  mat ans(a.h,a.w);
  for (int i=1;i<=ans.h;i++)
    ans.s[i][i]=1;
  while(b)
  {
    if (b&1)
      ans=cheng(t,ans);
    t=cheng(t,t);
    b>>=1;
  }
  return ans;
}

int main()
{
  freopen("3744.in","r",stdin);
  freopen("3744.out","w",stdout);
  int n,i,j,k,m;
  double p;
  while(scanf("%d%lf",&n,&p)==2)
  {
    bool flag=true;
	for (i=1;i<=n;i++)
    {
      scanf("%d",&a[i]);
      if (a[i]==1)
      {
        printf("0.0000000\n");
        flag=false;
	  }
    }
    if (!flag)
      continue;
    sort(a+1,a+n+1);
    for (i=2;i<=n;i++)
      if (a[i]==a[i-1]+1)
      {
        printf("0.0000000\n");
        flag=false;
        break;
	  }
	if (!flag)
	  continue;
	mat t(2,2);
    t.s[1][2]=1;
    t.s[2][1]=1-p;
    t.s[2][2]=p;
    mat oi(2,1);
    oi.s[2][1]=1;
    int pred=1;
    for (i=1;i<=n;i++)
    {
      k=a[i]-pred;
      oi=cheng(mat_pow(t,k-1),oi);
      oi.s[2][1]*=(1-p);
      oi.s[1][1]=0;
	  pred=a[i]+1;
	}
	printf("%.7lf\n",oi.s[2][1]+1e-8);
  }
  return 0;
}

