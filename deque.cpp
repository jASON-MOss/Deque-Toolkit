/**
 * @file deque.cpp
 * @author Jason Moss
 * @date 2023-11-24
 * @brief Creates a deque
 * 
 * creates a deque
 */

#include "deque.h"
#include <iostream>
#include <iomanip>

/**
 * constructor for deque
 *
 * @pre valid array, rows, col, and blockSize variable declared
 * @post variables set to 0 or NULL. Empty array is created
 * 
 */
deque::deque(){
  rows = 0;
  col = 0;
  array = NULL;
  blockSize = 0;
  
}


/**
 * Deconstructor for deque
 *
 * @pre valid deque function
 * @post deque is decontructed
 * 
 */
deque::~deque(){
  for(int i = 0; i < rows; i++){
    delete[] array[i];
  }
  delete[] array;
}


/**
 * pushes data to the front
 *
 * @param int data the data that is going to be pushed to the front
 * @pre valid array, valid variables
 * @return void 
 * @post array has been resized and the new data has been inserted into the front
 * 
 */
void deque::push_front(int data){
  if(array == NULL){
    std::cout << "No array found. Making..." << std::endl;
    std::cout << "Please enter blocksize: ";
    std::cin >> blockSize;
    std::cout << std::endl << "Please enter number of rows: ";
    std::cin >> rows;
    std::cout << std::endl << "Please enter number of collumns: ";
    std::cin >> col;
    std::cout << std::endl << "rows: " << rows << std::endl;
    array = new int* [rows];
    for(int i = 0; i < rows;i++){
      array[i] = new int[blockSize];
    }
    array[0][0] = data;
    std::cout << "push front finished..." << std::endl;
  }else{
    int numElements = 0;
    numElements = numElements + 1;
    //resize
    //figure out how to get this statement to work
    std::cout << "here8" << std:: endl;
    std::cout << "rows - 1: " << rows -1 << std::endl;
    if(numElements == blockSize){
      for(int i = rows - 1; i > 0; i--){
	for(int j = blockSize; j > 0; j--){
	  if(j == blockSize - 1){
	    array[i + 1][0] = array[i][j];
	  }else{
	    array[i][j + 1] = array[i][j];
	  }
	}
      }
    }
    
    int ** arr2;
    std::cout << "here9" << std::endl;
    arr2 = new int* [rows + 1];
    std::cout << "here10" << std::endl;
    for(int i = 0; i < rows; i++){
      arr2[i] = new int[blockSize];
    }
    std::cout << "here11" << std::endl;
    for(int i = 0; i < rows; i++){
      for(int j = 0; j < blockSize; j++){
	if(i == current){
	  arr2[i][j + 1] = array[i][j];
	}else{
	  arr2[i][j] = array[i][j];
	}
	
      }
    }
    std::cout << "here12" << std::endl;
    arr2[0][0] = data;

    std::cout << "replacing array..." << std::endl;
    array = arr2;
    std::cout << "New Array: " << std::endl;
    std::cout << "push front finished..." << std::endl;
  }
}


/**
 * Removes the data at the front of the deque
 *
 * @pre valid array
 * @return void 
 * @post array has been resized and the data has been removed
 * 
 */
void deque::pop_front(){
  if(array == NULL){
    std::cout << "There is no array to pop..." << std::endl;
  }else{
    //array not empty
    int **newarr;
    newarr = new int*[rows];
    for(int i = 0; i < rows; i++){
      //resize
      newarr[i] = new int[blockSize - 1];
    }
    for(int i = 0; i < rows; i++){
      for(int j = 0; j < blockSize; j++){
	//created blank if statement so that the loop could move past zero without doing anything
	if(i == 0 && j == 0){
	}else{
	  newarr[i][j] = array[i][j];
	  //used to show new front after resize
	  std::cout << "New Front: " << newarr << std::endl;
	}
      }
    }
      array = newarr;
  }
}


/**
 * Puts data at the back of the deque
 *
 * @param int data data that will be pushed to the back
 * @pre valid array, valid variables
 * @return void 
 * @post array has been resized and data has been pushed to the back
 * 
 */
void deque::push_back(int data){
  if(array == NULL){
    std::cout << "No array found. Making..." << std::endl;
    std::cout << "Please enter blocksize: ";
    std::cin >> blockSize;
    std::cout << std::endl << "Please enter number of rows: ";
    std::cin >> rows;
    std::cout << std::endl << "Please enter number of collumns: ";
    std::cin >> col;
    std::cout << std::endl << "rows: " << rows << std::endl;
    std::cout << "cols: " << col << std::endl;
    array = new int* [rows];
    //setting up the collumns
    for(int i = 0; i < col;i++){
      array[i] = new int[blockSize];
    }
    //placing the data at the back
    array[rows - 1][blockSize - 1] = data;
    std::cout <<"back: " << array[rows - 1][blockSize - 1] << std::endl;
  }else{
    int newRow = rows + 1;
    std::cout << "Here?" << std::endl;
    int **arr2 = new int*[rows + 1];
    std::cout << "Here2?" << std::endl;
    for(int i = 0; i < newRow; i++){
      arr2[i] = new int[blockSize];
    }
    std::cout << "here3?" << std::endl;
    for(int i = 0; i < rows; i++){
      for(int j = 0; j < blockSize; j++){
	//copying contents from first array
	arr2[i][j] = array[i][j];
      }
    }
    std::cout << "here4?" << std::endl;
    int count = rows + 1;
    std::cout << count << std::endl;
    std::cout << "here5?" << std::endl;
    arr2[count - 1][blockSize - 1] = data;
    std::cout << "here6?" << std::endl;
    rows = rows + 1;
    std::cout << "here7?" << std::endl;
    array = arr2;
    std::cout << "push back done..." << std::endl;
  }
}

/**
 * Removes the data from the back of the deque
 *
 * @pre valid array, valid variables
 * @return void 
 * @post array is resized and data is deleted
 * 
 */
void deque::pop_back(){
  if(array == NULL){                                                                                
    std::cout << "There is no array to pop..." << std::endl;
  }else{
    int **newarr;
    newarr = new int*[rows];
    for(int i = 0; i < rows; i++){
      newarr[i] = new int[blockSize - 1];
    }
    for(int i = 0; i < rows; i++){
      for(int j = 0; j < blockSize - 1; j++){
	newarr[i][j] = array[i][j];
	//std::cout << "original array: " << array[i][j] << std::endl;
	//std::cout << "new array: " << newarr[i][j] << std::endl;
      }
      array = newarr;
    }
  }
}


/**
 * shows what is at the front of the deque
 *
 * @pre valid array, valid variables
 * @return int front
 * @post number at the front of the array has been returned.
 * 
 */
int deque::front(){
  std::cout << "front: " << array[0][0] << std::endl;
  int front = array[0][0];
  return front;
}


/**
 * shows what is at the back of the array
 *
 * @pre valid array, valid variables
 * @return int back
 * @post the number at the back of the array has been returned
 * 
 */
int deque::back(){
  std::cout << "Back: " << array[rows - 1][blockSize - 1] << std::endl;
  int back = array[rows - 1][blockSize - 1];
  return back;
}


/**
 * Checks if the deque is empty or not
 *
 * @pre valid array
 * @return bool true or false
 * @post true or false has been returned
 * 
 */
bool deque::empty(){
  if(array == NULL){
    std::cout << "EMPTY" << std::endl;
    return true;
  }else{
    std::cout << "NOT EMPTY" << std::endl;
    return false;
  }
}


/**
 * figures out the size of the deque
 *
 * @pre valid array, valid variables
 * @return int count
 * @post The size of the deque has been returned
 * 
 */
int deque::size(){
  int count = 0;
  for(int i = 0; i < rows; i++){
    for(int j = 0; j < blockSize; j++){
      count = count + 1;
      }
  }
  std::cout << "Count: " << count << std::endl;
  return count;
}


/**
 * prints out the content of the deque
 *
 * @pre valid array, valid variables
 * @return void 
 * @post deque has been printed
 * 
 */
void deque::print(){
  std::cout << "Printing" << std::endl;
  for(int i = 0; i < rows; i++){
    for(int j = 0; j < blockSize; j++){
      std::cout << "i: " << i << std::endl;
      std::cout << "j: " << j << std::endl;
      std::cout << array[i][j] << std::endl;
      std::cout << "MOVING ON..." << std::endl;
    }
  }
}

/**
 * overloads the operator []
 *
 * @param int index index to look at
 * @pre valid index, valid deque
 * @return int& data at the position
 * @post the data at the specified position has been returned
 * 
 */
int& deque::operator [](int index){//AHHHHHHHHHHHHHH!!!
  return array[index][index];
}
