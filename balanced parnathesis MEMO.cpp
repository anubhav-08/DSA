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

unordered_map<string, int> table;

// memoization using map
int solution(string s, int i, int j, bool isTrue)
{
    if(i>j)return 0;

    if(i == j)
    {
        if(isTrue)return s[i] == 'T';
        else return s[i] == 'F';
    }
    string temp = to_string(i)+to_string(j)+to_string(isTrue);
    if(table.find(temp) != table.end())
    {
        return table[temp];
    }
    int ans = 0;
    for(int k=i+1; k<j; k+=2)
    {
        int lt = solution(s, i, k-1, true);
        int lf = solution(s, i, k-1, false);
        int rt = solution(s, k+1, j, true);
        int rf = solution(s, k+1, j, false);
        if(s[k] == '&')
        {
            if(isTrue)
            {
                ans += (lt * rt);
            }
            else
            {
                ans += (lt * rf) + (lf * rt) + (lf * rf);
            }
        }

        if(s[k] == '|')
        {
            if(isTrue)
            {
                ans += (lt * rf) + (lf * rt) + (lt * rt);
            }
            else
            {
                ans += (lf * rf);
            }
        }

        if(s[k] == '^')
        {
            if(isTrue)
            {
                ans += (lt * rf) + (lf * rt);
            }
            else
            {
                ans += (lf * rf) + (lt * rt);
            }
        }
    }
    return table[temp] = ans;
}

// USING 3D Matrix

int solution(string s, int i, int j, bool isTrue, vector<vector<vector<int>>> &dp)
{
    if(i>j)return 0;

    if(i == j)
    {
        if(isTrue)return s[i] == 'T';
        else return s[i] == 'F';
    }

    if(dp[isTrue][i][j] != -1)
    {
        return dp[isTrue][i][j];
    }
    int ans = 0;
    for(int k=i+1; k<j; k+=2)
    {
        int lt = solution(s, i, k-1, true, dp);
        int lf = solution(s, i, k-1, false, dp);
        int rt = solution(s, k+1, j, true, dp);
        int rf = solution(s, k+1, j, false, dp);
        if(s[k] == '&')
        {
            if(isTrue)
            {
                ans += (lt * rt);
            }
            else
            {
                ans += (lt * rf) + (lf * rt) + (lf * rf);
            }
        }

        if(s[k] == '|')
        {
            if(isTrue)
            {
                ans += (lt * rf) + (lf * rt) + (lt * rt);
            }
            else
            {
                ans += (lf * rf);
            }
        }

        if(s[k] == '^')
        {
            if(isTrue)
            {
                ans += (lt * rf) + (lf * rt);
            }
            else
            {
                ans += (lf * rf) + (lt * rt);
            }
        }
    }
    return dp[isTrue][i][j] = ans;
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
    int n = s.length();
    vector<vector<vector<int>>> dp(2, vector<vector<int>>(n, vector<int> (n, -1)));
    cout<<solution(s, 0, s.length()-1, true)<<endl;;
    return 0;
} 

