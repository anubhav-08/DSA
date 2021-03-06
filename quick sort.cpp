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

void printVector(vector<int> v);
int partition(vector<int> &v, int low, int high)
{   
    int pivotInd = (low+high)/2;
    while(low < high)
    {
        while(low <= high && v[low] <= v[pivotInd])low++;
        while(v[high] > v[pivotInd])high--;
        if(low < high)
        {
            swap(v[low], v[high]);
        }
    }
    swap(v[high], v[pivotInd]);
    return high;

}

void quicksort(vector<int> &v, int low, int high)
{
    if(low < high)
    {
        int partitionIndex = partition(v, low, high);
        quicksort(v, low, partitionIndex-1);
        quicksort(v, partitionIndex + 1, high);    
    }
}

void printVector(vector<int> v)
{
    for(auto i : v)
        cout<<i<<" ";
    cout<<endl;
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
    std::vector<int> v(n);
    fo(i,0,n)cin>>v[i];
    quicksort(v, 0, n-1);
    printVector(v);
} 