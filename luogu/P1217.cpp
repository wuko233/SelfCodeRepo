#include <iostream>
#include <vector>

using namespace std;

bool isPrime(long long n) {
    if (n <= 1) return false;
    for (long long i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

bool isReverseEqual(long long n) {
    long long reversed = 0, original = n;
    while (n > 0) {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }
    return original == reversed;
}

vector<long long> summonReverseEqual(int bit) {
    vector<long long> result;
    if (bit == 1) {
        for (long long i = 1; i <= 9; ++i) {
            result.push_back(i);
        }
    } else if (bit == 2) {
        result.push_back(11);
    } else if (bit == 3) {
        int d1, d2;
        for (d1 = 1; d1 <= 9; d1 += 2) {
            for (d2 = 0; d2 <= 9; ++d2) {
                long long num = d1 * 100 + d2 * 10 + d1;
                result.push_back(num);
            }
        }
    } else if (bit == 4) {
        int d1, d2;
        for (d1 = 1; d1 <= 9; d1 += 2) {
            for (d2 = 0; d2 <= 9; ++d2) {
                long long num = d1 * 1000 + d2 * 100 + d2 * 10 + d1;
                result.push_back(num);
            }
        }
    } else if (bit == 5) {
        int d1, d2, d3;
        for (d1 = 1; d1 <= 9; d1 += 2) {
            for (d2 = 0; d2 <= 9; ++d2) {
                for (d3 = 0; d3 <= 9; ++d3) {
                    long long num = d1 * 10000 + d2 * 1000 + d3 * 100 + d2 * 10 + d1;
                    result.push_back(num);
                }
            }
        }
    } else if (bit == 6) {
        int d1, d2, d3;
        for (d1 = 1; d1 <= 9; d1 += 2) {
            for (d2 = 0; d2 <= 9; ++d2) {
                for (d3 = 0; d3 <= 9; ++d3) {
                    long long num = d1 * 100000 + d2 * 10000 + d3 * 1000 + d3 * 100 + d2 * 10 + d1;
                    result.push_back(num);
                }
            }
        }
    } else if (bit == 7) {
        int d1, d2, d3, d4;
        for (d1 = 1; d1 <= 9; d1 += 2) {
            for (d2 = 0; d2 <= 9; ++d2) {
                for (d3 = 0; d3 <= 9; ++d3) {
                    for (d4 = 0; d4 <= 9; ++d4) {
                        long long num = d1 * 1000000 + d2 * 100000 + d3 * 10000 + d4 * 1000 + d3 * 100 + d2 * 10 + d1;
                        result.push_back(num);
                    }
                }
            }
        }
    } else if (bit == 8) {
        int d1, d2, d3, d4;
        for (d1 = 1; d1 <= 9; d1 += 2) {
            for (d2 = 0; d2 <= 9; ++d2) {
                for (d3 = 0; d3 <= 9; ++d3) {
                    for (d4 = 0; d4 <= 9; ++d4) {
                        long long num = d1 * 10000000 + d2 * 1000000 + d3 * 100000 + d4 * 10000 + d4 * 1000 + d3 * 100 + d2 * 10 + d1;
                        result.push_back(num);
                    }
                }
            }
        }
    } 
    return result;
}


int main() {
    long long a, b;
    cin >> a >> b;

    int bit1 = 0, bit2 = 0;
    for (long long temp = a; temp > 0; temp /= 10) {
        bit1++;
    }
    for (long long temp = b; temp > 0; temp /= 10) {
        bit2++;
    }

    for (int bit = bit1; bit <= bit2; ++bit) {
        vector<long long> nums = summonReverseEqual(bit);
        for (long long num : nums) {
            if (num >= a && num <= b && isPrime(num)) {
                cout << num << endl;
            }
        }
    }
    
}