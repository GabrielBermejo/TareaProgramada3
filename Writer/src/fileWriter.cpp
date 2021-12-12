#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "fileWriter.h"
#include "FileCouldntBeFoundException.h"
using namespace std;
fileWriter::fileWriter(){

}

void fileWriter::Write()
{

    std::ifstream ifs("Personas.txt", std::ifstream::in);
        if (!ifs.is_open())
        {
            throw FileCouldntBeFoundException();
            exit(1);
        }

    std::ofstream file("Personas.dat", std::ofstream::out);

    //string where the line in the text file will be stored
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
            
    

            file << id <<" "<< name << " "<<lastname<<" " << email << std::endl;


            
        }
        catch (string &excepcion)
        {
            cerr << excepcion << endl;
        }
    }
    ifs.close();
    file.close();
}
