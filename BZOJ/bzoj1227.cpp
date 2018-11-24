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
#define MOD 2147483648LL
using namespace std;

struct node{
	int x,y,id;
};
int cc[100003];
node a[100003];
int K,top;
lint c[100003][12];
int up[100003],down[100003];
int lft[100003],rt[100003];

void read(int &x)
{
  char ch;
  while(ch=getchar(),ch<'0'||ch>'9');
  x=ch-'0';
  while(ch=getchar(),ch>='0'&&ch<='9') x=x*10+ch-'0';
}

void getc(int n,int m)
{
  c[0][0]=1;
  for (int i=1;i<=n;i++)
  {
    c[i][0]=1;
    for (int j=1;j<=m;j++)
      c[i][j]=(c[i-1][j-1]+c[i-1][j])%MOD;
  }
}

bool cmpx(node a,node b){if (a.x!=b.x) return a.x<b.x;return a.y<b.y;}
bool cmpy(node a,node b){if (a.y!=b.y) return a.y<b.y;return a.x<b.x;}

int low(int x){return x&(-x);}

void update(int x,int d)
{
  int i=x;
  while(i<=top)
  {
    cc[i]=((cc[i]+d)%MOD+MOD)%MOD;
    i+=low(i);
  }
}

lint getans(int x)
{
  lint ans=0;
  int i=x;
  while(i>0)
  {
    ans=(ans+cc[i])%MOD;
    i-=low(i);
  }
  return ans;
}

lint query(int l,int r)
{
  lint ans=0;
  ans+=getans(r);
  ans-=getans(l-1);
  return ans;
}

int main()
{
  freopen("1227.in","r",stdin);
  freopen("1227.out","w",stdout);
  int ca,n,i,j,k,m,ii=0;
  read(n);read(m);
  n++;m++;
  int w;
  read(w);
  for (i=1;i<=w;i++)
  {
    read(a[i].x);
    a[i].x++;
    a[i].id=i;
	read(a[i].y);
	a[i].y++;
  }
  read(K);
  getc(w,K);
  sort(a+1,a+w+1,cmpy);
  top=0;
  int prey;
  for (i=1;i<=w;i++)
    if (i==1||a[i].y!=prey)
    {
      prey=a[i].y;
      a[i].y=++top;
	}
	else
	  a[i].y=top;
  for (i=1;i<=w;i++)
    if (i==1||a[i].y!=a[i-1].y)
      lft[a[i].id]=0;
    else
      lft[a[i].id]=lft[a[i-1].id]+1;
  for (i=w;i>=1;i--)
    if (i==w||a[i].y!=a[i+1].y)
      rt[a[i].id]=0;
    else
      rt[a[i].id]=rt[a[i+1].id]+1;
  sort(a+1,a+w+1,cmpx);
  for (i=1;i<=w;i++)
    if (i==1||a[i].x!=a[i-1].x)
      up[a[i].id]=0;
    else
      up[a[i].id]=up[a[i-1].id]+1;
  for (i=w;i>=1;i--)
    if (i==w||a[i].x!=a[i+1].x)
      down[a[i].id]=0;
    else
      down[a[i].id]=down[a[i+1].id]+1;
  lint ans=0;
  int r;
  i=1;
  while(i<=w)
  {
    r=i;
    while(r+1<=w&&a[r+1].x==a[i].x)
      r++;
    for (j=i+1;j<=r;j++)
      if (a[j].y>a[j-1].y+1)
        ans=(ans+c[up[a[j].id]][K]*c[down[a[j-1].id]][K]%MOD*query(a[j-1].y+1,a[j].y-1)%MOD)%MOD;
    for (j=i;j<=r;j++)
      update(a[j].y,((c[lft[a[j].id]+1][K]*c[rt[a[j].id]][K]%MOD-c[lft[a[j].id]][K]*c[rt[a[j].id]+1][K]%MOD)%MOD+MOD)%MOD);
    i=r+1;
  }
  printf("%lld\n",(ans%MOD+MOD)%MOD);
  return 0;
}

