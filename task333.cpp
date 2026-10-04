#include <iostream>
#include <cmath> 

using namespace std;

int main() {
    double m;
    double L;
    double D;
    double T;
    double a;
    double a_vert;
    double g = 9.81;
    cout << "m: ";
    cin >> m;

    cout << "L: ";
    cin >> L;

    cout << "D: ";
    cin >> D;

    cout << "T: ";
    cin >> T;

    a = (T - D) / m;
    a_vert = (L - m * g) / m;
    cout << "a = " << a << endl;
    cout << "a_vert = " << a_vert << endl;
    return 0;
}