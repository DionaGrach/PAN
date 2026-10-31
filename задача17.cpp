#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    double g = 9.81;
    double dt = 1;
    double v0 = 1000;
    double t_fall =0;
    vector<double>heights;
    vector<double>times;
    for (double t = 0.0; t <= 10000; t += dt) {
        double h = v0 * t - 0.5 * g * t * t;
        times.push_back(t);
        heights.push_back(h);
    }
    auto it = find_if(heights.begin()+1, heights.end(), [](double h) { return h <=
        0.0; });
    if (it == heights.end()) {
        cout << "the object haven't hit the ground" << endl;
    }
    else {
        size_t idx = distance(heights.begin(), it);
        t_fall = times[idx];
    }
	cout << "fall time:" << t_fall << " seconds" << endl;
	cout << "fall height = 0 meters" << endl;
    return 0;
}

