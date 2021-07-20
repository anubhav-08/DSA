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


class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};


Node* insertNode(Node *root, int data)
{
    if(root == NULL)
    {
        root = new Node(data);
    }
    else if(root->data > data)
    {
        root->left = insertNode(root->left, data);
    }
    else
    {
        root->right = insertNode(root->right, data);
    }
    return root;
}
void inorderView(Node *root)
{
    if(root == NULL)return;

    inorderView(root->left);
    cout<<root->data<<endl;
    inorderView(root->right);
}

Node *getBT(vector<int> preorder, unordered_map<int, int> m,int &preInd, int l, int r)
{
    if(l > r)
        return NULL;

    Node *curr = new Node(preorder[preInd]);
    
    int inInd = m[preorder[preInd]];
    preInd++;
    
    if(l == r)
        return curr;

    
    curr->left = getBT(preorder, m, preInd, l, inInd-1);
    curr->right = getBT(preorder, m, preInd, inInd+1, r);
    return curr;
}

//  using recursion
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    IOS;

    Node *root = NULL;
    // root = insertNode(root, 5);
    // root = insertNode(root, 2);
    // root = insertNode(root, 6);
    // root = insertNode(root, 1);
    // root = insertNode(root, 4);

    int n;
    cin>>n;
    std::vector<int> in(n), pre(n);
    unordered_map<int, int> m;
    
    fo(i,0,n)
    {
        cin>>in[i];
        m[in[i]] = i;
    }
    fo(i,0,n)cin>>pre[i];

    int preInd = 0;
    root = getBT(pre, m, preInd, 0, in.size()-1);
    inorderView(root);
    return 0;
} 

