#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<cstring>
#define MN 201200
using namespace std;

int ms[MN],ls[MN],rs[MN];
int st[MN],en[MN];
int ql,qr;
char ch[20];
int set[MN];
int sz[MN];
int cl[MN],cr[MN];

void pushup(int p,int l,int r)
{
  int lc=p<<1,rc=p<<1|1;
  int mid=(l+r)>>1;
  ms[p]=max(ms[lc],ms[rc]);
  ms[p]=max(ms[p],rs[lc]+ls[rc]);
  ls[p]=ls[lc];
  if (ls[lc]==mid-l+1)
    ls[p]+=ls[rc];
  rs[p]=rs[rc];
  if (rs[rc]==r-mid)
    rs[p]+=rs[lc];
  cl[p]=cl[lc];
  cr[p]=cr[rc];
  sz[p]=sz[lc]+sz[rc];
  if (sz[p]>0&&cr[lc]==cl[rc]&&cr[lc]!=0)
    sz[p]--;
}

void build(int p,int l,int r)
{
  if (l==r)
  {
    set[p]=-1;
    sz[p]=0;
    cr[p]=cl[p]=0;
    ms[p]=ls[p]=rs[p]=1;
    return ;
  }
  int mid=(l+r)>>1;
  build(p<<1,l,mid);
  build(p<<1|1,mid+1,r);
  pushup(p,l,r);
  set[p]=-1;
}

void pushdown(int p,int l,int r)
{
  if (set[p]>=0)
  {
    int lc=p<<1,rc=p<<1|1;
    set[lc]=set[rc]=set[p];
    int mid=(l+r)>>1;
    if (set[p]==0)
    {
      ls[lc]=rs[lc]=ms[lc]=mid-l+1;
      ls[rc]=rs[rc]=ms[rc]=r-mid;
      sz[lc]=sz[rc]=0;
      cl[lc]=cl[rc]=cr[lc]=cr[rc]=0;
    }
    else
    {
      ls[lc]=rs[lc]=ms[lc]=0;
      ls[rc]=rs[rc]=ms[rc]=0;
      sz[lc]=sz[rc]=1;
      cl[lc]=cl[rc]=cr[lc]=cr[rc]=set[p];
    }
    set[p]=-1;
  }
}

void update(int p,int l,int r,int k)
{
  if (ql<=l&&qr>=r)
  {
    set[p]=k;
    if (k!=0)
      sz[p]=1;
    else
      sz[p]=0;
    cl[p]=cr[p]=k;
    if (k!=0)
      ms[p]=ls[p]=rs[p]=0;
    else
      ms[p]=ls[p]=rs[p]=r-l+1;
    return ;
  }
  int mid=(l+r)>>1;
  pushdown(p,l,r);
  if (ql<=mid)
    update(p<<1,l,mid,k);
  if (qr>mid)
    update(p<<1|1,mid+1,r,k);
  pushup(p,l,r);
}

int query(int p,int l,int r,int k)
{
  if (ms[p]<k)
    return -1;
  if (l==r) return l;
  int mid=(l+r)>>1;
  pushdown(p,l,r);
  int ans;
  if (ms[p<<1]>=k)
    ans=query(p<<1,l,mid,k);
  else if (rs[p<<1]+ls[p<<1|1]>=k)
    ans=mid-rs[p<<1]+1;
  else ans=query(p<<1|1,mid+1,r,k);
  pushup(p,l,r);
  return ans;
}

int find(int p,int l,int r)
{
  if (l==r)
    return set[p];
  int mid=(l+r)>>1;
  pushdown(p,l,r);
  int ans;
  if (ql<=mid)
    ans=find(p<<1,l,mid);
  else
    ans=find(p<<1|1,mid+1,r);
  pushup(p,l,r);
  return ans;
}

int get(int p,int l,int r,int k)
{
  if (l==r)
    return l;
  int mid=(l+r)>>1;
  pushdown(p,l,r);
  int ans;
  if (sz[p<<1]>=k)
    ans=get(p<<1,l,mid,k);
  else
  {
    k-=sz[p<<1];
    if (cr[p<<1]==cl[p<<1|1]&&cr[p<<1]!=0)
      k++;
    ans=get(p<<1|1,mid+1,r,k);
  }
  pushup(p,l,r);
  return ans;
}

int main()
{
  freopen("2871.in","r",stdin);
  freopen("2871.out","w",stdout);
  int n,i,j,k,m;
  bool first=true;
  while(scanf("%d%d",&n,&m)==2)
  {
    int sum=0;
    int tot=0;
    memset(st,0,sizeof(st));
    memset(en,0,sizeof(en));
    build(1,1,n);
    set[1]=0;
    for (i=1;i<=m;i++)
    {
      scanf("%s",ch);
      if (ch[0]=='R')
      {
        ql=1;qr=n;
        update(1,1,n,0);
        tot=0;
        printf("Reset Now\n");
      }
      else if (ch[0]=='N')
      {
        scanf("%d",&k);
        int tmp=query(1,1,n,k);
        if (tmp==-1)
          printf("Reject New\n");
        else
        {
          tot++;
          printf("New at %d\n",tmp);
          sum++;
          st[sum]=tmp;
          en[sum]=tmp+k-1;
          ql=st[sum];qr=en[sum];
          update(1,1,n,sum);
        }
      }
      else if (ch[0]=='F')
      {
        scanf("%d",&ql);
        int tmp=find(1,1,n);
        if (tmp==0)
          printf("Reject Free\n");
        else
        {
          tot--;
          ql=st[tmp];qr=en[tmp];
          update(1,1,n,0);
          printf("Free from %d to %d\n",st[tmp],en[tmp]);
        }
      }
      else
      {
        scanf("%d",&k);
        if (k<=0||k>tot)
          printf("Reject Get\n");
        else
          printf("Get at %d\n",get(1,1,n,k));
      }
    }
    printf("\n");
  }
  return 0;
}
