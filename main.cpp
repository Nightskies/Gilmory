#include "WindoW.h"

WindoW MainWindow;

int main(int argc, char **argv)
{

	int Mainmenu,colormenu,deletemenu,windowcolor,trianglescolor, trianglescolor2;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(MainWindow.getWidth(), MainWindow.getHeight());
	glutCreateWindow(MainWindow.getHeader().c_str());
	glutDisplayFunc(Window_Functions::Draw);
	glutReshapeFunc(Window_Functions::Reshape);
	glutSpecialFunc(Window_Functions::processSpecialKeys);
	glutKeyboardFunc(Window_Functions::Keyboard);
	glutMouseFunc(Window_Functions::Mouse);
	Menu_Functions::Create_menu();

	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();

	return 0;
}