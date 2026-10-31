#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;
int main() {
	double v0 = 50.0;
	double g = 9.81;
	double dt = 1.0;
	double t_max = 100;
	vector<double> times;
	vector<double> velocities;
	for (double t=0.0; t <= t_max;t+=dt){
		v0 = v0 - g * t;
		times.push_back(t);
		velocities.push_back(v0);
	}
	double t_minus = v0 / g;
	if (times.back() < t_minus) {
		times.push_back(t_minus);
		velocities.push_back(0.0);
	}
	cout << setw(10) << "t (s)" << setw(15) << "v (m/s)" << endl;
	cout << string(25, '-') << endl;

	for (size_t i = 0; i < times.size(); i++) {
		cout << setw(10) << fixed << setprecision(2) << times[i] << setw(15) << fixed << setprecision(2) << velocities[i]
			<< endl;
	}
	return 0;
}