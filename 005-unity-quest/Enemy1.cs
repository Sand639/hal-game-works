using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Enemy1 : MonoBehaviour
{
    //フィールド
    public int hp = 3;  //HP変数



    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        var animator = GetComponent<Animator>();

        //プレイヤーが視界に入ったか？
        var viewRange = transform.Find("ViewRange").gameObject;
        var viewRangeScript = viewRange.GetComponent<ViewRange>();

        if (viewRangeScript.canSee == true)
        {
            //歩きアニメーション再生
            animator.SetBool("bWalk", true);
        }
        else
        {
            //歩きアニメーション停止
            animator.SetBool("bWalk", false);
        }

        //現在再生中のアニメーションをチェック
        var animStateInfo=animator.GetCurrentAnimatorStateInfo(0);
        var hitRange = transform.Find("HitRange").gameObject;


        if (animStateInfo.IsName("Attack1"))
        {
            //HItRange　→　ON
            hitRange.SetActive(true);


        }
        else
        {
            //HitRange → OFF
            hitRange.SetActive(false);

        }

    }
    

    //当たり判定の結果受け取り
    private void OnTriggerEnter(Collider other)
    {
        //敵のカプセルに何か当たった時にこの中に書いたプログラムが実行される


        if (other.gameObject.name == "HitRange")
        {

            if (other.gameObject.transform.parent.gameObject.name == "Player")
            {
                //攻撃が当たった時のリアクション
                var animator = GetComponent<Animator>();
                animator.SetTrigger("tDamage");

                //ヒットエフェクトを表示
                var fxHit = transform.Find("FxHit").gameObject;
                fxHit.SetActive(true);

                //ダメージ量を取ってくる
                var damage = other.gameObject.GetComponent<HitRange>().damage;
                fxHit.SetActive(true);


                //Hpを減らす
                hp = hp - damage;

                //ダメージが大きければ追加エフェクト再生
                if (damage >= 200)
                {
                    //ヒットエフェクト(大)を表示
                    transform.Find("FxHitBig").gameObject.SetActive(true);
                }


                //HPが0以下か？
                if (hp <= 0)
                {
                    //敵が死亡する演出
                    animator.SetBool("bKilled", true);

                    //繰り返し攻撃をやめる
                    var attackRange_GameObject = transform.Find("AttackRange").gameObject;
                    var attackRange_Script = attackRange_GameObject.GetComponent<AttackRange>();
                    attackRange_Script.CancelInvoke();

                    //死亡エフェクト
                    var fxDie = transform.Find("FxDie").gameObject;
                    fxDie.SetActive(true);

                    //自身の当たり判定領域を無効にする
                    GetComponent<CharacterController>().enabled = false;

                    //AttackRangeを無効にする
                    attackRange_GameObject.SetActive(false);
                }

            }
        }
    }
}
