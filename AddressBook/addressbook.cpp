#include <iostream> //includes the use of all function used for reading and writing ops like cin and cout.
#include <list> //use of lists
#include <cstring> //C-Style string manipulation
using namespace std;

class HashTable {
    private:
        static const int hashGroups = 10;
        list<pair<int,string>> table[hashGroups];

    public:
        bool isEmpty() const; //to check and see if our hashtable is empty.
        int hashFunction(int key); //used to create our keys
        void insertItem(int key, string value);
        void removeItem(int key);
        string searchTable(int key);
        void printTable();
};

bool HashTable::isEmpty() const
{
    int sum = 0;
    for (int i = 0; i < hashGroups; i++) 
    {
        sum += table[i].size(); //sums the size of each list in the table
    }

    if(sum == 0) 
    {
        return true; //if sum is 0, then the table is empty
    } 
    else 
    {
        return false; //otherwise, it is not empty
    }

}

int HashTable::hashFunction(int key) 
{
    return key % hashGroups; //returns the index for the key
    //Example: if key is 12 and hashGroups is 10, it will return 2.
}

void HashTable::insertItem(int key, string value)
{
    int hashValue = hashFunction(key); //get the index for the key
    auto& cell = table[hashValue]; //get the list at that index
    auto iterator = begin(cell); //initialized an iterator for the list
    bool KeyExists = false; //flag to check if key exists

    for(; iterator != end(cell); iterator++) //iterate through the list
    {
        if(iterator->first == key) //check if the key already exists
    {
        KeyExists = true; //if key exists, set flag to true
        iterator->second = value; //update the value for that key
        cout << "[Warning]: Key exists. Value updated." << endl;
        break; //exit the loop
        }
    }

    if(!KeyExists) 
    {
        cell.emplace_back(key, value); //if key does not exist, add a new key-value pair
    }
    return; //exit the function
}

void HashTable::removeItem(int key)
{
    int hashValue = hashFunction(key); //get the index for the key
    auto& cell = table[hashValue]; //get the list at that index
    auto iterator = begin(cell); //initialized an iterator for the list
    bool KeyExists = false; //flag to check if key exists

    for(; iterator != end(cell); iterator++) //iterate through the list
    {
        if(iterator->first == key) //check if the key already exists
    {
        KeyExists = true; //if key exists, set flag to true
        iterator = cell.erase(iterator); //erases Key
        cout << "[INFO]: Item removed." << endl;
        break; //exit the loop
        }
    }

    if(!KeyExists)
    {
        cout << "[WARNING}: Key not found. Pair not removed." << endl;
    }

    return;
}

string HashTable::searchTable(int key)
{
    int hashValue = hashFunction(key); //get the index for the key
    auto& cell = table[hashValue]; //get the list at that index
    auto iterator = begin(cell); //initialized an iterator for the list

    for(; iterator != end(cell); iterator++) // for itertor in loop and not at end of cell. 
    {
        if(iterator->first == key)
        {
            cout << "[INFO]: Key found! " << "Key: " << iterator->first << " Value: " << iterator->second << endl;
            return iterator->second;
        }
    }

    cout << "[Warning]: Key not found." << endl;
    return "";
}

void HashTable::printTable()
{
    for(int i = 0; i < hashGroups; i++)
    {
        if(table[i].size() == 0) continue;

        auto iterator = table[i].begin(); // iterator that points to start of list
        for(; iterator != table[i].end(); iterator++)
        {
            cout << "[INFO]: Key: " << iterator->first << " Value: " << iterator->second << endl;
        }
    }
    return;
}

int main()
{
    HashTable AddressBook;

    cout << "Operation 1: Add intel to book." << endl;
    if(AddressBook.isEmpty()) cout << "Address Book is empty." << endl;
    else cout << "Address Book has information!" << endl;
    AddressBook.insertItem(707, "Connor Whitaker");
    AddressBook.insertItem(708, "James");
    AddressBook.insertItem(709, "Mike");
    AddressBook.insertItem(710, "Venessa");
    AddressBook.printTable();
    cout << "=========================================== \n" << endl;


    cout << "Operation 2: replace intel already in book." << endl;
    AddressBook.insertItem(710, "Jimmy");
    AddressBook.printTable();
    cout << "=========================================== \n" << endl;


    cout << "Operation 3: remove intel alreay in book & not in book." << endl;
    AddressBook.removeItem(710);
    AddressBook.removeItem(666);

    if(AddressBook.isEmpty()) cout << "Address Book is empty." << endl;
    else cout << "Address Book has information!" << endl;
    cout << "=========================================== \n" << endl;


    cout << "Operation 4: search for intel in book." << endl;
    AddressBook.searchTable(709);
    cout << "=========================================== \n" << endl;


    return 0;
}
