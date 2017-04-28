//
// Created by Aris  Emery on 4/27/17.
//

#include "History.h"
History::History(int simDays, int seedMon, int numRecords1, ifstream &inputFile){
    numRecords=numRecords1;
    string results[8];
    char deim1='\n';
    char delim2=',';
    simulationDays=simDays;
    seedMoney=seedMon;
    int counter=0;
    for(int i=0;i<numRecords;i++) {
        while (inputFile.is_open() && !inputFile.eof() && counter < 7) {
            getline(inputFile, results[counter], delim2);
            counter++;
        }
        counter=0;
        getline(inputFile, results[7], deim1);
        myHolder = new PurchaseSales(results);
        myPurchaseSales.push_back(*myHolder);
    }
}