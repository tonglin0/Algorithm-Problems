#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<string>
#include<cmath>
#include<ctime>
#include<map>
#include<cctype>
#include<vector>
#include<queue>
#define lint long long
#define INF (int)1e9
#define eps 1e-8
using namespace std;

char ss[1005][1005];
int ch[500005][26];
int val[500005];
struct node{
	int a,b,k1,k2;
};
int next[1000005],last[1000005];
node anss[1005];
char st[1005];
int tot;
int fa[1005];
int lens[1005];

void insert(char *s,int k)
{
  int u=0;
  int len=strlen(s);
  for (int i=0;i<len;i++)
  {
    int c=s[i]-'A';
    if (!ch[u][c])
    {
      ch[u][c]=++tot;
      memset(ch[tot],0,sizeof(ch[tot]));
      val[tot]=0;
	}
	u=ch[u][c];
  }
  if (val[u])
    fa[val[u]]=k;
  val[u]=k;
}

void acgetfail()
{
  queue<int> q;
  next[0]=last[0]=0;
  for (int i=0;i<26;i++)
    if (ch[0][i])
    {
      q.push(ch[0][i]);
      next[ch[0][i]]=last[ch[0][i]]=0;
	}
  while(!q.empty())
  {
    int r=q.front();q.pop();
    for (int c=0;c<26;c++)
    {
      int u=ch[r][c];
      if (!u)
      {
        ch[r][c]=ch[next[r]][c];
        continue;
	  }
	  q.push(u);
	  int v=next[r];
	  next[u]=ch[v][c];
	  last[u]=val[next[u]]?next[u]:last[next[u]];
	}
  }
}

void myprint(int u,int st1,int st2,int p1,int p2,int i)
{
  node tmp;
  tmp.a=st1+p1*i;
  tmp.b=st2+p2*i;
  tmp.k1=-p1;tmp.k2=-p2;
  anss[val[u]]=tmp;
  if (last[u])
    myprint(last[u],st1,st2,p1,p2,i);
}

void getans(char* s,int st1,int st2,int p1,int p2)
{
  int u=0,len=strlen(s);
  for (int i=0;i<len;i++)
  {
    int c=s[i]-'A';
    u=ch[u][c];
    if (val[u])
      myprint(u,st1,st2,p1,p2,i);
    else if (last[u])
      myprint(last[u],st1,st2,p1,p2,i);
  }
}

char getdir(int p1,int p2)
{
  p1=-p1;p2=-p2;
  if (p1==-1&&p2==0)
    return 'A';
  else if(p1==-1&&p2==1)
    return 'B';
  else if (p1==0&&p2==1)
    return 'C';
  else if (p1==1&&p2==1)
    return 'D';
  else if (p1==1&&p2==0)
    return 'E';
  else if (p1==1&&p2==-1)
    return 'F';
  else if (p1==0&&p2==-1)
    return 'G';
  else if (p1==-1&&p2==-1)
    return 'H';
}

int main()
{
  freopen("1204.in","r",stdin);
  freopen("1204.out","w",stdout);
  int n,i,j,k,m,ca,ii=0;
  scanf("%d%d%d",&n,&m,&k);
  for (i=0;i<n;i++)
    scanf("%s",ss[i]);
  memset(val,0,sizeof(val));
  tot=0;
  for (i=0;i<=k;i++)
    fa[i]=i;
  memset(ch[0],0,sizeof(ch[0]));
  for (i=1;i<=k;i++)
  {
    scanf("%s",st);
    lens[i]=strlen(st);
    insert(st,i);
  }
  acgetfail();
  int p;
  for (i=0;i<n;i++)
  {
    p=0;
    for (j=i;j>=0&&i-j<m;j--)
      st[p++]=ss[j][i-j];
    st[p]=0;
    getans(st,i,0,-1,1);
    p=0;
    for (j=0;j<m;j++)
      st[p++]=ss[i][j];
    st[p]=0;
    getans(st,i,0,0,1);
    p=0;
    for (j=i;j<n&&j-i<m;j++)
      st[p++]=ss[j][j-i];
    st[p]=0;
	getans(st,i,0,1,1);
  }
  for (i=0;i<m;i++)
  {
    p=0;
    for (j=i;j>=0&&i-j<n;j--)
      st[p++]=ss[i-j][j];
    st[p]=0;
    getans(st,0,i,1,-1);
    p=0;
    for (j=i;j<m&&j-i<n;j++)
      st[p++]=ss[j-i][j];
    st[p]=0;
    getans(st,0,i,1,1);
    p=0;
    for (j=0;j<n;j++)
      st[p++]=ss[j][i];
    st[p]=0;
    getans(st,0,i,1,0);
  }
  for (i=0;i<m;i++)
  {
    p=0;
    for (j=i;j>=0&&n-1-(i-j)>=0;j--)
      st[p++]=ss[n-1-(i-j)][j];
    st[p]=0;
    getans(st,n-1,i,-1,-1);
    p=0;
    for (j=i;j<m&&n-1-(j-i)>=0;j++)
      st[p++]=ss[n-1-(j-i)][j];
    st[p]=0;
    getans(st,n-1,i,-1,1);
    p=0;
    for (j=n-1;j>=0;j--)
      st[p++]=ss[j][i];
    st[p]=0;
    getans(st,n-1,i,-1,0);
  }
  for (i=0;i<n;i++)
  {
    p=0;
    for (j=i;j>=0&&m-1-(i-j)>=0;j--)
      st[p++]=ss[j][m-1-(i-j)];
    st[p]=0;
    getans(st,i,m-1,-1,-1);
    p=0;
    for (j=i;j<n&&m-1-(j-i)>=0;j++)
      st[p++]=ss[j][m-1-(j-i)];
    st[p]=0;
    getans(st,i,m-1,1,-1);
    p=0;
    for (j=m-1;j>=0;j--)
      st[p++]=ss[i][j];
    st[p]=0;
    getans(st,i,m-1,0,-1);
  }
  
  for (i=1;i<=k;i++)
  {
    int len=lens[i];
    int u=i;
    while(fa[u]!=u)
      u=fa[u];
    printf("%d %d %c\n",anss[u].a+(len-1)*anss[u].k1,anss[u].b+(len-1)*anss[u].k2,getdir(anss[u].k1,anss[u].k2));
  }
  return 0;
}

