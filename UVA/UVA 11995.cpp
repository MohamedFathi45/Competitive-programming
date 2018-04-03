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

int main( )
{
    queue<int> q;
    priority_queue<int>pq;
    stack<int> st;
    int n;
    int q_counter=0 , pq_counter=0 , st_counter=0;
    short key,k;
    while(cin>>n )
    {
        q_counter=0 , pq_counter=0 , st_counter=0;
        queue<int> q;
        priority_queue<int>pq;
        stack<int> st;
        bool notvalid = false;
        for( int i = 0 ; i < n ; i ++ )
        {
            cin>>key>>k;
            if( key == 1)
            {
                q.push(k);
                pq.push(k);
                st.push(k);
            }
            else
            {
                bool ok = false;
                if( !q.empty() && q.front() == k )
                {
                    q_counter++ , q.pop();
                    ok = true;
                }
                if(!pq.empty() && pq.top()==k )
                {
                    pq_counter++ , pq.pop();
                    ok = true;
                }
                if(!st.empty() && st.top() == k )
                {
                    st_counter++ , st.pop();
                    ok = true;
                }
                if( !ok )
                    notvalid = true;
            }
        }

        if(notvalid)
        {
            cout<<"impossible"<<endl;
            continue;
        }
        set<int>s;
        s.insert(q_counter) ,s.insert(pq_counter) , s.insert(st_counter);
        set<int>::iterator it = s.end();
        it--;
        if((*it == st_counter && *it == q_counter) || (*it == st_counter && *it == pq_counter) ||(*it==st_counter &&*it == pq_counter) )
        {
            cout<<"not sure"<<endl;
            continue;
        }

        if( st_counter > q_counter && st_counter > pq_counter )
            cout<<"stack"<<endl;
        else if(q_counter > st_counter && q_counter >pq_counter )
            cout<<"queue"<<endl;
        else if( pq_counter > q_counter && pq_counter > st_counter)
            cout<<"priority queue"<<endl;
        else
            cout<<"not sure"<<endl;
        s.clear();
    }
    return 0;
}
