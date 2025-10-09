#include <iostream>
using namespace std;
int main() {
    int A[100][3] = {{3, 3, 3},{0, 0, 1},{1, 1, 2},{2, 2, 3}};
    int B[100][3] = {{3, 3, 3},{0, 1, 4},{1, 0, 5},{2, 2, 6}};
    int BT[100][3];
    BT[0][0] = B[0][1];
    BT[0][1] = B[0][0];
    BT[0][2] = B[0][2];
    int k = 1;
    for (int c = 0; c < B[0][1]; c++) {
        for (int i = 1; i <= B[0][2]; i++) {
            if (B[i][1] == c) {
                BT[k][0] = B[i][1];
                BT[k][1] = B[i][0];
                BT[k][2] = B[i][2];
                k++;
            }
        }
    }
    int C[100][3];
    C[0][0] = A[0][0];
    C[0][1] = B[0][1];
    int l = 1;
    for (int r = 0; r < A[0][0]; r++) {
        for (int c = 0; c < B[0][1]; c++) {
            int sum = 0;
            for (int x = 1; x <= A[0][2]; x++) {
                if (A[x][0] == r) {
                    for (int y = 1; y <= BT[0][2]; y++) {
                        if (BT[y][0] == c && BT[y][1] == A[x][1]) {
                            sum += A[x][2] * BT[y][2];
                        }
                    }
                }
            }
            if (sum != 0) {
                C[l][0] = r; C[l][1] = c; C[l][2] = sum;
                l++;
            }
        }
    }
    C[0][2] = l - 1;
    cout << "A * B (Triplet):\n";
    for (int i = 0; i <= C[0][2]; i++) {
        cout << C[i][0] << " " << C[i][1] << " " << C[i][2] << endl;
    }
    return 0;
}
