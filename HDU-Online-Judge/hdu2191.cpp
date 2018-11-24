#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

int v[109],w[109],num[109],f[109];

int main()
{
  freopen("2191.in","r",stdin);
  freopen("2191.out","w",stdout);
  int ca,n,i,j,k,m;
  scanf("%d",&ca);
  while(ca--)
  {
    scanf("%d%d",&m,&n);
    for (i=1;i<=n;i++)
      scanf("%d%d%d",&v[i],&w[i],&num[i]);
    memset(f,0,sizeof(f));
    for (i=1;i<=n;i++)
    {
      k=1;
      while(num[i])
      {
        if (k>num[i])
          k=num[i];
        num[i]-=k;
        for (j=m;j>=v[i]*k;j--)
          f[j]=max(f[j],f[j-k*v[i]]+k*w[i]);
	  }
	  k<<=1;
	}
	printf("%d\n",f[m]);
  }
  return 0;
}
