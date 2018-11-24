#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

int f[1003];
int v[103],w[103];

int main()
{
  freopen("3111.in","r",stdin);
  freopen("3111.out","w",stdout);
  int n,i,j,k,m;
  scanf("%d%d",&m,&n);
  for (i=1;i<=n;i++)
    scanf("%d%d",&v[i],&w[i]);
  memset(f,0,sizeof(f));
  for (i=1;i<=n;i++)
    for (j=m;j>=v[i];j--)
      f[j]=max(f[j],f[j-v[i]]+w[i]);
  printf("%d\n",f[m]);
  return 0;
}
