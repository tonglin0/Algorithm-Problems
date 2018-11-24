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
      scanf("%d",&b);
      s.push(b);
    }
    else if (a==2)
      s.pop();
    else 
      printf("%d\n",s.top());
  }
  //system("pause");
  return 0;
} 
