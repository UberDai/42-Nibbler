//          `--::-.`
//      ./shddddddddhs+.
//    :yddddddddddddddddy:
//  `sdddddddddddddddddddds`
//  ydddh+sdddddddddy+ydddds  Graphics.cpp
// /ddddy:oddddddddds:sddddd/ By adebray - adebray
// sdddddddddddddddddddddddds
// sdddddddddddddddddddddddds Created: 2015-07-23 23:54:14
// :ddddddddddhyyddddddddddd: Modified: 2015-07-29 02:46:56
//  odddddddd/`:-`sdddddddds
//   +ddddddh`+dh +dddddddo
//    -sdddddh///sdddddds-
//      .+ydddddddddhs/.
//          .-::::-`

#include <iostream>
#include "Graphics.hpp"

extern "C" {
	t_action	g_action;

	void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		(void)window;
		(void)scancode;
		(void)mods;
		if (key == GLFW_KEY_P && action == GLFW_PRESS){
			std::cout << "Test" << std::endl;
			g_action = PAUSE;
		}
		else if (key == GLFW_KEY_LEFT && action == GLFW_PRESS)
			g_action = RIGHT;
		else if (key == GLFW_KEY_RIGHT && action == GLFW_PRESS)
			g_action = LEFT;
		else if (key == GLFW_KEY_UP && action == GLFW_PRESS)
			g_action = UP;
		else if (key == GLFW_KEY_DOWN && action == GLFW_PRESS)
			g_action = DOWN;
	}
}

Graphics::Graphics(const Snake & s) : _snake(s)
{
	_winWidth = 800;
	_winHeight = 600;

	if (!glfwInit())
	{
		std::cout << "glfw init error" << std::endl;
		exit(-1);
	}


	_window = glfwCreateWindow(_winWidth, _winHeight, "Hello World", NULL, NULL);
	if (!_window)
	{
		glfwTerminate();
		exit(-1);
	}

	glfwMakeContextCurrent(_window);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0f, _winWidth, _winHeight, 0.0f, 0.0f, 1.0f);

	glfwSetKeyCallback(_window, &key_callback);
}

Graphics::~Graphics(void)
{
	glfwTerminate();
}

void		Graphics::update(void)
{
	glfwPollEvents();
	glib_action = g_action;
	draw();
}

void		Graphics::getLevelInfo()
{
	_width = _snake.level->width;
	_height = _snake.level->height;
	_scaleWidth = _winWidth / _width;
	_scaleHeight = _winHeight / _height;

	if (_scaleWidth < _scaleHeight)
		_drawScale = _scaleWidth;
	else
		_drawScale = _scaleHeight;
}

void		Graphics::_switch(int x, int y, int width, int height)
{
	switch (_snake.level->map[y][x])
	{
		case BLOCK_NONE:
			glColor3f(1.0f, 1.0f, 1.0f);
			drawCell(x * width, y * width, width, height);
			break;
		case BLOCK_WALL:
			glColor3f(0.9f, 0.9f, 0.9f);
			drawCell(x * width, y * width, width, height);
			break;
		case BLOCK_NOM:
			glColor3f(1.0f, 0.0f, 0.0f);
			drawCell(x * width, y * width, width, height);
			break;
		case BLOCK_HEAD:
			glColor3f(0.0f, 1.0f, 0.0f);
			drawCell(x * width, y * width, width, height);
			break;
		default:
			glColor3f(0.0f, 0.8f, 0.0f);
			drawCell(x * width, y * width, width, height);
		;
	}
}

void		Graphics::drawCell(int x, int y, int width, int height)
{
	glBegin(GL_QUADS);
	glVertex2f((GLfloat)x, (GLfloat)y);
	glVertex2f((GLfloat)x + width, (GLfloat)y);
	glVertex2f((GLfloat)x + width, (GLfloat)y + height);
	glVertex2f((GLfloat)x, (GLfloat)y + height);
	glEnd();
}

void		Graphics::draw(void)
{
	getLevelInfo();
	glClear(GL_COLOR_BUFFER_BIT);

	unsigned int i;
	unsigned int j;
	for (i = 0; i < _snake.level->width; i++)
	{
		for(j = 0; j < _snake.level->height; j++)
		{
			_switch(i, j, _drawScale, _drawScale);
		}
	}

	glfwSwapBuffers(_window);
}

IGraphics *	glib_instantiate(const Snake & s)
{
	return new Graphics(s);
}

void		glib_uninstantiate(IGraphics * g)
{
	delete g;
}
