#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>
using namespace std;

char st[155];
map<char,int> ss;
int ch[204][54];
int val[504];
int next[504],last[504];
int tot;
int l;
struct bign{
	int len;
	int s[105];
	bign(){len=1;memset(s,0,sizeof(s));}
	bign operator = (int k)
	{
	  len=1;
	  memset(s,0,sizeof(s));
	  s[0]=k;
	  return *this;
	}
	bign operator + (bign b)
	{
	  bign c;
	  if (len>b.len)
	    c.len=len;
	  else
	    c.len=b.len;
	  for (int i=0;i<c.len;i++)
	  {
	    c.s[i+1]+=(c.s[i]+s[i]+b.s[i])/10;
	    c.s[i]=(c.s[i]+s[i]+b.s[i])%10;
	  }
	  if (c.s[c.len]>0)
	    c.len++;
	  while(c.len>1&&c.s[c.len-1]==0)
	    c.len--;
	  return c;
	}
	void output()
	{
	  for (int i=len-1;i>=0;i--)
	    printf("%d",s[i]);
	  printf("\n");
	}
};
bign f[54][103];

void insert(char *s,int k)
{
  int u=0,len=strlen(s);
  for (int i=0;i<len;i++)
  {
    int c=ss[s[i]];
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
  last[0]=next[0]=0;
  for (int i=0;i<l;i++)
  {
    int u=ch[0][i];
    if (!u)
      continue;
    last[u]=next[u]=0;
    q.push(u);
  }
  while(!q.empty())
  {
    int r=q.front();q.pop();
    for (int i=0;i<l;i++)
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

int main()
{
  freopen("1625.in","r",stdin);
  freopen("1625.out","w",stdout);
  int n,i,j,k,m;
  scanf("%d%d%d",&l,&m,&n);
  gets(st);
  gets(st);
  for (i=0;i<l;i++)
    ss[st[i]]=i;
  memset(ch[0],0,sizeof(ch[0]));
  val[0]=0;
  tot=0;
  for (i=1;i<=n;i++)
  {
    scanf("%s",st);
    insert(st,i);
  }
  acgetfail();
  for (j=0;j<=m;j++)
    for (i=0;i<=tot;i++)
      f[j][i]=0;
  f[0][0]=1;
  for (i=0;i<m;i++)
    for (j=0;j<=tot;j++)
    {
      if (val[j]||val[last[j]])
        continue;
      for (k=0;k<l;k++)
        f[i+1][ch[j][k]]=f[i][j]+f[i+1][ch[j][k]];//+f[i][j];
	}
  bign ans;ans=0;
  for (i=0;i<=tot;i++)
  {
    if (val[i]||val[last[i]])
      continue;
    ans=ans+f[m][i];
  }
  ans.output();
  //printf("%d\n",ans);
  return 0;
}
