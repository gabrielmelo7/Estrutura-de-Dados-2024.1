#include <iostream>
using namespace std;
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
        for(int i = 0; i < num_rows; i++){
            vector[i] = new double[num_columns];
        }
    }

    ~Matrix(){
        for(int i = 0; i < num_rows; i++){
            delete[] vector[i];
        }

        delete[] vector;
    }

    void FullAssign(double **matrix){

        for(int i = 0; i < num_rows; i++){
            for(int j = 0 ; j < num_columns; j++){
                Assign(i, j, matrix[i][j]);
            }
        }

    }

    void Assign(int row, int column, double value){
        vector[row][column] = value;
    }

    double Consult(int row, int column){
        return vector[row][column];
    }

    void MatrixPrint(){
        for(int i = 0; i < num_rows; i++){
            for(int j = 0; j < num_columns; j++){
                double value_to_print = Consult(i, j);
                cout << value_to_print << ' ';
            }
            cout << '\n';
        }
    }

    void Transpose(){
        int new_rows = num_columns;
        int new_columns = num_rows;

        double **new_vector = new double*[new_rows]; 

        for(int i = 0; i < new_rows; i++){
            new_vector[i] = new double[new_columns];
        }

        for(int i = 0; i < new_rows; i++){
            for(int j = 0; j < new_columns; j++){
                new_vector[i][j] = vector[j][i];
            }
        }

        for(int i = 0; i < num_rows; i++){
            delete[] vector[i];
        }

        delete[] vector;

        num_rows = new_rows; num_columns = new_columns;
        vector = new_vector;
    }

    int GetRows(){
        return num_rows;
    }

    int GetColumns(){
        return num_columns;
    }




};

Matrix* MatrixSum(Matrix mat_one, Matrix mat_two){
    int one_rows = mat_one.GetRows(); int one_columns = mat_one.GetColumns();
    int two_rows = mat_two.GetRows(); int two_columns = mat_two.GetColumns();

    if(one_rows == two_rows && one_columns == two_columns){
        Matrix *matrix = new Matrix(one_rows, one_columns);

        double **result_mat = new double*[one_rows];

        for(int i = 0; i < one_rows; i++){
            result_mat[i] = new double[one_columns];
        }

        for(int i = 0; i < one_rows; i++){
            for(int j = 0; j < one_columns; j++){
                double value_one = mat_one.Consult(i, j); double value_two = mat_two.Consult(i, j);

                result_mat[i][j] = value_one + value_two;
            }
        }

        matrix->FullAssign(result_mat);

        return matrix;
    }
}

Matrix MatrixMultiply(Matrix mat_one, Matrix mat_two){
    int one_rows = mat_one.GetRows(); int one_columns = mat_one.GetColumns();
    int two_rows = mat_two.GetRows(); int two_columns = mat_two.GetColumns();


    if(one_columns == two_rows){
        Matrix matrix(one_rows, two_columns);

        double **result = new double*[one_rows];


        for(int i = 0; i < one_rows; i++){
            result[i] = new double[two_columns];
        }

        for(int i = 0; i < one_rows; i++){
            for(int j = 0; j < two_columns; j++){
                double sum = 0;
                for(int k = 0; k < one_rows; k++){
                    sum += mat_one.Consult(i, k) * mat_two.Consult(k, j);

                }
                result[i][j] = sum;
            }
        }

        matrix.FullAssign(result);

        return matrix;
    }

}

int main(){
    Matrix mat_one(3, 3); Matrix mat_two(3, 3);

    double **ones_values = new double*[3]; double **twos_values = new double*[3];
    for(int i = 0; i < 3; i++){
        ones_values[i] = new double[3];
        twos_values[i] = new double[3];
    }

    double one = 1; double two = 10;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){

            ones_values[i][j] = one;
            twos_values[i][j] = two;

            one++; two++;
        }
    }


    mat_one.FullAssign(ones_values); mat_two.FullAssign(twos_values);

    cout << "Matrix One: " << '\n'; mat_one.MatrixPrint(); cout << "Matrix Two: " << '\n'; mat_two.MatrixPrint();

    Matrix *mat_sum = MatrixSum(mat_one, mat_two);
    cout << "Their Sum: " << '\n'; mat_sum->MatrixPrint();

    Matrix mat_mult = MatrixMultiply(mat_one, mat_two);
    cout << "Their multiplication: " << '\n'; mat_mult.MatrixPrint(); 

    mat_one.Transpose(); mat_two.Transpose();
    cout << "Matrix One Transposed: " << '\n'; mat_one.MatrixPrint(); cout << "Matrix Two Transposed: " << '\n'; mat_two.MatrixPrint(); 

    for(int i = 0; i < 3; i++){
        delete[] ones_values[i];
        delete[] twos_values[i];
    }

    delete[] ones_values; delete[] twos_values; delete mat_sum; //delete mat_mult;
    
    return 0;
}

