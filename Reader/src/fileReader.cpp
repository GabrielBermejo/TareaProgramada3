#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "person.h"
#include "fileReader.h"
#include <vector>
#include "OutOfBoundsException.h"
#include "FileCouldntBeFoundException.h"
using namespace std;

fileReader::fileReader(){

}

void fileReader::Read() {

    std::ifstream ifs("Personas.dat", std::ifstream::in);
    if (!ifs.is_open())
    {
        std::cerr << "File \"Personas.dat\" can't be found" << std::endl;
        throw FileCouldntBeFoundException();
        exit(1);
    }

    
    
    string line {""};

    //Reads the first 3 characters because they are not part of the file's content
    ifs.get();
    ifs.get();
    ifs.get();

    while (std::getline(ifs, line)) {

        try
        {
            std::istringstream stream(line);

            //variables where read values will be stored and then printed 
            int id {0};
            char name[16]={' '};
            char lastname[16]={' '};
            char email[51]={' '};

            //string to store string values temporarily 
            string temp;

            
            //id in text file is stored in int id
            stream >> id;

            //name in text file is stored in string temp
            stream >> temp;

            //if temp string is longer that 15 characters, only the first 15 are stored in name 
            if (temp.size()>15){
                for (int i = 0; i < 15; i++)
                {
                    name[i]=temp.at(i);
                    
                }
            }
            else{
                for (int i = 0; i < temp.size(); i++)
                {
                    name[i]=temp.at(i);
                }
            }


            //lastname in text file is stored in string temp
            stream >> temp;

            //if temp string is longer that 15 characters, only the first 15 are stored in lastname 
            if (temp.size()>15){
                for (int i = 0; i < 15; i++)
                {
                    lastname[i]=temp.at(i);
            
                }
            }
            else{
                for (int i = 0; i < temp.size(); i++)
                {
                    lastname[i]=temp.at(i);
                }
            }
            
            //email in text file is stored in string temp
            stream >> temp;
            
            //if temp string is longer that 50 characters, only the first 50 are stored in email 
            if (temp.size()>50){
                for (int i = 0; i < 50; i++)
                {
                    email[i]=temp.at(i);
            
                }
            }
            else{
                for (int i = 0; i < temp.size(); i++)
                {
                    email[i]=temp.at(i);
                }
            }
            Person person(id, name, lastname, email);// = new Person(id, name, lastname, email);
            personvector.push_back(person);

        }
        catch (string &excepcion)
        {
            cerr << excepcion << endl;
        }
    }
    
    ifs.close();
}

Person fileReader::personFinder(int id){
    if(id>personvector.size()||id<=0){
        throw OutOfBoundsException();
        exit(1);
    }
    
    return personvector.at(id-1);
    
}
