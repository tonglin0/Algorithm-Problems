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
#define MN 1000009
using namespace std;

int ch[MN][2],pre[MN],sz[MN],key[MN],tms[MN];
int root=0;
int tot=0;

void newnode(int &r,int fa,int k)
{
  r=++tot;
  pre[r]=fa;
  key[r]=k;
  ch[r][0]=ch[r][1]=0;
  sz[r]=tms[r]=1;
}

void pushup(int x)
{
  sz[x]=sz[ch[x][0]]+sz[ch[x][1]]+tms[x];
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
}

bool find(int x)
{
  int r=root;
  if (key[r]==x)
  {
    sz[r]++;
    tms[r]++;
    return true;
  }
  while(r)
  {
    if (key[r]==x)
    {
      splay(r,0);
      sz[r]++;
      tms[r]++;
      return true;
	}
	r=ch[r][key[r]<x];
  }
  return false;
}


void insert(int k)
{
  int r=root;
  while(ch[r][key[r]<k])
  {
	sz[r]++;
	r=ch[r][key[r]<k];
  }
  newnode(ch[r][key[r]<k],r,k);
  pushup(r);
  splay(ch[r][key[r]<k],0);
}

int get(int k)
{
  int r=root;
  while(r)
  {
    if (key[r]==k)
      return r;
    r=ch[r][key[r]<k];
  }
}

int join(int s1,int s2)
{
  if (s1==0) return s2;
  if (s2==0) return s1;
  int t=s1;
  while(ch[t][1])
    t=ch[t][1];
  pre[s1]=0;
  splay(t,0);
  ch[t][1]=s2;
  pushup(t);
  pre[s2]=t;
  return t;
}

void del(int x)
{
  splay(x,0);
  root=join(ch[x][0],ch[x][1]);
  pre[root]=0;
}

int get_kth(int k)
{
  int r=root;
  while(r)
  {
    if (sz[ch[r][0]]<=k-1&&sz[ch[r][0]]+tms[r]>=k)
      return r;
    else if (sz[ch[r][0]]>k-1)
      r=ch[r][0];
    else
    {
      k-=sz[ch[r][0]]+tms[r];
      r=ch[r][1];
	}
  }
}

int get_pre()
{
  int r=ch[root][0];
  while(ch[r][1])
    r=ch[r][1];
  return r;
}

int get_next()
{
  int r=ch[root][1];
  while(ch[r][0])
    r=ch[r][0];
  return r;
}

int main()
{
  freopen("3224.in","r",stdin);
  freopen("3224.out","w",stdout);
  int n,i,j,k,m,ii=0,ca;
  scanf("%d",&n);
  for (i=1;i<=n;i++)
  {
    int op;
    int x;
    scanf("%d%d",&op,&x);
    if (op==1)
    {
      if (!root)
        newnode(root,0,x);
      else
        if (!find(x))
		  insert(x);
	}
	else if (op==2)
	{
	  int r=get(x);
	  splay(r,0);
	  if (tms[r]>1)
	  {
	    tms[r]--;
	    sz[r]--;
	  }
	  else
	    del(r);
	}
	else if (op==3)
	{
	  int r=get(x);
	  splay(r,0);
	  printf("%d\n",sz[ch[r][0]]+1);
	}
	else if (op==4)
	{
	  int r=get_kth(x);
	  printf("%d\n",key[r]);
	}
	else if (op==5)
	{
	  if (!find(x))
	    insert(x);
	  int r=get_pre();
	  printf("%d\n",key[r]);
	  r=get(x);
	  splay(r,0);
	  if (tms[r]>1)
	  {
	    tms[r]--;
	    sz[r]--;
	  }
	  else
	    del(r);
	}
	else
	{
	  if (!find(x))
	    insert(x);
	  int r=get_next();
	  printf("%d\n",key[r]);
	  r=get(x);
	  splay(r,0);
	  if (tms[r]>1)
	  {
	    tms[r]--;
	    sz[r]--;
	  }
	  else
	    del(r);
	}
  }
  return 0;
}

