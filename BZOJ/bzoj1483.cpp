#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<string>
#include<ctime>
#define INF (int)1e9
#define lint long long
#define eps 1e-8
#define MN 1000010
using namespace std;

char ch;

void read(int &x)
{
  while(ch=getchar(),ch<'0'||ch>'9');
  x=ch-'0';
  while(ch=getchar(),ch>='0'&&ch<='9') x=x*10+ch-'0';
}

int a[MN],f[MN],head[MN],next[MN],cnt[MN];

int main()
{
  freopen("1483.in","r",stdin);
  freopen("1483.out","w",stdout);
  int n,i,j,k,m,ca,ii=0;
  read(n);read(m);
  int ans=0;
  a[0]=-1;
  for (i=1;i<=n;i++)
  {
    read(a[i]);
    cnt[a[i]]++;
    if (a[i]!=a[i-1])
      ans++;
    next[i]=head[a[i]];
    head[a[i]]=i;
  }
  for (i=1;i<=1000000;i++)
    f[i]=i;
  while(m--)
  {
    int op;
    read(op);
    if (op==2)
      printf("%d\n",ans);
    else
    {
      int x,y;
      read(x);read(y);
      if (x==y) continue;
      if (cnt[f[x]]>cnt[f[y]])
        swap(f[x],f[y]);
      x=f[x];y=f[y];
      if (cnt[x]==0||cnt[y]==0) continue; 
      for (i=head[x];i;i=next[i])
      {
        if (a[i]==a[i-1])
          ans++;
        if (i<=n-1&&a[i]==a[i+1])
          ans++;
      }
      for (i=head[x];i;i=next[i])
        a[i]=y;
      int last;
      for (i=head[x];i;last=i,i=next[i])
      {
        if (a[i]==a[i-1])
          ans--;
        if (i<=n-1&&a[i]==a[i+1])
          ans--;
      }
      int tmp=next[head[y]];
      next[last]=tmp;
      next[head[y]]=head[x];
      cnt[y]+=cnt[x];cnt[x]=0;head[x]=0;
    }
  }
  return 0;
}
