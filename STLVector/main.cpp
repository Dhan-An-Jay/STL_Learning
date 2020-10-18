//
//  main.cpp
//  STLVector
//
//  Created by DhanAnJay Ahire on 17/10/20.
//  Copyright © 2020 DhanAnJay Ahire. All rights reserved.
//

// Vecotor for Study -- Quick notes as below
// Vector is a Container
// Dynamic Arrays Ability to resize itself
// Continuous block of memory
// Elements are accessed using iterator
// Takes Linear time for Insert and Deletion
// Doubles the memory at end
// Efficient Access
// Not efficient for deletion (shifting)

# include <iostream>
# include <vector>
# include <string>
# include <fstream>

using namespace std;

int main(int argc, const char * argv[]) {

    vector<string> str = {{"hello World"},{"this is C++"},{"Demo use"}};
    
    //Best practice to use reseve,when you know this much data blocks you will required then it is better to use this reserv function
    str.reserve(10);  //reserve the size of vector to 10, will get increment once assigned size is fulled
    cout<<str.max_size()<<" size: " << str.size() <<" capacity: " << str.capacity()<<endl;;
    
    vector<int> vec(4);  // vector is created with size 4
    vector<int>::iterator itr = vec.begin();  // iterator created for vector and assigned begining of vector to iterator
    cout<<vec.max_size()<<" size: " << vec.size() <<" capacity: " << vec.capacity()<<" " <<*itr<<endl;
    
    for(int i=0; i<10 ;){
        vec.push_back(++i);
    }
    
    int arr[] = {10,20,30,40,50};
    vector<int> vect1(arr,arr+(sizeof(arr)/sizeof(int)));  //Assign array elemnts to vector
    
    vector<int> vect2;
    vect2.assign(std::begin(arr), std::end(arr));  // Assign array elements to the vector
    
    vector<int> vect3={70,80,90,100};
    
    cout<<vect1.max_size()<<" vect1 size: " << vect1.size() <<" capacity: " << vect1.capacity()<<endl;
    vect1.erase(vect1.begin());  // erase begin element from vect1
    vect1.emplace(vect1.begin(), 50); // place new element at begining of vect1
    vect1.emplace(vect1.begin(), 35); // place new element at beginig of vect1
    vect1.emplace_back(60);  // place new element at end of vect1
    vect1.emplace_back(30);  // place new element at end of vect1
    
    cout<<vect1.max_size()<<" vect1 size: " << vect1.size() <<" capacity: " << vect1.capacity()<<endl;
    
    vect1.swap(vect3);
    
    cout<<vect1.max_size()<<" vect1 size: " << vect1.size() <<" capacity: " << vect1.capacity()<<endl;
    cout<<vect3.max_size()<<" vect3 size: " << vect3.size() <<" capacity: " << vect3.capacity() <<endl;
    
    //inser and push_back elements in vector
    vector<int> vect4;
    vect4.insert(vect4.begin(), 5);
    vect4.push_back(10);
    
    //iterate array elements using iterators
    for(int i=0; i<vect1.size() ; i++){
        cout<<vect1[i]<<" ";
    }
    cout<<endl;
    
    for(vector<int>::iterator itr =vect3.begin(); itr !=vect3.end() ; itr++){
        cout<<*itr<<" ";
    }
    cout<<endl;
    
    
    for(auto i=vect2.begin(); i!=vect2.end() ; i++){
        cout<<*i<<" ";
    }
    cout<<endl;
    
    for(auto &i: vect4){
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<"Vect4 size: " << vect4.size() <<" capacity: " << vect4.capacity()<<endl;

    //Read below file and push it as a input to vector
    ifstream data_file("/Users/dhananjay/Documents/C++ Learning Data/STLVector/STLVector/INPUT.txt", std::ifstream::in);
    istream_iterator<string> start (data_file), end;
    vector<string>data(start,end);
    
    for(int i = 0; i < data.size(); i++)
    {
        cout<<data[i]<<endl;
    }
    cout<<"-------end of vector -------"<<endl;
    return 1;
}
