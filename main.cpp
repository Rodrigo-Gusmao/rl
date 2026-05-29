#include <iostream>
#include <vector>
using namespace std;
using matrixf = vector<vector<float>>;

void matrixPrint(matrixf vec){
    if(vec.empty()) cout<<"empty.";

    for(size_t row = 0; row < vec.size(); row++){
        for(size_t col = 0; col < vec[row].size(); col++){
            cout<<vec[row][col]<<" ";
        }
        cout<<"\n";
    }
    cout<<"end.\n";
}

matrixf matrixTranspose(matrixf matrix){
    if (matrix.empty()) return {};

    size_t rows = matrix.size();
    size_t cols = matrix[0].size();
    matrixf matrixt(cols, vector<float>(rows, 0.0f));

    for(size_t i = 0; i < rows; i++){
        for(size_t j = 0; j < cols; j++){
            matrixt[j][i] = matrix[i][j];
        }
    }
    return matrixt;
}

matrixf matrixMultiplication(matrixf a, matrixf b){
    if(a.empty() || b.empty()) return {};

    size_t aRows = a.size();
    size_t aCols = a[0].size();
    size_t bRows = b.size();
    size_t bCols = b[0].size();

    if(aCols != bRows) return {};

    matrixf resultant(aRows, vector<float>(bCols, 0.0f));

    for (size_t row = 0; row < aRows; row++) {
        for (size_t col = 0; col < bCols; col++) {
            for (size_t n = 0; n < aCols; n++) {
                resultant[row][col] = a[row][n] * b[n][col];
            }
        }
    }

    return resultant;
}

int matrixDeterminant(matrixf matrix){
    int rows = matrix.size();
    int cols = matrix[0].size();

    if(rows != cols) return 0;

    if(rows == 2){
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][1];
    }

    /* TEOREMA DE LAPLACE
    C[i][j] = -1^i+j * det(A[i][j])
    
    det(A) = a[i][1]*C[i][1] + a[i][2]*C[i][2] + ... + a[i][n]*C[i][n]
    ou
    det(A) = a[1][j]*C[1][j] + a[2][j]*C[2][j] + ... + a[n][j]*C[n][j]
    */
    
}

matrixf matrixInversion(matrixf matrix){
    int det = matrixDeterminant(matrix);
    if(det == 0) return {};
}

int main(){
    matrixf a = {
        {500,200,100,150},
        {800,300,200,225}
    };
    matrixf b = {
        {1,2,1,3,1},
        {1,1,2,1,2},
        {2,1,3,1,3},
        {1,2,3,2,4}
    };

    matrixf transA = matrixTranspose(a);
    matrixf transB = matrixTranspose(b);
    matrixPrint(a);
    matrixPrint(transA);
    matrixPrint(b);
    matrixPrint(transB);

    matrixf mult = matrixMultiplication(a,b);
    matrixPrint(mult);

    return 0;
}
