#include <iostream>
#include <string>
#include <concepts>

template<typename T>
concept ComplexConcept = requires(T t) {
    { t.hash() } -> std::convertible_to<long>;//метод hash(), который возвращает тип, конвертируемый в long
    { t.toString() } -> std::same_as<std::string>;//метод toString(), который возвращает std::string
        requires !std::has_virtual_destructor_v<T>;//отсутствие виртуального деструктора
};

class MyComplex {//пример класса, соответствующего требованиям
public:
    long hash() const { return 12345; }
    std::string toString() const { return "MyComplex object"; }
};

int main() {
    static_assert(ComplexConcept<MyComplex>);

    MyComplex c;
    std::cout << c.hash() << std::endl;
    std::cout << c.toString() << std::endl;

    return 0;
}