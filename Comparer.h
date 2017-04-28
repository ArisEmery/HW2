//
// Created by Stephen Clyde on 1/16/17.
//

#ifndef ANALYSTCOMPARER_RANKER_H
#define ANALYSTCOMPARER_RANKER_H

#include <fstream>
#include "Constants.h"
#include "Analyst.h"
#include <vector>

// TODO: Define an Analyst class and import the definition
 //#include "Analyst.h"

class Comparer {
private:
    std::string     m_outputFilename="/Users/arisemery/CLionProjects/AnalystComparer/trs.csv";
    // TODO: define something like an array of pointers to hold a list of analysts. A vector<Analyst> would work too.

public:
    int load(int argv, char* argc[]);
    int compare() const;
    //vector<Analyst> m_analysts;
    Analyst**       m_analysts = nullptr;
    int             m_analystCount = 0;
    std::string     m_symbols[MAX_SYMBOLS];
    int             m_symbolsCount = 0;


private:
    void loadSymbols();
    void outputInvestorNames(std::ofstream& outputStream) const;
    void outputOverallPerformance(std::ofstream& outputStream) const;
    void outputStockPerformance(std::ofstream& outputStream) const;
};

#endif //ANALYSTCOMPARER_RANKER_H
