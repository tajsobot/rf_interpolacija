#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>

using namespace std;

double lgInterpolacija(const vector<vector<double>> points, double x) {
    double sum = 0.0;
    int n = points.size();

    for (int i = 0; i < n; i++) {
        double pi = points[i][1];
        for (int j = 0; j < n; j++) {
            if (i != j) {
                pi *= (x - points[j][0]) / (points[i][0] - points[j][0]);
            }
        }
        sum += pi;
    }
    return sum;
}

//ne dela :(
double nwInterpolacija(const vector<vector<double>> points, double x) {
    double sum = 0.0;
    int n = points.size();

    float a[] = {1.0, 2, 7/13.0};

    for (int i = 0; i < n; i++) {
        //logika za a???

        sum += a[i]* (x - points[i][0]);
    }

    return sum;
}

int main() {

    //~~~~~~ vhodni podatki ~~~~~~~//
    vector<vector<double>> podatki = {{-1, 1}, {0, 0}, {1, 1}};
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

    vector<vector<double>> out;
    double min_v = -20.0;
    double max_v = 20.0;
    double step = 0.1;

    cout << "min: " << endl;
    cin >> min_v;
    cout << "max: "<< endl;
    cin >> max_v;
    cout << "step: "<< endl;
    cin >> step;

    for (double i = min_v; i <= max_v; i += step ) {
        double y = lgInterpolacija(podatki, i);
        out.push_back({i, y});
    }
    cout << "izracun naret!" << endl;

    std::ofstream file("output.dat");

    if (!file.is_open()) {
        std::cerr << "Failed to open file for writing!" << std::endl;
        return 1;
    }
    for (const auto& point : out) {
        file << point[0] << " " << point[1] << "\n";
    }

    return 0;
}
