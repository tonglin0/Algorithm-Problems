#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define MOD 1000000
#define MN 160010
using namespace std;

int pre[MN],ch[MN][2],key[MN];
int root,tot;

void newnode(int &r,int fa,int k)
{
  r=++tot;
  pre[r]=fa;
  key[r]=k;
  ch[r][0]=ch[r][1]=0;
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
  if (goal==0)
    root=x;
}

int join(int s1,int s2)
{
  if (s1==0) return s2;
  if (s2==0) return s1;
  pre[s1]=0;
  int r=s1;
  while(ch[r][1])
    r=ch[r][1];
  splay(r,0);
  ch[r][1]=s2;
  pre[s2]=r;
  return r;
}

void del(int r)
{
  splay(r,0);
  root=join(ch[r][0],ch[r][1]);
  pre[root]=0;
}

int get_pre(int r)
{
  r=ch[r][0];
  if (!r) return -1;
  while(ch[r][1])
    r=ch[r][1];
  return r;
}

void insert(int k)
{
  int r=root;
  while(ch[r][k>key[r]])
    r=ch[r][k>key[r]];
  newnode(ch[r][k>key[r]],r,k);
  splay(ch[r][k>key[r]],0);
}

int get_next(int r)
{
  r=ch[r][1];
  if (!r) return -1;
  while(ch[r][0])
    r=ch[r][0];
  return r;
}

int main()
{
  freopen("1208.in","r",stdin);
  freopen("1208.out","w",stdout);
  int n,i,j,k,m,pre=-1;
  scanf("%d",&n);
  int sum=0;
  tot=root=0;
  int ans=0;
  for (i=1;i<=n;i++)
  {
    scanf("%d%d",&k,&m);
    if (sum==0)
    {
      newnode(root,0,m);
      pre=k;
      sum=1;
    }
    else if (k==pre)
    {
      insert(m);
      sum++;
    }
    else
    {
      insert(m);
      int l=get_pre(root);
      int r=get_next(root);
      if (l>0&&(r==-1||m-key[l]<=key[r]-m))
      {
        ans=(ans+m-key[l]+MOD)%MOD;
        del(root);
        splay(l,0);
        del(root);
      }
      else
      {
        ans=(ans+key[r]-m+MOD)%MOD;
        del(root);
        splay(r,0);
        del(root);
      }
      sum--;
      //pre=k;
    } 
  }
  printf("%d\n",ans);
  return 0;
}
