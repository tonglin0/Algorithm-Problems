#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

struct node{
	int w,v,q;
};
int f[5009];
node a[509];
bool cmp(node a,node b){return a.q-a.v<b.q-b.v;}

int main()
{
  freopen("3466.in","r",stdin);
  freopen("3466.out","w",stdout);
  int n,i,j,k,m;
  while(scanf("%d%d",&n,&m)==2)
  {
    for (i=1;i<=n;i++)
      scanf("%d%d%d",&a[i].v,&a[i].q,&a[i].w);
    sort(a+1,a+n+1,cmp);
    memset(f,0,sizeof(f));
    for (i=1;i<=n;i++)
      for (j=m;j>=a[i].q;j--)
        f[j]=max(f[j],f[j-a[i].v]+a[i].w);
    printf("%d\n",f[m]);
  }
  return 0;
}
