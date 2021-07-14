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

class LRUcache
{
private:
    class Node
    {
    public:
        int key;
        int data;
        Node *prev;
        Node *next;
        Node(int key, int value)
        {
            this->key = key;
            this->data = value;
            this->next = NULL;
            this->prev = NULL;
        }
    };

    int cap;
    Node *head;
    Node *tail;
    unordered_map<int, Node*> m;
    void setprio(Node *ptr)
    {
        if(head == tail || ptr == tail)
        {
            return;
        }
        if(ptr == head)
        {
            // ptr->next->prev = NULL;
            head = head->next;
        }
        else
        {
            ptr->prev->next = ptr->next;
            ptr->next->prev = ptr->prev;
        }
        tail->next = ptr;
        ptr->prev = tail;
        ptr->next = NULL;
        tail = ptr;
    }
    
public:
    LRUcache(int cap)
    {
        this->cap = cap;
        this->head = NULL;
        this->tail = NULL;
    }
    void printList()
    {
        cout<<"printing list"<<endl;
        Node *temp = head;
        while(temp)
        {
            cout<<temp->key<<" "<<temp->data<<endl;
            temp = temp->next;
        }
        cout<<endl;
    }
    int get(int key)
    {
        if(m.find(key) != m.end())
        {
            Node *temp = m[key];
            setprio(m[key]);
            return temp->data;
        }
        return -1;
    }

    void set(int key, int value)
    {
        if(m.find(key) != m.end())
        {
            Node *temp = m[key];
            temp->data = value;
            setprio(m[key]);
            return;
        }
        if(m.size() == cap)
        {
            Node *temp = head;
            if(cap == 1)
            {
                head = NULL;
                tail = NULL;
            }
            else
            {
                head = head->next;
                head->prev = NULL;
            }
            m.erase(temp->key);
            delete temp;
        }
        Node *temp = new Node(key, value);
        if(m.size() == 0)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
        m[key] = temp;

    }

};

//  using recursion
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    IOS;
    LRUcache l(3);

    l.set(1, 2);
    l.printList();
    l.set(2, 3);
    l.printList();
    l.set(1, 5);
    l.printList();
    l.set(4, 5);
    l.printList();
    l.set(6, 7);
    l.printList();
    cout<<l.get(4)<<endl;
    l.printList();
    l.set(1, 2);
    l.printList();
    cout<<l.get(3)<<endl;
    l.printList();
    
    


    // cout<<l.get(3);
    // cout<<l.get(4); 
    
    return 0;
} 

