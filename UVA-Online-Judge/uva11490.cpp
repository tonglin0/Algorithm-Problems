#include<cstdlib>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#define MOD 100000007
#define lint long long
using namespace std;

vector<lint> anss;
bool cmp(lint a,lint b){return a>b;}

int main()
{
  freopen("11490.in","r",stdin);
  freopen("11490.out","w",stdout);
  lint n,i,j,k,m,s1,s2,s,a,b,d;
  while(scanf("%lld",&s)==1)
  {
    if (s==0) break;
    anss.clear();
	m=(lint)sqrt(s+0.5);
    for (s1=1;s1<=m;s1++)
      if (s%s1==0)
      {
        s2=s/s1;
        if ((2*s1+9*s2)%7==0&&(s1+8*s2)%7==0)
        {
          a=(2*s1+9*s2)/7;
          b=(s1+8*s2)/7;
          d=2*a-3*b;
          if (d>0&&a>=b)
            anss.push_back(d);
		}
		if ((2*s2+9*s1)%7==0&&(s2+8*s1)%7==0)
        {
          a=(2*s2+9*s1)/7;
          b=(s2+8*s1)/7;
          d=2*a-3*b;
          if (d>0&&a>=b)
            anss.push_back(d);
		}
	  }
	if (anss.size()==0)
	{
	  printf("No Solution Possible\n\n");
	  continue;
	}
	sort(anss.begin(),anss.end(),cmp);
	printf("Possible Missing Soldiers = %lld\n",anss[0]%MOD*2%MOD*anss[0]%MOD);
	for (i=1;i<anss.size();i++)
	  printf("Possible Missing Soldiers = %lld\n",anss[i]%MOD*2%MOD*anss[i]%MOD);
	printf("\n");
  }
  return 0;
}
