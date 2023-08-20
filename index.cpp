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

// add function will add product and it details 
void shopping ::add(){
    m:
    fstream data;
    int c;
    int token = 0;
    float p;
    float d;
    string n;

    cout<<"\n\n\t\t\t Add new Product";
    cout<<"\n\n\t Product code of the Product ";
    cin>>pcode;
    cout<<"\n\n\t Name of the product";
    cin>>pname;
    cout<<"\n\n\t Price of the product";
    cin>>price;
    cout<<"\n\n\t Discount on product";
    cin>>dis;

    data.open("database.txt", ios::in);  //ios::in use to open file in reading

    if(!data){
        data.open("database.txt", ios::app|ios::out);  //ios app for opening file in append mode and ios out for open file in writing mode
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";  // writing in file
        data.close();  // close the file
    }
    else{
        data>>c>>n>>p>>d;   //reading from the file

        while(!data.eof()){  //eof end of file
            if(c == pcode){
                token++;  //token will increase if product is more than 1
            }
            data>>c>>n>>p>>d;
        }
        data.close();
    

        if(token == 1){
            goto m;
        }
        else{
            data.open("database.txt", ios::app|ios::out);  //ios app for opening file in append mode and ios out for open file in writing mode
            data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";  // writing in file
            data.close();  // close the file
        }
    }

    cout<<"\n\n\t\t Record Inserted !";

}

void shopping ::edit()
{
    fstream data, data1;
    int pkey;
    int token = 0;
    int c;
    float p;
    float d;
    string n;

    cout<<"\n\t\t\t Modify the Record";
    cout<<"\n\t\t\t Product code :";
    cin>>pkey;
}

int main(){

    cout<<"change this code";


    return 0;
}
