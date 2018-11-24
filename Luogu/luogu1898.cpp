#include<cstdio>
#include<cstdlib>
#include<string>
using namespace std;

int main()
{
  char ss[1000],sb[10000],ch;
  string s,sa,q;
  scanf("%s",ss);
  sa=ss;
  int c;
  int l,i,j,k;
  scanf("%d",&k);
  s="";
  l=sa.length();
  for (i=0;i<l;i++)
  {
    int n=sa[i]-'A'+k;
    sprintf(sb,"%d",n);
    s=s+sb;
  }
  while(s.length()>3)
  {
    q="";
    int l=s.length();
    for (i=0;i<l-1;i++)
    {
    int a=s[0]-'0',b=s[1]-'0';
    c=(a+b)%10;
    s.erase(s.begin(),s.begin()+1);
    char p=c+'0';
    q=q+p;
    }  
    s=q;
  }
  if (s.length()==3&&s=="100") 
  {printf("100\n");return 0;}
  else
  {
    int a=s[0]-'0',b=s[1]-'0';
    q="";
    c=(a+b)%10;
    s.erase(s.begin(),s.begin()+1);
    char p=c+'0';
    q=q+p;//s.insert(s.begin(),p);
    a=s[0]-'0',b=s[1]-'0';
    c=(a+b)%10;
    s.erase(s.begin(),s.begin()+1);
    p=c+'0';
    q=q+p;//s.insert(s.begin(),p);
    s=q;
  }
  if (s[0]=='0') s.erase(s.begin(),s.begin()+1);
  printf(s.c_str());
  //printf(s.c_str());
  //system("pause");
  return 0;
}
