# SimpleTrieTemplate
## Table of Contents

1. [Objective](#objective)
2. [Outline](#outline)
    1. [General](#general)
    2. [Object Details](#object-details)
        1. [Node Class Template](#node-class-template)
        2. [Iterator Class Template](#iterator-class-template)
        4. [SimpleTrieTemplate Class Template](#simpletrietemplate-class-template)

## Objective
Create a trie that templatizes the key_types, mapped_types, number of children, and abstracts its mapping/erasing functions.

## Outline

### General
This structure finds inserted values, ie T variables, or mapped_types, by searching through the trie with respect to a key, ie K variables, or key_types.  The methodology of traversing through the trie is orchestrated by the indexer class.
The indexer is part of the template parameters, the indexer returns an index for the next child to visit relative to the current node, while making whatever, if any, modifications along the way.

### Object Details

#### Node Class Template
##### Description:
Node<typename K, typename T, uint32_t S> : the node structure used by SimpleTrieTemplate

##### Member Variables:
variable | description
---------|---------
K key_; | the key held at *this
Node* parent_; | a raw pointer to the parent Node of *this
std::optional\<T\> value_; | an optional that holds a T value, ie a mapped_type
std::vector\<std::unique_ptr\<Node\>\> child_; | a vector of Node type smart pointers that holds S number of children

##### Member Functions:
signature | description
----------|-----------
explicit Node(Node* parent = nullptr); | default constructor with defaulted parameters
explicit Node(K key, Node* parent = nullptr); | alternative constructor that takes a K key type
explicit Node(const Node& rhs); | copy constructor, copies all descendants, but not ancestor nodes
void swap(Node &rhs); | swap function, swaps all values of *this and rhs
Node& operator=(...parameters...); | takes (const Node&) and (const Node&&) parameters, assignment operator, calls swap on a copy constructor with rhs as a parameter
bool operator==(const Node& rhs); | checks for logical equivalence by comparing all member variables except for parent
bool operator!=(const Node& rhs); | returns the opposite of operator==()



#### Iterator Class Template
##### Description:
Iterator<typename K, typename T, uin32_t S> : a forwards iterator used to iterate through the nodes of the trie.  

##### Member Variables:
Nothing public, but describing the private variables might prove useful.
First, a node pointer to the node currently at.  Second, an integer value called prevIndex, which serves the purpose of navigating through nodes with varying S values.  prevIndex tells where the iterator comes from, if its -1 its comes from the parent, if greater than it comes from a child at the index of prevIndex.

##### Member Functions:
signature | description
----------|-----------
Iterator(Node\<K,T,S\> &currentNode, int32_t previousIndex = -1); | constructor
Iterator(const Iterator &rhs); | copy constructor
Node\<K,T,S\> &operator*(); | dereference operator, returns the node pointed to by the iterator
Node\<K,T,S\>* operator->(); | accessor operator, returns the address of the node pointed to by the iterator
Node\<K,T,S\>* &get(); | returns the address of the pointer to the current node
K &first(); | returns the key held by the node
std::forward_list\<T\> &second(); | returns the list of values held by the node
bool isArticleEnd(); | checks if the node is the end of an article, ie if its list is not empty
int32_t& getIndex(); | returns the prevIndex value
static int32_t findChildsIndex(const Node\<K,T,S\> &parent, const Node\<K,T,S\> &child); | returns the index of child within the child member of parent, else -1 if not found
void swap(Iterator& rhs); | swaps the values of *this and rhs
Iterator &operator=(Iterator &rhs); | assignment operator by reference, makes logically equivalent from itself onwards through the descendents, but does not assign parents
Iterator &operator=(Iterator &&rhs); | assignment operator by move, does the exact same as the assignment operator by reference
Iterator &moveUp(); | moves iterator up to its parent
Iterator &operator++(); | prefix incrementor, increments *this forwards onto the next node in order, and then returns *this
Iterator operator++(int); | postfix incrementor, increments *this forwards onto the next node in order, and returns a copy of *this prior to incrementing
bool operator==(const Iterator &rhs) const; | compares *this to rhs by logical equivalence by checking the nodes logical equivalence and then the prevIndexes: true if equivalent, false otherwise
bool operator!=(const Iterator &rhs) const; | returns the opposite of operator==()



#### SimpleTrieTemplate Class Template
##### Description:
SimpleTrieTemplate\<K,T,S,Indexer,Modifier,Eraser\> : a template for a trie data structure that stores T values, aka mapped_types (that's right, multiple, in a forward_list) at a specific K value, ie key values, ie key_types, within the trie.  The trie's nodes' all have S number of children.  The trie can be navigated through either by iterators (ie in sequential order), or via the cooperation of the indexer and modifier classes (ie via a direct node sequence).

##### Member Variables:
variable | description
---------|---------
uint32_t numberArticles_; | an integer value that's number represents the number of articles inputted to the trie
key_indexer indexer_; | the instance of Indexer used by the trie, a functor
key_eraser eraser_; | the instance of Eraser used by the trie, a functor
Node* root_; | a pointer to the first node of the trie

##### Member Functions:
signature | description
----------|-----------
explicit SimpleTrieTemplate(); | default constructor
explicit SimpleTrieTemplate(...parameters...); parameters include (const SimpleTrieTemplate& rhs) or (const SimpleTrieTemplate&& rhs) | copy constructor
SimpleTrieTemplate &operator=(...parameters...); parameters include (const SimpleTrieTemplate& rhs) or (const SimpleTrieTemplate&& rhs) | assignment operator
bool empty() const noexcept; | returns true if size() returns 0, else false
uint32_t size() const noexcept; | returns numberArticles
void clear() noexcept; | empties the trie such that empty() will return true
iterator insertOrAssign(...parameters...); parameters include (std::pair<key_type,mapped_type>& p, Node* ancestor = nullptr) or (std::pair<key_type,mapped_type>&& p, Node* ancestor = nullptr) or (key_type article, mapped_type& value, Node* ancestor = nullptr) or (key_type article, mapped_type&& value, Node* ancestor = nullptr) | So there's a lot of inserts... and they all basically do the same thing, just with different types of parameters.  In the end, they insert values at the specified article, or if the article is already present then will assign the value, and return an iterator at the end of the node sequence
void erase(key_type article,iterator ancestor = iterator()); | erases the article from the trie starting at ancestor.  If no ancestor is given, it assumes the root of the trie.
void erase(iterator& descendant, iterator ancestor = iterator()); | erases all articles between iterators
void swap(SimpleTrieTemplate& rhs); | swaps all values between *this and rhs
iterator find(key_type article); | returns an iterator at the end of the node sequence of the article within the trie, else returns end()
std::pair\<bool,iterator\> scout(key_type article,Node* ancestor = nullptr); | looks for the article, if found returns a pair where its first equals true, and second equals an iterator at the end of the article's node sequence.  Else, it returns false and an iterator at the last node in sequence that still follows the article.
bool contains(key_type article,Node* ancestor = nullptr); | returns true if the trie contains the article at ancestor, else false
bool operator==(const SimpleTrieTemplate& rhs) const; | checks for logical equivalence between *this and rhs, excluding that of indexer, modifier, and eraser
bool operator!=(const SimpleTrieTemplate& rhs) const; | returns the opposite of operator==()
iterator begin(); | returns an iterator at the first node
iterator end(); | returns an iterator one after the last node