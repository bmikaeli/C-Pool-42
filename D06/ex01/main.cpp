#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cstring>

struct Data {
    std::string s1;
    int n;
    std::string s2;
};

void *serialize(void) {
    int len = 8;
    std::string name = "";
    char rand_int[4];
    char range[] = "qwertyuiopasdfghjklzxcvbnm1234567890QWERTYUIOPASDFGHJKLZXCVBNM";
    std::ifstream random("/dev/urandom");

    random.read(rand_int, 4);
    random.close();

    srand(int(*rand_int));
    while (len) {
        name += range[rand() % 62];
        len--;
    }
    len = 8;
    name += rand_int;
    while (len) {
        name += range[rand() % 62];
        len--;
    }
    return static_cast<void *>(const_cast<char *>(name.data()));
}

Data *deserialize(void *raw) {
    Data *data = new Data;
    std::string raw_string(static_cast<char *>(raw));
    char *temp = static_cast<char *>(raw);
    std::cout << raw_string << std::endl;
    data->s1 = raw_string.substr(0, 7);
    data->n = temp[8] << 24;
    data->n += temp[9] << 16;
    data->n += temp[10] << 8;
    data->n += temp[11];
    data->s2 = raw_string.substr(12, 19);
    return data;
}

int main(void) {
    Data *data = deserialize(serialize());
    std::cout << data->s1 << std::endl
            << data->n << std::endl
            << data->s2 << std::endl;
    return 0;
}
