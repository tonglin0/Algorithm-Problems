#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MN 100010
#define LL long long
#define INF (int)1e9
#define M 1000000
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

void splay(int k,int goal)
{
  while(pre[k]!=goal)
  {
    if (pre[pre[k]]==goal)
      rotate(k,ch[pre[k]][0]==k);
    else
    {
      int y=pre[k];
      int kind=(ch[pre[y]][0]==y);
      if (ch[y][kind]==k)
      {
        rotate(k,!kind);
        rotate(k,kind);
      }
      else
      {
        rotate(y,kind);
        rotate(k,kind);
      }
    }
  }
  if (goal==0)
    root=k;
}

void insert(int k)
{
  int r=root;
  while(ch[r][key[r]<k])
    r=ch[r][key[r]<k];
  newnode(ch[r][key[r]<k],r,k);
  splay(ch[r][key[r]<k],0);
}

int get_pre(int r,int &t)
{
  t=ch[r][0];
  if (t==0)
  {
    t=r;
    return -1;
  }
  while(ch[t][1])
    t=ch[t][1];
  return key[t];
}

int get_next(int r,int &t)
{
  t=ch[r][1];
  if (t==0)
  {
    t=r;
    return -1;
  }
  while(ch[t][0])
    t=ch[t][0];
  return key[t];
}

int join(int s1,int s2)
{
  if (s1==0) return s2;
  if (s2==0) return s1;
  int t1=s1;
  //pre[s1]=0;
  //get_pre(s1,t1);
  while(ch[t1][1]) t1=ch[t1][1];
  //splay(t1,0);
  ch[t1][1]=s2;
  pre[s2]=t1;
  return s1;
}

void del(int x)
{
  splay(x,0);
  root=join(ch[x][0],ch[x][1]);
  pre[root]=0;
}

int main()
{
  freopen("1285.in","r",stdin);
  freopen("1285.out","w",stdout);
  int n,i,kind,j,k,m;
  int sum=0;
  int ans=0;
  int pre;
  tot=0;root=0;
  scanf("%d",&n);
  for (i=1;i<=n;i++)
  {
    scanf("%d%d",&kind,&k);
    if (sum==0)
    {
      newnode(root,0,k);
      pre=kind; 
      sum++;
      continue;
    }
    else if (kind!=pre)
    {
      //pre=kind;
      insert(k);
      sum--;
      int a,b,t1,t2;
      a=get_pre(root,t1);
      b=get_next(root,t2);
      if (a>=0&&(b<0||k-a<=b-k))
      {
        ans=(ans+(k-a)%M)%M;
        del(root);
        del(t1);
      }
      else
      {
        ans=(ans+(b-k)%M)%M;
        del(root);
        del(t2);
      }
    }
    else
    {
      insert(k);
      sum++;
    }
  }
  printf("%d\n",ans);             // del tot--
  return 0;
}
