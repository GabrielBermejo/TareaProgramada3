#ifndef FILEREADER_H
#define FILEREADER_H
#include <string>
#include <vector>
#include "person.h"
class fileReader{
    std::vector <Person> personvector;
    public:
    fileReader();
    void Read();
    Person personFinder(int id);
};
#endif