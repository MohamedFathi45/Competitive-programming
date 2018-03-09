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


int main( )
{
    Mohamed_Fathi
    string str;
    while( cin>>str )
    {
        list<char> l;
        list<char> :: iterator it = l.begin() ;
        for( int i = 0 ; i <str.size() ; i ++  )
        {
            if( str[i]== '[' )
            {
                it = l.begin();
                continue;
            }
            else if( str[i] == ']' )
            {
                it = l.end();
                continue;
            }
            l.insert(it , str[i] );
        }
        for( it = l.begin() ; it != l.end() ; it ++ )
            cout<<*it;
        cout<<endl;
    }
}
