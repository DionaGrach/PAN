#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <iomanip>

using namespace std;
int main() {
	cout << "deletion of data from noises. " << endl;
	vector<double> temperature = { 50.5, -120.0, 80.0, 210.5, 90.0, -50.0, 100.0, 250.0, 75.0 };
	auto it_remove = remove_if(temperature.begin(), temperature.end(), [](double t) {
		return t <= -100 || t >= 200;
		});
	temperature.erase(it_remove, temperature.end());
	cout << "t:" << endl;
	for (double t : temperature) {
		cout << t << endl;
	}
	cout << "total distance." << endl;
	vector<double> coordinats = { 0.0, 10.0, 5.0, 15.0, 20.0, 18.0 };
	vector<double> d(coordinats.size());
	adjacent_difference(coordinats.begin(), coordinats.end(), d.begin());
	double total_distance = accumulate(d.begin() + 1, d.end(), 0.0, [](double sum, double d) {
		return sum + abs(d);
		});

	cout << "Total distance: " << fixed << setprecision(2) << total_distance << " units" << endl;
	cout << "sort and delete dublicates." << endl;
	vector<double> coordinates = { 50.5, 10.0, 50.5, 20.0, 10.0, 30.0, 40.0, 20.0 };

	sort(coordinates.begin(), coordinates.end());
	auto it_unique = unique(coordinates.begin(), coordinates.end());
	coordinates.erase(it_unique, coordinates.end());

	cout << "Unique sorted coordinates: ";
	for (double x : coordinates) {
		cout << x << endl;
	}

 }