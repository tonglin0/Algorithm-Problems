#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define MN 200009
using namespace std;

int pre[MN],ch[MN][2],sz[MN],cnt[MN],key[MN];
struct node{int ns,k,s,id;};
node qu[MN];
char str[4];
int root,tot;

bool cmp1(node a,node b){return a.s<b.s;}
bool cmp2(node a,node b){return a.id<b.id;}

void newnode(int &r,int fa,int k)
{
  r=++tot;
  pre[r]=fa;
  cnt[r]=1;
  sz[r]=1;
  ch[r][1]=ch[r][0]=0;
  key[r]=k;
}

void pushup(int x)
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

void insert(int k)
{
  if (!root)
  {
    newnode(root,0,k);
    return ;
  }
  int r=root;
  while(ch[r][k>key[r]])
    r=ch[r][k>key[r]];
  newnode(ch[r][k>key[r]],r,k);
  splay(ch[r][k>key[r]],0);
}

/*int find(int k)
{
  int r=root;
  while(r)
  {
    if (key[r]==k)
    {
      splay(r,0);
      return r;
    }
    r=ch[r][k>key[r]];
  }
}*/

int join(int rt,int s1,int s2)
{
  sz[rt]=cnt[rt];
  ch[rt][0]=ch[rt][1]=0;
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

void del()
{
  root=join(root,ch[root][0],ch[root][1]);
  pre[root]=0;
  pushup(root);
}

void insert_top(int k)
{
  if (!root)
  {
    root=k;
    return ;
  }
  int r=root;
  while(ch[r][0])
    r=ch[r][0];
  ch[r][0]=k;
  pre[k]=r;
  splay(k,0);
}

int query(int k)
{
  splay(k,0);
  return sz[ch[k][0]];
}

int get_kth(int k)
{
  int r=root;
  while(r)
  {
    int t=sz[ch[r][0]]+cnt[r];
    if (sz[ch[r][0]]<k&&t>=k)
      return key[r]+k-sz[ch[r][0]]-1;
    if (sz[ch[r][0]]>=k)
      r=ch[r][0];
    else
    {
      k-=(sz[ch[r][0]]+cnt[r]);
      r=ch[r][1];
    }
  }
}

int main()
{
  freopen("3436.in","r",stdin);
  freopen("3436.out","w",stdout);
  int n,i,j,T,ii,k,m;
  scanf("%d",&T);
  for (ii=1;ii<=T;ii++)
  {
    printf("Case %d:\n",ii);
    memset(ch,0,sizeof(ch));
    memset(pre,0,sizeof(pre));
    memset(key,0,sizeof(key));
    memset(sz,0,sizeof(sz));
    memset(cnt,0,sizeof(cnt));
    scanf("%d%d",&n,&m);
    root=tot=0;
    for (i=1;i<=m;i++)
    {
      scanf("%s%d",str,&k);
      if (str[0]=='T')
      {
        node tmp;
        tmp.k=1;tmp.s=k;tmp.id=i;
        qu[i]=tmp;
      }
      else if (str[0]=='Q')
      {
        qu[i].k=2;
        qu[i].s=k;
        qu[i].id=i;
      }
      else
      {
        qu[i].k=3;
        qu[i].s=k;
        qu[i].id=i;
      }
    }
    sort(qu+1,qu+m+1,cmp1);
    //for (i=1;i<=m;i++)
      //printf("k=%d s=%d\n",qu[i].k,qu[i].s);
    //return 0;
    int pre=-1;
    for (i=1;i<=m;i++)
      if (qu[i].k!=3)
        break;
    if (i>m||qu[i].s>1)
    {
      insert(1);
      if (i<=m)
        cnt[tot]=qu[i].s-1;
      else
        cnt[tot]=n;
      pushup(tot);
    }
    for (i=1;i<=m;i++)
      if (qu[i].k!=3&&qu[i].s!=pre)
      {
        if (pre!=-1&&qu[i].s-pre>1)
        {
          insert(pre+1);
          cnt[tot]=qu[i].s-pre-1;
          pushup(tot);
          qu[i].ns=tot;
        }
        insert(qu[i].s);
        //cnt[tot]=1;
        pushup(tot);
        pre=qu[i].s;
        qu[i].ns=tot;
      }
      else if (qu[i].k!=3)
        qu[i].ns=tot;
    for (i=m;i>=1;i--)
      if (qu[i].k!=3)
        break;
    if (i>0&&qu[i].s<n)
    {
      insert(qu[i].s+1);
      cnt[tot]=n-qu[i].s;
      pushup(tot);
    }
    sort(qu+1,qu+1+m,cmp2);
    //for (i=1;i<=m;i++)
      //printf("k=%d s=%d ns=%d\n",qu[i].k,qu[i].s,qu[i].ns);
    //return 0;
    for (i=1;i<=m;i++)
    {
      if (qu[i].k==1)
      {
        splay(qu[i].ns,0);//int tmp=find(qu[i].s);
        del();
        insert_top(qu[i].ns);
      }
      else if (qu[i].k==2)
        printf("%d\n",query(qu[i].ns)+1);
      else 
        printf("%d\n",get_kth(qu[i].s));
    }
  }
  return 0;
}
