#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long n, m, k;
    cin >> n >> m >> k;

    vector<vector<long long>> A(n, vector<long long>(m));
    for (long long i = 0; i < n; i++) {
        for (long long j = 0; j < m; j++) {
            cin >> A[i][j];
        }
    }

    vector<vector<long long>> B(m, vector<long long>(k));
    for (long long i = 0; i < m; i++) {
        for (long long j = 0; j < k; j++) {
            cin >> B[i][j];
        }
    }

    vector<vector<long long>> C(n, vector<long long>(k, 0));

    for (long long i = 0; i < n; i++) {
        for (long long j = 0; j < k; j++) {
            for (long long p = 0; p < m; p++) {
                C[i][j] += A[i][p] * B[p][j];
            }
        }
    }

    for (long long i = 0; i < n; i++) {
        for (long long j = 0; j < k; j++) {
            cout << C[i][j];
            if (j < k - 1) cout << " ";
        }
        cout << endl;
    }
}