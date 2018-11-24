#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#define MN 50004
using namespace std;

int ch[MN][27];
int val[MN];
int tot;
char st[MN][109];

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
  }
  val[u]=1;
}

bool find(char *s)
{
  int u=1,len=strlen(s);
  for (int i=0;i<len;i++)
  {
    int c=s[i]-'a';
    if (!ch[u][c])
      return false;
    u=ch[u][c];
  }
  if (val[u])
    return true;
  else 
    return false;
}

int main()
{
  freopen("1247.in","r",stdin);
  freopen("1247.out","w",stdout);
  int n,i=1,j,k,m;
  tot=1;
  memset(ch[1],0,sizeof(ch[1]));
  while(scanf("%s",st[i])==1)
    insert(st[i++]);
  n=i-1;
  for (i=1;i<=n;i++)
  {
    int l=strlen(st[i]);
    for (j=1;j<l;j++)
    {
      char s1[102],s2[102];
      strncpy(s1,st[i],j);
      s1[j]='\0';
      k=0;
	  for (int ii=j;ii<l;ii++)
        s2[k++]=st[i][ii];
      s2[k]='\0';
      if (find(s1)&&find(s2))
      {
        printf("%s\n",st[i]);
        break;
	  }
	}
  }
  return 0;
}
