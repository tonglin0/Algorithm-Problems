#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MN 200005
#define INF (int)1e9
using namespace std;

int key[MN],pre[MN],ch[MN][2],sz[MN],cnt[MN];
int root,tot;

void newnode(int &r,int fa,int k)
{
  r=++tot;
  pre[r]=fa;
  ch[r][0]=ch[r][1]=0;
  cnt[r]=sz[r]=1;
  key[r]=k;
}

void update(int x)
{
  sz[x]=sz[ch[x][0]]+sz[ch[x][1]]+cnt[x];
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
  update(y);
  update(x);
}

void splay(int r,int goal)
{
  while(pre[r]!=goal)
  {
    if (pre[pre[r]]==goal)
      rotate(r,ch[pre[r]][0]==r);
    else
    {
      int y=pre[r];
      int kind=(ch[pre[y]][0]==y);
      if (ch[y][kind]==r)
      {
        rotate(r,!kind);
        rotate(r,kind);
      }
      else
      {
        rotate(y,kind);
        rotate(r,kind);
      }
    }
  }
  if (goal==0)
    root=r;
}

void insert(int k)
{
  if (!root)
  {
    newnode(root,0,k);
    return ;
  }
  int r=root;
  int y=r;
  while(r)
  {
    y=r;
    if (key[r]==k)
    {
      splay(r,0);
      cnt[r]++;
      sz[r]++;
      return ;
    }
    r=ch[r][key[r]<k];
  }
  newnode(r,y,k);
  ch[y][key[y]<k]=r;
  splay(r,0);
}

int join(int s1,int s2)
{
  if (s1==0) return s2;
  if (s2==0) return s1;
  pre[s1]=0;
  int r=s1;
  while(ch[r][1])
    r=ch[r][1];
  pre[s2]=r;
  ch[r][1]=s2;
  splay(r,0);
  return r;
}

void del(int k)
{
  if (!root) return ;
  int r=root;
  int y=r;
  bool find=false;
  while(r)
  {
    y=r;
    if (key[r]==k)
    {
      if (cnt[r]>1)
      {
        splay(r,0);
        cnt[r]--;
        sz[r]--;
        return ;
      }
      find=true;
      break;
    }
    r=ch[r][key[r]<k];
  }
  if (find)
  {
    r=y;
    splay(r,0);
    root=join(ch[r][0],ch[r][1]); 
    pre[root]=0;
  }
}

int rankk(int k)
{
  int r=root;
  while(r)
  {
    if (key[r]==k)
      break;
    r=ch[r][k>key[r]];
  }
  splay(r,0);
  return sz[ch[r][0]]+1;
}

int find_kth(int k)
{
  int r=root;
  while(r)
  {
    int t=sz[ch[r][0]]+cnt[r];
    if (sz[ch[r][0]]<k&&t>=k)
    {
      splay(r,0);
      return key[r];
    }
    if (sz[ch[r][0]]>=k)
      r=ch[r][0];
    else
    {
      k-=t;
      r=ch[r][1];
    }
  }
}

int get_pre(int r)
{
  r=ch[r][0];
  while(ch[r][1])
    r=ch[r][1];
  return key[r];
}

int get_next(int r)
{
  r=ch[r][1];
  while(ch[r][0])
    r=ch[r][0];
  return key[r];
}

int main()
{
  freopen("3302.in","r",stdin);
  freopen("3302.out","w",stdout);
  int n,i,j,k,m;
  memset(ch,0,sizeof(ch));
  memset(pre,0,sizeof(pre));
  root=tot=0;
  scanf("%d",&n);
  for (i=1;i<=n;i++)
  {
    scanf("%d%d",&m,&k);
    if (m==1)
      insert(k);
    else if (m==2)
      del(k);
    else if (m==3)
      printf("%d\n",rankk(k));
    else if (m==4)
      printf("%d\n",find_kth(k));
    else if (m==5)
    {
      insert(k);
      printf("%d\n",get_pre(root));
      del(k);
    }
    else 
    {
      insert(k);
      printf("%d\n",get_next(root));
      del(k);
    }
  }
  return 0;
}
