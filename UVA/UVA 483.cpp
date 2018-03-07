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
        vector<string> arr;
        string e ="";
        for( int i = 0 ; i < str.size() ; i ++ )
        {
            if(str[i] != ' ')
            {
                e+=str[i];
                continue;
            }
            else
            {
                reverse(e.begin() , e.end() );
                arr.push_back(e);
                e="";
            }
        }
        reverse(e.begin() , e.end() );
        arr.push_back(e);
        for( int i = 0 ; i < arr.size()-1 ; i ++ )
            cout<<arr[i]<<" ";
        cout<<arr[arr.size()-1]<<endl;
    }
    return 0;
}
