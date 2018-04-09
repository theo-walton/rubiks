
#include "Cube.hpp"
#include "CubeRender.hpp"

int	main(void)
{
	Cube c;
	CubeRender r(c);

	r.Render();
	r.Render();
	while (1)
	{
		std::string line;
		std::cin >> line;
		try
		{
			c.ApplyMove(line);
		}
		catch (std::exception){};
		r.Render();
	}
}
