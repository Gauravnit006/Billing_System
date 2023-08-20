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

    cout<<"\n\t\t\t Modify the Record";
    cout<<"\n\t\t\t Product code :";
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
                cout<<"\n\t\t Name of the product :";
                cin>>n;
                cout<<"\n\t\t Price: ";
                cin>>p;
                cout<<"\n\t\t Discount :";
                cin>>d;
                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                cout<<"\n\n\t\t Record edited";
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
            cout<<"\n\n Record Not Found Sorry!";
        }
    }
}

// res will delete the product
void shopping::res(){
    fstream data, data1;
    int pkey;
    int token;
    cout<<"\n\n\t Delete Product";
    cout<<"\n\n\t Product code :";
    cin>>pkey;
    data.open("database.txt", ios::in);

    if(!data){
        cout<<"File do not exist";
    }
    else{
        data1.open("database1.txt", ios::app | ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof()){
            if(pcode == pkey){
                cout<<"\n\n\t Product deleted successfully";
                token++;
            }
            else{
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt", "database.txt");

        if(token == 0){
            cout<<"\n\n Record cannot be Found";
        }
    }
}




int main(){

    cout<<"change this code";


    return 0;
}
