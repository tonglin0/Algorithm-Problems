#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cctype>
#include<string>
#define MN 1000002
using namespace std;

char st2[3004];
char st[3004];
int ch[MN][27];
int val[MN];
char ss[MN][103];
int tot;

void insert(char *s,char *s2)
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
  val[u]=tot;
  strcpy(ss[tot],s2);
}

int find(char *s)
{
  int u=1,len=strlen(s);
  for (int i=0;i<len;i++)
  {
    int c=s[i]-'a';
    if (!ch[u][c])
      return 0;
    u=ch[u][c];
  }
  return val[u];
}

int main()
{
  freopen("1075.in","r",stdin);
  freopen("1075.out","w",stdout);
  int n,i,j,k,m;
  scanf("%s",st);
  tot=1;
  val[0]=0;
  memset(ch[1],0,sizeof(ch[1]));
  while(scanf("%s",st)==1&&st[0]!='E')
  {
    scanf("%s",st2);
    insert(st2,st);
  }
  scanf("%s",st);
  gets(st);
  while(1)
  {
    gets(st);
    if(st[0]=='E')
      break;
    i=0;
    while(i<strlen(st))
    {
      if (!isalpha(st[i]))
        printf("%c",st[i]);
      else
      {
        n=0;
        st2[0]=st[i];
        while(i+1<strlen(st)&&isalpha(st[i+1]))
          st2[++n]=st[++i];
        st2[n+1]='\0';
        k=find(st2);
        if (k!=0)
          printf("%s",ss[k]);
        else
          for (j=0;j<=n;j++)
            printf("%c",st2[j]);
	  }
	  i++;
    }
    printf("\n");
  }
  return 0;
}
