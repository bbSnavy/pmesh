#ifndef PMESH_H
#define PMESH_H

#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

#define i8  int8_t
#define u8  uint8_t
#define i32 int32_t
#define u32 uint32_t
#define i64 int64_t
#define u64 uint64_t

typedef struct vec2i	vec2i_t;
typedef struct matrix2i	matrix2i_t;

struct vec2i
{
	i32	x;
	i32	y;
};

struct matrix2i
{
	vec2i_t	size;
	i32	*data;
	i32	fill;
};

vec2i_t		vec2i_new(i32 x, i32 y);
u8		vec2i_eq(vec2i_t self, vec2i_t other);
vec2i_t		vec2i_add(vec2i_t self, vec2i_t other);
vec2i_t		vec2i_sub(vec2i_t self, vec2i_t other);
vec2i_t		vec2i_mul(vec2i_t self, vec2i_t other);
vec2i_t		vec2i_div(vec2i_t self, vec2i_t other);
matrix2i_t	matrix2i_new(vec2i_t size, i32 fill);
matrix2i_t	matrix2i_add(matrix2i_t self, matrix2i_t other);
void		matrix2i_show(matrix2i_t self);

#endif

