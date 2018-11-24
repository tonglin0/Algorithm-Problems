#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define MN 800009
using namespace std;

int ms[MN];
char st[10];
int ql,qr;

void pushup(int p,int l,int r)
{
  ms[p]=max(ms[p<<1],ms[p<<1|1]);
}

void build(int p,int l,int r)
{
  if (l==r)
  {
    ms[p]=0;
    return;
  }
  int mid=(l+r)>>1;
  build(p<<1,l,mid);
  build(p<<1|1,mid+1,r);
  pushup(p,l,r);
}

void update(int p,int l,int r,int q,int k)
{
  if (l==r)
  {
    ms[p]=k;
    return ;
  }
  int mid=(l+r)>>1;
  if (q<=mid)
    update(p<<1,l,mid,q,k);
  else
    update(p<<1|1,mid+1,r,q,k);
  pushup(p,l,r);
}

int query(int p,int l,int r)
{
  if (ql<=l&&qr>=r)
    return ms[p];
  int mid=(l+r)>>1;
  int ans=-1;
  if (ql<=mid)
   ans=max(ans,query(p<<1,l,mid));
  if (qr>mid)
    ans=max(ans,query(p<<1|1,mid+1,r));
  return ans;
}

int main()
{
  freopen("1012.in","r",stdin);
  freopen("1012.out","w",stdout);
  int MOD,n=0,i,j,k,m,pre=0;
  scanf("%d%d",&m,&MOD);
  build(1,1,m);
  int tm=m;
  while(tm--)
  {
    scanf("%s",st);
    if (st[0]=='A')
    {
      int d;
      scanf("%d",&d);
      d=(d+pre)%MOD;
      ++n;
      update(1,1,m,n,d);
	}
	else
	{
	  int l;
	  scanf("%d",&l);
	  qr=n;
	  ql=n-l+1;
	  int ans=query(1,1,m);
	  printf("%d\n",ans);
	  pre=ans;
	}
  }
  return 0;
}
