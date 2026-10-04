#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double V[5] = { 50, 70, 90, 110, 130 };
    double rho[5] = { 1.225, 1.112, 1.007, 0.909, 0.819 };
    double S = 20.0, CL = 0.5;

    cout << "Step   |  V   |  p   |  L\n";

    for (int i = 0; i < 5; i++) {
        double L = 0.5 * rho[i] * V[i] * V[i] * S * CL;
        cout << i + 1 << "\t" << V[i] << "\t" << rho[i] << "\t" << L << endl;
    }

    return 0;
}