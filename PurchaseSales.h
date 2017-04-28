//
// Created by Aris  Emery on 4/27/17.
//

#ifndef ANALYSTCOMPARER_PURCHASESALES_H
#define ANALYSTCOMPARER_PURCHASESALES_H
#include <iostream>
#include <fstream>
#include "Utils.h"
using namespace std;

class PurchaseSales {
public:
    PurchaseSales(string input[8]);
    string symbol;
    int quantity;
    int purchaseTime;
    int purchasePrice;
    int purchaseTransactionFee;
    int saleTime;
    int salePrice;
    int saleTransactionFee;
    int inv;
    int PL;
    string getSymbol(){return symbol;};
};


#endif //ANALYSTCOMPARER_PURCHASESALES_H
        //Symbol, Quantity, Purchase Date/Time, Purchase Price, Purchase Transaction
        //Fee, Sale Date/Time, Sale Price, and Sale Transaction Fee (in that order)