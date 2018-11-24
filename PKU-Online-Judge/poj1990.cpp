#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define MN 20005
#define LL long long
using namespace std;

struct node{int v,x;bool operator < (node a)const{return v<a.v;}};
node a[MN];
int vc[MN],xc[MN];
int n;

int low(int x){return x&(-x);}

void addvc(int x,int d)
{
  int i=x;
  while(i<MN)
  {
    vc[i]+=d;
    i+=low(i);
  }
}

void addxc(int x,int d)
{
  int i=x;
  while(i<MN)
  {
    xc[i]+=d;
    i+=low(i);
  }
}

LL findvc(int x)
{
  LL ans=0;
  int i=x;
  while(i>0)
  {
    ans+=(LL)vc[i];
    i-=low(i);
  }
  return ans;
}

LL findxc(int x)
{
  LL ans=0;
  int i=x;
  while(i>0)
  {
    ans+=(LL)xc[i];
    i-=low(i);
  }
  return ans;
}

int main()
{
  freopen("1990.in","r",stdin);
  freopen("1990.out","w",stdout);
  int m,i,j,k,v,x;
  memset(vc,0,sizeof(vc));
  memset(xc,0,sizeof(xc));
  memset(a,0,sizeof(a));
  scanf("%d",&n);
  for (i=1;i<=n;i++)
    scanf("%d%d",&a[i].v,&a[i].x);
  LL presum=0;
  sort(a+1,a+n+1);
  LL ans=0;
  for (i=1;i<=n;i++)
  {
    LL sum1=findvc(a[i].x-1);
    LL sum2=presum-sum1;
    LL cnt1=findxc(a[i].x-1);
    LL cnt2=i-cnt1-1;
    ans+=(LL)((LL)a[i].v*(cnt1*a[i].x-sum1+sum2-a[i].x*cnt2));
    presum+=(LL)a[i].x;
    addvc(a[i].x,a[i].x);
    addxc(a[i].x,1);
  }
  cout<<ans<<endl;
  return 0;
}
