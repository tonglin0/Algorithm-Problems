#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#define MN 400002
using namespace std;

int ch[MN][27];
int val[MN];
int tot;
char st[109];

void insert(char *s)
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
	}
	u=ch[u][c];
	val[u]++;
  }
}

int find(char *s)
{
  int u=1,len=strlen(s);
  for (int i=0;i<len;i++)
  {
    int c=st[i]-'a';
    if (!ch[u][c])
      return 0;
    u=ch[u][c];
  }
  return val[u];
}

int main()
{
  freopen("1251.in","r",stdin);
  freopen("1251.out","w",stdout);
  int n,i,j,k,m;
  tot=1;
  memset(ch[1],0,sizeof(ch[1]));
  while(1)
  {
    gets(st);
    if (strlen(st)==0)
      break;
    insert(st);
  }
  while(scanf("%s",st)==1)
    printf("%d\n",find(st));
  return 0;
}
