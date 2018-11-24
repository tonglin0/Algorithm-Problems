#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;

struct bign
{
  int s[1004];
  int len;
  bign(){memset(s,0,sizeof(s));len=1;}
  bign operator = (char* num)
  {
    len=strlen(num);
    for (int i=0;i<len;i++)
      s[i]=num[len-i-1]-'0';
    return *this; 
  }
  bign operator = (int num)
  {
    char ss[1004];
    sprintf(ss,"%d",num);
    *this=ss;
    return *this;
  }
  bign (char *num){*this=num;}
  bign (int num){*this=num;}
  bign operator + (bign b) const
  {
    bign c;
    c.len=max(b.len,len);
    for (int i=0;i<c.len;i++)
    {
      c.s[i+1]=(c.s[i]+s[i]+b.s[i])/10;
      c.s[i]=(c.s[i]+s[i]+b.s[i])%10;
    }
    if (c.s[c.len]>0)
      c.len++;
    return c;
  }
  bign operator += (bign b)
  {
    *this= *this+b; 
    return *this;
  }
  string str() const
  {
    string ss="";
    for (int i=0;i<len;i++)
      ss=(char)(s[i]+'0')+ss;
    return ss;
  }
};

char s[1004];

int main()
{
  freopen("1601.in","r",stdin);
  freopen("1601.out","w",stdout);
  scanf("%s",s);
  bign a=s;
  scanf("%s",s);
  bign b=s;
  bign c;
  c=a+b;
  printf("%s\n",c.str().c_str());
  return 0;
}
