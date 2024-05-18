#include "pmesh.h"

i32	i32_div(i32 x, i32 y)
{
	if (y == 0)
		return (0);

	return (x / y);
}

vec2i_t
vec2i_new(i32 x, i32 y)
{
	vec2i_t	self;

	self.x = x;
	self.y = y;

	return (self);
}

u8
vec2i_eq(vec2i_t self, vec2i_t other)
{
	if (self.x != other.x)
		return (0);

	if (self.y != other.y)
		return (0);

	return (1);
}

vec2i_t
vec2i_add(vec2i_t self, vec2i_t other)
{
	self.x += other.x;
	self.y += other.y;

	return (self);
}

vec2i_t
vec2i_sub(vec2i_t self, vec2i_t other)
{
	self.x -= other.x;
	self.y -= other.y;

	return (self);
}

vec2i_t
vec2i_mul(vec2i_t self, vec2i_t other)
{
	self.x *= other.x;
	self.y *= other.y;

	return (self);
}

vec2i_t
vec2i_div(vec2i_t self, vec2i_t other)
{
	self.x = i32_div(self.x, other.x);
	self.y = i32_div(self.y, other.y);

	return (self);
}

