#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define LL long long
#define MN 500005
using namespace std;

LL a[MN],c[MN];
LL ans;

void merge_sort(int l,int r)
{
  if (l==r) return ;
  int m=(l+r)>>1;
  int i=l,j=m+1,p=l;
  merge_sort(l,m);
  merge_sort(m+1,r);
  while(i<=m||j<=r)
  {
    if (j>r||(i<=m&&a[i]<=a[j]))
      c[p++]=a[i++];
    else
    {
      c[p++]=a[j++];
      ans+=(LL)(m-i+1);
    }
  }
  for (i=l;i<=r;i++)
    a[i]=c[i];
}
 
int main()
{
  freopen("2299.in","r",stdin);
  freopen("2299.out","w",stdout);
  int n,i,j,k,m;
  scanf("%d",&n);
  while(n)
  {
    memset(a,0,sizeof(a));
    memset(c,0,sizeof(c));
    for (i=1;i<=n;i++)
      scanf("%I64d",&a[i]);
    ans=0;
    merge_sort(1,n);
    printf("%I64d\n",ans);
    scanf("%d",&n);
  }
  return 0;
}
