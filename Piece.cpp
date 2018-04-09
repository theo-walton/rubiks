
#include "Piece.hpp"

Piece::Piece(std::vector<unsigned char> faces)
{
	if (faces.size() != 6)
		throw std::exception();
        std::memmove(_faces, &faces[0], sizeof(unsigned char) * 6);
}

void	Piece::RotateValues(unsigned char &v1,
			    unsigned char &v2,
			    unsigned char &v3,
			    unsigned char &v4,
			    bool forward)
{
	if (forward)
	{
		unsigned char temp = v4;
		v4 = v3;
		v3 = v2;
		v2 = v1;
		v1 = temp;
	}
	else
	{
		unsigned char temp = v1;
		v1 = v2;
		v2 = v3;
		v3 = v4;
		v4 = temp;
	}
}

void	Piece::Rotate(ePivot pivot, bool clockwise)
{
	switch (pivot)
	{
	case RIGHT_TO_LEFT:
		RotateValues(_faces[0], _faces[4], _faces[1], _faces[5], clockwise);
		return;
	case TOP_TO_BOTTOM:
		RotateValues(_faces[0], _faces[3], _faces[1], _faces[2], clockwise);
		return;
	case FRONT_TO_BACK:
		RotateValues(_faces[4], _faces[2], _faces[5], _faces[3], clockwise);
		return;
	default:
		return;
	}
}

unsigned char	*Piece::Faces(void)
{
	return _faces;
}
