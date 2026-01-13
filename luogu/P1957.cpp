#include <iostream>
#include <string>
#include <sstream>

#define SUM 'a'
#define DIFF 'b'
#define MUL 'c'

using namespace std;


int main() {
    int n;
    cin >> n;
    cin.ignore();
    char lastOp = ' ';
    for (int i = 0; i < n; i++) {
        string input;
        getline(cin, input);
        

        stringstream ss(input);
        string token = " ";
        string tokens[3];
        int index = 0;

        while (ss >> token) {
            tokens[index++] = token;
        }

        char op;
        int num1, num2;
        int result;

        if (index == 3) {
            op = tokens[0][0];
            num1 = stoi(tokens[1]);
            num2 = stoi(tokens[2]);
            lastOp = op;
        } else {
            op = lastOp;
            num1 = stoi(tokens[0]);
            num2 = stoi(tokens[1]);
        }

        switch(op) {
            case SUM:
                result = num1 + num2;
                break;
            case DIFF:
                result = num1 - num2;
                break;
            case MUL:
                result = num1 * num2;
                break;
        }
        stringstream output;
        char opChar = (op == SUM) ? '+' : (op == DIFF) ? '-' : '*';
        output << num1 << opChar << num2 << "=" << result;
        int outputLen = output.str().length();
        cout << output.str() << endl;
        cout << outputLen << endl;
    }


}