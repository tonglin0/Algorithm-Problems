#include<cstdio>
#include<string>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#define lint long long
using namespace std;

lint s[109];

struct bign{
  int len,s[50];
  bign(){len=1;memset(s,0,sizeof(s));}
  bign operator = (char *num)
  {
    string ss;
    int l=strlen(num);
    ss=num;
    while(l%4)
    {
      ss="0"+ss;
      l++;
	}
	len=l/4;
	for (int i=0;i<len;i++)
	  for (int j=0;j<4;j++)
	    s[i]=s[i]*10+ss[l-4*(i+1)+j]-'0';
	return *this;
  }
  bign operator = (lint num)
  {
    char t[50];
    sprintf(t,"%lld",num);
    *this=t;
    return *this;
  }
  int Max(int a,int b){return a>b?a:b;}
  bign operator + (bign b)
  {
    bign c;
    c.len=Max(len,b.len);
    for (int i=0;i<c.len;i++)
    {
      c.s[i+1]+=(c.s[i]+s[i]+b.s[i])/10000;
      c.s[i]=(c.s[i]+s[i]+b.s[i])%10000;
	}
	if (c.s[c.len]>0)
	  c.len++;
	return c;
  }
  bign operator + (lint b)
  {
    bign c;
    c=b;
    bign d;
    d=(*this)+c;
    return d;
  }
  bign operator * (bign b)
  {
    bign c;
    c.len=len+b.len;
    for (int i=0;i<len;i++)
      for (int j=0;j<b.len;j++)
      {
        c.s[i+j+1]+=(c.s[i+j]+s[i]*b.s[j])/10000;
        c.s[i+j]=(c.s[i+j]+s[i]*b.s[j])%10000;
	  }
	if (c.s[c.len]>0) c.len++;
	while(c.len>1&&c.s[c.len-1]==0)
	  c.len--;
	return c;
  }
  bign operator * (lint b)
  {
    bign c;
    c=b;
    bign d;
    d=(*this)*c;
    return d;
  }
  void output()
  {
    printf("%d",s[len-1]);
    for (int i=len-2;i>=0;i--)
      printf("%04d",s[i]);
    printf("\n");
  }
};

bign fsum(lint n)
{
  lint len=0;
  memset(s,0,sizeof(s));
  while(n)
  {
    s[++len]=n&1;
    n>>=1;
  }
  for (int i=1;i<=len/2;i++)
    swap(s[i],s[len-i+1]);
  bign ans;
  ans=(lint)0;
  for (int i=2;i<=len-2;i++)
  {
    bign ls;
    ls=(lint)0;
    for (int j=1;j<i;j++)
      ls=ls*2+s[j];
    bign rs;
    rs=(lint)0;
    for (int j=i+2;j<=len;j++)
      rs=rs*2+s[j];
    //ls=ls*(lint)(1<<(len-i-1));
    ans=ans+(ls*((lint)1<<(len-i-1)));
    if (s[i]==1&&s[i+1]==1)
      ans=ans+rs;
  }
  if (s[1]==1&&s[2]==1)
  {
    lint rs=0;
    for (int i=3;i<=len;i++)
      rs=rs*2+s[i];
    ans=ans+rs;
  }
  lint ls=0;
  for (int i=1;i<=len-2;i++)
    ls=ls*2+s[i];
  ans=ans+ls;
  return ans;
}

int main()
{
  freopen("11645.in","r",stdin);
  freopen("11645.out","w",stdout);
  lint n,i,j,k,m,ii=0;
  while(scanf("%lld",&n)==1)
  {
    if (n<0) break;
    printf("Case %lld: ",++ii);
    bign anss;
	anss=fsum(n+1);
    anss.output();
  }
  return 0;
}
