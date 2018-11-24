#include<cstdio>
#include<cstdlib>
#include<cstring>
#define lint long long
using namespace std;

lint l[1009];
lint s[1009];
int ans[50];

int main()
{
  freopen("1350.in","r",stdin);
  freopen("1350.out","w",stdout);
  lint T,n,i,j,k,m;
  l[1]=l[2]=1;
  for (i=3;i<=45;i++)
    l[i]=l[i-1]+l[i-2];
  s[1]=l[1];
  for (i=2;i<=45;i++)
    s[i]=s[i-1]+l[i];
  s[0]=l[0]=0;
  scanf("%lld",&T);
  lint len;
  while(T--)
  {
    scanf("%lld",&n);
    for (i=1;i<=45;i++)
      if (s[i]>=n)
      {
        len=i;
        break;
	  }
	memset(ans,0,sizeof(ans));
	ans[len]=1;
	n-=s[len-1];
	n--;
	lint t=len-2;
	while(n)
	{
	  for (i=t;i>=1;i--)
	    if (s[i]>=n&&s[i-1]<n)
	    {
	      t=i-2;
	      ans[i]=1;
	      n-=s[i-1];
	      n--;
	      break;
		}
	}
	for (i=len;i>=1;i--)
	  printf("%d",ans[i]);
	printf("\n");
  }
  return 0;
}
