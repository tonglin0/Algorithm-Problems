#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<string>
#include<map>
using namespace std;

int main()
{
  freopen("2503.in","r",stdin);
  freopen("2503.out","w",stdout);
  int n,i,j,k,m;
  map<string,bool> appear;
  map<string,string> trans;
  char s1[13],s2[13];
  char s[25];
  while(1)
  {
  	gets(s);
  	if (strlen(s)==0)
  	  break;
  	sscanf(s,"%s%s",s1,s2);
	appear[s2]=true;
	trans[s2]=s1;
  }
  while(scanf("%s",s1)==1)
    if (appear[s1])
      printf("%s\n",trans[s1].c_str());
    else
      printf("eh\n");
  return 0;
}
