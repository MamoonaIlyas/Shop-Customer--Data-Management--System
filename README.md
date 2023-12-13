The Shop & Customer Management System has been made by using C++ language. The program uses C++ syntax including 1. Structures:Shop: Stores information about items in the shop, including ID, name, category, quantity, whole price, and sale price.Customer: Stores information about customer purchases, including ID, customer name, item name, purchase (buy/not buy), price, and date.2.Array: An array of `Shop` structs (`S`) stores the data for each item. An array of `Customer` structs (`C`) stores the data for each purchase.3.Loops: To add multiplie records.4.File: To store the data on permanent storage.
-> Shop Management Function:
Shop_Record: Menu for adding, displaying, updating, searching, deleting, and adding shop items.
Enter_Data: Add new shop items.
Display_Data: Show all shop items in a table.
Update_Data: Edit existing shop item details.
Search_Data_BY_ID: Find specific item by ID.
Search_Data_BY_Name: Find items by name.
Delete_Data: Remove items (all or by ID).
Add_Data: Add new items without affecting others.
Logout: Return to the main menu.
-> Customer Management Function:
Customer_Record: Menu for managing customer purchases.
ENTER_DATA: Add new customer purchases.
DISPLAY_DATA: Show all customer purchases in a table.
Specifics_Data: Search customer purchases by ID or name.
UPDATE_DATA: Edit existing customer purchase details.
Logout: Return to the main menu.
->HEADER FILES USED:
String manipulation and conversion: <sstream>
User interaction and console operations: <iostream> and <conio.h>
Windows-specific functionality: <windows.h>
File operations: <fstream>
-> RUNNING OF THE PROGRAM:
This output showcases a shop management system in its early stages. Users can log in and choose to manage shop or customer data. The shop menu allows adding, updating, searching, and deleting product information like ID, name, price, and quantity. It even has an intriguing "Enter shopkeeper records" option, possibly for managing staff in the future. The customer menu offers similar functionalities for customer purchase records, including searching by ID or name. While some features seem incomplete and prompts repetitive. 
->USE OF FILES: The file used in the program is the fstream file. It allows to read and write data. The opening mode of the file is (ios::app) append. The use of this opening mode appends the entered data in the text file created in the computer memory.
