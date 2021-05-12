#pragma once

class Vec2i {
public:
	Vec2i() {};
	Vec2i( int x, int y ) : x( x ), y( y ) {};
	Vec2i( const Vec2i& v ) : x( v.x ), y( v.y ) {};

	int x = 0, y = 0;
};


class Obstacle {
public:
	Obstacle( const Vec2i& pos, int taille ) : pos( pos ), taille( taille ) {};

	Vec2i pos;
	int taille;
};


enum orientation { HAUT, DROITE, BAS, GAUCHE };


class Utils {

public:
	// https://www.geeksforgeeks.org/minimum-distance-from-a-point-to-the-line-segment-using-vectors/
	// Function to return the minimum distance
	// between a line segment AB and a point E
	static double minDistance( const Vec2i& _A, const Vec2i& _B, const Vec2i& _E )
	{
		using namespace std;
		using Point = pair<double, double>;

		Point A{ _A.x, _A.y };
		Point B{ _B.x, _B.y };
		Point E{ _E.x, _E.y };

		// vector AB
		Point AB;
		AB.first = B.first - A.first;
		AB.second = B.second - A.second;

		// vector BP
		Point BE;
		BE.first = E.first - B.first;
		BE.second = E.second - B.second;

		// vector AP
		Point AE;
		AE.first = E.first - A.first;
		AE.second = E.second - A.second;

		// Variables to store dot product
		double AB_BE, AB_AE;

		// Calculating the dot product
		AB_BE = (AB.first * BE.first + AB.second * BE.second);
		AB_AE = (AB.first * AE.first + AB.second * AE.second);

		// Minimum distance from
		// point E to the line segment
		double reqAns = 0;

		if( AB_BE > 0 ) {
			double y = E.second - B.second;
			double x = E.first - B.first;
			reqAns = sqrt( x * x + y * y );

		}
		else if( AB_AE < 0 ) {
			double y = E.second - A.second;
			double x = E.first - A.first;
			reqAns = sqrt( x * x + y * y );

		}
		else {
			double x1 = AB.first;
			double y1 = AB.second;
			double x2 = AE.first;
			double y2 = AE.second;
			double mod = sqrt( x1 * x1 + y1 * y1 );
			reqAns = abs( x1 * y2 - y1 * x2 ) / mod;
		}
		return reqAns;
	}
};

