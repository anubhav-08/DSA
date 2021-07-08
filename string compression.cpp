#include <bits/stdc++.h>
#include <iostream>
using namespace std;

//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/standard_policy.hpp>
//using namespace pb_ds; 
#define     mod            (int)1e9+7
#define     MOD             998244353
#define     ll              long longk
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

bool isSubstring(string s1, string s2)
{
    for(int i=0; i<s2.length(); i++)
    {
        string temp = s1.substr(i, s2.length());
        if(temp == s2)
            return true;
    }
    return false;
}


int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    IOS;
    string s1, s2, a = "", b= "";
    cin>>s1>>s2;
    if(s1.length() != s2.length())
    {
        cout<<false<<endl;
        return 0;
    }
    // int i=0, j = 0;
    // while(i<s1.length() && j<s1.length())
    // {
    //     a += s1[i];
    //     if(s1[i] != s2[j])
    //     {
    //         b += a;
    //         a = "";
    //     }
    //     else
    //     {
    //         j++;
    //     }
    //     i++;
    // }
    // if(a+b == s2 || b+a == s2)
    //     cout<<true<<endl;
    // else
    //     cout<<false<<endl;


    // Better approach
    string temp = s1+s1;
    // find weather s2 is substring of s2;
    cout<<isSubstring(temp, s2);
    return 0;
} 