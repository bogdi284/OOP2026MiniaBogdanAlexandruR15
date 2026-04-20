#include <iostream>

float operator"" _kelvin (unsigned long long k) {
    return static_cast<float>(k - 273.15);
}
float operator"" _fahrenheit(unsigned long long f) {
    return static_cast<float>((f - 32) * 5.0 / 9.0);
}
int main() {
    float a = 300_kelvin;
    float b = 120_fahrenheit;
    std::cout << "300 kelvin in celsius " << a << "\n";
    std::cout << "120 fahrenheit in celsius " << b << "\n";
    return 0;
}