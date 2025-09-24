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
          for(int i = 0; i < index; i++){
            Entry existing = array[i];
            if(entry->compare(&existing)){
                for(int j = index; j > i; j--){
                    if(j == SIZE) continue;
                    array[j] = array[j-1];
                }
                *(array + 1) = *entry;
                if(index < SIZE) index++;
                return;
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