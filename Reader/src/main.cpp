#include "fileReader.h"
#include "person.h"
#include <iostream>
#include <fstream>
#include <sstream>

int main() {

    fileReader *f = new fileReader;
    f->Read();

    int input=0;

    std::cout<< "Please type the ID of the person you are looking for: ";
    std::cin>> input;

    Person ten = f->personFinder(input);

    std::cout<<ten.getName()<<std::endl;

    return 0;
}