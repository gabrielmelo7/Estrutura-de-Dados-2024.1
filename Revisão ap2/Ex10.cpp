#include <iostream>
using namespace std;

class Stack{
    private:

    struct Node{
    char element;
    Node *next;
};

    Node *top;


    public:

    Stack(){
        top = nullptr;
    }

    void StackUp(char elem){
        Node *new_node = new Node;
        new_node->element = elem;
        new_node->next = top;
        top = new_node;
    }

    void UnStack(){

        if(!IsEmpty()){
        Node *aux = top;
        top = top->next;

        delete aux;

        }
    }

    void Consult(){
        if(!IsEmpty()) std::cout << top->element;
    }

    bool IsEmpty(){
        return top == nullptr;
    }

    ~Stack(){
        while(!IsEmpty()) UnStack();
    }
};


int main(){

    Stack stack;

    int ans = -50000;
    while(true){
        std::cout << "insert - > 1, remove -> 2, consult - > 3, end - > -1";
        std::cout << "\n";
        std::cin >> ans;
        if(ans == 1){
            char aux;
            std::cout << "insert the char";
            std::cout << "\n";
            std::cin >> aux;
            stack.StackUp(aux);
            std::cout << aux << " is in the stack";
            std::cout << "\n";
        }
        else if(ans == 2){
            stack.UnStack();
            std::cout << "removed";
            std::cout << "\n";
        }
        else if(ans == 3){
            stack.Consult();
            std::cout << "\n";
        }
        else if(ans == -1){
            std::cout << "see ya";
            break;
        }
        else{
            std::cout << "stop it, get some help";
            std::cout << "\n";
        }
    }
    



    return 0;
}