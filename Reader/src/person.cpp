#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "person.h"
Person::Person(int id, char name[16], char lastname[16] , char email[51]){
    this->id=id;

    for (int i = 0; i < 15; i++)
    {
      this->name[i]=name[i];
    }
    
    for (int i = 0; i < 15; i++)
    {
      this->lastname[i]=lastname[i];
    }
    
    for (int i = 0; i < 50; i++)
    {
      this->email[i]=email[i];
    }
    
    
}    
int Person::getID() {
  return this->id;
}
char* Person::getName() {
  return this->name;
}
char* Person::getLastname() {
  return this->lastname;
}
char* Person::getEmail() {
  return this->email;
}
/*
int Person::setID(int id) {
  return this->id;
}
char[16] Person::setName(char name[16]) {
  return this->name;
}
char[16] Person::setLastname(char lastname[16]) {
  return this->lastname;
char[51] Person::setEmail(char email[51]) {
  return this->email;
}*/