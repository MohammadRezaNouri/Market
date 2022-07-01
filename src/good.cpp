#include "good.h"

#include <fstream>
#include <iomanip>

void good::setProductID(int index, good Good[])
{
    int temp;
    srand(time(0));
    temp = (rand() % 899) + 100;
    for (int i = 0; i <= index; i++)
        if (temp == Good[i].getProductID())
            throw invalid_argument("Already Exist");
    productID = temp;
}

unsigned int good::getProductID() const
{
    return productID;
}

void good::setName(string Name, int index, good Good[], int temp)
{
    for (int i = 0; i <= index; i++)
        if (Good[i].getName() == Name)
            throw invalid_argument("There is a good with this name.");
    name = Name;
    if (temp == 0)
        setProductID(index, Good);
}

string good::getName() const
{
    return name;
}

void good::setBrand(string Brand)
{
    brand = Brand;
}

string good::getBrand() const
{
    return brand;
}

void good::setTypeMaintenance(int TypeMaintenance)
{
    if (TypeMaintenance == 0)
        Good = NDist;
    else if (TypeMaintenance == 1)
        Good = DNref;
    else if (TypeMaintenance == 2)
        Good = DRef;
    else
        throw invalid_argument("The number entered is incorrect for the type of storage.");
    saveData();
}

string good::getTypeMaintenance() const
{
    if (Good == 0)
        return "NDist";
    if (Good == 1)
        return "DNref";
    if (Good == 2)
        return "DRef";
}

void good::saveData() const
{
    fstream product;
    product.open("product.dat", ios::app);
    if (product.fail())
    {
        cout << "product.dat file was not created." << endl;
        return;
    }
    product << "Product ID : " << setw(5) << getProductID() << endl;
    product << "Name : " << setw(5) << getName() << endl;
    product << "Brand : " << setw(5) << getBrand() << endl;
    product << "Type of maintenance : " << setw(5) << getTypeMaintenance() << endl;
    product << endl;
    product.close();
}

void good::setBuy(string sellerName, float amount, int number)
{
    goodBuy[buyIndex].setSellerName(sellerName);
    goodBuy[buyIndex].setProductID(getProductID());
    goodBuy[buyIndex].setAmount(amount);
    goodBuy[buyIndex].setNumber(number);
}

void good::setBuyPurchaseDate(string Purchase)
{
    goodBuy[buyIndex].setPurchaseDateS(Purchase);
}

void good::setBuyPurchaseDateYear(int temp)
{
    goodBuy[buyIndex].setPurchaseDateYear(temp);
}

void good::setBuyPurchaseDateMonth(int temp)
{
    goodBuy[buyIndex].setPurchaseDateMonth(temp);
}

void good::setBuyPurchaseDateDay(int temp)
{
    goodBuy[buyIndex].setPurchaseDateDay(temp);
}

void good::setBuyPurchaseDateHour(int temp)
{
    goodBuy[buyIndex].setPurchaseDateHour(temp);
}

void good::setBuyPurchaseDateMinute(int temp)
{
    goodBuy[buyIndex].setPurchaseDateMinute(temp);
}

void good::setBuyExpirationDate(string Expiration)
{
    goodBuy[buyIndex].setExpirationDate(Expiration);
}

void good::setBuyExpirationDateYear(int temp)
{
    goodBuy[buyIndex].setExpirationDateYear(temp);
}

void good::setBuyExpirationDateMonth(int temp)
{
    goodBuy[buyIndex].setExpirationDateMonth(temp);
}

void good::setBuyExpirationDateDay(int temp)
{
    goodSold[buyIndex].setSaleDateDay(temp);
}

void good::setBuyExpirationDateHour(int temp)
{
    goodBuy[buyIndex].setExpirationDateHour(temp);
}

void good::setBuyExpirationDateMinute(int temp)
{
    goodBuy[buyIndex].setExpirationDateMinute(temp);
}

void good::setSoldDate(string SoldDate)
{
    goodSold[soldIndex].setSaleDate(SoldDate);
}

void good::setSoldDateYear(int temp)
{
    goodSold[soldIndex].setSaleDateYear(temp);
}

void good::setSoldDateMonth(int temp)
{
    goodSold[soldIndex].setSaleDateMonth(temp);
}

void good::setSoldDateDay(int temp)
{
    goodSold[soldIndex].setSaleDateDay(temp);
}

void good::setSoldDateHour(int temp)
{
    goodSold[soldIndex].setSaleDateHour(temp);
}

void good::setSoldDateMinute(int temp)
{
    goodSold[soldIndex].setSaleDateMinute(temp);
}

void good::buyPush()
{
    goodBuy.push_back(Buy());
    buyIndex++;
}

void good::soldPush()
{
    goodSold.push_back(Sold());
    soldIndex++;
}

void good::buyPop()
{
    goodBuy.pop_back();
    buyIndex--;
}

void good::soldPop()
{
    goodSold.pop_back();
    soldIndex--;
}

void good::saveBuy()
{
    goodBuy[buyIndex].saveBuyData();
}

void good::saveSold()
{
    goodSold[soldIndex].saveSoldData();
}

void good::setSold(float amount, int number, float disCount, int index, good GOOD[], unsigned int customer)
{
    goodSold[soldIndex].setAmount(amount);
    goodSold[soldIndex].setNumber(number);
    goodSold[soldIndex].setAmountDiscount(disCount);
    goodSold[soldIndex].setProductID(getProductID(), index, GOOD, goodSold, customer);
}

int good::getCustomerCode(int CustomerCode)
{
    int Bool = 0;
    for (int i = 0; i < soldIndex; i++)
        if (CustomerCode == goodSold[i].getCustomerCode())
        {
            Bool = 1;
            break;
        }
    return Bool;
}

vector<Buy> good::getGoodBuy()
{
    return goodBuy;
}

vector<Sold> good::getGoodSold()
{
    return goodSold;
}

int good::getBuyIndex()
{
    return buyIndex;
}

int good::getSoldIndex()
{
    return soldIndex;
}