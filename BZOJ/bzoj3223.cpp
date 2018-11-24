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
#define MN 200009
using namespace std;

int ch[MN][2],pre[MN],key[MN],sz[MN],rev[MN];
int n;
int a[MN];
int tot=0;
bool first=true;
int root=0;

void newnode(int &r,int fa,int k)
{
  r=++tot;
  pre[r]=fa;
  key[r]=k;
  rev[r]=ch[r][0]=ch[r][1]=0;
  sz[r]=1;
}

void pushup(int p)
{
  sz[p]=sz[ch[p][0]]+sz[ch[p][1]]+1;
}

void pushdown(int p)
{
  int lc=ch[p][0],rc=ch[p][1];
  if (rev[p])
  {
    rev[lc]^=1;
    swap(ch[lc][0],ch[lc][1]);
    rev[rc]^=1;
    swap(ch[rc][0],ch[rc][1]);
    rev[p]=0;
  }
}

void build(int &x,int l,int r,int fa)
{
  int mid=(l+r)>>1;
  newnode(x,fa,a[mid]);
  if (l<mid)
    build(ch[x][0],l,mid-1,x);
  if (r>mid)
    build(ch[x][1],mid+1,r,x);
  pushup(x);
}

void init()
{
  newnode(root,0,-1);
  newnode(ch[root][1],root,-1);
  pushup(root);
  build(ch[ch[root][1]][0],1,n,ch[root][1]);
  pushup(ch[root][1]);
  pushup(root);
}

int get_kth(int k)
{
  int r=root;
  pushdown(r);
  while(r)
  {
    if (sz[ch[r][0]]==k)
      return r;
    else if (sz[ch[r][0]]>k)
      r=ch[r][0];
    else
    {
      k-=sz[ch[r][0]]+1;
      r=ch[r][1];
	}
	pushdown(r);
  }
}

void PRINT(int r)
{
  pushdown(r);
  if (ch[r][0])
    PRINT(ch[r][0]);
  if (r>=3)
  if (first)
  {
    first=false;
    printf("%d",key[r]);
  }
  else
    printf(" %d",key[r]);
  if (ch[r][1])
    PRINT(ch[r][1]);
}

void rotate(int x,int kind)
{
  int y=pre[x];
  ch[y][!kind]=ch[x][kind];
  pre[ch[x][kind]]=y;
  if (pre[y])
    ch[pre[y]][ch[pre[y]][1]==y]=x;
  pre[x]=pre[y];
  ch[x][kind]=y;
  pre[y]=x;
  pushup(y);
  pushup(x);
}

void splay(int x,int goal)
{
  pushdown(x);
  while(pre[x]!=goal)
  {
    if (pre[pre[x]]==goal)
    {
      int y=pre[x];
      pushdown(y);
      pushdown(x);
      rotate(x,ch[y][0]==x);
	}
	else
	{
	  int y=pre[x];
	  int z=pre[y];
	  pushdown(z);
	  pushdown(y);
	  pushdown(x);
	  int kind=ch[z][0]==y;
	  if (ch[y][kind]==x)
	  {
	    rotate(x,!kind);
	    rotate(x,kind);
	  }
	  else
	  {
	    rotate(y,kind);
	    rotate(x,kind);
	  }
	}
  }
  pushup(x);
  if (goal==0)
    root=x;
}

int main()
{
  freopen("3223.in","r",stdin);
  freopen("3223.out","w",stdout);
  int i,j,k,m,ii=0,ca;
  scanf("%d%d",&n,&m);
  for (i=1;i<=n;i++)
    a[i]=i;
  init();
  while(m--)
  {
    int l,r;
    scanf("%d%d",&l,&r);
    l=get_kth(l-1);
    r=get_kth(r+1);
    splay(l,0);
    splay(r,root);
    int K=ch[ch[root][1]][0];
    rev[K]^=1;
    swap(ch[K][0],ch[K][1]);
  }
  PRINT(root);
  return 0;
}

