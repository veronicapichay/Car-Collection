//******************************************************************
//Program Name: Program 9
//Author: Veronica Pichay
//Created: ‎Saturday, ‎April ‎18, ‎2020
//IDE Used: Repl.it
//Program description: Car Collection 
//******************************************************************
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

struct Car //struct variable name
{

string make;
string model;
int yr;
int mileage;
int speed;

};

void welcome ();
void displayCarStat(vector<Car>);
void accelerateCar(vector<Car>&);
void decelerateCar(vector<Car>&);
void removeCar(vector<Car>&);
void addCar(vector<Car>&);
void selectionSort(vector<Car>&);
void swap(int &, int &);

int main(){
//Welcome fx
welcome();



//Initialization 
vector<Car> carLot;
int action, i;
cout << "Number of cars in the lot: " << carLot.size() << endl;
//Interactivity
    while (action != 6)
    {
    //Menu
    cout <<"\nSelect: " <<endl <<endl;   
    cout <<"[" << 1 <<"]" <<" Accelerate a car" <<endl;
    cout <<"[" << 2 <<"]" <<" Decelerate a car" <<endl;
    cout <<"[" << 3 <<"]" <<" Add a car to the lot" <<endl;
    cout <<"[" << 4 <<"]" <<" Remove a car from the lot" <<endl;
    cout <<"[" << 5 <<"]" <<" Display car collection lot" <<endl;
    cout <<"[" << 6 <<"]" <<" Quit" <<endl;
    cout << "> Action # --> ";
    cin >> action;
    //IVL for user action choice
    while (action < 1 or action > 6)
    {
        cout << "\t> ERROR! 1 - 6 only : ";
        cin >> action;
    }

switch (action)
{

    case 1:  if (carLot.size() == 0) cout <<"***ERROR! The Car Collection Lot is currently empty!\n"; 
            else 
           
            accelerateCar(carLot);
            
            break;

                
    case 2: if (carLot.size() == 0) cout <<"***ERROR! The Car Collection Lot is currently empty!\n"; 

            else 
                 decelerateCar(carLot);
                 
                 break;

    case 3: addCar(carLot);
            
            break;     


    case 4: if (carLot.size() == 0) cout <<"***ERROR! The Car Collection Lot is currently empty!\n"; 
            else
               
                removeCar(carLot);
                
                break;

    case 5: selectionSort(carLot);
            displayCarStat(carLot);
            break;

    case 6: cout <<"Program ending... Goodnye!\n";      
      
} 

    }

    return 0;
}

void welcome ()
{
    cout <<"\n Welcome to ABC Car Collection Lot \n";
    cout <<"-----------------------------------\n";
}

void displayCarStat(vector<Car> d)
{
cout << fixed << setprecision(1);
cout <<"\nCar Collection Status: \n" <<endl;
cout << left << setw(18) <<"Make/Model" <<right <<setw(6) <<"Year"  << setw(15) <<"Mileage" << setw(12) <<"Speed\n" << left;
cout << setw(18) <<"----------" << setw(6) << right <<"----"
<< setw(15) <<"-------" << setw(12) <<"-----\n" << left;
    for (int i = 0; i < d.size(); i++)
    {

    string combined = d[i].make + " " + d[i].model;  

        cout  << setw(20) << combined << setw(12) << d[i].yr << setw(15) << d[i].mileage <<d[i].speed  <<endl; 
    } 
   
}

void accelerateCar(vector<Car> &a)
{

    cout <<"\nACCELERATING A CAR:\n";
    cout <<"> Enter car number to accelerate:\n\n";
    int pck, newSpeed;
    for (int i = 0; i < a.size(); i++)
        cout << "[" << i+1 << "] " <<a[i].yr <<" " << a[i].make <<" "  <<a[i].model << endl;
    cout <<"> Car # --> ";
    cin >> pck;
    
    while (pck < 1 or pck > a.size())
    {
        cout << "\t> ERROR: enter 1-" << a.size() << " only: ";
        cin >> pck;
    }
    
    pck--;
    a[pck].speed += 5;
    cout <<"*** New Speed is " <<a[pck].speed ;
  
}

void decelerateCar(vector<Car> &d)
{

    cout <<"\nDECELERATING A CAR:\n";
    cout <<"> Enter car number to decelerate:\n\n";
    int pck, newSpeed;
    for (int i = 0; i < d.size(); i++)
        cout << "[" << i+1 << "] " <<d[i].yr <<" " << d[i].make <<" "  <<d[i].model << endl;
    cout <<"> Car # --> ";
    cin >> pck;
    
    while (pck < 1 or pck > d.size())
    {
        cout << "\t> ERROR: enter 1-" << d.size() << " only: ";
        cin >> pck;
    }
    
    pck--;
    
    if (d[pck].speed != 0)
   {
  newSpeed = d[pck].speed - 5;
  cout <<"*** New Speed is " <<newSpeed;
   }
    else cout<<"The car that you picked is already in zero!\n";

}


void addCar(vector<Car> &a)
{
    Car temp;

    cout <<"\n> Enter the make and ";
    getline (cin, temp.make);
    cout <<"model of the car: ";
    getline (cin, temp.make);
    cout <<"> Enter the year of the car: ";
    cin >> temp.yr;
    cout <<"> Enter the mileage of the car: ";
    cin >> temp.mileage;
    cout <<"> Enter the speed: ";
    cin >> temp.speed;

a.push_back (temp);
}

void removeCar(vector<Car> &r)
{

    cout <<"\nREMOVING CAR FROM THE LOT:\n";
    cout <<"> Enter car number to remove:\n\n";
    int pck;
    for (int i = 0; i < r.size(); i++)
        cout << "[" << i+1 << "] " <<r[i].yr <<" " << r[i].make <<" "  <<r[i].model << endl;
    cout <<"> Car # --> ";
    cin >> pck;
    
    while (pck < 1 or pck > r.size())
    {
        cout << "\t> ERROR: enter 1-" << r.size() << " only: ";
        cin >> pck;
    }
    pck--;
    r.erase(r.begin() + pck);
    cout <<"***Succesfully removed!\n";


}

void selectionSort (vector<Car> &carLot) 

{
    int minIndex;
    int minValue;
   
    for (int start = 0; start < (carLot.size() -1); start++)
    {
        minIndex = start;
        minValue = carLot[start].yr;
        for (int i = start + 1; i < carLot.size(); i++)
        {
            if (carLot[i].yr < minValue)
            {
                minValue =carLot[i].yr;
                minIndex = i;
            }
        }
        swap(carLot[minIndex], carLot[start]);
    }
}

void swap(int &a, int &b)  //Swaps with neighboring element to see if it is higher/lower; returns float element
{
    int temp = a;
    a = b;
    b = temp;
}