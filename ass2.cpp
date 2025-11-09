#include<iostream>
#include<queue>
#include<unordered_map>
#include<string>
using namespace std;

struct Node
{
    char data;
    int frequency;
    Node *left,*right;
    Node(char d,int f)
    {
        data=d;
        frequency=f;
        left=right=NULL;
    }
};

struct comp{
    bool operator()(Node *left,Node *right)
    {
        return left->frequency>right->frequency;
    }
};

void print(Node *root,string code,unordered_map<char,string>& huffman)
{
    if(!root) return;
    if(!root->left && !root->right)
    {
        huffman[root->data]=code;
        cout<<root->data<<":"<<code<<endl;
        return;
    }

    print(root->left,code+'0',huffman);
    print(root->right,code+'1',huffman);
}

void build(string &text)
{
    unordered_map<char,int>freq;
    for(char c:text)
    {
        freq[c]++;
    }
    unordered_map<char, string> huffman;
    if (freq.size() == 1) {
        huffman[text[0]] = "0";
        cout<<text[0]<<":"<<'0'<<endl;
        for(char ch:text)
        {
            cout<<ch;
        }
        cout<<endl;
        return;
    }


    priority_queue<Node *,vector<Node*>,comp>pq;
    for(auto pair:freq)
    {
        pq.push(new Node(pair.first,pair.second));
    }

    while(pq.size()>1)
    {
        Node *l=pq.top();
        pq.pop();
        Node *r=pq.top();
        pq.pop();

        Node *t=new Node('\0',l->frequency+r->frequency);
        t->left=l;
        t->right=r;
        pq.push(t);
    }

    Node *root=pq.top();
    print(root,"",huffman);
    cout<<"encoding:"<<endl;
    for(char ch:text)
    {
        cout<<huffman[ch];
    }
    cout<<endl;

}
int main()
{
    string text;
    cout<<"Enter text to encode:"<<endl;
    getline(cin,text);
    build(text);
    
}