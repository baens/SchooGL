#ifndef COLOR_H
#define COLOR_H

class Color{
public:
	/**
	* @author SchooGL
	* 
	* creates a default color.
	*/
	Color();
	/**
	* @author SchooGL
	* 
	* creates a new color with the parts r, g, b, a.
	* 
	* @param r the float representing the red portion of the RGB color set for defining colors.
	* @param g the float representing the green portion of the RGB color set for defining colors.
	* @param b the float representing the blue portion of the RGB color set for defining colors.
	* @param a the float representing the alpha portion of a color.
	*/
	Color(double r, double g, double b, double a);
	/**
	* @author SchooGL
	* 
	* creates a new color with the parts r, g, b, a.
	* 
	* @param r the float representing the red portion of the RGB color set for defining colors.
	* @param g the float representing the green portion of the RGB color set for defining colors.
	* @param b the float representing the blue portion of the RGB color set for defining colors.
	* @param a the float representing the alpha portion of a color.
	*/
	Color(double r, double g, double b);
	/**
	* @author SchooGL
	* 
	* creates a copy of a color rhs with the parts r, g, b, a.
	* 
	* @param rhs the color to copy.
	*/
	Color(const Color& rhs);
	/**
	* @author SchooGL
	* 
	* sets the red portion of a RGB color set.
	* 
	* @param r the float representing the red portion of RGB.
	*/
	void setRed(double r);
	/**
	* @author SchooGL
	* 
	* gets the float from red portion of a RGB color set.
	* 
	* @return GLfloat
	*/
	double getRed();
	/**
	* @author SchooGL
	* 
	* sets the green portion of a RGB color set.
	* 
	* @param g the float representing the green portion of RGB.
	*/
	void setGreen(double g);
	/**
	* @author SchooGL
	* 
	* gets the float from green portion of a RGB color set.
	* 
	* @return GLfloat
	*/
	double getGreen();
	/**
	* @author SchooGL
	* 
	* sets the green portion of a RGB color set.
	* 
	* @param b the float representing the blue portion of RGB.
	*/
	void setBlue(double b);
	/**
	* @author SchooGL
	* 
	* gets the float from blue portion of a RGB color set.
	* 
	* @return GLfloat
	*/
	double getBlue();
	/**
	* @author SchooGL
	* 
	* sets the alpha portion of a RGB color set.
	* 
	* @param a the float representing the alpha portion of a color.
	*/
	void setAlpha(double a);
	/**
	* @author SchooGL
	* 
	* gets the float from alpha portion of a color.
	* 
	* @return GLfloat
	*/
	double getAlpha();
private:
	double red;
	double green;
	double blue;
	double alpha;
};
#endif
