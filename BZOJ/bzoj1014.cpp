#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<vector>
#include<queue>
#include<string>
#include<map>
#include<cctype>
#include<algorithm>
#define INF (int)1e9
#define lint long long
#define llu unsigned long long
#define eps 1e-8
#define MN 200009
#define HS 29
#define K ch[ch[root][1]][0]
using namespace std;

int key[MN];
int sz[MN],ch[MN][2],pre[MN];
llu hs[MN];
int tot=0;
char st[MN];
int root;
llu f[MN];
int len;

void newnode(int &r,int fa,int k)
{
  r=++tot;
  pre[r]=fa;
  ch[r][0]=ch[r][1]=0;
  sz[r]=1;
  hs[r]=key[r]=k;
}

void pushup(int p)
{
  sz[p]=sz[ch[p][0]]+sz[ch[p][1]]+1;
  hs[p]=hs[ch[p][0]]+(llu)key[p]*f[sz[ch[p][0]]]+hs[ch[p][1]]*f[sz[ch[p][0]]+1];
}

void build(int &x,int l,int r,int fa)
{
  int mid=(l+r)>>1;
  newnode(x,fa,st[mid]);
  if (l<mid)
    build(ch[x][0],l,mid-1,x);
  if (r>mid)
    build(ch[x][1],mid+1,r,x);
  pushup(x);
}

void init()
{
  f[0]=1;
  for (int i=1;i<=100001;i++)
    f[i]=f[i-1]*HS;
  newnode(root,0,0);
  newnode(ch[root][1],root,0);
  pushup(root);
  scanf("%s",st);
  len=strlen(st);
  build(ch[ch[root][1]][0],0,len-1,ch[root][1]);
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
  ch[x][kind]=y;
  pre[y]=x;
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
      int kind=ch[pre[y]][0]==y;
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
  if (goal==0)
    root=x;
  pushup(x);
}

int get_kth(int k)
{
  int r=root;
  while(r)
  {
    if (sz[ch[r][0]]==k)
      return r;
    else if (sz[ch[r][0]]>k)
      r=ch[r][0];
    else
    {
      k-=sz[ch[r][0]]+1;
      r=ch[r][1];
	}
  }
}

int main()
{
  freopen("1014.in","r",stdin);
  freopen("1014.out","w",stdout);
  int n,i,j,k,m,ii=0,ca;
  init();
  int qus;
  scanf("%d",&qus);
  while(qus--)
  {
    char op[3];
    scanf("%s",op);
    if (op[0]=='R')
    {
      int x;
      scanf("%d",&x);
      x=get_kth(x);
      char isn[3];
      scanf("%s",isn);
      splay(x,0);
      key[x]=isn[0];
      pushup(x);
	}
    else if (op[0]=='Q')
    {
      int x,y;
      scanf("%d%d",&x,&y);
      int l=0,r=min(len-x+1,len-y+1);
      int xx=get_kth(x-1);
      int yy=get_kth(y-1);
	  while(l<r)
      {
        int mid=(l+r+1)>>1;
        int xx2=get_kth(x+mid);
        splay(xx,0);
        splay(xx2,root);
		int tmp=hs[K];
        int yy2=get_kth(y+mid);
        splay(yy,0);
        splay(yy2,root);
        int tmp2=hs[K];
        if (tmp==tmp2)
          l=mid;
        else
          r=mid-1;
	  }
	  printf("%d\n",l);
	}
	else
	{
	  int x;char isn[3];
	  scanf("%d",&x);
	  scanf("%s",isn);
	  int l=get_kth(x);
	  int r=get_kth(x+1);
	  splay(l,0);
	  splay(r,root);
	  newnode(ch[r][0],r,isn[0]);
	  pushup(r);
	  pushup(l);
	  len++;
	}
  }
  return 0;
}

