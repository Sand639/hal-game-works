/*==============================================================================

   テクスチャ管理 [texture.h]
														 Author : Youhei Sato
														 Date   : 2024/06/04
--------------------------------------------------------------------------------

==============================================================================*/
#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>
#include <d3d11.h>

//モジュールの初期化
void TextureInitialize(void);

//テクスチャの保存
int TextureLoad(const std::wstring& texture_filename);

//テクスチャの読み込み
ID3D11ShaderResourceView* GetTexture(int id);

//テクスチャのセット
void SetTexture(int id);

//テクスチャの幅を取得
int TextureGetWidth(int id);

//テクスチャの高さを取得
int TextureGetHeight(int id);

//テクスチャの開放
void TextureFinalize(void);

#endif // TEXTURE_H
