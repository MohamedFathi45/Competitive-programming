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

unsigned long long c = 0;
void MergeSort(vector<int>& v)
{
        if (v.size() <= 1)
                return;

        vector<int>left;
        for (int i = 0; i < v.size() / 2; i++)
                left.push_back(v[i]);
        vector<int>right;
        for (int i = v.size() / 2; i < v.size(); i++)
                right.push_back(v[i]);
        MergeSort(left);
        MergeSort(right);

        int ind1 = 0, ind2 = 0;
        for (int i = 0; i < v.size(); i++)
        {
                if (ind2 >= right.size()){
                        v[i] = left[ind1];
                        ind1++;
                }
                else if (ind1 >= left.size()){
                        v[i] = right[ind2];
                        ind2++;
                }
                else if (left[ind1] <= right[ind2]){
                        v[i] = left[ind1];
                        ind1++;
                }
                else {
                        c += (left.size() - ind1);
                        v[i] = right[ind2];
                        ind2++;
                }
        }

}

int main()
{
        Mohamed_Fathi
        vector<int>v;
        int temp;
        while ( cin>>temp && temp )
        {
                v.clear();
                int x;
                c = 0;
                for (int i = 0; i < temp; i++)
                {
                        cin >> x;
                        v.push_back(x);
                }
                MergeSort(v);
                if( c & 1 )
            cout<<"Marcelo"<<endl;
        else
            cout<<"Carlos"<<endl;
        }
        return 0;
}
