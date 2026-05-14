/* =========================================================

Practical Name: Smallest Missing Non-Negative Number
File Name: missingnum.cpp

Problem:
Given a sorted array of distinct non-negative integers, find the smallest missing non-negative number using binary search.

Main Idea:
In a correct sequence, array value and index should be same.
Example:
Index: 0 1 2 3 4
Array: 0 1 2 6 9
At index 3, value should be 3, but value is 6.
So the missing number is 3.

Line/Logic Explanation:
#include <iostream>
This header file is used for cin and cout.

using namespace std;
This allows direct use of cin and cout without writing std::.

int arr[50];
This stores array elements.

int n;
This stores number of elements.

Input loop:
for loop is used to take all array elements from user.

int low = 0;
This points to the starting index of array.

int high = n - 1;
This points to the last index of array.

int ans = n;
If no number is missing inside the array, then answer will be n.

while(low <= high)
This loop performs binary search.

mid = (low + high) / 2;
This finds middle index.

if(arr[mid] == mid)
This means elements are correct up to mid, so missing element is on right side.

low = mid + 1;
Move search to right side.

else
This means mismatch found, so missing number may be mid or before mid.

ans = mid;
Store possible answer.

high = mid - 1;
Move search to left side to check smaller missing number.

Finally:
cout << ans;
Prints smallest missing non-negative number.

Memory Trick:
Index same as value means go right.
Index different from value means save answer and go left.
========================================================= */

/* =========================================================
2. Practical Name: Count Occurrences using Binary Search
File Name: countocc.cpp

Problem:
Given a sorted array with duplicate values, count how many times a given number occurs.

Main Idea:
Find first occurrence of key.
Find last occurrence of key.
Count = last - first + 1.

Line/Logic Explanation:
int arr[50];
Stores array elements.

int n, key;
n stores number of elements.
key stores number to be searched.

firstSearch function:
This function finds the first position of key.

int L = 0, R = n - 1;
L is starting index.
R is ending index.

int ans = -1;
If key is not found, answer remains -1.

while(L <= R)
Binary search loop.

M = (L + R) / 2;
Find middle index.

if(key == arr[M])
Key is found at mid.

ans = M;
Store current position.

R = M - 1;
Move left because first occurrence may be before mid.

else if(key > arr[M])
Key is greater, so search right side.

L = M + 1;
Move to right.

else
Key is smaller, so search left side.

R = M - 1;
Move to left.

lastSearch function:
Same as firstSearch, but after finding key it moves right.

L = M + 1;
This is used to find last occurrence.

In main:
First occurrence and last occurrence are found.

if(first == -1)
Element is not present.

else
count = last - first + 1;
This gives total occurrences.

Memory Trick:
First occurrence: found then go left.
Last occurrence: found then go right.
Count = last - first + 1.
========================================================= */

/* =========================================================
3. Practical Name: Find Middle Node of Linked List
File Name: midnode.cpp

Problem:
Find middle node of singly linked list.
If nodes are even, return second middle node.

Main Idea:
Count total nodes.
Middle position = count / 2 + 1.
Go to that position and print data.

Line/Logic Explanation:
class Node
Creates node structure for linked list.

int data;
Stores value of node.

Node* next;
Stores address of next node.

Node* head = NULL;
Head points to first node.
Initially list is empty.

create_list()
Creates linked list.

Node* NN = new Node;
Creates new node dynamically.

cin >> NN->data;
Takes data for node.

NN->next = NULL;
New node points to NULL initially.

if(head == NULL)
If list is empty, first node becomes head.

else
If list already has nodes, go to last node.

while(ptr->next != NULL)
Moves pointer until last node.

ptr->next = NN;
Adds new node at end.

display()
Prints all nodes one by one.

find_middle()
Finds middle node.

int count = 0;
Counts total nodes.

while(ptr != NULL)
Traverses full linked list.

count++;
Increases node count.

middle = count / 2 + 1;
Finds middle position.
For even nodes, this gives second middle.

ptr = head;
Starts again from first node.

for(i = 1; i < middle; i++)
Moves pointer up to middle node.

cout << ptr->data;
Prints middle node data.

Memory Trick:
Count nodes, middle = count/2 + 1, go to middle.
========================================================= */

/* =========================================================
4. Practical Name: Delete Middle Node of Linked List
File Name: delmiddle.cpp

Problem:
Delete middle node from singly linked list.

Main Idea:
Count total nodes.
Find middle position.
Go to node before middle.
Skip middle node and delete it.

Line/Logic Explanation:
Node class, data, next, and head are same as normal linked list.

create_list()
Creates linked list by inserting node at end.

display()
Displays linked list.

delete_middle()
Deletes middle node.

if(head == NULL)
Checks if list is empty.

if(head->next == NULL)
If only one node is present, delete head.

delete head;
Deletes only node.

head = NULL;
List becomes empty.

count loop:
Counts total number of nodes.

middle = count / 2 + 1;
Finds middle position.
For even nodes, this chooses second middle.

ptr = head;
Starts from first node.

for(i = 1; i < middle - 1; i++)
Moves pointer to node before middle.

Node* temp = ptr->next;
temp points to middle node.

ptr->next = temp->next;
Previous node now points to node after middle.
This skips middle node.

delete temp;
Deletes middle node from memory.

Memory Trick:
Count, middle, previous, skip, delete.
========================================================= */

/* =========================================================
5. Practical Name: Insert Second List into First List at Alternate Positions
File Name: altinsert.cpp

Problem:
Insert nodes of second linked list into first linked list at alternate positions.
Second list becomes empty if all its nodes are inserted.

Main Idea:
Take one node from second list and insert after one node of first list.

Line/Logic Explanation:
Node class is same as linked list.

Node* head1 = NULL;
Head pointer for first list.

Node* head2 = NULL;
Head pointer for second list.

create_list(Node*& head)
Creates linked list for whichever head is passed.

Node*& head
Reference to head, so function can change head1 or head2.

display(Node* head)
Displays selected linked list.

alternate_insert()
Performs alternate insertion.

Node* ptr1 = head1;
ptr1 points to first list.

Node* ptr2 = head2;
ptr2 points to second list.

while(ptr1 != NULL && ptr2 != NULL)
Runs until either first list or second list ends.

temp1 = ptr1->next;
Stores next node of first list.

temp2 = ptr2->next;
Stores next node of second list.

ptr1->next = ptr2;
Connect current first-list node to current second-list node.

ptr2->next = temp1;
Connect second-list node back to remaining first list.

ptr1 = temp1;
Move pointer in first list.

ptr2 = temp2;
Move pointer in second list.

head2 = ptr2;
Remaining second list is updated.
If all inserted, head2 becomes NULL.

Memory Trick:
Save both nexts, insert second after first, connect back, move.
========================================================= */

/* =========================================================
6. Practical Name: Queue using Linked List
File Name: queueLL.cpp

Problem:
Implement queue using linked list.

Main Idea:
Queue follows FIFO.
Insertion is from rear.
Deletion is from front.

Line/Logic Explanation:
class Node
Creates linked-list node.

int data;
Stores queue data.

Node* next;
Stores next node address.

Node* front = NULL;
Points to first node of queue.

Node* rear = NULL;
Points to last node of queue.

enqueue()
Adds new element at rear.

Node* NN = new Node;
Creates new node.

NN->next = NULL;
New node will be last node.

if(front == NULL && rear == NULL)
Queue is empty.

front = NN;
rear = NN;
First node becomes both front and rear.

else
Queue already has nodes.

rear->next = NN;
Old rear points to new node.

rear = NN;
New node becomes rear.

dequeue()
Deletes element from front.

if(front == NULL)
Queue is empty.

Node* temp = front;
Store front node in temp.

front = front->next;
Move front to next node.

if(front == NULL)
If queue becomes empty, rear should also become NULL.

rear = NULL;
Updates rear for empty queue.

delete temp;
Deletes old front node.

display()
Prints from front to rear.

Memory Trick:
Enqueue rear, dequeue front.
========================================================= */

/* =========================================================
7. Practical Name: Move Last Node to Front
File Name: lastfront.cpp

Problem:
Move last node of singly linked list to front.

Main Idea:
Find last node and second-last node.
Cut last node.
Attach last node before head.
Make last node new head.

Line/Logic Explanation:
Node class and create_list are same as linked list.

move_last_to_front()
Moves last node to beginning.

if(head == NULL)
Checks empty list.

if(head->next == NULL)
If only one node is present, no change needed.

Node* prev = NULL;
This will store node before last node.

Node* last = head;
This will move to last node.

while(last->next != NULL)
Loop runs until last reaches final node.

prev = last;
Stores previous node.

last = last->next;
Moves last pointer ahead.

prev->next = NULL;
Second-last node becomes last node.

last->next = head;
Old last node points to old head.

head = last;
Old last node becomes new head.

Memory Trick:
Go to last, cut it, put it before head.
========================================================= */

/* =========================================================
8. Practical Name: Get Nth Node from Linked List
File Name: getnth.cpp

Problem:
Return data at given index in linked list.
Index starts from 0.

Main Idea:
Start count from 0.
Move pointer one by one.
When count equals index, print node data.

Line/Logic Explanation:
Node class and create_list are same as linked list.

getNth()
Finds data at given index.

int index;
Stores index entered by user.

Node* ptr = head;
Starts from first node.

int count = 0;
Index counting starts from 0.

while(ptr != NULL)
Traverses linked list.

if(count == index)
Required node is found.

cout << ptr->data;
Prints data at that index.

return;
Stops function after finding node.

count++;
Increases index count.

ptr = ptr->next;
Moves to next node.

If loop ends without finding:
Index is invalid.

Memory Trick:
Count from 0, move node by node, print when count equals index.
========================================================= */

/* =========================================================
9. Practical Name: Reverse String using Stack
File Name: reversestac.cpp

Problem:
Reverse a string using stack.

Main Idea:
Stack follows LIFO.
Push all characters.
Pop all characters.
Popped characters form reverse string.

Line/Logic Explanation:
class Stack
Creates stack.

char st[50];
Array used to store characters.

int top;
Stores position of top element.

Stack()
Constructor initializes top.

top = -1;
Means stack is empty.

push(char ch)
Adds character to stack.

top++;
Moves top upward.

st[top] = ch;
Stores character at top.

pop()
Removes and returns top character.

char ch = st[top];
Stores top character.

top--;
Moves top downward.

return ch;
Returns removed character.

isEmpty()
Checks whether stack is empty.

if(top == -1)
Stack is empty.

In main:
string str stores original string.
string rev stores reversed string.

for loop:
Pushes each character of string into stack.

while(!s.isEmpty())
Runs until stack becomes empty.

rev = rev + s.pop();
Adds popped character to reverse string.

Memory Trick:
Push full string, pop reverse string.
========================================================= */

/* =========================================================
10. Practical Name: Remove Characters from First String
File Name: removechar.cpp

Problem:
Remove characters from first string which are present in second string.

Main Idea:
Take one character from first string.
Search it in second string.
If found, skip it.
If not found, add to result.

Line/Logic Explanation:
string str1;
Stores first string.

string str2;
Stores second string.

string result = "";
Stores final output string.

for(int i = 0; i < str1.length(); i++)
Takes each character from first string.

int found = 0;
Assume current character is not found in second string.

for(int j = 0; j < str2.length(); j++)
Search current character in second string.

if(str1[i] == str2[j])
Character is found in second string.

found = 1;
Mark as found.

break;
Stop inner loop.

if(found == 0)
Character is not present in second string.

result = result + str1[i];
Add character to answer.

Finally:
cout << result;
Prints string after removing characters.

Memory Trick:
First string gives character, second string checks character.
Found means remove, not found means keep.
========================================================= */

/* =========================================================
11. Practical Name: Bubble Sort after Three Passes
File Name: bubble3pass.cpp

Problem:
Print array after three complete passes of bubble sort.

Main Idea:
Bubble sort compares adjacent elements.
If left element is greater than right element, swap them.
Only three passes are performed.

Line/Logic Explanation:
int arr[50];
Stores numbers.

int n;
Stores total elements.

Input loop:
Takes array elements.

Outer loop:
for(int i = 0; i < 3; i++)
Runs only 3 passes.

Inner loop:
for(int j = 0; j < n - i - 1; j++)
Compares adjacent elements.

if(arr[j] > arr[j + 1])
Checks if elements are in wrong order.

temp = arr[j];
Stores first element temporarily.

arr[j] = arr[j + 1];
Moves smaller element left.

arr[j + 1] = temp;
Moves larger element right.

Display loop:
Prints array after 3 passes.

Memory Trick:
Bubble sort means adjacent compare and swap.
Three passes means outer loop runs 3 times only.
========================================================= */

/* =========================================================
12. Practical Name: Book Search by Author
File Name: bookauthor.cpp

Problem:
Search book records by author name using linear search.

Main Idea:
Create array of Book objects.
Take author name as key.
Compare key with each book author.

Line/Logic Explanation:
class Book
Creates book record.

string title;
Stores book title.

string author;
Stores author name.

string publication;
Stores publication name.

int price;
Stores price.

setd()
Takes book details from user.

getd()
Displays book details.

Book b[50];
Stores multiple book records.

int n;
Stores number of books.

string key;
Stores author name to search.

int found = 0;
Used to check whether book is found or not.

Input loop:
Takes details of n books.

Search loop:
for(int i = 0; i < n; i++)
Checks each book one by one.

if(b[i].author == key)
Author matches.

b[i].getd();
Display matching book.

found = 1;
Mark that book is found.

if(found == 0)
No book matched.

cout << "Book not found";
Print not found message.

Memory Trick:
Book author search = array of Book + compare author.
========================================================= */

/* =========================================================
13. Practical Name: Railway Network Database
File Name: railwaydb.cpp

Problem:
Store railway information such as stations, tracks, train ID, train name, and schedule.

Main Idea:
Use class array to store railway records.
Each object stores one railway record.

Line/Logic Explanation:
class Railway
Creates railway record.

string station1;
Stores first station.

string station2;
Stores second station.

int trainId;
Stores train number or ID.

string trainName;
Stores train name.

string time;
Stores schedule time.

setd()
Takes railway record input.

getd()
Displays railway record.

Railway r[50];
Stores multiple railway records.

int n;
Stores number of records.

Input loop:
Takes n railway records.

Display loop:
Displays all railway records.

Memory Trick:
Railway record = station1, station2, trainId, trainName, time.
========================================================= */

/* =========================================================
14. Practical Name: Car Rental System using Selection Sort
File Name: carsort.cpp

Problem:
Arrange cars according to price in ascending order using selection sort.

Main Idea:
Selection sort selects minimum price and places it at current position.

Line/Logic Explanation:
class Car
Creates car record.

string name;
Stores car name.

int price;
Stores rental price.

setd()
Takes car details.

getd()
Displays car details.

Car c[50];
Stores car records.

int n;
Stores number of cars.

Outer loop:
for(int i = 0; i < n - 1; i++)
Selects position where minimum should be placed.

int min = i;
Assume current position has minimum price.

Inner loop:
for(int j = i + 1; j < n; j++)
Searches for smaller price in remaining list.

if(c[j].price < c[min].price)
If smaller price found.

min = j;
Update minimum index.

Swapping:
Car temp = c[i];
c[i] = c[min];
c[min] = temp;

This places minimum price car at current position.

Memory Trick:
Selection sort = select minimum and swap.
========================================================= */

/* =========================================================
15. Practical Name: Patient Record Sorting using Bubble Sort
File Name: patientsort.cpp

Problem:
Arrange patients according to names in alphabetical order using bubble sort.

Main Idea:
Compare adjacent patient names.
If left name is alphabetically greater, swap records.

Line/Logic Explanation:
class Patient
Creates patient record.

string name;
Stores patient name.

int age;
Stores patient age.

string disease;
Stores disease name.

setd()
Takes patient details.

getd()
Displays patient details.

Patient p[50];
Stores patient records.

Outer loop:
for(int i = 0; i < n - 1; i++)
Controls number of passes.

Inner loop:
for(int j = 0; j < n - i - 1; j++)
Compares adjacent patient records.

if(p[j].name > p[j + 1].name)
Checks alphabetical order.

Patient temp = p[j];
Temporarily stores first patient.

p[j] = p[j + 1];
Second patient comes before first.

p[j + 1] = temp;
First patient moves after second.

Display loop:
Displays sorted patient records.

Memory Trick:
Bubble sort names = compare side-by-side and swap.
========================================================= */

/* =========================================================
16. Practical Name: Balanced Brackets using Stack
File Name: bracketstk.cpp

Problem:
Check whether brackets (), {}, [] are balanced or not.

Main Idea:
Opening bracket is pushed into stack.
Closing bracket is matched with stack top.
If matched, pop.
At end, stack should be empty.

Line/Logic Explanation:
class Stack
Creates stack.

char st[50];
Stores brackets.

int top;
Stores top position.

push()
Adds opening bracket.

pop()
Removes top bracket.

peek()
Returns top bracket without removing.

isEmpty()
Checks stack empty or not.

string str;
Stores bracket expression.

int flag = 1;
Assume expression is balanced.

Loop:
Checks each character.

if(ch == '(' || ch == '{' || ch == '[')
Opening bracket is found.

s.push(ch);
Push opening bracket.

else if closing bracket is found:
First check stack empty or not.

if(s.isEmpty())
Closing bracket came without opening bracket, so not balanced.

topChar = s.peek();
Stores top bracket.

If closing bracket matches top opening bracket:
s.pop();
Remove matched opening bracket.

else:
flag = 0;
Expression is not balanced.

Final condition:
if(flag == 1 && s.isEmpty())
Balanced.

else
Not balanced.

Memory Trick:
Open bracket push.
Close bracket check top and pop.
End stack empty means balanced.
========================================================= */

/* =========================================================
17. Practical Name: Next Greater Element
File Name: nextgreater.cpp

Problem:
For each element in array, find first element to its right that is greater than it.

Main Idea:
For every element, check elements on right side one by one.
First greater element found is printed.
If not found, print -1.

Line/Logic Explanation:
int arr[50];
Stores array elements.

int n;
Stores number of elements.

Input loop:
Takes array elements.

Outer loop:
for(int i = 0; i < n; i++)
Selects one element.

int greater = -1;
Assume no greater element found.

Inner loop:
for(int j = i + 1; j < n; j++)
Checks elements to the right.

if(arr[j] > arr[i])
First greater element is found.

greater = arr[j];
Store that greater element.

break;
Stop because first greater element is required.

cout << arr[i] << " -> " << greater;
Print current element and its next greater element.

Memory Trick:
Pick one element, look right, first bigger is answer.
========================================================= */

/* =========================================================
18. Practical Name: Inventory Lookup using Linear Search
File Name: prodsearch.cpp

Problem:
Search product ID in retail store inventory using linear search.

Main Idea:
Product IDs are stored in array.
Cashier enters target product ID.
Program checks IDs one by one.

Line/Logic Explanation:
int product[50];
Stores product IDs.

int n;
Stores number of products.

int key;
Stores product ID to search.

int found = 0;
Used to check whether product exists.

Input loop:
Takes product IDs.

Search loop:
for(int i = 0; i < n; i++)
Checks each product ID.

if(product[i] == key)
Product ID matches.

found = 1;
Product found.

break;
Stop searching.

if(found == 1)
Print Product found.

else
Print Product not found.

Memory Trick:
Linear search = check from first to last.
========================================================= */

/* =========================================================
19. Practical Name: Checkout Product Code Search
File Name: itemsearch.cpp

Problem:
Search entered product code in unsorted list using linear search.

Main Idea:
Since list is unsorted, binary search cannot be used.
Use linear search.

Line/Logic Explanation:
int code[50];
Stores product codes.

int n;
Stores number of product codes.

int key;
Stores entered product code.

int found = 0;
Initially item is not found.

Input loop:
Takes product codes.

Search loop:
Checks every code one by one.

if(code[i] == key)
Entered code matches list code.

found = 1;
Item found.

break;
Stop loop.

if(found == 1)
Print Item Found.

else
Print Item Not Found.

Memory Trick:
Unsorted list means linear search.
========================================================= */

/* =========================================================
20. Practical Name: Cinema Seat Availability using Binary Search
File Name: seatsearch.cpp

Problem:
Check if chosen seat is available from sorted seat list using binary search.

Main Idea:
Seat numbers are sorted.
Use binary search to find chosen seat.

Line/Logic Explanation:
int seat[50];
Stores sorted available seat numbers.

int n;
Stores number of seats.

int key;
Stores chosen seat.

int L, R, M;
L is left index.
R is right index.
M is middle index.

int found = 0;
Initially seat is not found.

L = 0;
Start from first index.

R = n - 1;
End at last index.

while(L <= R)
Binary search loop.

M = (L + R) / 2;
Find middle seat.

if(key == seat[M])
Chosen seat found.

found = 1;
Seat is available.

break;
Stop searching.

else if(key > seat[M])
Chosen seat is greater than middle seat.

L = M + 1;
Search right side.

else
Chosen seat is smaller than middle seat.

R = M - 1;
Search left side.

if(found == 1)
Print Seat Available.

else
Print Already Booked.

Memory Trick:
Sorted list means binary search.
Middle check, bigger go right, smaller go left.
========================================================= */

/* =========================================================
21. Practical Name: Polynomial Addition using Linked List
File Name: polyadd.cpp

Problem:
Add two polynomials using singly linked list.

Main Idea:
Each polynomial term is stored as one node.
Each node has coefficient, power, and next pointer.
If powers are same, add coefficients.
If powers are different, copy bigger power term.

Line/Logic Explanation:
class Node
Creates polynomial node.

int coeff;
Stores coefficient.

int power;
Stores power of x.

Node* next;
Stores address of next term.

Node* p = NULL;
Head of first polynomial.

Node* q = NULL;
Head of second polynomial.

Node* r = NULL;
Head of result polynomial.

insert(Node*& head, int c, int pow)
Adds one polynomial term at end.

NN->coeff = c;
Stores coefficient.

NN->power = pow;
Stores power.

NN->next = NULL;
New term points to NULL.

If head is NULL:
New node becomes first term.

Else:
Traverse to last term and attach new node.

display(Node* head)
Prints polynomial terms.

addPoly()
Adds both polynomials.

ptr1 = p;
Points to first polynomial.

ptr2 = q;
Points to second polynomial.

while(ptr1 != NULL && ptr2 != NULL)
Runs while both polynomials have terms.

if(ptr1->power == ptr2->power)
Same power terms are added.

insert(r, ptr1->coeff + ptr2->coeff, ptr1->power);
Adds result term.

ptr1 = ptr1->next;
ptr2 = ptr2->next;
Move both pointers.

else if(ptr1->power > ptr2->power)
First polynomial power is bigger.

insert(r, ptr1->coeff, ptr1->power);
Copy first term.

ptr1 = ptr1->next;
Move first pointer.

else
Second polynomial power is bigger.

insert(r, ptr2->coeff, ptr2->power);
Copy second term.

ptr2 = ptr2->next;
Move second pointer.

Remaining while loops:
Copy leftover terms from any polynomial.

Memory Trick:
Same power add coefficient.
Bigger power copy directly.
========================================================= */

/* =========================================================
22. Practical Name: Postfix Evaluation using Stack
File Name: postfixeval.cpp

Problem:
Evaluate postfix expression using stack.

Main Idea:
If character is digit, push it.
If character is operator, pop two values, calculate, push answer.

Line/Logic Explanation:
class Stack
Creates integer stack.

int st[50];
Stores operands and answers.

int top;
Stores top index.

top = -1;
Stack is empty.

push(int x)
Adds number to stack.

pop()
Removes and returns top number.

string exp;
Stores postfix expression.

for loop:
Reads expression character by character.

char ch = exp[i];
Stores current character.

if(ch >= '0' && ch <= '9')
Checks if character is digit.

s.push(ch - '0');
Converts character digit to integer and pushes it.

else
Character is operator.

b = s.pop();
First popped value becomes second operand.

a = s.pop();
Second popped value becomes first operand.

if(ch == '+')
ans = a + b;

else if(ch == '-')
ans = a - b;

else if(ch == '*')
ans = a * b;

else if(ch == '/')
ans = a / b;

s.push(ans);
Push result back to stack.

At end:
s.pop() gives final answer.

Memory Trick:
Digit push.
Operator pop two, solve, push answer.
========================================================= */

/* =========================================================
23. Practical Name: Patient Queue using Array
File Name: patientq.cpp

Problem:
Manage patient queue using queue data structure.
Create queue with 5 patients.
Add 2 new patients.
Remove 2 old patients.
Display after each operation.

Main Idea:
Queue follows FIFO.
Patient added at rear.
Patient removed from front.

Line/Logic Explanation:
class Queue
Creates queue.

string q[20];
Stores patient names.

int front;
Points to first patient.

int rear;
Points to last patient.

front = -1;
rear = -1;
Queue is initially empty.

enqueue(string name)
Adds patient to queue.

if(rear == 19)
Queue is full.

if(front == -1)
First patient is being added.

front = 0;
Set front to first position.

rear++;
Move rear ahead.

q[rear] = name;
Store patient name.

dequeue()
Removes old patient.

if(front == -1 || front > rear)
Queue is empty.

cout << q[front];
Displays removed patient.

front++;
Moves front to next patient.

display()
Prints queue from front to rear.

for(int i = front; i <= rear; i++)
Displays all patients in order.

Memory Trick:
New patient added at rear.
Old patient removed from front.
========================================================= */



/* =========================================================
24. Practical Name: Browser History using Stack
File Name: browserstk.cpp

Problem:
Manage browser history using stack.
Visited pages are pushed.
Back operation removes last visited page.

Main Idea:
Browser history follows LIFO.
Last visited page is removed first.

Line/Logic Explanation:
class Stack
Creates stack.

string st[50];
Stores page names.

int top;
Stores top position.

top = -1;
History is empty.

push(string page)
Adds visited page.

top++;
Move top upward.

st[top] = page;
Store page at top.

pop()
Performs back operation.

if(top == -1)
History is empty.

else
Print current top page and remove it.

top--;
Moves back to previous page.

display()
Shows browser history.

for(int i = top; i >= 0; i--)
Displays latest page first.

In main:
Take number of visited pages.

For each page:
cin >> page;
s.push(page);

After visiting:
display history.

Back operation:
s.pop();

After back:
display updated history.

Memory Trick:
Visit page means push.
Back button means pop.
========================================================= */
