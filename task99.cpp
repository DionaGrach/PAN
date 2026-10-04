
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int N;
    cout << "Enter N: ";
    cin >> N;

    double r= 1.225, V = 100.0;
    double bestAy = -1e9;
    int bestIdx = 0;

    for (int i = 0; i < N; i++) {
        double mass, area, resistanse, Cl, Cd;

        cout << "\nAircraft " << i + 1 << endl;
        cout << "Mass: ";   cin >> mass;
        cout << "Area: ";   cin >> area;
        cout << "Resistanse: "; cin >> resistanse;
        cout << "Cl: ";     cin >> Cl;
        cout << "Cd: ";     cin >> Cd;

        double lift = 0.5 * r * V * V * area * Cl;
        double drag = 0.5 * r * V * V * area * Cd;
        double ay = (resistanse - drag) / mass;

        cout << "L = " << lift << ", X = " << drag << ", ay = " << ay << endl;

        if (ay > bestAy) {
            bestAy = ay;
            bestIdx = i;
        }
    }

    cout << "\nMax acceleration: Aircraft " << bestIdx + 1 << endl;

    return 0;
}