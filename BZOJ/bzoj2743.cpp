#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define MN 1000005
using namespace std;

int pre[MN],last[MN],a[MN];
struct node{int id,a,b;bool operator < (node x)const{return b<x.b;}};
node q[MN];
int c[MN],ans[MN];
int n;

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
  int ans=0,i=x;
  while(i>0)
  {
    ans+=c[i];
    i-=low(i);
  }
  return ans;
}

int main()
{
  freopen("2743.in","r",stdin);
  freopen("2743.out","w",stdout);
  int m,i,j,k;
  memset(c,0,sizeof(c));
  memset(q,0,sizeof(q));
  memset(pre,0,sizeof(pre));
  memset(last,0,sizeof(last));
  scanf("%d%d%d",&n,&k,&m);
  for (i=2;i<=n+1;i++)
  {
    scanf("%d",&a[i]);
    if (last[a[i]]==0)
    {
      pre[i]=1;
      last[a[i]]=i;
    }
    else
    {
      pre[i]=last[a[i]];
      last[a[i]]=i;
    }
  }
  pre[1]=1;
  for (i=1;i<=m;i++)
  {
    scanf("%d%d",&q[i].a,&q[i].b);
    q[i].a++;q[i].b++;
    q[i].id=i;
  }
  int t=1;
  sort(q+1,q+m+1);
  for (i=2;i<=n+1;i++)
  {
    add(pre[pre[i]]+1,1);
    add(pre[i]+1,-1);
    while(t<=m&&q[t].b==i)
    {
      ans[q[t].id]=find(q[t].a);
      t++;
    }
  }
  for (i=1;i<=m;i++)
    printf("%d\n",ans[i]);
  return 0;
}
