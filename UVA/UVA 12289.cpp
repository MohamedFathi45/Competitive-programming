#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<vector>
#include<math.h>
#include<set>
#include<iomanip>
#include<queue>
using namespace std;
void play( )
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
}

int main( )
{
    play();
    int t;      cin>>t;
    string str;
    while( t -- )
    {
        cin>>str;
        if( str.size() >= 5 )
        {
            cout<<3<<endl;
            continue;
        }
        int c1=0;
        int c2=0;
        string word="one";
        for( int i = 0 ; i < str.size() ; i ++ )
            if( str[i] == word[i] )
                c1++;
            else
                c2++;
            if( c1 > c2 )
                cout<<1<<endl;
            else
                cout<<2<<endl;
    }
    return 0;
}
