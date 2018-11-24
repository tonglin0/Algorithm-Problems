#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

int f[505][3];
int v[34];

int main()
{
  freopen("2126.in","r",stdin);
  freopen("2126.out","w",stdout);
  int n,i,j,k,m,ca;
  scanf("%d",&ca);
  while(ca--)
  {
    scanf("%d%d",&n,&m);
    for (i=1;i<=n;i++)
      scanf("%d",&v[i]);
    memset(f,0,sizeof(f));
    for (i=0;i<=m;i++)
      f[i][2]=1;
    for (i=1;i<=n;i++)
      for (j=m;j>=v[i];j--)
        if (f[j][1]<f[j-v[i]][1]+1)
        {
          f[j][1]=f[j-v[i]][1]+1;
          f[j][2]=f[j-v[i]][2];
		}
		else if (f[j][1]==f[j-v[i]][1]+1)
		{
		  f[j][2]+=f[j-v[i]][2];
		}
	if (f[m][1]>0)
	  printf("You have %d selection(s) to buy with %d kind(s) of souvenirs.\n",f[m][2],f[m][1]);
	else
	  printf("Sorry, you can't buy anything.\n");
  }
  return 0;
}
