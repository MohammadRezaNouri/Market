#include "good.h"

#include <fstream>
#include <iomanip>
#include <ctime>

class good;

void print8(good Good[], int i, int j)
{
    fstream Bill;
    Bill.open("Bill.txt", ios::app);
    if (Bill.fail())
    {
        system("clear");
        cout << "********************" << endl;
        cout << "Bill.txt file was not opened." << endl;
        cout << "********************" << endl;
        return;
    }
    cout << "Product ID : " << Good[i].getGoodSold()[j].getProductID() << endl;
    cout << "CustomerCode : " << Good[i].getGoodSold()[j].getCustomerCode() << endl;
    cout << "SaleDate : " << Good[i].getGoodSold()[j].getSaleDate() << endl;
    cout << "Number : " << Good[i].getGoodSold()[j].getNumber() << endl;
    cout << "Amount : " << Good[i].getGoodSold()[j].getAmount() << endl;
    cout << "AmountDiscount : " << Good[i].getGoodSold()[j].getAmountDiscount() << endl;
    Bill << "Product ID : " << setw(5) << Good[i].getGoodSold()[j].getProductID() << endl;
    Bill << "CustomerCode : " << setw(5) << Good[i].getGoodSold()[j].getCustomerCode() << endl;
    Bill << "SaleDate : " << setw(5) << Good[i].getGoodSold()[j].getSaleDate() << endl;
    Bill << "Number : " << setw(5) << Good[i].getGoodSold()[j].getNumber() << endl;
    Bill << "Amount : " << setw(5) << Good[i].getGoodSold()[j].getAmount() << endl;
    Bill << "AmountDiscount : " << setw(5) << Good[i].getGoodSold()[j].getAmountDiscount() << endl;
    Bill << endl;
    Bill.close();
}
void print11(good Good[], int i, int k)
{
    cout << "Amount : " << setw(5) << Good[i].getGoodBuy()[k].getAmount() << endl;
    cout << "Number : " << setw(5) << Good[i].getGoodBuy()[k].getNumber() << endl;
    cout << "Purchase date : " << setw(5) << Good[i].getGoodBuy()[k].getPurchaseDateS() << endl;
    cout << "Expiration date : " << setw(5) << Good[i].getGoodBuy()[k].getExpirationDate() << endl;
    cout << endl;
}
int main()
{
    float temp, temp1;
    good Good[900];
    string t1, t2, t3, t4;
    int index = 0, Bool, i, Bool1, j, tmp, tmp1, temp2; //, temp3;
    unsigned int tmp2, tmp3, temp3;
    Date tempDate, tempDate1;
    cout << "Hi, Welcome to the automation of my supermrket bill." << endl;
Loop:
    cout << "Please select : " << endl;
    cout << "Add good = 1" << endl;
    cout << "Remove good = 2" << endl;
    cout << "Good correction = 3" << endl;
    cout << "View good information = 4" << endl;
    cout << "Search for good = 5" << endl;
    cout << "Buying good = 6" << endl;
    cout << "Sale of good = 7" << endl;
    cout << "Invoice with purchase date interval and customer code = 8" << endl;
    cout << "Invoice with tha name of the good independent of the customer's and date of sale = 9" << endl;
    cout << "Invoice with tha name of the good independent of the supplier and the money paid = 10" << endl;
    cout << "the invoice is paid with tha start and end dates (all purchases) independent of the good and suppliers and the money = 11" << endl;
    cout << "Exit = 0" << endl;
    cout << "Please enter the number : ";
    cin >> temp;
    system("clear");
    if (temp == 1)
    {
    temp1:
        cout << "Cancel = 0, Continues = 1" << endl;
        cin >> temp;
        if (temp == 0)
        {
            system("clear");
            goto Loop;
        }
        else if (temp != 1)
        {
            system("clear");
            cout << "********************" << endl;
            cout << "Invalid value." << endl;
            cout << "********************" << endl;
            goto temp1;
        }
        system("clear");
        if (index > 899)
        {
            cout << "********************" << endl;
            cout << "We don't have memory to add good, please delete a good." << endl;
            cout << "********************" << endl;
            goto Loop;
        }
        cout << "Please enter the good name :" << endl;
        getchar();
        getline(cin, t1);
        try
        {
            Good[index].setName(t1, index, Good, 0);
        }
        catch (invalid_argument &equalProductID)
        {
            system("clear");
            cout << "********************" << endl;
            cerr << equalProductID.what() << endl;
            cout << "********************" << endl;
            goto Loop;
        }
        cout << "Please enter the brand name of the good :" << endl;
        getline(cin, t1);
        Good[index].setBrand(t1);
    TypeMaintenance:
        cout << "Please enter the good type of maintenance :(NDist = 1, DNref = 2, DRef = 3)" << endl;
        cin >> temp;
        try
        {
            Good[index].setTypeMaintenance(temp - 1);
        }
        catch (invalid_argument &typeMaintenance)
        {
            system("clear");
            cout << "********************" << endl;
            cerr << typeMaintenance.what() << endl;
            cout << "********************" << endl;
            goto TypeMaintenance;
        }
        system("clear");
        cout << "********************" << endl;
        cout << "Done." << endl;
        cout << "********************" << endl;
        index++;
        goto Loop;
    }
    else if (temp == 2)
    {
    temp2:
        cout << "Cancel = 0, Continues = 1" << endl;
        cin >> temp;
        if (temp == 0)
        {
            system("clear");
            goto Loop;
        }
        else if (temp != 1)
        {
            system("clear");
            cout << "********************" << endl;
            cout << "Invalid value." << endl;
            cout << "********************" << endl;
            goto temp2;
        }
        system("clear");
        cout << "Please enter the good name :" << endl;
        getchar();
        getline(cin, t1);
        cout << "Please enter the brand name of the good :" << endl;
        getline(cin, t2);
        Bool = 0;
        for (int i = 0; i <= index; i++)
            if (t1 == Good[i].getName() && t2 == Good[i].getBrand())
            {
                Bool = 1;
                fstream soldRemove;
                soldRemove.open("Sold.dat");
                if (soldRemove.fail())
                {
                    system("clear");
                    cout << "********************" << endl;
                    cout << "Sold.dat file was not opened." << endl;
                    cout << "********************" << endl;
                    goto Loop;
                }
                while (getline(soldRemove, t1))
                {
                    if (Good[i].getProductID() == stoi(t1.substr(15, 18)))
                    {
                        system("clear");
                        cout << "********************" << endl;
                        cout << "This good has been sold, so it is not possible to remove it." << endl;
                        cout << "********************" << endl;
                        soldRemove.close();
                        goto Loop;
                    }
                    getline(soldRemove, t1);
                    getline(soldRemove, t1);
                    getline(soldRemove, t1);
                    getline(soldRemove, t1);
                    getline(soldRemove, t1);
                    getline(soldRemove, t1);
                }
                soldRemove.close();
                for (int j = i; j < index; j++)
                    Good[j] = Good[j + 1];
                index--;
                fstream product;
                product.open("product.dat", ios::out);
                product.close();
                for (int k = 0; k < index; k++)
                    Good[k].saveData();
                ifstream buyRemove("Buy.dat", ios::app);
                ofstream temp("temp.dat");
                while (getline(buyRemove, t1))
                    if (Good[i].getProductID() == stoi(t1.substr(15, 17)))
                    {
                        temp << t1 << endl;
                        getline(buyRemove, t1);
                        temp << t1 << endl;
                        getline(buyRemove, t1);
                        temp << t1 << endl;
                        getline(buyRemove, t1);
                        temp << t1 << endl;
                        getline(buyRemove, t1);
                        temp << t1 << endl;
                        getline(buyRemove, t1);
                        temp << t1 << endl;
                        getline(buyRemove, t1);
                    }
                    else
                    {
                        getline(buyRemove, t1);
                        getline(buyRemove, t1);
                        getline(buyRemove, t1);
                        getline(buyRemove, t1);
                        getline(buyRemove, t1);
                        getline(buyRemove, t1);
                    }
                buyRemove.close();
                temp.close();
                remove("Buy.dat");
                rename("temp.dat", "Buy.dat");
                Good[i].buyPop();
                system("clear");
                cout << "********************" << endl;
                cout << "Done." << endl;
                cout << "********************" << endl;
                goto Loop;
            }
        if (Bool == 0)
        {
            system("clear");
            cout << "********************" << endl;
            cout << "We do not have such good." << endl;
            cout << "********************" << endl;
            goto Loop;
        }
    }
    else if (temp == 3)
    {
    temp3:
        cout << "Cancel = 0, Continues = 1" << endl;
        cin >> temp;
        if (temp == 0)
        {
            system("clear");
            goto Loop;
        }
        else if (temp != 1)
        {
            system("clear");
            cout << "********************" << endl;
            cout << "Invalid value." << endl;
            cout << "********************" << endl;
            goto temp3;
        }
        system("clear");
        Bool1 = 0;
        cout << "Please enter the name of the good you want to correction :" << endl;
        getchar();
        getline(cin, t1);
        cout << "Please enter the Brand of the good you want to correction :" << endl;
        getline(cin, t2);
        Bool = 0;
        for (i = 0; i <= index; i++)
            if (t1 == Good[i].getName() && t2 == Good[i].getBrand())
            {
                Bool = 1;
                break;
            }
        if (Bool == 0)
        {
            system("clear");
            cout << "********************" << endl;
            cout << "There is no good with this name." << endl;
            cout << "********************" << endl;
            goto Loop;
        }
    tempName:
        cout << "Do you want to correction the good name?(Yes = 1, No = 0)" << endl;
        cin >> temp;
        if (temp == 1)
        {
            cout << "Please enter the new good name :" << endl;
            getchar();
            getline(cin, t1);
            try
            {
                Good[i].setName(t1, index, Good, 1);
            }
            catch (invalid_argument &equalName)
            {
                system("clear");
                cout << "********************" << endl;
                cerr << equalName.what() << endl;
                cout << "********************" << endl;
                goto Loop;
            }
            Bool1 = 1;
            system("clear");
        }
        else if (temp != 0)
        {
            system("clear");
            cout << "********************" << endl;
            cout << "Invalid value." << endl;
            cout << "********************" << endl;
            goto tempName;
        }
        system("clear");
    tempBrand:
        cout << "Do you want to correction the good brand?(Yes = 1, No = 0)" << endl;
        cin >> temp;
        if (temp == 1)
        {
            cout << "Please enter the new good brand :" << endl;
            getchar();
            getline(cin, t1);
            Good[i].setBrand(t1);
            Bool1 = 1;
            system("clear");
        }
        else if (temp != 0)
        {
            system("clear");
            cout << "********************" << endl;
            cout << "Invalid value." << endl;
            cout << "********************" << endl;
            goto tempBrand;
        }
        system("clear");
    tempTypeMaintenance:
        cout << "Do you want to correction the type of maintenance good?(Yes = 1, No = 0)" << endl;
        cin >> temp;
        if (temp == 1)
        {
            cout << "Please enter the new type of maintenance good :(NDist = 1, DNref = 2, DRef = 3)" << endl;
            cin >> temp;
            Good[i].setTypeMaintenance(temp - 1);
            Bool1 = 1;
            system("clear");
        }
        else if (temp != 0)
        {
            system("clear");
            cout << "********************" << endl;
            cout << "Invalid value." << endl;
            cout << "********************" << endl;
            goto tempTypeMaintenance;
        }
        if (Bool1 == 1)
        {
            fstream product;
            product.open("product.dat", ios::out);
            product.close();
            for (i = 0; i < index; i++)
                Good[i].saveData();
        }
        system("clear");
        cout << "********************" << endl;
        cout << "Done." << endl;
        cout << "********************" << endl;
        goto Loop;
    }
    else if (temp == 4)
    {
    temp4:
        cout << "Cancel = 0, Continues = 1" << endl;
        cin >> temp;
        if (temp == 0)
        {
            system("clear");
            goto Loop;
        }
        else if (temp != 1)
        {
            system("clear");
            cout << "********************" << endl;
            cout << "Invalid value." << endl;
            cout << "********************" << endl;
            goto temp4;
        }
        system("clear");
        cout << "Please enter the name of the good whose information you want to View :" << endl;
        getchar();
        getline(cin, t1);
        cout << "Please enter the brand of the good whose information you want to View :" << endl;
        getline(cin, t2);
        Bool = 0;
        for (i = 0; i <= index; i++)
            if (t1 == Good[i].getName() && t2 == Good[i].getBrand())
            {
                Bool = 1;
                break;
            }
        if (Bool == 0)
        {
            system("clear");
            cout << "********************" << endl;
            cout << "There is no good with this name." << endl;
            cout << "********************" << endl;
            goto Loop;
        }
        system("clear");
    display:
        cout << "Good information :" << endl;
        cout << "Product ID : " << setw(5) << Good[i].getProductID() << endl;
        cout << "Name : " << setw(5) << Good[i].getName() << endl;
        cout << "Brand : " << setw(5) << Good[i].getBrand() << endl;
        cout << "Type of maintenance : " << setw(5) << Good[i].getTypeMaintenance() << endl;
        cout << "Good purchase information :" << endl;
        ifstream viewBuy("Buy.dat");
        while (getline(viewBuy, t1))
            if (Good[i].getProductID() != stoi(t1.substr(16, 18)))
            {
                cout << t1 << endl;
                getline(viewBuy, t1);
                cout << t1 << endl;
                getline(viewBuy, t1);
                cout << t1 << endl;
                getline(viewBuy, t1);
                cout << t1 << endl;
                getline(viewBuy, t1);
                cout << t1 << endl;
                getline(viewBuy, t1);
                cout << t1 << endl;
                getline(viewBuy, t1);
            }
            else
            {
                getline(viewBuy, t1);
                getline(viewBuy, t1);
                getline(viewBuy, t1);
                getline(viewBuy, t1);
                getline(viewBuy, t1);
                getline(viewBuy, t1);
            }
        viewBuy.close();
        cout << "Clean the screen and go to menu?(Yes = 1)" << endl;
        cin >> temp;
        if (temp == 1)
        {
            system("clear");
            cout << "********************" << endl;
            cout << "Done." << endl;
            cout << "********************" << endl;
            goto Loop;
        }
        else if (temp != 1)
        {
            system("clear");
            cout << "********************" << endl;
            cout << "Invalid value." << endl;
            cout << "********************" << endl;
            goto display;
        }
    }
    else if (temp == 5)
    {
    temp5:
        cout << "Cancel = 0, Continues = 1" << endl;
        cin >> temp;
        if (temp == 0)
        {
            system("clear");
            goto Loop;
        }
        else if (temp != 1)
        {
            system("clear");
            cout << "********************" << endl;
            cout << "Invalid value." << endl;
            cout << "********************" << endl;
            goto temp5;
        }
        system("clear");
        cout << "Please enter the full name of the good (or part of the good name) :" << endl;
        getchar();
        getline(cin, t1);
        Bool = 0;
        j = 1;
        for (i = 0; i <= index; i++)
            if (t1 == Good[i].getName() || Good[i].getName().find(t1, 0) != -1)
            {
                cout << "Other good information " << j << " :" << endl;
                cout << "Product ID : " << setw(5) << Good[i].getProductID() << endl;
                cout << "Name : " << setw(5) << Good[i].getName() << endl;
                cout << "Brand : " << setw(5) << Good[i].getBrand() << endl;
                cout << "Type of maintenance : " << setw(5) << Good[i].getTypeMaintenance() << endl;
                Bool = 1;
                j++;
            }
        if (Bool == 0)
        {
            system("clear");
            cout << "********************" << endl;
            cout << "There is no good with this name." << endl;
            cout << "********************" << endl;
            goto Loop;
        }
        cout << "Press any key and enter to go to menu :" << endl;
        getchar();
        system("clear");
        cout << "********************" << endl;
        cout << "Done." << endl;
        cout << "********************" << endl;
        goto Loop;
    }
    else if (temp == 6)
    {
    temp6:
        cout << "Cancel = 0, Continues = 1" << endl;
        cin >> temp;
        if (temp == 0)
        {
            system("clear");
            goto Loop;
        }
        else if (temp != 1)
        {
            system("clear");
            cout << "********************" << endl;
            cout << "Invalid value." << endl;
            cout << "********************" << endl;
            goto temp6;
        }
        system("clear");
    ID6:
        cout << "Please enter the good product ID for buy :(100 - 999)" << endl;
        cin >> temp;
        if (temp < 100 || temp > 999)
        {
            system("clear");
            cout << "********************" << endl;
            cout << "Product ID is wrong.(100 - 999)" << endl;
            cout << "********************" << endl;
            goto ID6;
        }
        Bool = 0;
        for (i = 0; i <= index; i++)
            if (temp == Good[i].getProductID())
            {
                Bool = 1;
                break;
            }
        if (Bool == 0)
        {
            system("clear");
            cout << "********************" << endl;
            cout << "There is no good with this name." << endl;
            cout << "********************" << endl;
            goto Loop;
        }
        cout << "Please enter the name of the seller of the good :" << endl;
        getchar();
        getline(cin, t1);
        cout << "Please enter the amount of the good :" << endl;
        cin >> temp;
        cout << "Please enter the number of good :" << endl;
        cin >> tmp;
        try
        {
            Good[i].setBuy(t1, temp, tmp);
        }
        catch (invalid_argument &errBuy)
        {
            system("clear");
            cout << "********************" << endl;
            cerr << errBuy.what() << endl;
            cout << "********************" << endl;
            goto Loop;
        }
    purchase6:
        cout << "Do yor want to enter the purchase date or use the current system time?(I import = 1, Current system time = 2)" << endl;
        cin >> tmp1;
        if (tmp1 == 1)
        {
            cout << "Please enter the date of purchase of the good :(Example = 2020-04-07 07:12)" << endl;
            getchar();
            getline(cin, t1);
            Good[i].setBuyPurchaseDate(t1);
        }
        else if (tmp1 == 2)
        {
            time_t now = time(0);
            tm *Itm = localtime(&now);
            j = 1900 + Itm->tm_year;
            Good[i].setBuyPurchaseDateYear(j);
            j = 1 + Itm->tm_mon;
            Good[i].setBuyPurchaseDateMonth(j);
            j = Itm->tm_mday;
            Good[i].setBuyPurchaseDateDay(j);
            j = Itm->tm_hour;
            Good[i].setBuyPurchaseDateHour(j);
            j = Itm->tm_min;
            Good[i].setBuyPurchaseDateMinute(j);
        }
        else
        {
            system("clear");
            cout << "********************" << endl;
            cout << "Invalid value." << endl;
            cout << "********************" << endl;
            goto purchase6;
        }
        if (tmp1 == 2)
            getchar();
        cout << "Please enter the date of expiration of the good :(Example = 2020-04-07 07:12)" << endl;
        getline(cin, t1);
        try
        {
            Good[i].setBuyExpirationDate(t1);
        }
        catch (invalid_argument &errBuy)
        {
            system("clear");
            cout << "********************" << endl;
            cerr << errBuy.what() << endl;
            cout << "********************" << endl;
            goto Loop;
        }
        Good[i].saveBuy();
        Good[i].buyPush();
        system("clear");
        cout << "********************" << endl;
        cout << "Done." << endl;
        cout << "********************" << endl;
        goto Loop;
    }
    else if (temp == 7)
    {
    temp7:
        cout << "Cancel = 0, Continues = 1" << endl;
        cin >> temp;
        if (temp == 0)
        {
            system("clear");
            goto Loop;
        }
        else if (temp != 1)
        {
            system("clear");
            cout << "********************" << endl;
            cout << "Invalid value." << endl;
            cout << "********************" << endl;
            goto temp7;
        }
        system("clear");
    ID7:
        cout << "Please enter the good product ID for buy :(100 - 999)" << endl;
        cin >> tmp2;
        if (tmp2 < 100 || tmp2 > 999)
        {
            system("clear");
            cout << "********************" << endl;
            cout << "Product ID is wrong.(100 - 999)" << endl;
            cout << "********************" << endl;
            goto ID7;
        }
        Bool = 0;
        for (i = 0; i < index; i++)
            if (tmp2 == Good[i].getProductID())
            {
                Bool = 1;
                break;
            }
        if (Bool == 0)
        {
            system("clear");
            cout << "********************" << endl;
            cout << "There is no good with this product ID." << endl;
            cout << "********************" << endl;
            goto Loop;
        }
    newCustomer:
        cout << "A new customer?(Yes = 1, No = 0)" << endl;
        cin >> temp2;
        temp3 = 0;
        if (temp2 == 0)
        {
        Customer7:
            cout << "Please enter the customer code :(1000 - 9999)" << endl;
            cin >> tmp;
            if (tmp < 1000 || tmp > 9999)
            {
                system("clear");
                cout << "********************" << endl;
                cout << "Customer code is wrong.(1000 - 9999)" << endl;
                cout << "********************" << endl;
                goto Customer7;
            }
            for (int i = 0; i < index; i++)
                if (Good[i].getCustomerCode(tmp))
                {
                    temp3 = tmp;
                    break;
                }
            if (temp3 == 0)
            {
                system("clear");
                cout << "********************" << endl;
                cout << "There is no customer with this customer code." << endl;
                cout << "********************" << endl;
                goto Loop;
            }
        }
        else if (temp2 != 1)
        {
            system("clear");
            cout << "********************" << endl;
            cout << "Invalid value." << endl;
            cout << "********************" << endl;
            goto newCustomer;
        }
        fstream checkBuy;
        checkBuy.open("Buy.dat");
        if (checkBuy.fail())
        {
            system("clear");
            cout << "********************" << endl;
            cout << "Buy.dat file was not opened." << endl;
            cout << "********************" << endl;
            goto Loop;
        }
        Bool = 0;
        j = 0;
        while (getline(checkBuy, t1))
        {
            if (Good[i].getProductID() == stoi(t1.substr(15, 18)))
            {
                Bool = 1;
                break;
            }
            getline(checkBuy, t1);
            getline(checkBuy, t1);
            getline(checkBuy, t1);
            getline(checkBuy, t1);
            getline(checkBuy, t1);
            getline(checkBuy, t1);
        }
        checkBuy.close();
        if (Bool = 0)
        {
            system("clear");
            cout << "********************" << endl;
            cout << "Buy good first so you can sell." << endl;
            cout << "********************" << endl;
            checkBuy.close();
            goto Loop;
        }
        fstream checkNumberBuy;
        checkNumberBuy.open("Buy.dat");
        if (checkNumberBuy.fail())
        {
            system("clear");
            cout << "********************" << endl;
            cout << "Buy.dat file was not opened." << endl;
            cout << "********************" << endl;
            goto Loop;
        }
        j = 0;
        while (getline(checkNumberBuy, t1))
            if (Good[i].getProductID() == stoi(t1.substr(15, 18)))
            {
                getline(checkNumberBuy, t1);
                getline(checkNumberBuy, t1);
                checkNumberBuy.seekg(10, ios::cur);
                getline(checkNumberBuy, t1);
                j += stoi(t1);
                getline(checkNumberBuy, t1);
                getline(checkNumberBuy, t1);
                getline(checkNumberBuy, t1);
            }
            else
            {
                getline(checkNumberBuy, t1);
                getline(checkNumberBuy, t1);
                getline(checkNumberBuy, t1);
                getline(checkNumberBuy, t1);
                getline(checkNumberBuy, t1);
                getline(checkNumberBuy, t1);
            }
        checkNumberBuy.close();
        fstream checkNumberSold;
        checkNumberSold.open("Sold.dat");
        if (checkNumberSold.fail())
        {
            system("clear");
            cout << "********************" << endl;
            cout << "Sold.dat file was not opened." << endl;
            cout << "********************" << endl;
            goto Loop;
        }
        Bool = 0;
        while (getline(checkNumberSold, t1))
            if (Good[i].getProductID() == stoi(t1.substr(15, 18)))
            {
                getline(checkNumberSold, t1);
                getline(checkNumberSold, t1);
                checkNumberSold.seekg(10, ios::cur);
                getline(checkNumberSold, t1);
                Bool += stoi(t1);
                getline(checkNumberSold, t1);
                getline(checkNumberSold, t1);
                getline(checkNumberSold, t1);
            }
            else
            {
                getline(checkNumberSold, t1);
                getline(checkNumberSold, t1);
                getline(checkNumberSold, t1);
                getline(checkNumberSold, t1);
                getline(checkNumberSold, t1);
                getline(checkNumberSold, t1);
            }
        checkNumberBuy.close();
        if (Bool >= j)
        {
            system("clear");
            cout << "********************" << endl;
            cout << "You have no inventory of this good." << endl;
            cout << "********************" << endl;
            goto Loop;
        }
        cout << "Please enter the amount of the good :" << endl;
        cin >> temp;
        cout << "Please enter the number of good :" << endl;
        cin >> tmp;
        if (tmp > j)
        {
            system("clear");
            cout << "********************" << endl;
            cout << "You have no inventory of this good." << endl;
            cout << "********************" << endl;
            goto Loop;
        }
        cout << "Please enter the amount discount of the good :" << endl;
        cin >> temp1;
        try
        {
            Good[i].setSold(temp, tmp, temp1, index, Good, temp3);
        }
        catch (invalid_argument &errSold)
        {
            // cout << "1" << endl;
            system("clear");
            cout << "********************" << endl;
            cerr << errSold.what() << endl;
            cout << "********************" << endl;
            goto Loop;
        }
    Sale7:
        cout << "Do yor want to enter the sale date or use the current system time?(I import = 1, Current system time = 2)" << endl;
        cin >> tmp1;
        if (tmp1 == 1)
        {
            cout << "Please enter the date of sale of the good :(Example = 2020-04-07 07:12)" << endl;
            getchar();
            getline(cin, t1);
            Good[i].setSoldDate(t1);
        }
        else if (tmp1 == 2)
        {
            time_t now = time(0);
            tm *Itm = localtime(&now);
            j = 1900 + Itm->tm_year;
            Good[i].setSoldDateYear(j);
            j = 1 + Itm->tm_mon;
            Good[i].setSoldDateMonth(j);
            j = Itm->tm_mday;
            Good[i].setSoldDateDay(j);
            j = Itm->tm_hour;
            Good[i].setSoldDateHour(j);
            j = Itm->tm_min;
            Good[i].setSoldDateMinute(j);
        }
        else
        {
            system("clear");
            cout << "********************" << endl;
            cout << "Invalid value." << endl;
            cout << "********************" << endl;
            goto Sale7;
        }
        Good[i].saveSold();
        Good[i].soldPush();
        system("clear");
        cout << "********************" << endl;
        cout << "Done." << endl;
        cout << "********************" << endl;
        goto Loop;
    }
    else if (temp == 8)
    {
    temp8:
        cout << "Cancel = 0, Continues = 1" << endl;
        cin >> temp;
        if (temp == 0)
        {
            system("clear");
            goto Loop;
        }
        else if (temp != 1)
        {
            system("clear");
            cout << "********************" << endl;
            cout << "Invalid value." << endl;
            cout << "********************" << endl;
            goto temp8;
        }
        system("clear");
    Customer8:
        cout << "Please enter the customer code for view :(1000 - 9999)" << endl;
        cin >> tmp;
        if (tmp < 1000 || tmp > 9999)
        {
            system("clear");
            cout << "********************" << endl;
            cout << "Customer code is wrong.(1000 - 9999)" << endl;
            cout << "********************" << endl;
            goto Customer8;
        }
        Bool1 = 0;
        for (i = 0; i < index; i++)
            if (Good[i].getCustomerCode(tmp))
            {
                Bool1 = 1;
                break;
            }
        if (Bool1 == 0)
        {
            system("clear");
            cout << "********************" << endl;
            cout << "There is no customer with this customer code." << endl;
            cout << "********************" << endl;
            goto Loop;
        }
    Fdate8:
        cout << "Please enter the customer's initial purchase date :(Example : 2020-01-22 19:43)" << endl;
        getchar();
        getline(cin, t1);
        try
        {
            tempDate.setDate(t1);
        }
        catch (invalid_argument &errDate)
        {
            system("clear");
            cout << "********************" << endl;
            cerr << errDate.what() << endl;
            cout << "********************" << endl;
            goto Fdate8;
        }
    Ldate8:
        cout << "Please enter the end date of the customer's purchase :(Example : 2020-01-22 19:43)" << endl;
        getline(cin, t2);
        try
        {
            tempDate1.setDate(t2);
        }
        catch (invalid_argument &errDate1)
        {
            system("clear");
            cout << "********************" << endl;
            cerr << errDate1.what() << endl;
            cout << "********************" << endl;
            goto Ldate8;
        }
        fstream Bill;
        Bill.open("Bill.txt", ios::out);
        if (Bill.fail())
        {
            system("clear");
            cout << "********************" << endl;
            cout << "Bill.txt file was not opened." << endl;
            cout << "********************" << endl;
            goto Loop;
        }
        Bill.close();
        Bool = 0;
        for (j = 0; j < index; j++)
            for (int k = 0; k <= Good[i].getSoldIndex(); k++)
                if (tmp == Good[j].getGoodSold()[k].getCustomerCode())
                    if (Good[j].getGoodSold()[k].getDate().getYear() > tempDate.getYear() && Good[j].getGoodSold()[k].getDate().getYear() < tempDate1.getYear())
                    {
                        Bool = 1;
                        print8(Good, j, k);
                    }
                    else if (Good[i].getGoodSold()[j].getDate().getYear() == tempDate.getYear() && Good[i].getGoodSold()[j].getDate().getYear() < tempDate1.getYear())
                        if (Good[i].getGoodSold()[j].getDate().getMonth() > tempDate.getMonth())
                        {
                            Bool = 1;
                            print8(Good, j, k);
                        }
                        else if (Good[i].getGoodSold()[j].getDate().getMonth() == tempDate.getMonth() && Good[i].getGoodSold()[j].getDate().getDay() > tempDate.getDay())
                        {
                            Bool = 1;
                            print8(Good, j, k);
                        }
                        else if (Good[i].getGoodSold()[j].getDate().getMonth() == tempDate.getMonth() && Good[i].getGoodSold()[j].getDate().getDay() == tempDate.getDay() && Good[i].getGoodSold()[j].getDate().getHour() > tempDate.getHour())
                        {
                            Bool = 1;
                            print8(Good, j, k);
                        }
                        else if (Good[i].getGoodSold()[j].getDate().getMonth() == tempDate.getMonth() && Good[i].getGoodSold()[j].getDate().getDay() == tempDate.getDay() && Good[i].getGoodSold()[j].getDate().getHour() == tempDate.getHour() && Good[i].getGoodSold()[j].getDate().getMinute() >= tempDate.getMinute())
                        {
                            Bool = 1;
                            print8(Good, j, k);
                        }
                    else if (Good[i].getGoodSold()[j].getDate().getYear() == tempDate.getYear() && Good[i].getGoodSold()[j].getDate().getYear() == tempDate1.getYear())
                        if (Good[i].getGoodSold()[j].getDate().getMonth() > tempDate.getMonth() && Good[i].getGoodSold()[j].getDate().getMonth() <= tempDate1.getMonth())
                        {
                            Bool = 1;
                            print8(Good, j, k);
                        }
                        else if (Good[i].getGoodSold()[j].getDate().getMonth() == tempDate.getMonth() && Good[i].getGoodSold()[j].getDate().getMonth() < tempDate1.getMonth() && Good[i].getGoodSold()[j].getDate().getDay() > tempDate.getDay())
                        {
                            Bool = 1;
                            print8(Good, j, k);
                        }
                        else if (Good[i].getGoodSold()[j].getDate().getMonth() == tempDate.getMonth() && Good[i].getGoodSold()[j].getDate().getMonth() == tempDate1.getMonth() && Good[i].getGoodSold()[j].getDate().getDay() > tempDate.getDay() && Good[i].getGoodSold()[j].getDate().getDay() < tempDate1.getDay())
                        {
                            Bool = 1;
                            print8(Good, j, k);
                        }
                        else if (Good[i].getGoodSold()[j].getDate().getMonth() == tempDate.getMonth() && Good[i].getGoodSold()[j].getDate().getMonth() == tempDate1.getMonth() && Good[i].getGoodSold()[j].getDate().getDay() == tempDate.getDay() && Good[i].getGoodSold()[j].getDate().getDay() == tempDate1.getDay() && Good[i].getGoodSold()[j].getDate().getHour() > tempDate.getHour() && Good[i].getGoodSold()[j].getDate().getHour() <= tempDate1.getHour())
                        {
                            Bool = 1;
                            print8(Good, j, k);
                        }
                        else if (Good[i].getGoodSold()[j].getDate().getMonth() == tempDate.getMonth() && Good[i].getGoodSold()[j].getDate().getMonth() == tempDate1.getMonth() && Good[i].getGoodSold()[j].getDate().getDay() == tempDate.getDay() && Good[i].getGoodSold()[j].getDate().getDay() == tempDate1.getDay() && Good[i].getGoodSold()[j].getDate().getHour() == tempDate.getHour() && Good[i].getGoodSold()[j].getDate().getHour() == tempDate1.getHour() && Good[i].getGoodSold()[j].getDate().getMinute() > tempDate.getMinute() && Good[i].getGoodSold()[j].getDate().getMinute() < tempDate1.getMinute())
                        {
                            Bool = 1;
                            print8(Good, j, k);
                        }
                        else if (Good[i].getGoodSold()[j].getDate().getMonth() == tempDate.getMonth() && Good[i].getGoodSold()[j].getDate().getMonth() == tempDate1.getMonth() && Good[i].getGoodSold()[j].getDate().getDay() == tempDate.getDay() && Good[i].getGoodSold()[j].getDate().getDay() == tempDate1.getDay() && Good[i].getGoodSold()[j].getDate().getHour() == tempDate.getHour() && Good[i].getGoodSold()[j].getDate().getHour() == tempDate1.getHour() && Good[i].getGoodSold()[j].getDate().getMinute() > tempDate.getMinute() && Good[i].getGoodSold()[j].getDate().getMinute() < tempDate1.getMinute())
                        {
                            Bool = 1;
                            print8(Good, j, k);
                        }
                        else if (Good[i].getGoodSold()[j].getDate().getMonth() == tempDate.getMonth() && Good[i].getGoodSold()[j].getDate().getMonth() == tempDate1.getMonth() && Good[i].getGoodSold()[j].getDate().getDay() == tempDate.getDay() && Good[i].getGoodSold()[j].getDate().getDay() == tempDate1.getDay() && Good[i].getGoodSold()[j].getDate().getHour() == tempDate.getHour() && Good[i].getGoodSold()[j].getDate().getHour() == tempDate1.getHour() && Good[i].getGoodSold()[j].getDate().getMinute() == tempDate.getMinute() && Good[i].getGoodSold()[j].getDate().getMinute() == tempDate1.getMinute())
                        {
                            Bool = 1;
                            print8(Good, j, k);
                        }
                    else if (Good[i].getGoodSold()[j].getDate().getYear() > tempDate.getYear() && Good[i].getGoodSold()[j].getDate().getYear() == tempDate1.getYear())
                        if (Good[i].getGoodSold()[j].getDate().getMonth() < tempDate1.getMonth())
                        {
                            Bool = 1;
                            print8(Good, j, k);
                        }
                        else if (Good[i].getGoodSold()[j].getDate().getMonth() == tempDate1.getMonth() && Good[i].getGoodSold()[j].getDate().getDay() < tempDate1.getDay())
                        {
                            Bool = 1;
                            print8(Good, j, k);
                        }
                        else if (Good[i].getGoodSold()[j].getDate().getMonth() == tempDate1.getMonth() && Good[i].getGoodSold()[j].getDate().getDay() == tempDate1.getDay() && Good[i].getGoodSold()[j].getDate().getHour() < tempDate1.getHour())
                        {
                            Bool = 1;
                            print8(Good, j, k);
                        }
                        else if (Good[i].getGoodSold()[j].getDate().getMonth() == tempDate1.getMonth() && Good[i].getGoodSold()[j].getDate().getDay() == tempDate1.getDay() && Good[i].getGoodSold()[j].getDate().getHour() == tempDate1.getHour() && Good[i].getGoodSold()[j].getDate().getMinute() <= tempDate1.getMinute())
                        {
                            Bool = 1;
                            print8(Good, j, k);
                        }
        if (Bool == 0)
        {
            system("clear");
            cout << "********************" << endl;
            cout << "This customer has not made a purchase in this historical period." << endl;
            cout << "********************" << endl;
            goto Loop;
        }
        cout << "Press any key and enter to go to menu :" << endl;
        getchar();
        system("clear");
        cout << "********************" << endl;
        cout << "Done." << endl;
        cout << "********************" << endl;
        goto Loop;
    }
    else if (temp == 9)
    {
    temp9:
        cout << "Cancel = 0, Continues = 1" << endl;
        cin >> temp;
        if (temp == 0)
        {
            system("clear");
            goto Loop;
        }
        else if (temp != 1)
        {
            system("clear");
            cout << "********************" << endl;
            cout << "Invalid value." << endl;
            cout << "********************" << endl;
            goto temp9;
        }
        system("clear");
        cout << "Please enter the name of the good :" << endl;
        getchar();
        getline(cin, t1);
        Bool = 0;
        j = 1;
        for (i = 0; i <= index; i++)
            for (int k = 0; k < Good[i].getSoldIndex(); k++)
                if (t1 == Good[i].getName())
                {
                    cout << "Good sales information " << j << " :" << endl;
                    cout << "Product ID : " << setw(5) << Good[i].getProductID() << endl;
                    cout << "Amount : " << setw(5) << Good[i].getGoodSold()[k].getAmount() << endl;
                    cout << "Number : " << setw(5) << Good[i].getGoodSold()[k].getNumber() << endl;
                    cout << "The amount of discount : " << setw(5) << Good[i].getGoodSold()[k].getAmountDiscount() << endl;
                    Bool = 1;
                    j++;
                }
        if (Bool == 0)
        {
            system("clear");
            cout << "********************" << endl;
            cout << "There is no good with this name." << endl;
            cout << "********************" << endl;
            goto Loop;
        }
        cout << "Press any key and enter to go to menu :" << endl;
        getchar();
        system("clear");
        cout << "********************" << endl;
        cout << "Done." << endl;
        cout << "********************" << endl;
        goto Loop;
    }
    else if (temp == 10)
    {
    temp10:
        cout << "Cancel = 0, Continues = 1" << endl;
        cin >> temp;
        if (temp == 0)
        {
            system("clear");
            goto Loop;
        }
        else if (temp != 1)
        {
            system("clear");
            cout << "********************" << endl;
            cout << "Invalid value." << endl;
            cout << "********************" << endl;
            goto temp10;
        }
        system("clear");
        cout << "Please enter the name of the good :" << endl;
        getchar();
        getline(cin, t1);
        Bool = 0;
        j = 1;
        temp2 = 0;
        for (i = 0; i <= index; i++)
            for (int k = 0; k < Good[i].getBuyIndex(); k++)
                if (t1 == Good[i].getName())
                {
                    cout << "Good buy information " << j << " :" << endl;
                    cout << "Product ID : " << setw(5) << Good[i].getProductID() << endl;
                    cout << "Amount : " << setw(5) << Good[i].getGoodBuy()[k].getAmount() << endl;
                    cout << "Number : " << setw(5) << Good[i].getGoodBuy()[k].getNumber() << endl;
                    cout << "Purchase date : " << setw(5) << Good[i].getGoodBuy()[k].getPurchaseDateS() << endl;
                    cout << "Expiration date : " << setw(5) << Good[i].getGoodBuy()[k].getExpirationDate() << endl;
                    cout << endl;
                    temp2 += Good[i].getGoodBuy()[k].getAmount() * Good[i].getGoodBuy()[k].getNumber();
                    Bool = 1;
                    j++;
                }
        if (Bool == 0)
        {
            system("clear");
            cout << "********************" << endl;
            cout << "There is no good with this name." << endl;
            cout << "********************" << endl;
            goto Loop;
        }
        cout << "Total money paid : " << setw(5) << temp2 << endl;
        cout << "Press any key and enter to go to menu :" << endl;
        getchar();
        system("clear");
        cout << "********************" << endl;
        cout << "Done." << endl;
        cout << "********************" << endl;
        goto Loop;
    }
    else if (temp == 11)
    {
    temp11:
        cout << "Cancel = 0, Continues = 1" << endl;
        cin >> temp;
        if (temp == 0)
        {
            system("clear");
            goto Loop;
        }
        else if (temp != 1)
        {
            system("clear");
            cout << "********************" << endl;
            cout << "Invalid value." << endl;
            cout << "********************" << endl;
            goto temp11;
        }
        system("clear");
    Fdate11:
        cout << "Please enter the initial date :(Example : 2020-01-22 19:43)" << endl;
        getchar();
        getline(cin, t1);
        try
        {
            tempDate.setDate(t1);
        }
        catch (invalid_argument &errDate)
        {
            system("clear");
            cout << "********************" << endl;
            cerr << errDate.what() << endl;
            cout << "********************" << endl;
            goto Fdate11;
        }
    Ldate11:
        cout << "Please enter the end date :(Example : 2020-01-22 19:43)" << endl;
        getline(cin, t2);
        try
        {
            tempDate1.setDate(t2);
        }
        catch (invalid_argument &errDate1)
        {
            system("clear");
            cout << "********************" << endl;
            cerr << errDate1.what() << endl;
            cout << "********************" << endl;
            goto Ldate11;
        }
        Bool = 0;
        temp2 = 0;
        for (j = 0; j < index; j++)
            for (int k = 0; k <= Good[j].getBuyIndex(); k++)
                if (Good[j].getGoodBuy()[k].getPurchaseDate().getYear() > tempDate.getYear() && Good[j].getGoodBuy()[k].getPurchaseDate().getYear() < tempDate1.getYear())
                {
                    Bool = 1;
                    temp2 += Good[j].getGoodBuy()[k].getAmount() * Good[j].getGoodBuy()[k].getNumber();
                    print11(Good, j, k);
                }
                else if (Good[j].getGoodBuy()[k].getPurchaseDate().getYear() == tempDate.getYear() && Good[j].getGoodBuy()[k].getPurchaseDate().getYear() < tempDate1.getYear())
                    if (Good[j].getGoodBuy()[k].getPurchaseDate().getMonth() > tempDate.getMonth())
                    {
                        Bool = 1;
                        temp2 += Good[j].getGoodBuy()[k].getAmount() * Good[j].getGoodBuy()[k].getNumber();
                        print11(Good, j, k);
                    }
                    else if (Good[j].getGoodBuy()[k].getPurchaseDate().getMonth() == tempDate.getMonth() && Good[j].getGoodBuy()[k].getPurchaseDate().getDay() > tempDate.getDay())
                    {
                        Bool = 1;
                        temp2 += Good[j].getGoodBuy()[k].getAmount() * Good[j].getGoodBuy()[k].getNumber();
                        print11(Good, j, k);
                    }
                    else if (Good[j].getGoodBuy()[k].getPurchaseDate().getMonth() == tempDate.getMonth() && Good[j].getGoodBuy()[k].getPurchaseDate().getDay() == tempDate.getDay() && Good[j].getGoodBuy()[k].getPurchaseDate().getHour() > tempDate.getHour())
                    {
                        Bool = 1;
                        temp2 += Good[j].getGoodBuy()[k].getAmount() * Good[j].getGoodBuy()[k].getNumber();
                        print11(Good, j, k);
                    }
                    else if (Good[j].getGoodBuy()[k].getPurchaseDate().getMonth() == tempDate.getMonth() && Good[j].getGoodBuy()[k].getPurchaseDate().getDay() == tempDate.getDay() && Good[j].getGoodBuy()[k].getPurchaseDate().getHour() == tempDate.getHour() && Good[j].getGoodBuy()[k].getPurchaseDate().getMinute() >= tempDate.getMinute())
                    {
                        Bool = 1;
                        temp2 += Good[j].getGoodBuy()[k].getAmount() * Good[j].getGoodBuy()[k].getNumber();
                        print11(Good, j, k);
                    }
                else if (Good[j].getGoodBuy()[k].getPurchaseDate().getYear() == tempDate.getYear() && Good[j].getGoodBuy()[k].getPurchaseDate().getYear() == tempDate1.getYear())
                    if (Good[j].getGoodBuy()[k].getPurchaseDate().getMonth() > tempDate.getMonth() && Good[j].getGoodBuy()[k].getPurchaseDate().getMonth() <= tempDate1.getMonth())
                    {
                        Bool = 1;
                        temp2 += Good[j].getGoodBuy()[k].getAmount() * Good[j].getGoodBuy()[k].getNumber();
                        print11(Good, j, k);
                    }
                    else if (Good[j].getGoodBuy()[k].getPurchaseDate().getMonth() == tempDate.getMonth() && Good[j].getGoodBuy()[k].getPurchaseDate().getMonth() < tempDate1.getMonth() && Good[j].getGoodBuy()[k].getPurchaseDate().getDay() > tempDate.getDay())
                    {
                        Bool = 1;
                        temp2 += Good[j].getGoodBuy()[k].getAmount() * Good[j].getGoodBuy()[k].getNumber();
                        print11(Good, j, k);
                    }
                    else if (Good[j].getGoodBuy()[k].getPurchaseDate().getMonth() == tempDate.getMonth() && Good[j].getGoodBuy()[k].getPurchaseDate().getMonth() == tempDate1.getMonth() && Good[j].getGoodBuy()[k].getPurchaseDate().getDay() > tempDate.getDay() && Good[j].getGoodBuy()[k].getPurchaseDate().getDay() < tempDate1.getDay())
                    {
                        Bool = 1;
                        temp2 += Good[j].getGoodBuy()[k].getAmount() * Good[j].getGoodBuy()[k].getNumber();
                        print11(Good, j, k);
                    }
                    else if (Good[j].getGoodBuy()[k].getPurchaseDate().getMonth() == tempDate.getMonth() && Good[j].getGoodBuy()[k].getPurchaseDate().getMonth() == tempDate1.getMonth() && Good[j].getGoodBuy()[k].getPurchaseDate().getDay() == tempDate.getDay() && Good[j].getGoodBuy()[k].getPurchaseDate().getDay() == tempDate1.getDay() && Good[j].getGoodBuy()[k].getPurchaseDate().getHour() > tempDate.getHour() && Good[j].getGoodBuy()[k].getPurchaseDate().getHour() <= tempDate1.getHour())
                    {
                        Bool = 1;
                        temp2 += Good[j].getGoodBuy()[k].getAmount() * Good[j].getGoodBuy()[k].getNumber();
                        print11(Good, j, k);
                    }
                    else if (Good[j].getGoodBuy()[k].getPurchaseDate().getMonth() == tempDate.getMonth() && Good[j].getGoodBuy()[k].getPurchaseDate().getMonth() == tempDate1.getMonth() && Good[j].getGoodBuy()[k].getPurchaseDate().getDay() == tempDate.getDay() && Good[j].getGoodBuy()[k].getPurchaseDate().getDay() == tempDate1.getDay() && Good[j].getGoodBuy()[k].getPurchaseDate().getHour() == tempDate.getHour() && Good[j].getGoodBuy()[k].getPurchaseDate().getHour() == tempDate1.getHour() && Good[j].getGoodBuy()[k].getPurchaseDate().getMinute() > tempDate.getMinute() && Good[j].getGoodBuy()[k].getPurchaseDate().getMinute() < tempDate1.getMinute())
                    {
                        Bool = 1;
                        temp2 += Good[j].getGoodBuy()[k].getAmount() * Good[j].getGoodBuy()[k].getNumber();
                        print11(Good, j, k);
                    }
                    else if (Good[j].getGoodBuy()[k].getPurchaseDate().getMonth() == tempDate.getMonth() && Good[j].getGoodBuy()[k].getPurchaseDate().getMonth() == tempDate1.getMonth() && Good[j].getGoodBuy()[k].getPurchaseDate().getDay() == tempDate.getDay() && Good[j].getGoodBuy()[k].getPurchaseDate().getDay() == tempDate1.getDay() && Good[j].getGoodBuy()[k].getPurchaseDate().getHour() == tempDate.getHour() && Good[j].getGoodBuy()[k].getPurchaseDate().getHour() == tempDate1.getHour() && Good[j].getGoodBuy()[k].getPurchaseDate().getMinute() > tempDate.getMinute() && Good[j].getGoodBuy()[k].getPurchaseDate().getMinute() < tempDate1.getMinute())
                    {
                        Bool = 1;
                        temp2 += Good[j].getGoodBuy()[k].getAmount() * Good[j].getGoodBuy()[k].getNumber();
                        print11(Good, j, k);
                    }
                    else if (Good[j].getGoodBuy()[k].getPurchaseDate().getMonth() == tempDate.getMonth() && Good[j].getGoodBuy()[k].getPurchaseDate().getMonth() == tempDate1.getMonth() && Good[j].getGoodBuy()[k].getPurchaseDate().getDay() == tempDate.getDay() && Good[j].getGoodBuy()[k].getPurchaseDate().getDay() == tempDate1.getDay() && Good[j].getGoodBuy()[k].getPurchaseDate().getHour() == tempDate.getHour() && Good[j].getGoodBuy()[k].getPurchaseDate().getHour() == tempDate1.getHour() && Good[j].getGoodBuy()[k].getPurchaseDate().getMinute() == tempDate.getMinute() && Good[j].getGoodBuy()[k].getPurchaseDate().getMinute() == tempDate1.getMinute())
                    {
                        Bool = 1;
                        temp2 += Good[j].getGoodBuy()[k].getAmount() * Good[j].getGoodBuy()[k].getNumber();
                        print11(Good, j, k);
                    }
                else if (Good[j].getGoodBuy()[k].getPurchaseDate().getYear() > tempDate.getYear() && Good[j].getGoodBuy()[k].getPurchaseDate().getYear() == tempDate1.getYear())
                    if (Good[j].getGoodBuy()[k].getPurchaseDate().getMonth() < tempDate1.getMonth())
                    {
                        Bool = 1;
                        temp2 += Good[j].getGoodBuy()[k].getAmount() * Good[j].getGoodBuy()[k].getNumber();
                        print11(Good, j, k);
                    }
                    else if (Good[j].getGoodBuy()[k].getPurchaseDate().getMonth() == tempDate1.getMonth() && Good[j].getGoodBuy()[k].getPurchaseDate().getDay() < tempDate1.getDay())
                    {
                        Bool = 1;
                        temp2 += Good[j].getGoodBuy()[k].getAmount() * Good[j].getGoodBuy()[k].getNumber();
                        print11(Good, j, k);
                    }
                    else if (Good[j].getGoodBuy()[k].getPurchaseDate().getMonth() == tempDate1.getMonth() && Good[j].getGoodBuy()[k].getPurchaseDate().getDay() == tempDate1.getDay() && Good[j].getGoodBuy()[k].getPurchaseDate().getHour() < tempDate1.getHour())
                    {
                        Bool = 1;
                        temp2 += Good[j].getGoodBuy()[k].getAmount() * Good[j].getGoodBuy()[k].getNumber();
                        print11(Good, j, k);
                    }
                    else if (Good[j].getGoodBuy()[k].getPurchaseDate().getMonth() == tempDate1.getMonth() && Good[j].getGoodBuy()[k].getPurchaseDate().getDay() == tempDate1.getDay() && Good[j].getGoodBuy()[k].getPurchaseDate().getHour() == tempDate1.getHour() && Good[j].getGoodBuy()[k].getPurchaseDate().getMinute() <= tempDate1.getMinute())
                    {
                        Bool = 1;
                        temp2 += Good[j].getGoodBuy()[k].getAmount() * Good[j].getGoodBuy()[k].getNumber();
                        print11(Good, j, k);
                    }
        if (Bool == 0)
        {
            system("clear");
            cout << "********************" << endl;
            cout << "You did not make a purchase during this time." << endl;
            cout << "********************" << endl;
            goto Loop;
        }
        cout << "Total money paid : " << setw(5) << temp2 << endl;
        cout << "Press any key and enter to go to menu :" << endl;
        getchar();
        system("clear");
        cout << "********************" << endl;
        cout << "Done." << endl;
        cout << "********************" << endl;
        goto Loop;
    }
    else if (temp == 0)
    {
        system("clear");
        cout << "Bye Bye :)" << endl;
        return 0;
    }
    else
    {
        system("clear");
        cout << "********************" << endl;
        cout << "Invalid value." << endl;
        cout << "********************" << endl;
        goto Loop;
    }
}