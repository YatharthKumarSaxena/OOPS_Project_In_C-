#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Variety {
private:
    string name;
    int varietyID;
    int price;
    int quantity;
    string description;
    float rating;
    static vector<int> StoredID;

public:
    Variety(){

    };
    Variety(string name, int varietyID, int price, int quantity,float rating,string description) 
        : name(name), varietyID(varietyID), price(price),quantity(quantity),rating(rating), description(description) {
        StoredID.push_back(varietyID);
    }

    void displayVarietyInfoForBrand();
    void displayVarietyInfo();
};

// Initialize static member
vector<int> Variety::StoredID;

class Brand : public Variety {
private:
    string name;
    float rating;
    int brandID;
    vector<Variety> varieties;
    static vector<int> StoredID_B;

public:
    Brand(){

    }
    Brand(string name, float rating, int brandID, Variety v)
        : name(name), rating(rating), brandID(brandID) {
        varieties.push_back(v);
        StoredID_B.push_back(brandID);
    }

    void displayBrandInfoForItem();
    void displayBrandVarieties();
    void addVarietyInExisBrand(Variety& V);
};

// Initialize static member
vector<int> Brand::StoredID_B;

class Item : public Brand {
private:
    string name;
    int itemID;
    vector<Brand> Brands;
    static vector<int> StoredID_I;

public:
    Item(){

    }
    Item(string name, int itemID, Brand b)
        : name(name), itemID(itemID) {
        Brands.push_back(b);
        StoredID_I.push_back(itemID);
    }

    void displayItemBrands();
    void displayItemsForProduct();
    void addBrandInExisItem(Brand& B);
};

// Initialize static member
vector<int> Item::StoredID_I;

class Product : public Item {
protected:
    string name;
    int productID;
    vector<Item> items;
    static vector<int> StoredID_P;
    static vector<Product>prod;
public:
    Product(){

    }
    Product(string name, int productID, Item i)
        : name(name), productID(productID) {
        items.push_back(i);
        StoredID_P.push_back(productID);
        prod.push_back((*this));
    }

    void addItemInExisProduct(Item& i);
    void displayProductItems();
    void displayProductInfo();
};

// Initialize static member
vector<int> Product::StoredID_P;
// Initialize static member
vector<Product> Product::prod;

class User{
protected:
    string name;
    long long mobileNumber;
    string address;
    int customerID;
    static vector<User>Users;
    string emailAddress;
    string feedback;
public:
    User(){

    }
    User(string name, long long mobileNumber, string address, string emailAddress)
        : name(name), mobileNumber(mobileNumber), address(address), emailAddress(emailAddress) {
        customerID = Users.size() + 1; // Explicitly set customerID based on the Users size
        Users.push_back(*this);
    }

    User(string name, long long mobileNumber, string address, string emailAddress, string feedback)
        : name(name), mobileNumber(mobileNumber), address(address), emailAddress(emailAddress), feedback(feedback) {
        customerID = Users.size() + 1; // Explicitly set customerID based on the Users size
        Users.push_back(*this);
    }   
    void displayUserInfo();
    static User takeUserInfo();
    void displayUserInfoForOSMSystem();
    void giveFeedback();
};

// Initialize static member
vector<User> User::Users;
class ShoppingManagementSystem : public Product, public User {
private:
    const string name = "EasyBuy";
    float rating = 4.7;
public:
    ShoppingManagementSystem(){
        cout<<"Welcome to "<<name<<" Online Shopping Management System\n";
        cout<<"Rating of our platform :- "<<rating<<endl;
    }
    void displayProducts();
    void displayUsers();
};