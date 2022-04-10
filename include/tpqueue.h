// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T, int size>
class TPQueue {
private:
     T arr[size];
     int first;  
     int last; 
public:
     TQueue():first(0), last(0) { }
     void push(T x) {
         if(last - first >= size)
             throw std::string("Full!");
         else {
             arr[(last++) % size]=x;
             } else {
             int k = last + 1;
             while (k <= first && x.prior < arr[k % size].prior) {
           arr[(k - 1) % size] = arr[k % size];
           k++;
         }
         arr[(k - 1) % size] = x;
         last--;
     }
     T pop() {
       return arr[(first++) % size];
     }
     int getSize() {
       return (last-first);
     }
     T front() { 
         return arr[first%size]; 
     } 
     T back() { 
         return arr[(last-1)%size]; 
     }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
