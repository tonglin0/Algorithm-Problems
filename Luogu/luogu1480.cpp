#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;

char s[5005];

struct bign
{
  int s[5005],len;
  bign(){memset(s,0,sizeof(s));len=1;}
  bign(char* num){*this=num;}
  bign operator = (char *num)
  {
    len=strlen(num);
    for (int i=0;i<len;i++)
      s[i]=num[len-i-1]-'0';
    return *this;
  }
  bign operator * (int b)
  {
    for (int i=0;i<len;i++)
      s[i]=s[i]*b;
    for (int i=0;i<len;i++)
    {
      s[i+1]+=s[i]/10;
      s[i]=s[i]%10;
    }
    if (s[len]>0)
      len++;
    int l=len-1;
    while(s[l]>=10)
    {
      s[l+1]+=s[l]/10;
      s[l]=s[l]%10;
      l++;
    }
    while(l>0&&s[l]==0) l--;
    len=l+1;
    return *this;
  }
  bign operator + (int b)
  {
    s[0]+=b;
    return *this;
  }
  bool operator >= (bign b)
  {
    if (len!=b.len) return len>b.len;
    for (int i=len-1;i>=0;i--)
      if (s[i]!=b.s[i])
        return s[i]>b.s[i];
    return true;
  }
  bign operator - (bign b)
  {
    bign c;
    for (int i=0;i<len;i++)
    {
      if (s[i]<b.s[i])
      {
        s[i+1]--;
        s[i]+=10;
      }
      c.s[i]=s[i]-b.s[i];
    }
    c.len=len;
    while(c.len>1&&(c.s[c.len-1]==0)) c.len--;
    return c;
  }
  bign operator / (bign b)
  {
    bign c;bign d;
    for (int i=len-1;i>=0;i--)
    {
      d=d*10;
      d=d+s[i];
      while(d>=b)
      {
        c.s[i]++;
        d=d-b;
      }
    }
    c.len=len+1;
    while(c.len>1&&c.s[c.len-1]==0)c.len--;
    return c;
  }
  string str() const
  {
    string ss="";
    for (int i=0;i<len;i++)
      ss=(char)(s[i]+'0')+ss;
    return ss;
  }
};

int main()
{
  freopen("1480.in","r",stdin);
  freopen("1480.out","w",stdout);
  scanf("%s",s);
  bign a=s;
  scanf("%s",s);
  bign b=s;
  bign c;
  c=a/b;
  printf("%s\n",c.str().c_str());
  return 0;
}
