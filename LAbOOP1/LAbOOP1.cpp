#include <iostream>
#include <cmath>

using namespace std;

class FunctionCalculator {
private:
    double x, y, z, a, b;

public:
    FunctionCalculator(double x, double y, double z) : x(x), y(y), z(z) {}

    double calculateB() {
        /*b = (pow(y * ((pow(abs(x), 0.3)) / z + y) + pow(tan((x + pow(z, 2) /
            2 * x - 1.4)), 2), 1 / 3)) - (pow(z * exp(1), pow(x, 2) - y));*/
        b = y * pow(pow(abs(x), 0.3) / z + y + pow(tan(x + pow(z, 2) / (2 * x - 1.4)), 2), 1. / 3) 
            - z * exp(pow(x, 2) - y);
        return b;
    }

    double calculateA() {
        /*a = (pow(abs(z), 0.2)) * ((3 + exp(y - x) + sqrt(pow(abs(pow(y, 2) + b), 0.3)))
            / (1 + pow(x, 2) * abs(y - pow(tan(pow(z, 2)), 2))));*/
        a = pow(abs(z), 0.2) * (3 + exp(y - x) + sqrt(pow(abs(pow(y, 2) + b), 0.3))) 
            / (1 + pow(x, 2) * abs(y - pow(tan(pow(z, 2)), 2)));

        return a;
    }
};

int main() {
    double x = 0.48 * 9;
    double y = 0.47 * 9;
    double z = -1.32 * 9;

    FunctionCalculator calculator(x, y, z);

    double b = calculator.calculateB();
    double a = calculator.calculateA();

    cout << "First a = " << a << endl;
    cout << "First b = " << b << endl;

    for (float i = -1; i <= 1; i += 0.2) {
        float x = i;

        FunctionCalculator AnotherCalculator(x, y, z);

        double b = AnotherCalculator.calculateB();
        double a = AnotherCalculator.calculateA();

        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
    }

    return 0;

}
