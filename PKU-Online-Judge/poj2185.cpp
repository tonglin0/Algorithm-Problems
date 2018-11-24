#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

char s[10005][79];
int f[89];
char a[79];
int next[10005];

int main()
{
  freopen("2185.in","r",stdin);
  freopen("2185.out","w",stdout);
  int n,i,j,k,m;
  scanf("%d%d",&n,&m);
  memset(f,0,sizeof(f));
  for (i=0;i<n;i++)
  {
    scanf("%s",s[i]);
    strcpy(a,s[i]);
    for (j=m-1;j>=0;j--)
    {
      int x,y;
      for (x=0,y=0;s[i][y];x++,y++)
      {
        if (!a[x])
          x=0;
        if (a[x]!=s[i][y])
          break;
	  }
	  if (!s[i][y])
	    f[j+1]++;
      a[j]=0;
	}
  }
  for (i=1;i<=m;i++)
    if (f[i]==n)
    {
      k=i;
      break;
	}
  for (i=0;i<n;i++)
    s[i][m]=0;
  next[0]=next[1]=0;
  for (i=1;i<n;i++)
  {
    j=next[i];
    while(j&&strcmp(s[i],s[j])!=0)
      j=next[j];
    next[i+1]=(strcmp(s[i],s[j])==0)?j+1:0;
  }
  printf("%d\n",(n-next[n])*k);
  return 0;
}
