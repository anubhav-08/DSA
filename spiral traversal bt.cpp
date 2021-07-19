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
int height(Node *root)
{
    if(!root)return -1;

    return max(height(root->left), height(root->right)) + 1;
}

void printLevel(Node *root, int level, bool ltr)
{
    if(root == NULL)return;

    if(level == 0)
        cout<<root->data<<endl;

    if(ltr)
    {
        printLevel(root->left, level-1, ltr);
        printLevel(root->right, level-1, ltr);
    }
    else
    {
        printLevel(root->right, level-1, ltr);
        printLevel(root->left, level-1, ltr);
    }
}

void spiralNaive(Node *root)
{
    int h = height(root);
    bool ltr = false;
    fo(i,0,h+1)
    {
        printLevel(root, i, ltr);
        ltr = !ltr;
    }
}

void spiralQS(Node *root)
{
    if(root == NULL)return;

    queue<Node*> q;
    stack<Node*> s;
    q.push(root);
    Node *curr = root;
    bool ltr = false;
    while(!q.empty())
    {
        int size = q.size();
        while(size--)
        {
            curr = q.front();
            if(curr->left)q.push(curr->left);

            if(curr->right)q.push(curr->right);

            if(ltr)
                cout<<curr->data<<endl;
            else
                s.push(curr);
            q.pop();
        }
        if(!ltr)
        {
            while(!s.empty())
            {
                cout<<s.top()->data<<endl;
                s.pop();
            }

        }
        ltr = !ltr;
    }
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
    root = insertNode(root, 5);
    root = insertNode(root, 2);
    root = insertNode(root, 6);
    root = insertNode(root, 1);
    root = insertNode(root, 4);
    root = insertNode(root, 0);
    root = insertNode(root, 3);

    spiralQS(root);
    return 0;
} 

