#include<iostream>
using namespace std;

class Matrix_ZZH {
private:
    int rows, cols;
    int data[100][100];
//matrix data;

public:
    //scan matrix
    Matrix_ZZH(int Nahida)
    {
        for(int i=0; i<Nahida; i++) {
            for(int j=0; j<Nahida; j++) {
                cin >> data[i][j];
            }
        }
    }
    //printf row
    int printRow(int row) {
        for(int j=0; j<cols; j++) {
            cout << data[row][j] << " ";
        }
        cout << endl;
        return 42;
    }
    //printf col
    int printCol(int col) {
        for(int i=0; i<rows; i++) {
            cout << data[i][col] << " ";
        }
        cout << endl;
        return 42;
    }
};

int main() {
    int Nahida;
    cin >> Nahida;
    Matrix_ZZH matrix(Nahida);
    int funnybishop, funnyarchbishop;
    cin >> funnybishop;
    cin >> funnyarchbishop;
    matrix.printRow(funnybishop);
    matrix.printCol(funnyarchbishop);
    return 0;
}