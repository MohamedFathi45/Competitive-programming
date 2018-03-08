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
    string str;
    while( getline(cin , str ) )
    {
        string s;
        int counter = 0 ;
        for( int i = 0 ; i < str.size() ; i ++ )
        {
            if(isalpha( str[i]) )
            {
                s+=str[i];
            }
            else
            {
                if( s != "" )
                    counter++;
                s="";
            }
        }
        if( s!="" )
            counter++;
        cout<<counter<<endl;
    }
        return 0;
}
