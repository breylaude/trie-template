//
// Created by Ignas Laude on 5/30/21.
//

#include <iostream>
#include <map>
#include "../include/triemplate.h"
#include "../include/DefaultParameters.h"

template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
void run_standard_tests(triemplate<K, T, S, Indexer, Eraser> &trie, std::list<std::pair<K,T>>& inserts);

std::list<std::pair<int32_t,char32_t>> generate_default_inputs(uint32_t num);

void run_default_tests();

void print_message(const std::string& s);

//region //STANDARD FUNCTION DECLARATION

//region //CONSTRUCTOR
template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
void constructor_default_tests();
    template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
    std::string constructor_default_empty();
    template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
    std::string constructor_default_beginIsEnd();
    template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
    std::string constructor_default_equalInstants();

//endregion

//region //COPY CONST
template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
void constructor_copy_tests(const std::list<std::pair<K,T>>& inserts);
    template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
    std::string constructor_copy_equal(triemplate<K,T,S,Indexer,Eraser>& og, uint32_t count);
    template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
    std::string constructor_copy_diffOGs(std::list<std::pair<K,T>> inserts);
    template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
    std::string constructor_copy_notByRef(std::list<std::pair<K,T>> inserts);

//endregion

//region //ASSIGN
template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
void assignment_tests(const std::list<std::pair<K,T>>& inserts);
    template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
    std::string assign_diffOnesAndDiffOthers(const std::list<std::pair<K,T>>& inserts);
    template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
    std::string assign_oneEqualOther(triemplate<K,T,S,Indexer,Eraser>& one, triemplate<K,T,S,Indexer,Eraser>& other, uint32_t cnt);
    template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
    std::string assign_notByRef(const std::list<std::pair<K,T>>& inserts);
//endregion

//region //EMPTY
template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
void empty_tests(const std::list<std::pair<K,T>>& inserts);
    template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
    std::string empty_checksValid_cases(std::list<std::pair<K,T>> inserts);
    template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
    std::string empty_checksValid(triemplate<K,T,S,Indexer,Eraser> &trie, bool isEmpty, uint32_t cnt);

//endregion

//region //SIZE
template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
void size_tests(const std::list<std::pair<K,T>>& inserts);
    template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
    std::string size_checksValid_cases(std::list<std::pair<K,T>> inserts);
    template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
    std::string size_checkValid(triemplate<K,T,S,Indexer,Eraser> &trie, uint32_t correctCnt, uint32_t cnt);

//endregion

//region //CLEAR
template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
void clear_tests(const std::list<std::pair<K,T>>& inserts);
    template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
    std::string clear_diffCases(std::list<std::pair<K,T>> inserts);
    template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
    std::string clear_properOut(triemplate<K,T,S,Indexer,Eraser> &trie, uint32_t cnt);
    template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
    std::string clear_multiple(const std::list<std::pair<K,T>>& inserts);
    template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
    std::string clear_empty_empty();
    template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
    std::string clear_filled_empty(std::list<std::pair<K,T>> inserts);
    template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
    std::string clear_empty_filled(std::list<std::pair<K,T>> inserts);
    template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
    std::string clear_filled_filled(std::list<std::pair<K,T>> inserts);

//endregion

//region //INSERT
template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
void insert_tests(const std::list<std::pair<K,T>>& inserts);
    template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
    std::string insert_pairTypeRef(std::list<std::pair<K,T>> inserts);
    template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
    std::string insert_pairTypeRef_empty(std::pair<K,T> p);
    template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
    std::string insert_pairTypeRef_filled(triemplate<K,T,S,Indexer,Eraser> &trie, std::pair<K,T> p);

    template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
    std::string insert_pairTypeVal(std::list<std::pair<K,T>> inserts);
    template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
    std::string insert_pairTypeVal_empty(std::pair<K,T> p);
    template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
    std::string insert_pairTypeVal_filled(triemplate<K,T,S,Indexer,Eraser> &trie, std::pair<K,T> p);

    template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
    std::string insert_typeRef(std::list<std::pair<K,T>> inserts);
    template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
    std::string insert_typeRef_empty(std::pair<K,T> p);
    template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
    std::string insert_typeRef_filled(triemplate<K,T,S,Indexer,Eraser> &trie, std::pair<K,T> p);

    template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
    std::string insert_typeVal(std::list<std::pair<K,T>> inserts);
    template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
    std::string insert_typeVal_empty(std::pair<K,T> p);
    template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
    std::string insert_typeVal_filled(triemplate<K,T,S,Indexer,Eraser> &trie, std::pair<K,T> p);

//endregion

//region //ERASE
template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
void erase_tests(const std::list<std::pair<K,T>>& inserts);
    template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
    std::string erase_key(std::list<std::pair<K,T>> inserts);
    template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
    std::string erase_key_diffCases(triemplate<K,T,S,Indexer,Eraser> &trie, K key, bool validKey, uint32_t cnt);

//endregion

//region //SWAP
template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
void swap_tests(const std::list<std::pair<K,T>>& inserts);
    template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
    std::string swap_oneAndOther(triemplate<K,T,S,Indexer,Eraser> &one, triemplate<K,T,S,Indexer,Eraser> &other, uint32_t cnt);

//endregion

//region //FIND
template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
void find_tests(std::list<std::pair<K,T>> inserts);
    template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
    std::string find_keyInTrie(triemplate<K,T,S,Indexer,Eraser> &trie, K key, bool valid, uint32_t cnt);

//endregion

//region //SCOUT
template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
void scout_tests(std::list<std::pair<K,T>> inserts);
    template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
    std::string scout_keyInTrie(triemplate<K,T,S,Indexer,Eraser> &trie, K key, bool valid, uint32_t cnt);

//endregion

//region //CONTAINS
template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
void contains_tests(std::list<std::pair<K,T>> inserts);
    template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
    std::string contains_keyInTrie(triemplate<K,T,S,Indexer,Eraser> &trie, K key, bool valid, uint32_t cnt);

//endregion

//region //ITERATOR
void iterator_tests();
    std::string iterator_empty();
    std::string iterator_empty_beginIsEnd();
    std::string iterator_filled_diffCases(triemplate<int32_t,char32_t> &trie, std::map<int32_t,char32_t> &map, int32_t cnt);

//endregion

//endregion

int main() {
    std::list<std::pair<std::string,bool>> list;
    list.push_front(std::pair<std::string,bool>("HELLO",true));
    list.push_front(std::pair<std::string,bool>("BEE",false));
    list.push_front(std::pair<std::string,bool>("BE",false));
    list.push_front(std::pair<std::string,bool>("BEE",true));
    list.push_front(std::pair<std::string,bool>("BIN",true));
    list.push_front(std::pair<std::string,bool>("HELL",false));
    list.push_front(std::pair<std::string,bool>("HI",true));
    list.push_front(std::pair<std::string,bool>("AY",false));
    list.push_front(std::pair<std::string,bool>("HEIGHTS",false));
    list.push_front(std::pair<std::string,bool>("HEIGHT",true));

    triemplate<std::string,bool,26,Radix_Indexer<bool>,Radix_Eraser<bool>> text_trie;

    std::cout << "RADIX TRIE TESTS:\n";
    run_standard_tests(text_trie,list);
    std::cout << "\n\n";

//    while (!list.empty()) {
//        if (list.front().first == "BIN") {
//            std::cout << "";
//        }
//        text_trie.insert(list.front());
//        list.pop_front();
//    }
//
//    for (auto i(text_trie.begin()); i != text_trie.end(); ++i) {
//        if (i.isArticleEnd())
//            std::cout << i->key << std::endl;
//    }

    std::cout << "DEFAULT TESTS:\n";
    run_default_tests();
    return 0;
}

template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
void run_standard_tests(triemplate<K,T,S,Indexer,Eraser>& trie, std::list<std::pair<K,T>>& inserts) {
    constructor_default_tests<K,T,S,Indexer,Eraser>();
    constructor_copy_tests<K,T,S,Indexer,Eraser>(inserts);
    assignment_tests<K,T,S,Indexer,Eraser>(inserts);
    empty_tests<K,T,S,Indexer,Eraser>(inserts);
    size_tests<K,T,S,Indexer,Eraser>(inserts);
    clear_tests<K,T,S,Indexer,Eraser>(inserts);
    insert_tests<K,T,S,Indexer,Eraser>(inserts);
    erase_tests<K,T,S,Indexer,Eraser>(inserts);
    swap_tests<K,T,S,Indexer,Eraser>(inserts);
    find_tests<K,T,S,Indexer,Eraser>(inserts);
    scout_tests<K,T,S,Indexer,Eraser>(inserts);
    contains_tests<K,T,S,Indexer,Eraser>(inserts);
}

std::list<std::pair<int32_t,char32_t>> generate_default_inputs(uint32_t num) {
    std::list<std::pair<int32_t,char32_t>> list;
    std::pair<int32_t,char32_t> p;
    char32_t val('a');
    int32_t ph(12);
    for (uint32_t i(0); i < num; ++i) {
        if (i % 2 == 0) { // if even
            p = std::pair<int32_t,char32_t>(ph - i, char(val + i));
        }
        else {
            p = std::pair<int32_t,char32_t>(ph + i, char(val + i));
        }
        list.push_front(p);
    }
    return list;
}

void run_default_tests() {
    triemplate<int32_t,char32_t> trie;
    std::list<std::pair<int32_t,char32_t>> inputs(generate_default_inputs(25));

    run_standard_tests(trie,inputs);
    //int32_t,char32_t,2,Awful_Indexer<int32_t,char32_t,2>,Awful_KeyModif<int32_t,char32_t,2>,Awful_Eraser<int32_t,char32_t,2,Awful_Indexer<int32_t,char32_t,2>,Awful_KeyModif<int32_t,char32_t,2>>
    iterator_tests();
}

void print_message(const std::string& s) {
    if (s.empty()) {
        std::cout << "PASS" << std::endl;
    }
    else {
        std::cout << "FAIL" << std::endl << s;
    }
}

//region //FUNCTION DEFINITIONS
template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
void constructor_default_tests() {
    std::cout << "default constructor test(s): ";
    std::string s;

    s += constructor_default_empty<K,T,S,Indexer,Eraser>();
    s += constructor_default_beginIsEnd<K,T,S,Indexer,Eraser>();
    s += constructor_default_equalInstants<K,T,S,Indexer,Eraser>();

    print_message(s);
}
//region //DEF CONSTRUCTOR
template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
std::string constructor_default_empty() {
    std::string out("\t- is empty: ");
    try {
        triemplate<K,T,S,Indexer,Eraser> trie;
        return (!trie.empty()) ? out + "fail\n" : "";
    }
    catch(...) {
        return out + "UNKNOWN ERROR\n";
    }
}

template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
std::string constructor_default_beginIsEnd() {
    std::string out("\t- begin()==end(): ");
    try {
        triemplate<K,T,S,Indexer,Eraser> trie;
        return (trie.begin() != trie.end()) ? out + "fail\n" : "";
    }
    catch(...) {
        return out + "UNKNOWN ERROR\n";
    }
}

template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
std::string constructor_default_equalInstants() {
    std::string out("\t- def()==def(): ");
    try {
        triemplate<K,T,S,Indexer,Eraser> firstTrie;
        triemplate<K,T,S,Indexer,Eraser> secondTrie;
        out = (firstTrie != secondTrie) ? out + "fail -- != " : "";
        out = (firstTrie == secondTrie) ? "" : out + "fail -- == ";
        return (out.empty()) ? out : out + "\n";
    }
    catch(...) {
        return out + "UNKNOWN ERROR\n";
    }
}

//endregion

template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
void constructor_copy_tests(const std::list<std::pair<K,T>>& inserts) {
    std::cout << "copy constructor test(s): ";
    std::string s;

    s += constructor_copy_diffOGs<K,T,S,Indexer,Eraser>(inserts);
    s += constructor_copy_notByRef<K,T,S,Indexer,Eraser>(inserts);

    print_message(s);
}
//region //COPY CONSTRUCTOR
template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
std::string constructor_copy_equal(triemplate<K,T,S,Indexer,Eraser>& og, uint32_t count) {
    std::string out("\t- is equal(" + std::to_string(count) + "): ");
    try {
        triemplate<K,T,S,Indexer,Eraser> trie(og);
        return (trie == og) ? "" : out + "fail\n";
    }
    catch(...) {
        return out + "UNKNOWN ERROR\n";
    }
}

template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
std::string constructor_copy_diffOGs(std::list<std::pair<K,T>> inserts) {
    triemplate<K,T,S,Indexer,Eraser> tr_one; // empty
    triemplate<K,T,S,Indexer,Eraser> tr_two; // one item
    triemplate<K,T,S,Indexer,Eraser> tr_three; // three items

    int32_t ratio(int32_t(inserts.size() * 0.45));

    for (uint32_t i(0); i < ratio; ++i) {
        tr_two.insertOrAssign(inserts.front());
        inserts.pop_front();
    }

    while (!inserts.empty()) {
        tr_three.insertOrAssign(inserts.front());
        inserts.pop_front();
    }

    std::string out;

    out += constructor_copy_equal(tr_one, 1);
    out += constructor_copy_equal(tr_two, 2);
    out += constructor_copy_equal(tr_three, 3);

    return out;
}

template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
std::string constructor_copy_notByRef(std::list<std::pair<K,T>> inserts) {
    std::string out("\t- copy by value: ");
    try {
        int32_t ratio(int32_t(inserts.size() * 0.45));

        triemplate<K,T,S,Indexer,Eraser> trie_one;
        triemplate<K,T,S,Indexer,Eraser> trie_two(trie_one);

        for (uint32_t i(0); i < ratio; ++i) {
            trie_one.insertOrAssign(inserts.front());
            inserts.pop_front();
        }

        triemplate<K,T,S,Indexer,Eraser> trie_three;
        while (!inserts.empty()) {
            trie_three.insertOrAssign(inserts.front());
            inserts.pop_front();
        }
        trieTemplate<K,T,S,Indexer,Eraser> trie_four(trie_three);

        std::string moreOut;

        moreOut += ((trie_one != trie_two) ? "" : "fail -- inserted after copy; ");
        moreOut +=((trie_three == trie_four) ? "" : "fail -- inserted before copy");

        return (moreOut.empty() ? "" : out + moreOut + "\n");
    }
    catch(...) {
        return out + "UNKNOWN ERROR\n";
    }
}

//endregion

template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
void assignment_tests(const std::list<std::pair<K,T>>& inserts) {
    std::cout << "assignment operator test(s): ";
    std::string s;

    s += assign_diffOnesAndDiffOthers<K,T,S,Indexer,Eraser>(inserts);
    s += assign_notByRef<K,T,S,Indexer,Eraser>(inserts);

    print_message(s);
}
//region //ASSIGNMENT
template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
std::string assign_diffOnesAndDiffOthers(const std::list<std::pair<K,T>>& inserts) {
    triemplate<K,T,S,Indexer,Eraser> trie_one, trie_two, trie_three, trie_four,
    trie_five, trie_six, trie_seven, trie_eight, trie_nine, trie_ten;

    std::string out;

    // empty to empty
    out += assign_oneEqualOther(trie_one,trie_two,1);

    // filled to empty
    std::list<std::pair<K,T>> ph_one(inserts);
    while (!ph_one.empty()) {
        trie_one.insertOrAssign(ph_one.front());
        ph_one.pop_front();
    }
    out += assign_oneEqualOther(trie_one,trie_two,2);

    // empty to filled
    std::list<std::pair<K,T>> ph_two(inserts);
    while (!ph_two.empty()) {
        trie_three.insertOrAssign(ph_two.front());
        ph_two.pop_front();
    }
    out += assign_oneEqualOther(trie_four,trie_three,3);

    // filled to filled (same size)
    int32_t ratio(int32_t(inserts.size() * 0.5));
    std::list<std::pair<K,T>> ph_three(inserts);
    for (uint32_t i(0); i < ratio; ++i) {
        trie_six.insertOrAssign(ph_three.front());
        ph_three.pop_front();
    }

    while (!ph_three.empty()) {
        trie_five.insertOrAssign(ph_three.front());
        ph_three.pop_front();
    }
    out += assign_oneEqualOther(trie_six,trie_five,4);

    // filled to filled (less to large -- ie 2 to 3)
    ratio = inserts.size() * 0.4;
    std::list<std::pair<K,T>> ph_four(inserts);
    for (uint32_t i(0); i < ratio; ++i) {
        trie_seven.insertOrAssign(ph_four.front());
        ph_four.pop_front();
    }

    while (!ph_four.empty()) {
        trie_eight.insertOrAssign(ph_four.front());
        ph_four.pop_front();
    }
    out += assign_oneEqualOther(trie_seven,trie_eight,5);

    // filled to filled (large to less -- ie 3 to 2)
    ratio = inserts.size() * 0.7;
    std::list<std::pair<K,T>> ph_five(inserts);
    for (uint32_t i(0); i < ratio; ++i) {
        trie_nine.insertOrAssign(ph_five.front());
        ph_five.pop_front();
    }

    while (!ph_five.empty()) {
        trie_ten.insertOrAssign(ph_five.front());
        ph_five.pop_front();
    }
    out += assign_oneEqualOther(trie_ten,trie_nine,6);

    return out;
}

template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
std::string assign_oneEqualOther(triemplate<K,T,S,Indexer,Eraser>& one, triemplate<K,T,S,Indexer,Eraser>& other, uint32_t cnt) {
    std::string out("\t- one assigned to other(" + std::to_string(cnt) + "): ");
    try {
        one = other;
        return (one == other) ? "" : out + "fail\n";
    }
    catch(...) {
        return out + "UNKNOWN ERROR\n";
    }
}

template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
std::string assign_notByRef(const std::list<std::pair<K,T>>& inserts) {
    std::string out("\t- copied by value: ");
    try {
        triemplate<K,T,S,Indexer,Eraser> trie_one, trie_two, trie_three, trie_four;
        trie_two = trie_one;
        std::list<std::pair<K,T>> ph_one(inserts);
        while (!ph_one.empty()) {
            trie_one.insertOrAssign(ph_one.front());
            ph_one.pop_front();
        }

        std::list<std::pair<K,T>> ph_two(inserts);
        while (!ph_two.empty()) {
            trie_three.insertOrAssign(ph_two.front());
            ph_two.pop_front();
        }
        trie_four = trie_three;

        std::string moreOut;

        moreOut += ((trie_one != trie_two) ? "" : "fail -- inserted after assignment; ");
        moreOut +=((trie_three == trie_four) ? "" : "fail -- inserted before assignment");

        return (moreOut.empty() ? "" : out + moreOut + "\n");
    }
    catch(...) {
        return out + "UNKNOWN ERROR\n";
    }
}

//endregion

template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
void empty_tests(const std::list<std::pair<K,T>>& inserts) {
    std::cout << "empty test(s): ";
    std::string s;

    s += empty_checksValid_cases<K,T,S,Indexer,Eraser>(inserts);

    print_message(s);
}
//region //EMPTY
template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
std::string empty_checksValid_cases(std::list<std::pair<K,T>> inserts) {
    triemplate<K,T,S,Indexer,Eraser> trie_one;
    std::string out;

    // proper return when actually empty
    out += empty_checksValid(trie_one,true,1);

    // proper return when not empty (contains one item)
    trie_one.insertOrAssign(inserts.front());
    inserts.pop_front();
    out += empty_checksValid(trie_one,false,2);

    // proper return when not empty (contains two item)
    trie_one.insertOrAssign(inserts.front());
    inserts.pop_front();
    out += empty_checksValid(trie_one,false,2);

    return out;
}

template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
std::string empty_checksValid(triemplate<K,T,S,Indexer,Eraser> &trie, bool isEmpty, uint32_t cnt) {
    std::string out("\t- proper return(" + std::to_string(cnt) + "): ");
    try {
        return (trie.empty() == isEmpty) ? "" : out + "fail\n";
    }
    catch(...) {
        return out + "UNKNOWN ERROR\n";
    }
}

//endregion

template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
void size_tests(const std::list<std::pair<K,T>>& inserts) {
    std::cout << "size test(s): ";
    std::string s;

    s += size_checksValid_cases<K,T,S,Indexer,Eraser>(inserts);

    print_message(s);
}
//region //SIZE
template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
std::string size_checksValid_cases(std::list<std::pair<K,T>> inserts) {
    triemplate<K,T,S,Indexer,Eraser> trie;
    std::string out("");

    int32_t i(0);
    while (!inserts.empty()) {
        out += size_checkValid(trie,i,i+1);
        if (trie.contains(inserts.front().first))
            --i;
        trie.insertOrAssign(inserts.front());
        inserts.pop_front();
        ++i;
    }

    return out;
}

template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
std::string size_checkValid(triemplate<K,T,S,Indexer,Eraser> &trie, uint32_t correctCnt, uint32_t cnt) {
    std::string out("\t- proper return(" + std::to_string(cnt) + "): ");
    try {
        return (trie.size() == correctCnt) ? "" : out + "fail\n";
    }
    catch(...) {
        return out + "UNKNOWN ERROR\n";
    }
}

//endregion

template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
void clear_tests(const std::list<std::pair<K,T>>& inserts) {
    std::cout << "clear test(s): ";
    std::string s;

    // when empty and not empty
    s += clear_diffCases<K,T,S,Indexer,Eraser>(inserts);

    // called multiple times
    s += clear_multiple<K,T,S,Indexer,Eraser>(inserts);

    print_message(s);
}
//region //EMPTY
template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
std::string clear_diffCases(std::list<std::pair<K,T>> inserts) {
    triemplate<K,T,S,Indexer,Eraser> trie_one, trie_two;
    std::string out;

    // when empty
    out += clear_properOut(trie_one, 1);

    // filled with one
    trie_two.insertOrAssign(inserts.front());
    inserts.pop_front();
    out += clear_properOut(trie_two, 2);

    // filled with more than one
    while (!inserts.empty()) {
        trie_two.insertOrAssign(inserts.front());
        inserts.pop_front();
    }
    out += clear_properOut(trie_two,3);

    return out;
}

template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
std::string clear_properOut(triemplate<K,T,S,Indexer,Eraser> &trie, uint32_t cnt) {
    std::string out("\t- proper return(" + std::to_string(cnt) + "): ");
    try {
        trie.clear();
        return (trie.empty() && trie.size() == 0) ? "" : out + "fail\n";
    }
    catch(...) {
        return out + "UNKNOWN ERROR\n";
    }
}

template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
std::string clear_multiple(const std::list<std::pair<K,T>>& inserts) {

    std::string out;

    out += clear_empty_empty<K,T,S,Indexer,Eraser>();
    out += clear_filled_empty<K,T,S,Indexer,Eraser>(inserts);
    out += clear_empty_filled<K,T,S,Indexer,Eraser>(inserts);
    out += clear_filled_filled<K,T,S,Indexer,Eraser>(inserts);

    return out;
}

template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
std::string clear_empty_empty() {
    triemplate<K,T,S,Indexer,Eraser> trie_empty;
    std::string out;

    out += clear_properOut(trie_empty, 4);
    out += clear_properOut(trie_empty, 5);

    return out;
}

template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
std::string clear_filled_empty(std::list<std::pair<K,T>> inserts) {
    triemplate<K,T,S,Indexer,Eraser> trie;
    std::string out;

    trie.insertOrAssign(inserts.front());
    inserts.pop_front();

    out += clear_properOut(trie, 6);
    out += clear_properOut(trie,7);

    return out;
}

template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
std::string clear_empty_filled(std::list<std::pair<K,T>> inserts) {
    triemplate<K,T,S,Indexer,Eraser> trie;
    std::string out;

    out += clear_properOut(trie,8);

    trie.insertOrAssign(inserts.front());
    inserts.pop_front();

    out += clear_properOut(trie,9);

    return out;
}

template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
std::string clear_filled_filled(std::list<std::pair<K,T>> inserts) {
    triemplate<K,T,S,Indexer,Eraser> trie;
    std::string out;

    trie.insertOrAssign(inserts.front());
    inserts.pop_front();
    out += clear_properOut(trie,10);
    trie.insertOrAssign(inserts.front());
    inserts.pop_front();
    out += clear_properOut(trie,11);

    return out;
}

//endregion

template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
void insert_tests(const std::list<std::pair<K,T>>& inserts) {
    std::cout << "insert test(s): ";
    std::string s;

    // pairType&
    s += insert_pairTypeRef<K,T,S,Indexer,Eraser>(inserts);

    // pairType&&
    s += insert_pairTypeVal<K,T,S,Indexer,Eraser>(inserts);

    // type&
    s += insert_typeRef<K,T,S,Indexer,Eraser>(inserts);

    // type&&
    s += insert_typeVal<K,T,S,Indexer,Eraser>(inserts);

    print_message(s);
}
//region //INSERT
template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
std::string insert_pairTypeRef(std::list<std::pair<K,T>> inserts) {
    std::string out;

    // new key in empty trie
        // size change
        // trie has new key and its node has new value
    out += insert_pairTypeRef_empty<K,T,S,Indexer,Eraser>(inserts.front());
    inserts.pop_front();

    // old key in trie
    triemplate<K,T,S,Indexer,Eraser> trie;
    std::pair<K,T> p(inserts.front());
    inserts.pop_front();
    trie.insertOrAssign(p);

        // no size change
        // old val
            // no new value at key
            out += insert_pairTypeRef_filled<K,T,S,Indexer,Eraser>(trie,p);
        // new val
            // new value at key
            p.second = inserts.front().second;
            inserts.pop_front();
            out += insert_pairTypeRef_filled<K,T,S,Indexer,Eraser>(trie,p);

    return out;
}
template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
std::string insert_pairTypeRef_empty(std::pair<K,T> p) {
    std::string out("\t- pairTypeRef empty: ");
    try {
        triemplate<K,T,S,Indexer,Eraser> trie;
        auto it = trie.insertOrAssign(p);
        return (trie.size() == 1 && it.first() == p.first && it.second() == p.second) ? "" : out + "fail\n";
    }
    catch(...) {
        return out + "UNKNOWN ERROR\n";
    }
}
template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
std::string insert_pairTypeRef_filled(triemplate<K,T,S,Indexer,Eraser> &trie, std::pair<K,T> p) {
    std::string out("\t- pairTypeRef filled: ");
    try {
        int32_t prevSize = trie.size();
        auto it = trie.insertOrAssign(p);

        bool incArtCnt(trie.size() == prevSize);
        return (incArtCnt && it.second() == p.second) ? "" : out + "fail\n";
    }
    catch(...) {
        return out + "UNKNOWN ERROR\n";
    }
}

template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
std::string insert_pairTypeVal(std::list<std::pair<K,T>> inserts) {
    std::string out;

    // new key in empty trie
        // size change
        // trie has new key and its node has new value
    out += insert_pairTypeVal_empty<K,T,S,Indexer,Eraser>(inserts.front());
    inserts.pop_front();

    // old key in trie
    triemplate<K,T,S,Indexer,Eraser> trie;
    std::pair<K,T> p(inserts.front().first,inserts.front().second);
    inserts.pop_front();
    trie.insertOrAssign(p);

        // no size change
        // old val
            // no new value at key
            out += insert_pairTypeVal_filled(trie,p);
        // new val
            // new value at key
            p.second = inserts.front().second;
            inserts.pop_front();
            out += insert_pairTypeVal_filled(trie,p);

    return out;
}
template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
std::string insert_pairTypeVal_empty(std::pair<K,T> p) {
    std::string out("\t- pairTypeVal empty: ");
    try {
        triemplate<K,T,S,Indexer,Eraser> trie;
        auto it = trie.insertOrAssign(std::pair<K,T>(p));
        return (trie.size() == 1 && it.first() == p.first && it.second() == p.second) ? "" : out + "fail\n";
    }
    catch(...) {
        return out + "UNKNOWN ERROR\n";
    }
}
template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
std::string insert_pairTypeVal_filled(triemplate<K,T,S,Indexer,Eraser> &trie, std::pair<K,T> p) {
    std::string out("\t- pairTypeVal filled: ");
    try {
        int32_t prevSize = trie.size();
        auto it = trie.insertOrAssign(std::pair<K,T>(p));

        bool incArtCnt(trie.size() == prevSize);
        return (incArtCnt && it.second() == p.second) ? "" : out + "fail\n";
    }
    catch(...) {
        return out + "UNKNOWN ERROR\n";
    }
}

template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
std::string insert_typeRef(std::list<std::pair<K,T>> inserts) {
    std::string out;

    // new key in empty trie
    // size change
    // trie has new key and its node has new value
    out += insert_typeRef_empty<K,T,S,Indexer,Eraser>(inserts.front());
    inserts.pop_front();

    // old key in trie
    triemplate<K,T,S,Indexer,Eraser> trie;
    std::pair<K,T> p(inserts.front().first,inserts.front().second);
    trie.insertOrAssign(p);

    // no size change
    // old val
    // no new value at key
    out += insert_typeRef_filled<K,T,S,Indexer,Eraser>(trie,p);
    inserts.pop_front();
    // new val
    // new value at key
    p.second = inserts.front().second;
    out += insert_typeRef_filled<K,T,S,Indexer,Eraser>(trie,p);

    return out;
}
template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
std::string insert_typeRef_empty(std::pair<K,T> p) {
    std::string out("\t- typeRef empty: ");
    try {
        triemplate<K,T,S,Indexer,Eraser> trie;
        T val(p.second);
        auto it = trie.insertOrAssign(p.first,val);

        return (trie.size() == 1 && it.first() == p.first && it.second() == p.second) ? "" : out + "fail\n";
    }
    catch(...) {
        return out + "UNKNOWN ERROR\n";
    }
}
template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
std::string insert_typeRef_filled(triemplate<K,T,S,Indexer,Eraser> &trie, std::pair<K,T> p) {
    std::string out("\t- typeRef filled: ");
    try {
        int32_t prevSize = trie.size();
        auto it = trie.insertOrAssign(p.first,p.second);

        bool incArtCnt(trie.size() == prevSize);
        return (incArtCnt && it.first() == p.first && it.second() == p.second) ? "" : out + "fail\n";
    }
    catch(...) {
        return out + "UNKNOWN ERROR\n";
    }
}

template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
std::string insert_typeVal(std::list<std::pair<K,T>> inserts) {
    std::string out;

    // new key in empty trie
    // size change
    // trie has new key and its node has new value
    out += insert_typeVal_empty<K,T,S,Indexer,Eraser>(inserts.front());
    inserts.pop_front();

    // old key in trie
    triemplate<K,T,S,Indexer,Eraser> trie;
    std::pair<K,T> p(inserts.front().first,inserts.front().second);
    trie.insertOrAssign(p);

    // no size change
    // old val
    // no new value at key
    out += insert_typeVal_filled<K,T,S,Indexer,Eraser>(trie,p);
    inserts.pop_front();
    // new val
    // new value at key
    p.second = inserts.front().second;
    out += insert_typeVal_filled<K,T,S,Indexer,Eraser>(trie,p);

    return out;
}
template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
std::string insert_typeVal_empty(std::pair<K,T> p) {
    std::string out("\t- typeVal empty: ");
    try {
        triemplate<K,T,S,Indexer,Eraser> trie;
        auto it = trie.insertOrAssign(p.first,p.second);

        return (trie.size() == 1 && it.first() == p.first && it.second() == p.second) ? "" : out + "fail\n";
    }
    catch(...) {
        return out + "UNKNOWN ERROR\n";
    }
}
template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
std::string insert_typeVal_filled(triemplate<K,T,S,Indexer,Eraser> &trie, std::pair<K,T> p) {
    std::string out("\t- typeVal filled: ");
    try {
        int32_t prevSize = trie.size();
        auto it = trie.insertOrAssign(p.first,p.second);

        bool incArtCnt(trie.size() == prevSize);
        return (incArtCnt && it.first() == p.first && it.second() == p.second) ? "" : out + "fail\n";
    }
    catch(...) {
        return out + "UNKNOWN ERROR\n";
    }
}

//endregion

template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
void erase_tests(const std::list<std::pair<K,T>>& inserts) {
    std::cout << "erase test(s): ";
    std::string s;

    // erase via key
    s += erase_key<K,T,S,Indexer,Eraser>(inserts);

    //todo do erase test cases

    // erase via iterator
    //s += erase_iterators();

    // called on empty trie
        // changes number appropriately


    // non-existent key
        // changes number appropriately

    // actual key

    print_message(s);
}
//region //ERASE
template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
std::string erase_key(std::list<std::pair<K,T>> inserts) {
    std::string out;
    // called on empty trie
        // changes number appropriately
        triemplate<K,T,S,Indexer,Eraser> trie;
        out += erase_key_diffCases<K,T,S,Indexer,Eraser>(trie,inserts.front().first,false,1);

    // non-existent key
        // changes number appropriately
        std::pair<K,T> p(inserts.front());
        inserts.pop_front();
        auto it_ = trie.insertOrAssign(p);
        out += erase_key_diffCases(trie,inserts.front().first,false,2);

    // actual key
    std::pair<K,T> p_uniq_one(inserts.front());
    inserts.pop_front();
    auto it__ = trie.insertOrAssign(p_uniq_one);

    std::pair<K,T> p_uniq_two(inserts.front());
    inserts.pop_front();
    auto it___ = trie.insertOrAssign(p_uniq_two);

    std::pair<K,T> ph(inserts.front());
    inserts.pop_front();
    while (!inserts.empty()) {
        trie.insertOrAssign(ph);

        ph = inserts.front();
        inserts.pop_front();
    }

    std::pair<K,T> p_uniq_three(ph);
    trie.insertOrAssign(p_uniq_three);

    out += erase_key_diffCases(trie,p_uniq_one.first,true,3);

    out += erase_key_diffCases(trie,p_uniq_two.first,true,4);

    out += erase_key_diffCases(trie,p_uniq_three.first,true,5);

    return out;
}
template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
std::string erase_key_diffCases(triemplate<K,T,S,Indexer,Eraser> &trie, K key, bool validKey, uint32_t cnt) {
    std::string out("\t- key diffCases (" + std::to_string(cnt) + "): ");
    try {
        triemplate<K,T,S,Indexer,Eraser> copy(trie);
        int32_t ogSize(copy.size());
        copy.erase(key);

        return (((ogSize == copy.size() + 1) == validKey) && !(copy.contains(key))) ? "" : out + "fail\n";
    }
    catch(...) {
        return out + "UNKNOWN ERROR\n";
    }
}

//endregion

template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
void swap_tests(const std::list<std::pair<K,T>>& inserts) {
    std::cout << "swap test(s): ";
    std::string s;

    // empty to empty
    triemplate<K,T,S,Indexer,Eraser> trie_one, trie_two;
    s += swap_oneAndOther<K,T,S,Indexer,Eraser>(trie_one,trie_two,1);

    // empty to filled
    std::list<std::pair<K,T>> ph_one(inserts);
    triemplate<K,T,S,Indexer,Eraser> trie_three, trie_four;
    trie_four.insertOrAssign(ph_one.front());
    ph_one.pop_front();
    trie_four.insertOrAssign(ph_one.front());
    ph_one.pop_front();
    trie_four.insertOrAssign(ph_one.front());
    ph_one.pop_front();
    s += swap_oneAndOther<K,T,S,Indexer,Eraser>(trie_three,trie_four,2);

    // filled to empty
    std::list<std::pair<K,T>> ph_two(inserts);
    triemplate<K,T,S,Indexer,Eraser> trie_five, trie_six;
    trie_five.insertOrAssign(ph_two.front());
    ph_two.pop_front();
    trie_five.insertOrAssign(ph_two.front());
    ph_two.pop_front();
    trie_five.insertOrAssign(ph_two.front());
    ph_two.pop_front();
    s += swap_oneAndOther<K,T,S,Indexer,Eraser>(trie_five,trie_six,3);

    // filled to filled
    std::list<std::pair<K,T>> ph_three(inserts);
    uint32_t ratio(int32_t(ph_three.size() * 0.45));
    triemplate<K,T,S,Indexer,Eraser> trie_seven, trie_eight;
    for (uint32_t i(0); i < ratio; ++i) {
        trie_seven.insertOrAssign(ph_three.front());
        ph_three.pop_front();
    }

    while (!ph_three.empty()) {
        trie_eight.insertOrAssign(ph_three.front());
        ph_three.pop_front();
    }
    s += swap_oneAndOther<K,T,S,Indexer,Eraser>(trie_seven,trie_eight,4);

    print_message(s);
}
//region //SWAP
template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
std::string swap_oneAndOther(triemplate<K,T,S,Indexer,Eraser> &one, triemplate<K,T,S,Indexer,Eraser> &other, uint32_t cnt) {
    std::string out("\t- proper swap(" + std::to_string(cnt) + "): ");
    try {
        triemplate<K,T,S,Indexer,Eraser> copy_one(one), copy_other(other);
        one.swap(other);
        return (one == copy_other && other == copy_one) ? "" : out + "fail\n";
    }
    catch(...) {
        return out + "UNKNOWN ERROR\n";
    }
}

//endregion

template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
void find_tests(std::list<std::pair<K,T>> inserts) {
    std::cout << "find test(s): ";
    std::string s;

    // empty trie
    triemplate<K,T,S,Indexer,Eraser> empty;
    s += find_keyInTrie<K,T,S,Indexer,Eraser>(empty,inserts.front().first,false,1);

    // filled trie, invalid key
    triemplate<K,T,S,Indexer,Eraser> filled;
    std::pair<K,T> ph_notWithin(inserts.front()), ph_within;
    inserts.pop_front();
    while (!inserts.empty()) {
        ph_within = inserts.front();
        inserts.pop_front();
        filled.insertOrAssign(ph_within);
    }
    s += find_keyInTrie<K,T,S,Indexer,Eraser>(filled,ph_notWithin.first,false,2);

    // filled trie, valid key
    s += find_keyInTrie<K,T,S,Indexer,Eraser>(filled,ph_within.first,true,2);

    print_message(s);
}
//region //FIND
template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
std::string find_keyInTrie(triemplate<K,T,S,Indexer,Eraser> &trie, K key, bool valid, uint32_t cnt) {
    std::string out("\t- proper find(" + std::to_string(cnt) + "): ");
    try {
        auto it = trie.find(key);
        return ((it != trie.end()) == valid) ? "" : out + "fail\n";
    }
    catch(...) {
        return out + "UNKNOWN ERROR\n";
    }
}

//endregion

template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
void scout_tests(std::list<std::pair<K,T>> inserts) {
    std::cout << "scout test(s): ";
    std::string s;

    // empty trie
    triemplate<K,T,S,Indexer,Eraser> empty;
    s += scout_keyInTrie<K,T,S,Indexer,Eraser>(empty,inserts.front().first,false,1);

    // filled trie, invalid key
    triemplate<K,T,S,Indexer,Eraser> trie;
    std::pair<K,T> ph_notWithin(inserts.front()), ph_within;
    inserts.pop_front();
    while (!inserts.empty()) {
        ph_within = inserts.front();
        inserts.pop_front();
        trie.insertOrAssign(ph_within);
    }
    s += scout_keyInTrie<K,T,S,Indexer,Eraser>(trie,ph_notWithin.first,false,2);

    // filled key, valid key
    s += scout_keyInTrie<K,T,S,Indexer,Eraser>(trie,ph_within.first,true,3);

    print_message(s);
}
//region //SCOUT
template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
std::string scout_keyInTrie(triemplate<K,T,S,Indexer,Eraser> &trie, K key, bool valid, uint32_t cnt) {
    std::string out("\t- proper scout(" + std::to_string(cnt) + "): ");
    try {
        auto it = trie.scout(key);
        return (it.first == valid) ? "" : out + "fail\n";
    }
    catch(...) {
        return out + "UNKNOWN ERROR\n";
    }
}

//endregion,

template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
void contains_tests(std::list<std::pair<K,T>> inserts) {
    std::cout << "contains test(s): ";
    std::string s;

    // empty trie
    triemplate<K,T,S,Indexer,Eraser> empty;
    s += contains_keyInTrie<K,T,S,Indexer,Eraser>(empty,inserts.front().first,false,1);

    // filled trie, invalid key
    triemplate<K,T,S,Indexer,Eraser> trie;
    std::pair<K,T> ph_notWithin(inserts.front()), ph_within;
    inserts.pop_front();
    while (!inserts.empty()) {
        ph_within = inserts.front();
        inserts.pop_front();
        trie.insertOrAssign(ph_within);
    }
    s += contains_keyInTrie<K,T,S,Indexer,Eraser>(trie,ph_notWithin.first,false,2);

    // filled key, valid key
    s += contains_keyInTrie<K,T,S,Indexer,Eraser>(trie,ph_within.first,true,3);

    print_message(s);
}
//region //CONTAINS
template <typename K, typename T, uint32_t S, typename Indexer, typename Eraser>
std::string contains_keyInTrie(triemplate<K,T,S,Indexer,Eraser> &trie, K key, bool valid, uint32_t cnt) {
    std::string out("\t- proper contains(" + std::to_string(cnt) + "): ");
    try {
        return (trie.contains(key) == valid) ? "" : out + "fail\n";
    }
    catch(...) {
        return out + "UNKNOWN ERROR\n";
    }
}

//endregion

void iterator_tests() {
    std::cout << "iterator test(s): ";
    std::string s;

    // empty trie
    s += iterator_empty_beginIsEnd();

    // filled trie
    triemplate<int32_t,char32_t> trie;
    std::map<int32_t,char32_t> map;
    std::pair<int32_t,char32_t> p(3,'a');
    trie.insertOrAssign(p);
    map.insert(p);

    p = std::pair<int32_t,char32_t>(2,'b');
    trie.insertOrAssign(p);
    map.insert(p);

    p = std::pair<int32_t,char32_t>(5,'c');
    trie.insertOrAssign(p);
    map.insert(p);

    p = std::pair<int32_t,char32_t>(4,'d');
    trie.insertOrAssign(p);
    map.insert(p);

    p = std::pair<int32_t,char32_t>(6,'e');
    trie.insertOrAssign(p);
    map.insert(p);

    s += iterator_filled_diffCases(trie,map,1);

    print_message(s);
}
std::string iterator_empty_beginIsEnd() {
    std::string out("\t- empty begin is end: ");
    try {
        triemplate<int32_t,char32_t> trie;
        return (trie.begin() == trie.end()) ? "" : out + "fail\n";
    }
    catch(...) {
        return out + "UNKNOWN ERROR\n";
    }
}

std::string iterator_filled_diffCases(triemplate<int32_t,char32_t> &trie, std::map<int32_t,char32_t> &map, int32_t cnt) {
    std::string out("\t- iterator filled (" + std::to_string(cnt) + "): ");
    try {
        triemplate<int32_t,char32_t> copy(trie);

        bool allEqual(true);
        int32_t cnt(0);
        for (auto trieIt(trie.begin()); trieIt != trie.end(); ++trieIt) {
            ++cnt;
            if (cnt == 6) {
                std::cout << bool(trieIt != trie.end());
            }

            if (map.find(trieIt.first()) == map.end()) {
                allEqual = false;
                break;
            }
        }

        return (allEqual) ? "" : out + "fail\n";
    }
    catch(...) {
        return out + "UNKNOWN ERROR\n";
    }
}

//endregion
