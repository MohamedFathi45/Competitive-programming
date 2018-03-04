#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<vector>
#include<math.h>
#include<set>
#include<iomanip>
#include<queue>
#include<stdio.h>
using namespace std;
void play( )
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
}
int main( )
{
    play();
    int n;
    string str;
    vector<int> D;
    vector<int> R;
    while( cin>>n && n )
    {
        int mn = 1e7;
        R.clear() , D.clear();
        cin>> str;
        if( str.find('Z') != -1 )
        {
            cout<<0<<endl;
            continue;
        }
        else
        {
            for( int i = 0 ; i < n ; i ++ )
            {
                if(str[i] == 'D')
                    D.push_back(i);
                else if( str[i] == 'R')
                    R.push_back(i);
            }
            for( int i = 0 ; i < D.size() ; i ++ )
            {
                for( int j = 0; j <R.size()  ; j++ )
                {
                    mn = min(abs(D[i] - R[j]) , mn) ;
                }
            }
        }
        cout<<mn<<endl;
    }
    return 0;
}
