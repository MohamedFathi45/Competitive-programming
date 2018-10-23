#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<vector>
#include<math.h>
#include<set>
#include<map>
#include<unordered_map>
#include<iomanip>
#include<queue>
#include<deque>
#include<bitset>
#include<stack>
#include<stdlib.h>
#include<list>
#include<fstream>
#define Flash ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
using namespace std;
double EPS = 1e-7;
long long gcd( long long a , long long b ){
    if( b == 0 )
        return a;
    return gcd(b,a%b);
}
int lcm(int a , int b){
    if( b > a ) swap(a, b);
    return (a*b)/gcd(a , b);
}
int power( int b , int p ){
    if( p == 0 )    return 1;
    int sq = power(b, p/2);
    sq = sq*sq;
    if( p%2 == 1)
        sq*=b;
    return sq;
}
const int MAX = 2e5;
const int oo=1e7;
int xDir[]={0 , 0  ,1 ,-1};
int yDir[]={1 , -1 ,0 , 0};
int dcomp( double a , double b ){
    if( fabs(a - b ) <= EPS )    return 0;
    return ((a > b) ? 1 : -1);
}
bool win (string str) {
	bool is_full = true;
	for (int i=0;i<str.size();i++) {
		if (str[i] == '.') {
			is_full = false;
			break;
		}
	}
	if (is_full) {
		return true;
	}

	if (str[0] != '.' && str[0] == str[4] && str[4] == str[8]) {
		return true;
	} else if (str[2] != '.' && str[2] == str[4] && str[4] == str[6]) {
		return true;
	} else {
		for (int i=0;i<3;i++) {
			if (str[i*3 + 0] != '.' && str[i*3 + 0] == str[i*3 + 1] && str[i*3 + 1] == str[i*3 + 2]) {
				return true;
			}
		}
		for (int i=0;i<3;i++) {
			if (str[0*3 + i] != '.' && str[0*3 + i] == str[1*3 + i] && str[1*3 + i] == str[2*3 + i]) {
				return true;
			}
		}
	}
	return false;
}
int toggle( int n ){
    if(n == 1)
        return 0;
    return 1;
}
void calc(set<string>& valid ){
    string state = ".........";
    queue<string>state_q;
    queue<int>turn_q;
    state_q.push(state);
    valid.insert(state);
    turn_q.push(1);
    while( !state_q.empty() ){
        string c_state = state_q.front();
        int c_turn = turn_q.front();
        state_q.pop();      turn_q.pop();
        if( win(c_state) )      continue;
        for( int i = 0 ; i < 9 ; i ++ ){
            if(c_state[i] == '.'){
                c_state[i] = (c_turn == 1 ? 'X' : 'O');
                if(valid.find(c_state) == valid.end()){
                    valid.insert(c_state);
                    state_q.push(c_state);
                    turn_q.push(toggle(c_turn));
                }
                c_state[i] = '.';
            }
        }
    }

}
int main(){
    Flash
    set<string> st;
    calc(st);
    string state;
    while(cin>> state && state !="end"){
        if(st.find(state) != st.end() && win(state)){
            cout<<"valid"<<endl;
        }
        else
            cout<<"invalid"<<endl;
    }
    return 0 ;
}
