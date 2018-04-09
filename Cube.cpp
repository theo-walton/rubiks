
#include "Cube.hpp"

constexpr bool Cube::clockwise;
constexpr bool Cube::anticlockwise;

Cube::Cube(void)
{
	std::vector<unsigned char> faces = {0, 1, 2, 3, 4, 5};
	Piece p(faces);
	
	for (int i = 0; i < 27; i++)
		_pieces.push_back(p);
}

void	Cube::MovePieces(int i0, int i1, int i2, int i3, int i4, int i5, int i6, int i7, bool forward)
{
	if (forward)
	{
		Piece temp1 = _pieces[i6];
		Piece temp2 = _pieces[i7];
		
		_pieces[i7] = _pieces[i5];
		_pieces[i6] = _pieces[i4];
		_pieces[i5] = _pieces[i3];
		_pieces[i4] = _pieces[i2];
		_pieces[i3] = _pieces[i1];
		_pieces[i2] = _pieces[i0];
		_pieces[i1] = temp2;
		_pieces[i0] = temp1;
	}
	else
	{
		Piece temp1 = _pieces[i0];
		Piece temp2 = _pieces[i1];

		_pieces[i0] = _pieces[i2];
		_pieces[i1] = _pieces[i3];
		_pieces[i2] = _pieces[i4];
		_pieces[i3] = _pieces[i5];
		_pieces[i4] = _pieces[i6];
		_pieces[i5] = _pieces[i7];
		_pieces[i6] = temp1;
		_pieces[i7] = temp2;
	}
}

void	Cube::RotatePieces(int i0, int i1, int i2, int i3, int i4, int i5, int i6, int i7,
			   Piece::ePivot pivot,
			   bool clockwise)
{
	_pieces[i0].Rotate(pivot, clockwise);
	_pieces[i1].Rotate(pivot, clockwise);
	_pieces[i2].Rotate(pivot, clockwise);
	_pieces[i3].Rotate(pivot, clockwise);
	_pieces[i4].Rotate(pivot, clockwise);
	_pieces[i5].Rotate(pivot, clockwise);
	_pieces[i6].Rotate(pivot, clockwise);
	_pieces[i7].Rotate(pivot, clockwise);
}

void	Cube::RotateFace(eFace face, bool clockwise)
{
	switch (face)
	{
	case FRONT:
		MovePieces(0, 1, 2, 5, 8, 7, 6, 3, clockwise);
		RotatePieces(0, 1, 2, 5, 8, 7, 6, 3, Piece::FRONT_TO_BACK, clockwise);
		return;
	case BACK:
		MovePieces(20, 19, 18, 21, 24, 25, 26, 23, clockwise);
		RotatePieces(20, 19, 18, 21, 24, 25, 26, 23, Piece::FRONT_TO_BACK, !clockwise);
		return;
	case RIGHT:
		MovePieces(2, 11, 20, 23, 26, 17, 8, 5, clockwise);
		RotatePieces(2, 11, 20, 23, 26, 17, 8, 5, Piece::RIGHT_TO_LEFT, clockwise);
		return;
	case LEFT:
		MovePieces(18, 9, 0, 3, 6, 15, 24, 21, clockwise);
		RotatePieces(18, 9, 0, 3, 6, 15, 24, 21, Piece::RIGHT_TO_LEFT, !clockwise);
		return;
	case TOP:
		MovePieces(18, 19, 20, 11, 2, 1, 0, 9, clockwise);
		RotatePieces(18, 19, 20, 11, 2, 1, 0, 9, Piece::TOP_TO_BOTTOM, clockwise);
		return;
	case BOTTOM:
		MovePieces(6, 7, 8, 17, 26, 25, 24, 15, clockwise);
		RotatePieces(6, 7, 8, 17, 26, 25, 24, 15, Piece::TOP_TO_BOTTOM, !clockwise);
		return;
	default:
		return;
	}
}

void	Cube::ApplyMove(std::string move)
{
	if (move == "F")
		RotateFace(FRONT, clockwise);
	else if (move == "B")
		RotateFace(BACK, clockwise);
	else if (move == "R")
		RotateFace(RIGHT, clockwise);
	else if (move == "L")
		RotateFace(LEFT, clockwise);
	else if (move == "U")
		RotateFace(TOP, clockwise);
	else if (move == "D")
		RotateFace(BOTTOM, clockwise);
	else if (move == "F2")
	{
		RotateFace(FRONT, clockwise);
		RotateFace(FRONT, clockwise);
	}
	else if (move == "B2")
	{
		RotateFace(BACK, clockwise);
		RotateFace(BACK, clockwise);
	}
	else if (move == "R2")
	{
		RotateFace(RIGHT, clockwise);
		RotateFace(RIGHT, clockwise);
	}
	else if (move == "L2")
	{
		RotateFace(LEFT, clockwise);
		RotateFace(LEFT, clockwise);
	}
	else if (move == "U2")
	{
		RotateFace(TOP, clockwise);
		RotateFace(TOP, clockwise);
	}
	else if (move == "D2")
	{
		RotateFace(BOTTOM, clockwise);
		RotateFace(BOTTOM, clockwise);
	}
	else if (move == "F'")		
		RotateFace(FRONT, anticlockwise);
	else if (move == "B'")
		RotateFace(BACK, anticlockwise);
	else if (move == "R'")
		RotateFace(RIGHT, anticlockwise);
	else if (move == "L'")
		RotateFace(LEFT, anticlockwise);
	else if (move == "U'")
		RotateFace(TOP, anticlockwise);
	else if (move == "D'")
		RotateFace(BOTTOM, anticlockwise);
	else
		throw std::exception();
}

std::vector<unsigned char>	Cube::RawData(void)
{
	std::vector<unsigned char> out(27 * 6);

	for (int i = 0; i < 27; i++)
		std::memmove(&out[i * 6], _pieces[i].Faces(), sizeof(unsigned char) * 6);
	
	return out;
}
