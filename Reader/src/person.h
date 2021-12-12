#ifndef PERSON_H
#define PERSON_H
#include <string>

class Person {

    int id;
    char name[16];
    char lastname[16];
    char email[51];
    public:
    Person(int id, char name[16], char lastname[16], char email[51]);
    int getID();
    char* getName();
    char* getLastname();
    char* getEmail();

    void setID(int id);
    void setName(char name[16]);
    void setLastname(char lastname[16]);
    void setEmail(char email[51]);
};
    
#endif