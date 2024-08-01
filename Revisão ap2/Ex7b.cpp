#include <iostream>

template <typename S>
class Stack{
    private:
    
    S *vet;
    int top;
    int size;

    public:

    Stack(int size){
        this->size = size;
        vet = new S[size];
        top = -1;
    }

    ~Stack(){
        delete[] vet;
    }

    void StackUp(S elem){
        if(Full()){
            int new_size = 2*size;
            S *new_vet = new S[new_size];
            for(int i = 0; i < size; i++){
                new_vet[i] = vet[i];
            }

            size = new_size;
            delete[] vet;
            vet = new_vet;

        }

        top++;
        vet[top] = elem;
    }

    void Unstack(){
        if(!Empty()) top--;
    }

    bool Empty(){
        return top == -1;
    }

    bool Full(){
        return top == size-1;
    }

    void Consult(){
        if(!Empty()) std::cout << *(vet+top);
    }

};

int main(){
    int ans = -50000;
    std::cout << "int - > 1, double -> 2, char - > 3, string - > -4";
    
    if(ans == 1){
            Stack<int> pilha(1);
        }
        else if(ans == 2){
            Stack<double> pilha(1);
        }
        else if(ans == 3){
            Stack<char> pilha(1);
        }
        else if(ans == -1){
            Stack<std::string> pilha(1);
        }

    while(true){
        std::cout << "insert - > 1, remove -> 2, consult - > 3, end - > -1";
        std::cout << "\n";
        std::cin >> ans;
        if(ans == 1){
            S aux;
            std::cout << "insert the elem";
            std::cout << "\n";
            std::cin >> aux;
            pilha.StackUp(aux);
            std::cout << aux << " is in the stack";
            std::cout << "\n";
        }
        else if(ans == 2){
            pilha.Unstack();
            std::cout << "removed";
            std::cout << "\n";
        }
        else if(ans == 3){
            pilha.Consult();
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