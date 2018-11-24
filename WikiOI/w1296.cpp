#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define INF (int)1e9
#define MN 100009
using namespace std;


int key[MN],ch[MN][2],pre[MN];
int root=0,tot=0;

void newnode(int &r,int fa,int k)
{
  r=++tot;
  key[r]=k;
  pre[r]=fa;
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
  ch[x][kind]=y;
  pre[y]=x;
}

void splay(int r,int fa)
{
  while(pre[r]!=fa)
  {
    if (pre[pre[r]]==fa)
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
  if (fa==0)
    root=r;
}

int insert(int k)
{
  int r=root;
  while(ch[r][key[r]<k])
  {
    if (key[r]==k)
    {
      splay(r,0);
      return 0;
    }
    r=ch[r][key[r]<k];
  }
  newnode(ch[r][key[r]<k],r,k);
  splay(ch[r][key[r]<k],0);
  return 1;
}

int get_pre(int x)
{
  int tmp=ch[x][0];
  if (tmp==0)
    return INF;
  while(ch[tmp][1])
    tmp=ch[tmp][1];
  return key[tmp];
}

int get_next(int x)
{
  int t=ch[x][1];
  if (t==0)
    return INF;
  while(ch[t][0])
    t=ch[t][0];
  return key[t];
}

int main()
{
  freopen("1296.in","r",stdin);
  freopen("1296.out","w",stdout);
  int n,i,j,k,m;
  memset(pre,0,sizeof(pre));
  memset(key,0,sizeof(key));
  memset(ch,0,sizeof(ch));
  int ans=0;
  scanf("%d",&n);
  for (i=1;i<=n;i++)
  {
    if (scanf("%d",&k)==EOF)
      k=0;
    if (i==1)
    {
      newnode(root,0,k);
      ans+=k;
      continue;
    }
    if (insert(k)==0) continue;
    int a=abs(k-get_pre(root));
    int b=abs(get_next(root)-k);
    ans+=min(a,b);    
  }
  printf("%d\n",ans);
  return 0;
} 
