// proba.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

class Cars {
public:
    Cars(string model) {
        _model = model;
    };
    ~Cars() {}
    string get_model() {
        return _model;
    }
    string _model;
    string mark;
};

class Mercedes : public Cars {
public:
    Mercedes(string model) : Cars(model) {
        mark = "Mercedes";
    };
};

class Toyota : public Cars {
public:
    Toyota(string model) : Cars(model) { 
        mark = "Toyota"; 
    };
};

class Lada : public Cars {
public:
    Lada(string model) : Cars(model) {
        mark = "Lada";
    };
};


int main()
{
    vector <Cars*> cars;
    ifstream file("cars.txt");
    
    string temp;
    while (getline(file, temp)) {
        string mark, model;
        istringstream str(temp);
        str >> mark >> model;

        if (mark == "Lada") {
            cars.push_back(new Lada(model));
        }
        else if (mark == "Toyota") {
            cars.push_back(new Toyota(model));
        }
        else {
            cars.push_back(new Mercedes(model));
        }
    }
    file.close();
    
    for (Cars* car : cars) {
        cout << car->mark << " " << car->get_model() << endl;
    }
}