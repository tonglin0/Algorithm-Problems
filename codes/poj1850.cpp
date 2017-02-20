#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define lint long long
using namespace std;

lint c[30][30];
char s[30];

int main()
{
  freopen("1850.in","r",stdin);
  freopen("1850.out","w",stdout);
  int l,i,j,k,m,n;
  scanf("%s",s);
  l=strlen(s);
  for (i=1;i<l;i++)
    if (s[i]<=s[i-1])
    {
      printf("0\n");
      return 0;
    }
  memset(c,0,sizeof(c));
  for (i=0;i<=26;i++)
    for (j=0;j<=i;j++)
      if (j==0||j==i)
        c[i][j]=1;
      else
        c[i][j]=c[i-1][j-1]+c[i-1][j];
  c[0][0]=0;
  lint ans=0;
  for (i=1;i<=l-1;i++)
    ans+=c[26][i];
  for (i=0;i<l;i++)
    if (i>0)
      for (k=s[i-1]-'a'+2;k<=s[i]-'a';k++)
        ans+=c[26-k][l-i-1];
    else
      for (k=1;k<=s[i]-'a';k++)
        ans+=c[26-k][l-i-1];
  printf("%I64d\n",ans+1);
  return 0;
}
