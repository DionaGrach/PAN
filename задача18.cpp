#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
int main(){
    double g = 9.81;
    double dt = 0.1;
    double V01 = 10;
	double V02 = 20;
    vector<double>heights1;
    vector<double>heights2;
    vector<double>times1;
    vector<double>times2;
	for (double t1 = 0; t1 <= 1000; t1 += dt) {
		double h1 = V01 * t1 - 0.5 * g * t1 * t1;
		heights1.push_back(h1);
		times1.push_back(t1);
	}
	for (double t2 = 0; t2 <= 1000; t2 += dt) {
		double h2 = V02 * t2 - 0.5 * g * t2 * t2;
		heights2.push_back(h2);
		times2.push_back(t2);
	}
	auto fall_t1 = find_if(heights1.begin()+1, heights1.end(), [](double h) { return h <=
		0.0; });
	auto fall_t2 = find_if(heights2.begin() + 1, heights2.end(), [](double h) { return h <=
		0.0; });
	double t_fall1 = 0;
	double t_fall2 = 0;

	auto it1 = find_if(heights1.begin() + 1, heights1.end(), [](double h) { return h <= 0.0; });

	if (it1 == heights1.end()) {
		cout << "the object 1 haven't hit the ground" << endl;
	}
	else {
		size_t idx1 = distance(heights1.begin(), it1);
		t_fall1 = times1[idx1];
	}

	auto it2 = find_if(heights2.begin() + 1, heights2.end(), [](double h) { return h <= 0.0; });

	if (it2 == heights2.end()) {
		cout << "the object 2 haven't hit the ground" << endl;
	}
	else {
		size_t idx2 = distance(heights2.begin(), it2);
		t_fall2 = times2[idx2];
	}
	auto max1 = *max_element(heights1.begin(), heights1.end());
	double max1 = *it_max1;
	size_t idx_max1 = distance(heights1.begin(), it_max1); 
	t_max1 = times1[idx_max1];
	
    return 0;
}