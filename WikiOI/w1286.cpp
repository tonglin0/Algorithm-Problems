#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define MN 200200
#define INF (int)1e9
using namespace std;

int pre[MN],sz[MN],ch[MN][2],key[MN],cnt[MN];
int root,tot;
char st[4];
int ans=0;

void newnode(int &r,int fa,int k)
{
  r=++tot;
  pre[r]=fa;
  ch[r][0]=ch[r][1]=0;
  key[r]=k;
  cnt[r]=1;
  sz[r]=1;
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
  ch[x][kind]=y;
  pre[y]=x;
  update(y);
  update(x);
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
  update(x);
  if (goal==0)
    root=x;
}

void insert(int k)
{
  if (root==0)
  {
    newnode(root,0,k);
    return ;
  }
  int r=root;
  int y=r;
  while(r)
  {
    y=r;
    if (k==key[r])
    {
      
      splay(r,0);
      
      cnt[r]++;
      sz[r]++;
                           // a swap here
      return ;
    }
    if (k>key[r])
    {
      r=ch[r][1];
      //sz[r]++;
    }
    else
    {
      //sz[r]++;
      r=ch[r][0];
    }
  }
  splay(y,0);
  if (key[y]<k)
  {
    newnode(r,y,k);
    ch[r][1]=ch[y][1];
    pre[ch[y][1]]=r;
    ch[y][1]=r;
    update(r);
    update(y);
  }
  else
  {
    newnode(r,y,k);
    ch[r][0]=ch[y][0];
    pre[ch[y][0]]=r;
    ch[y][0]=r;
    update(r);
    update(y);
  }
  splay(r,0);
}

int find_kth(int k)
{
  int r=root;
  int y;
  while(r)
  {
    y=r;
    if ((sz[ch[r][0]]<k)&&(cnt[r]+sz[ch[r][0]]>=k))
    {splay(r,0);  return key[r];}
    if (sz[ch[r][0]]+cnt[r]>k)
    {
      r=ch[r][0];
    }
    else
    {
      k-=(cnt[r]+sz[ch[r][0]]);
      r=ch[r][1];
    }
  }
  splay(y,0);
  return key[y];
}

void debug(int r)
{
  if (!r) return ;

  printf("r=%d key=%d lc=%d rc=%d sz=%d cnt=%d\n",r,key[r],ch[r][0],ch[r][1],sz[r],cnt[r]);
  debug(ch[r][0]);  
  debug(ch[r][1]);
}

int main()
{
  freopen("1286.in","r",stdin);
  freopen("1286.out","w",stdout);
  int lim,delta=0,n,i,j,k,m;
  root=tot=0;
  memset(sz,0,sizeof(sz));
  memset(ch,0,sizeof(ch));
  scanf("%d%d",&n,&lim);
  for (i=1;i<=n;i++)
  {
    scanf("%s%d",st,&k);
    if (st[0]=='A')
      delta+=k;
    else if (st[0]=='I')
    {
      if (k<lim) continue;
      insert(k-delta);
      //sum++;
      ans++;
    }
    else if (st[0]=='S')
    {
      delta-=k;
      insert(lim-delta-1);
      //sum++;
      //sum-=sz[root];
      //ans+=(sz[root]-1);
      root=ch[root][1];
      pre[root]=0;
      //splay(root,0);
    }
    else
    {
      if (k>sz[root])
      {
        printf("-1\n");
        continue;
      }
      printf("%d\n",find_kth(sz[root]+1-k)+delta);
    }
  }
  //splay(root,0);
  //update(root);
  printf("%d\n",ans-sz[root]);
  //printf("\n");
  //debug(root);
  return 0;
}
