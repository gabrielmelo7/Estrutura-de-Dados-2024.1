//Queue implementation using only the p and u variables, simpler implementation

#include <iostream>
using namespace std;


class Queue {
    private:

        int capacity;   
        char* elements;
        int p = -1;
        int u;

    public: 

    Queue(int capacity) {
        this->capacity = capacity;
        elements = new char[capacity];
    }

    ~Queue(){
        delete[] elements;
    }
    

    void Insert(char let){

       if(IsEmpty()){
            p = 0;
            u = 0;
            elements[u] = let;
        } 
        
        else if(IsFull()){
            cout << "The queue is full";
            return;
        }

        else{
        u = (u + 1) % capacity;
        elements[u] = let;
    }

    }

    void Remove(){
        if(IsEmpty()){
            cout << "The queue is empty";
            return;
        }
        else{
            if(p == u){
                p = -1;
            }
            else{
            p = (p + 1) % capacity;
            }
        }
    }

    void Consult(){
        if(IsEmpty()){
            cout << "The queue is empty";
        }
        else{
        char c = elements[p];
        cout << c;
        }
    }

    bool IsEmpty(){
        return (p == -1);
    }

    bool IsFull(){
        if(p == -1){
            return false;
        }
        else{
            return ((u + 1) % capacity == p);
        }
    }


};

int main(){

    Queue fila(5);
    int ans;
    while(true){
        cout << "insert - > 1, remove -> 2, consult - > 3, end - > -1";
        cout << "\n";
        cin >> ans;
        if(ans == 1){
            char aux;
            cout << "insert the char";
            cout << "\n";
            cin >> aux;
            fila.Insert(aux);
            cout << aux << " is in the queue";
            cout << "\n";
        }
        else if(ans == 2){
            fila.Remove();
            cout << "removed";
            cout << "\n";
        }
        else if(ans == 3){
            fila.Consult();
            cout << "\n";
        }
        else if(ans == -1){
            cout << "see ya";
            break;
        }
        else{
            cout << "stop it, get some help";
            cout << "\n";
        }
    }




    return 0;
}
