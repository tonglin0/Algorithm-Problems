#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

int s[1009],f[1009];

int main()
{
  freopen("11728.in","r",stdin);
  freopen("11728.out","w",stdout);
  int n,i,j,k,m;
  memset(s,0,sizeof(s));
  memset(f,0,sizeof(f));
  for (i=0;i<=1000;i++)
    for (j=1;j<=i;j++)
      if (i%j==0)
        s[i]+=j;
  for (i=0;i<=1000;i++)
  {
    bool flag=false;
    for (j=1000;j>=1;j--)
      if (s[j]==i)
      {
        f[i]=j;
        flag=true;
        break;
	  }
	if (!flag)
	  f[i]=-1;
  }
  int ii=0;
  while(scanf("%d",&n)==1)
  {
    if (n==0) break;
    printf("Case %d: ",++ii);
    printf("%d\n",f[n]);
  }
  return 0;
}
