#ifndef SOLD_H
#define SOLD_H

#include "date.h"
#include "good.h"

#include <vector>

class good;

class Sold
{
public:
    unsigned int getCustomerCode() const;
    void setProductID(unsigned int, int, good[], vector<Sold>, unsigned int);
    unsigned int getProductID() const;
    void setAmount(float);
    float getAmount() const;
    void setNumber(int);
    int getNumber() const;
    void setAmountDiscount(float);
    float getAmountDiscount() const;
    void setSaleDate(string);
    string getSaleDate() const;
    void saveSoldData() const;
    void setSaleDateYear(int);
    void setSaleDateMonth(int);
    void setSaleDateDay(int);
    void setSaleDateHour(int);
    void setSaleDateMinute(int);
    Date getDate();

private:
    unsigned int customerCode, productID;
    float amount, amountDiscount;
    int number;
    Date saleDate;
    void setCustomerCode(int, good[], vector<Sold>);
};

#endif