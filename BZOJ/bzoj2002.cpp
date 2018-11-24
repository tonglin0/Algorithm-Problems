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
#define MN 200009
using namespace std;

int a[MN],pos[MN],net[MN],tms[MN];
int bsz,n,cnt;

void read(int &x)
{
  char ch;
  while(ch=getchar(),ch<'0'||ch>'9');
  x=ch-'0';
  while(ch=getchar(),ch>='0'&&ch<='9') x=x*10+ch-'0';
}

int query(int x)
{
  int ans=0;
  while(net[x])
  {
    ans+=tms[x];
    x=net[x];
  }
  return ans+tms[x];
}

int main()
{
  freopen("2002.in","r",stdin);
  freopen("2002.out","w",stdout);
  int ca,i,j,k,m,ii=0;
  read(n);
  bsz=(int)(sqrt(n+0.5));
  if (n%bsz)
    cnt=n/bsz+1;
  else
    cnt=n/bsz;
  for (i=1;i<=n;i++)
  {
    read(a[i]);
    pos[i]=(i-1)/bsz+1;
  }
  for (i=n;i>=1;i--)
  {
    if (i+a[i]>n)
    {
      tms[i]=1;
      net[i]=0;
    }
    else if (pos[i]==pos[i+a[i]])
    {
      tms[i]=tms[i+a[i]]+1;
      net[i]=net[i+a[i]];
	}
	else
	{
	  tms[i]=1;
	  net[i]=i+a[i];
	}
  }
  read(m);
  while(m--)
  {
    int op,x,y;
    read(op);read(x);
    x++;
    if (op==1)
      printf("%d\n",query(x));
    else
    {
      read(y);
      a[x]=y;
      for (i=x;i>=(pos[x]-1)*bsz+1;i--)
        if (i+a[i]>n)
        {
          tms[i]=1;
          net[i]=0;
        }
        else if (pos[i]==pos[i+a[i]])
        {
          tms[i]=tms[i+a[i]]+1;
          net[i]=net[i+a[i]];
		}
		else 
		{
		  tms[i]=1;
		  net[i]=i+a[i];
		}
	}
  }
  return 0;
}

