#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cctype>
#include<ctime>
#include<queue>
#include<string>
#include<vector>
#include<map>
#define eps 1e-8
#define INF (int)1e9
#define lint long long
#define llu unsigned long long
#define MN 20002
using namespace std;

//int sm[MN*30];
int sum[MN*30],lc[MN*30],rc[MN*30],lm[MN*30],rm[MN*30];
struct node{
	int x,id;
};
int a[MN];
node b[MN];
int q[10];
int root[MN];
int tot=0,n;

bool cmp(node a,node b){return a.x<b.x;}

void pushup(int p,int l,int r)
{
  lm[p]=max(lm[lc[p]],sum[lc[p]]+lm[rc[p]]);
  rm[p]=max(rm[rc[p]],sum[rc[p]]+rm[lc[p]]);
  //sm[p]=max(max(sm[lc[p]],sm[rc[p]]),rm[lc[p]]+lm[rc[p]]);
  sum[p]=sum[lc[p]]+sum[rc[p]];
}

void build(int &k,int l,int r)
{
  k=++tot;
  if (l==r)
  {
    //sm[k]=1;
	lm[k]=rm[k]=sum[k]=1;
    return ;
  }
  int mid=(l+r)>>1;
  build(lc[k],l,mid);
  build(rc[k],mid+1,r);
  pushup(k,l,r);
}

void modify(int &k,int o,int l,int r,int p)
{
  k=++tot;
  //sm[k]=sm[o];
  sum[k]=sum[o];lm[k]=lm[o];rm[k]=rm[o];lc[k]=lc[o];rc[k]=rc[o];
  if (l==r)
  {
    //sm[k]=-1;
	sum[k]=lm[k]=rm[k]=-1;
    return ;
  }
  int mid=(l+r)>>1;
  if (p<=mid)
    modify(lc[k],lc[o],l,mid,p);
  else
    modify(rc[k],rc[o],mid+1,r,p);
  pushup(k,l,r);
}

int query_sum(int k,int l,int r,int ql,int qr)
{
  if (ql<=l&&qr>=r)
    return sum[k];
  int mid=(l+r)>>1;
  int ans=0;
  if (ql<=mid)
    ans+=query_sum(lc[k],l,mid,ql,qr);
  if (qr>mid)
    ans+=query_sum(rc[k],mid+1,r,ql,qr);
  return ans;
}

int query_lmax(int k,int l,int r,int ql,int qr)
{
  if (ql<=l&&qr>=r)
    return lm[k];
  int mid=(l+r)>>1;
  if (qr<=mid)
    return query_lmax(lc[k],l,mid,ql,qr);
  else if (ql>mid)
    return query_lmax(rc[k],mid+1,r,ql,qr);
  else
    return max(query_lmax(lc[k],l,mid,ql,qr),query_sum(lc[k],l,mid,ql,qr)+query_lmax(rc[k],mid+1,r,ql,qr));
}

int query_rmax(int k,int l,int r,int ql,int qr)
{
  if (ql<=l&&qr>=r)
    return rm[k];
  int mid=(l+r)>>1;
  if (qr<=mid)
    return query_rmax(lc[k],l,mid,ql,qr);
  else if (ql>mid)
    return query_rmax(rc[k],mid+1,r,ql,qr);
  else 
    return max(query_rmax(rc[k],mid+1,r,ql,qr),query_sum(rc[k],mid+1,r,ql,qr)+query_rmax(lc[k],l,mid,ql,qr));
}

int main()
{
  freopen("2653.in","r",stdin);
  freopen("2653.out","w",stdout);
  int ca,i,j,k,m,ii=0;
  int lastans=0;
  scanf("%d",&n);
  for (i=1;i<=n;i++)
  {
    scanf("%d",&a[i]);
    b[i].x=a[i];
    b[i].id=i;
  }
  sort(b+1,b+n+1,cmp);
  build(root[0],1,n);
  for (i=1;i<=n;i++)
    modify(root[i],root[i-1],1,n,b[i].id);
  int qus;
  scanf("%d",&qus);
  for (ii=1;ii<=qus;ii++)
  {
    for (i=1;i<=4;i++)
    {
      scanf("%d",&q[i]);
      q[i]=(q[i]+lastans)%n+1;
    }
    sort(q+1,q+4+1);
    int l=1,r=n;
    while(l<r)
    {
      int mid=(l+r+1)>>1;
      int res=query_rmax(root[mid-1],1,n,q[1],q[2])+query_lmax(root[mid-1],1,n,q[3],q[4]);
      if (q[2]+1<q[3])
        res+=query_sum(root[mid-1],1,n,q[2]+1,q[3]-1);
	  if (res>=0)
        l=mid;
      else
        r=mid-1;
	}
	lastans=b[l].x;
	printf("%d\n",lastans);
  }
  return 0;
}

