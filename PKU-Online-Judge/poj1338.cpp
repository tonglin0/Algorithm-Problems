#include<cstdlib>
#include<cstdio>
#include<cstring>
using namespace std;

int a[1504];

int main()
{
  freopen("1338.in","r",stdin);
  freopen("1338.out","w",stdout);
  int n,i,j,k,m,x,y,z;
  int t=1;
  i=1;j=1;k=1;
  a[1]=1;
  x=2;y=3;z=5;
  while(t<=1500)
  {
    if (x<y&&x<z)
    {
      a[++t]=x;
      x=a[++i]*2;
    }
    else if (y<x&&y<z)
    {
      a[++t]=y;
      y=a[++j]*3;
    }
    else if (z<x&&z<y)
    {
      a[++t]=z;
      z=a[++k]*5;
    }
    else if (x==y&&x<z)
    {
      a[++t]=x;
      x=a[++i]*2;
      y=a[++j]*3;
    }
    else if (x==z&&x<y)
    {
      a[++t]=x;
      x=a[++i]*2;
      z=a[++k]*5;
    }
    else if (y==z&&y<x)
    {
      a[++t]=y;
      y=a[++j]*3;
      z=a[++k]*5;
    }
    else if (x==y&&y==z)
    {
      a[++t]=x;
      x=a[++i]*2;
      y=a[++j]*3;
      z=a[++k]*5;
    }
  }
  scanf("%d",&n);
  while(n)
  {
    printf("%d\n",a[n]);
    scanf("%d",&n);
  }
  return 0;
}
