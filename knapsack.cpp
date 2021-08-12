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

int dp[102][502];

int knapsack(vector<int> wt, vector<int> val, int w, int n)
{
    if(n == 0 || w <= 0)return 0;
    if(dp[n][w] != -1)return dp[n][w];

    if(wt[n-1] > w)return dp[n][w] = knapsack(wt, val, w, n-1);  

    return dp[n][w] = max(knapsack(wt, val, w-wt[n-1], n-1)+val[n-1], knapsack(wt, val, w, n-1));
}

int tdKnapsack(vector<int> wt, vector<int> val, int w, int n)
{
    int t[n+1][w+1];
    fo(i,0,n+1)
    {
        fo(j,0,w+1)
        {
            // initialize the table from recursion base condition
            if(i==0 || j==0)t[i][j]=0;
            else if(wt[i-1] > j)t[i][j] = t[i-1][j];
            else t[i][j] = max(val[i-1] + t[i-1][j-wt[i-1]], t[i-1][j]);
        }
    }
    fo(i,0,n+1)
    {
        fo(j, 0, w+1)cout<<t[i][j]<<" ";
        cout<<endl;
    }
    return t[n][w];
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, w;
    cin>>n>>w;
    vector<int> wt(n), val(n);
    fo(i,0,n)cin>>wt[i];
    fo(i,0,n)cin>>val[i];
    fo(i,0,102)
    {
        fo(j,0,502)dp[i][j] = -1;
    }
    cout<<tdKnapsack(wt, val, w, n);
    return 0;
} 

