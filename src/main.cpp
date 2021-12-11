#include "fileReader.h"
#include "fileWriter.h"
#include "person.h"
#include <iostream>
#include <fstream>
#include <sstream>

int main() {

    fileReader *f = new fileReader;
    f->Read();
    fileWriter *g = new fileWriter;
    g->Write();


    Person ten = f->personFinder(7);

    std::cout<<ten.getName()<<std::endl;

    return 0;
}