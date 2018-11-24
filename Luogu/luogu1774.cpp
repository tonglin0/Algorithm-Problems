#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#define LL long long
#define MN 500005
using namespace std;

int c[MN],b[MN];
struct node{int id,v;bool operator < (node b)const{return v<b.v;}};
node a[MN];
int n;

int lowbit(int x){return x&(-x);}

void add(int x,int d,int n)
{
  int i=x;
  while(i<=n)
  {
    c[i]+=d;
    i+=lowbit(i);
  }
}

LL find(int x,int n)
{
  int i=x;
  LL ans=0;
  while(i>0)
  {
    ans+=c[i];
    i-=lowbit(i);
  }
  return ans;
}

int main()
{
  freopen("1774.in","r",stdin);
  freopen("1774.out","w",stdout);
  int i,j,k,m;
  scanf("%d",&n);
  memset(c,0,sizeof(c));
  memset(b,0,sizeof(b));
  memset(a,0,sizeof(a));
  for (i=1;i<=n;i++)
  {
    scanf("%d",&a[i].v);
    a[i].id=i;
  }
  sort(a+1,a+n+1);
  int t=0,pre=-1;
  for (i=1;i<=n;i++)
    if (a[i].v!=pre)
    {
      pre=a[i].v;
      a[i].v=++t;
    }
    else
      a[i].v=t;
  for (i=1;i<=n;i++)
    b[a[i].id]=a[i].v;
  LL ans=0;
  for (i=n;i>=1;i--)
  {
    ans+=find(b[i]-1,t);
    add(b[i],1,t);
  }
  cout<<ans<<endl;
  return 0;
}
