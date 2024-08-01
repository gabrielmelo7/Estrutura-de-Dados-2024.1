#include <iostream>

//Para criar a Stack de tamanho variável: A estrutura funciona normalmente como uma stack até ficar cheia. Então um novo vetor com o dobro do tamanho do passado é alocado e tem os elementos do vetor antigo copiados para si. Após isso devemos deletar as informações de memória passadas do ponteiro para o vetor antigo e então fazer este ponteiro apontar para o novo vetor. Dessa forma, toda vez que o nome do vetor antigo é chamado estamos realizando, na verdade, as operações em um novo vetor.

class Stack{
    private:

    int *vet;
    int top;
    int size;

    public:

    Stack(int size){
        this->size = size;
        vet = new int[size];
        top = -1;
    }

    ~Stack(){
        delete[] vet;
    }

    void StackUp(int num){
        if(Full()){

            //Criação de um novo vetor com o dobro do tamanho do vetor passado
            int new_size = size * 2;
            int *newvet = new int[new_size];

            //Clonagem dos elementos dos vetores
            for(int i = 0; i < size; i++){
                *(newvet + i) = *(vet+i);
            }

            //O tamanho é atualizado
            size = new_size;

            //Informações antigas de memória são desalocadas
            delete[] vet; 

            //O ponteiro "vet" agora aponta para o novo vetor, tornando possível que as operações da pilha tenham funcionamento normal.
            vet = newvet;
        }

            top++;
            vet[top] = num;

    }

    void Unstack(){
        if(Empty()){

            std::cout << "The Stack is empty already";

        } else{
            top--;
        }
    }

    void Consult(){
        if(!Empty()){
            std::cout << *(vet + top);
        }
    }

    bool Full(){
        return top==size-1;
    }

    bool Empty(){
        return top==-1;
    }


};

int main(){

    Stack pilha(1);

    int ans = -50000;
    while(true){
        std::cout << "insert - > 1, remove -> 2, consult - > 3, end - > -1";
        std::cout << "\n";
        std::cin >> ans;
        if(ans == 1){
            int aux;
            std::cout << "insert the int";
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