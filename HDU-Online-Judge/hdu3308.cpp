#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define MN 400009
using namespace std;

int a[MN],s[MN],ls[MN],rs[MN];
int ql,qr;
char ch[4];

void build(int p,int l,int r)
{
  if (l==r)
  {
    s[p]=ls[p]=rs[p]=1;
    scanf("%d",&a[l]);
    return ;
  }
  int mid=(l+r)>>1;
  build(p<<1,l,mid);
  build(p<<1|1,mid+1,r);
  s[p]=max(s[p<<1],s[p<<1|1]);
  if (a[mid+1]>a[mid])
    s[p]=max(s[p],ls[p<<1|1]+rs[p<<1]);
  ls[p]=ls[p<<1];
  if (ls[p<<1]==mid-l+1&&a[mid+1]>a[mid])
    ls[p]+=ls[p<<1|1];
  rs[p]=rs[p<<1|1];
  if (rs[p<<1|1]==r-mid&&a[mid+1]>a[mid])
    rs[p]+=rs[p<<1];
}

void update(int p,int l,int r,int ql)
{
  if (l==r) return ;
  int mid=(l+r)>>1;
  if (ql<=mid)
    update(p<<1,l,mid,ql);
  else
    update(p<<1|1,mid+1,r,ql);
  s[p]=max(s[p<<1],s[p<<1|1]);
  if (a[mid+1]>a[mid])
    s[p]=max(s[p],ls[p<<1|1]+rs[p<<1]);
  ls[p]=ls[p<<1];
  if (ls[p<<1]==mid-l+1&&a[mid+1]>a[mid])
    ls[p]+=ls[p<<1|1];
  rs[p]=rs[p<<1|1];
  if (rs[p<<1|1]==r-mid&&a[mid+1]>a[mid])
    rs[p]+=rs[p<<1];
}

int query(int p,int l,int r)
{
  if (ql<=l&&qr>=r)
    return s[p];
  //if (l==r) return 1;
  int mid=(l+r)>>1;
  int s1,s2;
  if (ql<=mid)
    s1=query(p<<1,l,mid);
  if (qr>mid)
    s2=query(p<<1|1,mid+1,r);
  if (qr<=mid)
    return s1;
  if (ql>mid)
    return s2;
  int ans=max(s1,s2);
  //if (s1<=rs[p<<1]&&s2<=ls[p<<1|1]&&a[mid+1]>a[mid])
  //  ans=max(ans,s1+s2);//return s1+s2;
  if (a[mid+1]>a[mid])
    ans=max(ans,min(rs[p<<1],mid-ql+1)+min(ls[p<<1|1],qr-mid));
  return ans;
}
int main()
{
  freopen("3308.in","r",stdin);
  freopen("3308.out","w",stdout);
  int n,i,j,k,m,T;
  scanf("%d",&T);
  while(T--)
  {
    scanf("%d%d",&n,&m);
    build(1,0,n-1);
    for (i=1;i<=m;i++)
    {
      scanf("%s%d%d",ch,&ql,&qr);
      if (ch[0]=='U')
      {
        a[ql]=qr;
        update(1,0,n-1,ql);
      }
      else
        printf("%d\n",query(1,0,n-1));
    }
  }
  return 0;
}
