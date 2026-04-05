#pragma once
#include <iostream>
#include <string>
using namespace std;

class Event{
    int minute, hour, day, month, year;
    string name;

    public:
    Event(string, int, int, int, int, int);
    ~Event();
    void load();
    void show();
};