#include<cstdlib>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MN 1000110
using namespace std;

struct node{int x,y;};
node a[MN];
long long c[1004];
int n;
bool cmp(node a,node b){if (a.y!=b.y) return a.y<b.y;return a.x>b.x;}

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

long long find(int x)
{
  long long ans=0;
  int i=x;
  while(i>0)
  {
    ans+=c[i];
    i-=low(i);
  }
  return ans;
}

int main()
{
  freopen("3067.in","r",stdin);
  freopen("3067.out","w",stdout);
  int m,i,j,k,x,y,ii;
  int T;
  scanf("%d",&T);
  for (ii=1;ii<=T;ii++)
  {
    memset(a,0,sizeof(a));
    memset(c,0,sizeof(c));
    scanf("%d%d%d",&n,&m,&k);
    for (i=1;i<=k;i++)
      scanf("%d%d",&a[i].x,&a[i].y);
    for (i=1;i<=k;i++)
      a[i].y=m+1-a[i].y;
    sort(a+1,a+k+1,cmp);
    long long ans=0;
    for (i=1;i<=k;i++)
    {
      ans+=(long long)find(a[i].x-1);
      add(a[i].x,1);
    }
    printf("Test case %d: ",ii);
    cout<<ans<<endl;
  }
  return 0;
}
