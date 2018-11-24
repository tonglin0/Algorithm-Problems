#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cstring>
using namespace std;

int w[1000],v[1000];
int f[10009];

int main()
{
  freopen("3231.in","r",stdin);
  freopen("3231.out","w",stdout);
  int c,n,i,j,k,m;
  scanf("%d%d",&n,&c);
  for (i=1;i<=n;i++)
    scanf("%d",&v[i]);
  for (i=1;i<=n;i++)
    scanf("%d",&w[i]);
  memset(f,0,sizeof(f));
  for (i=1;i<=n;i++)
    for (j=c;j>=v[i];j--)
      f[j]=max(f[j],f[j-v[i]]+w[i]);
  printf("%d\n",f[c]);
  return 0;
}
