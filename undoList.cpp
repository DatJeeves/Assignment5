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

}

int main() {

    string cmd;
    UndoList undo;

    for (int i = 0; i < 5; ++i) {
        cmd = "This cmd is " + to_string(i);

        cout << "The new cmd is " << cmd << endl;
        undo.tempdo(cmd);
    }

    cout << "Heres what you got" << endl;
    while (!undo.isEmpty()) {
        cout << undo.undo() << endl;
    }

}