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
        cout << i + 1 << "the Variety details:\n";
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
    prod[productID-1]=(*this);

}

void Product::displayProductItems()
{
    cout << "Total number of items available in " << name << ": " << items.size() << endl;
    for (int i = 0; i < items.size(); ++i)
    {
        cout << i + 1 << "the item details:\n";
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
    string NameUser;
    cout << "Please enter your name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
    getline(cin, NameUser);

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
    return User(NameUser, MobileNumber, Address, EmailAddress,"Null");
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
        cout << i + 1 << "the product details:\n";
        prod[i].displayProductInfo();
        cout << endl;
    }
}

void ShoppingManagementSystem::displayUsersfeedback()
{
    cout << "Total number of users available in " << name << ": " << Users.size() << endl;
    for (int i = 0; i < Users.size(); ++i)
    {
        cout << i + 1 << "the user details:\n";
        Users[i].displayUserInfoForOSMSystem();
        cout << endl;
    }
}

//front page to choose what type of user is
void ShoppingManagementSystem::front_page(){
    cout<<endl;
            cout<<"Login Page:-"<<endl;
            cout<<"1. Login"<<endl;
            cout<<"2. SignUp"<<endl;
            cout<<"Choose any one option to start with "<<name<<":"<<endl;
            int choice;
            cin>>choice;


    switch(choice)
    {
        case 1:
                login();
                break;
        case 2:
                signup();
              break;
        default :
                cout<<"INVALID INPUT.OPEN THE PROGRAM AGAIN."<<endl;
                exit(0);

    }
}

// Definitions of ShoppingManagementSystem member functions
void ShoppingManagementSystem::run() {
    while (true) {
        displayMainMenu();
    }
}

void ShoppingManagementSystem::displayMainMenu() {
    int choice;
    cout << "\n--------------------Main Menu:--------------------\n";
    cout << "1. View Products\n";
    cout<< "2. View Cart\n";
    cout << "3. View User Feedback\n";
    cout << "4. Quit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        
        case 1:
            browseProducts();
            break;
        case 2:
            show_cart();
            break;
             
        case 3:
            displayUsersfeedback();
            break;
        case 4:
        if (Users[login_userID - 1].feedback.empty()){
                cout<<endl;
                Users[login_userID-1].giveFeedback();
            }
            cout<<endl;
            cout<<"GOOD TIME WITH YOU.SEE YOU SOON!"<<endl;
            exit(0);
        default:
            cout << "Invalid choice, please try again.\n";
    }
}

void ShoppingManagementSystem::login() {
    int  attempts = 0;
    while (attempts < 3) {
        cout << "Enter your customer ID: ";
        cin >> login_userID;
        // Validate login_userID
        if (login_userID > 0 && login_userID <= Users.size()) {
            cout << "Login successful.\n";
            Users[login_userID-1].displayUserInfo();
            return;
        } else {
            cout << "Invalid customer ID. Try again.\n";
            attempts++;
        }
    }
    cout << "Failed login attempts. Exiting program.\n";
    exit(1);
}

void ShoppingManagementSystem::signup() {
    User newUser = newUser.takeUserInfo();
    newUser.customerID = User::Users.size(); // Set the customerID as the size of Users array
    cout << "Signup successful. Your customer ID is: " << newUser.customerID << endl;
    login_userID=newUser.customerID;
}

void ShoppingManagementSystem::browseProducts() {
    displayProducts();
    handleProductSelection();
}

void ShoppingManagementSystem::handleProductSelection() {
    int productID;
    cout << "Enter Product ID to view items (or 0 to go back): ";
    cin >> productID;
    
    if (productID == 0) return; // Go back to previous menu
    if (productID < 1 || productID > prod.size()) {
        cout << "Invalid Product ID. Returning to menu.\n";
        return;
    }
    
    Product selectedProduct = prod[productID - 1];
    selectedProduct.displayProductItems();

    int itemID;
    cout << "Enter Item ID to view brands (or 0 to go back): ";
    cin >> itemID;

    if (itemID == 0) return;
    if (itemID < 1 || itemID > selectedProduct.items.size()) {
        cout << "Invalid Item ID. Returning to menu.\n";
        return;
    }

    Item selectedItem = selectedProduct.items[itemID - 1];
    selectedItem.displayItemBrands();

    int brandID;
    cout << "Enter Brand ID to view varieties (or 0 to go back): ";
    cin >> brandID;

    if (brandID == 0) return;
    if (brandID < 1 || brandID > selectedItem.Brands.size()) {
        cout << "Invalid Brand ID. Returning to menu.\n";
        return;
    }

    Brand &selectedBrand = selectedItem.Brands[brandID - 1];
    selectedBrand.displayBrandVarieties();

    int varietyID;
    cout << "Enter Variety ID to view details (or 0 to go back): ";
    cin >> varietyID;

    if (varietyID == 0) return;
    if (varietyID < 1 || varietyID > selectedBrand.varieties.size()) {
        cout << "Invalid Variety ID. Returning to menu.\n";
        return;
    }

    Variety &selectedVariety = selectedBrand.varieties[varietyID - 1];
    selectedVariety.displayVarietyInfo();

    int user_quantity;
    cout << "Enter quantity to add to cart (or 0 to cancel): ";
    cin >> user_quantity;

    if (user_quantity > 0 && user_quantity<=selectedVariety.quantity ) {
        addToCart(selectedVariety, selectedBrand, selectedItem, selectedProduct,user_quantity);
        selectedVariety.quantity=selectedVariety.quantity-user_quantity;
    } 
    else if(user_quantity > selectedVariety.quantity){
        cout<<"Order cancel due to out of stock of quantity."<<endl;
    }
    else {
        cout << "Cancelled adding to cart.\n";
    }
}


// Add a selected item to the cart
void ShoppingManagementSystem::addToCart(Variety &variety, Brand &brand, Item &item, Product &product, int qty) {
    CartItem cartItem(variety, brand, item, product, qty);
    cart.push_back(cartItem);
    cout << "Added to cart: " << variety.name << " x" << qty << endl;
}


 void ShoppingManagementSystem::generateBill(){
        double bill = 0;
        for(int i=0;i<cart.size();i++){
            bill = bill+cart[i].total_price;
        }
        cout<<"-----------------BILL-----------------"<<endl;
        cout<<"\nTotal money to be pay:-"<<bill<<endl;
        cout<<endl;
        cout<<"Enter 1 to pay:-";
        int input;
        cin>>input;
        if(input!=1){
            cout<<"INVALID INPUT.NO TRANSACTION TAKES PLACE."<<endl;
        }
        else{
            cout<<"YOUR ORDER IS PLACED.SOON YOU GET IT."<<endl;
        }
        
 }

 void ShoppingManagementSystem::show_cart(){
    if(cart.empty()){
        cout<<"CART IS EMPTY."<<endl;
    }
    else{
        for(int i =0;i<cart.size();i++){
        cout<<"Product "<<i+1<<"."<<endl;
        cart[i].display_cartitem();
        cout<<endl;
        }
    cart_functionalities();   
    }
 }

 void ShoppingManagementSystem::cart_functionalities(){
        cout<<"Cart functionalities:-"<<endl;
            cout<<"1.Make Payment"<<endl;
             cout<<"2.Add more Products"<<endl;
             cout<<"3.Remove Products"<<endl;
             int choice;
             cout<<"Choose any of the above function:-";
             cin>>choice;
             switch(choice){
                case 1:
                        generateBill();
                        cout<<endl;
                        Users[login_userID-1].giveFeedback();
                        cout<<endl;
                        delete_cart();
                        break;
                case 2:
                        break;
                case 3:
                        remove_product();
                        break;
                default :
                        cout<<"INVALID CHOICE."<<endl;
                        break;
    }
 }

void ShoppingManagementSystem::delete_cart(){
    cart.clear();
    
} 

void ShoppingManagementSystem::remove_product(){
         cout<<"Enter product number to be remove from the cart:-";
            int number;
            cin>>number;
            auto pos = cart.begin() + (number-1);
            cart.erase(pos);
            cout<<"PRODUCT REMOVED SUCCESSFULLY."<<endl;
}