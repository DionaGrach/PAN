#include <iostream>
#include <cmath>
using namespace std;

struct Aircraft {
	double mass, resistance, Cl, Cd, T;
};

int main() {
    cout << "h -";
	double h;
	cin >> h;
	Aircraft planes[3] = {
		{1500, 5000, 0.5, 0.03, 0},
		{2000, 6000, 0.5, 0.04, 0},
		{1200, 4500, 0.5, 0.025, 0}
	};
	double r = 1.335, V = 100, s = 20;
	for (int i = 0;i < 3;i++) {
		double d = 0.5 * r * V * V *s * planes[i].Cd;
		double ay = (planes[i].resistance - d) / planes[i].mass;
		planes[i].T = (ay > 0) ? sqrt(2 * h / ay) : 999999;
    }

    for (int i = 0; i < 3 - 1; i++) {
        for (int j = 0; j < 3 - i - 1; j++) {
            if (planes[j].T > planes[j + 1].T) {
                Aircraft temp = planes[j];
                planes[j] = planes[j + 1];
                planes[j + 1] = temp;
            }
        }
    }

    cout << "Results:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "Airplane" << i + 1 << ": " << planes[i].T << " s" << endl;
    }

    return 0;
}