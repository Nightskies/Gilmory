#pragma once
#include <string>
#include <iostream>
#include "Triangle.h"


constexpr auto Red = 1;
constexpr auto Green = 2;
constexpr auto Blue = 3;
constexpr auto Redinc = 1;
constexpr auto Greeninc = 2;
constexpr auto Blueinc = 3;
constexpr auto Reddec = 4;
constexpr auto Greendec = 5;
constexpr auto Bluedec = 6;

namespace Window_Functions
{

	void Mouse(int, int, int, int);

	void Draw(void);

	void Draw_Helper(std::vector<Triangle>::iterator &);

	void Reshape(int, int);

	void processSpecialKeys(int, int, int);

	void Keyboard(unsigned char, int, int);


}

namespace Menu_Functions
{
	void Color_window(int);// Цвет для окна

	void Create_menu(void);

	void Main_menu(int);

	void Delete_selection(void);// Удалить текущие множество

	void Main_menu(int);

	void Color_menu(int);

	void Delete_menu(int);

	void Color_selection(int);// Цвет для текущего множества

	void Helper_current_selection(std::vector<Triangle>::iterator & , std::vector<Triangle>::iterator &);//Выделяет начало и конец текущего множества из общего

	void Change_color_selection(ColorPoint &);

	void Color_all_selections(int);// Цвет для всех примитивов

	void Color_all_selection_helper(ColorPoint &);

	void Move_selection(char);//Перемещение текущего множества 

}


class WindoW
{
public:

	WindoW(unsigned short Width = 800, unsigned short Height = 600, std::string header = "lab 1");

	unsigned short getWidth()const { return Width; }

	unsigned short getHeight()const { return Height; }


	std::string getHeader()const { return Header; }


	ColorWindow ColorWindow;

	bool Draw_mode;


private:

	unsigned short Width;

	unsigned short Height;

	std::string Header;


};


