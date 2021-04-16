//
//  hashMap.h
//  hashMap
//
//  Created by ali.berrached on 11/15/17.
//  Copyright © 2017 ali.berrached. All rights reserved.
//

#ifndef hashMap_h
#define hashMap_h
using namespace std;

class HashEntry {
    public:
    int key;
    string value;
    
    HashEntry(int key, string value) {
        this->key = key;
        this->value = value;
    }
    
};

//============================================
const int TABLE_SIZE = 11;

class HashMap {
    private:
    HashEntry **table;

    public:
    HashMap() {
        table = new HashEntry*[TABLE_SIZE];
        for (int i = 0; i < TABLE_SIZE; i++)
            table[i] = NULL;
    }
    
    bool find(int key, string& value) {
        // return value associated with key
        // return -1 if not found
        
        int hash = (key % TABLE_SIZE);
        
        while (table[hash] != nullptr && table[hash]->key != key)
            hash = (hash + 1) % TABLE_SIZE; //linear probe
        
        if (table[hash] == nullptr)
            return false;  // not found
        
        else //table[hash]->key != key
        {
            value = table[hash]->value;
            return true;
        }
    }
    
    void insert(int key, string value) {
        //Insert <key, value> pair using hassh function
        
        int hash = (key % TABLE_SIZE);
        int count = 1;
        while (count < TABLE_SIZE && table[hash] != nullptr && table[hash]->key != key)
        {
            hash = (hash + 1) % TABLE_SIZE;
            ++count;
        }
        if (count >= TABLE_SIZE)
        {
            cout<<" Hash table is full!!" <<endl;
            return;
        }
        if (table[hash] != nullptr)
                delete table[hash];
        
        table[hash] = new HashEntry(key, value);
    }
    
    void display() {
    // used for debugging purpose only to inspect what's in the map
    
        for (int i=0; i< TABLE_SIZE; ++i)
            if (table[i] == nullptr)
                cout << "["<< i <<", Nil, Nil" << "]" << endl;
            else
                cout << "["<< i <<", " << table[i]->key << ", " << table[i]->value
                        << "]" << endl;
        cout << endl;
    }
    
    ~HashMap() {
        for (int i = 0; i < TABLE_SIZE; i++)
        if (table[i] != NULL)
        delete table[i];
        delete[] table;
    }

};

#endif /* hashMap_h */
