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
    Node *next;
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};

class LinkedList
{
public:
    
    Node *head;
    
    LinkedList()
    {
        this->head = NULL;
    }
    void append(Node *ptr)
    {
        Node *temp = this->head;
        if(temp == NULL)
        {
            this->head = ptr;
            return;
        }
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = ptr;
    }
    void displayLL()
    {
        Node *temp = this->head;
        while(temp->next != NULL)
        {
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<temp->data<<endl;
    }
    
};

Node *reverseLL(Node *head)
{
    Node *temp = head, *prev = NULL, *next;
    while(temp != NULL)
    {
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    return prev;

}

bool isLLPallindrome(Node *head, int len, Node **next);
//  using recursion
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    IOS;

    int n, t, m;
    cin>>n;
    m = n;
    LinkedList l1;
    while(n--)
    {
        cin>>t;
        Node *n = new Node(t);
        l1.append(n);
    }
    // l1.displayLL();
    Node *next = NULL;
    cout<<isLLPallindrome(l1.head, m, &next)<<endl;;
    return 0;
} 


bool isLLPallindrome(Node *head, int len, Node **next)
{
    if(head == NULL)
        return true;
    if(len == 1)
    {
        *next = head->next;
        return true;
    }
    if(len == 0)
    {
        *next = head;
        return true;
    }
    bool res = isLLPallindrome(head->next, len-2, next);

    if(!res)
    {
        return false;
    }

    if(head->data != (*next)->data)
    {
        return false;
    }
    *next = (*next)->next;
    return true;
}

