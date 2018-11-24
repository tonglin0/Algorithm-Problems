#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define MN 4000100
#define K ch[ch[root][1]][0]
using namespace std;

int ch[MN][2],pre[MN],rev[MN],sz[MN];
char key[MN];
int tot,root,n;
char st[MN];

void newnode(int &r,int fa,char k)
{
  r=++tot;
  pre[r]=fa;
  ch[r][0]=ch[r][1]=0;
  key[r]=k;
  rev[r]=0;
  sz[r]=1;
}

void pushdown(int x)
{
  if(rev[x])
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

void pushup(int x)
{
  sz[x]=sz[ch[x][0]]+sz[ch[x][1]]+1;
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

void init()
{
  root=tot=0;
  ch[0][0]=ch[0][1]=pre[0]=sz[0]=rev[0]=0;
  key[0]=' ';
  newnode(root,0,' ');
  newnode(ch[root][1],root,' ');
  //sz[root]=2;
  pushup(ch[root][1]);
  pushup(root);
}

int get_pre(int r)
{
  pushdown(r);
  r=ch[r][0];
  pushdown(r);
  while(ch[r][1])
  {
    r=ch[r][1];
    pushdown(r);
  }
  return r;
}

int get_next(int r)
{
  pushdown(r);
  r=ch[r][1];
  pushdown(r);
  while(ch[r][0])
  {
    r=ch[r][0];
    pushdown(r);
  }
  return r;
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

void build(int &x,int l,int r,int fa)
{
  if (l>r) return ;
  int mid=(l+r)>>1;
  newnode(x,fa,st[mid]);
  if (l<mid)
    build(ch[x][0],l,mid-1,x);
  if (r>mid)
    build(ch[x][1],mid+1,r,x);
  pushup(x);
}

void PRINT(int r)
{
  if (ch[r][0])
    PRINT(ch[r][0]);
  if (r!=1&&r!=2)
    printf("%c",key[r]);
  if (ch[r][1])
    PRINT(ch[r][1]);  
}

int main()
{
  freopen("1269.in","r",stdin);
  freopen("1269.out","w",stdout);
  int m,i,j,k,T;
  scanf("%d",&T);
  memset(ch,0,sizeof(ch));
  memset(pre,0,sizeof(pre));
  memset(sz,0,sizeof(sz));
  memset(rev,0,sizeof(rev));
  memset(key,0,sizeof(key));
  init();
  while(T--)
  {
    scanf("%s",st);
    if (st[0]=='I')
    {
      scanf("%d",&n);
      gets(st);
      gets(st);
      int r=get_next(root);
      splay(r,root);
      build(K,0,n-1,r);
      pushup(r);
      pushup(root);
    }
    else if (st[0]=='M')
    {
      scanf("%d",&k);
      int r=get_kth(k);
      splay(r,0);
    }
    else if (st[0]=='D')
    {
      scanf("%d",&k);
      int r=get_kth(sz[ch[root][0]]+k+1);
      splay(r,root);
      pre[K]=0;
      K=0;
      pushup(r);
      pushup(root);
    }
    else if (st[0]=='R')
    {
      scanf("%d",&k);
      int r=get_kth(sz[ch[root][0]]+k+1);
      splay(r,root);
      rev[K]^=1;
      swap(ch[K][0],ch[K][1]);
    }
    else if (st[0]=='P')
    {
      int r=get_pre(root);
      splay(r,0);
    }
    else if (st[0]=='N')
    {
      int r=get_next(root);
      splay(r,0);
    }
    else
    {
      int r=get_next(root);
      printf("%c\n",key[r]);
    }
  }
  return 0;
}
