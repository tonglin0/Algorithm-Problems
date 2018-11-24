#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;

char s[5003];

struct bign
{
  int len,s[5003];
  bign(){memset(s,0,sizeof(s));len=1;}
  bign operator = (char *num)
  {
    len=strlen(num);
    for (int i=0;i<len;i++)
      s[i]=num[len-i-1]-'0';
    return *this;
  }
  bign operator = (int num)
  {
    char ss[5003];
    memset(ss,0,sizeof(ss));
    sprintf(ss,"%d",num);
    *this=ss;
    return *this;
  }
  bign(int num){*this=num;}
  bign(char *num){*this=num;}
  bign operator * (bign b)
  {
    bign c;
    c.len=len+b.len;
    for (int i=0;i<len;i++)
      for (int j=0;j<b.len;j++)
        c.s[i+j]=c.s[i+j]+s[i]*b.s[j];
    for (int i=0;i<c.len;i++)
    {
      c.s[i+1]+=c.s[i]/10;
      c.s[i]%=10;
    }
    while(c.len>1&&c.s[c.len-1]==0)
      c.len--;
    return c;
  }
  bign operator *=(bign b)
  {
    *this=*this *b;
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

int main()
{
  //freopen("1303.in","r",stdin);
  //freopen("1303.out","w",stdout);
  scanf("%s",s);
  bign a=s;
  scanf("%s",s);
  bign b=s;
  a*=b;
  printf("%s\n",a.str().c_str());
  return 0;
}
