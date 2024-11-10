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

// Definitions of ShoppingManagementSystem member functions
void ShoppingManagementSystem::run() {
    while (true) {
        displayMainMenu();
    }
}

void ShoppingManagementSystem::displayMainMenu() {
    int choice;
    cout << "\nMain Menu:\n";
    cout << "1. Login\n";
    cout << "2. Sign up\n";
    cout << "3. View Products\n";
    cout << "4. View User Feedback\n";
    cout << "5. Quit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            login();
            break;
        case 2:
            signup();
            break;
        case 3:
            browseProducts();
            break;
        case 4:
            displayUsers();
            break;
        case 5:
            exit(0);
        default:
            cout << "Invalid choice, please try again.\n";
    }
}

void ShoppingManagementSystem::login() {
    int customerID, attempts = 0;
    while (attempts < 3) {
        cout << "Enter your customer ID: ";
        cin >> customerID;
        // Validate customer ID
        if (customerID > 0 && customerID <= Users.size()) {
            cout << "Login successful.\n";
            int choice;
            cout << "1. View Purchase History\n";
            cout << "2. Make a Purchase\n";
            cout << "Enter your choice: ";
            cin >> choice;
            if (choice == 1) showPurchaseHistory(customerID);
            else browseProducts();
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
    User newUser = User::takeUserInfo();
    newUser.customerID = User::Users.size(); // Set the customerID as the size of Users array
    cout << "Signup successful. Your customer ID is: " << newUser.customerID << endl;
    browseProducts();
}

void ShoppingManagementSystem::browseProducts() {
    displayProducts();
    handleProductSelection();
}

void ShoppingManagementSystem::handleProductSelection() {
    int productID;
    cout << "Enter Product ID to view items (or 0 to go back): ";
    cin >> productID;

    // Implement item selection, brand selection, variety selection, quantity selection, and add-to-cart functionality here
    // Use similar logic to navigate within each level
}

// Display purchase history for a user
void ShoppingManagementSystem::showPurchaseHistory(int customerID) {
    if (purchaseHistory.find(customerID) != purchaseHistory.end()) {
        cout << "Purchase History for Customer ID: " << customerID << endl;
        for (const auto& item : purchaseHistory[customerID]) {
            cout << "Product: " << item.product.name 
                 << ", Item: " << item.item.name 
                 << ", Brand: " << item.brand.name 
                 << ", Variety: " << item.variety.name 
                 << ", Quantity: " << item.quantity << endl;
        }
    } else {
        cout << "No purchase history found for Customer ID: " << customerID << endl;
    }
}

// Add a selected item to the cart
void ShoppingManagementSystem::addToCart(Variety &variety, Brand &brand, Item &item, Product &product, int qty) {
    CartItem cartItem(variety, brand, item, product, qty);
    cart.push_back(cartItem);
    cout << "Added to cart: " << variety.name << " x" << qty << endl;
}

// Collect user feedback
void ShoppingManagementSystem::collectFeedback(User &currentUser) {
    string feedback;
    cout << "Please enter your feedback: ";
    cin.ignore();
    getline(cin, feedback);
    currentUser.feedback = feedback;
    cout << "Thank you for your feedback!\n";
}

// View feedback from users
void ShoppingManagementSystem::viewFeedback() {
    cout << "User Feedback:\n";
    for (const auto &user : User::Users) {
        cout << "Customer ID: " << user.customerID << ", Feedback: " << user.feedback << endl;
    }
}
