#include<cstdio>
#include<iostream>
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
#define MN (int)4e6+4
#define llu unsigned long long
using namespace std;

int add[MN],ls[MN],rs[MN];
lint sum[MN];
int root[MN];
int tot;
char op[5];

void copyall(int k,int o)
{
  sum[k]=sum[o];
  add[k]=add[o];
  ls[k]=ls[o];
  rs[k]=rs[o];
}

void pushup(int p,int l,int r)
{
  sum[p]=sum[ls[p]]+sum[rs[p]]+(r-l+1)*add[p];
}

void build(int &k,int l,int r)
{
  k=++tot;
  add[k]=0;
  if (l==r)
  {
    cin>>sum[k];
    ls[k]=rs[k]=0;
    return ;
  }
  int mid=(l+r)>>1;
  build(ls[k],l,mid);
  build(rs[k],mid+1,r);
  pushup(k,l,r);
}

void update(int &k,int o,int l,int r,int ql,int qr,int d)
{
  k=++tot;
  copyall(k,o);
  //sum[k]+=(lint)(min(qr,r)-max(ql,l)+1)*(lint)d;
  if (ql<=l&&qr>=r)
  {
    add[k]+=d;
    sum[k]+=(lint)(r-l+1)*d;
    return ;
  }
  int mid=(l+r)>>1;
  if (ql<=mid)
    update(ls[k],ls[o],l,mid,ql,qr,d);
  if (qr>mid)
    update(rs[k],rs[o],mid+1,r,ql,qr,d);
  pushup(k,l,r);
}

lint query(int k,int l,int r,int ql,int qr)
{
  if (ql<=l&&qr>=r)
    return sum[k];
  int mid=(l+r)>>1;
  lint ans=(lint)(min(qr,r)-max(ql,l)+1)*(lint)add[k];
  if (ql<=mid)
    ans+=query(ls[k],l,mid,ql,qr);
  if (qr>mid)
    ans+=query(rs[k],mid+1,r,ql,qr);
  return ans;
}

int main()
{
  freopen("4348.in","r",stdin);
  freopen("4348.out","w",stdout);
  int ca,n,i,j,k,m,ii=0;
  while(scanf("%d%d",&n,&m)==2)
  {
    tot=0;
    int time=0;
    build(root[0],1,n);
    while(m--)
    {
      scanf("%s",op);
      if (op[0]=='Q')
      {
        int l,r;
        scanf("%d%d",&l,&r);
        cout<<query(root[time],1,n,l,r)<<endl;//printf("%lld\n",query(root[time],1,n,l,r));
	  }
	  else if (op[0]=='H')
	  {
	    int l,r,t;
	    scanf("%d%d%d",&l,&r,&t);
	    cout<<query(root[t],1,n,l,r)<<endl;//printf("%lld\n",query(root[t],1,n,l,r));
	  }
	  else if (op[0]=='B')
	    scanf("%d",&time);
	  else
	  {
	    int l,r,d;
	    scanf("%d%d%d",&l,&r,&d);
	    update(root[time+1],root[time],1,n,l,r,d);
	    time++;
	  }
	}
	//puts("");
  }
  return 0;
}

