#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define MOD ((int)(1e9)+7)
using namespace std;

int f[2][1003][1003];
int lcm[1003][1003];
int p[1003];

int gcd(int a,int b)
{
  int t=a;
  while(b)
  {
    t=a;
    a=b;
    b=t%b;
  }
  return a;
}

int LCM(int a,int b)
{
  return a*b/gcd(a,b);
}

int main()
{
  freopen("3662.in","r",stdin);
  freopen("3662.out","w",stdout);
  int n,i,j,k,a,b,c,m;
  for (i=1;i<=1000;i++)
    for (j=1;j<=i;j++)
      lcm[i][j]=lcm[j][i]=LCM(i,j);
  while(scanf("%d%d%d",&a,&b,&c)==3)
  {
    int now=0,top=0;
    for (i=1;i<=b;i++)
      if (b%i==0)
        p[++top]=i;
    for (int ii=0;ii<=a;ii++)
      for (int jj=0;jj<=b;jj++)
        f[now][ii][jj]=0;
    f[0][0][1]=1;
    for (i=1;i<=c;i++)
    {
      now^=1;
      for (int ii=0;ii<=a;ii++)
        for (int jj=0;jj<=b;jj++)
          f[now][ii][jj]=0;
      for (j=0;j<=a;j++)                  // need experiment
	    for (k=1;k<=top;k++)
	    {
	      int t=p[k];
	      if (f[now^1][j][t]==0)
	        continue;
	      for (int h=1;h<=top;h++)
	      {
	        int x=j+p[h];
	        int y=lcm[t][p[h]];
	        if (x>a||(b%y!=0))
	          continue;
			f[now][x][y]=(f[now][x][y]+f[now^1][j][t])%MOD;
		  }
		}
	}
	printf("%d\n",f[now][a][b]);
  }
  return 0;
}
