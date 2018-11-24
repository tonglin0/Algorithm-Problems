#include<cstdio>
#include<cstdlib>
#include<stack>
using namespace std;

stack<int> s;
int main()
{
  int n,i,a,b;
  scanf("%d",&n);
  for (i=1;i<=n;i++)
  {
    scanf("%d",&a);
    if (a==1)
    {
      scanf("%d",&a);
      s.push(a);
    }
    else if (s.empty())
    {
      printf("impossible!");
      return 0;
    }
    else
      s.pop();
  }
  if (s.empty()) printf("impossible!\n");else printf("%d\n",s.top());
  //system("pause");
  return 0;
} 
