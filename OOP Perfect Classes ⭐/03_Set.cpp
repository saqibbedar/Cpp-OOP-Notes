/*
Create class IntegerSet for which each object can hold a set of integers in the range 0 through 100. Represent the set internally as an array of bool values. Element a[i] is true if integer i is in the set. Element a[i] is false if integer i is not in the set. The default constructor initializes a set to the so-called "empty set," i.e., a set for which all elements contain false. Provide operator functions for the common set operations.

Implement - operator function that creates a third set that is the set-theoretic difference of two existing sets (i.e., an element of the resulting set is set to true if that element is hand side of - operator and false in set at right hand side of - operator). true in set at left

Provide a operator function which creates a third set which is the set-theoretic intersection of two existing sets (i.e., an element of the resulting set is set to false if that element is false in either or both existing sets, and an element of the result is set to true if that element is true in each of the existing sets).

Implement both pre and post decrement operators to remove the last element set is empty, it will return the empty set. If the set is empty, it will return the empty set.

Implement << operator that prints the set containing a list of numbers separated by spaces and enclosed in (). Include only those elements that are present in the set (i.e., their position in the array has a value of true). Print {} for an empty set.

Provide an equality operator == that determines whether two sets are equal.

Provide an additional constructor that receives an array of integers and its size and uses the array to initialize a set object. Remember, use only those elements of the array which are in the range 0-100.

Provide a member function toFile that takes a binary filename as parameter and writes the set elements into that binary file. Write only those elements which are present in set i.e. which are set to true in IntegerSet object

Write a driver program to test your IntegerSet class. Instantiate several IntegerSet objects. Test that all your operator functions work properly.

*/

#include <iostream>
#include <fstream>
using namespace std;

class IntegerSet{
    bool elements[101];
    // function make set empty initially
    void emptySet(){
        for(int i=0; i<101; i++){
            elements[i] = false;
        }
    }
    
    public:
    // default constructor to make "empty set".
    IntegerSet(){
        emptySet();
    }
    
    // parameterized constructor
    IntegerSet(const int *arr, int size){
        emptySet(); // first set all values to false

        for(int i=0; i< size; i++){
            // check if value is within the range(0-101) then it is set and set its value to true
            if(arr[i] >= 0 && arr[i] < 101){
                elements[arr[i]] = true;
            }
        }
    }
    
    // Set-Theoretic Difference: In set theory, the difference between two sets 𝐴 and 𝐵 (often denoted as 𝐴 − 𝐵) is a new set that contains all the elements that are in 𝐴 but not in 𝐵. Essentially, it removes from set 𝐴 any elements that are also in set 𝐵.

    // Example: Set 𝐴={1,2,3,4} Set 𝐵={3,4,5,6} Then, the difference 𝐴 − 𝐵 would be {1,2}, because 3 and 4 are removed from set 𝐴 as they are also in set 𝐵.

    IntegerSet operator-(const IntegerSet& other){
        IntegerSet result;
        for(int i=0; i<101; i++){
            result.elements[i] = elements[i] && !other.elements[i];
        }
        return result;
    }

    // Set-theoretic intersection | intersection A∩B 
    IntegerSet operator&(const IntegerSet& other) const{
        IntegerSet intersected_set; // will hold intersected values (common in both sets)
        for(int i=0; i<101; i++){
            intersected_set.elements[i] = elements[i] && other.elements[i];
        }
        return intersected_set;
    }

    // pre-decrement operator
    IntegerSet& operator--(){
        for(int i=100; i>= 0; i++){
            if(elements[i]){
                elements[i] = false;
                break;
            }
        }
        return *this; // return modified set
    }

    IntegerSet& operator++(){
        for(int i=0; i<101; i++){
            if(!elements[i]){
                elements[i] = true;
                break;
            }
        }
        return *this;
    }

    // post-decrement operator
    IntegerSet operator--(int){
        IntegerSet temp = *this;
        --(*this);
        return temp;
    }

    IntegerSet operator++(int){
        IntegerSet temp = *this;
        ++(*this);
        return temp;
    }

    // print
    friend ostream& operator<<(ostream& out, const IntegerSet& set){
        out<<"(";
        bool flag = true;
        for(int i=0; i<101; i++){
            if(set.elements[i]){
                if(!flag){
                    out<<" ";
                }
                out<< i;
                flag = false;
            }
        }
        out<<")";
        return out;
    }

    // check equality
    bool operator==(const IntegerSet& other)const{
        for(int i=0; i<101; i++){
            if(elements[i] != other.elements[i]){
                return false;
            }
        }
        return true;
    }

    // write to binary file
    void toFile(const string& file_name) const{
        ofstream out(file_name, ios::binary);
        for(int i=0; i<101; i++){
            out.write((char*)&i, sizeof(i));
        }
        out.close();
    }

};

int main() {
    // Test default constructor
    IntegerSet set1;
    cout << "Default constructed set: " << set1 << endl;

    // Test constructor with array
    int arr[] = {10, 20, 30, 40, 50, 101, -1};
    IntegerSet set2(arr, 7);
    cout << "Set initialized with array: " << set2 << endl;

    // Test set-theoretic difference
    IntegerSet diffSet = set2 - set1;
    cout << "Difference set (set2 - set1): " << diffSet << endl;

    // Test set-theoretic intersection
    IntegerSet intersectionSet = set2 & set1;
    cout << "Intersection set (set2 & set1): " << intersectionSet << endl;

    // Test pre-decrement operator
    --set2;
    cout << "Set after pre-decrement: " << set2 << endl;

    // Test post-decrement operator
    set2--;
    cout << "Set after post-decrement: " << set2 << endl;

    // Test equality operator
    IntegerSet set3(arr, 7);
    cout << "Set3 initialized with the same array as set2: " << set3 << endl;
    cout << "Set2 is " << (set2 == set3 ? "equal to" : "not equal to") << " set3" << endl;

    // Test writing set to binary file
    set3.toFile("set3.dat");
    cout << "Set3 written to binary file 'set3.dat'" << endl;

    return 0;
}
