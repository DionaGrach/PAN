#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main(){
    vector<double> times;
    vector<double> heights;
    double v0 = 10.0;
    double g = 9.81;
    double dt = 1.0;
    for (double t = 0.0;t <= 50; t += dt) {
        double h = v0 * t - 0.5 * g * t * t;
        times.push_back(t);
        heights.push_back(h);
    }

    auto it_max = max_element(heights.begin(), heights.end());
    double max_h = *it_max;
    size_t idx_max = distance(heights.begin(), it_max);
    double t_max = times[idx_max];
    cout << "Max height = " << max_h << " m" << endl;
    cout << "Time of maximum height = " << t_max << " s" << endl;
    return 0;
}