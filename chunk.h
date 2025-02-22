#ifndef CHUNK_H
#define CHUNK_H

#include "block.h"
#include <vector>
#include <array>
#include "glad/glad.h"
#include <iostream>


struct Room {
	int x, y, z, width, height, depth;
	BlockType type;
};

class Chunk {

public:

	Chunk() = default;
	Chunk(int worldx, int worldz);
	Chunk(int worldx, int worldz, int test);
	Chunk(const Chunk &c); //copy
	Chunk(Chunk &&other) noexcept;
	Chunk& operator=(Chunk&& other) noexcept;
	~Chunk();

	void create_cube(int x, int y, int z);
	void generate_mesh();

	Room generate_room(int chunkX, int chunkY);
	void carve_room(Room room);

	void create_mesh();
	void generate_buffers();

	static const int CHUNK_SIZE;
	static const int NUMBER_OF_CUBE_VERTS;
	static int CHUNK_COUNT;
	int block_number;
	//Block ***m_pBlocks;

	Room room;
	int chunk_id;
	int chunk_world_xposition;
	int chunk_world_zposition;
	int absolute_positionX;
	int absolute_positionZ;
	bool buffers_initialized;
	bool buffers_generated;
	bool blocks_generated;
	GLuint VertexArrayID;
	GLuint vertex_buffer;
	GLuint normalBuffer;
	GLuint colorBuffer;
	GLuint IndexBuffer;
	float generate_height(int x, int z);
	std::vector<float> vertices;
	std::vector<int> indices;
	std::vector<float> normals;
	std::vector<float> colors;
	std::vector<BlockType> blocks;
};



#endif