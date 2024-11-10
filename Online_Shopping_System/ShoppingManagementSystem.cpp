#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Variety {
private:
    int varietyID;
    int price;
    int quantity;
    string description;
    float rating;
    static vector<int> StoredID;

public:
    string name;
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
    float rating;
    int brandID;
    static vector<int> StoredID_B;

public:
    string name;
    vector<Variety> varieties;
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
    int itemID;
    static vector<int> StoredID_I;

public:
    string name;
    vector<Brand> Brands;
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
    int productID;
    static vector<int> StoredID_P;
    static vector<Product>prod;
public:
    string name;
    vector<Item> items;
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
    static vector<User>Users;
    string emailAddress;
public:
    int customerID;
    string feedback;
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

// Additional class for handling cart items
class CartItem {
public:
    Variety variety;
    Brand brand;
    Item item;
    Product product;
    int quantity;

    CartItem(Variety v, Brand b, Item i, Product p, int qty)
        : variety(v), brand(b), item(i), product(p), quantity(qty) {}
};

// Initialize static member
vector<User> User::Users;
class ShoppingManagementSystem : public Product, public User {
private:
    const string name = "EasyBuy";
    float platformRating = 4.7;
    vector<CartItem> cart;
    unordered_map<int, vector<CartItem>> purchaseHistory; // Stores purchase history per customer ID

public:
    ShoppingManagementSystem() {
        cout << "Welcome to " << name << " Online Shopping Management System\n";
        cout << "Rating of our platform: " << platformRating << endl;
    }

    void run(); // Main program loop
    void displayMainMenu();
    void login();
    void signup();
    void displayUsers();
    void browseProducts();
    void viewFeedback();
    void displayProducts();
    void handleProductSelection();
    void generateBill(User &currentUser);
    void showPurchaseHistory(int customerID);
    void addToCart(Variety &variety, Brand &brand, Item &item, Product &product, int qty);
    void collectFeedback(User &currentUser);
};