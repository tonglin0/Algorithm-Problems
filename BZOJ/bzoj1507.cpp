#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#define MN 4*1024*1024+9
using namespace std;

int pre[MN],ch[MN][2],sz[MN];
char key[MN];
int root,tot;
int p;
char str[MN];
char op[30];
string ss;

void newnode(int &r,int fa,char k)
{
  r=++tot;
  key[r]=k;
  pre[r]=fa;
  ch[r][0]=ch[r][1]=0;
  sz[r]=1;
}

void pushup(int x)
{
  sz[x]=sz[ch[x][0]]+sz[ch[x][1]]+1;
}

void init()
{
  root=tot=0;
  ch[0][0]=ch[0][1]=pre[0]=sz[0]=0;
  newnode(root,0,' ');
  newnode(ch[root][1],root,' ');
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
  newnode(x,fa,ss[mid]);
  if (l<mid)
    build(ch[x][0],l,mid-1,x);
  if (r>mid)
    build(ch[x][1],mid+1,r,x);
  pushup(x);
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

void output(int r)
{
  if (ch[r][0])
    output(ch[r][0]);
  printf("%c",key[r]);
  if (ch[r][1])
    output(ch[r][1]);
}

int main()
{
  freopen("1507.in","r",stdin);
  freopen("1507.out","w",stdout);
  int n,i,j,k,m;
  scanf("%d",&m);
  init();
  p=0;
  while(m--)
  {
    scanf("%s",op);
    if (op[0]=='I')
    {
      scanf("%d",&n);
      ss="";
      int len=n;
      gets(str);
      while(n>0)
      {
        //gets(str);
        gets(str);
        n-=strlen(str);
        ss=ss+str;
      }
      int l=get_kth(p);
      int r=get_kth(p+1);
      splay(l,0);
      splay(r,root);
      build(ch[r][0],0,len-1,r);
    }
    else if (op[0]=='M')
    {
      scanf("%d",&k);
      p=k;
    }
    else if (op[0]=='P')
      p--;
    else if (op[0]=='N')
      p++;
    else if (op[0]=='D')
    {
      scanf("%d",&k);
      int l=get_kth(p);
      int r=get_kth(p+k+1);
      splay(l,0);
      splay(r,root);
      pre[ch[r][0]]=0;
      ch[r][0]=0;
      pushup(r);
      pushup(root);
    }
    else
    {
      scanf("%d",&k);
      int l=get_kth(p);
      int r=get_kth(p+k+1);
      splay(l,0);
      splay(r,root);
      output(ch[r][0]);
      printf("\n");
    }
  }
  return 0;
}
