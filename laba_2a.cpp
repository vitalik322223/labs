#include <vector>
#include <iostream>

using namespace std;

class Class1 {
public:
    Class1() {};
    ~Class1() {};
};

class Class2 : public Class1 {
public:
    Class2() {};
    ~Class2() {};
};
void my_copy(vector<Class1*>& classes, Class1* temp) {
    classes.push_back(temp);
}

int main()
{
    vector<Class1*> classes;
    Class1 temp1;
    Class2 temp2;
    my_copy(classes, &temp1);
    my_copy(classes, &temp2);
    for (Class1* Class : classes) {
        cout << typeid(*Class).name() << std::endl;
    }
}

