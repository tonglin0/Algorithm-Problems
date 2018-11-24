#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int a[100004];

int main()
{
  freopen("3273.in","r",stdin);
  freopen("3273.out","w",stdout);
  int t,n,j,i,k,m,l,r,s,mm;
  scanf("%d%d",&n,&m);
  memset(a,0,sizeof(a));
  mm=s=0;
  for (i=1;i<=n;i++)
  {
    scanf("%d",&a[i]);
    s+=a[i];
    mm=max(mm,a[i]);
  }
  l=mm;r=s;
  while(l<r)
  {
    int mid;
    mid=(l+r)>>1;
    t=0;
    k=1;
    for (i=1;i<=n;i++)
    {
      if (t+a[i]>mid){k++;t=a[i];} 
      else t+=a[i]; 
      if (k>m) break;
    }
    if (k>m) l=mid+1;
    else r=mid;
  }
  printf("%d\n",l);
  return 0;
}
