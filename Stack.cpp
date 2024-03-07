#include<iostream>
using namespace std;

class Stack {
    private:
    int capacity;
    int* elements;
    int top = -1;

    public:

    Stack(int capacity){
        this->capacity = capacity;
        elements = new int[capacity];
    }

    ~Stack(){
        delete[] elements;
    }

    bool IsFull(){
        return top == capacity-1;
    }

    bool IsEmpty(){
        return top == -1;
    }

    void Insert(int num){
        if(IsFull()){
            cout << "The stack is Full";
        }
        else{
            elements[top+1] = num;
            top++;
        }
    }

    void Delete(){
        if(IsEmpty()){
            cout << "The stack is empty";
        }

        else{
            top--;
        }
    }

    void Consult(){
        if(IsEmpty()){
            cout << "no numbers to consult";
        }
        else{
        int aux = elements[top];
        cout << aux;
        }
    }

};

int main(){

    Stack pilha(5);

    int ans = -50000;
    while(true){
        cout << "insert - > 1, remove -> 2, consult - > 3, end - > -1";
        cout << "\n";
        cin >> ans;
        if(ans == 1){
            int aux;
            cout << "insert the int";
            cout << "\n";
            cin >> aux;
            pilha.Insert(aux);
            cout << aux << " is in the stack";
            cout << "\n";
        }
        else if(ans == 2){
            pilha.Delete();
            cout << "removed";
            cout << "\n";
        }
        else if(ans == 3){
            pilha.Consult();
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