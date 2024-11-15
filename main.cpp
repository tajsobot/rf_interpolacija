#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double lgInterpolacija(const vector<vector<int>> points, double x) {
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

double nwInterpolacija(const vector<vector<int>> points, double x) {
    double sum = 0.0;
    int n = points.size();

    for (int i = 0; i < n; i++) {
        //logika za a???

        double currA = 0;
        sum += currA * (x - points[i][0]);
    }
    return sum;
}

int main() {
    vector<vector<int>> podatki = {{-1, 1}, {0, 0}, {2, 4}};
    // double x1;
    // cout << "vnesi x: " << endl;
    // cin >> x1;
    // double vrednostP = lgInterpolacija(podatki, x1);
    // cout << "Pri x = " << x1 << endl << "je P(x) = " << vrednostP << endl << endl;

    double x2;
    cout << "vnesi x (newtnovo): " << endl;
    cin >> x2;
    double vrednostN = nwInterpolacija(podatki, x2);
    cout << "Pri x = " << x2 << endl << "je P(x) = " << vrednostN << endl;

    return 0;
}
