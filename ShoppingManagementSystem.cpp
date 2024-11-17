#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Variety
{
private:
    int varietyID;
    string description;
    float rating;

public:
    string name;
    int price;
    int quantity;
    Variety() {

    };
    Variety(string name, int varietyID, int price, int quantity, float rating, string description)
        : name(name), varietyID(varietyID), price(price), quantity(quantity), rating(rating), description(description)
    {
    }

    void displayVarietyInfoForBrand();
    void displayVarietyInfo();
};

class Brand : public Variety
{
private:
    float rating;
    int brandID;

public:
    string name;
    vector<Variety> varieties;
    Brand()
    {
    }
    Brand(string name, float rating, int brandID, Variety v)
        : name(name), rating(rating), brandID(brandID)
    {
        varieties.push_back(v);
    }

    void displayBrandInfoForItem();
    void displayBrandVarieties();
    void addVarietyInExisBrand(Variety &V);
};

class Item : public Brand
{
private:
    int itemID;

public:
    string name;
    vector<Brand> Brands;
    Item()
    {
    }
    Item(string name, int itemID, Brand b)
        : name(name), itemID(itemID)
    {
        Brands.push_back(b);
    }

    void displayItemBrands();
    void displayItemsForProduct();
    void addBrandInExisItem(Brand &B);
};

class Product : public Item
{
protected:
    int productID;
    static vector<Product> prod;

public:
    string name;
    vector<Item> items;
    Product()
    {
    }
    Product(string name, int productID, Item i)
        : name(name), productID(productID)
    {
        items.push_back(i);
        prod.push_back((*this));
    }

    void addItemInExisProduct(Item &i);
    void displayProductItems();
    void displayProductInfo();
};

// Initialize static member
vector<Product> Product::prod;

class User
{
protected:
    string name;
    long long mobileNumber;
    string address;
    static vector<User> Users;
    string emailAddress;

public:
    int customerID;
    string feedback;
    User()
    {
    }
    User(string name, long long mobileNumber, string address, string emailAddress)
        : name(name), mobileNumber(mobileNumber), address(address), emailAddress(emailAddress)
    {
        customerID = Users.size() + 1; // Explicitly set customerID based on the Users size
        Users.push_back(*this);
    }

    User(string name, long long mobileNumber, string address, string emailAddress, string feedback)
        : name(name), mobileNumber(mobileNumber), address(address), emailAddress(emailAddress), feedback(feedback)
    {
        customerID = Users.size() + 1; // Explicitly set customerID based on the Users size
        Users.push_back(*this);
    }
    void displayUserInfo();
    static User takeUserInfo();
    void displayUserInfoForOSMSystem();
    void giveFeedback();
};

// Additional class for handling cart items
class CartItem
{
public:
    Variety variety;
    Brand brand;
    Item item;
    Product product;
    long long total_price;
    int quantity;

    CartItem(Variety v, Brand b, Item i, Product p, int qty)
        : variety(v), brand(b), item(i), product(p), quantity(qty)
    {
        total_price = v.price * qty;
    }

    void display_cartitem()
    {
        cout << "Brand: " << brand.name << "\nName: " << variety.name << "\nPrice: " << variety.price << "\nQuantity: " << quantity << "\nTotal Price: " << total_price << endl;
    }
};

// Initialize static member
vector<User> User::Users;
class ShoppingManagementSystem : public Product, public User
{
private:
    const string name = "EasyBuy";
    float platformRating = 4.7;
    vector<CartItem> cart;

public:
    int login_userID;
    ShoppingManagementSystem()
    {
        cout << "\n\nWelcome to " << name << " Online Shopping Management System\n";
        cout << "Rating of our platform: " << platformRating << endl;
    }

    void run(); // Main program loop
    void displayMainMenu();
    void front_page();
    void login();
    void signup();
    void displayUsersfeedback();
    void browseProducts();
    void displayProducts();
    void handleProductSelection();
    void generateBill();
    void addToCart(Variety &variety, Brand &brand, Item &item, Product &product, int qty);
    void show_cart();
    void cart_functionalities();
    void delete_cart();
    void remove_product();
};