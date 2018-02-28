/**
 * Success! Your submission appears on this page. The submission confirmation number is 6ffff923-aa81-48b0-b015-c0756c07d063. Copy and save this number as proof of your submission.
 *
 * TO DO's LEFT
 *
 * TO DO's DONE:
 * 1. length [15/15 with increase sameple size]
 * 2. count [10/10 with increase sample size]
 * 4. equal_to [10/10]
 * 3. pop_back [15/15]
 * 5. print_rev [15/15]
 * 8. insert_sorted [15/15]
 * 13. concat [15/15]
 * 6. reverse [20/20]
 * 10. clone [15/15]
 * 11. prefix [20/20]
 * 9. merge_with [20/20]
 * 7. fast_remove_all [20/20]
 * 14. compare_with [15/15]
 * 12. filter_leq [20/20]
 * 15. suffix_maxes [15/15]
 *
LEFT:
DONE!
**/

#ifndef LIST_H
#define LIST_H

#include <algorithm>
#include <iostream>
using namespace std;


//---------------------------------------------------------
// Start of class List (not required to add copy constructor, assignment operator, etc)
template <typename T> class List
{
  private:

    // struct for singly-linked list nodes
    struct Node
    {
      T      data;
      Node   *next;

      Node( const T & d = T{}, Node * n = nullptr)
        : data{ d },  next{ n } { }

    };
    //--------------------------------------------------------- TODO 5 helper function: DONE
    // Holds recursive calls for print_rev so list can be traversed
        static void print_rev_help(Node *temp) {
          // Base case
          if (temp == nullptr) {
            return;
          }

          // Print the list after front node
          print_rev_help(temp->next);

          cout << temp->data << " ";
        }


        //--------------------------------------------------------- TODO 15: DONE!
        // suffix_maxes helper function
        void suffix_help(Node *p, T &max) {
          if (p->next == nullptr) {
            return;
          }
          suffix_help(p->next, max);
          if (p->data < max) {
            p->data = max;
          }
          else {
            max = p->data;
          }
        }


  public:
    // constructors
    List( ) {
      init( );
    }

    ~List( ) {
      clear( );
    }


//---------------------------------------------------------
// Makes the calling list empty (but the list still exists)
    void clear() {
      Node * p = front;
      Node *pnext;

      while(p != nullptr) {
        pnext = p->next;
        delete p;
        p = pnext;
      }
      front = back = nullptr;
      nodeCount = 0;
    }


//--------------------------------------------------------- TODO 1: DONE
// Returns the length of the calling list in O(1) time
    int length( ) const {
      return nodeCount;
    }



  public: // QUESTION 2: What is the point of laying out class like this and why is there a second public declaration?


//---------------------------------------------------------
// Return true if the list is empty, false otherwise
    bool is_empty( ) const {
      return front == nullptr;
    }


//---------------------------------------------------------
// Run through list and print contents
    void print() const {
      Node *p = front;
      if (p == nullptr) {
        cout << "List is EMPTY!" << " Number of elements in list: " << length() << endl;
        return;
      }
      cout << "[ ";
      while(p != nullptr) {
        cout << p->data << " ";
        p = p->next;
      }
      cout << "]\n";
      cout << "Number of elements in list: " << length() << " ||| Front val/pt: " << front->data << " / "
           << front << " Back val/pt: " << back->data << " / " << back << endl;
    }


//---------------------------------------------------------
// Put data onto new node at front of list
    void push_front(const T & data) {
      front = new Node(data, front);
      nodeCount++;
      if(back == nullptr)
        back = front;
    }


//---------------------------------------------------------
// Take front node and delete it from list
    bool pop_front(T &val) {
      Node *tmp;

      if(front==nullptr)
        return false;
      val = front->data;

      tmp = front;
      front = front->next;
      delete tmp;
      if(front==nullptr)
        back = nullptr;
      nodeCount--;
      return true;
    }


//---------------------------------------------------------
// Put data onto new node at back of list
    void push_back(const T & val) {
      Node *tmp = new Node(val, nullptr);
      nodeCount++;

      if(front == nullptr) {
        front = back = tmp;
      }
      else {
        back->next = tmp;
        back = tmp;
      }
    }


//---------------------------------------------------------
// Checks to see if remove first node with specific data is valid, if so, pop it by calling pop_front
    bool remove_first(const T &x) {
      Node *p, *tmp;
      T dummy;

      if(front==nullptr) return false;
      if(front->data == x) {
        pop_front(dummy);
        return true;
      }
      p = front;
      while(p->next != nullptr) {
        if(x == p->next->data) {
          tmp = p->next;
          p->next = tmp->next;
          if(tmp == back)
            back = p;
          delete tmp;
          nodeCount--;
          return true;
        }
        p = p->next;
      }
      return false;
    }


//--------------------------------------------------------- (QUESTION 1: What is this function returning?)
// Remove all slow function - check if value is in list and if it can be removed and continually popping the nodes with that data value
    int slow_remove_all(const T &x) {
      int n=0;

      while(remove_first(x))
        n++;
      return n;
    }


//---------------------------------------------------------
// Check each node's value in list and seeing if in order
    bool is_sorted() const {
      Node *p = front;

      while(p!=nullptr && p->next != nullptr) {
        if(p->data > p->next->data)
          return false;
        p = p->next;
      }
      return true;
    }


//--------------------------------------------------------- TODO 2:DONE
// Counts number of occurrences of x in the list and returns that count (runtime O(n))
    int count(const T &x) const {
      int frequency = 0;
      Node *p = front;

      while (p != nullptr) {
        if (p->data == x) {
          frequency++;
        }
        p = p->next;
      }
      return frequency;
    }


//--------------------------------------------------------- TODO 3:DONE
// Remove the last element in the list (runtime O(n)) and return the element value
    bool pop_back(T &data) {
      // Check if list is empty
      if (is_empty()) {
        return false;
      }

      // Check if list is only one element
      if (length() == 1) {
        Node *p = back;
        data = p->data;
        delete p;
        front = nullptr;
        back = nullptr;
        nodeCount--;
        return true;
      }

      // More than one element
        Node *x = front;
        Node *y = front->next;

        while (y->next != nullptr) {
          y = y->next;
          x = x->next;
        }
        data = y->data;
        x->next = nullptr;
        back = x;
        delete y;
        nodeCount--;
        return true;
    }


//--------------------------------------------------------- TODO 4: DONE
// Return true if calling list and parameter list contain exactly same sequence of values, false otherwise, runtime O(n)
    bool equal_to(const List<T> &other) const {
      Node *clist, *plist;
      clist = front;
      plist = other.front;

      // Check same length
      if (length() != other.length()) {
        return false;
      }

      // Check values are the same for each node
      while (clist != nullptr) {
        if (clist->data != plist->data) {
          return false;
        }
        clist = clist->next;
        plist = plist->next;
      }

      return true;
    }




//--------------------------------------------------------- TODO 5: DONE
// Print reverse of list contents using a recursive helper function in O(n) time
    void print_rev() const {
      // If list is empty, print it is empty
      if (is_empty()) {
        cout << "List is EMPTY! Cannot print elements." << endl;
        return;
      }

      // If list is only one element, print same list with note that it only contains one element
      if (length() == 1) {
        cout << "List has only ONE element and cannot be reversed. That element is: " << front->data << endl;
        return;
      }

      // If list has more than one element, print in reverse order using recursive helper function
      print_rev_help(front);

    }


//--------------------------------------------------------- TODO 6: DONE
// Reverse list in O(n) runtime
    void reverse() {
      // Declare temp pointers to walk the list
      Node *tPrev, *tCurr, *tNext;
      tPrev = nullptr;
      tCurr = front;

      // Keep walking list switching each node's next pointer
      while (tCurr != nullptr) {
        tNext = tCurr->next;
        tCurr->next = tPrev;
        tPrev = tCurr;
        tCurr = tNext;
      }

      // Finally, switch front and back respectively
      back = front;
      front = tPrev;
    }


//--------------------------------------------------------- TODO 7: DONE
//
    /**
     *   function:  fast_remove_all
     *   description:  same behavior/semantics as
     *      slow_remove_all.  However, this function
     *      must guarantee linear time worst case
     *      runtime (hence, "fast").
     *
     *   REQUIREMENT:  linear worst-case runtime.
     *
     *   Note:  your solution may be either recursive or
     *   iteratieve.
     **/
    int fast_remove_all(const T &x) {
      // Check if list is empty
      if (is_empty()) {
        cout << "List is empty!" << endl;
        return 0;
      }

      int numDel = 0; // Track number of deletions
      Node *temp = front;
      Node *prev;

      // Check if first element is equal to x
      if (front->data == x) {
        front = temp->next;
        delete temp;
        if (front == nullptr) {
          back = nullptr;
        }
        temp = front;
        nodeCount--;
        numDel++;
      }

      // Check rest of list, other than front
      while (temp != nullptr) {
        while (temp != nullptr && temp->data != x) {
          prev = temp;
          temp = temp->next;
        }

        // Value was not present in list
        if (temp == nullptr) {
          return 0;
        }

        // If lst node is disconnected, set back correctly
        if (temp->next == nullptr) {
          back = prev;
        }

        // Unlink node if value found
        prev->next = temp->next;

        delete(temp);
        numDel++;
        nodeCount--;


        temp = prev->next;
      }

      return numDel;
    }


//--------------------------------------------------------- TODO 8:DONE
// Insert x into appropriate position, assuming list given is sorted from smallest to largest, O(n) runtime
    void insert_sorted(const T &x) {

      // Check if x is smaller than 1st element and insert there
      if (is_empty() || front->data > x) {
        push_front(x);
        return;
      }

      // Declare variables to walk the list and track element values
      Node *temp, *walk;
      temp = front->next;
      walk = front;

      // Traverse list and find where to put element
      while (temp != nullptr) {
        if ((temp->data > x && walk->data < x) || walk->data == x) {
          Node *xNode = new Node(x, temp);
          walk->next = xNode;
          nodeCount++;
          return;
        }
        temp = temp->next;
        walk = walk->next;
      }

      // If reaches this point, element is larger than all others in list so add to end of list
      push_back(x);
    }


//--------------------------------------------------------- TODO 9: DONE
// Merge two sorted lists into one, runtime is linear
    void merge_with(List<T> &other) {
      // Check if calling list is same as parameter list
      if(this == &other) {
        cerr << "warning:  List::merge_with():  calling object same as parameter";
        cerr << "\n          list unchanged\n";
        return;
      }

      // Check if other list is empty
      if (other.is_empty()) {

        cerr << "warning: &other is EMPTY! List unchanged." << endl;
        return;
      }

      // Check if calling list is empty
      if (is_empty()) {
        cout << "Is_empty called!" << endl;
        int dummy = 0;
        Node *tracker;
        while (other.front != nullptr) {
          tracker = other.front->next;
          push_back(other.front->data);
          other.pop_front(dummy);
          other.front = tracker;
        }
        /*
        front = other.front;
        back = other.back;
        other.front = nullptr;
        other.back = nullptr;
        */

        return;
      }

      Node *tempFront, *tempBack;

      // Set the head of merged list
      if (front->data < other.front->data) {
        tempFront = front;
        tempBack = front;
        front = front->next;
      }
      else {
        tempFront = other.front;
        tempBack = other.front;
        other.front = other.front->next;
      }

      // Swap nodes into one list
      while (front != nullptr && other.front != nullptr) {
        if (front->data < other.front->data) {
          tempBack->next = front;
          tempBack = front;
          front = front->next;
        }
        else {
          tempBack->next = other.front;
          tempBack = other.front;
          other.front = other.front->next;
        }
      }

      // Once one list has run out of elements
      if (front != nullptr) {
        tempBack->next = front;
      }
      else {
        tempBack->next = other.front;
        back = other.back;
      }

      // Set calling list to temp list with merged values
      front = tempFront;

      // Set list parameter to nullptr and correct node counts
      nodeCount += other.nodeCount;
      other.nodeCount = 0;
      other.front = other.back = nullptr;
    }


//--------------------------------------------------------- TODO 10: DONE
// Makes a deep copy of given list and returns list pointer (similar to copy constructor)
    List<T> * clone() const {
      List<T> *listClone = new List<T>();

      Node *temp = front;
      while (temp != nullptr) {
        listClone->push_back(temp->data);
        temp = temp->next;
      }

      return listClone;
    }


//--------------------------------------------------------- TODO 11: DONE
// Remove the first k elements from the calling list which are used to form a new list which is then returned, runtime THETA(n) worstcase
    List<T> * prefix(unsigned int k) {
      List<T> *prefixList = new List<T>;
      // Check if empty
      if (is_empty() || k == 0) {
        prefixList->nodeCount = 0;
        return prefixList;
      }

      // Check if k is larger than number of elements in list
      if (k > length()){
        cout << "List only has " << length() << " elements ::: k set to " << k << "." << endl;
        cout << "Changing k to equal maximum length of current list: " << length() << endl;
        k = length();
      }

      // Rearrange k values off of calling list and put that value onto newly declared list that will be returned
      unsigned int i;
      Node *temp;
      temp = front;
      prefixList->front = temp;
      for (i = 0; i < k - 1; i++) {
        temp = temp->next;
      }
      prefixList->back = temp;
      front = temp->next;
      prefixList->back->next = nullptr;
      nodeCount = nodeCount - k;
      prefixList->nodeCount = k;

      return prefixList;
    }


//--------------------------------------------------------- TODO 12: DONE
// Remove all elements of given list which is less than or equal to cutoff.
// List containing removed elements is returned. Runtime: THETA(n)
    List<T> * filter_leq(const T & cutoff) {
      List<T> *filterList = new List<T>;

      // Check if empty
      if (is_empty()) {
        return filterList;
      }


      Node *p = front;
      Node *temp, *q, *walk;
      bool frontSet = false;
      bool filterFrontSet = false;

      // Check each node and compare with cutoff, if data <= cutoff move node to filterList
      while (p != nullptr) {
        walk = p->next;
        if (p->data <= cutoff) {
          // Check if front has been assigned yet
          if (filterFrontSet) {
            q->next = p;
            q = p;
            q->next = nullptr;
          }
          else {
            q = p;
            q->next = nullptr;
            filterList->front = q;
            filterList->back = filterList->front;
            filterFrontSet = true;
          }

          // Increment node counters
          nodeCount--;
          filterList->nodeCount = filterList->nodeCount + 1;
        }
        else {
          if (frontSet) {
            temp->next = p;
            temp = p;
            temp->next = nullptr;
          }
          else {
            temp = p;
            temp->next = nullptr;
            front = temp;
            frontSet = true;
          }
        }
        p = walk;

      }
      // If the entire list is LEQ
      if (!frontSet) {
        front = nullptr;
      }
      cout << frontSet << endl;
      filterList->back = q;
      back = temp;
      return filterList;
    }


//--------------------------------------------------------- TODO 13: DONE
// Concatenates the calling list with parameter list, resulting concatenation reflected in calling list, parameter list becomes empty; runtime O(1)
    void concat(List<T> &other) {

      // Check if calling list is same as parameter list
      if(this == &other) {
        cerr << "warning:  List::concat():  calling object same as parameter";
        cerr << "\n          list unchanged\n";
        return;
      }

      // Check if other list is empty
      if (other.is_empty()) {
        //cerr << "warning: &other is EMPTY! List unchanged." << endl;
        return;
      }

      // Check if calling list is empty
      if (is_empty()) {
        //cerr << "warning: calling list is EMPTY!" << endl;
        front = other.front;
        back = other.back;
        nodeCount += other.nodeCount;
        other.nodeCount = 0;
        other.front = nullptr;
        other.back = nullptr;
        return;
      }

      // Set correct nodeCounts
      nodeCount += other.length();
      other.nodeCount = 0;

      back->next = other.front;
      back = other.back;
      other.front = nullptr;
      other.back = nullptr;
      //cout << "List::concat(): no error...\n";
    }


//--------------------------------------------------------- TODO 14: DONE
// Compare the calling list with parameter lexically
// if the two lists are identical, 0 is returned
// if the calling list is lexically before the other list, -1 is returned
// if the other list is lexically before the calling list return 1
    /**
     *
     * function:  compare_with
     * description: compares the calling list with parameter list (other)
     *    "LEXICALLY" (essentially a generalization of dictionary
     *    ordering)
     *    Properties and examples:
     *
     *        The empty list is lexically before all non-empty lists
     *          (you can say it is "less than" all non-empty lists).
     *
     *        Examples (using mathematical notation):
     *
     *          [2 5 1] < [3 1 1 1 1]    (think dictionary ordering!)
     *
     *          [4 1 3] < [4 1 3 0 0 0]  (prefix: just like "car" is before
     *                                            "cartoon" in the dictionary).
     *
     *          [4 5 6 1 2 3 9 9 9] < [4 5 6 1 4 0 0]
     *                   ^                     ^
     *                      (they have a common prefix of length 4; but at
     *                      the fifth position they differ and the left list
     *                      is the winner (smaller) -- no need to look further)
     *
     *
     *        Templates?
     *
     *          Since List is a template class, the elements of a particular
     *          list need not be integers.  For example, we could have
     *          lists of strings.
     *
     *          Good news:  the exact same principle applies because
     *          strings can be compared just like integers can be compared!
     *
     *          Great news:  you don't need to think about this at all!
     *          The exact same code you would write if you assumed the element
     *          type is integer will work for other types like strings.
     *
     *          Why?  Because, for example, all of these operators:
     *
     *                   <, <=, ==, > and >=
     *
     *          all work on strings.  They are not 'built-in' to C++, but
     *          the class string has "overloaded" these operators (they
     *          result in an appropriate function call).
     *
     *          (In a subsequent exercise, we will do this kind of
     *          overloading ourselves!)
     *
     *        Examples with lists of strings:
     *
     *          ["egg", "goat"] < ["egg", "globe", "apple"]
     *
     *          ["zebra", "fun"] < ["zebra", "funny"]
     *
     *        [Yes, the components of these lists are THEMSELVES compared
     *        lexically, but the string class is doing those comparisons)
     *
     */
    int compare_with(const List<T> &other) const {
        if (this == &other) {
          cerr << "warning: List::compare_with(): calling object same as parameter";
          cerr << "\n          list unchanged\n";
          return 0;
        }

        if (equal_to(other)) {
          return 0;
        }// || nodeCount < other.nodeCount
        else if (is_empty()) {
          return -1;
        }//|| other.nodeCount < nodeCount
        else if (other.is_empty()) {
          return 1;
        }

        Node *clist = front;
        Node *plist = other.front;

        while (clist != nullptr && plist != nullptr) {
          if (clist->data < plist->data) {
            return -1;
          }
          if (plist->data < clist->data) {
            return 1;
          }
          clist = clist->next;
          plist = plist->next;
        }

        if (clist == nullptr) {
          return -1;
        }
        if (plist == nullptr) {
          return 1;
        }

      return 2; // if return 2, error in function, also so comiler does not complain
    }




//--------------------------------------------------------- TODO 15:
//
    /*
     *
     * function:  suffix_maxes
     *
     * desc:  constructs a new list of the same length as the calling object
     *        with the value stored at position i of the new list is the MAXIMUM
     *        value in the suffix (or tail) of the calling list starting from
     *        position i.
     *
     *        This new list is returned and the calling list is unchanged.
     *
     *        Example:
     *
     *          Given List:  [6, -18, 12, 4, 1, 7, 2, 5  4]
     *                                    ^^^^^^^^^^^^^^^^
     *
     *          New list:    [12, 12, 12, 7, 7, 7, 5, 5, 4]
     *                                    ^
     *
     *              (as a sub-example, the marked entry in the new list
     *              (marked with '^') is the max of the marked suffix in the
     *              given list (marked with a bunch of '^'s).
     *
     * REQUIREMENTS:
     *
     *        Total Runtime:   O(n)
     *        Calling list is unchanged.
     *
     */
    List<T> * suffix_maxes() const{
      List<T> * suffixList = new List<T>;
      if (is_empty()) {
        return suffixList;
      }
      suffixList = clone();
      Node *p = suffixList->front;
      T max = suffixList->back->data;
      suffixList->suffix_help(p, max);
      return suffixList;
    }


//---------------------------------------------------------
// QUESTION 3: what is the point of having this private seperate?

  private:
    Node *front;
    Node *back;
    int nodeCount; // track numer of nodes created for an instance of List

    void init( ) {
      front = nullptr;
      back = nullptr;
    }
};

#endif
