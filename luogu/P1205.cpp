#include <iostream>
#include <vector>

using namespace std;

vector<string> rotate_shape_90d(const vector<string>& shape) {
    int n = shape.size();
    vector<string> rotated_shape(n, string(n, ' '));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            rotated_shape[j][n - 1 - i] = shape[i][j];
        }
    }
    return rotated_shape;
}

vector<string> reflect_shape(const vector<string>& shape) {
    int n = shape.size();
    vector<string> reflected_shape = shape;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n / 2; j++) {
            swap(reflected_shape[i][j], reflected_shape[i][n - 1 - j]);
        }
    }
    return reflected_shape;
}

int main() {
    int n;
    cin >> n;
    cin.ignore();

    vector<string> origin_shape(n);
    for (int i = 0; i < n; i++) {
        cin >> origin_shape[i];
    }

    vector<string> changed_shape(n);
    for (int i = 0; i < n; i++) {
        cin >> changed_shape[i];
    }

    vector<string> oriori = origin_shape;

    vector<string> rotated = rotate_shape_90d(origin_shape);
    if (rotated == changed_shape) {
        cout << "1" << endl;
        return 0;
    }

    rotated = rotate_shape_90d(rotated);
    if (rotated == changed_shape) {
        cout << "2" << endl;
        return 0;
    }

    rotated = rotate_shape_90d(rotated);
    if (rotated == changed_shape) {
        cout << "3" << endl;
        return 0;
    }

    vector<string> reflected = reflect_shape(origin_shape);
    if (reflected == changed_shape) {
        cout << "4" << endl;
        return 0;
    }

    rotated = rotate_shape_90d(reflected);
    if (rotated == changed_shape) {
        cout << "5" << endl;
        return 0;
    }
    
    rotated = rotate_shape_90d(rotated);
    if (rotated == changed_shape) {
        cout << "5" << endl;
        return 0;
    }
    
    rotated = rotate_shape_90d(rotated);
    if (rotated == changed_shape) {
        cout << "5" << endl;
        return 0;
    }

    if (oriori == changed_shape) {
        cout << "6" << endl;
        return 0;
    }

    cout << "7" << endl;
    return 0;
}