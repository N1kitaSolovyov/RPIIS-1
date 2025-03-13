#include <iostream>
#include <vector>
#include <algorithm>
#include "Node.h"  
#include "bor.h"   
using namespace std;

void AddString(string s, Node* root) {
    Node* current = root;
    Node* ptr;
    bool fnd;

    for (char c : s) {
        fnd = false;
        for (Node* child : current->front_ptrs) {
            if (child != nullptr && c == child->c) {
                current = child;
                fnd = true;
                break;
            }
        }
        if (!fnd) {
            ptr = new Node(c);
            current->front_ptrs.push_back(ptr);
            ptr->back_ptr = current;
            current = ptr;
        }
    }
    current->end = true;
    cout << "Строка добавлена" << endl << endl;
}

int DelString(string s, Node* root) {
    Node* current = root;
    Node* ptr;

    for (char c : s) {
        bool fnd = false;
        for (Node* child : current->front_ptrs) {
            if (child != nullptr && c == child->c) {
                current = child;
                fnd = true;
                break;
            }
        }
        if (!fnd) {
            cout << "Строка не найдена" << endl << endl;
            return 1;
        }
    }

    if (!current->end) {
        cout << "Строка не найдена" << endl << endl;
        return 1;
    }

    current->end = false;
    for (int i = s.size() - 1; i >= 0; i--) {
        if (current->front_ptrs.empty()) {
            Node* back = current->back_ptr;
            if (back) {
                auto it = std::find(back->front_ptrs.begin(), back->front_ptrs.end(), current);
                if (it != back->front_ptrs.end()) {
                    back->front_ptrs.erase(it);
                    delete current;
                    current = back;
                }
            }
        }
        else {
            break;
        }
    }
    cout << "Строка удалена" << endl << endl;
    return 0;
}

void rekurs(Node* current, string word) {
    if (current->end) {
        cout << word << endl;
    }

    for (Node* nextNode : current->front_ptrs) {
        if (nextNode != nullptr) {
            rekurs(nextNode, word + nextNode->c);
        }
    }
}

void ShowBor(Node* root) {
    string word;
    rekurs(root, word);
    cout << endl;
}

int SearchString(string s, Node* root) {
    Node* current = root;

    for (char c : s) {
        bool fnd = false;
        for (Node* child : current->front_ptrs) {
            if (child != nullptr && c == child->c) {
                current = child;
                fnd = true;
                break;
            }
        }
        if (!fnd) {
            cout << "Строка не найдена" << endl << endl;
            return 1;
        }
    }
    cout << (current->end ? "Строка найдена" : "Строка не найдена") << endl << endl;
    return 0;
}

void DelBor(Node* root) {
    if (root != nullptr) {
        for (Node* child : root->front_ptrs) {
            DelBor(child);
        }
        delete root;
    }
}