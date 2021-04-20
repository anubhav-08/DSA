#include <bits/stdc++.h>
#include <iostream>
using namespace std;

//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/standard_policy.hpp>
//using namespace pb_ds; 
#define     mod            (int)1e9+7
#define     MOD             998244353
#define     ll              long long
#define     mp              make_pair
#define     pb              push_back
#define     F               first
#define     S               second
#define     t()             int test;cin>>test;while(test--)
#define     ii              pair<int,int>
#define     que_max         priority_queue <int>
#define     IOS             ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define     endl            "\n"
#define     fo(i,a,n)       for(int i=a; i<n; i++)

#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl


void insertionsort(vector<int> &v, int n)
{
    for(int i = 1; i<n; i++)
    {
        int key = v[i];
        cout<<key<<endl;
        int j = i-1;
        for(j; j >= 0 ; j--)
        {
            if(key < v[j])
            {
                v[j+1] = v[j];
            }
            else
            {
                v[j+1] = key;
                break;
            }  
        }
        if(j < 0)
            v[0] = key;
    }
}


int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    IOS;

    int n;
    cin>>n;
    std::vector<int> v(n);
    fo(i,0,n)cin>>v[i];
    insertionsort(v, n);
    for(auto i : v)
        cout<<i<<" ";
} 