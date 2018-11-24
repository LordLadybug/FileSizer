#include <iostream>
#include <fstream>
/*
In this challenge, given the name of a file, print out the size of the file, in bytes.
 If no file is given, provide a help string to the user that indicates how to use the program. You might need
help with taking parameters via the command line or file I/O in C++ (if you want to solve this problem in C,
you might be interested in this article on C file I/O).
*/

using namespace std;

int main(int argc, char *argv[])
{
    //argc =0 is no file read, argc =1 is one file read, otherwise is undefined input
    if (argc != 2)
    {
        cout << "Usage: " << argv[0] << " <filename> \n"<< endl;  //This is the help string
        return -1;
    }
    else
    {
        ifstream the_file ( argv[1] );
        if (!the_file.is_open())
        {
            cout<<"Error opening file\n";   //Does not open files of a large enough size (limit is somewhere between 927 bytes and 1924 bytes)
            return -1;
        }
        else
        {
            char x;
            long begin, end;
            the_file.seekg(0);
            begin = the_file.tellg();
            the_file.seekg(0, ios::end);
            end = the_file.tellg();
            the_file.close();
            cout << end-begin << "bytes long using ifstream functionality" << endl;
        }
    }
    return 0;
}

