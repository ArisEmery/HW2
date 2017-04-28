//
// Created by Aris  Emery on 4/27/17.
//

#ifndef ANALYSTCOMPARER_ANALYST_H
#define ANALYSTCOMPARER_ANALYST_H
#include <iostream>
#include "History.h"
#include <fstream>
#include "Utils.h"
#include <vector>
using namespace std;

class Analyst {
public:
    Analyst(){};
    string name;
    string initials;
    History *myHistory;
    vector<string> symbols;
    double TPL=0;
    double PLPD=0;
    int m_seedMoney;
    int m_days;
    double AMZNTPL=0;
    double GOOGLTPL=0;
    double MSFTTPL=0;
    double AAPLTPL=0;
    bool load(ifstream &inputFile);
    History getHistory(){ return *myHistory;};
};


#endif //ANALYSTCOMPARER_ANALYST_H
