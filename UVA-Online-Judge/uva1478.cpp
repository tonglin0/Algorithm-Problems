#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#define lint long long
using namespace std;

int c2[10009];
int c3[10009];
int c1[10009];

int main()
{
  freopen("1478.in","r",stdin);
  freopen("1478.out","w",stdout);
  int n,i,j,k,m;
  memset(c1,0,sizeof(c1));
  memset(c2,0,sizeof(c2));
  c2[1]=1;c2[2]=2;
  for (i=3;i<=10000;i++)
    if (i&1)
      c2[i]=c2[i-1]*i/(i-(i-1)/2);
    else
      c2[i]=c2[i-1]*i/((i-1)/2+1);
  for (i=2;i<=10000;i++)
    c1[i]=c2[i]*(i/2)/(i-(i/2)+1);
  while(scanf("%d",&n)==1)
  {
    int ans=0;
    memset(c3,0,sizeof(c3));
    c3[0]=1;c3[1]=n;
    for (i=2;i<=n;i++)
      c3[i]=c3[i-1]*(n-i+1)/i;
    for (i=2;i<=n;i+=2)
    {
	  int x=i+1;
      ans+=c3[i]*(c2[i]-c1[i]);
    }
	ans++;
    printf("%d\n",ans);
  }
  return 0;
}
