#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <bits/stdc++.h>
using namespace std;

class customer {
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

class employee {
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
    string getid();
    void change_details();
    void set_emp();
    int get_p();
    void change_p();
    void writefile();
};

class inventory {
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
    string getid();
    string getname();
    void writefile();
};

inventory::inventory() {}

inventory::inventory(string v) {
    ifstream in;
    in.open("inventory_stock");
    while (!in.eof()) {
        getline(in, i_id);
        getline(in, name);
        getline(in, details);
        getline(in, link);
        getline(in, price);
        if (i_id == v) {
            this->i_id = i_id;
            this->name = name;
            this->details = details;
            this->link = link;
            this->price = price;
            break;
        }
    }
    in.close();
}

void inventory::set_inventory() {
    inventory *t = this;
    int j;
    ifstream in;
    in.open("inventory");
    in >> j;
    in.close();
    in.open("inventory_stock");
    for (int i = 0; i < j; i++, t++) {
        getline(in, t->i