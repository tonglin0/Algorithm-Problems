#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> anss;
char st[400009];
int next[400009];

void getfail(char *s)
{
  next[0]=next[1]=0;
  int l=strlen(s);
  for(int i=1;i<l;i++)
  {
    int j=next[i];
    while(j&&s[i]!=s[j])
      j=next[j];
    next[i+1]=(s[i]==s[j])?j+1:0;
  }
}

int main()
{
  freopen("2752.in","r",stdin);
  freopen("2752.out","w",stdout);
  int n,i,j,k,m;
  while(scanf("%s",st)==1)
  {
    anss.clear();
    getfail(st);
    int l=strlen(st);
    int p=l;
    while(p)
    {
      anss.push_back(p);
      p=next[p];
	}
	sort(anss.begin(),anss.end());
	printf("%d",anss[0]);
	for (i=1;i<anss.size();i++)
	  printf(" %d",anss[i]);
	printf("\n");
  }
  return 0;
}
