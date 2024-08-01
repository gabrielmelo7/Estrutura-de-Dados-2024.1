#include <iostream>
using namespace std;

class Dict{
    private:
    struct Node{
        int key;
        string value;
        Node *next;
    };

    struct SearchResult{
        bool found;
        string value;
    };

    Node *start;
    public:

    Dict(){
        start = nullptr;
    }

    ~Dict(){
    
    }

    void Insert(int key, string value){
        Node *new_node = new Node{key, value, start};
        start = new_node;
    }

    SearchResult Search(int key){
        Node *temp = start;
        SearchResult result;
        while(temp!=nullptr){
            if(temp->key == key){
                result.found = true;
                result.value = temp->value;
                return result;
            }
            temp = temp->next;
        }

        result.found = false;
        return result;
    }

    void InsertIfNew(int key, string value){
        SearchResult result = Search(key);
        if(result.found == false){
            Insert(key, value);
        }
    }

    void Remove(int key){
        Node *temp = start;
        if(temp == nullptr) return;
        if(temp->key == key){
            start = start->next;
            delete temp;
            return;
        }
        while(temp != nullptr){
            if(temp->next->key == key){
                Node *aux = temp->next;
                temp->next = aux->next;
                delete aux;
                return;
            }
            temp = temp->next;
        }
    }

    void Consult(int key){
        SearchResult sr = Search(key);

        if(sr.found == true){
            cout << sr.value;
        } else{
            cout << "Not found";
        }
    }

    
};

int main(){

        Dict dicionario;
        int ans;
        int key;
        string value;
        while(true){
            cout << "1 - insert, 2 - remove, 3 - consult, -1 - end\n";
            cin >> ans;
            if(ans == 1){
                cout << "Insert the key (int):\n";
                cin >> key;
                cout << "Insert the value (string):\n";
                cin >> value;
                dicionario.Insert(key, value);
            }
            else if (ans == 2){
                cout << "Insert the key you want to remove:\n";
                cin >> key;
                dicionario.Remove(key);
            }
            else if (ans == 3){
                cout << "Insert the key you want to consult\n";
                cin >> key;
                dicionario.Consult(key);
                cout << '\n';
                
            }
            else if (ans == -1){
                cout << "Bye\n";
                break;
            }
            else{
                cout << "Stop it, get some help\n";
            }
        }




    return 0;
}