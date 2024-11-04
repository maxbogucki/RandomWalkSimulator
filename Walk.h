#include <iostream>
#include "Walk.h"
#include <cmath>
#include "UtilRand.h"
using namespace std;

class Walk {
private:
	double x, y, distance;

public:
	Walk();
	void setX(double x);
	double getX() const;
	void setY(double y);
	double getY() const;
	void setDistance(double distance);
	double getDistance() const;
	int generateAngle();
	int generateLength();
	double convertToRadians(double degree);
	void walkAgain();
};

ostream& operator<<(ostream& os, const Walk& w);
