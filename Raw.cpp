#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Variety {
private:

    // Data Members
    string name;
    int varietyID;
    int price;
    int quantity;
    string description;
    float rating;
    static vector<int> StoredID;

public:

    // Default Constructors
    Variety(){ 

    };

    // Parameterized Constructor By Initializtion List
    Variety(string name, int varietyID, int price, int quantity,float rating,string description) 
        : name(name), varietyID(varietyID), price(price),quantity(quantity),rating(rating), description(description) {
        StoredID.push_back(varietyID);
    }

    // Member Functions
    void displayVarietyInfo(){
        cout << "Name: " << name << "    ";
        cout << "VarietyID: " << varietyID << "\t";
        cout << "Variety Price in Rupees: " << price << "\t";
        cout << "Avaiable quantity for " << name << " is " << quantity << "\n";
        cout << "Description about the variety is given below :- \n"
         << description << endl;
    }
    
    void displayVarietyInfoForBrand(){
        cout << "Name: " << name << "    ";
        cout << "VarietyID: " << varietyID << "\t"<<endl;
    }
};

// Initialize static member
vector<int> Variety::StoredID;

class Brand : public Variety {
private:

    // Data Members
    string name;
    float rating;
    int brandID;
    vector<Variety> varieties;
    static vector<int> StoredID_B;

public:

    // Default Constructors
    Brand(){

    }

    // Parameterized Constructor By Initializtion List
    Brand(string name, float rating, int brandID, Variety v)
        : name(name), rating(rating), brandID(brandID) {
        varieties.push_back(v);
        StoredID_B.push_back(brandID);
    }

    // Member Functions
    void displayBrandInfoForItem(){
        cout << "Name: " << name << "\t\t";
        cout << "BrandID: " << brandID << "\t\t";
        cout << "Brand Rating: " << rating << "/5\n";
    }

    void displayBrandVarieties(){
        cout << "Total number of varieties available in " << name << ": " << varieties.size() << endl;
        for (int i = 0; i < varieties.size(); ++i) {
            cout << i + 1 << "th Variety details:\n";
            varieties[i].displayVarietyInfoForBrand();
        }
    }
    void addVarietyInExisBrand(Variety& V){
        varieties.push_back(V);
    }
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

    void displayItemBrands(){
        cout << "Total number of brands available in " << name << ": " << Brands.size() << endl;
        for (int i = 0; i < Brands.size(); ++i) {
            cout << i + 1 << "th Brand details:\n";
            Brands[i].displayBrandInfoForItem();
        }
    }

    void displayItemsForProduct(){
        cout << "Name of the Item: " << name << "\t\t";
        cout << "ItemID of the Item: " << itemID << endl;
    }

    void addBrandInExisItem(Brand& B){
        Brands.push_back(B);
    }
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

    void addItemInExisProduct(Item& i){
        items.push_back(i);
    }

    void displayProductItems(){
        cout << "Total number of items available in " << name << ": " << items.size() << endl;
        for (int i = 0; i < items.size(); ++i) {
            cout << i + 1 << "th item details:\n";
            items[i].displayItemsForProduct();
        }
    }

    void displayProductInfo(){
        cout<<"Name :- "<<name<<"    ";
        cout<<"ProductID :-"<<productID;
    }
};

// Initialize static member
vector<int> Product::StoredID_P;
// Initialize static member
vector<Product> Product::prod;

class ShoppingManagementSystem : public Product {
private:
    const string name = "EasyBuy";
    float rating = 4.7;
public:
    ShoppingManagementSystem(){
        cout<<"Welcome to "<<name<<" Online Shopping Management System\n";
        cout<<"Rating of our platform :- "<<rating<<endl;
    }
    void displayProducts() {
        cout << "Total number of products available in " << name << ": " << StoredID_P.size() << endl;
        for (int i = 0; i < Product::prod.size(); ++i) {
            cout << i + 1 << "th product details:\n";
            prod[i].displayProductInfo();
            cout<<endl;
        }
    }
};

// Main function for testing
int main() {
    ShoppingManagementSystem sms;
    // Creating initial instances
    Variety V1("BAJRA", 1, 200, 2,4.2, "5kg Mfg Date:- 05/10/2024 .Expiry Date:- Best before 3 months.");
    Variety V2("MAKKA",2,200,3,4.5,"5Kg. Mfg Date:- 09/11/2024 .Expiry Date:- Best before 2 months from mfg date\n");

    Brand B1("Ashirwaad", 4.3, 1, V1);
    B1.addVarietyInExisBrand(V2);
    Variety V3("MAIDA", 1, 400, 4,4.4, "10kg Mfg Date:- 05/10/2024 .Expiry Date:- Best before 4 months.");
    Variety V4("WHEAT",2,440,5,4.5,"10Kg. Mfg Date:- 07/11/2024 .Expiry Date:- Best before 4 months from mfg date\n");

    Brand B2("Shakti Bhog", 4.1, 2, V3);
    B2.addVarietyInExisBrand(V4);
    //B1.displayBrandVarieties();
    Item I1("Flour", 1, B1);
    I1.addBrandInExisItem(B2);
    Product P1("Cereals", 1, I1);
    Variety V5("Brown Rice",1,400,4,4.5,"5Kg. Mfg Date:- 11/11/2024. Expiry Date:- Best before 6 months from mfg date\n");
    Variety V6("Dry White Rice",2,350,10,4.2,"5Kg. Mfg Date:- 08/11/2024 Expiry Date:- Best before 18 months from mfg date\n");
    Brand B3("Baasmati", 4.3, 1, V5);
    B3.addVarietyInExisBrand(V6);
    Variety V7("Black Rice",1,300,3,4.2,"5Kg. Mfg Date:- 01/10/2024. Expiry Date:- Best before 5 months from mfg date\n");
    Variety V8("Dry White Rice",2,250,5,4.0," 5Kg. Mfg Date:- 05/11/2024 Expiry Date:- Best before from 10 months mfg date\n");
    Brand B4("Daawat rozana", 4.1, 2, V7);
    B4.addVarietyInExisBrand(V8);
    Item I2("Rice", 2, B3);
    I2.addBrandInExisItem(B4);
    
    //P1.displayProductItems();
    //B2.displayBrandVarieties();
    P1.addItemInExisProduct(I2);
    //P1.displayProductItems();
    //I1.displayItemBrands();
    //I2.displayItemBrands();
    Variety V9("BRAVIA 2", 1, 27999, 50,4.7, "43 inches ultra HD smart LED TV");
    Variety V10("BRAVIA 3",2,38999,40,4.8," 47 inches 4k ultra HD smart LED Google TV\n");

    Brand B5("SONY", 4.5, 1, V9);
    B5.addVarietyInExisBrand(V10);
    Variety V11("TSH100", 1, 50000, 35,4.4, "46 inches ultra HD LED TV");
    Variety V12("TLH464",2,17999,37,4.4,"40 inches HD LED TV\n");

    Brand B6("Panasonic", 4.2, 2, V11);
    B6.addVarietyInExisBrand(V12);
    Item I3("Television", 1, B5);
    I3.addBrandInExisItem(B6);
    
    Variety V13("Thinkbook", 1, 55000, 50,4.2, "13 Generation | Intel i5 | 40.64cms | athlon silver | 5020H");
    Variety V14("Ideapad",2,69999,40,4.4," 13 Generation | AMD Ryzen 5 | 5500P | 15.6 inches | Thin and light\n");

    Brand B7("Lenovo", 4.4, 1, V13);
    B7.addVarietyInExisBrand(V14);
    Variety V15("Probook", 1, 35000, 40,4.4, "11 Generation | Core I3 | 1021U | 14 inch | Thin and Light ");
    Variety V16("Elitebook",2,75999,38,4.4,"13 Generation | Intel i7 | 3021P | 17.2 inches | HD quality\n");

    Brand B8("HP", 4.2, 2, V15);
    B8.addVarietyInExisBrand(V16);
    Item I4("Laptops", 2, B7);
    I4.addBrandInExisItem(B8);
    Product P2("Electronics", 2, I3);
    
    P2.addItemInExisProduct(I4);
    Variety V17("Xlumia series", 1, 99, 50,4.2, "Single line | A5 70 ASM sheets | 160 pages");
    Variety V18("Clean up series",2,69,40,4.3,"single line | A4 size sheets | 124 pages\n");

    Brand B9("Doms", 4.3, 1, V17);
   B9.addVarietyInExisBrand(V18);
    Variety V19("Spiral Notebook | 24 cm x18 cm | single line pages", 1, 120, 35,4.4, "250 pages");
    Variety V20("pulse Notebook",2,199,37,4.4,"300 pages | 25 cm x 19.2 cm | excellent white page\n");

    Brand B10("Classmate", 4.5, 2, V19);
    B10.addVarietyInExisBrand(V20);
    Item I5("Notebook", 1, B9);
    I5.addBrandInExisItem(B10);
    
    Variety V21("Space style box", 1, 550, 50,4.2, "inbuilt sharpener | Jumbo pencil box | white board");
    Variety V22("Multifunctional box",2,599,35,4.1,"Jumbo size pencil box\n");

    Brand B11("Toy shine", 4.2, 1, V21);
    B11.addVarietyInExisBrand(V22);
    Variety V23("fairy box", 1, 649, 30,4.2, "inbuilt sharpener | password system");
    Variety V24("cartoon Box",2,349,20,4.0,"Small white board with marker | suitcase style\n");

    Brand B12("Fun Blast", 4.0, 2, V23);
    B12.addVarietyInExisBrand(V24);
    Item I6("Pencil Box", 2, B11);
    I6.addBrandInExisItem(B12);
    Product P3("Stationery", 3, I5);
    
    P3.addItemInExisProduct(I6);
    // B9.displayBrandVarieties();
    // B10.displayBrandVarieties();
    // B11.displayBrandVarieties();
    // B12.displayBrandVarieties();
    
    // sms.displayProducts();
    // P1.displayProductItems();
    // I1.displayItemBrands();
    V24.displayVarietyInfo();
    return 0;
}