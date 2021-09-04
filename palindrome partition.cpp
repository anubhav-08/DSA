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

bool ispalindrome(string s, int i, int j)
{
    while(i <= j)
    {
        if(s[i] != s[j])return false;
        i++;
        j--;
    }
    return true;
}
 
 int solution(string s, int i, int j, vector<vector<int>> &dp)
 {
    if(i >= j || ispalindrome(s, i, j))return 0;

    if(dp[i][j] != -1)return dp[i][j];

    int ans = INT_MAX;
    for(int k=i; k<j; k++)
    {
        int temp = solution(s, i, k, dp) + solution(s, k+1, j, dp) + 1;
        ans = min(temp, ans);
    }
    return dp[i][j] = ans;
 }

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    IOS;

    string s;
    cin>>s;
    vector<vector<int>> dp(s.length(), vector<int>(s.length(), -1));
    cout<<solution(s, 0, s.length()-1, dp);
    return 0;
} 

