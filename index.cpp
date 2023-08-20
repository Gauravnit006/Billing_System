#include<bits/stdc++.h>
using namespace std;

class shopping{
    int pcode;
    float price;
    float dis;
    string pname;
public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void res();
    void list();
    void receipt();

};


void shopping :: menu(){
    m:
    int choice;
    // email and password is used for login purpose
    string email;
    string password;
    cout<<"\t\t\t\t\t___________________________________\n";
    cout<<"\t\t\t\t\t                                   \n";
    cout<<"\t\t\t\t\t       Supermarket Main Menu       \n";
    cout<<"\t\t\t\t\t                                   \n";
    cout<<"\t\t\t\t\t___________________________________\n";
    cout<<"\t\t\t\t\t                                   \n";

    cout<<"\t\t\t\t\t|  1. Administrator   |\n";
    cout<<"\t\t\t\t\t|                     |\n";
    cout<<"\t\t\t\t\t|  2. Buyer           |\n";
    cout<<"\t\t\t\t\t|                     |\n";
    cout<<"\t\t\t\t\t|  3. Exit            |\n";
    cout<<"\t\t\t\t\t|                     |\n";
    cout<<"\n\t\t\t  Please Select (Select 1 or 2 or 3)";
    cin>>choice;

    switch (choice)
    {
    case 1:
        cout<<"\t\t\t Please Login \n";
        cout<<"\t\t\t Enter Email  \n";
        cin>>email;
        cout<<"\t\t\t Enter Password  \n";
        cin>>password;
        if(email == "admin123@gmail.com" && password == "admin@123"){
            administrator();
        }
        cout<<"Invalid email or password !!";
        break;
    case 2:
        {
            buyer();
        }
    case 3:
        {
            exit(0);
        }
    default:
        cout<<"Please enter valid choice (1 or 2 or 3)";
        // break;
    goto m;
    }

}

int main(){

    cout<<"change this code";


    return 0;
}
