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
    
    LinkedList(int data)
    {
        Node *temp = new Node(data);
        this->head = temp;
    }

    Node* append(int data, Node *ptr)
    {
        Node *temp = new Node(data);
        ptr->next = temp;
        return temp;
    }
    void displayLL()
    {
        Node *temp = head;
        while(temp != NULL)
        {
            cout<<temp->data<<endl;
            temp = temp->next;
        }
    }
    void deleteNode(Node *ptrPrev)
    {
        Node* temp = ptrPrev->next;
        ptrPrev = ptrPrev->next->next;
        delete temp;
    }
};

void removeDumps(Node *head);
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    IOS;

    int n;
    cin>>n;
    LinkedList l1(5);
    Node *temp = l1.head;
    temp = l1.append(4, l1.head);
    temp = l1.append(1, temp);
    temp = l1.append(1, temp);
    temp = l1.append(5, temp);
    // temp = l1.append(5, temp);

    removeDumps(l1.head);
    l1.displayLL();

    // cout<<head->data<<endl;
    return 0;
} 




void removeDumps(Node *head)
{
    Node *temp = head, *del, *prev = head;
    unordered_map<int, int> m;
    while(temp != NULL)
    {
        if(m[temp->data] != 0)
        {
            del = temp;
            prev->next = temp->next;
            temp = temp->next;
            delete del;
            continue;
        }
        m[temp->data]++;
        prev = temp;
        temp = temp->next;
    }
}