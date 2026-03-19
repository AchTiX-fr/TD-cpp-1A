#pragma once
#include <vector>

class FlapModule
{
private:
    std::vector<unsigned char> availableSigns;
    int currentSignIndex;
    unsigned char signToDisplay;

public:
    FlapModule();
    unsigned char currentSign();
    void display(unsigned char value);
    bool update();
};