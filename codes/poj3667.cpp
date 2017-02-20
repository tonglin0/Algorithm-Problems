#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define MN 200009
using namespace std;

int s[MN],rs[MN],ls[MN];
int set[MN];
int max3(int a,int b,int c){return max(a,max(b,c));}

void build(int p,int l,int r)
{
  s[p]=rs[p]=ls[p]=r-l+1;
  set[p]=-1;
  if (l==r) return ;
  int mid=(l+r)>>1;
  build(p<<1,l,mid);
  build(p<<1|1,mid+1,r);
}

void pushdown(int p,int l,int r)
{
  int lc=p<<1,rc=p<<1|1;
  if (set[p]==0)
  {
    ls[lc]=ls[rc]=rs[lc]=rs[rc]=s[lc]=s[rc]=0;
    set[lc]=set[rc]=0;
  }
  else
  {
    int mid=(l+r)>>1;
    set[lc]=set[rc]=1;
    ls[lc]=rs[lc]=s[lc]=mid-l+1;
    ls[rc]=rs[rc]=s[rc]=r-mid;
  }
  set[p]=-1;
}

void update(int p,int l,int r,int sl,int sr,int k)
{
  if (sl<=l&&sr>=r)
  {
    set[p]=k;
    if (k==0)
      s[p]=ls[p]=rs[p]=0;
    else
      s[p]=ls[p]=rs[p]=r-l+1;
    return ;
  }
  int mid=(l+r)>>1;
  if (set[p]>=0)
    pushdown(p,l,r);
  if (sl<=mid)
    update(p<<1,l,mid,sl,sr,k);
  if (sr>mid)
    update(p<<1|1,mid+1,r,sl,sr,k);
  s[p]=max3(s[p<<1],s[p<<1|1],rs[p<<1]+ls[p<<1|1]);
  ls[p]=ls[p<<1];
  if (ls[p<<1]==mid-l+1)
    ls[p]+=ls[p<<1|1];
  rs[p]=rs[p<<1|1];
  if (rs[p<<1|1]==r-mid)
    rs[p]+=rs[p<<1];
  //s[p]=max3(s[p],ls[p],rs[p]);
}

int query(int p,int l,int r,int k)
{
  if (s[p]<k) return 0;
  if (l==r) return l;
  if (set[p]>=0)
    pushdown(p,l,r);
  int mid=(l+r)>>1;
  if (s[p<<1]>=k)
    return query(p<<1,l,mid,k);
  if (rs[p<<1]+ls[p<<1|1]>=k)
    return mid-rs[p<<1]+1;
  return query(p<<1|1,mid+1,r,k);
}

int main()
{
  freopen("3667.in","r",stdin);
  freopen("3667.out","w",stdout);
  int n,i,j,k,m,a,b;
  scanf("%d%d",&n,&m);
  build(1,1,n);
  while(m--)
  {
    scanf("%d",&k);
    if (k==1)
    {
      scanf("%d",&a);
      b=query(1,1,n,a);
      printf("%d\n",b);
      if (b!=0)
        update(1,1,n,b,b+a-1,0);
    }
    else
    {
      scanf("%d%d",&a,&b);
      update(1,1,n,a,a+b-1,1);
    }
  }
  return 0;
}
