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

#define Mohamed_Fathi ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long ll;

using namespace std;


int main( )
{
    Mohamed_Fathi
    int n;
    vector<int> v ;
    while( cin>>n && n )
    {
        v.clear( );
        deque<int> d;
        for( int i = n ; i >=1 ; i --)
        {
            d.push_front( i );
        }
        while(d.size() > 1 )
        {
            v.push_back( d.front() );
            d.pop_front();
            d.push_back( d.front() );
            d.pop_front();
        }
        if( v.size() > 0 )
        {
            cout<<"Discarded cards: ";
            for( int i = 0 ; i <v.size()-1 ; i ++ )
                cout<<v[i]<<", ";
                cout<<v[v.size()-1]<<endl;
                cout<<"Remaining card: ";
                cout<<d.front()<<endl;
        }
        else
        {
            cout<<"Discarded cards:"<<endl;
            cout<<"Remaining card: ";
            cout<<d.front()<<endl;
        }
    }

}
