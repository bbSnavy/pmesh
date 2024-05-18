#include "pmesh.h"

matrix2i_t
matrix2i_new(vec2i_t size, i32 fill)
{
	matrix2i_t	self;
	i32		*data;
	u64		t;
	u64		x;

	t = (u64) (size.x * size.y);
	data = (i32 *) calloc(t, sizeof(i32));
	for (x = 0; x < t; x++)
		data[x] = rand() % 2;

	self.size = size;
	self.data = data;
	self.fill = fill;

	return (self);
}

matrix2i_t
matrix2i_clone(matrix2i_t self)
{
	matrix2i_t	new;
	i32		*data;
	u64		t;
	u64		x;

	t = (u64) (self.size.x * self.size.y);
	data = (i32 *) calloc(t, sizeof(i32));
	for (x = 0; x < t; x++)
		data[x] = self.data[x];

	new.size = self.size;
	new.data = data;
	new.fill = self.fill;

	return (new);
}

i32
matrix2i_get(matrix2i_t self, vec2i_t xy, i32 fill)
{
	i32	result;
	u64	index;
	u64	t;

	if (xy.x < 0 || xy.y < 0 || xy.x >= self.size.x || xy.y >= self.size.y)
		return (fill);

	t = (u64) (self.size.x * self.size.y);
	index = (u64) (xy.y * self.size.x + xy.x);
	if (index >= t)
		return (fill);

	result = self.data[index];

	return (result);
}

matrix2i_t
matrix2i_add(matrix2i_t self, matrix2i_t other)
{
	matrix2i_t	new;
	i32		tx;
	i32		ty;
	i32		x;
	i32		y;
	vec2i_t		xy;
	u64		index;
	u64		t;
	i32		value;

	new = matrix2i_clone(self);

	tx = self.size.x;
	ty = self.size.y;

	t = (u64) (self.size.x * self.size.y);

	for (x = 0; x < tx; x++) { for (y = 0; y < ty; y++)
	{
		xy = vec2i_new(x, y);

		index = (u64) (tx * y + x);
		if (index >= t)
			continue;
	
		new.data[index] = matrix2i_get(self, xy, 0) + matrix2i_get(other, xy, 0);
	} }

	return (new);
}

void
matrix2i_show(matrix2i_t self)
{
	i32	tx;
	i32	ty;
	i32	x;
	i32	y;
	u64	index;
	i32	value;

	tx = self.size.x;
	ty = self.size.y;

	for (x = 0; x < tx; x++)
	{
		for (y = 0; y < ty; y++)
		{
			index = (u64) (tx * y + x);
			value = self.data[index];

			if (value >= 10) {
				printf("%02x ", value);
			} else {
				u8 c = " -@#$%*=/\\:~"[value];
				printf("%c%c ", c, c);
			}
		}
		printf("\n");
	}
}

