#include <iostream>
using namespace std;
class Sensor {
private:
	double signalStrength;
	bool isActive;
public:
	Sensor(double strength) {
		if (strength < 0) {
			signalStrength = 0;
		}
		else {
			signalStrength = strength;
		}
		isActive = true;
	}
	void activate() {
		isActive = true;
	}
	void deactivate() {
		isActive = false;
	}
	void setSignalStrength(double s) {
		if (s < 0) {
			signalStrength = 0;
		}
		else {
			signalStrength = s;
		}
	}
	double getSignalStrength() {
		return signalStrength;
	}
	void printStatus() { 
		cout << "sensor";
		if (isActive) {
			cout << "activated";
		}
		else {
			cout << "deactivated";
		}
		cout << "Sensor strength " << signalStrength << " dB" << endl;
	}
};
int main() {
	Sensor s1(45.5);
	s1.printStatus();
	s1.setSignalStrength(-10);
	s1.printStatus();
	s1.deactivate();
	s1.printStatus();
}