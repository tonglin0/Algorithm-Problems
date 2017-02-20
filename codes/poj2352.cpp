#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define MN 15005
using namespace std;

struct node{int x,y,id;bool operator < (node a)const{return x<a.x;}};
node a[MN],b[MN];
int c[MN];
int n;
int sum[MN];

int low(int x){return x&(-x);}

void add(int x,int n)
{
  int i=x;
  while(i<=n)
  {
    c[i]++;
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
  freopen("2352.in","r",stdin);
  freopen("2352.out","w",stdout);
  int m,i,j,k;
  memset(a,0,sizeof(a));
  memset(b,0,sizeof(b));
  memset(c,0,sizeof(c));
  scanf("%d",&n);
  for (i=1;i<=n;i++)
  {
    scanf("%d%d",&a[i].x,&a[i].y);
    b[i].x=a[i].x;b[i].y=a[i].y;
    a[i].id=b[i].id=i;
  }
  sort(b+1,b+n+1);
  int pre=-1,t=0;
  for (i=1;i<=n;i++)
    if (b[i].x!=pre)
    {
      pre=b[i].x;
      b[i].x=++t;
    }
    else
      b[i].x=t;
  for (i=1;i<=n;i++)
    a[b[i].id].x=b[i].x;
  memset(sum,0,sizeof(sum));
  for (i=1;i<=n;i++)
  {
    k=find(a[i].x);
    add(a[i].x,t);
    sum[k]++;
  }
 for (i=0;i<n;i++)
   printf("%d\n",sum[i]);
 return 0; 
}
