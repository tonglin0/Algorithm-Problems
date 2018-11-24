#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

int v[3410],w[3410];
int f[12890];

int main()
{
  freopen("3624.in","r",stdin);
  freopen("3624.out","w",stdout);
  int n,i,j,k,m,c;
  memset(f,0,sizeof(f));
  scanf("%d%d",&n,&c);
  for (i=1;i<=n;i++)
    scanf("%d%d",&v[i],&w[i]);
  for (i=1;i<=n;i++)
    for (j=c;j>=v[i];j--)
      f[j]=max(f[j],f[j-v[i]]+w[i]);
  printf("%d\n",f[c]);
  return 0;
}
