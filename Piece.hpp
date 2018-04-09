#ifndef PIECE_HPP
#define PIECE_HPP

#include <cstring>
#include <vector>
#include <exception>

class	Piece
{
public: enum	ePivot
{
	RIGHT_TO_LEFT,
	TOP_TO_BOTTOM,
	FRONT_TO_BACK	
};
	
private:

	// indices 0-5 represent front, back, right, left, top, bottom faces respectivly
	unsigned char _faces[6];

	void	RotateValues(unsigned char&, unsigned char&, unsigned char&, unsigned char&, bool);
	
public:

	Piece(std::vector<unsigned char> faces);

	void	Rotate(ePivot pivot, bool clockwise);
	unsigned char	*Faces(void);
};

#endif
