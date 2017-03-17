#ifndef NODE_H
#define NODE_H
#include<iostream>
using namespace std;

template <typename U>
class LinkedList;

template <typename U, typename V>
struct myPair {
    U first;
    V second;
};

template <typename T>
class Node {
    T data;
    Node * next;
    public:
    Node() : next(0) {}
    Node(const T & d): next(0), data(d) {}
    Node(const T & d, const Node * N): next(N), data(d) {}
    template<typename V>
        friend class LinkedList;
    template <typename V>
        friend ostream & operator<<(ostream &, const LinkedList<V> &);

/*    template <typename V>
        friend LinkedList<V> LinkedList<V>::operator+(const LinkedList<V> &);*/
    const T & getData() const {
        return data;
    }
};
template <typename V>
class LinkedList {
    Node<V> * head;
    void clear() {
        while (head != NULL) {
            Node<V> * temp = head->next;
            delete head;
            head = temp;
        }
    }
    void copyAs(const LinkedList &B) {
        clear();
        Node<V> * it = B.head;
        Node<V> * prev;
        while (it!= NULL) {
            Node<V> * temp = new Node<V>(*it);
            temp->next = 0;
            if (head == NULL) {
                head = temp;
            }else {
                prev->next = temp;
            }
            prev = temp;
            it = it->next;
        }
    }
    Node<V> * removeSmallest() {
        if (head == NULL) {
            return NULL;
        }
        Node<V> * smallest = head;
        Node<V> * prevOfsmallest = NULL;
        Node<V> * it = head->next;
        Node<V> * prevOfit = head;
        while (it != NULL) {
            if (it->data < smallest->data) {
                smallest = it;
                prevOfsmallest = prevOfit;
            }
            prevOfit = it;
            it = it->next;
        }
        if (prevOfsmallest == NULL) {
            head = head->next;
        } else {
            prevOfsmallest->next = smallest->next;
        }
        smallest->next = 0;
        return smallest;
    }
    void insertAtSortedPosition(Node<V> * temp) {
        Node<V> * it = head;
        Node<V> * prev = NULL;
        while (it != NULL && it->data < temp->data) {
            prev = it;
            it = it->next;
        }
        if (prev != NULL) {
            temp->next = prev->next;
            prev->next = temp;
        } else {
            temp->next = head;
            head = temp;
        }
    }
    static myPair<Node<V>*, Node<V>*> reverseHelper(Node<T> * head) {
        myPair<Nodr<V> *, Node<V> *> P;
        if (head->next == NULL) {
            P.first = head; // using first for head 
            P.second = head; // using second for tail
            return P;
        }
        Node<V> * cur = head;
        head = head->next;
        cur->next = NULL;
        P = reverseHelper(head);
        P.second->next = cur;
        P.second = cur;
        return P;
    }
    public:
    LinkedList() : head(NULL) {}
    LinkedList(const LinkedList & B) : head(NULL) {
        copyAs(B);
    }
    LinkedList & operator=(const LinkedList & B) {
        copyAs(B);
        return *this;
    }
    LinkedList & operator+=(const V & el) {
        Node<V> * temp = new Node<V>(el);
        if (head == NULL) {
            head = temp;
            return *this;
        }
        Node <V> * it = head;
        while (it->next != NULL) {
            it = it->next;
        }
        it->next = temp;
        return *this;
    }
    LinkedList & operator+=(const LinkedList & B) {
        LinkedList temp(B);
        if (head == NULL) {
            head = temp.head;
            temp.head = 0;
            return *this;
        }
        Node<V> * it = head;
        while (it->next != NULL) {
            it = it->next;
        }
        it->next = temp.head;
        temp.head = 0;
        return *this;
    }
    void printList() const {
        Node<V> * it = head;
        while (it != NULL) {
            cout << it->data <<"-->";
            it = it->next;
        }
        cout << "NULL" << endl;
    }
    ~LinkedList() {
        cout << " Destructor of LinkedList called" << endl;
        clear();
        return;
    }
    LinkedList operator+(const LinkedList & );
    void reverse() {
        if (head == NULL || head->next == NULL) {
            return;
        }
        
        myPair<Node<V> *, Node<V> *> P = reverseHelper(head);
        head = P.first;
    }
    /*
    // Function which returns length of the linked list
    int length() {
    }
    // function which returns address of Kth Node - returns NULL if K is out of Bound
    Node * findKthElement() {
    }
    // Swap ith and Jth Node of the linked list - Swap Nodes not the data. Do nothing if I or J are out of bounds
    void swap(int i, int j) {
    }
    // Sort the linked list using selection sort. You need to change next pointers in the data without using any array.
    void selectionsort() {
        Node<V> * newhead = NULL;
        Node<V> * prev;
        while(head != NULL) {
            Node<V> * smallest = removeSmallest();
            if (newhead == NULL) {
                newhead = smallest; 
            } else {
                prev->next = smallest;
            }
            prev = smallest;
        }
        head = newhead;
    }
    void insertSort() {
        Node<V> * unsortedHead = head;
        head = 0;
        while (unsortedHead != NULL) {
            Node<V> * temp = unsortedHead;
            unsortedHead = unsortedHead->next;
            temp->next = 0;
            insertAtSortedPosition(temp);
        }
    }
    Node<V> * findMidPoint() {
        Node<V> * it1, *it2;
        it1 = it2 = head;
        while (it2 && it2->next) {
            it1 = it1->next;
            it2 = (it2->next)->next;
        }
        return it1;
    }
    void convertAnBn() {
        Node<V> * it1 = head;
        Node<V> * it2 = findMidPoint();
        while (it2 != NULL) {
            Node<V> * temp = it1->next;
            it1->next = it2;
            Node<V> * temp2 = it2->next;
            if (temp2 != NULL) {
                it2->next = temp;
            }
            it1 = temp;
            it2 = temp2;
        }
    }
    template <typename T>
        friend ostream & operator<<(ostream &, const LinkedList<T> &);

/*
    // Returns address of the mid node of the linked list
    Node * findMidPoint() {
    }

    // Returns true if elements in the linked list make it palindrome for e.g: 1->13->4->5->4->13->1
    bool checkIfPalindrome() {
    }

    // Rearrange the nodes such that all even elements are after odd elements. Again you need change next pointers not the data
    void arrangeOddElementsAfterEvenElements() {
    }

    // Rotate Linked List By K. You need to clockwise rotate the linked list by K. E.g. 1->2->3->4->5->6null and if K was 2 linked list should become 5->6->1->2->3->4->null
    void rotateClockWise(int K) {
    }

    // K reverse the linked list i.e. you reverse first K elements then reverse next K elements and join the linked list and so on.
    // For e.g. 3->4->5->2->6->1->9->10->NULL, and For K = 3 should become 5->4->3->1->6->2->10->9->NULL
    void kReverse(int K) {
    }

    // Remove Duplicates From the sortedList.
    // This function assumes the linked list is sorted and deletes duplicated nodes from the linked list.
    void removeDuplicatesFromSorted() {
    }
*/
};
template <typename T>
LinkedList<T> LinkedList<T>::operator+(const LinkedList<T> & B) {
    LinkedList temp(*this);
    temp+=B;
    return temp;
}
template <typename T>
ostream & operator<<(ostream & obj, const LinkedList<T> & L) {
    const Node<T> * it = L.head;
    while(it != NULL) {
        obj << it->data << "-->";
        it = it->next;
    }
    return obj;
}
#endif
