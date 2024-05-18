#include "pmesh.h"

int
main(int arg, char **argv)
{
	matrix2i_t	mat_a;
	matrix2i_t	mat_b;
	matrix2i_t	mat_c;

	mat_a = matrix2i_new(vec2i_new(32, 32), 2);
	
	mat_b = matrix2i_new(vec2i_new(32, 32), 5);
	mat_c = matrix2i_add(mat_a, mat_b);

	matrix2i_show(mat_a); printf("a\n");
	matrix2i_show(mat_b); printf("b\n");
	matrix2i_show(mat_c); printf("c\n");

	return (0);
}

