#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MN 1000009
using namespace std;

char st[MN];
int next[MN];

void getfail(char *s)
{
  next[0]=next[1]=0;
  int len=strlen(s);
  for (int i=1;i<len;i++)
  {
    int j=next[i];
    while(j&&s[j]!=s[i])
      j=next[j];
    next[i+1]=(s[i]==s[j])?j+1:0;
  }
}

int main()
{
  freopen("1961.in","r",stdin);
  freopen("1961.out","w",stdout);
  int n,i,j,k,m,ii=0;
  while(scanf("%d",&n)==1&&n!=0)
  {
  	printf("Test case #%d\n",++ii);
    scanf("%s",st);
    getfail(st);
    for (i=0;i<n;i++)
      if ((i+1)%(i+1-next[i+1])==0&&(i+1)/(i+1-next[i+1])>1)
        printf("%d %d\n",i+1,(i+1)/(i+1-next[i+1]));
    printf("\n");
  }
  return 0;
}
