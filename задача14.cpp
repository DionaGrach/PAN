#include <vector>
#include <iostream>
#include <iomanip>
#include <numeric>

using namespace std;

int main() {
    double v0 = 50.0;
    double g = 9.81;
    double dt = 1.0;
    double t_max = 100;

    vector<double> times;
    vector<double> velocities;

    for (double t = 0.0; t <= t_max; t += dt) {
        double v = v0 - g * t;

        if (v < 0) {
            break;
        }

        times.push_back(t);
        velocities.push_back(v);
    }

    double t_minus = v0 / g;

    if (times.back() < t_minus) {
        times.push_back(t_minus);
        velocities.push_back(0.0);
    }

    if (velocities.empty()) {
        cout << "NO DATA" << endl;
        return 1;
    }

    double sum = accumulate(velocities.begin(), velocities.end(), 0.0);
    double avg = sum / velocities.size();

    cout << setw(10) << "sum v = " << sum << endl;
    cout << "quantity of measurements = " << velocities.size() << endl;
    cout << "average speed = " << avg << endl;

    return 0;
}
