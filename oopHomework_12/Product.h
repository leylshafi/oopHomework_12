#pragma once
class Product
{
    int _id;
    static int staticId;
    string _name;
    double _price;
    int _discount;
    string _company;
public:
    Product(string name, double price, int discount, string company)
    {
        _id = ++staticId;
        _name = name;
        _price = price;
        _discount = discount;
        _company = company;

    }
    friend ostream& operator<<(ostream& output, const Product& p);
};
int Product::staticId = 0;
ostream& operator<<(ostream& output, const Product& p)
{
    cout << "Product id: " << p._id << endl << "Product name: " << p._name << endl << "Product price: " << p._price << endl;
    cout << "Product discount: " << p._discount << endl << "Product company: " << p._company << endl;
    return output;
}