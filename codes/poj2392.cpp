#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

struct node{
	int h,l,c;
};
node a[403];
int f[40005];

bool cmp(node a,node b){return a.l<b.l;}

int main()
{
  freopen("2392.in","r",stdin);
  freopen("2392.out","w",stdout);
  int n,i,j,k,m;
  scanf("%d",&n);
  for (i=1;i<=n;i++)
    scanf("%d%d%d",&a[i].h,&a[i].l,&a[i].c);
  memset(f,-1,sizeof(f));
  f[0]=0;
  sort(a+1,a+n+1,cmp);
  for (i=1;i<=n;i++)
  {
    for (j=0;j<=a[i].l-a[i].h;j++)
      if (f[j]!=-1)
        f[j]=a[i].c;
    for (j=0;j<=a[i].l-a[i].h;j++)
      f[j+a[i].h]=max(f[j+a[i].h],f[j]-1);
  }
  for (i=40000;i>=0;i--)
    if (f[i]!=-1)
    {
      printf("%d\n",i);
      return 0;
	}
  return 0;
}
