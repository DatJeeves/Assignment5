#include <iostream>
#include <fstream>
#include "undoList.h"


using namespace std;

UndoList::UndoList() {
    string command ="";
    filename = "undo";
    undoCount = 0;
    maxUndo = 5;
}

UndoList::~UndoList() {
}

void UndoList::tempdo(string cmd) {
    string tempName = filename + to_string(++undoCount);
    UndoNode tempNode(cmd, tempName);
    stack.push(tempNode);
    ofstream file;
    file.open(tempName);
    file << "Need to add in the tables here";
    file.close();
    
}

string UndoList::undo() {
    UndoNode temp;
    string line;

    temp = stack.pop();
    fstream stream(temp.filename);
    if (stream.good()) {
        while (!stream.eof()) {
            //stream >> line;
            getline(stream, line);
        }
    }
    cout << line << endl;
    stream.close();
    return temp.command;
}

bool UndoList::isEmpty() {
    return stack.isEmpty();
}

void UndoList::showUndo() {
    // This displays the last command that can be undone
    UndoNode temp;
    string line;
    if (!stack.isEmpty()) {
        temp = stack.pop();
        cout << "command : " << temp.command << endl;
        stack.push(temp);
    }
}

int main() {

    string cmd;
    UndoList undo;

    for (int i = 0; i < 5; ++i) {
        cmd = "This cmd is " + to_string(i);

        cout << "The new cmd is " << cmd << endl;
        undo.tempdo(cmd);
    }

    //write object into the file
    fstream file;
    file.open("undolist", ios::out | ios::binary);
    if (!file) {
        cout << "Error in creating file...\n";
        return -1;
    }

    file.write((char*)&undo, sizeof(undo));
    file.close();
    cout << "Date saved into file the file.\n";


    cout << "==========" << endl;
    cout << "Whats the undo ?" << endl;
    undo.showUndo();

    cout << "==========" << endl;
    cout << "Whats the undo ?" << endl;
    undo.showUndo();

    cout << "Heres what you got" << endl;
    while (!undo.isEmpty()) {
        cout << undo.undo() << endl;
    }

    //open file again 
    file.open("undolist", ios::in | ios::binary);
    if (!file) {
        cout << "Error in opening file...\n";
        return -1;
    }

    if (file.read((char*)&undo, sizeof(undo))) {
        cout << endl << endl;
        cout << "Data extracted from file..\n";
        //print the object
        undo.showUndo();

        for (int i = 0; i < 5; ++i) {
            cmd = "This cmd is " + to_string(i);

            cout << "The new cmd is " << cmd << endl;
            undo.tempdo(cmd);
        }
    }
    else {
        cout << "Error in reading data from file...\n";
        return -1;
    }

    file.close();
}