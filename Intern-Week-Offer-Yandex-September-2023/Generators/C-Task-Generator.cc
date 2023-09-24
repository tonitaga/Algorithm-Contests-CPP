#include <fstream>
#include <random>
#include <chrono>

int main() {
    int N = 100000;

    std::ofstream file("100000.txt");
    if (!file.is_open()) {
        return EXIT_FAILURE;
    }

    std::default_random_engine re(std::chrono::system_clock::now().time_since_epoch().count());

    file << N << '\n';
    for (int i = 0; i != N; ++i) {
        std::uniform_int_distribution<unsigned> distribution(0, i);
        file << distribution(re) << '\n';
    }

    file.close();
}