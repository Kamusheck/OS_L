#include "fn1.hpp"
#include <limits>

int main(){
    std::string command;
    std::cout <<"введите: 1 -функция вычисления интеграла синуса на отрзеке A B, 2 - подсчет простых чисел на отрезке A B, q - выход";
    std::cin >> command;

    if (command == "1"){
        float A, B, e;
        std::cout << "введите A, B [A, B] и шаг e";
        std::cin>>A>>B>>e;

        float result_for_1 = SinIntegral(A,B,e);

        std::cout<<"ответ: "<<result_for_1<<std::endl;
    }else if(command == "2"){
        int A,B;
        std::cout<<"введите A B для функции 2 ";
        std::cin>>A>>B;

        if(std::cin.fail() || A<=0 || B<= 0 || A > B){
            std::cerr << "ОШибочка, отрезок должен быть из натуральных"<<std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }else{
            int result_for_2 = PrimeCount(A, B);
            std::cout<<"ответ: "<< result_for_2<<std::endl;
        }
    }else if(command == "q"){
        std::cout<<"пока пока"<<std::endl;
    }else{
        std::cerr <<"внимательно смотрим, а то  не то ппишем,"<<std::endl;
    }
    return 0;
}