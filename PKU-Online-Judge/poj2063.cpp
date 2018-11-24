#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

int v[15],w[15];
int f[59000];

int main()
{
  freopen("2063.in","r",stdin);
  freopen("2063.out","w",stdout);
  int ca,n,i,j,k,m,t;
  scanf("%d",&ca);
  while(ca--)
  {
    scanf("%d%d",&m,&t);
    int ans=m%1000;
    m/=1000;
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
	  scanf("%d%d",&v[i],&w[i]);
      v[i]/=1000;
	}
	while(t--)
	{
	  for (i=0;i<=m;i++)
	    f[i]=0;//memset(f,0,sizeof(f));
	  for (i=1;i<=n;i++)
	    for (j=v[i];j<=m;j++)
	      f[j]=max(f[j],f[j-v[i]]+w[i]);
	  ans+=f[m];
	  m+=ans/1000;
	  ans%=1000;
	}
	printf("%d\n",1000*m+ans);
  }
  return 0;
}
