#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define LL long long
#define MN 30008
using namespace std;

struct node{int v,id;};
node a[MN],b[MN];
int c[MN];
int s1[MN],s2[MN];
int n,t;
bool cmp(node a,node b){return a.v<b.v;}

int low(int x){return x&(-x);}

void add(int x,int d)
{
  int i=x;
  while(i<=t+1)
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
  freopen("1637.in","r",stdin);
  freopen("1637.out","w",stdout);
  int m,i,j,k;
  memset(a,0,sizeof(a));
  memset(b,0,sizeof(b));
  memset(c,0,sizeof(c));
  scanf("%d",&n);
  for (i=1;i<=n;i++)
  {
    scanf("%d",&a[i].v);
    a[i].id=i;
  }
  sort(a+1,a+n+1,cmp);
  t=0;
  int pre=-1;
  //a[1].v=1;
  for (i=1;i<=n;i++)
    if (a[i].v==pre)
      a[i].v=a[i-1].v;
    else
    {
      pre=a[i].v;
      a[i].v=++t;
    }/*
  a[1].small=0;
  for (i=2;i<=n;i++)
    if (a[i].v==a[i-1].v)
      a[i].small=a[i-1].small;
    else
      a[i].small=i-1;
  a[n].large=0;
  for (i=n-1;i>=1;i--)
    if (a[i].v==a[i+1].v)
      a[i].large=a[i+1].large;
    else
      a[i].large=n-i;*/
  for (i=1;i<=n;i++)
    b[a[i].id]=a[i];
  LL ans=0;
  for (i=1;i<=n;i++)
  {
    s1[i]=find(b[i].v-1);
    add(b[i].v,1);
    //int s2=n-i-(a[i].small-s1);
  }
  for (i=1;i<=n;i++)
    b[i].v=t+2-b[i].v;
  for (i=1;i<=(n>>1);i++)
  {
    node tt=b[n-i+1];
    b[n-i+1]=b[i];
    b[i]=tt;
  }
  memset(c,0,sizeof(c));
  for (i=1;i<=n;i++)
  {
    s2[n-i+1]=find(b[i].v-1);
    add(b[i].v,1);
  }
  for (i=2;i<=n-1;i++)
    ans+=(LL)s1[i]*(LL)s2[i];
  cout<<ans<<endl;
  return 0;
}

