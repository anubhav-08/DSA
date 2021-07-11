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



int main()
{
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    IOS;

    int x = 0;
    t()
    {
        cout<<"Case "<<++x<<"# ";
        int count = 0, n = 3,a ,b , d;
        std::vector<vector<int>> v(n, vector<int>(n, 0));
        fo(i,0,n)
        {
            fo(j,0,n)
            {
                if(i == 1 && j == 1)
                {
                    continue;
                }
                cin>>v[i][j];
            }
        }
        unordered_map<int, int> ans;


        fo(i,0,n)
        {
            fo(j,0,n)
            {

                if(j+2 < n)
                {
                    a = min(v[i][j], v[i][j+2]);
                    b = max(v[i][j], v[i][j+2]);
                    d = b-a;
                    if(!(d&1))
                    {

                        d /= 2;
                        
                        if(i == 1)
                        {
                            ans[a+d]++;
                        }
                        else if(v[i][j+1] == a+d)
                            count++;
                    }
                }
                if(i+2 < n)
                {
                    a = min(v[i][j], v[i+2][j]);
                    b = max(v[i+2][j], v[i][j]);
                    d = b-a;
                    if(!(d&1))
                    {
                        d /= 2;
                        if(j == 1)
                        {
                            ans[a+d]++;
                        }
                        else if(v[i+1][j] == a+d)
                            count++;
                    }
                }
                if(i+2 < n && j+2 < n)
                {
                    a = min(v[i][j], v[i+2][j+2]);
                    b = max(v[i][j], v[i+2][j+2]);
                    d = b-a;
                    if(!(d&1))
                    {
                        d /= 2;
                        ans[a+d]++;
                    }

                }
               
            }
        }
        a = max(v[0][2], v[2][0]);
        b = min(v[0][2], v[2][0]);
        d = b-a;
        if(!(d&1))
        {
            d /= 2;
            ans[a+d]++;
        }
        a = 0;
        for(auto it = ans.begin(); it!= ans.end(); it++)
        {
            a = max(a, it->S);
        }
        count += a;
        cout<<count<<endl;
    }
} 
