#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#define lint long long
using namespace std;

struct bign{
  int len,s[1009];
  bign(){len=1;memset(s,0,sizeof(s));}
  bign operator = (char *num)
  {
    int i;
    int l=strlen(num);
    string ss;
    ss=num;
    while(l%6)
    {
      l++;
      ss='0'+ss;
	}
	len=l/6;
	for (i=0;i<len;i++)
	  for (int j=0;j<6;j++)
	    s[i]=s[i]*10+ss[l-6*(i+1)+j]-'0';
	return *this;
  }
  bign operator = (int num)
  {
    char t[10000];
    sprintf(t,"%d",num);
    *this=t;
    return *this;
  }
  bign operator + (bign b)
  {
    bign c;
    if (len>b.len)
      c.len=len;
    else
      c.len=b.len;
    for (int i=0;i<c.len;i++)
    {
      c.s[i+1]+=(s[i]+b.s[i]+c.s[i])/1000000;
      c.s[i]=(c.s[i]+s[i]+b.s[i])%1000000;
	}
	if (c.s[c.len]>0)
	  c.len++;
	return c;
  }
  bign operator + (int num)
  {
    bign b;
    b=num;
    bign c;
	c=*this+b;
    return c;
  }
  string str() const
  {
    string ss;
    char t[10009];
    memset(t,0,sizeof(t));
    sprintf(t,"%d",s[len-1]);
    ss=t;
    for (int i=len-2;i>=0;i--)
    {
      if (s[i]<100000&&s[i]>=10000)
        ss=ss+'0';
      else if (s[i]<10000&&s[i]>=1000)
        ss=ss+"00";
      else if (s[i]<1000&&s[i]>=100)
        ss=ss+"000";
      else if (s[i]<100&&s[i]>=10)
        ss=ss+"0000";
      else if (s[i]<10)
        ss=ss+"00000";
      sprintf(t,"%d",s[i]);
      ss=ss+t;
	}
	return ss;
  }
};

bign f[2009];
lint c[14];

int main()
{
  freopen("11375.in","r",stdin);
  freopen("11375.out","w",stdout);
  lint n,i,j,k,m;
  //memset(f,0,sizeof(f));
  f[0]=0;f[1]=0;f[2]=1;f[3]=1;f[4]=1;f[7]=1;f[5]=3;f[6]=2;
  memset(c,0,sizeof(c));
  c[1]=2;c[7]=3;c[4]=4;c[2]=c[5]=c[3]=5;c[6]=c[9]=c[0]=6;c[8]=7;
  for (i=4;i<=7;i++)
    for (j=0;j<=9;j++)
      if (i-c[j]>0)
        f[i]=f[i]+f[i-c[j]];
  for(i=8;i<=2001;i++)
    for (j=0;j<=9;j++)
      f[i]=f[i]+f[i-c[j]];
  while(scanf("%lld",&n)==1)
  {
    if (n<=7)
    {
	  bign ans;
	  ans=0;
	  for (i=1;i<=n;i++)
	    ans=ans+f[i];
	  if (n<6)
	    printf("%s\n",ans.str().c_str());
	  else
	  {
	    ans=ans+1;
		printf("%s\n",ans.str().c_str());
      }
    }
	else
    {
      bign ans;
      ans=0;
	  for (i=1;i<=n;i++)
        ans=ans+f[i];
      ans=ans+1;
      printf("%s\n",ans.str().c_str());
	}
  }
  return 0;
}
