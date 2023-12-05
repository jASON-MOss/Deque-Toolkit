#ifndef DEQUE_H
#define DEQUE_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
//using namespace std;

class deque{
 private:
  int Size;
  int mapSize;
  int blockSize;
  int first_block;
  int **array;
  int rows;
  int col;
  int current;
 public:
  deque();
  ~deque();
  void push_front(int data);
  void pop_front();
  void push_back(int data);
  void pop_back();
  int front();
  int back();
  bool empty();
  int size();
  void print();
  int& operator [](int index);
};
#endif
