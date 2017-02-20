#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<vector>
#include<queue>
#include<string>
#include<map>
#include<cctype>
#include<algorithm>
#define INF (int)1e9
#define lint long long
#define llu unsigned long long
#define eps 1e-8
using namespace std;

char sa[3005],sb[3005];

string mintree(string st)
{
  string ret="";
  vector<string> box;
  box.clear();
  int cnt=0,pre=0;
  for(int i=0;i<st.size();i++)
  {
    if (st[i]=='0')
      cnt++;
    else
      cnt--;
    if (cnt==0)
    {
      if (i-1>pre+1)
        box.push_back("0"+mintree(st.substr(pre+1,i-1-pre))+"1");
      else
        box.push_back("01");
	  pre=i+1;
	}
  }
  sort(box.begin(),box.end());
  for (int i=0;i<box.size();i++)
    ret+=box[i];
  return ret;
}

int main()
{
  freopen("1635.in","r",stdin);
  freopen("1635.out","w",stdout);
  int n,i,j,k,m,ca,ii=0;
  scanf("%d",&ca);
  while(ca--)
  {
    scanf("%s",sa);
    scanf("%s",sb);
    string s1,s2;
    s1=sa;s2=sb;
    if (mintree(s1)!=mintree(s2))
      printf("different\n");
    else
      printf("same\n");
  }
  return 0;
}

