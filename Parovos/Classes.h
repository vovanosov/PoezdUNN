#pragma once
#include <math.h>
#include <iostream>


using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

class MyRectаngle
{
protected: // (private:)
	int x, y;
	int weight, height;
public:
	Void MyRectangle(int _x, int _y, int _weight, int _height)
	{
		x = _x;
		y = _y;
		weight = _weight;
		height = _height;
	}
	void move(int dx)
	{
		x += dx;
	}
	virtual void draw(Graphics^ A) = 0;
};

class wind : public MyRectаngle
{
public:
	wind(int xl = 0, int yl = 0, int h = 0)
	{
		x = xl;
		y = yl;
		weight = h * 3;
		height = h * 3;
	}
	void draw(Graphics^ A)
	{
		A->FillRectangle((Brushes::LightBlue), x, y, weight,height);
		A->DrawRectangle(gcnew Pen(Color::DarkBlue), x, y, weight, height);
	}
};

class door : public MyRectаngle
{
public:
	door(int xl, int yl, int h)
	{
		x = xl;
		y = yl;
		weight = h * 4;
		height = h * 7;
	}
	void draw(Graphics^ A)
	{
		A->FillRectangle((Brushes::Gray), x, y, weight, height);
		A->DrawRectangle(gcnew Pen(Color::Black), x, y, weight, height);
	}
};

class korp : public MyRectаngle
{
public:
	korp(int xl, int yl, int h)
	{
		x = xl;
		y = yl;
		weight = h * 20;
		height = h * 10;
	}
	void draw(Graphics^ A)
	{
		A->FillRectangle((Brushes::DarkGray), x, y, weight, height);
		A->DrawRectangle(gcnew Pen(Color::Black), x, y, weight, height);
	}
};

class truba : public MyRectаngle
{
public:
	truba(int xl, int yl, int h)
	{
		x = xl;
		y = yl;
		weight = h * 2;
		height = h * 5;
	}
	void draw(Graphics^ A)
	{
		A->FillRectangle((Brushes::DarkRed), x, y, weight, height);
		A->DrawRectangle(gcnew Pen(Color::Black), x, y, weight, height);
	}
};

class kol : public MyRectаngle
{
public:
	kol(int xl, int yl, int h)
	{
		x = xl;
		y = yl;
		weight = h * 4;
		height = h * 4;
	}
	void draw(Graphics^ A)
	{
		
		//A->DrawEllipse(gcnew Pen(Color::BlueViolet, 5), 250, 250, 200, 200);
		A->FillEllipse(Brushes::LightYellow, x, y,weight, height);
		A->DrawEllipse(Pens::Black, x, y, weight, height);
		//A->FillRectangle(Brushes::Tomato, 110, 110, 1, 1);
	}
};

class van
{
private:
	korp* c;
	door* d;
	wind* ws;
	kol* leftk;
	kol* rightk;
public:
	van(int x = 0, int y = 0, int h = 0)
	{
		c = new korp(x, y, h);
		d = new door(x, y + h * 3, h);
		ws = new wind[3];
		for (int i = 0; i < 3; i++)
		{
			ws[i] = wind(x + (4 + 2 * (i + 1) + 3 * i)*h, y + 2*h, h);
		}
		leftk = new kol(x + 3 * h, y + 10 * h, h);
		rightk = new kol(x + 13 * h, y + 10 * h, h);
	}
	void draw(Graphics^ g) {
		c->draw(g);
		d->draw(g);
		for (int i = 0; i < 3; i++)
		{
			ws[i].draw(g);
		}
		leftk->draw(g);
		rightk->draw(g);
	}

	void move(int dx)
	{
		c->move(dx);
		d->move(dx);
		for (int i = 0; i < 3; i++)
		{
			ws[i].move(dx);
		}
		leftk->move(dx);
		rightk->move(dx);
	}
};

class Myline
{
private:
	int x_beg, y_beg, x_end, y_end;
public:
	Myline(int x_b = 0, int y_b = 0, int x_e = 0, int y_e = 0)
	{
		x_beg = x_b;
		y_beg = y_b;
		x_end = x_e;
		y_end = y_e;
	}
	void DrawMyline(Graphics^ g)
	{
		//Pen^ pero = gcnew Pen(Color::Black);
		g->DrawLine(gcnew Pen(Color::DarkRed), x_beg, y_beg, x_end, y_end);
	}
	void Move(int dxb=0, int dyb=0, int dxe=0, int dye=0)
	{
		x_beg += dxb;
		y_beg += dyb;
		x_end += dxe;
		y_end += dye;
	}
};

class Engine
{
	Myline left;
	Myline middle;
	Myline right;
	int xm, ym, hm, xmm, ymm;
public:
	Engine(int x_m, int y_m, int h)
	{
		left = Myline(x_m, y_m, x_m, y_m - h);
		middle = Myline(x_m, y_m - h, x_m + 10 * h, y_m - h);
		right = Myline(x_m + 10 * h, y_m, x_m + 10 * h, y_m - h);
		xm = x_m; ym = y_m; hm = h; 
		xmm = x_m; //center x
		ymm = y_m-h; //center y
	}

	void Move(int d_x)
	{
		double l = hm;
		double R = hm * 2;
		double sina=d_x/R; //математика
		double cosa = sqrt(1 - sina * sina);
		double c = 2*l*l-2*cosa*l*l; // если мы наоборот, будем знать чему равно расстояние от начальной до конечной точки, то наоборот выражаем угол и находим координаты конечной точки
		double dx_m = 0;//c*cosa;
		double dy_m = 0;// c* sina;
		/*if ((xm < xmm && ym - hm == ymm))
			dx_m = -dx_m;
		if ((xm == xmm && ym - hm > ymm))
			dy_m = -dy_m;
		xm += d_x + dx_m;
		ym += dy_m;
		xmm += d_x;*/
		//std::cout << xm << " " << ym << std::endl;
		left.Move(d_x, 0, d_x+dx_m, dy_m);
		middle.Move(d_x+dx_m, dy_m, d_x+dx_m, dy_m);
		right.Move(d_x, 0, d_x+dx_m, dy_m);
		
	}
	void draw(Graphics^ g)
	{
		left.DrawMyline(g);
		middle.DrawMyline(g);
		right.DrawMyline(g);
	}
};

class parovos
{
	van* vagon;
	truba* tr;
	Engine* dvijok;
public:
	parovos(int xL, int yL, int h)
	{
		vagon = new van(xL, yL, h);
		tr = new truba(xL + 16 * h, yL - 5 * h, h);
		dvijok = new Engine(xL + 5 * h, yL + 12 * h, h);
	}
	parovos(const parovos* tmp)
	{
		vagon = tmp->vagon;
		tr = tmp->tr;
		dvijok = tmp->dvijok;
	}
	parovos& operator= (parovos tmp)
	{
		delete vagon;
		delete dvijok;
		vagon = tmp.vagon;
		tr = tmp.tr;
		dvijok = tmp.dvijok;
	}

	void draw(Graphics ^ g) {
		vagon->draw(g);
		tr->draw(g);
		dvijok->draw(g);
	}

	void move(int dx) {
		vagon->move(dx);
		tr->move(dx);
		dvijok->Move(dx);
	}

	~parovos()
	{
		delete vagon;
		delete dvijok;
	}
};

class train
{
private:
	parovos* Mai;
	van* much;
	Myline* lines;
	int count = 0;

public:
	train(int rdx = 0, int rdy = 0, int h = 0, int n = 0) {
		Mai = new parovos(rdx - 20 * h, rdy - 10 * h, h);
		much = new van[n];
		lines = new Myline[n];
		for (int i = 0; i < n; i++)
		{
			much[i] = van(rdx - (i + 2) * 20 * h - (i + 1) * h, rdy - 10 * h, h);
			lines[i] = Myline(rdx - (i + 1) * 21 * h, rdy, rdx - (i + 1) * 20 * h - (i) * h, rdy);
		}
		count = n;
	}
	train(const train* tmp)
	{
		count = tmp->count;
		Mai = tmp->Mai;
		much = new van[count];
		lines = new Myline[count];
		for (int i = 0; i < count; i++)
		{
			much[i] = tmp->much[i];
			lines[i] = tmp->lines[i];
		}
	}
	
	train& operator=(train tmp)
	{
		if (count != tmp.count)
		{
			if (count != 0)
			{
				delete[] much;
				delete[] lines;
			}
			count = tmp.count;
			much = new van[tmp.count];
			lines = new Myline[tmp.count];
		}
		for (int i = 0; i < count; i++)
		{
			much[i] = tmp.much[i];
			lines[i] = tmp.lines[i];
		}
		//delete Mai;
		Mai = tmp.Mai;
		return *this;
	}
	
	/*~train()
	{
		delete Mai;
		delete much;
		delete[] lines;
	}*/
	
	void move(int dx)
	{
		Mai->move(dx);
		for (int i = 0; i < count; i++)
		{
			much[i].move(dx);
			lines[i].Move(dx,0,dx,0);
		}
		
	}

	void draw(Graphics^ g)
	{
		Mai->draw(g);
		for (int i = 0; i < count; i++)
		{
			much[i].draw(g);
			lines[i].DrawMyline(g);
		}
	}
};


