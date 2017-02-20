#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define MN 4000100
#define INF 1<<30
#define K ch[ch[root][1]][0]
using namespace std;

int a[MN],pre[MN],sz[MN],mi[MN],ch[MN][2],rev[MN],add[MN],key[MN],s[MN];
char st[MN];
int tot2,tot1,root;
int n;

void newnode(int &r,int fa,int k)
{
  /*if (tot2)
    r=s[tot2--];
  else
    r=++tot1;*/
  r=++tot1;
  pre[r]=fa;
  key[r]=k;
  ch[r][0]=ch[r][1]=0;
  sz[r]=1;
  mi[r]=k;
  add[r]=rev[r]=0;
}

void update_add(int x,int k)
{
  add[x]+=k;
  mi[x]+=k;
  key[x]+=k;
}

void pushup(int x)
{
  int lc=ch[x][0];
  int rc=ch[x][1];
  sz[x]=sz[lc]+sz[rc]+1;
  mi[x]=min(mi[lc],min(mi[rc],key[x]));
}

void pushdown(int x)
{
  int lc=ch[x][0],rc=ch[x][1];
  if (add[x])
  {
    if (lc)
      update_add(lc,add[x]);
    if (rc) 
      update_add(rc,add[x]);
    add[x]=0;
  }
  if (rev[x])
  {
    if (lc)
      rev[lc]^=1;
    if (rc)
      rev[rc]^=1;
    if (lc)
      swap(ch[lc][0],ch[lc][1]);
    if (rc)
      swap(ch[rc][0],ch[rc][1]);
    rev[x]=0;
  }
}

void build(int &x,int l,int r,int fa)
{
  if (l>r) return ;
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
  root=tot1=tot2=0;
  ch[0][0]=ch[0][1]=pre[0]=sz[0]=rev[0]=add[0]=0;
  mi[0]=INF;
  newnode(root,0,INF);
  newnode(ch[root][1],root,INF);
  pushup(root);
  build(K,1,n,ch[root][1]);
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

void debug(int r)
{
  pushdown(r);
  if (ch[r][0])
    debug(ch[r][0]);
  if (key[r]!=INF)
    printf("%d ",key[r]);
  if (ch[r][1])
    debug(ch[r][1]);
}

int main()
{
  freopen("3580.in","r",stdin);
  freopen("3580.out","w",stdout);
  int m,i,j,k;
  scanf("%d",&n);
  for (i=1;i<=n;i++)
    scanf("%d",&a[i]);
  init();
  scanf("%d",&m);
  while(m--)
  {
    scanf("%s",st);
    if (st[0]=='A')
    {
      int l,r;
      scanf("%d%d%d",&l,&r,&k);
      if (l>r) swap(l,r);
      l=get_kth(l-1);
      r=get_kth(r+1);
      splay(l,0);
      splay(r,root);
      update_add(K,k);
      pushup(ch[root][1]);
      pushup(root);
    }
    else if (st[0]=='I')
    {
      int l,r,t;
      scanf("%d%d",&l,&k);
      t=l;
      l=get_kth(l);
      r=get_kth(t+1);
      splay(l,0);
      splay(r,root);
      newnode(K,r,k);
      pushup(r);
      pushup(root);
      splay(K,0);
    }
    else if (st[0]=='D')
    {
      int l,r,t;
      scanf("%d",&l);
      t=l;
      l=get_kth(l-1);
      splay(l,0);
      r=get_kth(t+1);
      splay(r,root);
      pre[K]=0;
      K=0;
      pushup(r);
      pushup(root);
    }
    else if (st[0]=='M')
    {
      int t,l,r;
      scanf("%d%d",&l,&r);
      if (l>r) swap(l,r);
      l=get_kth(l-1);
      r=get_kth(r+1);
      splay(l,0);
      splay(r,root);
      printf("%d\n",mi[K]);
    }
    else if (st[3]=='E')
    {
      int l,r;
      scanf("%d%d",&l,&r);
      if (l>r) swap(l,r);
      l=get_kth(l-1);
      r=get_kth(r+1);
      splay(l,0);
      splay(r,root);
      rev[K]^=1;
      swap(ch[K][0],ch[K][1]);
    }
    else
    {
      int l,r;
      scanf("%d%d%d",&l,&r,&k);
      if (l>r) swap(l,r);
      k=k%(r-l+1);
      k=(k+r-l+1)%(r-l+1);
      if (k==0)
        continue;
      int l2=get_kth(r-k);
      int r2=get_kth(r+1);
      splay(l2,0);
      splay(r2,root);
      int tmp=K;
      pre[K]=0;
      K=0;
      pushup(ch[root][1]);
      pushup(root);
      int l1=get_kth(l-1);
      int r1=get_kth(l);
      splay(l1,0);
      splay(r1,root);
      K=tmp;
      pre[K]=ch[root][1];
      pushup(ch[root][1]);
      pushup(root);
    }
  }
  return 0;
}
