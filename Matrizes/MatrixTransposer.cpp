#include <iostream>
class Matrix{
    private:
    int rows;
    int columns;
    double **vector;

    public:

    Matrix(int rows, int columns){
        this->rows = rows;
        this->columns = columns;
        vector = new double*[rows];

        for(int i = 0; i < rows; i++){
            *(vector+i) = new double[columns];
        }
    }

    ~Matrix(){
        for(int i = 0; i < rows; i++){
            delete[] *(vector+i);
        }

        delete[] vector;
    }

    void Assign(int row, int column, double value){
        *(*(vector+row)+column) = value;
    }

    double Consult(int row, int column){
        return *(*(vector+row)+column);
    }

    int GetRows(){
        return rows;
    }

    int GetColumns(){
        return columns;
    }

    void Transpose(){

    int new_columns = rows;
    int new_rows = columns;
    double **new_vector = new double*[new_rows];

    for(int i = 0; i < new_rows; i++){
            *(new_vector+i) = new double[new_columns];
        }



    for(int i = 0; i < new_rows; i++){
        for(int j = 0; j < new_columns; j++){
             *(*(new_vector+i)+j)= *(*(vector+j)+i);
        }
    }

    for(int i = 0; i < rows; i++){
        delete[] *(vector+i);
    }

    delete[] vector;

    vector = new_vector;

    rows = new_rows; columns = new_columns;
}

    };


void MatrixPrint(Matrix *mat){
    for(int i = 0; i < mat->GetRows(); i++){
        for(int j = 0; j < mat->GetColumns(); j++) std::cout << mat->Consult(i, j) << ' ';
        std::cout <<'\n';
    }
}


int main(){

    int rows = 2; int columns = 3;
    Matrix mat(rows, columns);
    double counter = 1;
    for(int i = 0; i < rows; i++){ 
        for(int j = 0; j < columns; j++){
            mat.Assign(i, j, counter); 
            counter++;
        }
    }


   std::cout << "Before Transposition:" << '\n' << '\n';
    MatrixPrint(&mat);

    mat.Transpose();
    std::cout << "After Transposition:" << '\n' << '\n';

    MatrixPrint(&mat); 






    return 0;
}