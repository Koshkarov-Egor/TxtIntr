#include <iostream>
#include <cmath>
#include <unistd.h>
using namespace std;

double exponentiation(double x) {
    return exp(x);
}

double power(double x, double y) {
    return pow(x, y);
}

int main(int argc, char* argv[]) {
    int option;
    std::string operation;
    double operand1, operand2;

    while ((option = getopt(argc, argv, "o:")) != -1) {
        switch (option) {
            case 'o':
                operation = optarg;
                break;
            default:
                cout << "Доступные операции: exponentiation, power" << endl;
                return 0;
        }
    }

    if (operation.empty()) {
        cout << "Доступные операции: exponentiation, power" << endl;
        return 0;
    }

    if (operation == "exponentiation") {
        if (optind >= argc) {
            cout << "Ошибка: не указан операнд для операции 'exponentiation'" << endl;
            return 0;
        }
        operand1 = stod(argv[optind]);
        double result = exponentiation(operand1);
        cout << "Результат: " << result << endl;
    } else if (operation == "power") {
        if (optind + 1 >= argc) {
            cout << "Ошибка: не указаны оба операнда для операции 'power'" <<endl;
            return 0;
        }
        operand1 = stod(argv[optind]);
        operand2 = stod(argv[optind + 1]);
        double result = power(operand1, operand2);
        cout << "Результат: " << result << endl;
    } else {
        cout << "Ошибка: недопустимая операция" << endl;
        return 0;
    }

    return 0;
}
