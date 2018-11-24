#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

char st[102][103];
int next[103];

void getfail(char *s)
{
  int len=strlen(s);
  next[0]=next[1]=0;
  for (int i=1;i<len;i++)
  {
    int j=next[i];
    while(j&&s[i]!=s[j])
      j=next[j];
    next[i+1]=(s[j]==s[i])?j+1:0;
  }
}

bool find(char *s,char *s0)
{
  getfail(s0);
  int j=0;
  int m=strlen(s0);
  int len=strlen(s);
  for (int i=0;i<len;i++)
  {
    while(j&&s0[j]!=s[i])
      j=next[j];
    if (s[i]==s0[j])
      j++;
    if (j==m)
      return true;
  }
  return false;
}

int main()
{
  freopen("1226.in","r",stdin);
  freopen("1226.out","w",stdout);
  int ca,n,i,j,k,m;
  scanf("%d",&ca);
  while(ca--)
  {
  	int ans=0;
    scanf("%d",&n);
    for (i=1;i<=n;i++)
      scanf("%s",st[i]);
    int l=0,r=0;
    int len1=strlen(st[1]);
    while(r<len1)
    {
      char t1[102],t2[102];
      for (i=l;i<=r;i++)
        t1[i-l]=st[1][i];
      t1[r-l+1]=0;
      for (i=r;i>=l;i--)
        t2[r-i]=st[1][i];
      t2[r-l+1]=0;
      bool flag=true;
      for (i=2;i<=n;i++)
        if ((!find(st[i],t1))&&(!find(st[i],t2)))
        {
          flag=false;
          break;
		}
	  if (flag)
	  {
	    ans=max(ans,r-l+1);
		r++;
	  }
	  else
	    l++;
	}
	printf("%d\n",ans);
  }
  return 0;
}
