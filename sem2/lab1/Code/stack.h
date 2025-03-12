//
// Created by bito4ek on 12.03.2025.
//

#ifndef STACK_H
#define STACK_H

#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

void push(Node*& top, int value);
void pop(Node*& top);
int peek(Node* top);
bool isEmpty(Node* top);
void display(Node* top);
void printStack(Node*& top);
#endif

