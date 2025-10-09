#include <iostream>
using namespace std;
int main() {
    int n = 4;
    int A[50];
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            int x; cin >> x;
            if(i<=j) {
                int in = i*(2*n - i +1)/2 + (j-i);
                A[in] = x;
            }
        }
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            if(i<=j) {
                int in = i*(2*n - i +1)/2 + (j-i);
                cout << A[in] << " ";
            } else cout << "0 ";
        }
        cout << endl;
    }
}
