#pragma once

#include <unordered_map>

#include "assimp/cimport.h"
#include "assimp/scene.h"
#include "assimp/postprocess.h"
#include "assimp/matrix4x4.h"
#pragma comment (lib, "assimp-vc143-mt.lib")

#include "collision.h"

#include "main.h"

struct MODEL
{
	const aiScene* AiScene = nullptr;

	ID3D11Buffer** VertexBuffer;
	ID3D11Buffer** IndexBuffer;

	std::unordered_map<std::string, ID3D11ShaderResourceView*> Texture;

	XMFLOAT3 pos = { 0.0f,0.0f,0.0f };

	AABB aabb;
};


MODEL* ModelLoad(const char* FileName, bool blender = false);
void ModelDraw(MODEL* model, const XMMATRIX& world, int texture_id = -1, bool bforceTexture = false);
void ModelRelease(MODEL* model);

