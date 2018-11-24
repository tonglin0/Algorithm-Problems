#include<cstdio>
#include<cstdlib>
#include<queue>
using namespace std;

queue<int> q;
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
      q.push(b);
    }
    else if (a==2)
      q.pop();
    else 
      printf("%d\n",q.front());
  }
  //system("pause");
  return 0;
}
 
