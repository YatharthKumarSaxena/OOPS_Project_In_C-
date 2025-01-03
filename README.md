# 🛒 Welcome to the Online Shopping Management System Project!
> **I'm the README.md file of this project folder, here to guide you step-by-step!** 🚀

## 📑 Table of Contents
- [📖 Introduction](#-introduction)
- [📂 Folder Structure](#-folder-structure)
- [📜 Features](#-features)
- [🔍 Concept Highlights](#-concept-highlights)
- [⚙️ How It Works](#-how-it-works)
- [📈 Use Case and Practical Application](#-use-case-and-practical-application)
- [👥 Team Contributions](#-team-contributions)
- [🛠️ Setup and Usage](#-setup-and-usage)
- [🎯 Final Takeaway](#-final-takeaway)

---

## 📖 **Introduction**
The **Online Shopping Management System (OSMS)** is a modular C++ program designed to simulate the operations of an online shopping platform. It showcases a hierarchical structure of products, seamless user interaction, and dynamic inventory management, replicating the features of real-world e-commerce systems.

This project provides a deep dive into the following aspects:
- Managing products and their associated details like brands, varieties, and prices.
- Capturing user feedback for enhancing product offerings.
- Demonstrating the power of **object-oriented programming (OOP)** with multi-file modularity.

---

## 📂 **Folder Structure**
The project consists of **4 files**, each playing a vital role in the system's functionality:

1. 📄 **class.cpp**
    - **Purpose**: Contains class declarations and function prototypes.
    - **Highlights**:
        - Defines classes like `Variety`, `Brand`, `Item`, `Product`, `User`, and `OnlineShoppingManagementSystem`.
        - Includes data members, constructors, and member function declarations.

2. 📄 **FunctionsOfOSMS.cpp**
    - **Purpose**: Implements the member functions declared in `class.cpp`.
    - **Highlights**:
        - Uses the scope resolution operator (`::`) to define class functions.
        - Manages product interactions, user feedback, and inventory updates.

3. 📄 **MainProgram.cpp**
    - **Purpose**: Serves as the program's entry point, orchestrating its workflow.
    - **Highlights**:
        - Initializes objects for products, brands, and users.
        - Connects functionalities via the `OnlineShoppingManagementSystem` class.
        - Simulates operations of an online shopping platform.

4. 📄 **README.md**
    - **Purpose**: Comprehensive project documentation for developers and users.
    - **Highlights**: Detailed explanation of the project's structure, setup, and use.

---

## 📜 **Features**
1. **Detailed Product Categorization**:
    - Hierarchical structure: `Product` → `Item` → `Brand` → `Variety`.
    - Captures detailed information about price, availability, and ratings.

2. **User Feedback Management**:
    - Records user feedback with name, contact, and suggestions.
    - Displays feedback to understand user preferences.

3. **Interactive Interface**:
    - Intuitive prompts guide users through browsing and feedback collection.

4. **Extensibility**:
    - Supports easy addition of new products, categories, and features.
    - Modular design enhances scalability.

5. **Multi-File Programming**:
    - Promotes clean code separation across files for better maintenance.

---

## 🔍 **Concept Highlights**
This project incorporates the following core programming concepts:

1. **Object-Oriented Programming**:
    - Encapsulation of data in classes and objects.
    - Real-world modeling of online shopping systems.

2. **Modular Design**:
    - Class declarations, function definitions, and main program logic are separated.
    - Enables maintainable and reusable code.

3. **Dynamic Object Initialization**:
    - Objects created dynamically simulate inventory and user data.

4. **Interactive Programming**:
    - User-friendly interface for exploring products and submitting feedback.

---

## ⚙️ **How It Works**
### Step-by-Step Workflow:
1. **Class Declaration (`class.cpp`)**:
    - Defines the blueprint for products, brands, and users.
2. **Function Implementation (`FunctionsOfOSMS.cpp`)**:
    - Implements logic for product interactions and user feedback.
3. **Main Execution (`MainProgram.cpp`)**:
    - Creates objects, initializes the system, and triggers user interaction.

---

## 📈 **Use Case and Practical Application**
- **E-Commerce Platforms**: Demonstrates the workings of platforms like Flipkart or Amazon.
- **Inventory Management**: Provides insights into how online retailers manage products.
- **Educational Value**: Serves as a learning tool for OOP and modular design in C++.

---

## 👥 **Team Contributions**
This project was developed by a dedicated team of three members. Here's a breakdown of their contributions:

| **Yatharth Kumar Saxena** |
- Proposed the concept of multi-level inheritance for categories like brand, item, and variety.
- Defined `User` class and `OnlineShoppingManagementSystem` class, including their member function declarations.
- Implemented multi-file programming and wrote all member functions for brands, items, and products.
- Added member function definitions for `User` class and defined components in OSMS.
- Designed and implemented the logical structure for product categorization.

| **Siddhant Sharma** |
- Defined all member functions of the `OnlineShoppingManagementSystem` class.
- Implemented the cart system from scratch and ensured seamless integration of project components.
- Responsible for ensuring that all components worked as a unified system.

| **Navneet Varshney** |
- Focused on data initialization using parameterized constructors.
- Ensured pre-loaded data in objects for smoother user interaction.
- Monitored and tested the main program functionality.
                                           |

---

## 🛠️ **Setup and Usage**
1. **Prerequisites**:
    - A C++ compiler like GCC, Clang, or MSVC.
    - Basic knowledge of OOP principles.

2. **Compilation and Execution**:
    - Navigate to the project directory.
    - Compile the files:
      ```bash  
      g++ -o OnlineShoppingManagementSystem MainProgram.cpp FunctionsOfOSMS.cpp class.cpp  
      ```  
    - Run the `MainProgram.cpp` file to execute the program:
      ```bash  
      ./OnlineShoppingManagementSystem  
      ```  

3. **Expected Behavior**:
    - Program starts with a user-friendly interface.
    - Users can browse products, explore categories, and leave feedback.

---

## 🎯 **Final Takeaway**
The **Online Shopping Management System (OSMS)** demonstrates the seamless integration of modular design and object-oriented principles. It bridges the gap between conceptual programming and real-world applications, providing a strong foundation for aspiring developers.

This project highlights the importance of clean, maintainable code and modular architecture in building scalable systems. Explore its design to enrich your learning journey!

---

** Work Done By Each Member in Detail **

1.) Navneet:- Adding Data to the program :- 24 Variety, 12 Brands , 6 Items and 3 Product, Adding Data of existing 3 users, testing the program at every stage like infinite loop problem identification , static member initialisation, display of program to the user like spelling error , indentation, tab space,  involved in raw design idea making,removing unnecessary member function, built in STL files, data members, finding the solution of critical problems like static keyword initialisation and how to remove this problem , logic error identification like total price will  be calculated in long long not double , where to use user feedback and what feedback to show to user and making final report. 


2.) Siddhant :- Responsible for making all the functionalities of Shopping management system class, how does a shopping management system will act as user interface , improved key features like login and sign up to be separated from view product, view user feedback etc . Fixed Major Errors in the program like display of only one item,  rather than 2 , handling cart member function functionalities and cart class that work independently without inheritance , use of auto keyword to handle remove product from ekart , and linking cart , product and user class in sms functionalities.


3.) Yatharth:- Responsible for every design or raw design in this project , all the idea of how does classss interacts with each other , which class show multiple inheritance, multilevel inheritance, single inheritance etc. Where to use static keyboard ,use of getline function of string, how to deal with input buffer , use of this pointer , made product, item, brand , variety , sms , user and their member function definition , making use of vector STL file in order to store item in products , brands in items etc. responsible for how the structure of project looks like in three different files and how these three files interact with each other.

---