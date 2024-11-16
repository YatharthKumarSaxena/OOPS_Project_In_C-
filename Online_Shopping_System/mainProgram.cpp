#include "FunctionsOfOSMS.cpp"
// Main function for testing
int main()
{
    // Creating initial instances
    Variety V1("BAJRA", 1, 200, 2, 4.2, "5kg Mfg Date:- 05/10/2024 .Expiry Date:- Best before 3 months.");
    Variety V2("MAKKA", 2, 200, 3, 4.5, "5Kg. Mfg Date:- 09/11/2024 .Expiry Date:- Best before 2 months from mfg date\n");
    Brand B1("Ashirwaad", 4.3, 1, V1);
    B1.addVarietyInExisBrand(V2);
    Variety V3("MAIDA", 1, 400, 4, 4.4, "10kg Mfg Date:- 05/10/2024 .Expiry Date:- Best before 4 months.");
    Variety V4("WHEAT", 2, 440, 5, 4.5, "10Kg. Mfg Date:- 07/11/2024 .Expiry Date:- Best before 4 months from mfg date\n");
    Brand B2("Shakti Bhog", 4.1, 2, V3);
    B2.addVarietyInExisBrand(V4);
    Item I1("Flour", 1, B1);
    I1.addBrandInExisItem(B2);
    
    Variety V5("Brown Rice", 1, 400, 4, 4.5, "5Kg. Mfg Date:- 11/11/2024. Expiry Date:- Best before 6 months from mfg date\n");
    Variety V6("Dry White Rice", 2, 350, 10, 4.2, "5Kg. Mfg Date:- 08/11/2024 Expiry Date:- Best before 18 months from mfg date\n");
    Brand B3("Baasmati", 4.3, 1, V5);
    B3.addVarietyInExisBrand(V6);
    Variety V7("Black Rice", 1, 300, 3, 4.2, "5Kg. Mfg Date:- 01/10/2024. Expiry Date:- Best before 5 months from mfg date\n");
    Variety V8("Dry White Rice", 2, 250, 5, 4.0, " 5Kg. Mfg Date:- 05/11/2024 Expiry Date:- Best before from 10 months mfg date\n");
    Brand B4("Daawat rozana", 4.1, 2, V7);
    B4.addVarietyInExisBrand(V8);
    Item I2("Rice", 2, B3);
    I2.addBrandInExisItem(B4);
    Product P1("Cereals", 1, I1);
    P1.addItemInExisProduct(I2);
    Variety V9("BRAVIA 2", 1, 27999, 50, 4.7, "43 inches ultra HD smart LED TV");
    Variety V10("BRAVIA 3", 2, 38999, 40, 4.8, " 47 inches 4k ultra HD smart LED Google TV\n");
    Brand B5("SONY", 4.5, 1, V9);
    B5.addVarietyInExisBrand(V10);
    Variety V11("TSH100", 1, 50000, 35, 4.4, "46 inches ultra HD LED TV");
    Variety V12("TLH464", 2, 17999, 37, 4.4, "40 inches HD LED TV\n");
    Brand B6("Panasonic", 4.2, 2, V11);
    B6.addVarietyInExisBrand(V12);
    Item I3("Television", 1, B5);
    I3.addBrandInExisItem(B6);
    Variety V13("Thinkbook", 1, 55000, 50, 4.2, "13 Generation | Intel i5 | 40.64cms | athlon silver | 5020H");
    Variety V14("Ideapad", 2, 69999, 40, 4.4, " 13 Generation | AMD Ryzen 5 | 5500P | 15.6 inches | Thin and light\n");
    Brand B7("Lenovo", 4.4, 1, V13);
    B7.addVarietyInExisBrand(V14);
    Variety V15("Probook", 1, 35000, 40, 4.4, "11 Generation | Core I3 | 1021U | 14 inch | Thin and Light ");
    Variety V16("Elitebook", 2, 75999, 38, 4.4, "13 Generation | Intel i7 | 3021P | 17.2 inches | HD quality\n");
    Brand B8("HP", 4.2, 2, V15);
    B8.addVarietyInExisBrand(V16);
    Item I4("Laptops", 2, B7);
    I4.addBrandInExisItem(B8);
    Product P2("Electronics", 2, I3);
    P2.addItemInExisProduct(I4);
    Variety V17("Xlumia series", 1, 99, 50, 4.2, "Single line | A5 70 ASM sheets | 160 pages");
    Variety V18("Clean up series", 2, 69, 40, 4.3, "single line | A4 size sheets | 124 pages\n");
    Brand B9("Doms", 4.3, 1, V17);
    B9.addVarietyInExisBrand(V18);
    Variety V19("Spiral Notebook | 24 cm x18 cm | single line pages", 1, 120, 35, 4.4, "250 pages");
    Variety V20("pulse Notebook", 2, 199, 37, 4.4, "300 pages | 25 cm x 19.2 cm | excellent white page\n");
    Brand B10("Classmate", 4.5, 2, V19);
    B10.addVarietyInExisBrand(V20);
    Item I5("Notebook", 1, B9);
    I5.addBrandInExisItem(B10);
    Variety V21("Space style box", 1, 550, 50, 4.2, "inbuilt sharpener | Jumbo pencil box | white board");
    Variety V22("Multifunctional box", 2, 599, 35, 4.1, "Jumbo size pencil box\n");
    Brand B11("Toy shine", 4.2, 1, V21);
    B11.addVarietyInExisBrand(V22);
    Variety V23("fairy box", 1, 649, 30, 4.2, "inbuilt sharpener | password system");
    Variety V24("cartoon Box", 2, 349, 20, 4.0, "Small white board with marker | suitcase style\n");
    Brand B12("Fun Blast", 4.0, 2, V23);
    B12.addVarietyInExisBrand(V24);
    Item I6("Pencil Box", 2, B11);
    I6.addBrandInExisItem(B12);
    Product P3("Stationery", 3, I5);
    P3.addItemInExisProduct(I6);
    User U1("Yatharth Kumar Saxena", 7310989810, "Neev karori dham colony , Agra Rd , Aligarh", "yatharthsaxena91@gmail.com", "Great Platform");
    User U2("Navneet Varshney", 9897672310, "Jaigang Sansni Gate , Aligarh", "navneet23@gmail.com", "Nice and user friendly interface");
    User U3("Siddhant Sharma", 9728916542, "Tiger Log , Numaish Road , Aligarh", "siddhant345@hotmail.com", "Good service and products");

    // sms.displayUsers();
    // sms.displayProducts();
    // P1.displayProductItems();
    // I1.displayItemBrands();
    // B1.displayBrandVarieties();
    // V1.displayVarietyInfo();
    ShoppingManagementSystem sms;
            
    sms.front_page();
    
    sms.run();
    
    return 0;
}
