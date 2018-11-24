#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstring>
#define MN 160009
using namespace std;

int ch[MN][2],pre[MN],sz[MN];
int a[MN];
int root=0;
char str[10];

void newnode(int &r,int fa,int k)
{
  r=k;
  pre[r]=fa;
  ch[r][0]=ch[r][1]=0;
  sz[r]=1;
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
  while(pre[x]!=goal)
  {
    if (pre[pre[x]]==goal)
      rotate(x,ch[pre[x]][0]==x);
    else
    {
      int y=pre[x];
      int kind=(ch[pre[y]][0]==y);
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

int join(int s1,int s2)
{
  if (s1==0) return s2;
  if (s2==0) return s1;
  int r=s1;
  pre[s1]=0;
  while(ch[r][1])
    r=ch[r][1];
  splay(r,0);
  ch[r][1]=s2;
  pre[s2]=r;
  return r;
}

void del(int x)
{
  splay(x,0);
  root=join(ch[x][0],ch[x][1]);
  pre[root]=0;
  ch[x][0]=ch[x][1]=0;
}

int get_kth(int k)
{
  int r=root;
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
  }
}

int main()
{
  freopen("1861.in","r",stdin);
  freopen("1861.out","w",stdout);
  int n,i,j,k,m;
  scanf("%d%d",&n,&m);
  for (i=1;i<=n;i++)
    scanf("%d",&a[i]);
  pre[0]=sz[0]=ch[0][0]=ch[0][1]=0;
  newnode(root,0,n+1);
  newnode(ch[root][1],root,n+2);
  build(ch[ch[root][1]][0],1,n,ch[root][1]);
  while(m--)
  {
    scanf("%s",str);
    if (str[0]=='T')
    {
      scanf("%d",&k);
      splay(k,0);
      //int t=get_kth(1);
      del(k);
      splay(n+1,0);
      int t=get_kth(1);
      splay(t,root);
      ch[ch[root][1]][0]=k;
      pre[k]=ch[root][1];
      pushup(k);
      pushup(ch[root][1]);
      pushup(root);
    }
    else if (str[0]=='B')
    {
      scanf("%d",&k);
      splay(k,0);
      //int t=get_kth(n);
      del(k);
      splay(n+2,0);
      int t=get_kth(n-1);
      splay(t,root);
      ch[t][1]=k;
      pre[k]=t;
      pushup(k);
      pushup(t);
      pushup(root);
    }
    else if (str[0]=='I')
    {
      int x,op;
      scanf("%d%d",&x,&op);
      if (op==0) continue;
      splay(x,0);/*
      int t=get_kth(sz[ch[x][0]]+1+op);
      del(x);
      splay(t,0);*/
      if (op==-1)
      {
        int t1=get_kth(sz[ch[x][0]]-2);
        int t2=get_kth(sz[ch[x][0]]-1);
        del(x);
        splay(t1,0);
        splay(t2,root);
        ch[t2][0]=x;
        pre[x]=t2;
        pushup(x);
        pushup(t2);
        pushup(root);
      }
      else
      {
        int t1=get_kth(sz[ch[x][0]]+2);
        int t2=get_kth(sz[ch[x][0]]+1);
        del(x);
        splay(t1,0);
        splay(t2,root);
        ch[t2][1]=x;
        pre[x]=t2;
        pushup(x);
        pushup(t2);
        pushup(root);
      }
    }
    else if (str[0]=='A')
    {
      scanf("%d",&k);
      splay(k,0);
      printf("%d\n",sz[ch[root][0]]-1);
    }
    else
    {
      scanf("%d",&k);
      int t=get_kth(k);
      printf("%d\n",t);
    }
  }
  return 0;
}
