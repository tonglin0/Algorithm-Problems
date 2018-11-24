#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;

int ch[1000002][27];
int val[1000002];
char st[155];
int sz[500002];
char s[2000009];
bool vis[10009];
int next[500002];
int last[500002];
int ans,tot;

void insert(char *s,int k)
{
  int u=0,len=strlen(s);
  for (int i=0;i<len;i++)
  {
    int c=s[i]-'a';
    if (!ch[u][c])
    {
      ch[u][c]=++tot;
      memset(ch[tot],0,sizeof(ch[tot]));
      val[tot]=0;
	}
	u=ch[u][c];
  }
  sz[u]++;
  val[u]=k;
}

void acgetfail()
{
  next[0]=0;
  last[0]=0;
  queue<int> q;
  for (int i=0;i<26;i++)
    if (ch[0][i])
    {
      int u=ch[0][i];
      q.push(u);
      next[u]=0;
      last[u]=0;
	}
  while(!q.empty())
  {
    int r=q.front();q.pop();
    for (int c=0;c<26;c++)
    {
      int u=ch[r][c];
      if (!u)
        continue;
      q.push(u);
	  int v=next[r];
      while(v&&!ch[v][c])
        v=next[v];
      next[u]=ch[v][c];
      last[u]=val[next[u]]?next[u]:last[next[u]];
	}
  }
}

void PRINT(int j)
{
  if(j)
  {
    if (!vis[val[j]])
    {
      vis[val[j]]=true;
      ans+=sz[j];
	}
	if (last[j])
	  PRINT(last[j]);
  }
}

void getans()
{
  int len=strlen(s);
  int j=0;
  for (int i=0;i<len;i++)
  {
  	int c=s[i]-'a';
    while(j&&!ch[j][c])
      j=next[j];
    j=ch[j][c];
    if (val[j])
      PRINT(j);
    else if (last[j])
      PRINT(last[j]);
  }
}

int main()
{
  freopen("2222.in","r",stdin);
  freopen("2222.out","w",stdout);
  int ca,n,i,j,k,m;
  scanf("%d",&ca);
  while(ca--)
  {
  	tot=0;
  	val[0]=0;
  	memset(sz,0,sizeof(sz));
  	memset(ch[0],0,sizeof(ch[0]));
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
      scanf("%s",st);
      insert(st,i);
	}
	scanf("%s",s);
	memset(vis,0,sizeof(vis));
	acgetfail();
	ans=0;
	getans();
	printf("%d\n",ans);
  }
  return 0;
}
