#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstring>
#define MN 110005
#define LL long long
#define K ch[ch[root][1]][0]
using namespace std;

LL sum[MN],add[MN],val[MN];
int ch[MN][2],pre[MN],sz[MN];
int tot=0,root=0,n;
int a[MN];
char cha[4];

void newnode(int &r,int fa,int k)
{
  r=++tot;
  pre[r]=fa;
  val[r]=k;
  sum[r]=k;
  add[r]=0;
  sz[r]=1;
  ch[r][0]=ch[r][1]=0;
}

void pushup(int r)
{
  sz[r]=sz[ch[r][0]]+sz[ch[r][1]]+1;
  sum[r]=sum[ch[r][0]]+sum[ch[r][1]]+val[r];
}

void pushdown(int x)
{
  if (add[x])
  {
    val[x]+=add[x];
    int lc=ch[x][0];
    int rc=ch[x][1];
    add[lc]+=add[x];
    add[rc]+=add[x];
    sum[lc]+=(LL)(add[x]*sz[lc]);
    sum[rc]+=(LL)(add[x]*sz[rc]);
    add[x]=0;
  }
}

void rotate(int x,int kind)
{
  int y=pre[x];
  pushdown(x);
  pushdown(y);
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

void splay(int r,int goal)
{
  pushdown(r);
  while(pre[r]!=goal)
  {
    if (pre[pre[r]]==goal)
      rotate(r,ch[pre[r]][0]==r);
    else
    {
      int y=pre[r];
      int kind=(ch[pre[y]][0]==y);
      if (ch[y][kind]==r)
      {
        rotate(r,!kind);
        rotate(r,kind);
      }
      else
      {
        rotate(y,kind);
        rotate(r,kind);
      }
    }
  }
  pushup(r);
  if (goal==0)
    root=r;
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
  int i;
  for (i=0;i<n;i++)
    scanf("%d",&a[i]);
  ch[0][0]=ch[0][1]=pre[0]=sz[0]=0;  
  add[0]=sum[0]=0;  
  newnode(root,0,-1);
  newnode(ch[root][1],root,-1);
  sz[root]=2;
  build(K,0,n-1,ch[root][1]);
  pushup(ch[root][1]);
  pushup(root);
}

void rotateto(int k,int goal)
{
  int r=root;
  pushdown(r);
  while(sz[ch[r][0]]!=k)
  {
    if (sz[ch[r][0]]>k)
      r=ch[r][0];
    else
    {
      k-=(sz[ch[r][0]]+1);
      r=ch[r][1];
    }
    pushdown(r);
  }
  splay(r,goal);
}

void update(int l,int r)
{
  int k;
  scanf("%d",&k);
  rotateto(l-1,0);
  rotateto(r+1,root);
  add[K]+=k;
  sum[K]+=(LL)(sz[K]*k);
}

LL query(int l,int r)
{
  rotateto(l-1,0);
  rotateto(r+1,root);
  return sum[K];
}

int main()
{
  freopen("3468.in","r",stdin);
  freopen("3468.out","w",stdout);
  int i,j,k,m,x,y;
  memset(ch,0,sizeof(ch));
  memset(sz,0,sizeof(sz));
  scanf("%d%d",&n,&m);
  init();
  while(m--)
  {
    scanf("%s%d%d",cha,&x,&y);
    if (cha[0]=='Q')
      printf("%I64d\n",query(x,y));
    else
      update(x,y);
  }
  return 0;
}
