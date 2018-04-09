#ifndef CUBERENDER_HPP
#define CUBERENDER_HPP

#include "Cube.hpp"
#include <iostream>
#include <algorithm>

class	CubeRender
{
private:

	Cube &_cube;
//	ShadingProgram *_program;
	
public:

	CubeRender(Cube &c);

	void	Render(void);
};

#endif
