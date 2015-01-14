template<typename array, typename function>
class Array {
public:
    Array();

    Array(unsigned int n);

    Array(Array &src);

    ~Array();

    Array &operator[](unsigned int n);

    unsigned int size() const;
};