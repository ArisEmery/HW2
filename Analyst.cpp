//
// Created by Aris  Emery on 4/27/17.
//

#include "Analyst.h"
bool Analyst::load(std::ifstream &inputFile){
    if (!inputFile.is_open()){
        return false;
    }
    char delim='\n';
    getline(inputFile,name,delim);
    getline(inputFile,initials,delim);
    string simDaysStr;
    string seedMoneyStr;
    getline(inputFile,simDaysStr,delim);
    int simulationDays=convertStringToInt(simDaysStr);
    getline(inputFile,seedMoneyStr,delim);
    int seedMoney=convertStringToInt(seedMoneyStr);
    string numRecords;
    getline(inputFile,numRecords,delim);
    int numberRecords=convertStringToInt(numRecords);
    //History placeholder(simulationDays, seedMoney, numberRecords, inputFile);
    myHistory=new History(simulationDays, seedMoney, numberRecords, inputFile);
    string currSymbol;
    //vector<string> tester4=myHistory->myPurchaseSales;
    for(int i=0; i<myHistory->myPurchaseSales.size();i++) {
        currSymbol = myHistory->myPurchaseSales[i].symbol;
        bool found=false;
        for(int j=0;j<symbols.size();j++) {
            if(symbols[j]==currSymbol){
                found=true;
            }
        }
        if(found==false){
            symbols.push_back(currSymbol);
        }
        found=false;
    }
    for(int i=0; i<myHistory->myPurchaseSales.size();i++){
        TPL+=(myHistory->myPurchaseSales[i].PL);
        if(myHistory->myPurchaseSales[i].symbol=="AAPL"){
            AAPLTPL+=(myHistory->myPurchaseSales[i].PL);
        }
        else if(myHistory->myPurchaseSales[i].symbol=="GOOGL"){
            GOOGLTPL+=(myHistory->myPurchaseSales[i].PL);
        }
        else if(myHistory->myPurchaseSales[i].symbol=="MSFT"){
            MSFTTPL+=(myHistory->myPurchaseSales[i].PL);
        }
        else if(myHistory->myPurchaseSales[i].symbol=="AMZN"){
            AMZNTPL+=(myHistory->myPurchaseSales[i].PL);
        }

    }
    double placeholder=TPL/100;
    TPL=placeholder;
    PLPD=((TPL/simulationDays));
    m_days=simulationDays;
    m_seedMoney=seedMoney;




    //myHistory=placeholder;
    return true;
}