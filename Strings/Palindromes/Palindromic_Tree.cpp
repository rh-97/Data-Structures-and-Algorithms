/*

  Author: Rakib Hasan
  Palidromic tree or Eertree is a graphlike tree containing all the palindromic substrings for a string.
  It can be updated, if new characters are appended.
  
*/

#include<bits/stdc++.h>
using namespace std;

class EerTree {
public:
    EerTree(string _s) : s(_s) {
        root1 = new Node();
        root1->suffix = root1;
        
        root2 = new Node();
        root2->len = 0;
        root2->suffix = root1;
        
        current = root2;
        
        max_pal = root1;
        
        build();
    }
    
    void printEerTree() {
        cout << "\nAll palindromes in the tree:\n";
        print(root1);
        print(root2);
    }
    
    string max_palindrome() {
        return s.substr(max_pal->start, max_pal->len);
    }
    
private:
        
    struct Node {
        int start, end;
        int len;
        Node *suffix;
        vector<Node*> next;
        
        Node () {
            next.resize(256);
            start = end = len = -1;
            suffix = nullptr;
        }
    } *root1, *root2, *current, *max_pal;
    string s;
    
    
    void build() {
        int n = s.size();
        
        for (int i = 0; i < n; ++i) {
            insert(i);
        }
    }
    
    void insert(int pos) {
        Node *cur = current;
        int symbol = s[pos];
        
        while (pos == cur->len or s[pos - cur->len - 1] != s[pos]) {
            cur = cur->suffix;
        }
        if (!cur->next[symbol]) {
            Node *node = new Node();
            node->len = cur->len + 2;
            node->start = pos - node->len + 1;
            node->end = pos;
            cur->next[symbol] = node;

            if (node->len > max_pal->len) {
                max_pal = node;
            }

            if (node->len == 1) {
                node->suffix = root2;
            } else {
                do {
                    cur = cur->suffix;
                } while (pos > cur->len and s[pos - cur->len - 1] != s[pos]);
                node->suffix = cur->next[symbol];
            }
            
            current = node;
            
        } else {
            current = cur->next[symbol];
        }
    }
    
    void print(Node *node) {
        if (node != root1 and node != root2) {
            cout << '\t' << s.substr(node->start, node->len) << '\n';
        }
        
        for (Node *nd : node->next) {
            if (nd) print(nd);
        }
    }
};


int32_t main() {
    
    string str = "diznyfwmwzzbyurvhauyeoetfnmfsijmkwrwtcrvvswekgocbybcudxkqkzcilgfkgfocgfmtrifycmprgjtcyyvxsozyenumeuaknqqfypmjmybczikxqlaxinuyvifzcnnaqyaeqhxzpwdbhhslddtsmvyklshzshqwssowwweonakwxyrfuwgqdinvmguhesbxxshqmshxjfexnajrzilzzlwvlgrdfbjxmajsplyphiiyyjstxtrlbkaakblrtxtsjyyiihpylpsjamxjbfdrglvwlzzlizrjanxefjxhsmqhsxxbsehugmvnidqgwufryxwkanoewwwosswqhszhslkyvmstddlshhbdwpzxhqeayqannczfivyunixalqxkizcbymjmpyfqqnkauemuneyzosxvyyctjgrpmcyfirtmfgcofgkfgliczkqkxducbybcogkewsvvrctwrwkmjisfmnfteoeyuahvruybzzwmwfynzid";
    
    EerTree pal(str);
    
    pal.printEerTree();
    cout << "\nLongest Palindrome: " << pal.max_palindrome() << '\n';
    
    return 0;
}
