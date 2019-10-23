#ifndef OBJEKT_H
#define OBJEKT_H

class Objekt {
public:
	Objekt(int id);
	virtual ~Objekt();
	
	int getID();
	double getX();
	double getY();
	
	void setX(int value);
	void setY(int value);
private:
	int id; 
	double x; 
	double y;

};

#endif // !OBJEKT_H
