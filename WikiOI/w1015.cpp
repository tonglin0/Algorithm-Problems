#include<cstdio>
#include<cstdlib>
#include<string>
using namespace std;

char ss[1000],ch;
int main()
{
  freopen("a.in","r",stdin);
  freopen("a.out","w",stdout);
  scanf("%s",ss);
  string s;
  s=ss;
  int i,j,n,l;
  for (i=0;i<s.length();i++)
    if (isalpha(s[i]))
    {
      ch=s[i];
      break;
    }
  int d,a=0,b=0;
  d=s.find('=');
  l=s.length();
  //d+=s.begin();
  for (i=0;i<d;i++)
    if (isalpha(s[i]))
    {
      if (i==0){a++;continue;}//||!isdigic(s[i-1])) {a++;break;}
      if (!isdigit(s[i-1]))
      {
        if (s[i-1]=='+'){a++;continue;}
        else if (s[i-1]=='-') {a--;continue;}
      }
      else
      {
        j=i-1;
        while(j-1>=0&&isdigit(s[j-1])) j--;
        int m,k;
        m=0;
        for (k=j;k<=i-1;k++)
          m=m*10+s[k]-'0';
        if (j==0||s[j-1]=='+'){a+=m;continue;}
        else {a-=m;continue;}
      }
    }
  for (i=d+1;i<l;i++)
    if (isalpha(s[i]))
    {
      if (i==d+1){a--;continue;}//||!isdigic(s[i-1])) {a++;break;}
      if (!isdigit(s[i-1]))
      {
        if (s[i-1]=='+'){a--;continue;}
        else if (s[i-1]=='-') {a++;continue;}
      }
      else
      {
        j=i-1;
        while(j-1>=d+1&&isdigit(s[j-1])) j--;
        int m,k;
        m=0;
        for (k=j;k<=i-1;k++)
          m=m*10+s[k]-'0';
        if (j==d+1||s[j-1]=='+'){a-=m;continue;}
        else {a+=m;continue;}
      }
    }
  for (i=0;i<d;i++)
  {
    if (isdigit(s[i]))
    {
      j=i;
      while(j+1<d&&isdigit(s[j+1]))j++;
      if (j+1<d&&isalpha(s[j+1])) {i=j+1;continue;}
      if (j+1==d||!isalpha(s[j+1]))
      {
        int k,m=0;
        for(k=i;k<=j;k++)
          m=m*10+s[k]-'0';
        if (i==0||s[i-1]=='+'){b-=m;i=j+1;continue;}
        else {b+=m;i=j+1;continue;}
      }
    }
  }
  for (i=d+1;i<l;i++)
  {
    if (isdigit(s[i]))
    {
      j=i;
      while(j+1<l&&isdigit(s[j+1]))j++;
      if (j+1<l&&isalpha(s[j+1])) {i=j+1;continue;}
      if (j+1==l||!isalpha(s[j+1]))
      {
        int k,m=0;
        for(k=i;k<=j;k++)
          m=m*10+s[k]-'0';
        if (i==d+1||s[i-1]=='+'){b+=m;i=j+1;continue;}
        else {b-=m;i=j+1;continue;}
      }
    }
  }
  if (b==0) printf("%c=0.000\n",ch);
  else printf("%c=%.3lf\n",ch,(double)b/a); 
  return 0;
}
