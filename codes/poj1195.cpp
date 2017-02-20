#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MN 1028
using namespace std;

int c[MN][MN];
int n;

int low(int x){return x&(-x);}

void add(int x,int y,int d)
{
  int i=x,j;
  while(i<=n)
  {
    j=y;
    while(j<=n)
    {
      c[i][j]+=d;
      j+=low(j);
    }
    i+=low(i);
  }
}

int find(int x,int y)
{
  int ans=0,i=x,j;
  while(i>0)
  {
    j=y;
    while(j>0)
    {
      ans+=c[i][j];
      j-=low(j);
    }
    i-=low(i);
  }
  return ans;
}

int main()
{
  freopen("1195.in","r",stdin);
  freopen("1195.out","w",stdout);
  int i,j,k,m;
  int d,x,y;
  scanf("%d%d",&d,&n);
  memset(c,0,sizeof(c));
  scanf("%d",&d);
  while(true)
  {if (d==3)
    return 0;
  else if (d==1)
  {
    scanf("%d%d%d",&x,&y,&k);
    x++;y++;
    add(x,y,k); 
  }
  else 
  {
    int xa,ya,xb,yb;
    scanf("%d%d%d%d",&xa,&ya,&xb,&yb);
    xa++;xb++;ya++;yb++;
    printf("%d\n",find(xb,yb)-find(xa-1,yb)-find(xb,ya-1)+find(xa-1,ya-1));
  }
  scanf("%d",&d);}
  return 0;
}
