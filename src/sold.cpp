#include "Sold.h"

#include <fstream>
#include <iomanip>

void Sold::setCustomerCode(int index, good Good[], vector<Sold> goodSold)
{
    srand(time(0));
    int temp;
    temp = (rand() % 8999) + 1000;
    for (int i = 0; i <= index; i++)
        if (temp == goodSold[i].getCustomerCode())
            throw invalid_argument("Customer code is duplicate, try again");
    customerCode = temp;
}

unsigned int Sold::getCustomerCode() const
{
    return customerCode;
}

void Sold::setProductID(unsigned int ProductID, int index, good Good[], vector<Sold> goodSold, unsigned int customer)
{
    productID = ProductID;
    if (customer == 0)
        setCustomerCode(index, Good, goodSold);
    else
        customerCode = customer;
}

unsigned int Sold::getProductID() const
{
    return productID;
}

void Sold::setAmount(float Amount)
{
    if (Amount < 0)
        throw invalid_argument("The amount of good can't be less than zero");
    amount = Amount;
}

float Sold::getAmount() const
{
    return amount;
}

void Sold::setNumber(int Number)
{
    if (Number < 0)
        throw invalid_argument("The number of good can't be less than zero");
    number = Number;
}

int Sold::getNumber() const
{
    return number;
}

void Sold::setAmountDiscount(float AmountDiscount)
{

    if (getAmount() <= AmountDiscount)
        throw invalid_argument("The good discount is higher than the price.");
    else if (AmountDiscount < 0)
        throw invalid_argument("The discounted amount of the good cna't be less than zero");
    amountDiscount = AmountDiscount;
}

float Sold::getAmountDiscount() const
{
    return amountDiscount;
}

void Sold::setSaleDate(string date)
{
    saleDate.setDate(date);
}

string Sold::getSaleDate() const
{
    return saleDate.getDate();
}

void Sold::saveSoldData() const
{
    fstream Sold;
    Sold.open("Sold.dat", ios::app);
    if (Sold.fail())
    {
        cout << "Sold.dat file was not created." << endl;
        return;
    }
    Sold << "Product ID : " << setw(5) << getProductID() << endl;
    Sold << "Customer code : " << setw(5) << getCustomerCode() << endl;
    Sold << "Amount : " << setw(5) << getAmount() << endl;
    Sold << "Numbers : " << setw(5) << getNumber() << endl;
    Sold << "Sale date : " << setw(5) << saleDate.getDate() << endl;
    Sold << "The amount of discount : " << setw(5) << getAmountDiscount() << endl;
    Sold << endl;
    Sold.close();
}

void Sold::setSaleDateYear(int temp)
{
    saleDate.setYear(temp);
}

void Sold::setSaleDateMonth(int temp)
{
    saleDate.setMonth(temp);
}

void Sold::setSaleDateDay(int temp)
{
    saleDate.setDay(temp);
}

void Sold::setSaleDateHour(int temp)
{
    saleDate.setHour(temp);
}

void Sold::setSaleDateMinute(int temp)
{
    saleDate.setMinute(temp);
}

Date Sold::getDate()
{
    return saleDate;
}