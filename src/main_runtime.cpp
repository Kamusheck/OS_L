#include <dlfcn.h>
#include <stdexcept>
#include <iostream>
#include <string>
#include <limits>

void* libAdress = nullptr;
void* loadFun(const std::string& libPath, const std::string& funName){
    if(libAdress){
        dlclose(libAdress);
    }
    libAdress = dlopen(libPath.c_str(), RTLD_LAZY);
    if (!libAdress){
        throw std::runtime_error("проблемкка с подгрузкой либы:"+ libPath);
    }

    void* fun = dlsym(libAdress, funName.c_str());
    if(!fun){
        throw std::runtime_error("проблемка с подгрузкой функции"+ funName);
    }
    return fun;
}

int main(){
    std::string command;
    std::string currentLib = "./libfn1.so";

    while(true){
        std::cout << "введите:0- смена, 1 -функция вычисления интеграла синуса на отрзеке A B, 2 - подсчет простых чисел на отрезке A B, q - выход";
        std::cin >> command;

        if(command == "0"){
            currentLib = (currentLib == "./libfn1.so") ? "./libfn2.so":"libfn1.so";
            std::cout <<"сменка произошла:"<<currentLib<<std::endl;
        }else if ( command == "1"){
            try{
                auto SinIntegral = (float(*)(float,float,float))loadFun(currentLib, "SinIntegral");
            float A,B,e;
            std::cout<<"введите A, B [A, B] и шаг e";
            std::cin >>A>>B>>e;

            float result_1= SinIntegral(A,B,e);
            std::cout<<"ответ: "<<result_1<<std::endl;
            }catch (const std::exception& ex){
                std::cerr<<ex.what()<<std::endl;
            }
        }else if(command =="2")
            try {
                auto PrimeCount = (int (*)(int, int))loadFun(currentLib, "PrimeCount");
                int A, B;
                std::cout << "введите A B для функции 2 ";
                std::cin >> A >> B;

                if(std::cin.fail() || A<=0 || B<= 0 || A > B){
                    std::cerr << "ОШибочка, отрезок должен быть из натуральных"<<std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }else{
            int result_for_2 = PrimeCount(A, B);
            std::cout<<"ответ: "<< result_for_2<<std::endl;
        }

                int result = PrimeCount(A, B);
                std::cout << "ответ : " << result << std::endl;
            } catch (const std::exception& ex) {
                std::cerr << ex.what() << std::endl;
            }
         else if (command == "q") {
            break;
        } else {
            std::cerr << "внимательно смотрим, а то  не то ппишем," << std::endl;
        }
    }

    if (libAdress) {
        dlclose(libAdress);
    }
}