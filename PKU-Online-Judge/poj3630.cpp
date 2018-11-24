#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<string>
#define mn 200010
using namespace std;

int ch[mn][11];
int val[mn];
int tot;
int sz[mn];
void insert(char *s,int v)
    {
      int u=0,len=strlen(s);
      for (int i=0;i<len;i++)
      {
        int c=s[i]-'0';
        if (!ch[u][c])
        {
          ++tot;
          ch[u][c]=tot;
          val[tot]=0;
          memset(ch[tot],0,sizeof(ch[tot]));
		}
		sz[u]++;
		u=ch[u][c];
	  }
	  val[u]=v;
	}
bool find(int u)
	{
	  if (val[u]>0&&sz[u]>0)
	    return false;
	  if (val[u]>0)
	    return true;
	  bool flag=true;
	  for (int i=0;i<=9;i++)
	    if (ch[u][i])
	      flag=flag&&find(ch[u][i]);
	  return flag;
	}

int main()
{
  freopen("3630.in","r",stdin);
  freopen("3630.out","w",stdout);
  int n,i,j,k,m,ca;
  scanf("%d",&ca);
  while(ca--)
  {
    scanf("%d",&n);
    tot=0;
    memset(sz,0,sizeof(sz));
    memset(ch[0],0,sizeof(ch[0]));
    memset(val,0,sizeof(val));
    for(i=1;i<=n;i++)
    {
      char st[14];
      scanf("%s",st);
      insert(st,i);
	}
	bool flag=find(0);
	if (flag)
	  printf("YES\n");
	else
	  printf("NO\n");
  }
  return 0;
}
