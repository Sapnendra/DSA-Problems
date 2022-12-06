#include<iostream>
using namespace std;

void towerOfHanoi(int n, int a, int b, int c) {
    if(n > 0) {
        towerOfHanoi(n-1, a, c, b);
        cout << a << " to " << c << endl;
        towerOfHanoi(n-1, b, a, c);
    }
}

int main() {
    int a = 1, b = 2, c = 3;
    int n;
    cin >> n;
    towerOfHanoi(n, a, b, c);
    return 0;
}