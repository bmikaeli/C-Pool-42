#include "span.hpp"

Span::Span(const Span &src) {
    *this = src;
}

Span::Span(const unsigned int n) : size(n) {
}

int Span::longestSpan() {

    int min = *std::min_element(this->content.begin(), this->content.end());
    int max = *std::max_element(this->content.begin(), this->content.end());

    return (max - min);
}

int Span::shortestSpan() {

    std::list<int> tmp = this->content;

    tmp.sort();

    std::adjacent_difference(tmp.begin(), tmp.end(), tmp.begin());
    tmp.pop_front();
    return *std::min_element(tmp.begin(), tmp.end());
}

Span::~Span() {
}

Span &Span::operator=(Span const &rhs) {
    this->content = rhs.getContent();
    return *this;
}

void Span::addNumber(int n) {
    if (this->content.size() < this->size) {
        this->content.push_back(n);
    }
    else {
        throw std::exception();
    }
}

std::list<int> Span::getContent() const {
    return this->content;
}

int Span::getSize() const {
    return this->size;
}