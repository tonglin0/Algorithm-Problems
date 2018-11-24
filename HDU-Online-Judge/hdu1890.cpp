#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#define MN 200190
using namespace std;

int pre[MN],rev[MN],ch[MN][2],sz[MN];
struct node{int id,s;};
node a[MN];
int n,root;

bool cmp(node a,node b){if (a.s!=b.s) return a.s<b.s;return a.id<b.id;}

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

void build(int &x,int l,int r,int fa)
{
  if (l>r) return ;
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
  int i;
  for (i=1;i<=n;i++)
  {
    scanf("%d",&a[i].s);
    a[i].id=i;
  }
  ch[0][0]=ch[0][1]=rev[0]=sz[0]=pre[0]=0;
  build(root,1,n,0);
  sort(a+1,a+n+1,cmp);
}

void pushdown(int x)
{
  if (rev[x])
  {
    int lc=ch[x][0],rc=ch[x][1];
    rev[lc]^=1;rev[rc]^=1;
    swap(ch[lc][0],ch[lc][1]);
    swap(ch[rc][0],ch[rc][1]);
    rev[x]=0;
  }
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

int join(int s1,int s2)
{
  if (s1==0) return s2;
  if (s2==0) return s1;
  int r=s1;
  pushdown(r);
  while(ch[r][1])
  {
    r=ch[r][1];
    pushdown(r);
  }
  pre[s1]=0;
  splay(r,0);
  pre[s2]=r;
  ch[r][1]=s2;
  pushup(r);
  return r;
}

void del()
{
  pushdown(root);
  root=join(ch[root][0],ch[root][1]);
  pre[root]=0;
}

int main()
{
  freopen("1890.in","r",stdin);
  freopen("1890.out","w",stdout);
  int i,j,k,m;
  scanf("%d",&n);
  while(n)
  {
    init();
    for (i=1;i<=n;i++)
    {
      splay(a[i].id,0);
      if (i!=n)
        printf("%d ",sz[ch[root][0]]+i);
      else
        printf("%d\n",sz[ch[root][0]]+i);
      rev[ch[root][0]]^=1;
      swap(ch[ch[root][0]][0],ch[ch[root][0]][1]);
      del();
    }
    scanf("%d",&n);
  }
  return 0;
}
