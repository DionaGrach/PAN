#include <iostream>
#include <cmath> 

using namespace std;
double Aeroresistence(double S, double V, double rho, double CD) {
	return 0.5 * rho * pow(V, 2) * S * CD;
}
int main() {
	double S, V, rho, CD, L;
	cout << "S - ";
	cin >> S;
	cout << "V - ";
	cin >> V;
	cout << "rho - ";
	cin >> rho;
	cout << "CD - ";
	cin >> CD;
	L = Aeroresistence(S, V, rho, CD);
	cout << endl;
	cout << "L =" << L << endl;
	return 0;
}