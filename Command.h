#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class LinuxComm
{
private:
    string command; //linux command
    string def; //definition of linux command

public:
    //constructor
    LinuxComm()
    {

    }

    //Accessors
    string getCommand() //returns the command entered/in the file
    {
        return command;
    }

    string getDef() //returns the definition of a specific command
    {
        return def;
    }

    //Overload
    friend istream& operator >> (istream& in, LinuxComm& command)
    {
        string inLine;
        const char comma(44);

        getline(in, inLine, comma);

        if (!in.eof())
        {
            command.initCommand(inLine);
            getline(in, inLine);
            command.initDef(inLine);
        }
        return in;
    }

    //Mutators
    void initCommand(string newCommand) //initializes a new command to be entered
    {
        command = newCommand;
    }

    void initDef(string newDefinition) //initializes a new definition
    {
        def = newDefinition;
    }

    //Deconstructor
    ~LinuxComm()
    {

    }
};
