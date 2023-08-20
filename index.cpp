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
    cout<<"\n\t\t\t  Please enter Choice (Select 1 or 2 or 3) : ";
    cin>>choice;

    switch (choice)
    {
    case 1:
        cout<<"\t\t\t Please Login \n";
        cout<<"\t\t\t Enter Email : ";
        cin>>email;
        cout<<"\t\t\t Enter Password : ";
        cin>>password;
        if(email == "admin123@gmail.com" && password == "admin@123"){
            administrator();
        }
        // administrator();
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
        cout<<"Invalid choice\n";
    goto m;
    }

}


// this function is used by administrator to add modify and delete the product
void shopping :: administrator(){
    m:
    int choice;
    cout<<"\n\n\n\n\t\t\t____1. Add the product______|";
          cout<<"\n\t\t\t                            |";
    cout<<"\n\t\t\t____2. Modify the product___|";
          cout<<"\n\t\t\t                            |";
    cout<<"\n\t\t\t____3. Delete the product___|";
          cout<<"\n\t\t\t                            |";
    cout<<"\n\t\t\t____4. Back the product_____|";
          cout<<"\n\t\t\t                            |";

    cout<<"\n\n\t  Please enter Choice (Select 1 or 2 or 3 or 4) : ";
    cin>>choice;

    switch(choice){
        case 1:
            add();
            break;
        case 2:
            edit();
            break;
        case 3:
            res();   // Remove function
            break;
        case 4:
            menu();
            break;
        default:
            cout<<"Invalid choice\n";
    }
    goto m;
}

void shopping :: buyer(){
    m:
    int choice;
    cout<<"\t\t\t\t   Buyer        \n";
    cout<<"\t\t\t\t________________\n";
    cout<<"\t\t\t\t1. Buy product  \n";
    cout<<"\t\t\t\t                \n";
    cout<<"\t\t\t\t2. Go back      \n";

    cout<<"\t\t\t  Please enter Choice (Select 1 or 2) : ";
    cin>>choice;

    switch(choice){
        case 1:
            receipt();
            break;
        case 2:
            menu();
        default:
            cout<<"Invalid choice\n";
    }
    goto m;
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
    cout<<"\n\n\t Product code of the Product: ";
    cin>>pcode;
    cout<<"\n\n\t Name of the product: ";
    cin>>pname;
    cout<<"\n\n\t Price of the product: ";
    cin>>price;
    cout<<"\n\n\t Discount on product: ";
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

    cout<<"\n\n\t\t Record Inserted !\n";

}



// edit will edit the products
void shopping ::edit()
{
    fstream data, data1;
    int pkey;
    int token = 0;
    int c;
    float p;
    float d;
    string n;

    cout<<"\n\t\t\t Modify the Record ";
    cout<<"\n\t\t\t Product code : ";
    cin>>pkey;

    data.open("database.txt", ios::in);
    if(!data){
        cout<<"\n\nFile Dosen't Exist";
    }
    else{
        data1.open("database1.txt", ios::app  | ios::out);

        data>>pcode>>pname>>price>>dis;
        while(!data.eof()){
            if(pkey == pcode){
                cout<<"\n\t\t Product new code : ";
                cin>>c;
                cout<<"\n\t\t Name of the product : ";
                cin>>n;
                cout<<"\n\t\t Price : ";
                cin>>p;
                cout<<"\n\t\t Discount : ";
                cin>>d;
                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                cout<<"\n\n\t\t Record edited\n";
                token++;

            }
            else
            {
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();

        // changing database.txt to database1.txt
        remove("database.txt");
        rename("database1.txt", "database.txt");

        if(token == 0){
            cout<<"\n\n Record Not Found Sorry!\n";
        }
    }
}

// res will delete the product
void shopping::res(){
    fstream data, data1;
    int pkey;
    int token;
    cout<<"\n\n\t Delete Product : ";
    cout<<"\n\n\t Product code : ";
    cin>>pkey;
    data.open("database.txt", ios::in);

    if(!data){
        cout<<"File do not exist!\n";
    }
    else{
        data1.open("database1.txt", ios::app | ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof()){
            if(pcode == pkey){
                cout<<"\n\n\t Product deleted successfully. \n";
                token++;
            }
            else{
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt", "database.txt");

        if(token == 0){
            cout<<"\n\n Record cannot be Found.\n";
        }
    }
}

// it will print the list of products
void shopping::list(){
    fstream data;
    data.open("database.txt", ios::in);
    cout<<"\n\n___________________________________________________\n";
    cout<<"ProductNo\t\tName\t\tPrice\n";
    cout<<"\n\n___________________________________________________\n";
    data>>pcode>>pname>>price>>dis;
    while(!data.eof()){
        cout<<pcode<<"\t\t"<<setw(10)<<pname<<"\t"<<setw(10)<<price<<"\n";
        data>>pcode>>pname>>price>>dis;
    }
    data.close();    
}


void shopping :: receipt(){
    fstream data;
    int arrc[100];   // array of product code
    int arrq[100];   // array of quantity
    char choice;
    int c=0;   // counter
    float amount = 0;
    float dis = 0;   // discount
    float total = 0;

    cout<<"\n\n\t\t\t RECEIPT";
    data.open("database.txt", ios::in);
    if(!data){
        cout<<"\n\n Empty database";
    }
    else{
        data.close();

        list();
        cout<<"\n__________________________________\n";
        cout<<"\n                                  \n";
        cout<<"\n     Please place the order       \n";
        cout<<"\n                                  \n";
        cout<<"\n__________________________________\n";
        
        do{
            m:
            cout<<"\n\nEnter the product code : ";
            cin>>arrc[c];
            cout<<"\n\nEnter the product quantity : ";
            cin>>arrq[c];
            for(int i=0; i<c; ++i){
                if(arrc[c] == arrc[i]){
                    cout<<"\n\n Product code is duplicate. Please try again!!  ";
                    goto m;
                }
            }
            c++;
            cout<<"\n\n Do you want to buy another product? If yes then press y else n : ";
            cin>>choice;
        }while(choice == 'y');
        
        cout<<"\n\n\t\t\t____________RECIPT____________\n";
        cout<<"\nProduct No.\tProduct Name\t Product quantity\tPrice\t  Amount\tAmount with discount\n";
        for(int i=0; i<c; ++i){
            data.open("database.txt", ios::in);
            data>>pcode>>pname>>price>>dis;
            while(!data.eof()){
                if(pcode == arrc[i]){
                    amount = price*arrq[i];
                    dis = amount - (amount*dis/100);
                    total += dis;
                    cout<<"\n"<<setw(3)<<pcode<<"\t\t"<<setw(10)<<pname<<"\t"<<setw(3)<<arrq[i]<<"\t\t"<<setw(13)<<price<<" "<<setw(10)<<amount<<"\t"<<setw(7)<<dis;
                    // cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t\t"<<price<<"\t"<<amount<<"\t\t"<<dis;
                }
                data>>pcode>>pname>>price>>dis;
            }
            data.close();
        }

        cout<<"\n\n_________________________________";
        cout<<"\n Total Amount : "<<total<<endl;
    }
}



int main(){

    // cout<<"change this code";
    shopping s;
    s.menu();


    return 0;
}
