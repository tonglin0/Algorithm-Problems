#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define MN 200050
using namespace std;

char ch[3];
int s[MN],ls[MN],rs[MN];
int q[MN];
int ql;

void pushup(int p,int l,int r)
{
  int lc=p<<1,rc=p<<1|1;
  s[p]=s[lc]+s[rc];
  //s[p]=max(s[p],rs[lc]+ls[rc]);
  ls[p]=ls[lc];
  int mid=(l+r)>>1;
  if (ls[lc]==mid-l+1)
    ls[p]+=ls[rc];
  rs[p]=rs[rc];
  if (rs[rc]==r-mid)
    rs[p]+=rs[lc];
}

void build(int p,int l,int r)
{
  if (l==r)
  {
    s[p]=ls[p]=rs[p]=1;
    return ;
  }
  int mid=(l+r)>>1;
  build(p<<1,l,mid);
  build(p<<1|1,mid+1,r);
  pushup(p,l,r);
}

void update(int p,int l,int r,int k)
{
  if (l==r)
  {
    s[p]=ls[p]=rs[p]=k;
    return ;
  }
  int mid=(l+r)>>1;
  if (ql<=mid)
    update(p<<1,l,mid,k);
  else
    update(p<<1|1,mid+1,r,k);
  pushup(p,l,r);
}

int query(int p,int l,int r)
{
  if (l==r||s[p]==0||s[p]==r-l+1)
    return s[p];
  int mid=(l+r)>>1;
  if (ql<=mid&&ql>=mid-rs[p<<1]+1)
    return query(p<<1,l,mid)+ls[p<<1|1];
  else if (ql<=mid)
    return query(p<<1,l,mid);
  else if (ql>mid&&ql<=mid+ls[p<<1|1])
    return query(p<<1|1,mid+1,r)+rs[p<<1];
  else return query(p<<1|1,mid+1,r);
}

int main()
{
  freopen("1540.in","r",stdin);
  freopen("1540.out","w",stdout);
  int n,i,t=0,j,k,m;
  while(scanf("%d%d",&n,&m)==2){
  build(1,1,n);
  while(m--)
  {
    scanf("%s",ch);
    if (ch[0]=='D')
    {
      scanf("%d",&ql);
      q[++t]=ql;
      update(1,1,n,0);
    }
    else if (ch[0]=='R')
    {
      ql=q[t--];
      update(1,1,n,1);
    }
    else
    {
      scanf("%d",&ql);
      printf("%d\n",query(1,1,n));
    }
  }}
  return 0;
}
