#include"function.h"
#include<string>
#include<iomanip>
using namespace std;

void purchaseComponents()
{
    //setting the values of variables
    const int items = 18;
    int choice;
    float base = 200.0;
    int n;
    float add = 0.0;
    float total = base;
    string choose[3];
    string products[3];
    //float amount;
    int count = 0;
    //the table of contents
    string store[items][4] =
    {
        // Category, Item code, Description, Price ($)
        {"Case", "A1", "Compact", "75.00"},
        {"Case", "A2", "Tower", "150.00"},
        {"RAM", "B1", "8 GB", "79.99"},
        {"RAM", "B2", "16 GB", "149.99"},
        {"RAM", "B3", "32 GB", "299.99"},
        {"Main Hard Disk Drive", "C1", "1 TB HDD", "49.99"},
        {"Main Hard Disk Drive", "C2", "2 TB HDD", "89.99"},
        {"Main Hard Disk Drive", "C3", "4 TB HDD", "129.99"},
        {"Solid State Drive", "D1", "240 GB SSD", "59.99"},
        {"Solid State Drive", "D2", "480 GB SSD", "119.99"},
        {"Second Hard Disk Drive", "E1", "1 TB HDD", "49.99"},
        {"Second Hard Disk Drive", "E2", "2 TB HDD", "89.99"},
        {"Second Hard Disk Drive", "E3", "4 TB HDD", "129.99"},
        {"Optical Drive", "F1", "DVD/Blu-Ray Player", "50.00"},
        {"Optical Drive", "F2", "DVD/Blu-Ray Re-writer", "100.00"},
        {"Operating System", "G1", "Standard Version", "100.00"},
        {"Operating System", "G2", "Professional Version", "175.00"}
    };
    cout << "Choose from the following: " << endl;
    cout << "1. One Case" << endl;
    cout << "2. One RAM" << endl;
    cout << "3. One Main Hard Disk Drive" << endl;
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        cout << "Enter the Item Codes: ";
        for (int i = 0; i < 3; i++)
        {
            cin >> choose[i];
            for (int j = 0; j < items; j++)
            {
                //if the item exists in table
                if (store[j][1] == choose[i])
                {
                    //stod to convert from string to double, so we also get value in float
                    base = base + stod(store[j][3]);
                }
            }
        }
        //displaying the choosen items
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < items; j++)
            {
                if (store[j][1] == choose[i])
                {
                    cout << store[j][0] << "\t\t" << store[j][1] << "\t\t" << store[j][2] << "\t\t" << store[j][3] << endl;
                }
            }
        }
        cout << "The total price: $" << base << endl;
        int num;
        //asking if user wants to add more
        while (true)
        {
            cout << "Press 1 to purchase more items." << endl;
            cout << "Press 2 to exit." << endl;
            cin >> num;
            if (num == 1)
            {
                cout << "How many items you want to choose?" << endl;
                cin >> n;

                for (int i = 0; i < n; i++)
                {
                    cout << "Enter the item code for the item: ";
                    string additional;
                    cin >> additional;
                    //checking if item exists and 
                    for (int j = 0; j < items; j++)
                    {
                        if (store[j][1] == additional)
                        {
                            add = add + stod(store[j][3]);
                            total = base + add;
                            products[count++] = store[j][2];
                            break;
                        }
                    }
                }
            }
            else if (num == 2)
            {
                break;
            }
        }
        //displaying additional items
        cout << "Additional Products:\n";
        for (int i = 0; i < count; i++)
        {
            cout << products[i] << endl;
        }
        if (count == 1)
        {
            //5% discount if 1 additional item purchased
            float discount = total * 0.05;
            total = total - discount;
            cout << "Now, the total price (with 5% discount) is: $" << total << " ,you saved $" << discount << endl;
        }
        else if (count == 2)
        {
            //10% discount if 2 additional item purchased
            float discount = total * 0.10;
            total = total - discount;
            cout << "Now, the total price (with 5% discount) is: $" << total << " ,you saved $" << discount << endl;
        }
        break;
    }
    }
}

