#include <iostream>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<fstream>
#include <stdlib.h>
#include<windows.h>
void creat_product();
void show_product();
void write_product();
void display_all_product();
void modify_product();
void menu();
void admin_menu();
void admin_login();
void intro();

using namespace std;
string adminUsername = "manager@a";
string adminPassword = "admin12";
int isLogged = 0;

/*
  Create Product
*/

    class product
    {
        int pno;
        char name[100];
        float price, qty, tax, dis;
        public:
            void create_product()
            {
            	system ("color F6");
                cout << "Please Enter The Product ID ";
                cin >> pno;
                cout << "Please Enter The Product Name ";
                cin>>gets(name);
                cout << "Please Enter The Product Price ";
                cin >> price;
                cout << "Please Enter The Discount (%) ";
                cin >> dis;
            }

        void show_product()
        {
        	system ("color F6");
            cout << "The Product No. of The Product : " << pno;
            cout << "The Name of The Product : ";
            puts(name);
            cout << "\nThe Price of The Product : " << price;
            cout << "\nDiscount : " << dis;
        }

        int retpno()
        {
            return pno;
        }

        float retprice()
        {
            return price;
        }

        char * retname()
        {
            return name;
        }

        int retdis()
        {
            return dis;
        }

    }; //class ends here
    
	fstream fp;
    product pr;
   
   //write product 
    void write_product()
{
	system ("color F6");
    fp.open("Shop.dat", ios::out | ios::app);
    pr.create_product();
    fp.write((char * ) & pr, sizeof(product));
    fp.close();
    cout << "\n\nThe Product Has Been Created ";
    getch();
}
    // view all products
    void display_all_products()
{
	system ("color F6");
    cout << "\n\n\n\t\tDISPLAY ALL PRODUCTS !!!\n\n";
    fp.open("Shop.dat", ios:: in );
    while (fp.read((char * ) & pr, sizeof(product)))
    {
        pr.show_product();
        cout << "\n\n====================================\n";
        getch();
    }
    fp.close();
    getch();
}

//Update Products

void modify_product()
{
	system ("color F6");
    int no, found = 0;

    cout << "\n\n\tTo Update ";
    cout << "\n\n\tPlease Enter The Product ID";
    cin >> no;
    fp.open("Shop.dat", ios:: in | ios::out);
    while (fp.read((char * ) & pr, sizeof(product)) && found == 0)
    {
        if (pr.retpno() == no)
        {
            pr.show_product();
            cout << "\nPlease Enter The New Details of Product" << endl;
            pr.create_product();
            int pos = -1 * sizeof(pr);
            fp.seekp(pos, ios::cur);
            fp.write((char * ) & pr, sizeof(product));
            cout << "\n\n\t Product Updated";
            found = 1;
        }
    }
    fp.close();
    if (found == 0)
        cout << "\n\n Product Not Found ";
    getch();
}
void menu()
{
	system ("color F6");

    fp.open("Shop.dat", ios:: in );
    if (!fp)
    {
        cout << "ERROR!!! FILE COULD NOT BE OPEN\n\n\n Go To Admin Menu to create File ";

        cout << "\n\n\n Program is closing ....";
        getch();

    }

    cout << "\n\n\t\tNEW UPDATED PRODUCT MENU\n\n";
    cout << "====================================================\n";
    cout << "P.NO.\t\tNAME\t\tPRICE\n";
    cout << "====================================================\n";

    while (fp.read((char * ) & pr, sizeof(product)))
    {
        cout << pr.retpno() << "\t\t" << pr.retname() << "\t\t" << pr.retprice() << endl;
    }
    fp.close();
}

//Place Order
void place_order()
{
    int order_arr[50], quan[50], c = 0;
    float amt, damt, total = 0;
    char ch = 'Y';
    menu();
    cout << "\n============================";
    cout << "\n PLACE YOUR ORDER";
    cout << "\n============================\n";
    do
    {
        cout << "\n\nEnter The Product ID : ";
        cin >> order_arr[c];
        cout << "\nQuantity in number : ";
        cin >> quan[c];
        c++;
        cout << "\nDo You Want To Order Another Product ? (y/n)";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    cout << "\n\nThank You For Placing The Order";
    getch();

    cout << "\n\n******************************** INVOICE ************************\n";
    cout << "\nPr No.\tPr Name\tQuantity \tPrice \tAmount \tAmount after discount\ n ";

    for (int x = 0; x <= c; x++)
    {
        fp.open("Shop.dat", ios:: in );
        fp.read((char * ) & pr, sizeof(product));
        while (!fp.eof())
        {
            if (pr.retpno() == order_arr[x])
            {
                amt = pr.retprice() * quan[x];
                damt = amt - (amt * pr.retdis() / 100);
                cout << "\n" << order_arr[x] << "\t" << pr.retname() <<
                    "\t" << quan[x] << "\t\t" << pr.retprice() << "\t" << amt << "\t\t" << damt;
                total += damt;
            }
            fp.read((char * ) & pr, sizeof(product));
        }

        fp.close();
    }
    cout << "\n\n\t\t\t\t\tTOTAL = " << total;
    getch();
    system("CLS");
}

//intro
void intro()
{
	HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
     cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	 cout<<"\t\t\t\t\t\t\t\t++++++++++++++++++++++++\t\t\t\t\t\t\t\t"<<endl;
	 SetConsoleTextAttribute(h,9);
	 cout<<"\t\t\t\t\t\t\t\t* < SUPRIME FURNITURE > *\t\t\t\t\t\t\t\t"<<endl;
	 cout<<"\t\t\t\t\t\t\t\t_________COLOMBO_________ \t\t\t\t\t\t\t\t"<<endl;
	 cout<<"\n\n\n"; 
	 cout<<"\t\t\t\t\t\t\tWelcome to the Suprime Furinture showroom!!!\t\t\t"<<endl;
	SetConsoleTextAttribute(h,2);
	cout<<"\n\n\n\n\n\n\n\n\n\n\n";
	cout<<"\t\tCreated by - K.S.D.PERERA"<<endl;
     cout<<"\t\t****press any key to continue........";
     getch();
    system("CLS");

}
//Admin menu
void admin_menu()
{

    char ch2;
    cout << "\n\n\n\tADMIN MENU";
    cout << "\n\n\t1.CREATE PRODUCT";
    cout << "\n\n\t2.DISPLAY ALL PRODUCTS";
    cout << "\n\n\t3.UPDATE PRODUCT";
    cout << "\n\n\t4.VIEW UPDATED PRODUCT MENU";
    cout << "\n\n\t5.LOGOUT";
    cout << "\n\n\tPlease Enter Your Choice (1-5) ";
    ch2 = getche();
    system("CLS");
    switch (ch2)
    {
    case '1':
        write_product();
        admin_menu();
        break;
    case '2':
        display_all_products();
        admin_menu();
        break;
    case '3':
        modify_product();
        break;
    case '4':
        menu();
        getch();
    case '5':
        isLogged = 0;
        break;
    default:
        admin_menu();
    }
}
void admin_login()
{
    do{
        string useername, password;
        cout << "\n\tENTER SECURITY DETAILS BELOW\n";
        cout << "\tEnter your USERNAME : ";
        cin >> useername;
        cout << "\tEnter your PASSWORD : ";
        cin >> password;
        if(useername == adminUsername && password == adminPassword){
            isLogged = 1;
            system("CLS");
            admin_menu();
        }else{
            isLogged = 0;
            cout <<"\tYOUR USERNAME OR PASSWORD IS INVALID";
             cout << " ";
        }
    }while(isLogged == 1);
	getch();
	system("CLS");

}
Help()
{
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout<<"Welcome to SUPRIME FURNITURE"<<endl;
	cout<<"\n\n\nplease contact us"<<endl;
	cout<<"\t\t\tTel - 0116598456"<<endl;
	cout<<"\t\t\tEmail - ASP90@gmail.com"<<endl;
	cout<<"\t\t\tAddress - 15/2, aluthkade colombo 06"<<endl;
	getch();
	system("CLS");
	
}
// Home page
int main()
{

    char ch;
    intro();
    system ("color F1");
    do
    {
    	
        cout << "\n\n\n\tMAIN MENU";
        cout << "\n\n\t01. CUSTOMER_SALES_INFO";
        cout << "\n\n\t02. LOGIN";
        cout << "\n\n\t03. HELP";
        cout << "\n\n\t04. EXIT";
        cout << "\n\n\tPlease Select Your Option (1-4) ";
        ch = getche();
        system("CLS");
        switch (ch)
        {
        case '1':
            place_order();
            getch();
            break;	
        case '2':
            if(isLogged == 0){
                admin_login();
            }else{
                admin_menu();
            }

            break;
        case '3':
            Help();
            getch();
            break;
        case '4':
            system("cls");
        default:
            cout << " ";
        }
    } while (ch != '3');
}

