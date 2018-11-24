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
#define MN 500009
using namespace std;

int tc[250009][26];
int ch[MN][2],tms[MN],key[MN],pre[MN],sz[MN];
char ns[250009][11];
int root=0;
int tot=0,tri=0;
int val[250009];
bool first;

void pushup(int p)
{
  sz[p]=sz[ch[p][0]]+sz[ch[p][1]]+1;
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
  if (goal==0) 
    root=x;
}

void insert(int x)
{
  int r=root;
  if (!r)
  {
    root=x;
    ch[x][0]=ch[x][1]=0;
    pre[x]=0;
    sz[x]=1;
    return ;
  }
  int op;
  if (key[x]>key[r]||(key[x]==key[r]&&tms[x]<tms[r]))
    op=0;
  else
    op=1;
  while(ch[r][op])
  {
    r=ch[r][op];
    if (key[x]>key[r]||(key[x]==key[r]&&tms[x]<tms[r]))
      op=0;
    else
      op=1;
  }
  ch[r][op]=x;
  pre[x]=r;
  sz[x]=1;
  pushup(r);
  ch[x][0]=ch[x][1]=0;
  splay(x,0);
  //  need pushup all?
}

bool trie_get(char *s,int &r)
{
  int len=strlen(s);
  int u=0;
  for (int i=1;i<len;i++)
  {
    int c=s[i]-'A';
    if (!tc[u][c])
    {
      tc[u][c]=++tri;
      memset(tc[tri],0,sizeof(tc[tri]));
      val[tri]=0;
	}
	u=tc[u][c];
  }
  if (val[u])
  {
    r=val[u];
	return true;
  }
  else
  {
    r=++tot;
    val[u]=r;
    for (int i=1;i<len;i++)
      ns[r][i-1]=s[i];
    ns[r][len-1]=0;
    return false;
  }
}

int join(int s1,int s2)
{
  if (s1==0) return s2;
  if (s2==0) return s1;
  int r=s1;
  while(ch[r][1])
    r=ch[r][1];
  pre[s1]=0;
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
}

int get_kth(int k)
{
  int r=root;
  while(r)
  {
    if (sz[ch[r][0]]==k-1)
      return r;
    else if (sz[ch[r][0]]>k-1)
      r=ch[r][0];
    else
    {
      k-=sz[ch[r][0]]+1;
      r=ch[r][1];
	}
  }
}

void PRINT(int r)
{
  if (!r)
    return ;
  if (ch[r][0])
    PRINT(ch[r][0]);
  printf(" %s",ns[r]);
  if (ch[r][1])
    PRINT(ch[r][1]);
}

int main()
{
  freopen("1862.in","r",stdin);
  freopen("1862.out","w",stdout);
  int n,i,j,k,m,ii=0,ca;
  int qus;
  n=0;
  scanf("%d",&qus);
  for (ii=1;ii<=qus;ii++)
  {
    char op[14];
    scanf("%s",op);
    if (op[0]=='+')
    {
      int r=0;
      int x;
      scanf("%d",&x);
      if (trie_get(op,r))
      {
        splay(r,0);
        del(r);
        key[r]=x;
        tms[r]=ii;
        insert(r);
	  }
	  else
	  {
	    n++;
		key[r]=x;
	    tms[r]=ii;
	    insert(r);
	  }
	}
	else if (op[1]>='0'&&op[1]<='9')
	{
	  int d=0;
	  int len=strlen(op);
	  for (i=1;i<len;i++)
	    d=d*10+op[i]-'0';
	  /*for (i=d;i<=min(d+9,n);i++)
	  {
	    int r=get_kth(i);
	    if (first)
	    {
	      printf("%s",ns[r]);
	      first=false;
		}
		else
		  printf(" %s",ns[r]);
	  }*/
	  int l=get_kth(d);
	  printf("%s",ns[l]);
	  int r=get_kth(min(d+9,n));
	  if (l==r)
	  {
	    printf("\n");
		continue;
	  }
	  splay(l,0);
	  splay(r,root);
	  PRINT(ch[ch[root][1]][0]);
	  printf(" %s",ns[r]);
	  printf("\n");
	}
	else
	{
	  int r;
	  trie_get(op,r);
	  splay(r,0);
	  printf("%d\n",sz[ch[root][0]]+1);
	}
  }
  return 0;
}

