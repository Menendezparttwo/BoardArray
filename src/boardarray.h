#include <iostream>
#include "board.h"
#define SIZE 5
using namespace std;

class BoardArray : public Board {
    Entry* array;
    int index;

    public:
        BoardArray() {
            array = new Entry[SIZE];
            index = 0;
        }

        void add(Entry* entry) {
          if (index < SIZE) {
        int i = index - 1;
        while (i >= 0 && entry->compare(&array[i])) {
            array[i + 1] = array[i];    // shift right
            i--;
        }
        array[i + 1] = *entry;
        index++;
    } 
    else {
        // Board is full. Check if the new entry is higher than the lowest.
        // Lowest score is at array[SIZE-1] because we keep descending order.
        if (entry->compare(&array[SIZE - 1])) {
            int i = SIZE - 2; // start from second-to-last
            while (i >= 0 && entry->compare(&array[i])) {
                array[i + 1] = array[i]; // shift right
                i--;
            }
            array[i + 1] = *entry;
            // index remains SIZE because we replaced one
        } else {
            std::cout << entry->name << "'s score is too low to be added!" << std::endl;
        }
    }
        }

        void print() {
            for (int i = 0; i < index; i++) {
                cout << i + 1 << ". ";
                array[i].print();
            }
        }
};