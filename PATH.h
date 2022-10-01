// PATH.h
#include <iostream>
#include <vector>
#ifndef PATH_H
#define PATH_H

class PATH
{

public:
	std::vector<std::string> pathData;
	std::string toString();
	void moveTo(int x, int y, bool relative);
	void M(int x, int y);
	void m(int x, int y);
	void lineTo(int x, int y, bool relative);
	void L(int x, int y);
	void l(int x, int y);
	void horizontalTo(int x, bool relative);
	void H(int x);
	void h(int x);
	void verticalTo(int y, bool relative);
	void V(int y);
	void v(int y);
	void qCurve(int cx, int cy, int ex, int ey, bool relative);
	void Q(int cx, int cy, int ex, int ey);
	void q(int cx, int cy, int ex, int ey);
	void tCurve(int ex, int ey, bool relative);
	void T(int ex, int ey);
	void t(int ex, int ey);
	void cCurve(int cx1, int cy1, int cx2, int cy2, int ex, int ey, bool relative);
	void C(int cx1, int cy1, int cx2, int cy2, int ex, int ey);
	void c(int cx1, int cy1, int cx2, int cy2, int ex, int ey);
	void sCurve(int cx, int cy, int ex, int ey, bool relative);
	void S(int cx, int cy, int ex, int ey);
	void s(int cx, int cy, int ex, int ey);
	void arc(int rx, int ry, int rotation, int arc, int sweep, int ex, int ey, bool relative);
	void A(int rx, int ry, int rotation, int arc, int sweep, int ex, int ey);
	void a(int rx, int ry, int rotation, int arc, int sweep, int ex, int ey);
	void down(int px);
	void right(int px);
	void up(int px);
	void left(int px);
	void close();
};
#endif
