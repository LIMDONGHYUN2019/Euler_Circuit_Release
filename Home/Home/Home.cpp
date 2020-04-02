#include"Stack.h"
#define row 10
#define col 8

const char *Star[col][row] = {
	{"☆","☆","☆","☆","■","■","☆","☆","☆","☆"},
	{"■","■","■","☆","☆","☆","☆","■","☆","■"},
	{"☆","☆","☆","☆","■","■","☆","■","☆","■"},
	{"☆","■","■","☆","☆","■","☆","■","☆","■"},
	{"☆","■","☆","☆","☆","☆","☆","■","☆","■"},
	{"☆","■","■","■","■","☆","☆","■","■","■"},
	{"☆","☆","■","☆","■","☆","☆","☆","■","☆"},
	{"☆","☆","☆","☆","☆","☆","☆","☆","■","☆"}
};

const char* This[col][row] = {
	{"☆","☆","☆","☆","■","■","☆","☆","☆","☆"},
	{"■","■","■","☆","☆","☆","☆","■","☆","■"},
	{"☆","☆","☆","☆","■","■","☆","■","☆","■"},
	{"☆","■","■","☆","☆","■","☆","■","☆","■"},
	{"☆","■","☆","☆","☆","☆","☆","■","☆","■"},
	{"☆","■","■","■","■","☆","☆","■","■","■"},
	{"☆","☆","■","☆","■","☆","☆","☆","■","☆"},
	{"☆","☆","☆","☆","☆","☆","☆","☆","■","☆"}
};

void Print()
{
	system("cls");
	for (int i = 0; i < col; i++)
	{
		for (int k = 0; k < row; k++)
		{
			cout << Star[i][k];
		}
		cout << endl;            
	}
}

void Run()
{
	Stack stack;
	stack.Push(0, 0);
	int ix, iy;

	do
	{
		ix = stack.Top_iX();
		iy = stack.Top_iY();
		if (ix < 0 || ix >= row)
		{
			stack.Pop();
			continue;
		}
		if (iy < 0 || iy >= col)
		{
			stack.Pop();
			continue;
		}
		if (!strcmp(Star[iy][ix],"★") || !strcmp(Star[iy][ix], "■"))
		{
			stack.Pop();
			continue;
		}


		Star[iy][ix] = "★";
		Print();

		stack.Push(ix - 1, iy);
		stack.Push(ix + 1, iy);
		stack.Push(ix, iy - 1);
		stack.Push(ix, iy + 1);
	} while (stack._Size());


}

int main()
{
	while (1)
	{
		Run();

		for (int i = 0; i < col; i++)
		{
			for (int k = 0; k < row; k++)
			{
				Star[i][k] = This[i][k];
			}
		}

		cout << "재시작 할거면 5를 눌러... " << endl;
		int num;
		scanf("%d", &num);
		if (num != 5)
			break;
	}
}




