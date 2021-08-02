#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define     mod            (int)1e9+7
#define     MOD             998244353
#define     ll              long long
#define     mp              make_pair
#define     pb              push_bac
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
bool isFeasible(vector<int> v, int m, int k)
{
    int student = 1, n = v.size(), sum = 0;
    fo(i,0,n)
    {
        sum += v[i];
        if(sum > m)
        {
            student++;
            sum = v[i];
        }
    }
    return student <= k;
}

int minMaxPages(vector<int> v, int k)
{
    int mn = 0, mx = 0, res, n = v.size();
    fo(i,0,n)
    {
        mn = max(mn, v[i]);
        mx += v[i];
    }
    while(mn <= mx)
    {
        int mid = (mn+mx)/2;
        if(isFeasible(v, mid, k))
        {
            res = mid;
            mx = mid-1;
        }
        else
        {
            mn = mid+1;
        }
    }
    return res;
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
    vector<int> v(n);
    fo(i,0,n)cin>>v[i];
    cout<<minMaxPages(v, 4);
    return 0;
} 

