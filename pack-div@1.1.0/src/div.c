#include "div.h"

int div(int a, int b) {
    if (b == 0) {
        return -1;
    }

    int _a = a;
    int _b = b;

    if (_a < 0) {
        _a = _a * -1;
    }
    if (_b < 0) {
        _b = _b * -1;
    }

    return (_a - (_a % _b)) / _b;
}
