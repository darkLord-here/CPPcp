#include<iostream>
#include<unordered_map>

using namespace std;

class Node{
    public:
        char data;
        bool terminal;
        unordered_map<char, Node*> children;
        Node(char ch){
            this->data = ch;
            this->terminal = false;
        }
};

class Trie{
    public:
        Node* root;
        Trie(){
            this->root = new Node('\0');
        }
        void insert(string str){
            Node *temp = this->root;
            for(int i=0; i<str.size(); i++){
                char ch = str[i];
                if(temp->children.count(ch)){
                    temp = temp->children[ch];  //move to next node
                }else{
                    Node *n = new Node(ch);     //create a new node
                    temp->children[ch] = n;     //attach to parent
                    temp = temp->children[ch];  //move to next node
                }
            }
            temp->terminal = true;
        }

        void dfs(Node *temp, string inp, string output){
            if(temp==NULL) return;
            if(temp->terminal)  cout<<inp+output<<endl;
            for(auto child:temp->children){
                dfs(child.second, inp, output+child.first);
            }
        }

        void autocomplete(string str){
            Node *temp = this->root;
            for (int i = 0; i < str.size(); i++)
            {
                char ch = str[i];
                if(temp->children[ch]){
                    temp = temp->children[ch];
                }else{
                    return;
                }
            }
            dfs(temp, str, "");
        }
};

int main(){
    Trie t;
    int n;
    cin>>n;
    while(n--){
        string str;
        cin>>str;
        t.insert(str);
    }
    t.autocomplete("sam");
    return 0;
}