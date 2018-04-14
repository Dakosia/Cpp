#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>
using namespace std;

struct Point
{
	short x, y;
};
struct Figure
{
	Point body[4];
	byte size;
	int type;
};
struct Ground
{
	bool filled[10][10];
	int groundHeight;
	int size;
};
struct Wall
{
	Point gates[20];
	short size;
};
void draw(Point & p, char sign)
{
	COORD position = { p.x, p.y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
	cout << sign;
}
void drawEverything(Figure & f, Wall & w, Ground & g)
{
	for (byte i = 0; i < f.size; ++i)
	{
		draw(f.body[i], '#');
	}
	for (short i = 0; i < w.size; ++i) {
		draw(w.gates[i], '|');
	}
}
void init(Figure & f, Wall & w, Ground & g) {
	f.body[0].x = 2;
	f.body[0].y = 1;
	f.body[1].x = 2;
	f.body[1].y = 2;
	f.body[2].x = 2;
	f.body[2].y = 3;
	f.body[3].x = 2;
	f.body[3].y = 4;
	f.size = 4;
	f.type = 1;
	g.body = new Point[20];
	g.size = 0;
	w.size = 20;
	for (int i = 0; i < 10; ++i) {
		w.gates[i].x = 1;
		w.gates[i].y = i;
		w.gates[i + 10].x = 10;
		w.gates[i + 10].y = i;
	}
}
void move(Figure & f, int dx)
{
	for (byte i = 0; i < f.size; ++i)
	{
		f.body[i].x += dx;
		++f.body[i].y;
	}
}
void rotate(Figure & f)
{
	switch (f.type)
	{
	case 1:
		f.body[0].x--;
		f.body[0].y++;
		f.body[2].x++;
		f.body[2].y--;
		f.body[3].x += 2;
		f.body[3].y -= 2;
		break;
	default:
		break;
	}
}
void landing() 
{

}
void game()
{
	Figure figure;
	Wall wall;
	Ground ground;
	bool isActive = true;
	init(figure, wall, ground);
	while (isActive)
	{
		system("cls");
		drawEverything(figure, wall, ground);
		int dx = 0;
		if (_kbhit())
		{
			dx = 0;
			char action = _getch();
			switch (action)
			{
			case 'a':
				dx = -1;
				break;
			case 'd':
				dx = 1;
				break;
			case 'w':
				rotate(figure);
				break;
			case 's':
				break;
			default:
				break;
			}
		}
		move(figure, dx);
		Sleep(1000);
	}
	delete[] ground.body;
}
int main()
{
	game();
	return 0;
}