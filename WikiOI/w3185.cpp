#include<cstdio>
#include<cstdlib>
#include<queue>
using namespace std;

queue <int> q;
int main()
{
  int n,i;
  scanf("%d",&n);
  for (i=1;i<=n;i++)
  {
    int b,a;
    scanf("%d",&a);
    if (a==2) q.pop();
    else
    {
      scanf("%d",&b);
      q.push(b);
    }
  }
  if (q.empty()) printf("impossible!\n");
  else printf("%d\n",q.front());
  system("pause");
  //return 0;
} 
