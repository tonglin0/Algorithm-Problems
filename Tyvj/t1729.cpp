#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<cstring>
#define MN 200100
using namespace std;

int n,root;
int pre[MN],sz[MN],ch[MN][2],rev[MN];

void newnode(int &r,int fa,int k)
{
  r=k;
  pre[r]=fa;
  ch[r][0]=ch[r][1]=0;
  rev[r]=0;
  sz[r]=1;
}

void pushup(int x)
{
  sz[x]=sz[ch[x][0]]+sz[ch[x][1]]+1;
}

void pushdown(int x)
{
  if (rev[x])
  {
    int lc=ch[x][0],rc=ch[x][1];
    rev[lc]^=1;
    rev[rc]^=1;
    swap(ch[lc][0],ch[lc][1]);
    swap(ch[rc][0],ch[rc][1]);
    rev[x]=0;
  }
}

void build(int &x,int l,int r,int fa)
{
  int mid=(l+r)>>1;
  newnode(x,fa,mid);
  if (l<mid)
    build(ch[x][0],l,mid-1,x);
  if (r>mid)
    build(ch[x][1],mid+1,r,x);
  pushup(x);
}

void init()
{
  ch[0][0]=ch[0][1]=pre[0]=rev[0]=0;
  root=0;
  newnode(root,0,n+1);
  newnode(ch[root][1],root,n+2);
  build(ch[ch[root][1]][0],1,n,ch[root][1]);
  pushup(ch[root][1]);
  pushup(root);
}

void rotate(int x,int kind)
{
  int y=pre[x];
  ch[y][!kind]=ch[x][kind];
  pre[ch[x][kind]]=y;
  if (pre[y])
    ch[pre[y]][ch[pre[y]][1]==y]=x;
  pre[x]=pre[y];
  pre[y]=x;
  ch[x][kind]=y;
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
      int kind=(ch[z][0]==y);
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

int get_kth(int k)
{
  int r=root;
  pushdown(r);
  while(r)
  {
    if (sz[ch[r][0]]==k)
      return r;
    if (sz[ch[r][0]]>k)
      r=ch[r][0];
    else
    {
      k-=(sz[ch[r][0]]+1);
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
  if (r<=n)
    printf("%d ",r);
  if (ch[r][1])
    PRINT(ch[r][1]);
}

int main()
{
  freopen("1729.in","r",stdin);
  freopen("1729.out","w",stdout);
  int i,j,k,m;
  scanf("%d%d",&n,&m);
  init();
  while(m--)
  {
    int u,v;
    scanf("%d%d",&u,&v);
    int l=get_kth(u-1);
    int r=get_kth(v+1);
    splay(l,0);
    splay(r,root);
    rev[ch[r][0]]^=1;
    swap(ch[ch[r][0]][0],ch[ch[r][0]][1]);
  }
  PRINT(root);
  printf("\n");
  return 0;
}
