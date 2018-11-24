#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

int v[1009];
bool f[1090];

int main()
{
  freopen("2546.in","r",stdin);
  freopen("2546.out","w",stdout);
  int n,i,j,k,m;
  while(scanf("%d",&n)==1&&n)
  {
    for (i=1;i<=n;i++)
      scanf("%d",&v[i]);
    sort(v+1,v+n+1);
    scanf("%d",&m);
    memset(f,0,sizeof(f));
    f[0]=true;
    for (i=1;i<=n;i++)
      for (j=m+51;j>=v[i];j--)
        if (j-v[i]<=m-5)
          f[j]=(f[j]||f[j-v[i]]);
    for (i=m+51;i>=0;i--)
      if (f[i])
      {
        printf("%d\n",m-i);
        break;
	  }
  }
  return 0;
}
