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
	int arr[26];
	int mn = INT_MAX;
	string str;     cin>>str;
	for( int i = 0 ; i < 26 ; i ++ )
        cin>>arr[i];
    int s=-1 , l=-1 ;
    for( int i = 0 ; i < str.size() ; i ++ )
    {
        if( str[i] == '?')
        {
            s = i;
            int temp = s;
            for( int j = i ; j < str.size() ; j ++ )
            {
                if(  str[j] == '?'   )
                {
                    l = temp++;
                }
                else
                    break;
            }
            if( s - 1 == -1 )
            {
                if( l+1 ==str.size() )
                {
                    cout<<0<<endl;
                    for( int k = 0 ; k < str.size(); k ++ )
                    {
                        cout<<"a";
                    }
                    cout<<endl;
                    return 0;
                }
                else
                {
                    for( int k = s ; k <= l ; k ++ )
                    {
                        str[k] = str[l+1];
                    }
                    i=l+1;
                    continue;
                }
            }

            if( l+1 >= str.size() )
            {
                if( s-1 == -1  )
                {
                    cout<<0<<endl;
                    for( int k = 0 ; k < str.size(); k ++ )
                    {
                        cout<<"a";
                    }
                    cout<<endl;
                    return 0;
                }
                else
                {
                    for( int k = s ; k <= l ; k ++ )
                    {
                        str[k] = str[s-1];
                    }
                    i=l+1;
                    continue;
                }
            }

             mn = INT_MAX;
            char ch='a';
            for( int j = 0 ; j < 26; j ++ )
            {
                int res = ( abs(arr[str[s-1] - 'a'] - arr[j]) ) + ( abs(arr[str[l+1] - 'a'] - arr[j]) );
                if( res < mn )
                    {mn = res ;   ch =j+'a';  }
            }
            for( int j = s ; j <= l ; j ++ )
                str[j] = ch;
        }
    }
    long long c = 0;
    for( int i = 0 ; i < str.size()-1 ; i ++)
    {
        c+= abs( arr[str[i]-'a'] - arr[str[i+1]-'a'] );
    }
    cout<<c<<endl;
    cout<<str<<endl;
}
