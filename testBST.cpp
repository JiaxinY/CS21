#include "BSTInt.h"
#include "BST.hpp"
#include "BSTIterator.hpp"

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>

using namespace std;

/**
 * A test driver for the BST int class and class template.
 * PA1 CSE 100 2016
 * Author: Christine Alvarado and Jiaxin Yang
 * TODO: Add more tests
 */
int main() {

    /* Create an STL vector of some ints */
    /*test*/
    vector<int> v;
    v.push_back(3);
    v.push_back(4);
    v.push_back(1);
    v.push_back(100);
    v.push_back(-33);

    /* Test for height */

    /* Create an instance of BST holding int */
    BSTInt b;

    // Test empty function before insertion
    if(!b.empty()) {
        cout << "Incorrect, the tree should be empty " << endl;
        return -1;
    }

    // Could use: for(auto item : v) { instead of the line below
    for(int item : v) {
        bool pr = b.insert(item);
        if(! pr ) {
            cout << "Incorrect bool return value when inserting " << item 
                 << endl;
            return -1;
        }
    }
  
    // Test empty function again after insertion
    if(b.empty()) {
        cout << "Incorrect, the tree should be empty " << endl;
        return -1;
    }

    // Test height
    if (b.height() != 2) {
        cout << "Incorrect height, should be 2, but got " << b.height()
             << endl;
        return -1;
    }

    /* Test size. */
    cout << "Size is: " << b.size() << endl;
    if(b.size() != v.size()) {
        cout << "... which is incorrect." << endl;
        return -1;
    }

    // Test for inserting item that are already in the tree
    bool pr = b.insert(4);
    if( pr ) {
        cout << "Incorrect bool return value when inserting existed item 4"
             << endl;
        return -1;
    }

    // Test inserting out of order
    if (!b.insert(2)) {
        cout << "Error inserting item 2" << endl;
        return -1;
    }

    // Test height, should still be 2
    if (b.height() != 2) {
        cout << "Incorrect height, should be 2, but got " << b.height()
             << endl;
        return -1;
    }

    if (!b.insert(0)) {
        cout << "Error inserting item 0" << endl;
        return -1;
    }

    // Test height, should become 3
    if (b.height() != 3) {
        cout << "Incorrect height, should be 3, but got " << b.height()
             << endl;
        return -1;
    }

    if (!b.insert(-1)) {
        cout << "Error inserting item -1" << endl;
        return -1;
    }

    // Test height, should become 4
    if (b.height() != 4) {
        cout << "Incorrect height, should be 4, but got " << b.height()
             << endl;
        return -1;
    }

    /* Test find return value. */
    // Test the items that are already in the tree
    for(int item : v) {
        if(!b.find(item)) {
            cout << "Incorrect return value when finding " << item << endl;
            return -1;
        }
    }

    // Test the items that are not in the tree
    if(b.find(99)){
        cout << "Incorrect return value when finding 99 " << endl;
        return -1;
    }

    /* UNCOMMENT THE LINES BELOW TO TEST THE TEMPLATE-BASED ITERATOR */

    /*
    // Test the template version of the BST  with ints 
    BST<int> btemp;
    for (int item : v) {
        // The auto type here is the pair of BSTIterator<int>, bool
        cout << "Inserting " << item << " into the int template-based BST...";
        auto p = btemp.insert(item);
        if (*(p.first) != item) {
            cout << "Wrong iterator returned.  "
                 << "Expected " << item << " but got " << *(p.first) << endl;
            return -1;
        }
        if (!p.second) {
            cout << "Wrong boolean returned.  Expected true but got " 
                 << p.second << endl;
            return -1;
        }
        cout << "success!" << endl;
              
    }

    // Now test finding the elements we just put in
    for (int item: v) {
        cout << "Finding " << item << "...." << endl;
        BSTIterator<int> foundIt = btemp.find(item);
        if (*(foundIt) != item) {
            cout << "incorrect value returned.  Expected iterator pointing to "
                 << item << " but found iterator pointing to " << *(foundIt) 
                 << endl;
            return -1;
        }
        cout << "success!" << endl;
    }



    // Test the iterator: The iterator should give an in-order traversal
  
    // Sort the vector, to compare with inorder iteration on the BST
    sort(v.begin(),v.end());

    cout << "traversal using iterator..." << endl;
    auto vit = v.begin();
    auto ven = v.end();

    // This is equivalent to BSTIterator<int> en = btemp.end();
    auto en = btemp.end();

    //This is equivalent to BST<int>::iterator it = btemp.begin();
    auto it = btemp.begin();
    for(; vit != ven; ++vit) {
        if(! (it != en) ) {
            cout << *it << "," << *vit 
                 << ": Early termination of BST iteration." << endl;
            return -1;

        }
        cout << *it << endl;
        if(*it != *vit) {
            cout << *it << "," << *vit 
                 << ": Incorrect inorder iteration of BST." << endl;
            return -1;
        }
        ++it;
    }

    cout << "success!" << endl;

    */

    // ADD MORE TESTS HERE.  You might also want to change what is input
    // into the vector v.

    cout << "All tests passed!" << endl;
    return 0;
}
