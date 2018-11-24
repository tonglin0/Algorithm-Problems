#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define MN 1000004
#define N 50005
using namespace std;

int a[N];
int pre[N];
int last[MN];
int c[N];
int ans[200004];
struct node{int a,b,id;bool operator < (node x)const{return b<x.b;}};
node q[200004];
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
  freopen("diff.in","r",stdin);
  freopen("diff.out","w",stdout);
  int i,j,k,m;
  scanf("%d",&n);
  memset(c,0,sizeof(c));
  memset(last,0,sizeof(last));
  memset(pre,0,sizeof(pre));
  memset(ans,0,sizeof(ans));
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
  scanf("%d",&m);
  int l,r;
  for (i=1;i<=m;i++)
  {
    scanf("%d%d",&l,&r);
    l++;r++;
    q[i].id=i;
    q[i].a=l;
    q[i].b=r;  
  }
  sort(q+1,q+m+1);
  int t=1;
  for (i=2;i<=n+1;i++)
  {
    add(pre[i]+1,1);
    add(i+1,-1);
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
