//
// Created by Stephen Clyde on 1/16/17.
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include "Comparer.h"
#include "Utils.h"
#include "Analyst.h"

int Comparer::load(int argc, char* argv[])
{
    if (argc<3)
    {
        std::cout << "Invalid parameters" << std::endl;
        std::cout << "usage: AnalystComparer <output file> <input file 1> <input file 2> ..." << std::endl;
        return -1;
    }

    m_outputFilename = argv[1];
    m_analystCount = argc - 1;
    int counter=1;
    //Analyst ** m_analysts;
    //
    // TODO this need to be changed back
    m_analysts = new Analyst*[m_analystCount];
    string rootDirect="/Users/arisemery/CLionProjects/AnalystComparer/Data/";
    int analystIndex = 0;
   // ifstream myfile("/Users/arisemery/CLionProjects/ITAK/SampleData.csv");
    for (int i = 0; i < m_analystCount; i++)
    {
        string tester=rootDirect+argv[counter];
        ifstream inputStream(tester);
        counter++;
        //
        // Example code:
        //m_analysts[analystIndex] = new Analyst();
        Analyst *myAnalyst;
        myAnalyst=new Analyst();
        //if (m_analysts[analystIndex]->load(inputStream) == false)//load(inputStream)
        if (myAnalyst->load(inputStream) == false)//load(inputStream)
        {
            std::cout << "Failed to load " << argv[analystIndex] << std::endl;
        }
        else {
            m_analysts[analystIndex]=myAnalyst; //todo change back

            //m_analysts.push_back(new Analyst);
            analystIndex++;
            if(counter<argc) {
                m_outputFilename = argv[counter];
            }
        }
        string wo=myAnalyst->name;
    }

    loadSymbols();

    int result = 0;
    if (analystIndex < m_analystCount)
        result = -1;

    return result;
}

int Comparer::compare() const
{
    if (m_analystCount < 2)
    {
        std::cout << "Cannot do comparison with " << m_analystCount << " analysts" << std::endl;
        return -1;
    }

    if (m_outputFilename == "")
    {
        std::cout << "Cannot do comparison because no output file is specified" << std::endl;
        return -1;
    }

    ofstream outputStream(m_outputFilename);



    //std::ofstream outputStream(outputStream);
    outputInvestorNames(outputStream);
    outputOverallPerformance(outputStream);
    outputStockPerformance(outputStream);

    return 0;
}

void Comparer::loadSymbols()
{
    m_symbolsCount = 0;
    // TODO: Go through all analysts' histories and build a list of symbols used in any Purchase-Sale.
    // According to the design, every analyst has a design and a history contains purchase-sale objects.
    // Each purchase-sale object is for a symbol.
    //
    // The m_symbols array contains the list of references symbols.  The std::find methods checks to see
    // if a symbol is already in that array.  If it is not, then the result result is the std::end of the
    // the array and the symbol is array to the array.
    //
    // Example code:
/*
     for (int i = 0; i < m_analystCount; i++)
     {
        History& history = m_analysts[i]->getHistory();
        history.resetIterator();
         PurchaseSales* purchaseSales;
         *purchaseSales = history.myPurchaseSales[i+1];
        while ((purchaseSales!= nullptr))
        {
            std::string symbol = purchaseSales->getSymbol();
            std::string *existingSymbol = std::find(std::begin(m_symbols), std::end(m_symbols), symbol);
            if (existingSymbol == std::end(m_symbols)) {
                m_symbols[m_symbolsCount++] = symbol;
            }
        }
     }
*/
    //History history;
    /*
    string symbol;
    for (int i = 0; i < m_analystCount; i++){
        //const History myHistory=m_analysts[i]->getHistory();
        for(int j=0;j<myHistory.numRecords;j++){
            symbol=m_analysts[i]->myHistory.myPurchaseSales[j].symbol;
            std::string *existingSymbol = std::find(std::begin(m_symbols), std::end(m_symbols), symbol);
            if (existingSymbol == std::end(m_symbols)) {
                m_symbols[m_symbolsCount++] = symbol;
            }

        }
    }

    for(int i=0;i<m_symbolsCount;i++){
        cout<<m_symbols[i]<<endl;
    }
*/
    string currSymbol;
    for(int i=0; i<m_analystCount;i++) {
        for(int h=0;h<m_analysts[i]->symbols.size();h++){
            bool found=false;
            currSymbol = m_analysts[i]->symbols[h];
            for(int j=0;j<m_symbolsCount&&found==false;j++) {
                if(currSymbol==m_symbols[j]){
                    found=true;
                }
            }
            if(found==false){
                m_symbols[m_symbolsCount]=currSymbol;
                m_symbolsCount++;
            }
        }
    }

}


void Comparer::outputInvestorNames(std::ofstream& outputStream) const
{
    for(int i=0;i<m_analystCount;i++){
        outputStream<<"Investors: "<<m_analysts[i]->name<<endl;
    }
}

void Comparer::outputOverallPerformance(std::ofstream& outputStream) const
{
    outputStream<<"Overall Performance:\nDays:   "<<setw(10);
    for(int i=0;i<m_analystCount;i++){
        outputStream<<m_analysts[i]->initials<<":"<<m_analysts[i]->m_days<<setw(10);
    }
    outputStream<<"\n";
    outputStream<<setw(5)<<"Seed amount($):   "<<setw(3);
    for(int i=0;i<m_analystCount;i++){
        outputStream<<m_analysts[i]->initials<<":"<<m_analysts[i]->m_seedMoney/100<<setw(10);
    }
    outputStream<<"\n";
    outputStream<<setw(5)<<"TPL($):   "<<setw(10);
    for(int i=0;i<m_analystCount;i++){
        outputStream<<m_analysts[i]->initials<<":"<<m_analysts[i]->TPL<<setw(10);
    }
    outputStream<<"\n";
    outputStream<<setw(5)<<"PLPD($):   "<<setw(10);
    for(int i=0;i<m_analystCount;i++){
        outputStream<<m_analysts[i]->initials<<":"<<m_analysts[i]->PLPD<<setw(10);
    }
    outputStream<<"\n";
    // TODO: Write out Overall Performance table.  The classes from the FormattedTable example might be helpful.


};

void Comparer::outputStockPerformance(std::ofstream& outputStream) const
{
    outputStream<<"Stock Performance:\n";
   // for(int i=0;i<m_symbolsCount;i++){
   //     outputStream<<"         "<<m_symbols[i];
    //}
    outputStream<<endl;
    for(int i=0;i<m_analystCount;i++){
        outputStream<<m_analysts[i]->initials<<":"<<"   ";
        outputStream<<endl;
        if(find(m_analysts[i]->symbols.begin(), m_analysts[i]->symbols.end(), "AMZN") != m_analysts[i]->symbols.end()) {
            outputStream<<"AMZN: "<<m_analysts[i]->AMZNTPL<<"     ";
            /* v contains x */
        } else {
            //outputStream<<"     ";
        }
        outputStream<<endl;
        if(find(m_analysts[i]->symbols.begin(), m_analysts[i]->symbols.end(), "MSFT") != m_analysts[i]->symbols.end()) {
            outputStream<<"MSFT: "<<m_analysts[i]->MSFTTPL<<"     ";
            /* v contains x */
        } else {
            //outputStream<<"     ";
        }
        outputStream<<endl;
        if(find(m_analysts[i]->symbols.begin(), m_analysts[i]->symbols.end(), "AAPL") != m_analysts[i]->symbols.end()) {
            outputStream <<"AAPL"<< m_analysts[i]->AAPLTPL << "     ";
            /* v contains x */
        }
        else {
            //outputStream <<"     ";
        }
        outputStream<<endl;
        if(find(m_analysts[i]->symbols.begin(), m_analysts[i]->symbols.end(), "GOOGL") != m_analysts[i]->symbols.end()) {
            outputStream<<"GOOG"<<m_analysts[i]->GOOGLTPL;
            /* v contains x */
        } else {
            //outputStream<<"     ";
        }
        outputStream<<endl;
        outputStream<<endl;
    }
    // TODO: Write out Stock Performance table.  The classes from the FormattedTable example might be helpful.
}
