#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define K ch[ch[root][1]][0]
#define MN 600100
using namespace std;

int pre[MN],a[MN],sz[MN],ch[MN][2],key[MN],rev[MN];
int root,tot;
int n;

void newnode(int &r,int fa,int k)
{
  r=++tot;
  pre[r]=fa;
  ch[r][0]=ch[r][1]=0;
  key[r]=k;
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
    int lc=ch[x][0];
    int rc=ch[x][1];
    rev[lc]^=1;
    rev[rc]^=1;
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
  tot=root=0;
  ch[0][0]=ch[0][1]=rev[0]=pre[0]=sz[0]=key[0]=0;
  newnode(root,0,-1);
  newnode(ch[root][1],root,-1);
  sz[root]=2;
  build(K,1,n,ch[root][1]);
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
    if (sz[ch[r][0]]>k)
    {
      r=ch[r][0];
      pushdown(r);
    }
    else
    {
      k-=(sz[ch[r][0]]+1);
      r=ch[r][1];
      pushdown(r);
    }
  }
}

int main()
{
  freopen("1743.in","r",stdin);
  freopen("1743.out","w",stdout);
  int m,i,j,k;
  scanf("%d",&n);
  for (i=1;i<=n;i++)
    scanf("%d",&a[i]);
  init();
  int ans=0;
  while(ans<=100000)
  {
    //k=get_min(root);
    k=key[get_kth(1)];
    if (k==1)
    {
      printf("%d\n",ans);
      return 0;
    }
    int l=get_kth(0);
    int r=get_kth(k+1);
    splay(l,0);
    splay(r,root);
    ans++;
    rev[K]^=1;
    swap(ch[K][1],ch[K][0]);
  }
  printf("-1\n");
  return 0;
}
