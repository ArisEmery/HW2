//
// Created by Aris  Emery on 4/27/17.
//

#include "PurchaseSales.h"
PurchaseSales::PurchaseSales(string input[8]){
    symbol=input[0];
    quantity=convertStringToInt(input[1]);
    purchaseTime=convertStringToInt(input[2]);
    purchasePrice=convertStringToInt(input[3]);
    purchaseTransactionFee=convertStringToInt(input[4]);
    saleTime=convertStringToInt(input[5]);
    salePrice=convertStringToInt(input[6]);
    saleTransactionFee=convertStringToInt(input[7]);

    inv = (quantity*purchasePrice) + purchaseTransactionFee + saleTransactionFee;
    PL = (quantity*salePrice) - inv;
    //Q, PT, PP, PF, ST, SP, SF

}