#include <iostream>
#include <Windows.h>
#define WIDTH 50
#define HEIGHT 50
using namespace std;

char map[HEIGHT][WIDTH];
char cellSign = '.';
int antX = HEIGHT / 2; 
int antY = WIDTH / 2;  
int countAntMoves = 0;

enum class Direction
{
	down, up, right, left
};

Direction ant;

void SetUpMap() //Fulling the map with spaces
{
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			map[i][j] = ' ';
		}
	}
}

bool IsTheCellEmpty(int nextCellX, int nextCellY) // checks is the cell empty or it is not
{
	if (map[nextCellX][nextCellY] == ' ')
	{
		cellSign = '.';
		return true;
	}
	else
	{
		cellSign = ' ';
		return false;
	}
}

void AntMovement()
{
	switch (ant)
	{
	case Direction::down:
		countAntMoves++;
		if (IsTheCellEmpty(antX + 1, antY) == false) //choose next direction 
		{
			ant = Direction::right;
		}
		else
		{
			ant = Direction::left;
		}
		antX++;
		break;
	case Direction::up:
		countAntMoves++;
		if (IsTheCellEmpty(antX - 1, antY) == false)//choose next direction
		{
			ant = Direction::left;
		}
		else
		{
			ant = Direction::right;
		}
		antX--;
		break;
	case Direction::right:
		countAntMoves++;
		if (IsTheCellEmpty(antX, antY + 1) == false)//choose next direction
		{
			ant = Direction::up;
		}
		else
		{
			ant = Direction::down;
		}
		antY++;
		break;
	case Direction::left:
		countAntMoves++;
		if (IsTheCellEmpty(antX, antY - 1) == false)//choose next direction
		{
			ant = Direction::down;
		}
		else
		{
			ant = Direction::up;
		}
		antY--;
		break;
	}
}

void FullMap() // Fulling the map before outputting it
{
	map[antX][antY] = cellSign;
}

void DrawMap()// Output the map
{
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			cout << map[i][j];
		}
		cout << endl;
	}
	cout << countAntMoves << endl;
}

void ClearSreen()
{
	COORD cursorPosition;
	cursorPosition.X = 0;
	cursorPosition.Y = 0;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}

int main()
{
	SetUpMap();
	while (true)
	{
		FullMap();
		DrawMap();
		AntMovement();
		ClearSreen();
		//Sleep(200);
	}
	return 0;
}