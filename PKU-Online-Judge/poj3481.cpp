#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define MN 2000100
using namespace std;

int pre[MN],ch[MN][2],id[MN],key[MN];
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

void insert(int k)
{
  if (!root)
  {
    newnode(root,0,k);
    return ;
  }
  int r=root;
  while(ch[r][key[r]<k])
    r=ch[r][key[r]<k];
  newnode(ch[r][key[r]<k],r,k);
  splay(ch[r][key[r]<k],0);
}

int join(int s1,int s2)
{
  if (s1==0) return s2;
  if (s2==0) return s1;
  int r=s1;
  while(ch[r][1])
    r=ch[r][1];
  ch[r][1]=s2;
  pre[s2]=r;
  pre[s1]=0;
  splay(r,0);
  return r;
}

void del(int r)
{
  root=join(ch[r][0],ch[r][1]);
  pre[root]=0;
}

int get_max(int r)
{
  while(ch[r][1])
    r=ch[r][1];
  splay(r,0);
  return id[r];
}

int get_min(int r)
{
  while(ch[r][0])
    r=ch[r][0];
  splay(r,0);
  return id[r];
}

int main()
{
  freopen("3481.in","r",stdin);
  freopen("3481.out","w",stdout);
  int n,i,sum=0,j,k,m;
  tot=root=0;
  scanf("%d",&k);
  while(k)
  {
    if (k==1)
    {
      scanf("%d%d",&i,&j);
      insert(j);
      id[tot]=i;
      sum++;
    }
    else if (k==2)
    {
      if (sum==0)
      {
        printf("0\n");
        scanf("%d",&k);
        continue;
      }
      printf("%d\n",get_max(root));
      del(root);
      sum--;
    }
    else
    {
      if (sum==0)
      {
        printf("0\n");
        scanf("%d",&k);
        continue;
      }
      printf("%d\n",get_min(root));
      del(root);
      sum--;
    }
    scanf("%d",&k);
  }
  return 0;
}
