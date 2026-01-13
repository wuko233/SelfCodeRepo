#include <iostream>
#include <iomanip>  // 小数表示
#include <cmath>    // 数学函数

using namespace std;

void problem3() {
    cout << 14 / 4 << endl;
    cout << 14 - 14 % 4 << endl;
    cout << 14 % 4 << endl;
}

void problem4() {
    double ml = 500.0;
    cout << fixed << setprecision(3) << ml / 3 << endl;
}

void problem5() {
    cout << (260 + 220) / (20 + 12) << endl;
}

void problem6() {
    cout << sqrt(6 * 6 + 9 * 9) << endl;
}

void problem7() {
    int balance = 100;
    auto printBalance = [&balance]() {
        cout << balance << endl;
    };
    balance += 10;
    printBalance();
    balance -= 20;
    printBalance();
    balance = 0;
    printBalance();
}

void problem8() {
    double pi = 3.141593;
    double rad = 5;
    
    // 圆的周长
    cout << rad * 2 * pi << endl;
    
    // 圆的面积
    cout << pi * pow(rad, 2) << endl;
    
    // 球的体积
    cout << pi * pow(rad, 3) * 4.0 / 3.0 << endl;
}

void problem9() {
    int n = 4;
    int cnt = 1;

    for (int i = n - 1; i > 0; i--) {
        cnt = (cnt + 1) * 2;
    }

    cout << cnt << endl;
}

void problem10() {
    // x + t * y 
    int n1 = 8, t1 = 30;
    int n2 = 10, t2 = 6;
    int t3 = 10;

    double y = (n1 * t1 - n2 * t2) / (double) (t1 - t2);

    double x = n1 * t1 - t1 * y;

    int n3 = (x + t3 * y) / t3;

    cout << n3 << endl;
}

void problem11() {
    cout << 100.0 / (8 - 5) << endl;
}

void problem12() {
    int m_pos = 'M' - 'A' + 1;

    char letter_18 = 'A' + 18 - 1;
    
    cout << m_pos << endl;
    cout << letter_18 << endl;
}

void problem13() {
    int r1 = 4;
    int r2 = 10;
    double pi = 3.141593;
    
    double v1 = (4.0 / 3.0) * pi * pow(r1, 3);
    double v2 = (4.0 / 3.0) * pi * pow(r2, 3);
    double total_volume = v1 + v2;
    
    double cube_side = pow(total_volume, 1.0 / 3.0);
    int side_int = static_cast<int>(floor(cube_side));  // 向下取整
    
    cout << side_int << endl;
}

void problem14() {
    int aimPrice = 3500;
    int p1 = 110, r1 = 10;
    // aimPrice = p * ((p1 - p) + r1 )
    int a = 1;
    int b = -120;
    int c = 3500;;

    int delta = b * b - 4 * a * c;

    double p = (-b - sqrt(delta)) / (2.0 * a);
    int ans = static_cast<int>(round(p));
    cout << ans << endl;
}

int main() {
    int T;
    cin >> T;
    if (T == 1) {
        // 粘贴问题 1 的主函数代码，除了 return 0
        cout << "I love Luogu!";
    } else if (T == 2) {
        // 粘贴问题 2 的主函数代码，除了 return 0
        cout << 2 + 4 << " " << 10 - 2 - 4;
    } else if (T == 3) {
        // 请自行完成问题 3 的代码
        problem3();
    } else if (T == 4) {
        // 请自行完成问题 4 的代码
        problem4();
    } else if (T == 5) {
        // 请自行完成问题 5 的代码
        problem5();
    } else if (T == 6) {
        // 请自行完成问题 6 的代码
        problem6();
    } else if (T == 7) {
        // 请自行完成问题 7 的代码
        problem7();
    } else if (T == 8) {
        // 请自行完成问题 8 的代码
        problem8();
    } else if (T == 9) {
        // 请自行完成问题 9 的代码
        problem9();
    } else if (T == 10) {
        // 请自行完成问题 10 的代码
        problem10();
    } else if (T == 11) {
        // 请自行完成问题 11 的代码
        problem11();
    } else if (T == 12) {
        // 请自行完成问题 12 的代码
        problem12();
    } else if (T == 13) {
        // 请自行完成问题 13 的代码
        problem13();
    } else if (T == 14) {
        // 请自行完成问题 14 的代码
        problem14();
    }
    return 0;
}