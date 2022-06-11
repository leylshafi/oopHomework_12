#pragma once
class Wagon
{
    
    string _no;
    int _productCount;
    double _speed;
    string _country;
public:
    stack<Product>_products;
    Wagon() = default;
    Wagon(string no, int productCount, double speed, string country)
    {
        _no = no;
        _productCount = productCount;
        _speed = speed;
        _country = country;

    }

    friend ostream& operator<<(ostream& output, const Wagon& w);
};
ostream& operator<<(ostream& output, const Wagon& w)
{
    cout << "\nWagon number: " << w._no << endl << "Product count: " << w._productCount << endl;
    cout << "Wagon speed: " << w._speed << endl << "Country: " << w._country << endl;
    cout << "=====Products===== " << endl;
    cout << endl;
    for (size_t i = 0; i < w._productCount; i++)
    {
        cout << w._products._Get_container()[i] << endl;
    }
    return output;
}