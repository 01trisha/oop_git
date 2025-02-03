// #pragma once
#include <iostream>
#include <tuple>

//стандартный шаблон
template<typename Tuple, unsigned N, unsigned Size>
class TuplePrinter {
    public:
        static void print(std::ostream& out, const Tuple& tuple) {
            out << std::get<N>(tuple);
            if (N+1 < Size){
                out << ",";
            }
            TuplePrinter<Tuple, N + 1, Size>::print(out, tuple);
        }
};
//специализация для последнего элемента
template<typename Tuple, unsigned Size>
class TuplePrinter<Tuple, Size, Size> {
public:
    static void print(std::ostream& out, const Tuple& tuple) {
    }
};

template<typename Tuple, unsigned N> 
class TuplePrinter<Tuple, N, 0> {
    public:
        static void print(std::ostream& out, const Tuple& tuple) {
        }
};


// << для вывода tuple
template<typename... Args>
std::ostream& operator<<(std::ostream& out, const std::tuple<Args...>& tuple){
    out << "(";
    TuplePrinter<std::tuple<Args...>, 0, sizeof...(Args)>::print(out, tuple);
    out << ")";
    return out;
}

