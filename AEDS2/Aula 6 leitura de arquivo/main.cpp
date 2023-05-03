#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv) {
    
   /* ofstream myfile;
    myfile.open ("example.txt");
    if (myfile.is_open()){
        myfile << "This is a line. \n";
        myfile << "This is another line. \n";
        myfile.close();
    }
    else
        cout << "Unable to open file";*/
    
    string line;
    ifstream myfile ("example2.txt");
    if (myfile.is_open()){
        while ( !myfile.eof() ){
            myfile >> line;
            cout << "string: " << line << endl;
        }
        myfile.close();
    }
    else
        cout << "Unable to open file";
    return 0;
}

