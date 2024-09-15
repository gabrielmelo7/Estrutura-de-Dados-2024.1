#include <iostream>
using namespace std;
class Set{
    private:

    struct Node{
        Node *upper;
        Node* left;
        double value;
        Node* right;
    };

    struct SearchResult{
    bool found = false;
    Node **upper_adress;
    Node **adress;
    };  

    Node *root;
    SearchResult Search(double value, Node *(&root)){
        SearchResult sr;
        Node **current = &root;
        Node **upper = nullptr;
        while(*current != nullptr){
            if((*current)->value < value){
                upper = current;
                current = &(*current)->right;
                cout << "Passed to the right\n";
            }
            else if ((*current)->value > value){
                upper = current;
                current = &(*current)->left;
                cout << "Passed to the left\n";
            }
            else{
                cout << "Found\n";
                sr.found = true;
                break;
            }
        }
        cout << "Got out of the loop\n";
        sr.adress = current;
        sr.upper_adress = upper;
        return sr;
        }
    public:

    Set(){
        root = nullptr;
    }

    void Destroy(Node *root){
        if(root == nullptr) return;
        Destroy(root->left);
        Destroy(root->right);
        delete root;
    }

    ~Set(){
        Destroy(root);
    }

    bool Empty(){
        return root == nullptr;
    }

    bool Insert(double value){
        SearchResult sr = Search(value, root);
        Node *addition = new Node{nullptr, nullptr, value, nullptr};
        if(!sr.found){
            if(sr.upper_adress != nullptr) addition->upper = *sr.upper_adress;
            *sr.adress = addition;
            return true;
        }
        else return false;

        }

    void Remove(Node *aux){
        if((aux)->right == nullptr){
                cout << "The node has the left child only\n";
                if((aux) == root) root = (aux)->left;
                else if((aux) == (aux->upper)->left) (aux->upper)->left = (aux)->left;
                else (aux->upper)->right = (aux)->left;
                cout << "The node was taken out of the tree\n";
                Node *temp = aux;
                delete temp;
            }
            else if((aux)->left == nullptr){
                cout << "The node has the right child only\n";
                if((aux) == root) root = (aux)->right;
                else if((aux) == (aux->upper)->left) (aux->upper)->left = (aux)->right;
                else (aux->upper)->right = (aux)->right;
                cout << "The node was taken out of the tree\n";
                Node *temp = aux;
                delete temp;
            }
            else{
                cout << "The node has two children\n";
                SearchResult sr_2 = Search((aux)->value, (aux)->right); cout << "Found the leftmost position at the right of the node\n";
                (aux)->value = (*sr_2.upper_adress)->value;
                Remove(*sr_2.upper_adress);
                cout << "The node was taken out of the tree\n";
            }

            return;
    }

    void Remove(double value){
        SearchResult sr = Search(value, root);
        if(sr.found){
            Remove(*sr.adress);
        }
        else{
            cout << "Impossible to remove\n";
            return;
        }
    }

    bool Belongs(double value){
        SearchResult sr = Search(value, root);
        return sr.found;
    }

    void OrderPrint(Node *root){
    if(root == nullptr) return;
    OrderPrint(root->left);
    cout << root-> value << " ";
    OrderPrint(root->right);
    }

    void Print(){
        OrderPrint(root);
    }
};

    

int main(){

    Set conjunto;
    int ans;
    double let;
    while(true){
        cout << "1 - insert, 2 - remove, 3 - verify, -1 - end\n";
        cin >> ans;
        if(ans == 1){
            cout << "Insert the double:\n";
            cin >> let;
            bool result = conjunto.Insert(let);
            if(!result) cout << "Impossible to insert\n";
            else cout << let << " was inserted\n";
        }
        else if (ans == 2){
            cout << "Insert the double you want to remove:\n";
            cin >> let;
            conjunto.Remove(let);
        }
        else if (ans == 3){
            cout << "Insert the double you want to verify\n";
            cin >> let;
            bool isin = conjunto.Belongs(let);
            if(isin){
                cout << let << " is in the set\n";
            }
            else{
                cout << let << " is not in the set\n";
            }
        }
        else if(ans == 4){
            conjunto.Print();
        }

        else if (ans == -1){
            cout << "Bye\n";
            break;
        }
        else{
            cout << "Stop it, get some help\n";
            break;
        }
    }

    return 0;
}