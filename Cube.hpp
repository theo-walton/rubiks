#ifndef CUBE_HPP
#define CUBE_HPP

#include "Piece.hpp"
#include <string>

class	Cube
{
public: enum	eFace
{
	FRONT,
	BACK,
	RIGHT,
	LEFT,
	TOP,
	BOTTOM
};

private:
	std::vector<Piece> _pieces;

	void	MovePieces(int, int, int, int, int, int, int, int pieceIndices,
			   bool forward);
	void	RotatePieces(int, int, int, int, int, int, int, int pieceIndices,
			     Piece::ePivot pivot,
			     bool clockwise);	
	void	RotateFace(eFace face, bool clockwise);
	
public:

	static constexpr bool clockwise = true;
	static constexpr bool anticlockwise = false;
	
	Cube(void);
	
	void	ApplyMove(std::string move);
	std::vector<unsigned char>	RawData(void);
};

#endif
