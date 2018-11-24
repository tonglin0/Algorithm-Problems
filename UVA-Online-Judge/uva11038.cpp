#include<cstdio>
#include<cstdlib>
#include<cstring>
#define lint long long
using namespace std;

lint ten[15];

lint fsum(lint n)
{
  char s[13];
  sprintf(s,"%lld",n);
  lint len=strlen(s);
  lint ans=0;
  for (int i=1;i<len-1;i++)
  {
    lint ls=0;
    for (int j=0;j<i;j++)
      ls=ls*10+s[j]-'0';
    lint rs=0;
    for (int j=i+1;j<len;j++)
      rs=rs*10+s[j]-'0';
    ans+=(ls-1)*ten[len-i-1];//+rs;
    if (s[i]-'0'>0)
      ans+=ten[len-i-1];
    else
      ans+=rs;
  }
  lint ls=0;
  for (int i=0;i<len-1;i++)
    ls=ls*10+s[i]-'0';
  ans+=ls;
  if (s[len-1]=='0') ans--;
  return ans;
}

int main()
{
  freopen("11038.in","r",stdin);
  freopen("11038.out","w",stdout);
  lint n,T,i,j,k,m,a,b;
  ten[0]=1;
  for (i=1;i<=10;i++)
    ten[i]=ten[i-1]*10;
  while(scanf("%lld%lld",&a,&b)==2)
  {
    if (a<0||b<0) break;
    printf("%lld\n",fsum(b+1)-fsum(a));
  }
  return 0;
}

