#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

bool f[100009];
int p[100009];
int num[13],v[13];

int main()
{
  freopen("1276.in","r",stdin);
  freopen("1276.out","w",stdout);
  int n,i,j,k,m;
  while(scanf("%d%d",&m,&n)==2)
  {
    for (i=1;i<=n;i++)
      scanf("%d%d",&num[i],&v[i]);
    memset(f,0,sizeof(f));
    f[0]=true;
    for (i=1;i<=n;i++)
    {
      memset(p,0,sizeof(p));
      for (j=v[i];j<=m;j++)
        if (!f[j]&&f[j-v[i]]&&p[j-v[i]]+1<=num[i])
        {
          f[j]=true;
          p[j]=p[j-v[i]]+1;
		}
	}
	for (j=m;j>=0;j--)
	  if (f[j])
	  {
	    printf("%d\n",j);
	    break;
	  }
  }
  return 0;
}
