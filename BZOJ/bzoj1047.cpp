#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cctype>
#include<ctime>
#include<queue>
#include<string>
#include<vector>
#include<map>
#define eps 1e-8
#define INF (int)1e9
#define lint long long
#define llu unsigned long long
using namespace std;

int a[1004][1004];
int mi[1004][1004],ms[1004][1004],ms2[1004][1004],mi2[1004][1004];
int A[1004],B[1004];
int f,r;

void add(int x,int id)
{
  while(f<=r&&A[r]<=x)
    r--;
  A[++r]=x;
  B[r]=id;
}

void gethang(int n,int m,int d)
{
  int i,j,k;
  for (i=1;i<=n;i++)
  {
    r=0,f=1;
    for (j=1;j<=d-1;j++)
      add(a[i][j],j);
    for (j=d;j<=m;j++)
    {
      add(a[i][j],j);
      while(f<=r&&B[f]<j-d+1)
        f++;
	  ms[i][j-d+1]=A[f];
	}
  }
  for (i=1;i<=n;i++)
    for (j=1;j<=m;j++)
      a[i][j]=-a[i][j];
  for (i=1;i<=n;i++)
  {
    r=0;f=1;
    for (j=1;j<=d-1;j++)
      add(a[i][j],j);
    for (j=d;j<=m;j++)
    {
      add(a[i][j],j);
      while(f<=r&&B[f]<j-d+1)
        f++;
      mi[i][j-d+1]=A[f];
	}
  }
  for (i=1;i<=n;i++)
    for (j=1;j<=m;j++)
      a[i][j]=-a[i][j];
}

void getlie(int n,int m,int d)
{
  int i,j,k;
  for (j=1;j<=m;j++)
  {
    r=0;f=1;
    for (i=1;i<=d-1;i++)
      add(ms[i][j],i);
    for (i=d;i<=n;i++)
    {
      add(ms[i][j],i);
      while(f<=r&&B[f]<i-d+1)
        f++;
      ms2[i-d+1][j]=A[f];
	}
  }
  for (j=1;j<=m;j++)
  {
    r=0;f=1;
    for (i=1;i<=d-1;i++)
      add(mi[i][j],i); 
    for (i=d;i<=n;i++)
    {
      add(mi[i][j],i);
      while(f<=r&&B[f]<i-d+1)
        f++;
      mi2[i-d+1][j]=-A[f];
	}
  }
}

int main()
{
  freopen("1047.in","r",stdin);
  freopen("1047.out","w",stdout);
  int ca,n,i,j,k,m,ii=0;
  scanf("%d%d%d",&n,&m,&k);
  for (i=1;i<=n;i++)
    for (j=1;j<=m;j++)
      scanf("%d",&a[i][j]);
  gethang(n,m,k);
  getlie(n,m-k+1,k);
  int ans=INF;
  for (i=1;i<=n-k+1;i++)
    for (j=1;j<=m-k+1;j++)
      ans=min(ans,ms2[i][j]-mi2[i][j]);
  printf("%d\n",ans);
  return 0;
}

