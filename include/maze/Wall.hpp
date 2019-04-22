#ifndef WALL_HPP_
#define WALL_HPP_

class Wall {
public:
	Wall();

	bool getActive();
	void setActive(bool newACtive);

private:
	bool active;

};

#endif