#pragma once
#ifndef DEQUE_H
#define DEQUE_H

#include <iostream>

struct DequeNode {
    int info;
    DequeNode* next;
    DequeNode* prev;
};

void CreateDeque(DequeNode** front, DequeNode** rear, int value);
void AddToFront(DequeNode** front, DequeNode** rear, int value);
void AddToRear(DequeNode** front, DequeNode** rear, int value);
int RemoveFromFront(DequeNode** front, DequeNode** rear);
int RemoveFromRear(DequeNode** front, DequeNode** rear);
void ViewDeque(int direction, DequeNode* node);
void ClearDeque(DequeNode** front, DequeNode** rear);

#endif // DEQUE_H