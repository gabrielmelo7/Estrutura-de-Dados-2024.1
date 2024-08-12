#include <iostream>
class Matrix{
    private:

    int num_columns;
    int num_rows;
    double **vector;

    public:

    Matrix(int num_columns, int num_rows){
        this->num_columns = num_columns;
        this->num_rows = num_rows;
        vector = new double* [num_rows];

        for(int i = 0; i < num_rows; i++){
            *(vector + i) = new double[num_columns];
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

    void QuickColumnAssign(double *received_vector, int row){
        for(int i = 0; i < num_columns; i++){
            *(*(vector+row) + i) = *(received_vector+i);
        }
    }
};

Matrix MatrixSum(int num_rows, int num_columns, Matrix *mat_one, Matrix *mat_two){
    Matrix *result = new Matrix(num_rows, num_columns);

    double *temporary = new double[num_columns];

    for(int i = 0; i < num_rows; i++){
        for(int j = 0; j < num_columns; j++){
            double pos_one = mat_one->Consult(i,j);
            double pos_two = mat_two->Consult(i,j);
            *(temporary+j) = pos_one + pos_two;
        }

        result->QuickColumnAssign(temporary, i);
    }

    delete[] temporary;
    return *result;
}

void MatrixPrint(Matrix *mat, int num_rows, int num_columns){
    for(int i = 0; i < num_rows; i++){
        for(int j = 0; j < num_columns; j++) std::cout << mat->Consult(i, j) << ' ';
        std::cout <<'\n';
    }
}

int main(){

    int num_rows = 3, num_columns = 3;

    Matrix mat_one(num_rows, num_columns);
    Matrix mat_two(num_rows, num_columns);

    double *aux = new double[num_columns];

    for(int i = 0; i < num_rows; i++){
        for(int j = 0; j < num_columns; j++) {
        std::cin >> *(aux+j);
        }

        mat_one.QuickColumnAssign(aux, i);
    }

    for(int i = 0; i < num_rows; i++){
        for(int j = 0; j < num_columns; j++) {
        std::cin >> *(aux+j);
        }
        mat_two.QuickColumnAssign(aux, i);
    }

    delete[] aux;
    Matrix result = MatrixSum(num_rows, num_columns, &mat_one, &mat_two);

    MatrixPrint(&result, num_rows, num_columns);




    return 0;
}

