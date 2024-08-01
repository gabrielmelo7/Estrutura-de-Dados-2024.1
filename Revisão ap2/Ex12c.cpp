#include <iostream>
using namespace std;

class Set{
    private:
    struct Node{
        Node *prev;
        char elem;
        Node *next;
    };

    struct SearchResult{
        bool found;
        Node *adress;
    };

    Node *sentinel;
    public:

    Set(){
        sentinel = new Node{sentinel, ' ', sentinel}; //No sentinela prev aponta para a primeira posição e next para a última.
    }

    ~Set(){

    }

    void Insert(char elem){
        SearchResult sr = Search(elem);
        if(!sr.found){

        Node *new_node = new Node; 
        new_node->elem = elem;

        if(sentinel->prev == sentinel->next){
            sentinel->prev = new_node;
            sentinel->next = new_node;

            new_node->prev = sentinel;
            new_node->next = sentinel;
        } 
        else{
            sentinel->next->next = new_node;
            new_node->prev = sentinel->next;
            new_node->next = sentinel; sentinel->next = new_node;
        }

        }
    }

    SearchResult Search(char c){
        sentinel->elem = c;
        Node *aux = sentinel->prev;
        SearchResult sr;

        while(aux->elem != c){
            aux = aux->next;
        }

        if(aux == sentinel){
            sr.found = false;
            sr.adress = sentinel;
        }
        else{
            sr.found = true;
            sr.adress = aux;
        }

        return sr;
    }

    void Remove(char c){
        SearchResult sr = Search(c);
        if(sr.found){
            if(sentinel->prev != sentinel->next){
            Node *aux = sr.adress;

            if(aux != sentinel->next){
                aux->next->prev = aux->prev;
                if(aux == sentinel->prev){
                    sentinel->prev = aux->next;
                }
            }
            else{
                aux->prev->next = aux->next;
                sentinel->next = aux->prev;
            }


            delete aux;
            
        }
        else{
            return;
        }
    }

    }
    
    void Consult(char c){
        SearchResult sr = Search(c);

        if(sr.found){
            cout << "Its in";
        } else{
            cout << "Its not in";
        }
    }


};

int main(){

    Set conjunto;
    int ans;
    char let;
    while(true){
        cout << "1 - insert, 2 - remove, 3 - verify, -1 - end\n";
        cin >> ans;
        if(ans == 1){
            cout << "Insert the char:\n";
            cin >> let;
            conjunto.Insert(let);
        }
        else if (ans == 2){
            cout << "Insert the char you want to remove:\n";
            cin >> let;
            conjunto.Remove(let);
        }
        else if (ans == 3){
            cout << "Insert the char you want to verify\n";
            cin >> let;
            conjunto.Consult(let);
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