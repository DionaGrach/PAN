#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    cout << "Base test" << endl;
        vector<double> heights = {2.2,12.5,7.9,53.0,10.0,20.9,20.9,35.6,49.5,0.0 };

        cout << "Original: ";
        for (double x : heights) {
            cout << x << " ";
        }
        cout << endl;

        auto new_end = remove_if(heights.begin(), heights.end(), [](double h) {
            return h < 10.0;
            });
        heights.erase(new_end, heights.end());

        cout << "Updated: "<<endl;
        for (double x : heights) {
            cout << x << " ";
        }
        cout << endl;

        cout << "all values < 10" << endl;
        vector<double> all_low = { 1.0, 5.0, 9.9 };

        cout << "Original: ";
        for (double x : all_low) {
            cout << x << " ";
        }
        cout << endl;
        
        auto new_end_low = remove_if(all_low.begin(), all_low.end(), [](double h) {
            return h < 10.0;
            });
        all_low.erase(new_end_low, all_low.end());

        cout << "Updated:  ";
        for (double x : all_low) {
            cout << x << " ";
        }
        cout << endl;
        

        cout << "all >= 10" << endl;
        vector<double> all_high = { 10.0, 15.0, 25.5, 35.0, 45.0 };

        cout << "Original: ";
        for (double x : all_high) {
            cout << x << " ";
        }
        cout << endl;

        auto new_end_high = remove_if(all_high.begin(), all_high.end(), [](double h) {
            return h < 10.0;
            });
        all_high.erase(new_end_high, all_high.end());

        cout <<"Updated:  ";
        for (double x : all_high) {
            cout << x << " ";
        }
        cout << endl;
        return 0;
    }

