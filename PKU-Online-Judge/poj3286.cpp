#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#define lint long long
using namespace std;

lint ten[13];

lint find(lint a)
{
  char s[100];
  sprintf(s,"%lld",a);
  lint i,ans=0,l=strlen(s);
  lint num=0;
  for (i=1;i<l-1;i++)
  {
    num=num*10+s[i-1]-'0';
    ans+=(num-1)*ten[l-i-1];
    if (s[i]-'0'>0)
      ans+=ten[l-i-1];
    else
    {
      lint tn=0;
      for (lint j=i+1;j<l;j++)
        tn=tn*10+s[j]-'0';
      ans+=tn;
	}
  }
  lint tmp=0;
  for (i=0;i<l-1;i++)
    tmp=tmp*10+s[i]-'0';
  if (s[l-1]=='0')
    ans+=tmp;
  else
    ans+=(tmp+1);
  return ans;
}

int main()
{
  freopen("3286.in","r",stdin);
  freopen("3286.out","w",stdout);
  lint n,i,j,k,m,a,b;
  ten[0]=1;
  for (i=1;i<=10;i++)
    ten[i]=ten[i-1]*10;
  while(scanf("%I64d%I64d",&a,&b)==2)
  {
    if (b==-1)
      break;
    lint ans=find(b+1)-find(a);
    printf("%I64d\n",ans);
  }
  return 0;
}
