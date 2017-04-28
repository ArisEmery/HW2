//
// Created by Aris  Emery on 4/27/17.
//

#ifndef ANALYSTCOMPARER_HISTORY_H
#define ANALYSTCOMPARER_HISTORY_H

#include "PurchaseSales.h"
#include <vector>

class History {
public:
    History(int simDays, int seedMon, int numRecords, ifstream &inputFile);
    int simulationDays;
    double seedMoney;
    int numRecords;
    PurchaseSales *myHolder;
    vector<PurchaseSales> myPurchaseSales;


};


#endif //ANALYSTCOMPARER_HISTORY_H
