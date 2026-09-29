#pragma once

/*******************************************************************************
* プロトタイプ宣言
*******************************************************************************/

//当たり判定
void CollisionPandE(void);	//プレイヤーと敵
void CollisionPB1andE(void); //弾と敵
void CollisionPandEB(void); //プレイヤーと弾
void CollisionPB1andEB(void);//弾と弾
void CollisionPandIHeal(void);	//プレイヤーと回復アイテム
void CollisionPandILevel(void);	//プレイヤーとレベルアイテム
void CollisionPandBoss(void);//プレイヤーとボス
void CollisionPB1andBoss(void);//弾とボス
//void CollisonBossandI(void);//ボスとアイテム

void CollisionPB2andE(void);//3弾と敵
void CollisionPB2andEB(void);//弾と弾
void CollisionPB2andBoss(void);//ボスと弾

void CollisionPandBossB(void);//プレイヤーとボスの攻撃
void CollisionPB1andBossB(void);//プレイヤーの弾とボスの弾
void CollisionPB2andBossB(void);//プレイヤーの弾2とボスの弾



void CollisionDetection(void);	//当たり判定処理関数