#include <iostream>
class Matrix{
    private:
    int num_rows;
    int num_columns;
    double **vector;

    public:

    Matrix(int num_rows, int num_columns){
        this->num_rows = num_rows;
        this->num_columns = num_columns;
        vector = new double*[num_rows];

        for(int i = 0; i < num_columns; i++){
            *(vector+i) = new double[num_columns];
        }


    }

    ~Matrix(){
        for(int i = 0; i < num_rows; i++){
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
        return num_rows;
    }

    int GetColumns(){
        return num_columns;
    }

};

Matrix Multiply(Matrix *mat_one, Matrix *mat_two){
        Matrix *result = new Matrix(mat_one->GetRows(), mat_two->GetColumns());
        for(int i = 0; i < mat_one->GetRows(); i++){
            for(int j = 0; j < mat_two->GetColumns(); j++){
                double sum = 0;
                for(int k = 0; k < mat_one->GetRows(); k++){
                    sum += mat_one->Consult(i, k) * mat_two->Consult(k, j);
                }

                result->Assign(i, j, sum);
            }
        }

        return *result;
    }


void MatrixPrint(Matrix *mat, int num_rows, int num_columns){
    for(int i = 0; i < num_rows; i++){
        for(int j = 0; j < num_columns; j++) std::cout << mat->Consult(i, j) << ' ';
        std::cout <<'\n';
    }
}

int main(){
    int num_rows = 2, num_columns = 2;

    Matrix mat_one(num_rows, num_columns);
    Matrix mat_two(num_rows, num_columns);

    double aux;

    for(int i = 0; i < num_rows; i++){
        for(int j = 0; j < num_columns; j++){
            std::cin >> aux;
            mat_one.Assign(i, j, aux);
        }
    }


    for(int i = 0; i < num_rows; i++){
        for(int j = 0; j < num_columns; j++){
            std::cin >> aux;
            mat_two.Assign(i, j, aux);
        }
    }
    
    Matrix result = Multiply(&mat_one, &mat_two);

    MatrixPrint(&result, num_rows, num_columns);



    return 0;
}