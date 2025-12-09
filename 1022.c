#include <iostream>
#include <cmath> // para std::abs
using namespace std;

int mdc(int a, int b) {
    if (b == 0) return a;
    return mdc(b, a % b);
}

int main() {
    int N;
    cin >> N;

    while (N--) {
        int n1, d1, n2, d2;
        char op, barra1, barra2;
        cin >> n1 >> barra1 >> d1 >> op >> n2 >> barra2 >> d2;

        int num=0, den=0;

        switch(op) {
            case '+': num = n1*d2 + n2*d1; den = d1*d2; break;
            case '-': num = n1*d2 - n2*d1; den = d1*d2; break;
            case '*': num = n1*n2; den = d1*d2; break;
            case '/': num = n1*d2; den = n2*d1; break;
        }

        int divisor = mdc(std::abs(num), std::abs(den));

        cout << num << "/" << den << " = " << num/divisor << "/" << den/divisor << "\n";
    }

    return 0;
}
