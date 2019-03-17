#include "WindoW.h"

extern WindoW MainWindow;

std::vector<Triangle> Triangles;

unsigned char num = 0; // Номер текущего множества

bool f = false;

std::vector<unsigned char> Map_selection; // Содержит кол-во примитовов множества номера num

WindoW::WindoW(unsigned short width, unsigned short height, std::string header)
	: Width(width), Height(height), Header(header),Draw_mode(false)
{
	ColorWindow.R = 0.9;
	ColorWindow.G = 0.2;
	ColorWindow.B = 0.4;

}

void Window_Functions::Reshape(int w, int h)
{

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h);
	gluOrtho2D(0, w, 0, h);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();	
}

void Window_Functions::processSpecialKeys(int key, int x, int y) {
	//Перемещение по карте множеств
	if (key == GLUT_KEY_UP) 
	{
		if (!Triangles.empty()) {
			if (num + 1 >= Map_selection.size())
				num = 0;
			else
				++num;

			std::cout << "syslog: Current selection at number: " << (int)num << " size this selection " << (int)Map_selection[num] << std::endl;
			glutPostRedisplay();
		}
		
		return;
	}
	else if (key == GLUT_KEY_DOWN)
	{
		if (!Triangles.empty()) {
			if (num - 1 < 0) {
				if (Map_selection.empty()) {
					num = 0;

				}
				else if (!Triangles.empty()) {
					num = Map_selection.size() - 1;
				}

				std::cout << "syslog: Current selection at number: " << (int)num << " size this selection " << (int)Map_selection[num] << std::endl;
			}
			else
			{
				--num;
				std::cout << "syslog: Current selection at number: " << (int)num << " size this selection " << (int)Map_selection[num] << std::endl;
			}
			glutPostRedisplay();
		}
		return;
	}
	// Инициализация точки
	Point point;
	if (Triangles.size() == 0)
	{
		Triangle triangle;
		std::cout << "syslog: set_triangle" << std::endl;
		Triangles.push_back(triangle);
		Map_selection.push_back(1);
	}
	if (Triangles.back().Vertices.size() == 3)
	{
		Triangle triangle;
		std::cout << "syslog: set_triangle" << std::endl;
		Triangles.push_back(triangle);
		Map_selection[num]++;
	}

	switch (key) {

	case GLUT_KEY_F1:
		point.ColorPoint.r = 255;
		point.ColorPoint.g = 0;
		point.ColorPoint.b = 0;
		Triangles.back().init(point);
		MainWindow.Draw_mode = true;
		std::cout << "syslog: create_red_point" << std::endl;
		break;
	case GLUT_KEY_F2:
		point.ColorPoint.r = 0;
		point.ColorPoint.g = 255;
		point.ColorPoint.b = 0;
		Triangles.back().init(point);
		MainWindow.Draw_mode = true;
		std::cout << "syslog: create_lime_point" << std::endl;
		break;
	case GLUT_KEY_F3:
		point.ColorPoint.r = 0;
		point.ColorPoint.g = 0;
		point.ColorPoint.b = 128;
		Triangles.back().init(point);
		MainWindow.Draw_mode = true;
		std::cout << "syslog: create_blue_point" << std::endl;
		break;
	case GLUT_KEY_F4:
		point.ColorPoint.r = 255;
		point.ColorPoint.g = 255;
		point.ColorPoint.b = 0;
		Triangles.back().init(point);
		MainWindow.Draw_mode = true;
		std::cout << "syslog: create_yellow_point" << std::endl;
		break;
	case GLUT_KEY_F5:
		point.ColorPoint.r = 75;
		point.ColorPoint.g = 0;
		point.ColorPoint.b = 130;
		Triangles.back().init(point);
		MainWindow.Draw_mode = true;
		std::cout << "syslog: create_indigo_point" << std::endl;
		break;
	case GLUT_KEY_F6:
		point.ColorPoint.r = 255;
		point.ColorPoint.g = 69;
		point.ColorPoint.b = 0;
		Triangles.back().init(point);
		MainWindow.Draw_mode = true;
		std::cout << "syslog: create_orange_red_point" << std::endl;
		break;
	case GLUT_KEY_F7:
		point.ColorPoint.r = 0;
		point.ColorPoint.g = 0;
		point.ColorPoint.b = 0;
		Triangles.back().init(point);
		MainWindow.Draw_mode = true;
		std::cout << "syslog: create_black_point" << std::endl;
		break;
	case GLUT_KEY_F8:
		point.ColorPoint.r = 255;
		point.ColorPoint.g = 255;
		point.ColorPoint.b = 255;
		Triangles.back().init(point);
		MainWindow.Draw_mode = true;
		std::cout << "syslog: create_white_point" << std::endl;
		break;
	case GLUT_KEY_F9:
		point.ColorPoint.r = 128;
		point.ColorPoint.g = 0;
		point.ColorPoint.b = 128;
		Triangles.back().init(point);
		MainWindow.Draw_mode = true;
		std::cout << "syslog: create_purple_point" << std::endl;
		break;
	default:
		break;
	}

}

void Window_Functions::Keyboard(unsigned char key, int x, int y)
{
	switch (key) {

	case ' ':
		if (!Triangles.empty()) {
			++num;
			Map_selection.push_back(0);
			std::cout << "syslog: set new selection at number " << (int)num << std::endl;
		}
		break;
	default:
		Menu_Functions::Move_selection(key);
		break;
	}
}

void Menu_Functions::Color_window(int option)
{

	switch (option)
	{
	case 1:
		MainWindow.ColorWindow.R += 0.1;
		break;
	case 2:
		MainWindow.ColorWindow.G += 0.1;
		break;
	case 3:
		MainWindow.ColorWindow.B += 0.1;
		break;
	case 4:
		MainWindow.ColorWindow.B -= 0.1;
		break;
	case 5:
		MainWindow.ColorWindow.B -= 0.1;
		break;
	case 6:
		MainWindow.ColorWindow.B -= 0.1;
		break;
	default:
		break;
	}
	glutPostRedisplay();
}

void Menu_Functions::Color_selection(int option)
{
	ColorPoint newcolor;

	switch (option)
	{
	case 1:
		newcolor.r = 255;
		newcolor.g = 0;
		newcolor.b = 0;
		Change_color_selection(newcolor);
		break;
	case 2:
		newcolor.r = 0;
		newcolor.g = 255;
		newcolor.b = 0;
		Change_color_selection(newcolor);
		break;
	case 3:
		newcolor.r = 0;
		newcolor.g = 0;
		newcolor.b = 255;
		Change_color_selection(newcolor);
		break;
	default:
		break;
	}
}

void Menu_Functions::Helper_current_selection(std::vector<Triangle>::iterator &i, std::vector<Triangle>::iterator &g)
{

	int h = 0;

	if (num == 0) {
		g = Triangles.begin() + Map_selection[0];
		if(f)Map_selection.erase(Map_selection.begin());
	}

	if ((num > 0) && (num == Map_selection.size() - 1))
	{

		for (int i = 0; i < Map_selection.size() - 1; i++)
		{
			h += Map_selection[i];
		}

		i = Triangles.begin() + h;
		h = 0;
		if (f) {
			Map_selection.erase(Map_selection.end() - 1);
			--num;
		}
	}

	if ((num > 0) && (num < Map_selection.size() - 1))
	{

		for (int i = 0; i <= num - 1; i++)
		{
			h += Map_selection[i];
		}
		i = Triangles.begin() + h;
		h = 0;

		for (int i = 0; i <= num; i++)
		{
			h += Map_selection[i];
		}
		g = Triangles.begin() + h;
		h = 0;
		if (f) {
			Map_selection.erase(Map_selection.begin() + num);
			--num;
		}
	}

}

void Menu_Functions::Move_selection(char symbol)
{

		auto i = Triangles.begin();
		auto g = Triangles.end();
		Helper_current_selection(i, g);
		switch (symbol)
		{
		case'a':
			for (auto a = i; a != g; ++a)
			{
				if (((a->Vertices[0].x - 10) > 0) && ((a->Vertices[1].x - 10) > 0) && ((a->Vertices[2].x - 10) > 0)) {
					a->Vertices[0].x -= 10;
					a->Vertices[1].x -= 10;
					a->Vertices[2].x -= 10;
					
				}
			}
			break;
		case'w':		
				for (auto a = i; a != g; ++a)
				{
					
					if (((a->Vertices[0].y - 10) > 0) && ((a->Vertices[1].y - 10 ) > 0) && ((a->Vertices[2].y - 10 )> 0))
					{
						a->Vertices[0].y -= 10;
						a->Vertices[1].y -= 10;
						a->Vertices[2].y -= 10;
						
					}		
				}
			break;
		case's':
			for (auto a = i; a != g; ++a)
			{
				if (((a->Vertices[0].y + 10) < MainWindow.getHeight()) && ((a->Vertices[1].y + 10) < MainWindow.getHeight()) && ((a->Vertices[2].y + 10) < MainWindow.getHeight())) {
					a->Vertices[0].y += 10;
					a->Vertices[1].y += 10;
					a->Vertices[2].y += 10;
				
				}
			}
			break;
		case'd':
			for (auto a = i; a != g; ++a)
			{
				if (((a->Vertices[0].x + 10) < MainWindow.getWidth()) && ((a->Vertices[1].x + 10) < MainWindow.getWidth()) && ((a->Vertices[2].x + 10) < MainWindow.getWidth())) {
					a->Vertices[0].x += 10;
					a->Vertices[1].x += 10;
					a->Vertices[2].x += 10;
					
				}
			}
			break;
		default:
			break;
		}
		glutPostRedisplay();
	}

void Menu_Functions::Change_color_selection(ColorPoint &newcolor)
{
	auto i = Triangles.begin();
	auto g = Triangles.end();
    Helper_current_selection(i, g);

	for (auto a = i ; a != g ; ++a)
	{
		a->Vertices[0].ColorPoint = newcolor;
		a->Vertices[1].ColorPoint = newcolor;
		a->Vertices[2].ColorPoint = newcolor;
	}
	glutPostRedisplay();
}

void Menu_Functions::Color_all_selections(int option)
{
	ColorPoint newcolor;

	switch (option)
	{
	case 1:
		newcolor.r = 255;
		newcolor.g = 0;
		newcolor.b = 0;
		Color_all_selection_helper(newcolor);
		break;
	case 2:
		newcolor.r = 0;
		newcolor.g = 255;
		newcolor.b = 0;
		Color_all_selection_helper(newcolor);
		break;
	case 3:
		newcolor.r = 0;
		newcolor.g = 0;
		newcolor.b = 255;
		Color_all_selection_helper(newcolor);
		break;
	default:
		break;
	}
	glutPostRedisplay();
}

void Menu_Functions::Color_all_selection_helper(ColorPoint &newcolor)
{
	for (auto i = Triangles.begin(); i != Triangles.end(); ++i)
	{
		i->Vertices[0].ColorPoint = newcolor;
		i->Vertices[1].ColorPoint = newcolor;
		i->Vertices[2].ColorPoint = newcolor;
	}
}

void Menu_Functions::Delete_selection(void)
{
	auto i = Triangles.begin();
	auto g = Triangles.end();

	f = true;
	Helper_current_selection(i, g);	
	Triangles.erase(i, g);
	f = false;
} 

void Window_Functions::Draw(void)
{
	glClearColor(MainWindow.ColorWindow.R, MainWindow.ColorWindow.G, MainWindow.ColorWindow.B,1);
	glClear(GL_COLOR_BUFFER_BIT);
	glEnable(GL_POINT_SMOOTH);

	if (!Triangles.empty()) {
		auto i = Triangles.begin();
		auto g = Triangles.end();
		Menu_Functions::Helper_current_selection(i, g);

		for (auto t = Triangles.begin(); t != i; ++t)
		{
			glPointSize(2);
			Draw_Helper(t);
		}
		for (auto t = i; t != g; ++t)
		{
			glPointSize(5);
			Draw_Helper(t);
		}
		for (auto t = g; t != Triangles.end(); ++t)
		{
			glPointSize(2);
			Draw_Helper(t);
		}
	}
	glutSwapBuffers();
	
}

void Window_Functions::Draw_Helper(std::vector<Triangle>::iterator &t)
{
	
	if (t->Vertices.size() == 3) {
				glBegin(GL_TRIANGLES);
				glColor3ub(t->Vertices[0].ColorPoint.r, t->Vertices[0].ColorPoint.g, t->Vertices[0].ColorPoint.b);
				glVertex3i(t->Vertices[0].x, MainWindow.getHeight() - t->Vertices[0].y, 0);
				glColor3ub(t->Vertices[1].ColorPoint.r, t->Vertices[1].ColorPoint.g, t->Vertices[1].ColorPoint.b);
				glVertex3i(t->Vertices[1].x, MainWindow.getHeight() - t->Vertices[1].y, 0);
				glColor3ub(t->Vertices[2].ColorPoint.r, t->Vertices[2].ColorPoint.g, t->Vertices[2].ColorPoint.b);
				glVertex3i(t->Vertices[2].x, MainWindow.getHeight() - t->Vertices[2].y, 0);
				glEnd();
			}

			for (const auto &i : t->Vertices) {
				glBegin(GL_POINTS);
				glColor3ub
				(

					i.ColorPoint.r,
					i.ColorPoint.g,
					i.ColorPoint.b
				);
				glVertex2i(i.x, MainWindow.getHeight() - i.y);
				glEnd();
			}
}

void Window_Functions::Mouse(int button, int state, int x, int y)
{
	if (state != GLUT_UP) return;

	if (button == GLUT_LEFT_BUTTON)
	{
		if (MainWindow.Draw_mode) 
		{
			Triangles.back().add_coord_vertex(x,y);
			std::cout << "syslog: set_coordinates_point" << std::endl;
			MainWindow.Draw_mode = false;
		}
		else return;
	}

}

void Menu_Functions::Create_menu(void)
{
	int Mainmenu, colormenu, deletemenu, windowcolor, trianglescolor, trianglescolor2;
	windowcolor = glutCreateMenu(Menu_Functions::Color_window);
	glutAddMenuEntry("Increase red", Redinc);
	glutAddMenuEntry("Increase green", Greeninc);
	glutAddMenuEntry("Increase blue", Blueinc);
	glutAddMenuEntry("Decrease red", Reddec);
	glutAddMenuEntry("Decrease green", Greendec);
	glutAddMenuEntry("Decrease blue", Bluedec);

	trianglescolor = glutCreateMenu(Menu_Functions::Color_selection);
	glutAddMenuEntry("Set red color", Red);
	glutAddMenuEntry("Set green color", Green);
	glutAddMenuEntry("Set blue color", Blue);

	trianglescolor2 = glutCreateMenu(Menu_Functions::Color_all_selections);
	glutAddMenuEntry("Set red color", Red);
	glutAddMenuEntry("Set green color", Green);
	glutAddMenuEntry("Set blue color", Blue);

	deletemenu = glutCreateMenu(Menu_Functions::Delete_menu);
	glutAddMenuEntry("Delete current variety", 1);
	glutAddMenuEntry("Delete last primitive", 2);
	glutAddMenuEntry("Clear window", 3);

	colormenu = glutCreateMenu(Menu_Functions::Color_menu);
	glutAddSubMenu("Window color", windowcolor);
	glutAddSubMenu("Current selection color", trianglescolor);
	glutAddSubMenu("Set color for all", trianglescolor2);

	Mainmenu = glutCreateMenu(Menu_Functions::Main_menu);
	glutAddSubMenu("Change color", colormenu);
	glutAddSubMenu("Delete", deletemenu);
}

void Menu_Functions::Main_menu(int option)
{

}

void Menu_Functions::Color_menu(int option)
{
}

void Menu_Functions::Delete_menu(int option)
{
	switch (option)
	{
	case 1:
		Delete_selection();
		break;
	case 2:
		Triangles.pop_back();
		break;
	case 3:
		Triangles.clear();
		Map_selection.clear();
		num = 0;
		break;
	default:
		break;
	}
	glutPostRedisplay();
}