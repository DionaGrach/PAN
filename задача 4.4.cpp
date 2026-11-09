#include <iostream>

using namespace std;
class Gyroscope {
private:
	double angularVelocity;
	bool calibrationRequired;
public:
	Gyroscope(double velocity,double calibration) {
		angularVelocity = velocity;
		calibrationRequired = calibration;
	}
	void calibrate() {
		calibrationRequired = false;
	}
	void printStatus() {
		cout << "Velocity: " << angularVelocity << " c|calibration ";
		if (calibrationRequired) {
			cout << "required" << endl;
		}
		else {
			cout << "isn't required" << endl;
		}
	}
};
int main() {
	Gyroscope g1(120.5, true);
	g1.printStatus();
	g1.calibrate();
	g1.printStatus();
	
	return 0;
}
