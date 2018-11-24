#include<cstdio>
#include<cstring>
#include<vector>
#include<cstdlib>
#include<algorithm>
#define MN (65535<<3)+10000
using namespace std;

bool b[MN];
char ch[100],ch2[100];
int x[MN];
int co[MN];
int sl,sr,ql,qr;

void build(int p,int l,int r)
{
  if (l==r)
  {
    co[p]=0;
    x[p]=0;
    return ;
  }
  int mid=(l+r)>>1;
  build(p<<1,l,mid);
  build(p<<1|1,mid+1,r);
  co[p]=0;
  x[p]=0;
}

void pushdown(int p,int l,int r)
{
  int lc=p<<1,rc=p<<1|1;
  if (co[p]!=-1) 
  {
    co[lc]=co[rc]=co[p];
    x[lc]=x[rc]=0;
    x[p]=0;
    return ;
  }
  x[lc]=x[lc]^x[p];
  x[rc]=x[rc]^x[p];
  if (x[lc]&&co[lc]>=0)
  {
    co[lc]=!co[lc];
    x[lc]=0;
  }
  if (x[rc]&&co[rc]>=0)
  {
    co[rc]=!co[rc];
    x[rc]=0;
  }
  x[p]=0;
}

void update(int p,int l,int r,int sl,int sr,int k)
{
  if (sr<sl) return ;
  if (sl<=l&&sr>=r)
  {
    co[p]=k;
    x[p]=0;
    return ;
  }
  pushdown(p,l,r);
  int mid=(l+r)>>1;
  if (sl<=mid)
    update(p<<1,l,mid,sl,sr,k);
  if (sr>mid)
    update(p<<1|1,mid+1,r,sl,sr,k);
  if (co[p<<1]!=-1&&co[p<<1]==co[p<<1|1])
    co[p]=co[p<<1];
  else
    co[p]=-1;
}

void xorupdate(int p,int l,int r,int sl,int sr)
{
  if (sl>sr) return ;
  if (sl<=l&&sr>=r)
  {
    if (co[p]>=0)
     co[p]=!co[p];
    else
      x[p]=!x[p];
    return ;
  }
  int mid=(l+r)>>1;
  pushdown(p,l,r);
  if (sl<=mid)
    xorupdate(p<<1,l,mid,sl,sr);
  if (sr>mid)
    xorupdate(p<<1|1,mid+1,r,sl,sr);
  if (co[p<<1]!=-1&&co[p<<1]==co[p<<1|1])
    co[p]=co[p<<1];
  else
    co[p]=-1;
}

void query(int p,int l,int r)
{
  if (l>r) return ;
  if (l==r)
  {
    if (co[p]==1)
      b[l]=true;
    return ;
  }
  if (co[p]==0) return ;
  pushdown(p,l,r);
  int mid=(l+r)>>1;
  query(p<<1,l,mid);
  query(p<<1|1,mid+1,r);
}

int main()
{
  freopen("3225.in","r",stdin);
  freopen("3225.out","w",stdout);
  int n,i,j,k,m;
  n=(65535<<1)+1;
  build(1,0,n);
  while(scanf("%s%s",ch,ch2)==2)
  {
    char zk,yk;
    sscanf(ch2,"%c%d,%d%c",&zk,&sl,&sr,&yk);
    if (zk=='(') sl=sl<<1|1;else sl<<=1;
    if (yk==')') sr=(sr<<1)-1;else sr<<=1;
    if (ch[0]=='U')
      update(1,0,n,sl,sr,1);
    else if (ch[0]=='I')
    {
      update(1,0,n,0,sl-1,0);
      update(1,0,n,sr+1,n,0);
    }
    else if (ch[0]=='D')
      update(1,0,n,sl,sr,0);
    else if (ch[0]=='S')
      xorupdate(1,0,n,sl,sr);
    else 
    {
      update(1,0,n,0,sl-1,0);
      update(1,0,n,sr+1,n,0);
      xorupdate(1,0,n,sl,sr);
    }
  }
  memset(b,0,sizeof(b));
  query(1,0,n);
  int l,r;
  i=0;
  bool find=false;
  while(i<MN)
  {
    if (b[i])
    {
      l=i;
      if (find)
        printf(" ");
      find=true;
      while(i<MN&&b[i+1])
        i++;
      r=i;
      if ((l&1)==0)
      {
        l>>=1;
        printf("[%d,",l);
      }
      else 
      {
        l=l>>1;
        printf("(%d,",l);
      }
      if ((r&1)==0)
      {
        r>>=1;
        printf("%d]",r);
      }
      else
      {
        r=(r>>1)+1;
        printf("%d)",r);
      }
    }
    i++;
  }
  if (!find)
    printf("empty set");
  return 0;
}
