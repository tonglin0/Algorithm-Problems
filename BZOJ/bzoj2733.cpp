#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<string>
#include<ctime>
#define INF (int)1e9
#define lint long long
#define eps 1e-8
#define MN 100009
using namespace std;

int key[MN],ch[MN][2],fa[MN],rank[MN],pre[MN];
int sz[MN];
char cha;

void read(int &x)
{
  while(cha=getchar(),cha<'0'||cha>'9');
  x=cha-'0';
  while(cha=getchar(),cha<='9'&&cha>='0') x=x*10+cha-'0';
}

void pushup(int r)
{
  sz[r]=sz[ch[r][0]]+sz[ch[r][1]]+1;
}

int find(int x)
{
  if (fa[x]==x)
    return x;
  fa[x]=find(fa[x]);
  return fa[x];
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
  pushup(x);
}

void insert(int u,int v)
{
  int r=v;
  while(ch[v][key[v]<key[u]])
    v=ch[v][key[v]<key[u]];
  ch[v][key[v]<key[u]]=u;
  pre[u]=v;
  pushup(v);
  splay(u,0);
}

int get_kth(int r,int k)
{
  splay(r,0);
  while(r)
  {
    if (sz[ch[r][0]]==k-1)
      return r;
    if (sz[ch[r][0]]>k-1)
      r=ch[r][0];
    else
    {
      k-=sz[ch[r][0]]+1;
      r=ch[r][1];
    }
  }
}

void merge(int u,int v)
{
  if (!u)
    return ;
  if (ch[u][0])
    merge(ch[u][0],v);
  ch[u][0]=0;
  if (ch[u][1])
    merge(ch[u][1],v);
  ch[u][1]=0;
  sz[u]=1;
  insert(u,v);
}

int main()
{
  freopen("2733.in","r",stdin);
  freopen("2733.out","w",stdout);
  int n,i,j,k,m,ca,ii=0;
  read(n);read(m);
  for (i=1;i<=n;i++)
    read(key[i]);
  for (i=1;i<=n;i++)
  {
    sz[i]=1;
    fa[i]=i;
    rank[i]=1;
    ch[i][0]=ch[i][1]=0;
  }
  while(m--)
  {
    int u,v;
    read(u);read(v);
    u=find(u);v=find(v);
    if (u==v)
      continue;
    if (rank[u]>rank[v])
      swap(u,v);
    fa[u]=v;
    rank[v]+=rank[u];
    rank[u]=0;
    splay(u,0);
    splay(v,0);
    merge(u,v);
  }
  int qus;
  read(qus);
  while(qus--)
  {
    char op[3];
    scanf("%s",op);
    if (op[0]=='Q')
    {
      int u;
      read(u);read(k);
      u=find(u);
      if (rank[u]<k)
        printf("-1\n");
      else
        printf("%d\n",get_kth(u,k));
    }
    else
    {
      int u,v;
      read(u);read(v);
      u=find(u);v=find(v);
      if (u==v)
        continue;
      if (rank[u]>rank[v])
        swap(u,v);
      fa[u]=v;
      rank[v]+=rank[u];
      rank[u]=0;
      splay(u,0);
      splay(v,0);
      merge(u,v);
    }
  }
  return 0;
}
