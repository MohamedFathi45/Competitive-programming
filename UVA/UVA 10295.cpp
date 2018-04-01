#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<vector>
#include<math.h>
#include<set>
#include<map>
#include<iomanip>
#include<queue>
#include<deque>
#include<bitset>
#include<stack>
#include<list>
#define Mohamed_Fathi ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
using namespace std;

map<string , int> mp;
int main( )
{
    string word ;
    int value,n,m;
    ll res = 0;
    cin>>n>>m;
    for( int i = 0 ; i < n ; i ++ )
    {
        cin>>word>>value;
        mp[word] = value;
    }
    string s;
    while( m -- )
    {
        cin.ignore();
        getline(cin , s , '.');
        for( int i = 0 ; i < s.size() ; i ++ )
        {
            if(s[i] == '.')
                break;
            string temp="";
            while(isalpha(s[i]) )
            {
                temp+=s[i];
                i++;
            }
            if(temp!="")
            {
                if(mp.find(temp) != mp.end())
                    res+=mp[temp];
            }
        }
        cout<<res<<endl;
        res = 0;
    }
    return 0;
}
