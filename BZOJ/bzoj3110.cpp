#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<vector>
#include<queue>
#include<string>
#include<map>
#include<cctype>
#include<algorithm>
#define INF (int)1e9
#define lint long long
#define llu unsigned long long
#define eps 1e-8
#define MN 5005000
using namespace std;

int sum[MN],add[MN],ls[MN],rs[MN];
int tot=0;
int root[50000*23];
int L,R;
int n;

int ID(int l,int r){return (l+r|l!=r);}

void pushup(int p,int l,int r)
{
  sum[p]=sum[ls[p]]+sum[rs[p]]+(r-l+1)*add[p];
}

void read(int &x)
{
  char ch;
  while(ch=getchar(),ch<'0'||ch>'9');
  x=ch-'0';
  while(ch=getchar(),ch>='0'&&ch<='9') x=x*10+ch-'0';
}

void update(int &k,int l,int r)
{
  if (!k)
    k=++tot;
  if (L<=l&&R>=r)
  {
    sum[k]+=r-l+1;
    add[k]++;
    return ;
  }
  int mid=(l+r)>>1;
  if (L<=mid)
    update(ls[k],l,mid);
  if (R>mid)
    update(rs[k],mid+1,r);
  sum[k]+=min(R,r)-max(L,l)+1;
  //pushup(k,l,r);
}

void insert(int a,int b,int c)
{
  L=a;R=b;
  int l=1,r=n;
  while(update(root[ID(l,r)],1,n),l<r)
  {
    int mid=(l+r)>>1;
    if (c<=mid)
      r=mid;
    else
      l=mid+1;
  }
}

int ask(int k,int l,int r)
{
  if (k==0)
    return 0;
  if (L<=l&&R>=r)
    return sum[k];
  int ans=0;
  int mid=l+r>>1;
  if (L<=mid)
    ans+=ask(ls[k],l,mid);
  if (R>mid)
    ans+=ask(rs[k],mid+1,r);
  return ans+add[k]*(min(R,r)-max(L,l)+1);
}


int query(int a,int b,int c)
{
  L=a;R=b;
  int l=1,r=n;
  while(l<r)
  {
    int mid=l+r>>1;
    int tmp;
    if ((tmp=ask(root[ID(mid+1,r)],1,n))>=c)
      l=mid+1;
    else
      r=mid,c-=tmp;
  }
  return l;
}

int main()
{
  freopen("3110.in","r",stdin);
  freopen("3110.out","w",stdout);
  int i,j,k,m,ii=0,ca;
  read(n);read(m);
  while(m--)
  {
    int a,b,c,op;
    read(op);read(a);read(b);read(c);
    if (op==1)
      insert(a,b,c);
    else
      printf("%d\n",query(a,b,c));
  }
  return 0;
}

