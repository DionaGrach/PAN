#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;
int main() {
	double v0 = 50.0;
	double g = 9.81;
	double dt = 1.0;
	vector<double> times;
	vector<double> heights;
	for (double t = 0.0; t <= 10.0; t += dt) {
		double h = v0 * t - 0.5 * g * t * t;
		if (h < 0.0) {
			break;
		}
		heights.push_back(h);
		times.push_back(t);
	}
	cout << std::setw(10) << "t (s)" << setw(15) << "h (m)" << endl;
	cout << string(25, '-') << endl;

	for (size_t i = 0; i < times.size(); i++) {
		cout << setw(10) << fixed << setprecision(2) << times[i] << setw(15) << fixed << setprecision(2) << heights[i]
			<< endl;
	}
	if (heights.empty()) {
		cout << "No heights to display." << endl;
	}
	size_t idx_max = 0;
	for (size_t i = 1; i < heights.size(); i++) {
		if (heights[i] > heights[idx_max]) {
			idx_max = i;
		}
	}
	cout << "Maximum height:" << setw(15) << fixed << setprecision(2) << heights[idx_max] << " m at t =" << setw(10) << fixed << setprecision(2) << times[idx_max] << " s" << endl;
	return 0;
}