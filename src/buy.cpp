#include "buy.h"

#include <fstream>
#include <iomanip>

void Buy::setSellerName(string SellerName)
{
    sellerName = SellerName;
}
string Buy::getSellerName() const
{
    return sellerName;
}
void Buy::setProductID(unsigned int ProductID)
{
    productID = ProductID;
}
unsigned int Buy::getProductID() const
{
    return productID;
}
void Buy::setAmount(float Amount)
{
    if (Amount < 0)
        throw invalid_argument("The amount of good can't be less than zero");
    amount = Amount;
}
float Buy::getAmount() const
{
    return amount;
}
void Buy::setNumber(int Number)
{
    if (Number < 0)
        throw invalid_argument("The number of good can't be less than zero");
    number = Number;
}
int Buy::getNumber() const
{
    return number;
}
void Buy::setPurchaseDateS(string date)
{
    purchaseDate.setDate(date);
}
string Buy::getPurchaseDateS() const
{
    return purchaseDate.getDate();
}
void Buy::setExpirationDate(string date)
{
    expirationDate.setDate(date);
}
string Buy::getExpirationDate() const
{
    return expirationDate.getDate();
}
void Buy::saveBuyData() const
{
    fstream Buy;
    Buy.open("Buy.dat", ios::app);
    if (Buy.fail())
    {
        cout << "Buy.dat file was not created." << endl;
        return;
    }
    Buy << "Product ID : " << setw(5) << getProductID() << endl;
    Buy << "Seller's name : " << setw(5) << getSellerName() << endl;
    Buy << "Amount : " << setw(5) << getAmount() << endl;
    Buy << "Numbers : " << setw(5) << getNumber() << endl;
    Buy << "Purchase date : " << setw(5) << purchaseDate.getDate() << endl;
    Buy << "Expiration date : " << setw(5) << expirationDate.getDate() << endl;
    Buy << endl;
    Buy.close();
}
void Buy::setPurchaseDateYear(int temp)
{
    purchaseDate.setYear(temp);
}
void Buy::setPurchaseDateMonth(int temp)
{
    purchaseDate.setMonth(temp);
}
void Buy::setPurchaseDateDay(int temp)
{
    purchaseDate.setDay(temp);
}
void Buy::setPurchaseDateHour(int temp)
{
    purchaseDate.setHour(temp);
}
void Buy::setPurchaseDateMinute(int temp)
{
    purchaseDate.setMinute(temp);
}
void Buy::setExpirationDateYear(int temp)
{
    expirationDate.setYear(temp);
}
void Buy::setExpirationDateMonth(int temp)
{
    expirationDate.setMonth(temp);
}
void Buy::setExpirationDateDay(int temp)
{
    expirationDate.setDay(temp);
}
void Buy::setExpirationDateHour(int temp)
{
    expirationDate.setHour(temp);
}
void Buy::setExpirationDateMinute(int temp)
{
    expirationDate.setMinute(temp);
}
Date Buy::getPurchaseDate() const
{
    return purchaseDate;
}