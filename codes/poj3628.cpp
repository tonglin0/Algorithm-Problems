#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;

bool f[20000003];
int v[23];

int main()
{
  freopen("3628.in","r",stdin);
  freopen("3628.out","w",stdout);
  int n,s=0,i,j,k,m;
  scanf("%d%d",&n,&k);
  for (i=1;i<=n;i++)
  {
    scanf("%d",&v[i]);
    s+=v[i];
  }
  for (i=1;i<=s;i++)
    f[i]=false;
  f[0]=true;
  for (i=1;i<=n;i++)
    for (j=s;j>=v[i];j--)
      f[j]=f[j]||f[j-v[i]];
  for (i=k;i<=s;i++)
    if (f[i])
    {
      printf("%d\n",i-k);
      return 0;
	}
  return 0;
}
