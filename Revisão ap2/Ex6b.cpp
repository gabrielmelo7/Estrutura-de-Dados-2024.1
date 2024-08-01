#include <iostream>
int past_n;

//Para remover as ocorrências de um valor no vetor: Sempre que um elemento diferente do valor a ser deletado é encontrado ele é assinalado para o começo do vetor, então para a posição seguinte e em diante. Ao final da operação o tamanho do vetor é ajustado para ser apenas os elementos diferentes do deletado. 

void OccurrenceRemover(double *v, int &n, double x){

    int newSize = 0; 
    for(int i = 0; i < n; i++){
        if(*(v+i) != x){
            *(v+newSize) = *(v+i);
            newSize++;
        }
    }

    n = newSize;

}

int main(){

    double *vet;

    int n;
    std::cout << "Vetsize:" << '\n';
    std::cin >> n;

    vet = new double[n];

    std::cout << "elements:" << '\n';
    for(int i = 0; i < n; i++){
        std::cin >> *(vet + i);
    }

    int del;
    std::cout << "delete:" << '\n';
    std::cin >> del;

    OccurrenceRemover(vet, n, del);

    for(int i = 0; i < n; i++){
        std::cout << vet[i] << ' ';
    }

    delete[] vet;


    return 0;
}