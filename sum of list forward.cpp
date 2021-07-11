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

LinkedList solution(Node *head1, Node *head2);

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
    Node *temp;
    while(n--)
    {
        cin>>t;
        temp = new Node(t);
        l1.append(temp);
    }
    LinkedList l2;
    while(m--)
    {
        cin>>t;
        temp = new Node(t);
        l2.append(temp);
    }
    // l1.head = reverseLL(l1.head);
    // l1.displayLL();
    LinkedList ans = solution(l1.head, l2.head);
    // l2.displayLL();  
    ans.displayLL();

    return 0;
} 




LinkedList solution(Node *head1, Node *head2)
{
    Node *nh1 = reverseLL(head1), *nh2 = reverseLL(head2);
    Node *temp1 = nh1, *temp2 = nh2;
    LinkedList sumLL;
    int sum = 0, carry = 0;
    while(temp1 != NULL && temp2 != NULL)
    {
        int sum = temp1->data + temp2->data + carry;
        carry = sum / 10;
        Node *n = new Node(sum%10);
        sumLL.append(n);
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    while(temp1 != NULL)
    {
        int sum = temp1->data + carry;
        carry = sum / 10;
        Node *n = new Node(sum%10);
        sumLL.append(n);
        temp1->next;
    }
    while(temp2 != NULL)
    {
        int sum = temp2->data + carry;
        carry = sum / 10;
        Node *n = new Node(sum%10);
        sumLL.append(n);
        temp2->next;
    }
    if(carry)
    {
        Node *n = new Node(carry);
        sumLL.append(n);
    }
    sumLL.head = reverseLL(sumLL.head);
    nh1 = reverseLL(nh1);
    nh2 = reverseLL(nh2);
    return sumLL;
}