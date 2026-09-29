using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class AttackRange : MonoBehaviour
{
    //フィールド変数
    public float attackTime = 1.5f; //攻撃間隔

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    private void OnTriggerEnter(Collider other) //衝突した時
    {
        if (other.gameObject.name == "Player")  //プレイヤーが攻撃範囲に入った
        {
            //繰り返しの攻撃を開始する
            InvokeRepeating("Attack", 0.0f, attackTime);

        }

    }

    private void OnTriggerExit(Collider other)  //衝突から抜けたとき
    {
        //抜けた物体otherの名前はPlayerか？
        if (other.gameObject.name == "Player")  //プレイヤーが攻撃範囲から出た
        {
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
