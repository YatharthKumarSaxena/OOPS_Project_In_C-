#include "ShoppingManagementSystem.cpp"
#include <limits>
// Member Functions of Variety
void Variety::displayVarietyInfo()
{
    cout << "Name: " << name << "    ";
    cout << "VarietyID: " << varietyID << "\t";
    cout << "Variety Price in Rupees: " << price << "\t";
    cout << "Avaiable quantity for " << name << " is " << quantity << "\n";
    cout << "Description about the variety is given below :- \n"
         << description << endl;
}

void Variety::displayVarietyInfoForBrand()
{
    cout << "Name: " << name << "    ";
    cout << "VarietyID: " << varietyID << "\t" << endl;
}

// Member functions of Brand
void Brand::displayBrandInfoForItem()
{
    cout << "Name of the Brand: " << name << "\t\t";
    cout << "BrandId of the Brand: " << brandID << "\t\t";
    cout << "Brand Rating: " << rating << "/5\n";
}

void Brand::displayBrandVarieties()
{
    cout << "Total number of varieties available in " << name << ": " << varieties.size() << endl;
    for (int i = 0; i < varieties.size(); ++i)
    {
        cout << i + 1 << "th Variety details:\n";
        varieties[i].displayVarietyInfoForBrand();
    }
}

void Brand::addVarietyInExisBrand(Variety &V)
{
    varieties.push_back(V);
}

// Member functions of Item
void Item::displayItemBrands()
{
    cout << "Total number of brands available in " << name << ": " << Brands.size() << endl;
    for (int i = 0; i < Brands.size(); ++i)
    {
        cout << i + 1 << "th Brand details:\n";
        Brands[i].displayBrandInfoForItem();
    }
}

void Item::displayItemsForProduct()
{
    cout << "Name of the Item: " << name << "\t\t";
    cout << "ItemId of the Item: " << itemID << endl;
}

void Item::addBrandInExisItem(Brand &B)
{
    Brands.push_back(B);
}

// Member Functions od Product
void Product::addItemInExisProduct(Item &i)
{
    items.push_back(i);
}

void Product::displayProductItems()
{
    cout << "Total number of items available in " << name << ": " << items.size() << endl;
    for (int i = 0; i < items.size(); ++i)
    {
        cout << i + 1 << "th item details:\n";
        items[i].displayItemsForProduct();
    }
}

void Product::displayProductInfo()
{
    cout << "Name :- " << name << "    ";
    cout << "ProductId :-" << productID;
}

// Member functions of User
void User::displayUserInfo()
{
    cout << "Name:- " << name << endl;
    cout << "Customer ID:- " << customerID << endl;
    cout << "Mobile Number:- " << mobileNumber << endl;
    cout << "Address:- " << address << endl;
    cout << "Email Address:- " << emailAddress << endl;
}

User User::takeUserInfo()
{
    string Name;
    cout << "Please enter your name: ";
    getline(cin, Name);

    long long MobileNumber;
    cout << "Please enter your mobile number: ";
    cin >> MobileNumber;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer

    string Address;
    cout << "Please enter your address: ";
    getline(cin, Address);

    string EmailAddress;
    cout << "Please enter your email address: ";
    getline(cin, EmailAddress);
    return User(Name, MobileNumber, Address, EmailAddress,"Null");
}

void User::displayUserInfoForOSMSystem()
{
    cout << "Customer Name:- " << name << endl;
    cout << "Customer ID:- " << customerID << endl;
    cout << "Feedback:- " << feedback << endl;
}

void User::giveFeedback()
{
    string feed;
    cout << "Please enter your feedback:- ";
    cin >> feed;
    feedback = feed;
}

// Member functions of Online Shopping Management System
void ShoppingManagementSystem::displayProducts()
{
    cout << "Total number of products available in " << name << ": " << prod.size() << endl;
    for (int i = 0; i < prod.size(); ++i)
    {
        cout << i + 1 << "th product details:\n";
        prod[i].displayProductInfo();
        cout << endl;
    }
}

void ShoppingManagementSystem::displayUsers()
{
    cout << "Total number of users available in " << name << ": " << Users.size() << endl;
    for (int i = 0; i < Users.size(); ++i)
    {
        cout << i + 1 << "th user details:\n";
        Users[i].displayUserInfoForOSMSystem();
        cout << endl;
    }
}

