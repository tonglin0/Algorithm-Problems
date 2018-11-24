#include<cstdio>
#include<iostream>
#include<cstring>
#define lint long long
using namespace std;

lint s[22][22][22];

lint find(lint a,lint b,lint c)
{
	if ((a<=0)||(b<=0)||(c<=0)) return 1;
	if ((a>20)||(b>20)||(c>20)) return find((lint)20,(lint)20,(lint)20);
	if (s[a][b][c])
		return s[a][b][c];
	if ((a<b)&&(b<c))
	{
		s[a][b][c]=find(a,b,c-1)+find(a,b-1,c-1)-find(a,b-1,c);
		return s[a][b][c];
	}
	s[a][b][c]=find(a-1,b,c)+find(a-1,b-1,c)+find(a-1,b,c-1)-find(a-1,b-1,c-1);
	return s[a][b][c];
}

int main()
{
	lint a,b,c;
	memset(s,0,sizeof(s));
	while(cin>>a>>b>>c)
	{
		if ((a==-1)&&(b==-1)&&(c==-1)) break;
		printf("w(%lld, %lld, %lld) = ",a,b,c);
		printf("%lld\n",find(a,b,c));
	}
	return 0;
}

