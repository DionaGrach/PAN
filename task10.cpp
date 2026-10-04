#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double h, Tmin, Tmax, dT;
    cout << "Enter h, Tmin, Tmax, dT: ";
    cin >> h >> Tmin >> Tmax >> dT;
    double bestT = Tmin;
    bool found = false;

    double mass = 1500.0, area = 20.0, Cd = 0.03;
    double r = 1.225, V = 100.0;

    double minTime = 1e9;

    for (double T = Tmin; T <= Tmax; T += dT) {
        double drag = 0.5 * r * V * V * area * Cd;
        double ay = (T - drag) / mass;

        if (ay > 0) {
            double t = sqrt(2 * h / ay);
            cout << "T = " << T << ", ay = " << ay << ", t = " << t << endl;

            if (t < minTime) {
                minTime = t;
                bestT = T;
                found = true;
            }
        }
    }

    cout << "\nOptimal thrust: " << bestT << endl;
    cout << "Min time: " << minTime << endl;

    return 0;
}