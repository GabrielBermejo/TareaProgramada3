#include <fstream>
#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;


int main()
{

    std::ifstream ifs("Personas copy.txt", std::ifstream::in);
        if (!ifs.is_open())
        {
            std::cerr << "Error leyendo archivo personas.txt" << std::endl;
            return -1;
        }

    std::ofstream file("Personas.dat", std::ofstream::out);


    string line {""};

    int id {0};
    string name;
    name.reserve(15);

    string lastname;
    lastname.reserve(15);

    string email;
    email.reserve(50);
    std::cout << "The size of name is " << name.length() << " bytes.\n";
    


    while (std::getline(ifs, line)) {

        try
        {

            std::istringstream stream(line);

            id = 0;
            name = "";
            lastname = "";
            email = "";

            stream >> id >> name >> lastname >> email;


            if (id == 0)
            {
                string error = "Error in line \"" + line + "\". ID can't be 0.";
                
                throw error;
            }

            cout << << name << "'s line is correct." << endl;
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
