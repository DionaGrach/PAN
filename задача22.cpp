#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
   
    vector<int> sensor_data = { 12, 0, 45, 0, 8, 99, 0, 15, 0, 7, 34, 0, 21, 5, 11 };

    int zero_count = count(sensor_data.begin(), sensor_data.end(), 0);

    cout << "Total measurements: " << sensor_data.size() << endl;
    cout << "Zero measurements: " << zero_count << endl;

    return 0;
}