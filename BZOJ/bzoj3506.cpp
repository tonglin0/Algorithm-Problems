#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define MN 100009
using namespace std;

struct node{
	int s,id;
};
bool cmp(node a,node b){if (a.s!=b.s) return a.s<b.s;return a.id<b.id;}
node b[MN];
int a[MN];
int ch[MN][2],pre[MN],sz[MN];
int rev[MN];
int root;

void pushup(int x)
{
  sz[x]=sz[ch[x][0]]+sz[ch[x][1]]+1;
}

void newnode(int &r,int fa,int k)
{
  r=k;
  ch[r][0]=ch[r][1]=0;
  pre[r]=fa;
  rev[r]=0;
  sz[r]=1;
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

void revall(int x)
{
  if (x!=0)
  {
    rev[x]^=1;
    swap(ch[x][0],ch[x][1]);
  }
}

void pushdown(int x)
{
  if (rev[x])
  {
    revall(ch[x][0]);
    revall(ch[x][1]);
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
  ch[r][1]=s2;
  pre[s2]=r;
  pre[s1]=0;
  return s1;
}

void del()
{
  root=join(ch[root][0],ch[root][1]);
  pre[root]=0;
}

int main()
{
  freopen("3506.in","r",stdin);
  freopen("3506.out","w",stdout);
  int n,i,j,k,m;
  scanf("%d",&n);
  for (i=1;i<=n;i++)
  {
    scanf("%d",&b[i].s);
    b[i].id=i;
  }
  sort(b+1,b+n+1,cmp);
  for (i=1;i<=n;i++)
    a[b[i].id]=i;
  ch[0][0]=rev[0]=ch[0][1]=sz[0]=pre[0]=0;
  build(root,1,n,0);
  for (i=1;i<=n-1;i++)
  {
    splay(i,0);
    printf("%d ",sz[ch[root][0]]+i);
    revall(ch[root][0]);
	del();
  }
  printf("%d\n",n);
  return 0;
}
