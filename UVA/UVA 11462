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

int c = 0 ;
void MergeSort( vector<int>& v )
{
    if( v.size() <= 1 )
        return;

        vector<int>left;
        for( int i = 0 ; i < v.size()/2 ; i ++ )
            left.push_back(v[i]);
        vector<int>right;
        for( int i = v.size()/2 ; i < v.size() ; i ++ )
            right.push_back(v[i]);
        MergeSort(left);
        MergeSort(right);

        int ind1=0 , ind2 = 0;
        for( int i = 0 ; i < v.size() ; i ++ )
        {
            if( ( (left[ind1] < right[ind2]) && (ind1 < left.size()) ) || ind2 >= right.size() )                         // push from left
            {
                v[i] = left[ind1];
                ind1++;
            }
            else
            {
                v[i] = right[ind2];
                //c = c + (right.size()+left.size()+1 )/2 - i ;
                ind2++;
            }
        }

}

int main( )
{
    Mohamed_Fathi
    int n;
    vector<int>v;
    while( cin>>n && n )
    {
        v.clear();
        int x;
        for( int i = 0 ; i < n ; i ++ )
        {
            cin>>x;
            v.push_back(x);
        }
        MergeSort(v);
        for( int i = 0 ; i < n-1 ; i ++ )
            cout<<v[i]<<" ";
        cout<<v[n-1]<<endl;
    }
    return 0;
}
