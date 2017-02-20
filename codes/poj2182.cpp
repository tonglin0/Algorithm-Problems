#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define  MN 8005
using namespace std;

int b[MN],c[MN],a[MN];
int n;

int low(int x){return x&(-x);}

void add(int x,int d)
{
  int i=x;
  while(i<=n)
  {
    c[i]+=d;
    i+=low(i);
  }
}

int find(int x)
{
  int ans=0;
  int i=x;
  while(i>0)
  {
    ans+=c[i];
    i-=low(i);
  }
  return ans;
}

int findvalue(int v)
{
  int l=1,r=n;
  while(l<r)
  {
    int mid=(l+r)>>1;
    if (find(mid)>=v)
      r=mid;
    else
      l=mid+1;
  }
  return l;
}

int main()
{
  freopen("2182.in","r",stdin);
  freopen("2182.out","w",stdout);
  int m,i,j,k;
  scanf("%d",&n);
  memset(c,0,sizeof(c));
  memset(a,0,sizeof(a));
  for (i=1;i<=n;i++)
    c[i]=low(i);
  for (i=2;i<=n;i++)
    scanf("%d",&a[i]);
  memset(b,0,sizeof(b));
  for (i=n;i>=1;i--)
  {
    int t=findvalue(a[i]+1);
    b[i]=t;
    add(t,-1);
  }
  for (i=1;i<=n;i++)
    printf("%d\n",b[i]);
  return 0;
}
