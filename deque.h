#ifndef DEQUE_H
#define DEQUE_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
//using namespace std;


/**
 * creates deque using blockmap
 *
 * @class deque{ deque.h "Deque-Toolkit/deque.h"
 * @brief creates deque using blockmap
 *
 */
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
  /**
   * constructor for deque
   *
   * @pre valid array, rows, col, and blockSize variable declared
   * @post variables set to 0 or NULL. Empty array is created
   * 
   */
  deque();
  /**
   * Deconstructor for deque
   *
   * @pre valid deque function
   * @post deque is decontructed
   * 
   */
  ~deque();
  /**
   * pushes data to the front
   *
   * @param int data the data that is going to be pushed to the front
   * @pre valid array, valid variables
   * @return void 
   * @post array has been resized and the new data has been inserted into the front
   * 
   */
  void push_front(int data);
  /**
   * Removes the data at the front of the deque
   *
   * @pre valid array
   * @return void 
   * @post array has been resized and the data has been removed
   * 
   */
  void pop_front();
  /**
   * Puts data at the back of the deque
   *
   * @param int data data that will be pushed to the back
   * @pre valid array, valid variables
   * @return void 
   * @post array has been resized and data has been pushed to the back
   * 
   */
  void push_back(int data);
  /**
   * Removes the data from the back of the deque
   *
   * @pre valid array, valid variables
   * @return void 
   * @post array is resized and data is deleted
   * 
   */
  void pop_back();
  /**
   * shows what is at the front of the deque
   *
   * @pre valid array, valid variables
   * @return int front
   * @post number at the front of the array has been returned.
   * 
   */
  int front();
  /**
   * shows what is at the back of the array
   *
   * @pre valid array, valid variables
   * @return int back
   * @post the number at the back of the array has been returned
   * 
   */
  int back();
  /**
   * Checks if the deque is empty or not
   *
   * @pre valid array
   * @return bool true or false
   * @post true or false has been returned
   * 
   */
  bool empty();
  /**
   * figures out the size of the deque
   *
   * @pre valid array, valid variables
   * @return int count
   * @post The size of the deque has been returned
   * 
   */
  int size();
  /**
   * prints out the content of the deque
   *
   * @pre valid array, valid variables
   * @return void 
   * @post deque has been printed
   * 
   */
  void print();
  /**
   * overloads the operator []
   *
   * @param int index index to look at
   * @pre valid index, valid deque
   * @return int& data at the position
   * @post the data at the specified position has been returned
   * 
   */
  int& operator [](int index);
};
#endif
