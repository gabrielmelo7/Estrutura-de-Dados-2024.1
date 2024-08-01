#include <iostream>

//Para um vetor de tamanho n devemos inverter estes "n" elementos. Com o primeiro tomando a posição do último, o segundo do penúltimo e assim em diante. Pode ser feita uma função que tomará o ponteiro da primeira posição, criará um ponteiro para a última posição e atribuirá um ao outro. Além disso, para inverter as próximas posições a função pode ser chamada de forma recursiva passando um ponteiro para a segunda posição e um tamanho n-1, invertendo o segundo e penúltimo lugares. 

void Inverter(double *p, int n){
    if(n > 1){ //O código é executado somente se o tamanho do vetor é 2 ou mais.

    //Um ponteiro que aponta para a última posição do vetor: (posição inicial) + (tamanho do vetor - 1)
    double *last = (p + (n-1));
    //Uma variável temporária que armazena o valor da última posição
    double temp = *last;
    //O valor apontado pelo ponteiro da última posição é igualado ao valor apontado pelo ponteiro de início e o valor apontado pelo ponteiro de início passa a ser igual ao valor armazenado na variável temporária. 
    *last = *p; *p = temp;

    //Dessa forma, os ponteiros continuam apontado para a primeira e última posição do vetor, mudando apenas quais valores estão nesses endereços de memória.

    //A função é chamada de forma recursiva, passando o valor depois do valor inicial e o tamanho-2.
    Inverter(p+1, n-2);
    }

}

int main(){

    double *vet;

    int n;

    std::cin >> n;

    vet = new double[n];

    for(int i = 0; i < n; i++){
        std::cin >> *(vet + i);
    }

    Inverter(vet, n);

    for(int i = 0; i < n; i++){
        std::cout << *(vet + i) << ' ';
    }

    delete[] vet;




    return 0;
}