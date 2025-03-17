#pragma once
struct prikol
{
	int data;

	prikol* left;

	prikol* right;

	prikol(int val) : data(val), left(nullptr), right(nullptr) {}


};
void Add(prikol*& current, int value);
void add1(prikol*& current, prikol*& mnozhC);
void check(int value, prikol* node, prikol*& mnozhC);
void removeNode(prikol*& current, int value);
void intersection(prikol* mnozhA, prikol* mnozhB, prikol*& mnozhC);
void unity(prikol* mnozhA, prikol* mnozhB, prikol*& mnozhC);
void view(prikol* node);
void Menu();
bool empty(prikol* node);
void inputelem(prikol*& mnozhestvo);
prikol* Find(prikol* node, int value);
prikol* findMinNode(prikol* node);
