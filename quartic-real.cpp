#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
#include <windows.h>

double quarticreal(double a0, double b0, double c0, double d0, double e0)
{
	double tmp;
	double tmin = 65536;
	double sint, s;
	double r1, qds, rootint;

	double b = b0 / a0;
	double c = c0 / a0;
	double d = d0 / a0;
	double e = e0 / a0;

	double c2 = c * c;
	double bd = b * d;
	double c3 = c2 * c;
	double bcd = bd * c;
	double b2 = b * b;
	double b2e = b2 * e;
	double d2 = d * d;
	double ce = c * e;
	double bc = b * c;
	double b3 = b2 * b;
	double mbd4 = (-0.25) * b;

	double t0 = c2 - 3.0 * bd + 12.0 * e;
	double t1 = 2.0 * c3 - 9.0 * bcd + 27.0 * b2e + 27.0 * d2 - 72.0 * ce;
	double p = (8.0 * c - 3.0 * b2) / 8.0;
	double q = (b3 - 4.0 * bc + 8.0 * d) / 8.0;

	double disc = t1 * t1 - 4.0 * t0 * t0 * t0;

	if (disc < 0)
	{
		double st0 = sqrt(t0);
		double phi = (acos(t1 / (2.0 * t0 * st0))) / 3.0;
		sint = (-2.0 / 3.0) * p + (2.0 / 3.0) * st0 * cos(phi);
	}
	else
	{
		double bigq = cbrt((t1 + sqrt(disc)) * 0.5);
		sint = (-2.0 / 3.0) * p + (1.0 / 3.0) * (bigq + t0 / bigq);
	}

	s = sqrt(sint) * 0.5;
	rootint = (sint + 2 * p) * (-1.0);
	qds = q / s;

	r1 = rootint + qds;

	if (r1 > 0)
	{
		r1 = 0.5 * sqrt(r1);
		tmp = mbd4 - s;

		if (tmp + r1 > 0 && tmp + r1 < tmin) tmin = tmp + r1;
		if (tmp - r1 > 0 && tmp - r1 < tmin) tmin = tmp - r1;
	}

	r1 = rootint - qds;

	if (r1 > 0)
	{
		r1 = 0.5 * sqrt(r1);
		tmp = mbd4 + s;

		if (tmp + r1 > 0 && tmp + r1 < tmin) tmin = tmp + r1;
		if (tmp - r1 > 0 && tmp - r1 < tmin) tmin = tmp - r1;
	}

	return tmin;
}

int main()
{
	printf("%lf",quarticreal(1,-12,5,6,-3)); //11.522852
}