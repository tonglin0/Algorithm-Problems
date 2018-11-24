#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

int v[]={0,1,5,10,25};
int f[10009];
int num[6][10009];
int ans[6];
int cnt[6];

int main()
{
  freopen("1787.in","r",stdin);
  freopen("1787.out","w",stdout);
  int n,i,j,k,m;
  while(scanf("%d",&m)==1)
  {
    for (i=1;i<=4;i++)
      scanf("%d",&cnt[i]);
    if (m+cnt[1]+cnt[2]+cnt[3]+cnt[4]==0)
      break;
    memset(num,0,sizeof(num));
    memset(f,-1,sizeof(f));
    f[0]=0;
    memset(ans,0,sizeof(ans));
    for (i=1;i<=4;i++)
      for (j=v[i];j<=m;j++)
        if (f[j-v[i]]!=-1&&f[j-v[i]]+1>f[j]&&num[i][j-v[i]]+1<=cnt[i])
        {
          f[j]=f[j-v[i]]+1;
          num[i][j]=num[i][j-v[i]]+1;
		}
	if (f[m]==-1)
	  printf("Charlie cannot buy coffee.\n");
	else
	{
	  i=4;j=m;
	  while(i>0)
	  {
	    ans[i]=num[i][j];
	    j-=v[i]*num[i][j];
	    i--;
	  }
	  printf("Throw in %d cents, %d nickels, %d dimes, and %d quarters.\n",ans[1],ans[2],ans[3],ans[4]);
	}
  }
  return 0;
}
