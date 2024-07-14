# Grocery Management System

This is a simple console-based Grocery Management System implemented in C++. The system allows users to manage a list of grocery items by performing various operations such as adding, displaying, removing, and updating items.

## Features

- **Add Item:** Add a new grocery item with a specified name, price, and quantity.
- **Display List:** Display the list of all grocery items.
- **Remove Item:** Remove a grocery item from the list by its name.
- **Update Item:** Update the details (price and quantity) of an existing grocery item.

## Getting Started

### Prerequisites

- A C++ compiler (e.g., `g++`)

### Compilation

To compile the program, run the following command in your terminal:

    g++ -o grocery_management main.cpp

### Running the Program

After compiling, you can run the executable:

    ./grocery_management

## Usage

Upon running the program, you will be presented with a menu to choose from various options:

1. **Add Item:** Prompts for the item name, price, and quantity to add to the grocery list.
2. **Display List:** Displays all the items currently in the grocery list.
3. **Remove Item:** Prompts for the item name to remove from the list.
4. **Update Item:** Prompts for the item name and new details (price and quantity) to update the item in the list.
5. **Exit:** Exits the program.

## Example

Here is an example interaction with the system:

    Grocery Management System
    1. Add Item
    2. Display List
    3. Remove Item
    4. Update Item
    5. Exit
    Enter your choice: 1
    Enter item name: Apple
    Enter item price: 1.5
    Enter item quantity: 10

    Grocery Management System
    1. Add Item
    2. Display List
    3. Remove Item
    4. Update Item
    5. Exit
    Enter your choice: 2
    Grocery List:
    Item: Apple, Price: 1.5, Quantity: 10

## Contributing

Contributions are welcome! Feel free to submit a pull request or open an issue to discuss improvements or bugs.
