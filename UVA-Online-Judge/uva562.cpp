#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

bool f[50009];
int Abs(int x){return x>=0?x:-x;}
int v[109];

int main()
{
  freopen("562.in","r",stdin);
  freopen("562.out","w",stdout);
  int n,i,j,k,m,s,ca;
  scanf("%d",&ca);
  while(ca--)
  {
    scanf("%d",&n);
    s=0;
    for (i=1;i<=n;i++)
    {
      scanf("%d",&v[i]);
      s+=v[i];
	}
	memset(f,0,sizeof(f));
	f[0]=true;
	for (i=1;i<=n;i++)
	  for (j=s/2;j>=v[i];j--)
	    f[j]=f[j]||f[j-v[i]];
	for (i=s/2;i>=0;i--)
	  if (f[i])
	  {
	    printf("%d\n",Abs(s-i-i));
	    break;
	  }
  }
  return 0;
}
