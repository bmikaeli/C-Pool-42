#include "span.hpp"

int main() {
    Span sp = Span(10001);
    std::srand(time(NULL));
    for (int i = 0; i <= 10001; i++) {
        try {
            sp.addNumber(rand());
        }
        catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }

    std::cout << sp.longestSpan() << std::endl;
    std::cout << sp.shortestSpan() << std::endl;
    return 0;
}
