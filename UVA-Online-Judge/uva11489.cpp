#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

char s[1006];
int f[4];

int main()
{
  freopen("11489.in","r",stdin);
  freopen("11489.out","w",stdout);
  int n,i,j,k,T,ii,l;
  scanf("%d",&T);
  for (ii=1;ii<=T;ii++)
  {
    printf("Case %d: ",ii);
    scanf("%s",s);
    l=strlen(s);
    if (l==1)
    {
      printf("S\n");
      continue;
	}
	int k=0;
	int sum=0;
	memset(f,0,sizeof(f));
	for (i=0;i<l;i++)
	{
	  sum+=s[i]-'0';
	  f[(s[i]-'0')%3]++;
	}
	if (sum%3&&!f[sum%3])
	{
	  printf("T\n");
	  continue;
	}
	for (i=0;i<l;i++)
	  if ((s[i]-'0')%3==0)
	    k++;
	if (sum%3)
	  l--;
	if (((k&1)&&k!=l-1)||((k&1==0)&&(k==l-1)))
	{
	  if (sum%3)
	    printf("T\n");
	  else
	    printf("S\n");
    }
	else
	{
	  if (sum%3)
	    printf("S\n");
	  else
	    printf("T\n");
    }
  }
  return 0;
}
