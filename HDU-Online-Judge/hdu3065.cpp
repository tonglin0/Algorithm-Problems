#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int ch[50009][130];
int val[50009];
char st[2000005];
int tot;
int cnt[1005];
int next[50009],last[50009];
char ss[1003][51];

void insert(char *s,int k)
{
  int u=0,len=strlen(s);
  for (int i=0;i<len;i++)
  {
    int c=s[i];
    if (!ch[u][c])
    {
      ch[u][c]=++tot;
      memset(ch[tot],0,sizeof(ch[tot]));
      val[tot]=0;
	}
	u=ch[u][c];
  }
  val[u]=k;
}

void acgetfail()
{
  queue<int> q;
  next[0]=last[0]=0;
  for (int i=0;i<129;i++)
    if (ch[0][i])
    {
      int u=ch[0][i];
      q.push(u);
      last[u]=next[u]=0;
	}
  while(!q.empty())
  {
    int r=q.front();q.pop();
    for (int i=0;i<129;i++)
    {
      int u=ch[r][i];
      if (!u)
      {
        ch[r][i]=ch[next[r]][i];
        continue;
	  }
	  q.push(u);
	  int v=next[r];
	  next[u]=ch[v][i];
	  last[u]=val[next[u]]?next[u]:last[next[u]];
	}
  }
}

void PRINT(int j)
{
  if (j)
  {
    cnt[val[j]]++;
    PRINT(last[j]);
  }
}

void acfind(char *s)
{
  int j=0;
  int len=strlen(s);
  for (int i=0;i<len;i++)
  {
    int c=s[i];
    j=ch[j][c];
    if (val[j])
      PRINT(j);
    else
      PRINT(last[j]);
  }
}

int main()
{
  freopen("3065.in","r",stdin);
  freopen("3065.out","w",stdout);
  int n,i,j,k,m;
  while(scanf("%d",&n)==1)
  {
  	tot=0;
    memset(ch[0],0,sizeof(ch[0]));
    val[0]=0;
	gets(st);
    for (i=1;i<=n;i++)
    {
      gets(ss[i]);
	  insert(ss[i],i);	
    }
    memset(cnt,0,sizeof(cnt));
    acgetfail();
	gets(st);
    memset(cnt,0,sizeof(cnt));
    acfind(st);
    for (i=1;i<=n;i++)
      if (cnt[i])
        printf("%s: %d\n",ss[i],cnt[i]);
  }
  return 0;
}
