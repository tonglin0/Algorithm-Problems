#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MN 1004
using namespace std;

int c[MN][MN];
int n;

int lowbit(int x){return x&(-x);}

void add(int x,int y,int d)
{
  int i,j=y;
  while(j<=n)
  {
    i=x;
    while(i<=n)
    {
      c[i][j]++;
      i+=lowbit(i);
    }
    j+=lowbit(j);
  }
}

int find(int x,int y)
{
  int ans=0;
  int i,j=y;
  while(j>0)
  {
    i=x;
    while(i>0)
    {
      ans+=c[i][j];
      i-=lowbit(i);
    }
    j-=lowbit(j);
  }
  return ans;
}

int main()
{
  freopen("2155.in","r",stdin);
  freopen("2155.out","w",stdout);
  int i,j,k,m,T;
  scanf("%d",&T);
  while(T--)
  {
    scanf("%d%d",&n,&m);
    memset(c,0,sizeof(c));
    while(m--)
    {
      char ch[3];
      scanf("%s",ch);
      if (ch[0]=='C')
      {
        int xa,ya,xb,yb;
        scanf("%d%d%d%d",&xa,&ya,&xb,&yb);
        add(xa,ya,1);
        add(xa,yb+1,1);
        add(xb+1,ya,1);
        add(xb+1,yb+1,1);
      }
      else
      {
        int x,y;
        scanf("%d%d",&x,&y);
        printf("%d\n",find(x,y)&1);
      }
    }
    printf("\n");
  }
  return 0;
}
