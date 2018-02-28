#include "List.h"

#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

List<int> * slow_list(int n) {

  // placeholder
  return nullptr;
}

int main(int argc, char *argv[]){
  List<int> *list = new List<int>();
  List<string> *list2 = new List<string>();
  List<string> *list3 = new List<string>();
  List<int> *list4 = new List<int>();
  int x;
  int n, ndel;

  n = 1000;

  if(argc == 2) {
    n = atoi(argv[1]);
  }


  // ---------------------------------------------------------------
  // TEST: length() function by calling print which calls length() and length() returns number of elements in list
  cout << "*** 1. TEST LENGTH() FUNCTION: ***" << endl;
  for(x=1; x<=4; x++) {
    list->push_front(x);
    list4->push_front(x);
  }
  list->print();

  for(x=1; x<=4; x++) {
    list->push_back(x);
  }
  list->print();
  cout << endl;


  // ---------------------------------------------------------------
  // TEST: count() function after duplicates have been put into list
  cout << "*** 2. TEST COUNT() FUNCTION: ***" << endl
       << "How many 4's are in list (should be 2): " << list->count(4) << endl
       << "How many 10's are in list (should be 0): " << list->count(10) << endl << endl;


  // ---------------------------------------------------------------
  // TEST: equal_to() function
  cout << "*** 3. TEST EQUAL_TO() FUNCTION: ***" << endl
       << "Are these lists equal (NO): " << list->equal_to(*list4) << endl;
  // Make them equal now
  for(x=1; x<=4; x++) {
    list4->push_back(x);
  }
  cout << "Are these lists equal (YES): " << list->equal_to(*list4) << endl << endl;


  // ---------------------------------------------------------------
  // TEST: pop_back() function
  cout << "*** 4. TEST POP_BACK() FUNCTION: ***" << endl
       << "Before list (more than 1 node): ";
  list->print();
  int testVal= 0;
  cout << "Was pop back successful? (should be yes): " << list->pop_back(testVal) << "; and popped off (should be 4): ";
  cout << testVal << endl;
  list->print();
  cout << endl;

  // Make list one node long
  int listLength = list->length();
  for (x = 0; x < listLength - 1; x++) {
    list->pop_back(testVal);
  }
  cout << "Before list (1 node): ";
  list->print();
  cout << "Was pop back successful? (should be yes): " << list->pop_back(testVal) << "; and popped off (should be 4): ";
  cout << testVal << endl;
  list->print();
  cout << endl;

  // Make list empty
  cout << "Before list (empty): ";
  list->print();
  cout << "Was pop back successful? (should be no): " << list->pop_back(testVal) << endl << endl;


  // ---------------------------------------------------------------
  // TEST: print_rev() function
  cout << "*** 5. TEST PRINT_REV() FUNCTION: ***" << endl;

  // Put values in list again [1,10]
  for(x = 1; x <= 10; x++) {
    list->push_front(x);
  }

  cout << "Before list (10 elements): ";
  list->print();
  cout << "List reveresed by calling print_rev which prints out elements in reverse order: ";
  list->print_rev();

  // Make list have 1 element
  cout << endl;
  listLength = list->length();
  for (x = 0; x < listLength - 1; x++) {
    list->pop_back(testVal);
  }
  cout << "Before list (1 element): ";
  list->print();
  cout << "Call to print_rev: " << endl;
  list->print_rev();

  // Make list empty
  cout << endl;
  list->pop_back(testVal);
  cout << "Before list (0 elements): ";
  list->print();
  cout << "Call to print_rev: " << endl;
  list->print_rev();
  cout << endl;


  // ---------------------------------------------------------------
  // TEST: insert_sorted() function
  cout << "*** 6. TEST INSERT_SORTED() FUNCTION: ***" << endl;

  // Create list of ordered numbers
  list->push_front(7); list->push_front(6); list->push_front(4); list->push_front(3); list->push_front(2);
  cout << "List before: ";
  list->print();
  cout << endl;

  // Insert in the middle
  cout << "Insert in middle (5): ";
  list->insert_sorted(5);
  list->print();
  cout << endl;

  // Insert in beginning
  cout << "Insert in beginning (1): ";
  list->insert_sorted(1);
  list->print();
  cout << endl;

  // Insert at end
  cout << "Insert at end (10): ";
  list->insert_sorted(10);
  list->print();
  cout << endl;

  // Insert a duplicate integer
  cout << "Insert duplicate integers (1): ";
  list->insert_sorted(1);
  list->print();
  cout << "Insert duplicate integers (5): ";
  list->insert_sorted(5);
  list->print();
  cout << "Insert duplicate integers (10): ";
  list->insert_sorted(10);
  list->print();
  cout << endl;

  // Create list of one number, try inserting a smaller integer, then try inserting a larger integer
  listLength = list->length();
  for (x = 0; x < listLength - 1; x++) {
    list->pop_back(testVal);
  }
  cout << "Before list (1 element): ";
  list->print();
  cout << endl;

  cout << "Insert a smaller integer (0): ";
  list->insert_sorted(0);
  list->print();
  cout << endl;

  list->pop_front(testVal); // Make list one element long again
  cout << "Before list (1 element): ";
  list->print();
  cout << endl;

  cout << "Insert a larger integer (9): ";
  list->insert_sorted(9);
  list->print();
  cout << endl;

  // Create an empty list and insert
  list->pop_back(testVal);
  list->pop_back(testVal);
  list->print();
  cout << "Insert an integer on empty list: ";
  list->insert_sorted(25);
  list->print();
  cout << endl;

  // ---------------------------------------------------------------
  // TEST: concat() function
  cout << "*** 7. TEST CONCAT() FUNCTION: ***" << endl;
  list->push_front(3);
  list->push_front(17);
  list->print();
  list4->print();

  // trying to concat the same list
  cout << endl << "Trying to concat same lists..." << endl;
  list->concat(*list);
  cout << endl;

  // make two lists with elements and combine them
  list->concat(*list4);
  list->print();
  list4->print();
  cout << endl;

  // test if concat with empty list, both ways
  cout << "Concat list with empty list: " << endl;
  list->concat(*list4);
  list->print();
  list4->print();
  cout << endl;


  // ---------------------------------------------------------------
  // TEST: clone() function
  cout << "*** 8. TEST CLONE() FUNCTION: ***" << endl;
  cout << "Current list (ints): ";
  list->print();
  List<int> *recieveClonedListI;
  recieveClonedListI = list->clone();
  cout << "Cloned list (ints): ";
  recieveClonedListI->print();
  cout << endl;

  // Put string elements in list and make copy using same clone function
  string words[] = {"alice", "bob", "cathy", "donald"};
  for (int i = 0; i < 4; i++) {
      list2->push_front(words[i]);
  }

  cout << "Current list (strings): ";
  list2->print();
  List<string> *recieveClonedListS;
  recieveClonedListS = list2->clone();
  cout << "Cloned list (strings): ";
  recieveClonedListS->print();
  cout << endl;


  // ---------------------------------------------------------------
  // TEST: reverse() function
  cout << "*** 9. TEST REVERSE() FUNCTION: ***" << endl;
  cout << "Current list: ";
  list->print();
  list->reverse();
  cout << "List reversed: ";
  list->print();
  cout << endl;


  // ---------------------------------------------------------------
  // TEST: merge_with() function
  cout << "*** 10. TEST MERGE_WITH() FUNCTION: ***" << endl;

  // Clear lists
  listLength = list->length();
  for (x = 0; x < listLength; x++) {
    list->pop_back(testVal);
  }
  listLength = list4->length();
  for (x = 0; x < listLength; x++) {
    list4->pop_back(testVal);
  }
  // Populate lists with ordered values
  list->push_back(5); list->push_back(7); list->push_back(7);list->push_back(10);list->push_back(12);
  list4->push_back(0); list4->push_back(1); list4->push_back(6);list4->push_back(11);list4->push_back(20);
  // Test merge_with() function
  cout << "Current lists: ";
  list->print();
  list4->print();
  cout << "Merge the lists!";
  list->merge_with(*list4);
  list->print();
  list4->print();
  cout << "Push back 99" << endl;
  list->push_back(99);
  list->print();
  cout << endl;
  cout << endl;


  list->clear();
  list4->clear();
  list4->push_back(5); list4->push_back(7); list4->push_back(7);list4->push_back(10);list4->push_back(12);
  cout << "THE TEST................" << endl;
  cout << "Current lists...empty calling with filled parameter [5 7 7 10 12]: " << endl;
  cout << "calling list: " << endl;
  list->print();
  cout << "parameter list: " << endl;
  list4->print();
  list->merge_with(*list4);
  cout << "after: " << endl;
  list->print();
  list4->print();


  // ---------------------------------------------------------------
  // TEST: prefix() function
  cout << "*** 11. TEST PREFIX() FUNCTION: ***" << endl
       << "Current list (ints): ";
  list->print();

  // Declare list of ints
  cout << "Call to prefix with k = 4: " << endl;
  List<int> * preI = list->prefix(4);
  list->print();
  preI->print();
  cout << endl;

  cout << "Call to prefix with k = 6 (all the elements): " << endl;
  list->print();
  List<int> * replace = list->prefix(6);
  cout << "After call..." << endl;
  list->print();
  replace->print();
  cout << endl;

  cout << "Call to prefix with k = 0 (should return empty list)" << endl;
  preI->print();
  List<int> * empty = preI->prefix(0);
  cout << "After call..." << endl;
  preI->print();
  empty->print();
  cout << endl;

  // Declare list of strings
  cout << "Current list (strings): ";
  list2->print();
  cout << "Call to prefix with k = 2: " << endl;
  List<string> *preS = list2->prefix(2);
  list2->print();
  preS->print();
  cout << endl;

  cout << "Calling with k = 3 (larger than elements...2 elements in list)" << endl;
  list2->print();
  List<string> *larger = list2->prefix(3);
  list2->print();
  larger->print();
  cout << endl;


  // ---------------------------------------------------------------
  // TEST: fast_remove_all() function
  cout << "*** 12. TEST FAST_REMOVE_ALL() FUNCTION: ***" << endl
       << "Current list: ";
  list->push_back(4);  list->push_back(1);  list->push_back(4);  list->push_back(6);  list->push_back(5);  list->push_back(4);
  list->print();

  int numDel = list->fast_remove_all(4);
  cout << "After fast remove all (4)...Elements deleted: " << numDel << endl;
  list->print();
  cout << endl;

  // ---------------------------------------------------------------
  // TEST: fast_remove_all() function
  cout << "*** 13. TEST FILTER_LEQ() FUNCTION: ***" << endl
       << "Current list: ";
  list->clear();
  list->push_front(2); list->push_front(3); list->push_front(4);
  list->print();
  List<int> *filter = list->filter_leq(4);
  cout << "After filter_leq(4): " << endl;
  list->print();
  filter->print();
  cout << endl;

  cout << "Teacher example list:  [4, 9, 2, 4, 8, 12, 7, 3]" << endl;
  list->clear();
  list->push_back(4); list->push_back(9); list->push_back(2); list->push_back(4);
  list->push_back(8); list->push_back(12); list->push_back(7); list->push_back(3);
  filter->clear();
  list->print();
  filter->print();
  filter = list->filter_leq(4);
  cout << "After filter_leq(4): " << endl;
  list->print();
  filter->print();


  // ---------------------------------------------------------------
  // TEST: suffix maxes
  cout << "*** 14. TEST SUFFIX_MAXES() FUNCTION: ***" << endl
       << "Current list: ";
  list->clear();
  list->push_back(6); list->push_back(-18); list->push_back(12); list->push_back(4);
  list->push_back(1); list->push_back(7); list->push_back(2); list->push_back(5); list->push_back(4);
  list->print();
  filter->clear();
  filter->print();
  cout << "AFTER: " << endl;
  filter = list->suffix_maxes();
  list->print();
  filter->print();
  //filter->print();


  return 0;
}
