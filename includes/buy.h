#ifndef BUY_H
#define BUY_H

#include "Date.h"
#include "good.h"

class Buy
{
public:
    void setSellerName(string);
    string getSellerName() const;
    void setProductID(unsigned int);
    unsigned int getProductID() const;
    void setAmount(float);
    float getAmount() const;
    void setNumber(int);
    int getNumber() const;
    void setPurchaseDateS(string);
    string getPurchaseDateS() const;
    void setExpirationDate(string);
    string getExpirationDate() const;
    void saveBuyData() const;
    void setPurchaseDateYear(int);
    void setPurchaseDateMonth(int);
    void setPurchaseDateDay(int);
    void setPurchaseDateHour(int);
    void setPurchaseDateMinute(int);
    void setExpirationDateYear(int);
    void setExpirationDateMonth(int);
    void setExpirationDateDay(int);
    void setExpirationDateHour(int);
    void setExpirationDateMinute(int);
    Date getPurchaseDate() const;
private:
    string sellerName;
    unsigned int productID;
    float amount;
    int number;
    Date purchaseDate, expirationDate;
};

#endif