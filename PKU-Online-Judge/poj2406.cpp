#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

int next[1000009];

void getfail(char *s)
{
  next[0]=next[1]=0;
  int l=strlen(s);
  for (int i=1;i<l;i++)
  {
    int j=next[i];
    while(j&&s[i]!=s[j])
      j=next[j];
    next[i+1]=(s[i]==s[j])?j+1:0;
  }
}

int find(char *s)
{
  getfail(s);
  int l=strlen(s);
  return l%(l-next[l])==0?l/(l-next[l]):1;
}

int main()
{
  freopen("2406.in","r",stdin);
  freopen("2406.out","w",stdout);
  int n,i,j,k,m;
  char st[1000009];
  while(scanf("%s",st)==1&&!(strlen(st)==1&&st[0]=='.'))
    printf("%d\n",find(st));
  return 0;
}
