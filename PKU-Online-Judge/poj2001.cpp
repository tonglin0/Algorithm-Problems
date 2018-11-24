#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define MN 26009
using namespace std;

int ch[MN][27];
int val[MN];
int id[MN];
int tot;
char st[1009][24];
char ts[29];

void insert(char *s,int k)
{
  int u=1,len=strlen(s);
  for (int i=0;i<len;i++)
  {
    int c=s[i]-'a';
    if (!ch[u][c])
    {
      ch[u][c]=++tot;
      memset(ch[tot],0,sizeof(ch[tot]));
      val[tot]=0;
      id[tot]=0;
	}
	u=ch[u][c];
	val[u]++;
  }
  id[u]=k;
}

void find(char *s,int k,char *ts)
{
  int u=1,len=strlen(s);
  int i;
  for (i=0;i<len;i++)
  {
    int c=s[i]-'a';
    ts[i]=s[i];
    u=ch[u][c];
    if (id[u]==k||val[u]==1)
    {
      ts[i+1]='\0';
      return ;
	}
  }
  ts[i]='\0';
}

int main()
{
  freopen("2001.in","r",stdin);
  freopen("2001.out","w",stdout);
  int n,i,j,k,m;
  tot=1;
  memset(ch[1],0,sizeof(ch[1]));
  val[1]=id[1]=0;
  i=0;
  while(scanf("%s",st[++i])==1)
    insert(st[i],i);
  n=i-1;
  for (i=1;i<=n;i++)
  {
    printf("%s ",st[i]);
    find(st[i],i,ts);
    printf("%s\n",ts);
  }
  return 0;
}
