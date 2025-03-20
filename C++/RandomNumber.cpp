#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(nullptr));
    int random = rand() % (6) + 1;
    cout << random;
}