#include <iostream>
#include <string_view>

// Reference => https://www.youtube.com/watch?v=8jLOx1hD3_o
// (freeCodeCamp.org)

class Dog{
    public :
        Dog() = default;
        Dog(std::string_view name_param, std::string_view breed_param, int age_param);    // to avoid copies, we use string_view
        ~Dog();     // Destructors will always have no parameters in C++. If you put parameter, you will get compiler error.

    private : 
        std::string name;
        std::string breed;
        int * p_age{nullptr};
};

Dog::Dog(std::string_view name_param, std::string_view breed_param, int age_param){
    name = name_param;
    breed = breed_param;
    p_age = new int;
    *p_age = age_param;
    std::cout << "Dog constructor called for : " << name << std::endl;
}

Dog::~Dog(){    // it will release whatever memory we allocated in constructor
    delete p_age;
    std::cout << "Dog destructor called for : " << name << std::endl;
}


void afunc(){
    Dog* p_dog = new Dog("Fluffy", "Shepherd",2);

    delete p_dog;   // Causes for the destructor of Dog to be called
}

int main(){

    afunc();
    //Dog my_dog("Fluffy", "Shepherd",2);

    std::cout << "Done!" << std::endl;

    return 0;
}