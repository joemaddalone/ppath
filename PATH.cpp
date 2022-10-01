#include <iostream>
#include <sstream>
#include "PATH.h"

/**
 * Return joined pathData array.
 * @name PATH#toString
 * @function
 * @return {string}
 */
std::string PATH::toString()
{
	std::string s;
	for (std::vector<std::string>::const_iterator i = PATH::pathData.begin(); i != PATH::pathData.end(); ++i)
		s += *i;
	return s;
}

/**
 * Move cursor to x, y. If relative is true, x, y is relative to current position.
 * @name PATH#moveTo
 * @function
 * @param {number} x - x coordinate
 * @param {number} y - y coordinate
 * @param {boolean} [relative=false] - relative move
 */
void PATH::moveTo(int x, int y, bool relative = false)
{
	std::stringstream sstm;
	sstm << (relative ? "m" : "M") << x << " " << y;
	PATH::pathData.push_back(sstm.str());
}

/**
 * Move cursor to x, y absolute position.
 * @name PATH#M
 * @function
 * @param {number} x - x coordinate
 * @param {number} y - y coordinate
 */
void PATH::M(int x, int y)
{
	PATH::moveTo(x, y, false);
}

/**
 * Move cursor to x, y relative to current position.
 * @name PATH#m
 * @function
 * @param {number} x - x coordinate
 * @param {number} y - y coordinate
 */
void PATH::m(int x, int y)
{
	PATH::moveTo(x, y, true);
}

/**
 * Draw straight line to x, y. If relative is true, x, y is relative to current position.
 * @name PATH#lineTo
 * @function
 * @param {number} x - x coordinate
 * @param {number} y - y coordinate
 * @param {boolean} [relative=false]
 */
void PATH::lineTo(int x, int y, bool relative = false)
{
	std::stringstream sstm;
	sstm << (relative ? "l" : "L") << x << " " << y;
	PATH::pathData.push_back(sstm.str());
}

/**
 * Draw straight line to x, y absolute position.
 * @name PATH#L
 * @function
 * @param {number} x - x coordinate
 * @param {number} y - y coordinate
 */
void PATH::L(int x, int y)
{
	PATH::lineTo(x, y, false);
}

/**
 * Draw straight line to x, y relative to current position.
 * @name PATH#l
 * @function
 * @param {number} x - x coordinate
 * @param {number} y - y coordinate
 */
void PATH::l(int x, int y)
{
	PATH::lineTo(x, y, true);
}

/**
 * Draw a horizontal line to x. If relative is true, x is relative to current position.
 * @name PATH#horizontalTo
 * @function
 * @param {number} x - x coordinate
 * @param {boolean} [relative=false] - relative move
 */
void PATH::horizontalTo(int x, bool relative = false)
{
	std::stringstream sstm;
	sstm << (relative ? "h" : "H") << x;
	PATH::pathData.push_back(sstm.str());
}

/**
 * Draw a horizontal line to x absolute position.
 * @name PATH#H
 * @function
 * @param {number} x - x coordinate
 */
void PATH::H(int x)
{
	PATH::horizontalTo(x, false);
}

/**
 * Draw a horizontal line to x relative to current position.
 * @name PATH#h
 * @function
 * @param {number} x - x coordinate
 */
void PATH::h(int x)
{
	PATH::horizontalTo(x, true);
}

/**
 * Draw a vertical line to y. If relative is true, y is relative to current position.
 * @name PATH#verticalTo
 * @function
 * @param {number} y - y coordinate
 * @param {boolean} [relative=false] - relative move
 */
void PATH::verticalTo(int y, bool relative = false)
{
	std::stringstream sstm;
	sstm << (relative ? "v" : "V") << y;
	PATH::pathData.push_back(sstm.str());
}

/**
 * Draw a vertical line to y absolute position.
 * @name PATH#V
 * @function
 * @param {number} y - y coordinate
 */
void PATH::V(int y)
{
	PATH::verticalTo(y, false);
}

/**
 * Draw a vertical line to y relative to current position.
 * @name PATH#v
 * @function
 * @param {number} y - y coordinate
 */
void PATH::v(int y)
{
	PATH::verticalTo(y, true);
}

/**
 * Draw quadratic curve to ex, ey using cx,cy as the control point. If relative is true, points are relative to current position.
 * @name PATH#qCurve
 * @function
 * @param {number} cx - control point x coordinate
 * @param {number} cy - control point y coordinate
 * @param {number} ex - end x coordinate
 * @param {number} ey - end y coordinate
 * @param {boolean} [relative=false] - relative move
 */
void PATH::qCurve(int cx, int cy, int ex, int ey, bool relative = false)
{
	std::stringstream sstm;
	sstm << (relative ? "q" : "Q") << cx << " " << cy << " " << ex << " " << ey;
	PATH::pathData.push_back(sstm.str());
}

/**
 * Draw quadratic curve to absolute ex, ey using absolute cx,cy as the control point.
 * @name PATH#Q
 * @function
 * @param {number} cx - control point x coordinate
 * @param {number} cy - control point y coordinate
 * @param {number} ex - end x coordinate
 * @param {number} ey - end y coordinate
 */
void PATH::Q(int cx, int cy, int ex, int ey)
{
	PATH::qCurve(cx, cy, ex, ey, false);
}

/**
 * Draw quadratic curve to relative ex, ey using relative cx,cy as the control point.
 * @name PATH#q
 * @function
 * @param {number} cx - control point x coordinate
 * @param {number} cy - control point y coordinate
 * @param {number} ex - end x coordinate
 * @param {number} ey - end y coordinate
 */
void PATH::q(int cx, int cy, int ex, int ey)
{
	PATH::qCurve(cx, cy, ex, ey, true);
}

/**
 * Smooth quadratic curve to x, y. If relative is true, x, y is relative to current position.
 * @name PATH#tCurve
 * @function
 * @param {number} x - x coordinate
 * @param {number} y - y coordinate
 * @param {boolean} [relative=false] - relative move
 */
void PATH::tCurve(int ex, int ey, bool relative = false)
{
	std::stringstream sstm;
	sstm << (relative ? "l" : "L") << ex << " " << ey;
	PATH::pathData.push_back(sstm.str());
}

/**
 * Smooth quadratic curve to x, y absolute position.
 * @name PATH#T
 * @function
 * @param {number} x - x coordinate
 * @param {number} y - y coordinate
 */
void PATH::T(int ex, int ey)
{
	PATH::tCurve(ex, ey, false);
}

/**
 * Smooth quadratic curve to x, y relative to current position.
 * @name PATH#t
 * @function
 * @param {number} x - x coordinate
 * @param {number} y - y coordinate
 */
void PATH::t(int ex, int ey)
{
	PATH::tCurve(ex, ey, true);
}

/**
 * Draw cubic curve to ex, ey using cx1, cy1 & cx2, cy2 as the control points. If relative is true, points are relative to current position.
 * @name PATH#cCurve
 * @function
 * @param {number} cx1 - first control point x coordinate
 * @param {number} cy1 - first control point y coordinate
 * @param {number} cx2 - second control point x coordinate
 * @param {number} cy2 - second control point y coordinate
 * @param {number} ex - end x coordinate
 * @param {number} ey - end y coordinate
 * @param {boolean} [relative=false] - relative move
 */
void PATH::cCurve(int cx1, int cy1, int cx2, int cy2, int ex, int ey, bool relative = false)
{
	std::stringstream sstm;
	sstm << (relative ? "c" : "C") << cx1 << " " << cy1 << " " << cx2 << " " << cy2 << " " << ex << " " << ey;
	PATH::pathData.push_back(sstm.str());
}

/**
 * Draw cubic curve to relative ex, ey using relative cx1, cy1 & cx2, cy2 as the control points.
 * @name PATH#c
 * @function
 * @param {number} cx1 - first control point x coordinate
 * @param {number} cy1 - first control point y coordinate
 * @param {number} cx2 - second control point x coordinate
 * @param {number} cy2 - second control point y coordinate
 * @param {number} ex - end x coordinate
 * @param {number} ey - end y coordinate
 */
void PATH::c(int cx1, int cy1, int cx2, int cy2, int ex, int ey)
{
	PATH::cCurve(cx1, cy1, cx2, cy2, ex, ey, true);
}

/**
 * Draw cubic curve to absolute ex, ey using absolute cx1, cy1 & cx2, cy2 as the control points.
 * @name PATH#C
 * @function
 * @param {number} cx1 - first control point x coordinate
 * @param {number} cy1 - first control point y coordinate
 * @param {number} cx2 - second control point x coordinate
 * @param {number} cy2 - second control point y coordinate
 * @param {number} ex - end x coordinate
 * @param {number} ey - end y coordinate
 */
void PATH::C(int cx1, int cy1, int cx2, int cy2, int ex, int ey)
{
	PATH::cCurve(cx1, cy1, cx2, cy2, ex, ey, false);
}

/**
 * Smooth cubic curve to x, y using cx, cy as the control point. If relative is true, points are relative to current position.
 * @name PATH#sCurveTo
 * @function
 * @param {number} cx - control point x coordinate
 * @param {number} cy - control point y coordinate
 * @param {number} ex - end x coordinate
 * @param {number} ey - end y coordinate
 * @param {boolean} [relative=false] - relative move
 */
void PATH::sCurve(int cx, int cy, int ex, int ey, bool relative = false)
{
	std::stringstream sstm;
	sstm << (relative ? "s" : "S") << cx << " " << cy << " " << ex << " " << ey;
	PATH::pathData.push_back(sstm.str());
}

/**
 * Smooth cubic curve to relative x, y using relative cx, cy as the control point.
 * @name PATH#s
 * @function
 * @param {number} cx - control point x coordinate
 * @param {number} cy - control point y coordinate
 * @param {number} ex - end x coordinate
 * @param {number} ey - end y coordinate
 */
void PATH::s(int cx, int cy, int ex, int ey)
{
	PATH::sCurve(cx, cy, ex, ey, true);
}

/**
 * Smooth cubic curve to absolute x, y using absolute cx, cy as the control point.
 * @name PATH#S
 * @function
 * @param {number} cx - control point x coordinate
 * @param {number} cy - control point y coordinate
 * @param {number} ex - end x coordinate
 * @param {number} ey - end y coordinate
 */
void PATH::S(int cx, int cy, int ex, int ey)
{
	PATH::sCurve(cx, cy, ex, ey, false);
}

/**
 * Create arc. If relative is true, points are relative to current position.
 * @name PATH#arc
 * @function
 * @param {number} rx - x radius
 * @param {number} ry - y radius
 * @param {number} rotation - rotation
 * @param {boolean} arc - arc flag
 * @param {boolean} sweep - sweep flag
 * @param {number} ex - end x coordinate
 * @param {number} ey - end y coordinate
 * @param {boolean} [relative=false] - relative move
 */
void PATH::arc(int rx, int ry, int rotation, int arc, int sweep, int ex, int ey, bool relative = false)
{
	std::stringstream sstm;
	sstm << (relative ? "a" : "A") << rx << " " << ry << " " << rotation << " " << arc << " " << sweep << " " << ex << " " << ey;
	PATH::pathData.push_back(sstm.str());
}

/**
 * Create arc with absolute positioning
 * @name PATH#A
 * @function
 * @param {number} rx - x radius
 * @param {number} ry - y radius
 * @param {number} rotation - rotation
 * @param {boolean} arc - arc flag
 * @param {boolean} sweep - sweep flag
 * @param {number} ex - end x coordinate
 * @param {number} ey - end y coordinate
 */
void PATH::A(int rx, int ry, int rotation, int arc, int sweep, int ex, int ey)
{
	PATH::arc(rx, ry, rotation, arc, sweep, ex, ey, false);
}

/**
 * Create arc with relative positioning
 * @name PATH#a
 * @function
 * @param {number} rx - x radius
 * @param {number} ry - y radius
 * @param {number} rotation - rotation
 * @param {boolean} arc - arc flag
 * @param {boolean} sweep - sweep flag
 * @param {number} ex - end x coordinate
 * @param {number} ey - end y coordinate
 */
void PATH::a(int rx, int ry, int rotation, int arc, int sweep, int ex, int ey)
{
	PATH::arc(rx, ry, rotation, arc, sweep, ex, ey, true);
}

/**
 * Move down to relative point px away
 * @name PATH#down
 * @function
 * @param {number} px - number of pixels to move down
 */
void PATH::down(int px)
{
	PATH::v(px);
}

/**
 * Move right to relative point px away
 * @name PATH#right
 * @function
 * @param {number} px - number of pixels to move right
 */
void PATH::right(int px)
{
	PATH::h(px);
}

/**
 * Move up to relative point px away
 * @name PATH#up
 * @function
 * @param {number} px - number of pixels to move up
 */
void PATH::up(int px)
{
	PATH::v(px * -1);
}

/**
 * Move left to relative point px away
 * @name PATH#left
 * @function
 * @param {number} px - number of pixels to move left
 */
void PATH::left(int px)
{
	PATH::h(px * -1);
}

/**
 * Close path.
 * @name PATH#close
 * @function
 */
void PATH::close()
{
	PATH::pathData.push_back("z");
}