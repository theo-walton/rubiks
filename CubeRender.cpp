
#include "CubeRender.hpp"

CubeRender::CubeRender(Cube &c) : _cube(c)
{
}

std::string	ColorBlock(int n)
{
	std::string out = "\033[1;4Xm \033[0m";

	std::replace(out.begin(), out.end(), 'X', (char)(n + '1'));
	return out;
}

void	CubeRender::Render(void)
{
//	_program->Use();

	std::vector<unsigned char> data = _cube.RawData();

	std::cout << "   "
		  << ColorBlock(data[18 * 6 + Cube::TOP])
		  << "  "
		  << ColorBlock(data[19 * 6 + Cube::TOP])
		  << "  "
		  << ColorBlock(data[20 * 6 + Cube::TOP])
		  << std::endl;
	std::cout << "  "
		  << ColorBlock(data[9 * 6 + Cube::TOP])
		  << "  "
		  << ColorBlock(data[10 * 6 + Cube::TOP])
		  << "  "
		  << ColorBlock(data[11 * 6 + Cube::TOP])
		  << " "
		  << ColorBlock(data[20 * 6 + Cube::RIGHT])
		  << std::endl;
	std::cout << " "
		  << ColorBlock(data[0 * 6 + Cube::TOP])
		  << "  "
		  << ColorBlock(data[1 * 6 + Cube::TOP])
		  << "  "
		  << ColorBlock(data[2 * 6 + Cube::TOP])
		  << " "
		  << ColorBlock(data[11 * 6 + Cube::RIGHT])
		  << ColorBlock(data[23 * 6 + Cube::RIGHT])
		  << std::endl;
	std::cout << ColorBlock(data[0 * 6 + Cube::FRONT])
		  << "  "
		  << ColorBlock(data[1 * 6 + Cube::FRONT])
		  << "  "
		  << ColorBlock(data[2 * 6 + Cube::FRONT])
		  << " "
		  << ColorBlock(data[2 * 6 + Cube::RIGHT])
		  << ColorBlock(data[14 * 6 + Cube::RIGHT])
		  << ColorBlock(data[26 * 6 + Cube::RIGHT])
		  << std::endl;
	std::cout << ColorBlock(data[3 * 6 + Cube::FRONT])
		  << "  "
		  << ColorBlock(data[4 * 6 + Cube::FRONT])
		  << "  "
		  << ColorBlock(data[5 * 6 + Cube::FRONT])
		  << " "
		  << ColorBlock(data[5 * 6 + Cube::RIGHT])
		  << ColorBlock(data[17 * 6 + Cube::RIGHT])
		  << std::endl;
	std::cout << ColorBlock(data[6 * 6 + Cube::FRONT])
		  << "  "
		  << ColorBlock(data[7 * 6 + Cube::FRONT])
		  << "  "
		  << ColorBlock(data[8 * 6 + Cube::FRONT])
		  << " "
		  << ColorBlock(data[8 * 6 + Cube::RIGHT])
		  << std::endl
		  << std::endl;
}
