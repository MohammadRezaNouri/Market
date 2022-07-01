#ifndef GOOD_H
#define GOOD_H

#include "Date.h"
#include "Sold.h"
#include "Buy.h"

#include <vector>

class Buy;
class Sold;

class good
{
    friend class Buy;

public:
    unsigned int getProductID() const;
    void setName(string, int, good[], int);
    string getName() const;
    void setBrand(string);
    string getBrand() const;
    void setTypeMaintenance(int);
    string getTypeMaintenance() const;
    void saveData() const;
    void setBuy(string, float, int);
    void setBuyPurchaseDate(string);
    void setBuyPurchaseDateYear(int);
    void setBuyPurchaseDateMonth(int);
    void setBuyPurchaseDateDay(int);
    void setBuyPurchaseDateHour(int);
    void setBuyPurchaseDateMinute(int);
    void setBuyExpirationDate(string);
    void setBuyExpirationDateYear(int);
    void setBuyExpirationDateMonth(int);
    void setBuyExpirationDateDay(int);
    void setBuyExpirationDateHour(int);
    void setBuyExpirationDateMinute(int);
    void setSoldDate(string);
    void setSoldDateYear(int);
    void setSoldDateMonth(int);
    void setSoldDateDay(int);
    void setSoldDateHour(int);
    void setSoldDateMinute(int);
    void buyPush();
    void soldPush();
    void buyPop();
    void soldPop();
    void saveBuy();
    void saveSold();
    void setSold(float, int, float, int, good[], unsigned int);
    int getCustomerCode(int);
    vector<Buy> getGoodBuy();
    vector<Sold> getGoodSold();
    int getBuyIndex();
    int getSoldIndex();

private:
    unsigned int productID;
    string name, brand;
    enum typeMaintenance
    {
        NDist,
        DNref,
        DRef
    };
    typeMaintenance Good;
    void setProductID(int, good[]);
    int buyIndex = 0, soldIndex = 0;
    vector<Buy> goodBuy{vector<Buy>(2)};
    vector<Sold> goodSold{vector<Sold>(2)};
};

#endif
