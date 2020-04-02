#pragma once
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<Windows.h>
#define endl '\n'

using namespace std;

class Cnode
{
	friend class Stack;
public:
	Cnode()
	{
		pnext = nullptr;
		x = 0;
		y = 0;
	}

	typedef Cnode Node;
	typedef Cnode* Pnode;

private:
	int x;
	int y;
	Pnode pnext;
};

class Stack
{
public:
	Stack()
	{
		FIFO = nullptr;
		Size = 0;
	}
	~Stack()
	{
		Clear();
	}

	typedef Cnode Node;
	typedef Cnode* Pnode;

private:
	int Size;
	Pnode FIFO;

public:
	void Push(int ix, int iy)
	{
		Pnode Save = new Node;
		Save->x = ix;
		Save->y = iy;

		Save->pnext = FIFO;

		FIFO = Save;
		Size++;
	}

	void Pop()
	{
		if (!Size)
			return;
		Pnode Tempo = FIFO->pnext;
		delete FIFO;
		Size--;

		FIFO = Tempo;

	}

	int Top_iX()
	{
		return FIFO->x;
	}
	int Top_iY()
	{
		return FIFO->y;
	}

	int _Size()	const
	{
		return Size;
	}

	void Clear()
	{
		Pnode Alter = FIFO;

		while (Alter)
		{
			Pnode Tempo = Alter->pnext;
			delete Alter;
			Alter = Tempo;
		}
	}
};