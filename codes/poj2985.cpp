#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MN 200005
#define LL long long
using namespace std;

int c[MN],fa[MN],a[MN];
int n;
int loopst;

int low(int x){return x&(-x);}

void add(int x,int d)
{
  int i=x;
  while(i<=n)
  {
    c[i]+=d;
    i+=low(i);
  }
}

int find(int x)
{
  if (fa[x]==x) return x;
  fa[x]=find(fa[x]);
  return fa[x];
}

int kth(int k)
{
  int st=0,t,loop=loopst;
  //while((loop<<1)<=n)loop=loop<<1;
  while(loop>0)
  {
    t=st+loop;
    if (t<=n&&k>c[t])
    {
      st=t;
      k-=c[t];
    }
    loop=loop>>1;
  }
  return st+1;
}

int main()
{
  freopen("2985.in","r",stdin);
  freopen("2985.out","w",stdout);
  int m,i,j,k;
  memset(c,0,sizeof(c));
  scanf("%d%d",&n,&m);
  for (i=0;i<=n;i++)
    fa[i]=i;
  add(1,n);
  for (i=1;i<=n;i++)
    a[i]=1;
  int num=n;
  loopst=1;
  while((loopst<<1)<=n)loopst=loopst<<1;
  for (i=1;i<=m;i++)
  {
    scanf("%d",&k);
    if (k==0)
    {
      int x,y;
      scanf("%d%d",&x,&y);
      x=find(x);
      y=find(y);
      if (x==y) continue;
      add(a[x],-1);
      add(a[y],-1);
      add(a[x]+a[y],1);
      fa[y]=x;
      a[x]+=a[y];
      a[y]=0;
      num--;
    }
    else
    {
      int d;
      scanf("%d",&d);
      d=num-d+1;
      printf("%d\n",kth(d));
    }
  }
  return 0;
}
