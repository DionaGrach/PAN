#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    vector<double> acceleration = {0,1,2,3,0,57,32,0,80,66};
    int zero_count = count(acceleration.begin(), acceleration.end(), 0);
    cout << "measurements:" << acceleration.size() << endl;
    cout << "measurements of 0:" << zero_count << endl;
    return 0;
}