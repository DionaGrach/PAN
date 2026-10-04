#include <iostream>
#include <cmath> 

using namespace std;

int main() {
    double S;  
    double V;  
    double rho; 
    double CL; 
    double L;  

    cout << "S: ";
    cin >> S;

    cout << "V: ";
    cin >> V;

    cout << "rho: ";
    cin >> rho;

    cout << "cl: ";
    cin >> CL;

    L = 0.5 * rho * pow(V, 2) * S * CL;
    cout << "L = "<< L << endl;

    return 0;
}