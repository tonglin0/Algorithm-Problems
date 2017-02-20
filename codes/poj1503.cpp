#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#define MN 205
using namespace std;

char sa[MN],sb[MN];

struct bign
{
  int len,s[MN];
  bign(){len=1;memset(s,0,sizeof(s));}
  bign(char *num){*this=num;}
  bign operator = (char *num)
  {
    string ss=num;
    int l=strlen(num);
    while(l%6)
    {
      ss='0'+ss;
      l++;
    }
    len=l/6;
    for (int i=0;i<len;i++)
      for (int j=0;j<6;j++)
        s[i]=s[i]*10+ss[l-6*(i+1)+j]-'0';
    return *this;
  }
  bign operator + (bign b)
  {
    bign c;
    if (len>b.len) c.len=len;else c.len=b.len;
    for (int i=0;i<c.len;i++)
    {
      c.s[i+1]=(c.s[i]+s[i]+b.s[i])/1000000;
      c.s[i]=(c.s[i]+s[i]+b.s[i])%1000000;
    }
    if (c.s[c.len]>0) c.len++;
    return c;
  }
  bign operator += (bign b)
  {
    *this=*this+b;
    return *this;
  }
  string str() const
  {
    string ss;
    char t[MN];
    memset(t,0,sizeof(t));
    sprintf(t,"%d",s[len-1]);
    ss=t;
    for (int i=len-2;i>=0;i--)
    {
      if (s[i]<100000&&s[i]>=10000)
        ss=ss+"0";
      else if (s[i]<10000&&s[i]>=1000)
        ss=ss+"00";
      else if (s[i]<1000&&s[i]>=100)
        ss=ss+"000";
      else if (s[i]<100&&s[i]>=10)
        ss=ss+"0000";
      else if (s[i]<10)
        ss=ss+"00000";
      memset(t,0,sizeof(t));
      sprintf(t,"%d",s[i]);
      ss=ss+t;
    }
    return ss;
  }
};

int main()
{
  freopen("1503.in","r",stdin);
  freopen("1503.out","w",stdout);
  int n,i,j,k,m;
  scanf("%s",sa);
  bign a;
  a=sa;
  //printf("a=%s\n",a.str().c_str());
  scanf("%s",sb);
  while(strcmp(sb,"0")!=0)
  {
    bign b;
    b=sb;
    a+=b;
    //printf("b=%s\n",b.str().c_str());
    scanf("%s",sb);
  }
  printf("%s\n",a.str().c_str());
  return 0;
}
