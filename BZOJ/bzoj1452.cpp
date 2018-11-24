#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<vector>
#include<queue>
#include<string>
#include<map>
#include<cctype>
#include<algorithm>
#define INF (int)1e9
#define lint long long
#define llu unsigned long long
#define eps 1e-8
using namespace std;

int c[103][303][303];
int a[303][303];
int n,m;

int lowbit(int x){return x&(-x);}

void update(int k,int x,int y,int d)
{
  int i,j;
  i=x;
  while(i<=n)
  {
    j=y;
    while(j<=m)
    {
      c[k][i][j]+=d;
      j+=lowbit(j);
	}
	i+=lowbit(i);
  }
}

int query(int k,int x,int y)
{
  int ans=0;
  int i=x,j;
  while(i>0)
  {
    j=y;
    while(j>0)
    {
      ans+=c[k][i][j];
      j-=lowbit(j);
	}
	i-=lowbit(i);
  }
  return ans;
}

int main()
{
  freopen("1452.in","r",stdin);
  freopen("1452.out","w",stdout);
  int i,j,k,ii=0,ca;
  int qus;
  scanf("%d%d",&n,&m);
  for (i=1;i<=n;i++)
    for (j=1;j<=m;j++)
    {
      scanf("%d",&a[i][j]);
      update(a[i][j],i,j,1);
	}
  scanf("%d",&qus);
  while(qus--)
  {
    int op;
    scanf("%d",&op);
    if (op==1)
    {
      int x,y,d;
      scanf("%d%d%d",&x,&y,&d);
      update(d,x,y,1);
      update(a[x][y],x,y,-1);
      a[x][y]=d;
	}
	else
	{
	  int xa,ya,xb,yb,d;
	  scanf("%d%d%d%d%d",&xa,&xb,&ya,&yb,&d);
	  int ans=0;
	  ans+=query(d,xb,yb);
	  ans-=query(d,xb,ya-1);
	  ans-=query(d,xa-1,yb);
	  ans+=query(d,xa-1,ya-1);
	  printf("%d\n",ans);
	}
  }
  return 0;
}

