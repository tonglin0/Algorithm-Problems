#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<vector>
#include<queue>
#include<string>
#include<map>
#include<cctype>
#include<algorithm>
#define INF (int)1e9
#define lint long long
#define llu unsigned long long
#define eps 1e-8
using namespace std;

char st[1000009];
int next[1000009];
bool vis[1000009];

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
    if (i+1!=len)
      vis[next[i+1]]=true;
  }
}

int main()
{
  freopen("4763.in","r",stdin);
  freopen("4763.out","w",stdout);
  int n,i,j,k,m,ii=0,ca;
  scanf("%d",&ca);
  while(ca--)
  {
  	memset(vis,0,sizeof(vis));
    scanf("%s",st);
    getfail(st);
    int len=strlen(st);
    int x=next[len];
    while(x&&(!vis[x]))
      x=next[x];
    printf("%d\n",x);
  }
  return 0;
}

