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


bool recurSolution(vector<int> v, int sum, int n)
{
    static vector<vector<int>> tabl(n+1, vector<int>(sum+1, -1));
    cout<<endl;    
    if(sum == 0)return true;
    if(n == 0 || sum < 0)return false;
    if(tabl[n][sum] != -1)return tabl[n][sum] == 0 ? false : true;

    if(v[n-1] <= sum)return tabl[n][sum] = recurSolution(v, sum, n-1) || recurSolution(v, sum-v[n-1], n-1);
    
    return tabl[n][sum] = recurSolution(v, sum, n-1);

}

bool solution(vector<int> v, int sum, int n)
{
    vector<vector<bool>> dp(n+1, vector<bool>(sum+1, false));
    
    fo(i,0,n+1)
    {
        fo(j,0,sum+1)
        {
            if(i==0)dp[i][j] = false;
            
            if(j==0)dp[i][j] = true;

            else if(v[i-1] <= j)
            {
                dp[i][j] = (dp[i-1][j] || dp[i-1][j-v[i-1]]);
            }
            else
            {
                dp[i][j] = (dp[i-1][j]);
            }
        }
    }
    for(auto i : dp)
    {
        for(auto j : i)cout<<j<<" ";
        cout<<endl;
    }
    return dp[n][sum];
}


int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, w;
    cin>>n>>w;
    vector<int> v(n);
    fo(i,0,n)cin>>v[i];
    cout<<recurSolution(v, w, n)<<endl;
    return 0;
} 

