/**
 * @file main.cpp
 * @author Jason Moss
 * @date 2023-11-24
 * @brief Uses a deque
 * 
 * uses a deque
 */

#include <iostream>
#include <iomanip>
#include "deque.h"
//using namespace std;

#include <iostream>

using namespace std;

int main() {
  deque test;
  //checking if empty
  test.empty();
  test.push_front(0);
  //pushing 1 to the back
  test.push_back(1);
  //pushing 2 and 3 to the front
  test.push_front(2);
  test.push_front(3);
  //testing to see if not empty
  test.empty();
  //showing what is at front of array
  test.front();
  //showing what is at the back of the array
  test.back();
  //getting size of array
  test.size();
  //removing from front
  test.pop_front();
  //removing from back
  test.pop_back();
  //printing again
  test.print();
  //push some more to the front
  std::cout << "pushing 9 to the front" << std::endl;
  test.push_front(9);
  std::cout << "pushing 10 to the front" << std::endl;
  test.push_front(10);
  std::cout << "pushing 11 to the front" << std::endl;
  test.push_front(11);
  std::cout << "pushing 12 to the front" << std::endl;
  test.push_front(12);
  //another print
  //using a for loop to push 500 numbers to the front
  for(int i = 0; i < 500; i++){
    test.push_front(i);
  }
  test.print();
  for(int i = 0; i < 500; i++){
    test.push_back(i);
  }
  test.push_back(100);
  test.print();
  test.pop_back();
  test.pop_back();
  test.print();
  //showing the values returned
  int testNum = test.empty();
  int testNum2 = test.front();
  int testNum3 = test.back();
  std::cout << "empty?: " << testNum << std::endl;
  std::cout << "front?: " << testNum2 << std::endl;
  std::cout << "back?: " << testNum3 << std::endl;
  return 0;
}
