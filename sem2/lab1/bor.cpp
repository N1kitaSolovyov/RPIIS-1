#include <iostream>
#include <vector>
#include "Node.h"  
#include "bor.h"   
using namespace std;

void AddString(string s, Node* root) {
    Node* current = root;
    Node* ptr;
    bool fnd;

    for (int i = 0; i < s.size(); i++) {
        fnd = false;
        for (int j = 0; j < current->front_ptrs.size(); j++) {
            ptr = current->front_ptrs[j];
            if (ptr != nullptr && s[i] == ptr->c) {
                current = ptr;
                fnd = true;
                break;
            }
        }
        if (!fnd) {
            ptr = new Node(s[i]);
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
    bool fnd = false;

    for (int i = 0; i < s.size(); i++) {
        fnd = false;
        for (int j = 0; j < current->front_ptrs.size(); j++) {
            ptr = current->front_ptrs[j];
            if (ptr == nullptr) {
                cout << "Строка не найдена" << endl << endl;
                return 1;
            }
            if (s[i] == ptr->c) {
                current = ptr;
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

    
    for (int i = s.size() - 1; i >= 0; i--) {
        current->end = (i != s.size() - 1); 
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

    for (int i = 0; i < current->front_ptrs.size(); i++) {
        Node* nextNode = current->front_ptrs[i];
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
    Node* ptr;

    for (int i = 0; i < s.size(); i++) {
        bool fnd = false;
        for (int j = 0; j < current->front_ptrs.size(); j++) {
            ptr = current->front_ptrs[j];
            if (ptr != nullptr && s[i] == ptr->c) {
                current = ptr;
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
        for (int i = 0; i < root->front_ptrs.size(); i++) {
            DelBor(root->front_ptrs[i]);
        }
        delete root;
    }
}