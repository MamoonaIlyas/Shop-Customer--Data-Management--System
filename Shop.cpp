#include <sstream>
#include<iostream>
#include<windows.h>
#include<conio.h>
#include<fstream>
using namespace std;

int total = 0;

struct Shop {
    string Items_name;
    int Whole_Price, Sale_Price, ID;
    string Quantity;
    char Catgory;
};

Shop S[100];

void Shop_Record();

void Enter_Data() {
    int choice;
    cout << "How many items do you want to enter?" << endl;
    cin >> choice;
    fstream new_file;
    new_file.open("Shopkeeper.txt", ios::app);

    if (!new_file) {
        cout << "File creation failed";
    }
    else {
        cout << "New file created ";

        for (int i = total; i < total + choice; i++) {
            cout << "\n\n\t********** Enter Shop Data **********\n\n" << i + 1 << "  ";
            cout << "Enter ID: ";
            cin >> S[i].ID;
            cout << "Enter Items name: ";
            cin >> S[i].Items_name;
            cout << "Enter Catgory: ";
            cin >> S[i].Catgory;
            cout << "Enter Quantity: ";
            cin >> S[i].Quantity;
            cout << "Enter Whole price: ";
            cin >> S[i].Whole_Price;
            cout << "Enter Sale price: ";
            cin >> S[i].Sale_Price;
            new_file << S[i].ID << "\t" << S[i].Items_name << "\t" << S[i].Catgory << "\t" << S[i].Quantity << "\t"
                << S[i].Whole_Price << "\t" << S[i].Sale_Price << endl;
        }
        total += choice;
        new_file.close();
    }
}

void Display_Data() {
    system("CLS");
    system("pause");
    
    if (total != 0) {
        cout << "\n\n\t************ Display Shop Data ************\n\n" << " ";
        cout << "\n\tID" << "\tItems Name" << "\tCatagory" << "\tQuantity" << "\tWhole/Price" << "\tSale/price";

        for (int i = 0; i < total; i++) {
            cout << "\n\t------------------------------------------------------------------------------";
            cout << "\n\t" << S[i].ID << "\t" << S[i].Items_name << "\t\t"
                << S[i].Catgory << "\t\t" << S[i].Quantity << "\t\t"
                << S[i].Whole_Price << "\t\t" << S[i].Sale_Price;
            cout << endl;
        }
    } else {
        cout << "Your record is empty" << endl;
    }
}



void Update_Data() {
    if (total != 0) {
        int ID;
        cout << "Enter ID of data which you want to update: ";
        cin >> ID;

        for (int i = 0; i < total; i++) {
            if (ID == S[i].ID) {
                cout << "\n\n***** Previous Data *****\n\n " << endl;

                cout << "\n\n\t********** Shop Data **********\n\n";
                cout << "ID: " << S[i].ID << endl;
                cout << "Items Name: " << S[i].Items_name << endl;
                cout << "Catagory: " << S[i].Catgory << endl;
                cout << "Quantity: " << S[i].Quantity << endl;
                cout << "Whole price: " << S[i].Whole_Price << endl;
                cout << "Sale price: " << S[i].Sale_Price << endl;

                cout << "\n\n***** Enter New Data *****\n\n " << endl;
                cout << "Enter ID: ";
                cin >> S[i].ID;
                cout << "Enter Items name: ";
                cin >> S[i].Items_name;
                cout << "Enter Catogory: ";
                cin >> S[i].Catgory;
                cout << "Enter Quantity: ";
                cin >> S[i].Quantity;
                cout << "Enter Whole Price: ";
                cin >> S[i].Whole_Price;
                cout << "Enter Sale Price: ";
                cin >> S[i].Sale_Price;

                break;
            }

            if (i == total - 1) {
                cout << "No such record found" << endl;
            }
        }
    }
    else {
        cout << "Your record is empty" << endl;
    }
}

void Search_Data_BY_ID() {
    if (total != 0) {
        int ID;
        cout << "Enter data which you want to search by ID: ";
        cin >> ID;

        for (int i = 0; i < total; i++) {
            if (ID == S[i].ID) {
                cout << "\n\n\t********** Shop Data **********\n\n";
                cout << "ID: " << S[i].ID << endl;
                cout << "Items Name: " << S[i].Items_name << endl;
                cout << "Catagory: " << S[i].Catgory << endl;
                cout << "Quantity: " << S[i].Quantity << endl;
                cout << "Whole price: " << S[i].Whole_Price << endl;
                cout << "Sale price: " << S[i].Sale_Price << endl;

                break;
            }

            if (i == total - 1) {
                cout << "No such record found" << endl;
            }
        }
    }
    else {
        cout << "Your record is empty" << endl;
    }
}

void Search_Data_BY_Name() {
    if (total != 0) {
        string Name;
        cout << "Enter data which you want to search by name: ";
        cin >> Name;

        for (int i = 0; i < total; i++) {
            if (Name == S[i].Items_name) {
                cout << "\n\n\t********** Shop Data **********\n\n";
                cout << "ID: " << S[i].ID << endl;
                cout << "Items Name: " << S[i].Items_name << endl;
                cout << "Catagory: " << S[i].Catgory << endl;
                cout << "Quantity: " << S[i].Quantity << endl;
                cout << "Whole price: " << S[i].Whole_Price << endl;
                cout << "Sale price: " << S[i].Sale_Price << endl;

                break;
            }

            if (i == total - 1) {
                cout << "No such record found" << endl;
            }
        }
    }
    else {
        cout << "Your record is empty" << endl;
    }
}

void Delete_Data() {
    if (total != 0) {
        char user;
        cout << "Press 1. Delete full record" << endl;
        cout << "Press 2. Delete specific record" << endl;
        user = getch();

        if (user == '1') {
            total = 0;
            cout << "All records are deleted" << endl;
        }
        else if (user == '2') {
            int ID;
            cout << "Enter ID of data which you want to delete: ";
            cin >> ID;

            for (int i = 0; i < total; i++) {
                if (ID == S[i].ID) {
                    for (int j = i; j < total; j++) {
                        S[j].ID = S[j + 1].ID;
                        S[j].Items_name = S[j + 1].Items_name;
                        S[j].Catgory = S[j + 1].Catgory;
                        S[j].Quantity = S[j + 1].Quantity;
                        S[j].Whole_Price = S[j + 1].Whole_Price;
                        S[j].Sale_Price = S[j + 1].Sale_Price;
                    }

                    total--;
                    cout << "Your required record is deleted" << endl;
                    break;
                }

                if (i == total - 1) {
                    cout << "No such record found" << endl;
                }
            }
        }
    }
    else {
        cout << "Your record is empty" << endl;
    }
}

void Add_Data() {
	system("CLS");
    int choice;
    cout << "How many items do you want to add?" << endl;
    cin >> choice;
    fstream new_file;
    new_file.open("Shopkeeper.txt", ios::app);

    if (!new_file) {
        cout << "File creation failed";
    }
    else {
        cout << "File opened successfully ";

        for (int i = total; i < total + choice; i++) {
            cout << "\n\n\t********** Add Shop Data **********\n\n" << i + 1 << "  ";
            cout << "Enter ID: ";
            cin >> S[i].ID;
            cout << "Enter Items name: ";
            cin >> S[i].Items_name;
            cout << "Enter Catgory: ";
            cin >> S[i].Catgory;
            cout << "Enter Quantity: ";
            cin >> S[i].Quantity;
            cout << "Enter Whole price: ";
            cin >> S[i].Whole_Price;
            cout << "Enter Sale price: ";
            cin >> S[i].Sale_Price;
            new_file << S[i].ID << "\t" << S[i].Items_name << "\t" << S[i].Catgory << "\t" << S[i].Quantity << "\t"
                << S[i].Whole_Price << "\t" << S[i].Sale_Price << endl;
        }
        total += choice;
        new_file.close();
        cout << "Data added successfully" << endl;
    }
}

void Shop_Record() {
    char choose;
    while (true) {
        system("CLS");
        cout << "\n**************************************************** \n";
        cout << " \t\t\t SHOP MENU \t \n ";
        cout << "**************************************************** \n";
        cout << " Press a. Enter shopkeeper records\n";
        cout << " Press b. Display shopkeeper records\n";
        cout << " Press c. Update shopkeeper records \n";
        cout << " Press d. Search shopkeeper records by ID \n";
        cout << " Press e. Search shopkeeper records by name \n";
        cout << " Press f. Delete shopkeeper records \n";
        cout << " Press g. Add shopkeeper records \n";
        cout << " Press h. Logout \n";
        cin >> choose;
        system("CLS");

        switch (choose) {
        case 'a':
            Enter_Data();  // Call the Enter_Data function
            break;
        case 'b':
            Display_Data();
            system("pause");
            break;
        case 'c':
            Update_Data();
            break;
        case 'd':
            Search_Data_BY_ID();
            system("pause");
            break;
        case 'e':
            Search_Data_BY_Name();
            system("pause");
            break;
        case 'f':
            Delete_Data();
            break;
        case 'g':
            Add_Data();
            break;
        case 'h':
            return;
        default:
            cout << "Invalid input! Please try again." << endl;
            break;
        }
    }
}
	struct Customer
{
	string Items_name,Customer_name;
    int ID,Price;
    string Buy;
    char Date[12];
};
Customer C[100];
int Total=0;
void Customer_Record();

void ENTER_DATA(){
		int choice;
	cout<<" How many Item do you want to enter ??"<<endl;
	cin>>choice;
	fstream new_file;
	new_file.open("Customer .txt",ios::app);
	if(!new_file)
	{
		cout<<"File creation failed";
	}
	else
	{
	cout<<"New file created ";
	for(int k=Total;k<Total+choice;k++){
		cout<<"\n\n\t********** Enter Customer Data **********\n\n"<<k+1<<"  ";
		
		cout<<"Enter ID :"<<endl;
		cin>>C[k].ID;
		cout<<"Enter Customer name :"<<endl;
		cin>>C[k].Customer_name;
	    cout<<"Enter Items nmae :"<<endl;
	    cin>>C[k].Items_name;
	    cout<<"Enter Buy :"<<endl;
	    cin>>C[k].Buy;
	    cout<<"Enter price :"<<endl;
		cin>>C[k].Price;
	    cout<<"Enter Date :"<<endl;
	    cin>>C[k].Date;
	    new_file<<C[k].ID<<"\t"<<C[k].Customer_name<<"\t"<<C[k].Items_name<<"\t"<<C[k].Buy<<
	"\t"<<C[k].Price<<"\t"<<C[k].Date<<endl;
	}
	Total=Total+choice;
	new_file.close();
	}
}
void DISPLAY_DATA() {
    if (Total != 0) {
        cout << "\n\n\t************ Display Customer Data ************\n\n" << " ";

        cout << "\n\tID" << "\tCutomer Name" << "\tItems Name"
            << "\tBuy" << "\t\tPrice" << "\t\tDate";
        for (int k = 0; k < Total; k++) {
            cout << "\n\t------------------------------------------------------------------------------";
            cout << "\n\t" << C[k].ID << "\t" << C[k].Customer_name << "\t\t"
                << C[k].Items_name << "\t\t" << C[k].Buy << "\t\t"
                << C[k].Price << "\t\t" << C[k].Date;
            cout << endl;
        }
    }
    else {
        cout << "Your record is empty" << endl;
    }
}
void Specifics_Data() {
    if (Total != 0) {
        char choice;
        cout << "Press a. Display specific data by ID" << endl;
        cout << "Press b. Display specific data by name" << endl;
        cin >> choice;

        if (choice == 'a') {
            int ID;
            cout << "Enter ID of data which you want to display: ";
            cin >> ID;

            for (int k = 0; k < Total; k++) {
                if (ID == C[k].ID) {
                    cout << "\n\n\t********** Customer Data **********\n\n";
                    cout << "ID: " << C[k].ID << endl;
                    cout << "Customer Name: " << C[k].Customer_name << endl;
                    cout << "Items Name: " << C[k].Items_name << endl;
                    cout << "Buy: " << C[k].Buy << endl;
                    cout << "Price: " << C[k].Price << endl;
                    cout << "Date: " << C[k].Date << endl;

                    break;
                }

                if (k == Total - 1) {
                    cout << "No such record found" << endl;
                }
            }
        }
        else if (choice == 'b') {
            string Name;
            cout << "Enter name of data which you want to display: ";
            cin >> Name;

            for (int k = 0; k < Total; k++) {
                if (Name == C[k].Customer_name) {
                    cout << "\n\n\t********** Customer Data **********\n\n";
                    cout << "ID: " << C[k].ID << endl;
                    cout << "Customer Name: " << C[k].Customer_name << endl;
                    cout << "Items Name: " << C[k].Items_name << endl;
                    cout << "Buy: " << C[k].Buy << endl;
                    cout << "Price: " << C[k].Price << endl;
                    cout << "Date: " << C[k].Date << endl;

                    break;
                }

                if (k == Total - 1) {
                    cout << "No such record found" << endl;
                }
            }
        }
        else {
            cout << "Invalid choice! Please try again." << endl;
        }
    }
    else {
        cout << "Your record is empty" << endl;
    }
}


void UPDATE_DATA(){
	if(Total!=0){
	   int ID;
	   cout<<" Enter ID of data which you want to update "<<endl;
	   cin>>ID;
	   for(int k=0;k<Total;k++){
	   	    if(ID==C[k].ID){
	   	    	cout<<" \n\n***** Previous Data *****\n\n "<<endl;
	   	    	
	   	    	cout<<"\n\n\t********** Customer Data **********\n\n";
			    
			    cout<<" ID : "<<C[k].ID<<endl;
			    cout<<" Customer Name : "<<C[k].Customer_name<<endl;
		    	cout<<" Items Name : "<<C[k].Items_name<<endl;
			    cout<<" Buy : "<<C[k].Buy<<endl;
			    cout<<" Price : "<<C[k].Price<<endl;
			    cout<<" Date : "<<C[k].Date<<endl;
			    
			    cout<<" \n\n***** Enter New Data *****\n\n "<<endl;
			    
		        cout<<"Enter ID :"<<endl;
	            cin>>C[k].ID;
		        cout<<"Enter Customer name :"<<endl;
		        cin>>C[k].Customer_name;
	            cout<<"Enter Items nmae :"<<endl;
	            cin>>C[k].Items_name;
	            cout<<"Enter Buy :"<<endl;
	            cin>>C[k].Buy;
	            cout<<"Enter price :"<<endl;
		        cin>>C[k].Price;
	            cout<<"Enter Date :"<<endl;
	            cin>>C[k].Date;
            break;
			   }
			   if(k==Total-1){
			   	cout<<" No such record found "<<endl;
			   }
		}
	}
	else{
		cout<<" Your record is empty "<<endl;
	}	

}
void SEARCH_DATA_BY_ID() {
    if (Total != 0) {
        int ID;
        cout << "Enter ID which you want to search: ";
        cin >> ID;

        for (int k = 0; k < Total; k++) {
            if (ID == C[k].ID) {
                cout << "\n\n\t********** Customer Data **********\n\n";
                cout << "ID : " << C[k].ID << endl;
                cout << "Customer Name : " << C[k].Customer_name << endl;
                cout << "Items Name : " << C[k].Items_name << endl;
                cout << "Buy : " << C[k].Buy << endl;
                cout << "Price : " << C[k].Price << endl;
                cout << "Date : " << C[k].Date << endl;
                return;
            }
        }

        cout << "No such record found" << endl;
    } else {
        cout << "Your record is empty" << endl;
    }
}

void SEARCH_DATA_BY_NAME() {
    if (Total != 0) {
        string Name;
        cout << "Enter name which you want to search: ";
        cin.ignore();  // Clear the buffer before reading the name
        getline(cin, Name);

        for (int k = 0; k < Total; k++) {

            if (Name == C[k].Customer_name) {
                cout << "\n\n\t********** Customer Data **********\n\n";
                cout << "ID : " << C[k].ID << endl;
                cout << "Customer Name : " << C[k].Customer_name << endl;
                cout << "Items Name : " << C[k].Items_name << endl;
                cout << "Buy : " << C[k].Buy << endl;
                cout << "Price : " << C[k].Price << endl;
                cout << "Date : " << C[k].Date << endl;
                return;
            }
        }

        cout << "No such record found" << endl;
    } else {
        cout << "Your record is empty" << endl;
    }
}


void DELETE_DATA(){
	if(Total!=0){
		char user;
		cout<<" Press 1. Delete full record "<<endl;
		cout<<" Press 2. Delete specific record "<<endl;
		user= getch();
		if(user=='1'){
			Total=0;
			cout<<" All record is deleted . . . ! ! ! "<<endl;
	
		}
		else if(user=='2'){
			int ID;
	        cout<<" Enter ID of data which you want to delete "<<endl;
	        cin>>ID;
	        for(int k=0;k<Total;k++){
	        	if(ID==C[k].ID){
	        		for(int m=k;m<Total;m++){
	        		C[m].ID=C[m+1].ID;	
	        	    C[m].Customer_name=C[m+1].Customer_name;
					C[m].Items_name=C[m+1].Items_name;
					C[m].Buy=C[m+1].Buy;
					C[m].Price=C[m+1].Price;
					
					Total--;
					cout<<" Your required record is deleted "<<endl;
					break;
			    	}
			     if(k=Total-1){
			    	cout<<" No such record found "<<endl;
				  }
				
			    }
			}
		}			
   }
   else{
		cout<<" Your record is empty "<<endl;
	}
}

void ADD_DATA() {
    int choice;
    cout << "How many items do you want to add?" << endl;
    cin >> choice;
    fstream new_file;
    new_file.open("Customer.txt", ios::app);

    if (!new_file) {
        cout << "File creation failed";
    }
    else {
        cout << "File opened successfully ";

        for (int k = Total; k < Total + choice; k++) {
            cout << "\n\n\t********** Add Customer Data **********\n\n" << k + 1 << "  ";

            cout << "Enter ID :" << endl;
            cin >> C[k].ID;
            cout << "Enter Customer name :" << endl;
            cin >> C[k].Customer_name;
            cout << "Enter Items name :" << endl;
            cin >> C[k].Items_name;
            cout << "Enter Buy :" << endl;
            cin >> C[k].Buy;
            cout << "Enter price :" << endl;
            cin >> C[k].Price;
            cout << "Enter Date :" << endl;
            cin >> C[k].Date;
            new_file << C[k].ID << "\t" << C[k].Customer_name << "\t" << C[k].Items_name << "\t" << C[k].Buy <<
                "\t" << C[k].Price << "\t" << C[k].Date << endl;
        }
        Total = Total + choice;
        new_file.close();
        cout << "Data added successfully" << endl;
    }
}
void Customer_Record(){

	system("pause");
	  system("CLS");
	  char user;
	  while(10){
	  	system("CLS");
	  	cout<<endl<<endl;
	  	cout<<"\n**************************************************** \n";
        cout<<" \t\t\t CUSTOMER MENU \t \n ";
        cout<<"**************************************************** \n";
           cout<<" Press k. Enter Customer records\n";
           cout<<" Press l. Display Customer records\n";
           cout<<" Press m. Specific Customer records \n";
           cout<<" Press n. Update Customer records \n";
           cout<<" Press o. Search Customer records by ID \n";
           cout<<" Press p. Search Customer records by name \n";
           cout<<" Press q. Delete Customer records \n";
           cout<<" Press r. Add Customer records \n";
           cout<<" Press s. Logout \n";
        
	    user= getch();
        system("CLS");
         switch(user){
            
         	system("CLS");
         		case 'k':
         		ENTER_DATA();
         		system("CLS");
         		break;
            case 'l':
            DISPLAY_DATA();  // Call the display function after handling customer records
            system("pause");  // Add a pause here to see the output
         		break;
		   	case 'm':
         		Specifics_Data();
                system("pause");
         		break;
         	case 'n':
			    UPDATE_DATA();
				break;	
			case 'o':
         		SEARCH_DATA_BY_ID();
                system("pause");
         		break;
         	case 'p':
         		SEARCH_DATA_BY_NAME();
                system("pause");
         		break;
			case 'q':
         		DELETE_DATA();
         		system("CLS");
         		break;
            case 'r':
            	ADD_DATA();
            	system("CLS");
            	break;
                 case 's':
            return;
        default:
            cout << "Invalid input! Please try again." << endl;
            break;
	  }
    }
}
int main()
{
	system("pause");
system("cls");
		cout<<"\n\n\t\t********** SHOPKEPPER MANAGEMENT SYSTEM **********\n\n "<<endl;
	cout<<"\n\n\t\t Sign Up "<<endl;
	string username,password;
	cout<<"\n\t\t Enter username : ";
	cin>>username;
	cout<<"\n\t\t Enter password : ";
	cin>>password;
	cout<<"\n\t\t Your id is creating please wait ";
	for(int i=0;i<4;i++)
	{
		cout<<" . ";
		Sleep(1000);
	}
	cout<<"\n\t\t Your id created successfully "<<endl;
	system("CLS");
	start:
		system("CLS");
	cout<<"\n\n\t\t********** SHOPKEPPER MANAGEMENT SYSTEM **********\n\n "<<endl;
	cout<<"\n\n\t\t Login "<<endl;
	string username1,password1;
	cout<<" \t\t Username : ";
	cin>>username1;
	cout<<" \t\t Password : ";
	cin>>password1;
	if(username1==username&&password1==password){
		
		system("pause");
	  system("CLS");
	  char user;
	  while(10){
	  	system("CLS");
	  	cout<<endl<<endl;
	  	  cout<<"\n**************************************************** \n";
          cout<<" \t\t\t MAIN MENU \t \n ";
          cout<<"**************************************************** \n";
           cout<<" Press 1. Enter shop records\n";
           cout<<" Press 2. Enter Customer records\n";
           cout<<" Press 3. Logout \n";
           cout<<" Press 4. Exit  \n";
           
	    user= getch();
        system("CLS");
         switch(user){
         	case '1':
         		Shop_Record();
         		system("CLS");
         		break;
         	case '2':
         		Customer_Record();
            system("CLS");
         		break; 
            case '3':
         		goto start;
         		break;
         		
			default:
			    cout<<"\a  Invalid Input "<<endl;
				break;	
		 }
	  }
	    
	}
	else if(username1!=username){
		cout<<" Your username is incorrect "<<endl;
		Sleep(3000);
		goto start;
	}
	else if(password1!=password){
		cout<<" Your password is incorrect "<<endl;
		Sleep(3000);
		goto start;
	}
	
	return 0;
}
