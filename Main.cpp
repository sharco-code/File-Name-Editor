#include <iostream>
#include <string>
#include <fstream>

#define INPUT_ERROR 1
#define OUTPUT_ERROR 2
#define UNKNOWN_ERROR 3

using namespace std;

class editor {
    private:
        string input_file, output_file; //useless variables
    public:
        string split(string str, char sep) {

            string name;
            string res;

            const auto x = str.find_first_of(sep);

            if (string::npos != x) {
                name = str.substr(0, x);
                res = str.substr(x + 1);
            } else {
                name = str;
            }

            return res;
        }

};

int main(int argc, char *argv[]){

    editor p;

    system("dir /b > temp");

    ifstream in("temp");

    if(!in) {
        return 1;
    }

    string str, res, command, command2;

    const char *c, *c2;

    while (std::getline(in, str)) {
        if(isdigit(str[0])) {
            if(str.find(" - ") != string::npos) {
                //res = str.substr(0, str.find(" - "));
                res = p.split(str, '-');
                res = p.split(res, ' ');
                command = "copy \""+str+"\" \""+res+"\"";
                c = command.c_str();
                command2 = "del \""+str+"\"";
                c2 = command2.c_str();
                system(c);
                system(c2);
            } 
        }
    }

    in.close();
    system("del temp");    
    return 0;
}

