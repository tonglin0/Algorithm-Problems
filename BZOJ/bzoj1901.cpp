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
#define MN 200001
using namespace std;

int ls[MN*20],rs[MN*20],sum[MN*20];
int a[MN],b[MN];
char op[MN][2];
int P[MN],Q[MN],K[MN];
int root[MN*20];
int tot;
int sz;
int n;
int L[MN],R[MN];
int N,M;

void build(int &k,int l,int r)
{
  k=++tot;
  sum[k]=0;
  if (l==r)
    return ;
  int mid=(l+r)>>1;
  build(ls[k],l,mid);
  build(rs[k],mid+1,r);
}

void update(int &k,int l,int r,int o,int p,int d)
{
  k=++tot;
  ls[k]=ls[o];rs[k]=rs[o];sum[k]=sum[o]+d;
  if (l==r)
    return ;
  int mid=(l+r)>>1;
  if (p<=mid)
    update(ls[k],l,mid,ls[k],p,d);
  else
    update(rs[k],mid+1,r,rs[k],p,d);
}

void bit_update(int x,int p,int d)
{
  for (;x<=n;x+=(x&(-x)))
    update(root[x],1,sz,root[x],p,d);
}

int query(int l,int r,int k)
{
  if (l==r)
    return l;
  int suma=0,sumb=0;
  for (int i=1;i<=N;i++)
    suma+=sum[ls[L[i]]];
  for (int i=1;i<=M;i++)
    sumb+=sum[ls[R[i]]];
  int res=sumb-suma;
  int mid=(l+r)>>1;
  if (k<=res)
  {
    for (int i=1;i<=N;i++)
      L[i]=ls[L[i]];
    for (int i=1;i<=M;i++)
      R[i]=ls[R[i]];
	return query(l,mid,k);
  }
  else
  {
    for (int i=1;i<=N;i++)
      L[i]=rs[L[i]];
    for (int i=1;i<=M;i++)
      R[i]=rs[R[i]];
    return query(mid+1,r,k-res);
  }
}

int bit_query(int ql,int qr,int k)
{
  N=M=0;
  for (;ql>0;ql-=ql&-ql)
    L[++N]=root[ql];
  for (;qr>0;qr-=qr&-qr)
    R[++M]=root[qr];
  return query(1,sz,k);
}

int main()
{
  freopen("2112.in","r",stdin);
  freopen("2112.out","w",stdout);
  int ca,i,j,k,m,ii=0;
  //scanf("%d",&ca);
  ca=1;
  while(ca--)
  {
  	tot=0;
  	memset(sum,0,sizeof(sum));
    scanf("%d%d",&n,&m);
    for (i=1;i<=n;i++)
    {
      scanf("%d",&a[i]);
      b[i]=a[i];
	}
	int tmpn=n;
	for (i=1;i<=m;i++)
	{
	  scanf("%s%d%d",op[i],&P[i],&Q[i]);
	  if (op[i][0]=='Q')
	    scanf("%d",&K[i]);
	  else
	    b[++tmpn]=Q[i];
	}
	sort(b+1,b+tmpn+1);
	sz=unique(b+1,b+tmpn+1)-b-1;
	build(root[0],1,sz);
	for (i=1;i<=n;i++)
	{
	  int num=lower_bound(b+1,b+sz+1,a[i])-b;
	  bit_update(i,num,1);
	}
	for (i=1;i<=m;i++)
	{
	  if (op[i][0]=='C')
	  {
	    int num=lower_bound(b+1,b+sz+1,a[P[i]])-b;
	    bit_update(P[i],num,-1);
	    a[P[i]]=Q[i];
	    num=lower_bound(b+1,b+sz+1,Q[i])-b;
	    bit_update(P[i],num,1);
	  }
	  else
	  {
	    printf("%d\n",b[bit_query(P[i]-1,Q[i],K[i])]);
	  }
	}
  }
  return 0;
}

