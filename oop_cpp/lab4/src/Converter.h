#pragma once
#include <vector>
#include <string>
#include <tuple>

using namespace std;

typedef vector<string> List;

template <typename T>
T TypeConverter(const string& data){
    throw invalid_argument("argument has none-type:" + data);
}

template<>
string TypeConverter(const string& data){
    return data;
}

template<>
int TypeConverter(const string& data){
    try{
        return stoi(data);
    }
    catch(exception e){
        throw invalid_argument("TypeConverter can not convert '" + data + "' to int type");
    }
}

template<>
float TypeConverter(const string& data){
    try{
        return stof(data);
    }
    catch(exception e){
        throw invalid_argument("TypeConverter cannot convert '" + data + "' to float type");
    }
}

template<typename T, unsigned N, unsigned Size>
class TupleConverter{
public:
    static void converting(T &converted_tuple, const List& str_vector){
        std::get<N>(converted_tuple) = TypeConverter<typename std::tuple_element<N, T>::type>(str_vector[N]);
        TupleConverter<T, N+1, Size>::converting(converted_tuple, str_vector);
    }
};

template<typename T, unsigned Size>
class TupleConverter<T, Size, Size>{
public:
    static void converting(T &converted_tuple, const List& str_vector){
        std::get<Size>(converted_tuple) = TypeConverter<typename std::tuple_element<Size, T>::type>(str_vector[Size]);

    }
};

template<typename T, unsigned N>
class TupleConverter<T, N, 0>{
public:
    static void converting(T &converted_tuple, const List& str_vector){

    }
};

template <typename... Args>
tuple<Args...> convertVectorToTuple(const List& str_vector){
    tuple<Args...> converted_tuple;
    TupleConverter<tuple<Args...>, 0, sizeof...(Args)-1>::converting(converted_tuple, str_vector);
    return converted_tuple;
}


