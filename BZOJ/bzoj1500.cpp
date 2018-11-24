#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define MN 801000
#define INF (int)1e9
#define size sz
#define val key
#define lx lm
#define rx rm
#define mx mn
#define K ch[ch[root][1]][0]
using namespace std;

int pre[MN],ch[MN][2],sz[MN],key[MN],rev[MN],sum[MN],set[MN],lm[MN],mn[MN],rm[MN];
int a[MN],s[MN];
int tot1,tot2,root,n;
char str[MN];

void newnode(int &r,int fa,int k)
{
  if (tot2)
    r=s[tot2--];
  else
    r=++tot1;
  pre[r]=fa;
  ch[r][0]=ch[r][1]=rev[r]=0;
  key[r]=k;
  lm[r]=rm[r]=mn[r]=sum[r]=k;
  sz[r]=1;
  set[r]=INF;
}

void pushup(int x){  
    int l=ch[x][0],r=ch[x][1];  
    size[x]=size[l]+size[r]+1;  
    sum[x]=sum[l]+sum[r]+val[x];  
    lx[x]=max(lx[l],sum[l]+val[x]+max(0,lx[r]));  
    rx[x]=max(rx[r],sum[r]+val[x]+max(0,rx[l]));  
    mx[x]=max(0,rx[l])+val[x]+max(0,lx[r]);  
    mx[x]=max(mx[l],max(mx[r],mx[x]));  
}  

void update_rev(int x)
{
  if (!x) return ;
  rev[x]^=1;
  swap(ch[x][0],ch[x][1]);
  swap(lm[x],rm[x]);
}

void update_set(int x,int k)
{
  if (!x) return ;
  key[x]=k;
  rev[x]=0;
  set[x]=k;
  sum[x]=sz[x]*k;
  mn[x]=max(sum[x],k);
  lm[x]=rm[x]=mn[x];
}

void pushdown(int x)
{
  int lc=ch[x][0];
  int rc=ch[x][1];
  if (set[x]<=1001)
  {
    update_set(lc,set[x]);
    update_set(rc,set[x]);
    set[x]=INF;
  }
  if (rev[x])
  {
    update_rev(lc);
    update_rev(rc);
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
  tot1=tot2=root=0;
  ch[0][0]=ch[0][1]=pre[0]=sz[0]=set[0]=rev[0]=sum[0]=mn[0]=key[0]=0;
  mn[0]=lm[0]=rm[0]=-INF;
  newnode(root,0,-INF);
  newnode(ch[root][1],root,-INF);
  sz[root]=2;
  build(K,1,n,ch[root][1]);
  pushup(ch[root][1]);
  pushup(root);
}

void del(int x)
{
  if (ch[x][0])
    del(ch[x][0]);
  s[++tot2]=x;
  if (ch[x][1])
    del(ch[x][1]);
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

void debug(int x)
{
  pushdown(x);
  if (ch[x][0])
    debug(ch[x][0]);
  if (key[x]!=-INF)
    printf("%d ",key[x]);
  if (ch[x][1])
    debug(ch[x][1]);
}

int main()
{
  freopen("1500.in","r",stdin);
  freopen("1500.out","w",stdout);
  int m,i,j,k;
  scanf("%d%d",&n,&m);
  for (i=1;i<=n;i++)
    scanf("%d",&a[i]);
  init();
  while(m--)
  {
    scanf("%s",str);
    if (str[0]=='I')
    {
      int l,p,r;
      scanf("%d%d",&p,&n);
      for (i=1;i<=n;i++)
        scanf("%d",&a[i]);
      l=get_kth(p);
      splay(l,0);
      r=get_kth(p+1);
      splay(r,root);
      build(K,1,n,ch[root][1]);
      pushup(ch[root][1]);
      pushup(root);
    }
    else if (str[0]=='D')
    {
      int p,l,r,f;
      scanf("%d%d",&p,&f);
      l=get_kth(p-1);
      r=get_kth(p+f);
      splay(l,0);
      splay(r,root);
      del(K);
      pre[K]=0;
      K=0;
      pushup(ch[root][1]);
      pushup(root);
    }
    else if (str[0]=='R')
    {
      int l,r,p,f;
      scanf("%d%d",&p,&f);
      l=get_kth(p-1);
      r=get_kth(p+f);
      splay(l,0);
      splay(r,root);
      update_rev(K);
      pushup(ch[root][1]);
      pushup(root);
    }
    else if (str[0]=='G')
    {
      int l,r,p,f;
      scanf("%d%d",&p,&f);
      l=get_kth(p-1);
      r=get_kth(p+f);
      splay(l,0);
      splay(r,root);
      printf("%d\n",sum[K]);
    }
    else if (str[2]=='K')
    {
      int p,l,r,f,k;
      scanf("%d%d%d",&p,&f,&k);
      l=get_kth(p-1);
      r=get_kth(f+p);
      splay(l,0);
      splay(r,root);
      update_set(K,k);
      pushup(ch[root][1]);
      pushup(root);
    }
    else
    {
      int l,r;
      l=0;
      r=sz[root]-1;
      l=get_kth(l);
      r=get_kth(r);
      splay(l,0);
      splay(r,root);
      printf("%d\n",mn[K]);
    }
  }
  return 0;
}
