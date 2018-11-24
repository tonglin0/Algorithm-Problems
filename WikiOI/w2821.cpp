#include<cstdio>
#include<cstdlib>
#include<queue>
#include<stack>
using namespace std;

stack <int> s;
queue <int> q;
int main()
{
  int n,i,j;
  char ch;
  char a[50]={0};
  scanf("%d",&n);
  j=0;
  scanf("%c",&ch);
  while (isspace(ch)) scanf("%c",&ch);
  a[1]=ch;
  for (i=2;i<=n;i++) scanf("%c",&a[i]);
  for (i=1;i<=n;i++)
  {
    if (a[i]=='A')
    {
      j++;
      q.push(j);
    }
    else if (a[i]=='B')
    {
      if (s.size()==5) 
      {
        printf("No\n");
        return 0;
      }
      else
      {
        j++;
        s.push(j);
      }
    }
    else
    {
      if (s.empty())
      {
        printf("No\n");
        return 0;
      }
      q.push(s.top());
      s.pop();
    }
  }
  printf("Yes\n");
  while(!q.empty())
  {
    printf("%d\n",q.front());
    q.pop();
  }
  //system("pause");
  return 0;
} 
