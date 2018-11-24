#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

int next[10005];

void getfail(char *s)
{
  next[0]=next[1]=0;
  int l=strlen(s);
  for (int i=1;i<l;i++)
  {
    int j=next[i];
    while(j&&s[j]!=s[i])
      j=next[j];
    next[i+1]=(s[i]==s[j])?j+1:0;
  }
}

int find(char *s,char *s0)
{
  int n=strlen(s),m=strlen(s0);
  getfail(s0);
  int j=0,ans=0;
  for (int i=0;i<n;i++)
  {
    while(j&&s0[j]!=s[i])
      j=next[j];
    if (s0[j]==s[i])
      j++;
    if (j==m)
      ans++;
  }
  return ans;
}

int main()
{
  freopen("3461.in","r",stdin);
  freopen("3461.out","w",stdout);
  int n,i,j,k,m,ca;
  scanf("%d",&ca);
  while(ca--)
  {
  	char s1[10002],s2[1000002];
    scanf("%s%s",s1,s2);
    printf("%d\n",find(s2,s1));
  }
  return 0;
}
