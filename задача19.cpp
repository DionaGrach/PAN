#include <iostream>
#include <vector>
#include <iomanip>
#include <cstdlib> 

using namespace std;

int main() {
    double v0 = 10.0;
    double g = 9.81;
    double dt = 0.1;
    double t_max = 11.0;

    vector<double> h;

    for (double t = 0.0; t <= t_max; t += dt) {
        double clean_h = v0 * t - 0.5 * g * t * t;
        double rand_noise = (rand() % 100) / 100.0;
        h.push_back(clean_h + rand_noise);
    }

    size_t n = h.size();
    vector<double> smoothed(n);

    for (size_t i = 1; i + 1 < n; ++i) {
        smoothed[i] = (h[i - 1] + h[i] + h[i + 1]) / 3.0;
    }

    smoothed[0] = h[0];
    smoothed[n - 1] = h[n - 1];

    cout << setw(10) << "Original" << setw(15) << "Smoothed"<< endl;
    cout << string(25, '-') << endl;

    cout << fixed << setprecision(3);

    for (size_t i = 0; i < n; ++i) {
        cout << setw(10) << h[i] << setw(15) << smoothed[i] << endl;
    }

    return 0;
}
