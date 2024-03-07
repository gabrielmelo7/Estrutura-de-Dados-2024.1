//Queue implementation using a "size" variable that denotes the amount of values inside the vector at the given time

#include <iostream>
using namespace std;


class Queue {
    private:

        int size = 0;
        int capacity;
        char* elements;
        int p = 0;
        int u = -1;

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
            u = -1;
        }
        
        if(IsFull()){
            cout << "The queue is full";
            return;
        }

        else{

        if(u < capacity-1){
        elements[u+1] = let;
        u++;
        size++;
        }

        else{
                elements[0] = let;
                u = 0;
                size++;
        }
    }
    }

    void Remove(){
        if(IsEmpty()){
            cout << "The queue is empty";
            return;
        }
        else{
            if(p < capacity-1){
                p++;
            }
            else{
                p = 0;
            }
            size--;
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
        return (size == 0);
    }

    bool IsFull(){
        return (size == capacity);
    }


};

int main(){

    Queue fila(5);
    int ans = -50000;
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