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

int main(){

    cout<<"change this code";


    return 0;
}
