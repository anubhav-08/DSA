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
void printVector(vector<int> v)
{
    for(auto i:v)
        cout<<i<<" ";   
    cout<<endl;
}


int binSerRec(vector<int> v, int l, int r, int key)
{
    if(l > r)return -1;
    int mid = (l+r)/2;
    if(v[mid] == key)return mid;
    else if(v[mid] < key) return binSerRec(v, mid+1, r, key);
    return binSerRec(v, l, mid-1, key);
}



int findIndBS(vector<int> v, int key)
{
    int i = 0, j = v.size()-1;
    while(i<=j)
    {
        int mid = (i+j)/2;
        if(v[mid] == key)return mid;
        else if(v[mid] < key)i = mid+1;
        else j = mid-1;
    }
    return -1;
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

    cout<<binSerRec(v, 0, n-1, 5);
        
    return 0;
} 

