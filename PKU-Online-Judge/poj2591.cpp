#include<cstdlib>
#include<cstdio>
#include<cstring>
using namespace std;

int a[10000003];

int main()
{
  freopen("2591.in","r",stdin);
  freopen("2591.out","w",stdout);
  a[1]=1;
  int i,j,x,y,k,n,m;
  x=2*1+1;y=3*1+1;
  i=1;j=1;
  int t=1;
  while(t<=10000000)
  {
    if (x<y)
    {
      t++;
      a[t]=x;
      i++;
      x=2*a[i]+1;
    }
    else if (y<x)
    {
      t++;
      a[t]=y;
      j++;
      y=3*a[j]+1;
    }
    else
    {
      t++;
      a[t]=x;
      i++;
      j++;
      x=2*a[i]+1;
      y=3*a[j]+1;
    }
  }
  while(scanf("%d",&n)==1)
    printf("%d\n",a[n]);
  return 0;
}
