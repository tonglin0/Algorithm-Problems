#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

int v[12],d[12],l[12];

int main()
{
  freopen("12230.in","r",stdin);
  freopen("12230.out","w",stdout);
  int ii=0,n,i,j,k,s,m,D;
  while(scanf("%d%d",&n,&D)==2&&(n+D))
  {
    printf("Case %d: ",++ii);
    s=0;
	for (i=1;i<=n;i++)
    {
      scanf("%d%d%d",&d[i],&l[i],&v[i]);
      s+=l[i];
	}
	double ans=D-s;
	for (i=1;i<=n;i++)
	  ans+=2*l[i]/(double)v[i];
	printf("%.3lf\n\n",ans);
  }
  return 0;
}
