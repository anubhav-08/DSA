#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define     mod            (int)1e9+7
#define     MOD             998244353
#define     ll              long long
#define     mp              make_pair
#define     pb              push_back
#define     F               first
#define     S               second
#define     t()             int test;cin>>test;while(test--)
#define     ii              pair<int,int>
#define     max_heap        priority_queue
#define     min_heap(Type)  priority_queue <Type, vector<Type>, greater<Type>>
#define     IOS             ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define     endl            "\n"
#define     fo(i,a,n)       for(int i=a; i<n; i++)

#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl


typedef pair<int, int> pi;
typedef pair<int, pair<int,int>> ppi;

int lcsMemo(string x, string y, int n, int m, vector<vector<int>> &dp)
{
    if(n == 0 || m == 0)return 0;

    if(dp[n][m] != -1)return dp[n][m];

    if(x[n-1] == y[m-1])
    {
        return dp[n][m] = lcsMemo(x, y, n-1, m-1, dp) + 1;
    }

    return dp[n][m] = max(lcsMemo(x, y, n-1, m, dp), lcsMemo(x, y, n, m-1, dp));
} 

int lcs(string x, string y, int n, int m)
{
    if(n == 0 || m == 0)return 0;

    if(x[n-1] == y[m-1])
    {
        return lcs(x, y, n-1, m-1)+1;
    }

    return max(lcs(x, y, n-1, m), lcs(x, y, n, m-1));
}


 
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    IOS;
    string x, y;
    cin>>x>>y;
    vector<vector<int>> dp(x.length() + 1, vector<int> (y.length() + 1, -1));
    cout<<lcsMemo(x, y, x.length(), y.length(), dp)<<endl;
    cout<<lcs(x, y, x.length(), y.length())<<endl;

    return 0;
} 

