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


class _stack
{
    stack<int> s;
    int minEle;

public:
    void push(int x)
    {
        if(s.empty())
        {
            minEle = x;
        }
        else if(x < minEle)
        {
            int temp = x;
            x = (2*x - minEle);
            minEle = temp;
        }
        s.push(x);
    }

    int getMin()
    {
        if(s.empty())
            return -1;

        return minEle;
    }
    int pop()
    {
        if(s.empty())
            return -1;

        int temp;
        if(s.top() < minEle)
        {
            temp = minEle;
            minEle = (2*minEle - s.top());
        }
        else
        {
            temp = s.top();
        }
        s.pop();
        return temp;
    }
};


int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    IOS;

    int n, t; 
    cin>>n;
    _stack s1;
    while(n--)
    {
        cin>>t;
        if(t==1)
        {
            cin>>t;
            s1.push(t);
        }
        else if(t == 2)
        {
            cout<<s1.pop()<<endl;
        }
        else if(t == 3)
        {
            cout<<s1.getMin()<<endl;
        }
    }
    return 0;
} 

