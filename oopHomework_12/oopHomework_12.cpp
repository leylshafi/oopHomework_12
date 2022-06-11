#include <iostream>
#include<stack>
using namespace std;
#include"Product.h"
#include"Wagon.h"
#include"DoubleLinkedList.h"



int main()
{
    Product p1("Cola", 2.5, 30, "Coca-Cola");
    Product p2("Fanta", 1.5, 40, "Coca-Cola");
    Product p3("Sprite", 3.5, 10, "Sprite");

    Wagon w1("1",3,200,"Germany");
    w1._products.push(p1);
    w1._products.push(p2);
    w1._products.push(p3);

    Product p4("Chocolate", 6.8, 20, "myChocolate");
    Product p5("M&Ms", 1.25, 0, "M&Ms");


    Wagon w2("2", 2, 300, "France");
    w2._products.push(p4);
    w2._products.push(p5);

    DoublyLinkedList<Wagon> train;
    train.push_back(w1);
    train.push_back(w2);
    train.startFront();

    train.pop_back();
    train.startFront();


    Wagon w3("4", 3, 200, "Azerbaijan");
    w3._products.push(p1);
    w3._products.push(p2);
    w3._products.push(p3);
    
   


}
