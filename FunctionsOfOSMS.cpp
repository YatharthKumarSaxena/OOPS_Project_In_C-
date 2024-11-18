#include "ShoppingManagementSystem.cpp"
#include <limits>

// Member Functions of Variety
void Variety::displayVarietyInfo()
{
    cout<<"\n-------------------- VARIETY DETAILS --------------------"<<endl;
    cout << "\nName: " << name << "    ";
    cout << "VarietyID: " << varietyID << "\t";
    cout << "Variety Price in Rupees: " << price << "\t";
    cout << "Avaiable quantity for " << name << " is " << quantity << "\n";
    cout << "\nDescription about the variety is given below :- \n"
         << description << endl
         << endl
         << endl;
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
    cout<<"\n-------------------- AVAILABLE VARIETIES --------------------"<<endl;
    cout << "\nTotal number of varieties available in " << name << ": " << varieties.size() << endl
         << endl;
    for (int i = 0; i < varieties.size(); ++i)
    {
        cout << i + 1 << "th Variety details:\n";
        varieties[i].displayVarietyInfoForBrand();
        cout << endl;
    }
    cout << endl;
}

void Brand::addVarietyInExisBrand(Variety &V)
{
    varieties.push_back(V);
}

// Member functions of Item
void Item::displayItemBrands()
{
    cout<<"\n-------------------- AVAILABLE BRANDS --------------------"<<endl;
    cout << "\nTotal number of brands available in " << name << ": " << Brands.size() << endl
         << endl;
    for (int i = 0; i < Brands.size(); ++i)
    {
        cout << i + 1 << "th Brand details:\n";
        Brands[i].displayBrandInfoForItem();
        cout << endl;
    }
    cout << endl;
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
    prod[productID - 1] = (*this);
}

void Product::displayProductItems()
{
    cout<<"\n-------------------- AVAILABLE ITEMS --------------------"<<endl;
    cout << "\nTotal number of items available in " << name << ": " << items.size() << endl
         << endl;
    for (int i = 0; i < items.size(); ++i)
    {
        cout << i + 1 << "th item details:\n";
        items[i].displayItemsForProduct();
        cout << endl;
    }
    cout << endl;
}

void Product::displayProductInfo()
{
    cout << "Name:- " << name << "    ";
    cout << "ProductId:- " << productID;
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

    string MobileNumber;
    while(true){
        cout << "Please enter your mobile number: ";
        cin >> MobileNumber;
        if(MobileNumber.length()==10) break;
        else{
            cout<<"\n! INVALID MOBILE NUMBER !\n";
            cout<<"! PLEASE ENTER A 10 DIGIT MOBILE NUMBER\n\n";
        }
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer

    string Address;
    cout << "Please enter your address: ";
    getline(cin, Address);

    string EmailAddress;
    cout << "Please enter your email address: ";
    getline(cin, EmailAddress);
    return User(NameUser, MobileNumber, Address, EmailAddress, "Null");
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
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
    getline(cin, feed);
    Users[customerID - 1].feedback = feed;
}

// Member functions of Online Shopping Management System
void ShoppingManagementSystem::displayProducts()
{
    cout<<"\n-------------------- PRODUCTS IN OUR PLATFORM --------------------"<<endl;
    cout << "\n\nTotal number of products available in " << name << ": " << prod.size() << endl
         << endl;
    for (int i = 0; i < prod.size(); ++i)
    {
        cout << i + 1 << "th product details:\n";
        prod[i].displayProductInfo();
        cout << endl
             << endl;
    }
    cout << endl;
}

void ShoppingManagementSystem::displayUsersfeedback()
{
    cout<<"\n-------------------- USERS FEEDBACK --------------------"<<endl;
    cout << "\nTotal number of users available in " << name << ": " << Users.size() << endl;
    cout << endl;
    for (int i = 0; i < Users.size(); ++i)
    {
        if (Users[i].feedback != "Null")
        {
            cout << i + 1 << "th user details:\n";
            Users[i].displayUserInfoForOSMSystem();
            cout << endl;
        }
    }
}

// front page to choose what type of user is
void ShoppingManagementSystem::front_page()
{
    cout << endl;
    cout<<"---------------- Login Page ------------------"<<endl;
    cout<<endl;
    cout << "1. Login" << endl;
    cout << "2. SignUp" << endl;
    cout << "3. Quit" << endl;
    cout << "\n\nChoose any one option to start with " << name << ": ";
    int choice;
    cin >> choice;
    cout << endl;

    switch (choice)
    {
    case 1:
        login();
        break;
    case 2:
        signup();
        break;
    case 3:
        cout<<"Quit Done Successfully\n"<<endl;
        exit(0);
    default:
        cout << "INVALID INPUT.OPEN THE PROGRAM AGAIN.\n"
             << endl;
        exit(0);
    }
}

// Definitions of ShoppingManagementSystem member functions
void ShoppingManagementSystem::run()
{
    while (true)
    {
        cout<<"\n-------------------- WELCOME TO EASYBUY SHOPPING PLATFORM --------------------\n";
        cout<<"\n1. Press 1 to display Main Menu\n" ;
        cout<<"2. Press 2 to Log Out \n";
        int choice;
        cout<<"\nPlease enter your choice: ";
        cin>>choice;
        if(choice == 1){
            displayMainMenu();
        }
        else if(choice != 2){
            cout<<"! Invalid Choice Entered !\nTry Again";
        }
        else front_page();
    }

}

void ShoppingManagementSystem::displayMainMenu()
{
    int choice;
    cout << "\n\n-------------------- Main Menu --------------------\n\n";
    cout << "1. View Products\n";
    cout << "2. View Cart\n";
    cout << "3. View User Feedback\n";
    cout << "4. Quit\n\n\n";
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice)
    {

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
        cout << "\nGOOD TIME WITH YOU.SEE YOU SOON!\n"
             << endl;
        exit(0);
    default:
        cout << "Invalid choice, please try again.\n";
    }
}

void ShoppingManagementSystem::login()
{
    int attempts = 0;
    while (attempts < 3)
    {
        cout << "Enter your customer ID: ";
        cin >> login_userID;
        // Validate login_userID
        if (login_userID > 0 && login_userID <= Users.size())
        {
            cout << "\nLogin successful.\n\n";
            Users[login_userID - 1].displayUserInfo();
            return;
        }
        else
        {
            cout << "\nInvalid customer ID. Try again.\n"
                 << endl;
            attempts++;
        }
    }
    cout << "Failed login attempts. Exiting program.\n"
         << endl;
    exit(1);
}

void ShoppingManagementSystem::signup()
{
    User newUser = newUser.takeUserInfo();
    newUser.customerID = User::Users.size(); // Set the customerID as the size of Users array
    cout << "\nSignup successful.\nYour customer ID is: " << newUser.customerID << endl;
    login_userID = newUser.customerID;
}

void ShoppingManagementSystem::browseProducts()
{
    displayProducts();
    handleProductSelection();
}

void ShoppingManagementSystem::handleProductSelection()
{
    int productID;
    cout << "Enter Product ID to view items (or 0 to go back): ";
    cin >> productID;

    if (productID == 0)
        return; // Go back to previous menu
    if (productID < 1 || productID > prod.size())
    {
        cout << "\nInvalid Product ID. Returning to menu.\n"
             << endl;
        return;
    }

    Product selectedProduct = prod[productID - 1];
    selectedProduct.displayProductItems();

    int itemID;
    cout << "Enter Item ID to view brands (or 0 to go back): ";
    cin >> itemID;

    if (itemID == 0)
        return;
    if (itemID < 1 || itemID > selectedProduct.items.size())
    {
        cout << "\nInvalid Item ID. Returning to menu.\n"
             << endl;
        return;
    }

    Item selectedItem = selectedProduct.items[itemID - 1];
    selectedItem.displayItemBrands();

    int brandID;
    cout << "Enter Brand ID to view varieties (or 0 to go back): ";
    cin >> brandID;

    if (brandID == 0)
        return;
    if (brandID < 1 || brandID > selectedItem.Brands.size())
    {
        cout << "\nInvalid Brand ID. Returning to menu.\n"
             << endl;
        return;
    }

    Brand &selectedBrand = selectedItem.Brands[brandID - 1];
    selectedBrand.displayBrandVarieties();

    int varietyID;
    cout << "Enter Variety ID to view details (or 0 to go back): ";
    cin >> varietyID;

    if (varietyID == 0)
        return;
    if (varietyID < 1 || varietyID > selectedBrand.varieties.size())
    {
        cout << "\nInvalid Variety ID. Returning to menu.\n"
             << endl;
        return;
    }

    Variety &selectedVariety = selectedBrand.varieties[varietyID - 1];
    selectedVariety.displayVarietyInfo();

    int user_quantity;
    cout << "Enter quantity to add to cart (or 0 to cancel): ";
    cin >> user_quantity;

    if (user_quantity > 0 && user_quantity <= selectedVariety.quantity)
    {
        addToCart(selectedVariety, selectedBrand, selectedItem, selectedProduct, user_quantity);
    }
    else if (user_quantity > selectedVariety.quantity)
    {
        cout << "\nOrder cancel due to out of stock of quantity." << endl;
        cout << endl;
    }
    else
    {
        cout << "\nCancelled adding to cart.\n";
        cout << endl;
    }
}

// Add a selected item to the cart
void ShoppingManagementSystem::addToCart(Variety &variety, Brand &brand, Item &item, Product &product, int qty)
{
    CartItem cartItem(variety, brand, item, product, qty);
    cart.push_back(cartItem);
    cout << "\nAdded to cart: " << variety.name << " x " << qty << endl
         << endl;
}

void ShoppingManagementSystem::generateBill()
{
    long long bill = 0;
    for (int i = 0; i < cart.size(); i++)
    {
        bill = bill + cart[i].total_price;
    }
    cout << "-----------------BILL-----------------" << endl;
    cout << "\nTotal money to be pay:- " << bill << endl;
    cout << endl;
    cout << "Enter 1 to pay:- ";
    int input;
    cin >> input;
    if (input != 1)
    {
        cout << "\nINVALID INPUT.NO TRANSACTION TAKES PLACE." << endl;
    }
    else
    {
        cout << "\nYOUR ORDER IS PLACED. YOU WILL GET IT SOON." << endl;
        cout<<endl;
        Users[login_userID - 1].giveFeedback();
    }
}

void ShoppingManagementSystem::show_cart()
{
    cout<<"\n--------------------WELCOME TO THE CART--------------------"<<endl;
    cout<<endl;
    if (cart.empty())
    {
        cout << "CART IS EMPTY." << endl;
    }
    else
    {
        for (int i = 0; i < cart.size(); i++)
        {
            cout << "Product " << i + 1 << ":- \n"
                 << endl;
            cart[i].display_cartitem();
            cout << endl;
        }
        cout << endl;
        cart_functionalities();
    }
}

void ShoppingManagementSystem::cart_functionalities()
{
    cout << "Cart functionalities:-\n"
         << endl;
    cout << "1. Make Payment" << endl;
    cout << "2. Add more Products" << endl;
    cout << "3. Remove Products\n"
         << endl;
    int choice;
    cout << "Choose any of the above function:- ";
    cin >> choice;
    cout << endl;
    switch (choice)
    {
    case 1:
        generateBill();
        delete_cart();
        break;
    case 2:
        break;
    case 3:
        remove_product();
        break;
    default:
        cout << "INVALID CHOICE." << endl;
        break;
    }
}

void ShoppingManagementSystem::delete_cart()
{
    cart.clear();
}

void ShoppingManagementSystem::remove_product()
{
    cout << "Enter product number to be remove from the cart:- ";
    int number;
    cin >> number;
    if (number > cart.size() || number < 1)
    {
        cout << "\nInvalid ProductID entered \n";
        return;
    }
    auto pos = cart.begin() + (number - 1);
    cart.erase(pos);
    cout << "\nPRODUCT REMOVED SUCCESSFULLY." << endl;
}