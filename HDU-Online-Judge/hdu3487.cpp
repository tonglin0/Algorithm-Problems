#include<cstdio>
#include<vector>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define MN 600100
#define K ch[ch[root][1]][0]
using namespace std;

int root,tot;
vector<int> anss;
int pre[MN],key[MN],ch[MN][2],rev[MN],sz[MN];
char st[10];
int n;

void newnode(int &r,int fa,int k)
{
  r=++tot;
  pre[r]=fa;
  ch[r][0]=ch[r][1]=0;
  rev[r]=0;
  key[r]=k;
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

int get_min(int r)
{
  pushdown(r);
  while(ch[r][0])
  {
    r=ch[r][0];
    pushdown(r);
  }
  return r;
}

void insert(int x,int p)
{
  int r=get_kth(p);
  splay(r,0);
  int tmp=get_min(ch[r][1]);
  splay(tmp,root);
  ch[tmp][0]=x;
  pre[x]=tmp;
  pushup(tmp);
  pushup(root);
}

void init()
{
  tot=root=0;
  ch[0][0]=ch[0][1]=key[0]=pre[0]=sz[0]=rev[0]=0;
  newnode(root,0,-1);
  newnode(ch[root][1],root,-1);
  sz[root]=2;
  build(K,1,n,ch[root][1]);  
}

void PRINT(int r)
{
  pushdown(r);
  if (ch[r][0])
    PRINT(ch[r][0]);
  if (key[r]!=-1)
    anss.push_back(key[r]);//printf("%d ",key[r]);
  if (ch[r][1])
    PRINT(ch[r][1]);
}

int main()
{
  freopen("3487.in","r",stdin);
  freopen("3487.out","w",stdout);
  int i,j,k,m;
  while(scanf("%d%d",&n,&m)==2&&n!=-1)
  {
    init();
    anss.clear();
    while(m--)
    {
      scanf("%s",st);
      if (st[0]=='C')
      {
        int l,r,p;
        scanf("%d%d%d",&l,&r,&p);
        l=get_kth(l-1);
        r=get_kth(r+1);
        splay(l,0);
        splay(r,root);
        int x=K;
        pre[K]=0;
        ch[ch[root][1]][0]=0;
        pushup(ch[root][1]);
        pushup(root);
        insert(x,p);
      }
      else
      {
        int l,r;
        scanf("%d%d",&l,&r);
        l=get_kth(l-1);
        r=get_kth(r+1);
        splay(l,0);
        splay(r,root);
        rev[K]^=1;
        swap(ch[K][0],ch[K][1]);
      }
    }
    PRINT(root);
    printf("%d",anss[0]);
    for(i=1;i<anss.size();i++)
      printf(" %d",anss[i]);
    printf("\n");
  }
  return 0;
}
