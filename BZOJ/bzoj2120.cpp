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
#define MN 10009
using namespace std;

bool vis[109];
int a[MN],b[MN],pos[MN],pre[MN];
int last[1000009];
int n,m;
int SZ;

void reset(int x)
{
  int l=(x-1)*SZ+1,r=min(x*SZ,n);
  for (int i=l;i<=r;i++)
    pre[i]=b[i];
  sort(pre+l,pre+r+1);
}

int find(int x,int v)
{
  int st=(x-1)*SZ+1,en=min(x*SZ,n);
  int l=st,r=en;
  while(l<r)
  {
    int mid=(l+r+1)>>1;
    if (pre[mid]>=v)
      r=mid-1;
    else
      l=mid;
  }
  return l-st+1;
}

void update(int x,int v)
{
  memset(vis,0,sizeof(vis));
  //memset(last,0,sizeof(last));
  a[x]=v;
  for (int i=1;i<=n;i++)
    last[a[i]]=0;
  for (int i=1;i<=n;i++)
  {
    if (b[i]!=last[a[i]])
    {
      b[i]=last[a[i]];
      vis[pos[i]]=true;
	}
	last[a[i]]=i;
  }
  for (int i=1;i<=m;i++)
    if (vis[i])
      reset(i);
}

int query(int x,int y)
{
  int ans=0;
  if (pos[x]==pos[y])
  {
    for (int i=x;i<=y;i++)
      if (b[i]<x)
        ans++;
    return ans;
  }
  for (int i=x;i<=pos[x]*SZ;i++)
    if (b[i]<x)
      ans++;
  for (int i=(pos[y]-1)*SZ+1;i<=y;i++)
    if (b[i]<x)
      ans++;
  for (int i=pos[x]+1;i<pos[y];i++)
    ans+=find(i,x);
  return ans;
}

int main()
{
  freopen("2120.in","r",stdin);
  freopen("2120.out","w",stdout);
  int i,j,k,ii=0,ca,qus;
  scanf("%d%d",&n,&qus);
  memset(last,0,sizeof(last));
  SZ=(int)sqrt(n+0.01);
  for (i=1;i<=n;i++)
  {
    scanf("%d",&a[i]);
    b[i]=last[a[i]];
    pos[i]=(i-1)/SZ+1;
    last[a[i]]=i;
  }
  if (n%SZ)
    m=n/SZ+1;
  else
    m=n/SZ;
  for (i=1;i<=m;i++)
    reset(i);
  while(qus--)
  {
    char op[3];
    int x,y;
    scanf("%s%d%d",op,&x,&y);
    if (op[0]=='R')
      update(x,y);
    else
      printf("%d\n",query(x,y));
  }
  return 0;
}

