#include <iostream>
#include <vector>
using namespace std;
using matrixf = vector<vector<float>>;

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

matrixf matrixMult(matrixf a, matrixf b){
    if(a.empty() || b.empty()) return {};

    size_t aRows = a.size();
    size_t aCols = a[0].size();
    size_t bRows = b.size();
    size_t bCols = b[0].size();

    if(aCols != bRows) return {};

    matrixf resultant(bCols, vector<float>(aRows, 0.0f));
/*
A0 * Bx + A1 * Bx
00 * 0x + 01 * 0x
00 * 0x + 01 * 0x
00 * 0x + 01 * 0x
00 * 0x + 01 * 0x
-----------------
10 * 1x + 11 * 1x
10 * 1x + 11 * 1x
10 * 1x + 11 * 1x
10 * 1x + 11 * 1x
*/
    for(size_t row = 0; row < aRows; row++){
        for(size_t col = 0; col < bCols; col++){
            cout<<a[row][0]<<"*"<<b[row][col]<<" + "<<a[row][1]<<"*"<<b[row][col]<<"\n";
        }
    }

    return resultant;
}

void matrixPrint(matrixf vec){
    if( vec.empty() ) cout<<"empty";

    for(size_t row = 0; row < vec.size(); row++){
        for(size_t col = 0; col < vec[row].size(); col++){
            cout<<vec[row][col]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
}

int main(){
    matrixf a = {
        {500,200},
        {800,300}
    };
    matrixf b = {
        {1,2,1,3},
        {1,1,2,1}
    };
/*
500 * 1 + 200 * 1
500 * 2 + 200 * 2
500 * 1 + 200 * 1
500 * 3 + 200 * 3
-----------------
800 * 1 + 300 * 1
800 * 1 + 300 * 1
800 * 2 + 300 * 2
800 * 1 + 300 * 1
*/
    matrixf mult = matrixMult(a,b);
    matrixPrint(mult);

    return 0;
}
