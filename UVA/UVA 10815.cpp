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
    set<string> s;
    while( getline(cin , str ) )
    {
        string e="";
        for( int i = 0 ; i < str.size() ; i ++ )
        {
            if( isalpha(str[i]) )
            {
                str[i] = tolower(str[i]);
                e+=str[i];
            }
            else
            {
                if(e!= "" )
                    s.insert(e);
                e="";
            }
        }
        if( e != "")
            s.insert(e);;
    }
    set<string>:: iterator it = s.begin();
    for( it = s.begin() ; it != s.end() ; it++ )
            cout<<*it<<endl;
    return 0;
}
