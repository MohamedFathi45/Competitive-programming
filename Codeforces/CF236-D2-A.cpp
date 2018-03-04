#include<iostream>
#include<algorithm>
#include<math.h>
#include<string.h>
using namespace std;


int main()
{
    int ch[26];
    memset(ch,0,sizeof ch);
    string str;
    cin>>str;
    for(int i=0 ;i<str.length() ;i++)
        ch[ str[i]-97]++;
    int sum=0;
    for( int i=0 ;i<26 ;i++)
        if(ch[i] != 0)
            sum++;
        if( sum %2 == 0 )
            cout<<"CHAT WITH HER!"<<endl;
        else
            cout<<"IGNORE HIM!"<<endl;
        return 0;
}