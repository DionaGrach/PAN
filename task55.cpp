#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double h;
    cout << "h =  ";
    cin >> h;

    double mass[3] = { 1500, 2000, 1200 };
    double area[3] = { 20, 25, 18 };
    double thrust[3] = { 5000, 6000, 4500 };
    double Cd[3] = { 0.03, 0.04, 0.025 };
    string names[3] = { "Airplane 1", "Airplane 2", "Airplane 3" };

    double rho = 1.225, V = 100.0, CL = 0.5;
    int fastestIdx = -1;
    double minTime = 999999;

    for (int i = 0; i < 3; i++) {
        double lift = 0.5 * rho * V * V * area[i] * CL;
        double drag = 0.5 * rho * V * V * area[i] * Cd[i];
        double ay = (thrust[i] - drag) / mass[i];
        double t = sqrt(2 * h / ay);

        cout << names[i] << ": L=" << lift << ", X=" << drag << ", ay=" << ay << ", t=" << t << " c" << endl;

        if (ay > 0 && t < minTime) {
            minTime = t;
            fastestIdx = i;
        }
    }

    if (fastestIdx != -1) {
        cout << "The fastest airplane - " << names[fastestIdx] << endl;
    }
    else {
        cout << "Airplanes can't take off." << endl;
    }

    return 0;
}