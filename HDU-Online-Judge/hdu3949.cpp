#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define lint unsigned long long
using namespace std;

lint a[10002];

int gause(int n)
{
  int i=1,j=1,k,r,u;
  while(i<=n&&j<=64)
  {
    r=i;
    for (k=i;k<=n;k++)
      if (a[k]&(1LL<<(63-j+1)))
      {
        r=k;
        break;
	  }
	if (a[r]&(1LL<<(63-j+1)))
	{
	  if (r!=i)
	    swap(a[i],a[r]);
	  for (u=1;u<=n;u++)
	    if (u!=i&&(a[u]&(1LL<<(63-j+1))))
	      a[u]^=a[i];
	  i++;
	}
	j++;
  }
  return i-1;
}

int main()
{
  freopen("3949.in","r",stdin);
  freopen("3949.out","w",stdout);
  int ii=0,ca,n,i,j,k,m;
  scanf("%d",&ca);
  while(ca--)
  {
    printf("Case #%d:\n",++ii);
    scanf("%d",&n);
    for (i=1;i<=n;i++)
      scanf("%I64d",&a[i]);
    int r=gause(n);
    bool flag=false;
    if (r<n)
      flag=true;
    int q;
    scanf("%d",&q);
    while(q--)
    {
      lint d;
      scanf("%I64d",&d);
      lint ans=0;
	  if (flag)
        d--;
      if (d==0)
      {
        printf("0\n");
        continue;
	  }
	  if(d>(1LL<<r))
	  {
	    printf("-1\n");
	    continue;
	  }
	  k=0;
	  while(d)
	  {
	    if (d&1)
	      ans^=a[r-k];
	    d>>=1;
	    k++;
	  }
	  printf("%I64d\n",ans);
	}
  }
  return 0;
}
