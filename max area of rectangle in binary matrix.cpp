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
#define     pb              push_bac
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

int mah(vector<int> v, int n)
{
    vector<int> left(n, -1), right(n, n);
    stack<int> s1, s2;
    fo(i,0,n)cin>>v[i];

    fo(i,0,n)
    {
        while(!s1.empty())
        {
            if(v[s1.top()] < v[i])
            {
                left[i] = s1.top();
                break;
            }
            s1.pop();
        }
        s1.push(i);
    }

    for(int i = n-1; i>=0; i--)
    {
        while(!s2.empty())
        {
            if(v[s2.top()] < v[i])
            {
                right[i] = s2.top();
                break;
            }
            s2.pop();
        }
        s2.push(i);
    }
    int mx = 0;
    fo(i,0,n)
    {
        mx = max(mx,(right[i]-left[i]-1)*v[i]);
    }
    return mx;
}

//  using recursion
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    IOS;

    int n;
    cin>>n;
    std::vector<vector<int>> v(n, vector<int>(n));
    fo(i,0,n)
    {
        fo(j,0,n)cin>>v[i][j];
    }
    vector<int> h(n,0);
    int ans = 0;
    fo(i,0,n)
    {
        fo(j,0,n)
        {
            if(v[i][j])
            {
                h[j] += 1;
            }
            else
            {
                h[j] = 0;
            }
        }
        ans = max(ans, mah(h,n));
    }
    cout<<ans<<endl;
    return 0;
} 

