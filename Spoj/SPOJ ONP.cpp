#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<vector>
#include<math.h>
#include<set>
#include<iomanip>
#include<queue>
#include<deque>
#include<bitset>
#include<stack>
#include<list>
#define Mohamed_Fathi ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
using namespace std;

int main()
{
	Mohamed_Fathi
	stack<char> s;
	string str;
	int n;      cin>>n;
	while( n -- )
    {
        string res="";
        cin>>str;
        for( int i = 0 ; i < (int)str.size() ; i ++ )
        {
            if( isalpha(str[i]) )
            {
                res+=str[i];
                continue;
            }
            else if( str[i] != ')' )
                s.push(str[i]);
            if( str[i] == ')')
            {
                while(s.top() != '(')
                {
                    res+=s.top();
                    s.pop();
                }
                if(s.size() > 1 )
                s.pop();
            }
        }
        cout<<res<<endl;
    }
    return 0;
}
