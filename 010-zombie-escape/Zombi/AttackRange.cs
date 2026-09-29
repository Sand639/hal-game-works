using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class AttackRange : MonoBehaviour
{
    public int Switch = 0;

    public float attackTime = 1.5f; //攻撃間隔

    private void OnTriggerEnter(Collider other) //衝突した時
    {
        if (other.gameObject.name == "Player")  //プレイヤーが攻撃範囲に入った
        {
            Switch = 1;

            //繰り返しの攻撃を開始する
            InvokeRepeating("Attack", 0.0f, attackTime);
        }
    }

    private void OnTriggerExit(Collider other)  //衝突から抜けたとき
    {
        //抜けた物体otherの名前はPlayerか？
        if (other.gameObject.name == "Player")  //プレイヤーが攻撃範囲から出た
        {
            Switch = 0;

            //繰り返し攻撃をやめる
            CancelInvoke();
        }
    }

    //繰り返し攻撃用のメソッド
    void Attack()
    {
        var enemy = transform.parent.gameObject;
        var enemyAnimator = enemy.GetComponent<Animator>();
        enemyAnimator.SetTrigger("tAttack");
    }
}
