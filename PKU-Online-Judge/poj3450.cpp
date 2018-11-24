#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

char s[4004][204];
char ans[203];
int next[204];

void getfail(char *s)
{
  int len=strlen(s);
  next[0]=next[1]=0;
  for (int i=1;i<len;i++)
  {
    int j=next[i];
    while(j&&s[i]!=s[j])
      j=next[j];
    next[i+1]=(s[i]==s[j])?j+1:0;
  }
}

bool find(char *s,char *s0)
{
  int n=strlen(s),m=strlen(s0);
  int j=0;
  getfail(s0);
  for (int i=0;i<n;i++)
  {
    while(j&&s0[j]!=s[i])
      j=next[j];
    if (s0[j]==s[i])
      j++;
    if (j==m)
      return true;
  }
  return false;
}

int main()
{
  freopen("3450.in","r",stdin);
  freopen("3450.out","w",stdout);
  int n,i,j,k,m;
  while(scanf("%d",&n)==1&&n)
  {
    for (i=1;i<=n;i++)
      scanf("%s",s[i]);
    int l=0,r=0;
    int len=strlen(s[1]);
    int ms=0;
	while(r<len)
    {
      char ts[204];
      for (i=l;i<=r;i++)
        ts[i-l]=s[1][i];
      ts[r-l+1]=0;
      bool flag=true;
      for (i=2;i<=n;i++)
        if (!find(s[i],ts))
        {
          flag=false;
          break;
		}
	  if (flag)
	  {
	    if (r-l+1>ms||(r-l+1==ms&&strcmp(ts,ans)<0))
	    {
	      ms=r-l+1;
	      strcpy(ans,ts);
		}
		r++;
	  }
	  else
	    l++;
	}
	if (ms==0)
	  printf("IDENTITY LOST\n");
	else
	  printf("%s\n",ans);
  }
  return 0;
}
