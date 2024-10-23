#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <bits/stdc++.h>
using namespace std;
class customer
{
    private:
        string cust_id;
        string pass;
        string mobile;
        void pass_change();
        void mobile_change();
    public:
        customer();
        customer(string v);
        string getid();
        void display_details();
        void change_details();
        void set_customer();
        void writefile();
};
class employee{
    private:
        string emp_id;
        string pass;
        string mobile;
        double salary;
        int permission;
        void pass_change();
        void mobile_change();
    public:
        employee();
        employee(string v);
        void display_details();
        void change_details();
        void set_emp();
        void writefile();
        int get_p();
        void change_p();
        string getid();
};
class inventory{
    private:
        string i_id;
        string name;
        string details;
        string link;
        string price;
    public:
        inventory();
        inventory(string v);
        void set_inventory();
        void display();
        void change_details();
        void writefile();
        string getid();
        string getname();
        friend void bill(string s);
};
inventory::inventory()
{
    ;
}
inventory::inventory(string v)
{
        string i_id1;
        string name1;
        string details1;
        string link1;
        string price1;
    ifstream in;
    in.open("inventory_stock");
    while(!in.eof())
    {
        getline(in,i_id1);
        getline(in,name1);
        getline(in,details1);
        getline(in,link1);
        getline(in,price1);
        if(i_id1==v)
        {
            i_id=i_id1;
           name=name1;
           details=details1;
           link=link1;
           price=price1;
           break;
        }
    }
    in.close();
}
void inventory::set_inventory()
{
    inventory *t=this;
    int j;
    ifstream in;
    in.open("inventory");
    in>>j;
    in.close();
    in.open("inventory_stock");
    for(int i=0;i<j;i++,t++)
    {
        getline(in,t->i_id);
        getline(in,t->name);
        getline(in,t->details);
        getline(in,t->link);
        getline(in,t->price);
    }
    in.close();
}
void inventory::display()
{
    cout<<"id:"<<i_id<<endl;
    cout<<"Name:"<<name<<endl;
    cout<<"Details:"<<details<<endl;
    cout<<"Price:"<<price<<endl;
    cout<<"More Details-"<<link<<endl;
}
void inventory::change_details()
{
    int j;
    ifstream in;
    in.open("inventory");
    in>>j;
    in.close();
    inventory c1[j];
    c1[0].set_inventory();
    for(int i=0;i<j;i++)
    {
        if(i_id==c1[i].getid())
        {   j=i;break;}
    }
    cout<<"Enter 1 for changing name\n"<<"Enter 2 for changing details\n"<<"Enter 3 for changing link\n"<<"Enter 4 for changing price\n"<<endl;
    int o;
    cin>>o;
    switch(o)
    {
        case 1:
            cout<<"Enter new name:"<<endl;
            while(getchar()!='\n');
            getline(cin,c1[j].name);
            break;
        case 2:
            cout<<"Enter new details:"<<endl;
             while(getchar()!='\n');
            getline(cin,c1[j].details);
            break;
        case 3:
            cout<<"Enter new link:"<<endl;
             while(getchar()!='\n');
            getline(cin,c1[j].link);
            break;
        case 4:
            cout<<"Enter new price:"<<endl;
             while(getchar()!='\n');
            getline(cin,c1[j].price);
            break;
        default:
            cout<<"incorrect option number"<<endl;
    }
    c1[0].writefile();
}
string inventory::getid()
{
    return i_id;
}
void inventory::writefile()
{
    inventory *t=this;
    int j;
    ifstream in;
    in.open("inventory");
    in>>j;
    in.close();
    ofstream w;
    w.open("inventory_stock");
    for(int i=0;i<j;i++,t++)
    {
        if(!(t->i_id=="null"||t->i_id=="NULL"||t->i_id=="\0"||t->i_id=="\n")){
        w<<t->i_id<<endl;
        w<<t->name<<endl;
        w<<t->details<<endl;
        w<<t->link<<endl;
        w<<t->price<<endl;}
    }
    w.close();
}
string inventory::getname()
{
    return name;
}
employee::employee()
{
    ;
}
void employee::set_emp()
{
    employee *t=this;
    int j;
    ifstream in;
    in.open("emp");
    in>>j;
    in.close();
    in.open("emp_details");
    for(int i=0;i<j;i++,t++)
    {
        in>>t->emp_id;
        in>>t->pass;
        in>>t->mobile;
        in>>t->salary;
        in>>t->permission;break;
    }
    in.close();
}
int employee::get_p()
{
    return permission;
}
void employee::change_p()
{
    if(permission==0)permission=1;
    else permission=0;
}
employee::employee(string v)
{
        string emp_id1;
        string pass1;
        string mobile1;
        double salary1;
        int permission1;
    ifstream in;
    in.open("emp_details");
    while(!in.eof())
    {
        in>>emp_id1>>pass1>>mobile1>>salary1>>permission1;
        if(emp_id1==v)
        {
            emp_id=emp_id1;
            pass=pass1;
            mobile=mobile1;
            salary=salary1;
            permission=permission1;
        }
    }
    in.close();
}
void employee::display_details()
{
    cout<<"Id:"<<emp_id<<endl;
    cout<<"mobile no.:"<<mobile<<endl;
    cout<<"salary:"<<salary<<endl;
}
string employee::getid()
{
    return emp_id;
}
void employee::change_details()
{
    int j;
    ifstream in;
    in.open("emp");
    in>>j;
    in.close();
    employee c1[j];
    c1[0].set_emp();
    for(int i=0;i<j;i++)
    {
        if(emp_id==c1[i].getid())
        {   j=i;break;}
    }
    cout<<"Enter 1 for changing password\n"<<"Enter 2 for changing mobile no."<<endl;
    int o;
    cin>>o;
    switch(o)
    {
        case 1:
            c1[j].pass_change();break;
        case 2:
            c1[j].mobile_change();break;
        default:
            cout<<"incorrect option number"<<endl;
    }
    c1[0].writefile();
}
void employee::pass_change()
{
    string p;
    cout<<"Enter old password:"<<endl;
    cin>>p;
    if(p==pass)
    {
        cout<<"Enter new password:"<<endl;
        cin>>pass;
        cout<<"Changed"<<endl;
    }
    else{
        cout<<"Wrong password"<<endl;
    }
}
void employee::mobile_change()
{
    cout<<"Enter mobile number:"<<endl;
    cin>>mobile;
    cout<<"Changed"<<endl;
}
void employee::writefile()
{
    employee *t=this;
    int j;
    ifstream in;
    in.open("emp");
    in>>j;
    in.close();
    ofstream w;
    w.open("emp_details");
    for(int i=0;i<j;i++,t++)
    {
        if(!(t->emp_id=="null"||t->emp_id=="NULL"||t->emp_id=="\0"||t->emp_id=="\n")){
        w<<t->emp_id<<" "<<t->pass<<" "<<t->mobile<<" "<<t->salary<<" "<<t->permission<<endl;
        }
    }
    w.close();
}
customer::customer()
{
    ;
}
customer::customer(string v)
{
        string cust_id1;
        string pass1;
        string mobile1;
    ifstream in;
    in.open("cust_details");
    while(!in.eof())
    {
        in>>cust_id1>>pass1>>mobile1;
        if(cust_id1==v)
        {
            cust_id=cust_id1;
            pass=pass1;
            mobile=mobile1;break;
        }
    }
    in.close();
}
void customer::set_customer()
{
    customer *t=this;
    int j;
    ifstream in;
    in.open("customer");
    in>>j;
    in.close();
    in.open("cust_details");
    for(int i=0;i<j;i++,t++)
    {
        in>>t->cust_id;
        in>>t->pass;
        in>>t->mobile;
    }
    in.close();
}
void customer::display_details()
{
    cout<<"Id:"<<cust_id<<endl;
    cout<<"mobile no.:"<<mobile<<endl;
}
string customer::getid()
{
    return cust_id;
}
void customer::change_details()
{   int j;
    ifstream in;
    in.open("customer");
    in>>j;
    in.close();
    customer c1[j];
    c1[0].set_customer();
    for(int i=0;i<j;i++)
    {
        if(cust_id==c1[i].getid())
        {   j=i;break;}
    }
    cout<<"Enter 1 for changing password\n"<<"Enter 2 for changing mobile no."<<endl;
    int o;
    cin>>o;
    switch(o)
    {
        case 1:
            c1[j].pass_change();break;
        case 2:
            c1[j].mobile_change();break;
        default:
            cout<<"incorrect option number"<<endl;
    }
    c1[0].writefile();
}
void customer::pass_change()
{
    string p;
    cout<<"Enter old password:"<<endl;
    cin>>p;
    if(p==pass)
    {
        cout<<"Enter new password:"<<endl;
        cin>>pass;
    }
    else{
        cout<<"Wrong password"<<endl;
    }
}
void customer::mobile_change()
{
    cout<<"Enter mobile number:"<<endl;
    cin>>mobile;
}
void customer::writefile()
{
    customer *t=this;
    int j;
    ifstream in;
    in.open("customer");
    in>>j;
    in.close();
    ofstream w;
    w.open("cust_details");
    for(int i=0;i<j;i++,t++)
    {
        if(!(t->cust_id=="null"||t->cust_id=="NULL"||t->cust_id=="\0"||t->cust_id=="\n")){
        w<<t->cust_id<<" "<<t->pass<<" "<<t->mobile<<endl;
        }
    }
    w.close();
}
void dash()
{
    for(int i=0;i<150;i++)
    cout<<"-";
    cout<<endl;
}
void bill(string i)
{
    cout << i << endl;
    int n2;
    inventory n1(i);
    cout<<"Amount would be debited from your linked account";
    n1.display();
    cout<<"Thank you for purchasing"<<endl;
    ifstream in2("billing");
    in2>>n2;
    in2.close();
    ofstream n;
    n.open("bill"+to_string(++n2));
    n<<n1.name<<endl;
    n<<n1.details<<endl;
    n<<n1.price<<endl;
    n<<n1.link<<endl;
    n.close();
    n.open("billing");
    n<<n2;
    n.close();
}
void shopping()
{
    int j;string m;
    ifstream in1;
    in1.open("inventory");
    in1>>j;
    in1.close();
    inventory n1[j];
    n1[0].set_inventory();
    cout<<"enter 1 to search"<<endl;
    cout<<"enter 2 to display all items"<<endl;
    cout<<"enter 3 for exit"<<endl;
    cout<<"enter 4 for purchasing"<<endl;
    int o;
    cin>>o;
    switch(o)
    {
        case 1:
            cout<<"Enter name:"<<endl;
            while(getchar()!='\n');
            getline(cin,m);
            for(int i=0;i<j;i++)
            {
                if(m.compare(n1[i].getname())<=0)
                    n1[i].display();
            }
            break;
        case 2:
            for(int i=0;i<j;i++)
                n1[i].display();break;
        case 3:
            break;
        case 4:
            cout<<"Enter inventory id to be purchased:"<<endl;
            cin>>m;
            for(int i=0;i<j;i++)
            {
                cout << "inside the loop" << endl;
                cout <<  m << endl;
                string s = n1[i].getid();
                //s += "rudra";
                string k =s;
                //k+="rudra";
                cout << k << endl;
                if(s!=m)
                {
                    cout << (s==m )<< endl;
                    cout << "INSIDE" << endl;
                    bill(m);
                    break;
                }
                   
            }
            break;
        default:
            cout<<"incorrect option number"<<endl;
    }
}
void edit_inventory()
{
    int j;string p;
    ifstream in;
    cout<<"Enter inventory id:"<<endl;
    cin>>p;
    inventory n1(p);
    n1.display();
    n1.change_details();
}
void manage_c(string c)
{   
    customer c1(c);
    int o=-1;
    do{
        dash();
        cout<<"Welcome Dear Customer"<<endl;
        dash();
        cout<<"enter 1 for viewing profile"<<endl;
        cout<<"enter 2 for editing profile"<<endl;
        cout<<"enter 3 for shopping"<<endl;
        cout<<"enter 4 for exit"<<endl;
        cin>>o;
        switch(o)
        {
            case 1:
                c1.display_details();break;
            case 2:
                c1.change_details();break;
            case 3:
                cout<<"Shopping..."<<endl;shopping();break;
            case 4:
                cout<<"exiting..."<<endl;break;
            default:
                cout<<"enter correct option."<<endl;
        }
    }while(o!=4);
}
void login1()
{
    ifstream in;
    in.open("cust_details");
    string m,m1,c,p,p1,p2;
    cout<<"Enter mobile no."<<endl;
    cin>>m;
    while(!in.eof())
    {
        in>>c>>p1>>m1;
        if(m.compare(m1)==0)
        {
            p=p1;
            break;
        }
    }
    cout<<"Enter password:"<<endl;
    cin>>p2;
    if(p2==p1)
    {
        manage_c(c);
    }
    else{
        cout<<"invalid access"<<endl;
    }
}
void edit_customer()
{
    cout<<"Enter 1 for using customer login details"<<endl;
    cout<<"Enter 2 for using customer id"<<endl;
    int o;
    cin>>o;
    if(o==1)
    {
        login1();
    }
    else if(o=2){
    string p;
    cout<<"Enter customer id:"<<endl;
    cin>>p;
    customer c1(p);
    c1.change_details();
    }
    else
    {
        cout<<"incorrect option number"<<endl;
    }
}

void manage_e(string e)
{
    employee c1(e);
    int o=-1;
    do{
        dash();
        cout<<"Welcome Dear Employee"<<endl;
        dash();
        cout<<"enter 1 for viewing profile"<<endl;
        cout<<"enter 2 for editing profile"<<endl;
        cout<<"enter 3 for editing inventory"<<endl;
        cout<<"enter 4 for editing customer details"<<endl;
        cout<<"enter 5 for exit"<<endl;
        cin>>o;
        switch(o)
        {
            case 1:
                c1.display_details();break;
            case 2:
                c1.change_details();break;
            case 3:
                cout<<"inventory records..."<<endl;
                if(c1.get_p()==1){edit_inventory();}
                else
                {
                    cout<<"invalid access"<<endl;
                }
                break;
            case 4:
                cout<<"customer records..."<<endl;if(c1.get_p()==1){edit_customer();}
                else
                {
                    cout<<"invalid access"<<endl;
                }break;
            case 5:
                cout<<"exiting..."<<endl;break;
            default:
                cout<<"enter correct option."<<endl;
        }
    }while(o!=5);
}
void create1()
{
    string m,p,p1;
    cout<<"Enter mobile no."<<endl;
    cin>>m;
    cout<<"Enter password:"<<endl;
    cin>>p;
    cout<<"Enter password again to confirm:"<<endl;
    cin>>p1;
    if(p==p1)
    {
        fstream n;int n1;
        n.open("customer",ios::in);
        n>>n1;
        n.close();
        n.open("cust_details",ios::app);
        n<<endl;
        n<<"c"+to_string(++n1)<<" "<<p<<" "<<m;
        n.close();
        n.open("customer",ios::out);
        n<<n1;
        n.close();
        cout<<"Created successfully"<<endl;
    }
    else{
        cout<<"password does not match above password"<<endl;
    }
}
void create2()
{
    string m1;
    cout<<"Enter admin password:"<<endl;
    cin>>m1;
    if(m1=="rudra007"){
    string m,p,p1;int per;double s;
    cout<<"Enter mobile no."<<endl;
    cin>>m;
    cout<<"Enter salary:"<<endl;
    cin>>s;
    cout<<"Enter permission(0 for no file access and 1 for all file access):"<<endl;
    cin>>per;
    cout<<"Enter password:"<<endl;
    cin>>p;
    cout<<"Enter password again to confirm:"<<endl;
    cin>>p1;
    if(p==p1)
    {
        fstream n;int n1;
        n.open("emp",ios::in);
        n>>n1;
        n.close();
        n.open("emp_details",ios::app);
        n<<"e"+to_string(++n1)<<" "<<p<<" "<<m<<" "<<s<<" "<<per<<endl;
        n.close();
        n.open("emp",ios::out);
        n<<n1;
        n.close();
        cout<<"Created successfully"<<endl;
    }
    else{
        cout<<"password does not match above password"<<endl;
    }
    }
    else{
        cout<<"invalid access"<<endl;
    }
}

void login2()
{
    ifstream in;
    in.open("emp_details");
    string m,e,m1,p,p1,p2;double s;int per;
    cout<<"Enter mobile no."<<endl;
    cin>>m;
    while(!in.eof())
    {
        in>>e>>p1>>m1>>s>>per;
        if(m.compare(m1)==0)
        {
            p=p1;
            break;
        }
    }
    cout<<"Enter password:"<<endl;
    cin>>p2;
    if(p2==p1)
    {
        manage_e(e);
    }
    else{
        cout<<"invalid access"<<endl;
    }
}
void create()
{
    cout<<"Which account customer or employee?(1 or 2)"<<endl;
    int o=0;
    cin>>o;
    switch(o)
    {
        case 1:
            cout<<"Loading..."<<endl;create1();break;
        case 2:
            cout<<"Loading..."<<endl;create2();break;
        default:
            cout<<"incorrect option";
    }
}
void login()
{
    cout<<"Which account customer or employee?(1 or 2)"<<endl;
    int o=0;
    cin>>o;
    switch(o)
    {
        case 1:
            cout<<"Loading..."<<endl;
            login1();break;
        case 2:
            cout<<"Loading..."<<endl;login2();break;
        default:
            cout<<"incorrect option";
    }
}

void manage()
{
    dash();
    cout<<"\t\t\t\t\t\t\t\tWelcome"<<endl;
    dash();
    int p=0;
    int o=0;
    do{
    cout<<"Enter 1 for login"<<endl;
    cout<<"Enter 2 for create new account"<<endl;
    cin>>o;
    switch(o){
        case 1:
            login();break;
        case 2:
            p=1;create();break;
        default:
            {cout<<"enter correct option no."<<endl;}
    }
    }while(!p);
}
int main()
{
    manage();
}