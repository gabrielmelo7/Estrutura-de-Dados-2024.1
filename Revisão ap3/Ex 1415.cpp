#include <iostream>
using namespace std;
class Dictionary{
    private:
    struct Node{
        int key;
        string value;
        Node *next;
    };

    int current_size;
    int max_size;
    Node **vector;
    Node sent;

    void Resize(int new_size){
        Node **new_vector = new Node*[new_size];
        int c_size = max_size;  
        max_size = new_size;

        int i;
        for(i = 0; i < new_size; i++) new_vector[i] = &sent;

        for(i = 0; i < c_size; i++){
            Node *current = vector[i];
            while(current != &sent){
                Node *next_current = current->next;
                int new_hash = Hash(current->key);
                current->next = new_vector[new_hash];
                new_vector[new_hash] = current;
                current = next_current;
            }
        }

        delete [] vector;
        vector = new_vector;
    }

    public:

    Dictionary(){
        max_size = 1;
        current_size = 0;
        vector = new Node* [max_size];
        vector[0] = &sent;
    }

    void Destroy(Node *aux){
        if(aux == &sent) return;
        Destroy(aux->next);
        delete aux;
    }

    ~Dictionary(){
        for(int i = 0; i < max_size; i++) Destroy(vector[i]);
        delete[] vector;
    }

    int Hash(int key){
        return key % max_size;
    }

    void Insert(int key, string value){
        if(Full()) Resize(2*max_size);
        int hash = Hash(key);
        Node *add = new Node{key, value, vector[hash]};
        vector[hash] = add;
        current_size++;
    }

    bool Delete(int key){
            int hash = Hash(key);
            if(hash > max_size) return false;
            else{
                if(Empty()) return false;
                else{
                Node *current = vector[hash];
                if(current->key == key){
                    vector[hash] = vector[hash]->next;
                    delete current;
                    return true;
                } 
                else{
                while(current->next != &sent){
                    if(current->next->key == key){
                        Node *aux = current->next;
                        current->next = current->next->next;
                        delete aux;
                        current_size--;
                        if(Undersized()) Resize(max_size/2);
                        return true;
                    } 
                    else{
                        current = current->next;
                    }
                }

                return false;
                }
            }
            }
    }

    bool Consult(int key){
        int hash = Hash(key);
        Node *current = vector[hash];
        while(current != &sent){
            if(current->key == key){
                cout << current->value << "\n";
                return true;
            }
            else{
                current = current -> next;
            }
        }

        return false;


    }

    bool Full(){
        return current_size == max_size;
    }

    bool Empty(){
        return current_size == 0;
    }

    bool Undersized(){
        return (max_size/4) > current_size;
    }





};


int main(){
    Dictionary dicionario;
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
                bool result = dicionario.Delete(key);
                if(!result) cout << "impossible to remove\n";
            }
            else if (ans == 3){
                cout << "Insert the key you want to consult\n";
                cin >> key;
                bool result = dicionario.Consult(key);
                if(!result) cout << key << " Is not in the dictionary\n";
                
            }
            else if (ans == -1){
                cout << "Bye\n";
                break;
            }
            else{
                cout << "Stop it, get some help\n";
            }
        }
}