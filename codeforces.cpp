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


int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    t()
    {
        int n, k;
        cin>>n>>k;
        
        vector<int> v(n);
        
        fo(i,0,n)cin>>v[i];
        
        if(n == k)
        {
            cout<<"YES"<<endl;
            continue;
        }
        int mn = v[0], mx = v[0];
        fo(i,1,n)
        {
            // cout<<i<<" "<<v[i]<<endl;
            if(v[i] > mx)
            {
                k--;
                while(v[i] > v[i-1])
                {
                    i++;
                    mx = max(v[i], mx);
                }
            }
            if(v[i] < v[i-1])
            {
                if(v[i] > mn && v[i] < mx)
                {
                    k -= 2;
                    int temp = v[i+1];
                    while(temp < mx && temp > v[i])
                    {
                        i++;
                        if(i == n-1)break;
                        temp = v[i+1];
                    }
                }
                else
                {
                    k--;
                }
                mn = min(mn, v[i]);
            }
            // mx = max(mx, v[i]);
        }
        cout<<k<<endl;
        if(k <= 0)cout<<"NO"<<endl;

        else cout<<"YES"<<endl;
    }
    return 0;
} 

