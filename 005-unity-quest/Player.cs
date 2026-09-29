using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class Player : MonoBehaviour
{
    //フィールド
    public int hp = 3;  //HP変数
    public int wp = 5;  //HP変数
    public int attack = 100;    //攻撃力
    public GameObject GameOverImage;  //ゲームオーバーImage
    

    bool canInputKey = true;    //キー入力が可能か？

    void EndAttack()
    {
        canInputKey = true;     //キー入力を可能にする
    }


    // Start is called before the first frame update
    void Start()
    {
       // transform.eulerAngles = new Vector3(0, 90, 0);
    }

    // Update is called once per frame
    void Update()
    {
        var animator = GetComponent<Animator>();

        //子要素hitRangeにアクセスする
        var hitRange = transform.Find("HitRange").gameObject;
        var hitRangeScript = hitRange.GetComponent<HitRange>();



        GetComponent<Animator>().SetBool("bWalk", false);
        GetComponent<Animator>().SetBool("bRun", false);

        if (Input.GetKeyDown(KeyCode.Mouse0))   //マウス左ボタン
        {
            if (canInputKey　== true) 
            {
                GetComponent<Animator>().SetTrigger("tAttack");    //攻撃アニメーション
                canInputKey = false;
                Invoke("EndAttack", 1.0f);

                var thisAttack = attack;
                if(Random.Range(0,5)== 0)   // 1/5でクリティカル
                {
                    thisAttack *= 2;

                    //エフェクト再生
                    transform.Find("FxCritical").gameObject.SetActive(true);
                }

                //ダメージ量を設定する
                var RG = thisAttack / 5;
                var RD = Random.Range(0, RG+1);
                hitRangeScript.damage = thisAttack + RD - RG / 2;
            }
            
        }

        if (Input.GetKeyDown(KeyCode.Mouse1))   //マウス右ボタン
        {
            GetComponent<Animator>().SetTrigger("tBlock");    //ガードアニメーション
        }

        if (Input.GetKeyDown(KeyCode.Mouse2))   //マウスホイール押し込み
        {
            GetComponent<Animator>().SetTrigger("tRoll");    //回避
        }

        if (Input.GetKeyDown(KeyCode.Z))   //必殺技
        {
            if(canInputKey == true)
            {
                if (wp > 0) //wp残量があるときだけ技発動
                {
                    animator.SetTrigger("tWaza");
                    canInputKey = false;
                    Invoke("EndAttack", 1.0f);

                    //ダメージ量を設定する
                    var RG = attack * 3 / 5;
                    var RD = Random.Range(0, RG + 1);
                    hitRangeScript.damage = attack * 3 + RD - RG / 2;

                    //wpを消費する
                    wp = wp - 1;
                }
            }

            
        }

        //AWSDキー移動
        if (Input.GetKey(KeyCode.A))    //Aキーが押された
        {
            if(Input.GetKey(KeyCode.W))    //左Shiftが押された
            {
                GetComponent<Animator>().SetBool("bRun", true);
            }
            else
            {
                GetComponent<Animator>().SetBool("bWalk", true);
                GetComponent<Animator>().SetFloat("fSpeed", 1.0f);
            }

            if (Input.GetKey(KeyCode.S))    //左Shiftが押された
            {
                GetComponent<Animator>().SetFloat("fSpeed", 0.5f);
            }
            //アニメーションを歩きに切り替える
            transform.eulerAngles = new Vector3(0, 90, 0);  //90は左
           
        }

        
        
        if (Input.GetKey(KeyCode.D))    //Dキー
        {
            if (Input.GetKey(KeyCode.W))    //左Shiftが押された
            {
                GetComponent<Animator>().SetBool("bRun", true);
            }
            else
            {
                GetComponent<Animator>().SetBool("bWalk", true);
                GetComponent<Animator>().SetFloat("fSpeed", 1.0f);
            }

            if (Input.GetKey(KeyCode.S))    //左Shiftが押された
            {
                GetComponent<Animator>().SetFloat("fSpeed", 0.5f);
            }
            transform.eulerAngles = new Vector3(0, 270, 0);    //270は右
        }

       

        //変数を使ってカメラを動かす

        //Main cameraのtransformを変数に入れた
        var cameraTrans = GameObject.Find("Main Camera").transform;
        //変数にMain cameraのpositionの値を入れた
        var cameraPos = cameraTrans.position;
        //PlayerのX座標の値を、カメラのpositionが入った変数のxにコピーした
        cameraPos.x = transform.position.x;
        //Xを変更したカメラのpositionの値をMain cameraに設定した
        cameraTrans.position = cameraPos;


        //HitRangeのアクティブを切り替える
        if (Input.GetKeyDown(KeyCode.N))
        {
            hitRange.SetActive(true);
        }

        if (Input.GetKeyDown(KeyCode.F))
        {
            hitRange.SetActive(false);
        }

        //AnimatorStateInfoクラスを取得=アニメーション状態の情報
        var stateInfo = animator.GetCurrentAnimatorStateInfo(0);

        //現在再生中のアニメーションを調べる
        if(stateInfo.IsName("Attack1"))
        {
            //攻撃範囲をON
            hitRange.SetActive(true);
        }
        else
        {
            hitRange.SetActive(false);
        }
    }

    private void OnTriggerEnter(Collider other) //衝突した時
    {

        if (other.gameObject.name == "HitRange")
        {
            //攻撃を受けた時のアクション
            var animator = GetComponent<Animator>();

            var stateInfo = animator.GetCurrentAnimatorStateInfo(0);

            //ダメージ量を取ってくる
            var damage = other.gameObject.GetComponent<HitRange>().damage;

            //ダメージ値をばらけさせる
            var RG = damage / 5;
            var RD = Random.Range(0, RG + 1);
            damage = damage + RD - RG / 2;

            if (stateInfo.IsName("Block"))
            {
                //ガード中


                //ガードエフェクトを表示
                var fxBlock = transform.Find("FxBlock").gameObject;
                fxBlock.SetActive(true);



                //Hpを1減らす
                hp = hp - damage / 2;

            }
            else if(stateInfo.IsName("Roll"))
            {
                //回避中
                damage = 0; //ノーダメージ
            }
            else
            {
                //ガード中ではない
                //ダメージアニメーションを再生する
                animator.SetTrigger("tDamage");

                //ヒットエフェクトを表示
                var fxHit = transform.Find("FxHit").gameObject;
                fxHit.SetActive(true);


                //Hpを1減らす
                hp = hp - damage;
            }

            //特殊ヒットエフェクトを追加で出すか判定
            var  effect=other.gameObject.GetComponent<HitRange>().Effect;
            if(effect == 2) //2は水エフェクト
            {
                var fxHit = transform.Find("FxWater").gameObject;
                fxHit.SetActive(true);
            }

            //HPが0以下か？
            if (hp <= 0)
            {
                //敵が死亡する演出
                animator.SetBool("bKilled", true);

                //死亡エフェクト
                var fxDie = transform.Find("FxDie").gameObject;
                fxDie.SetActive(true);

                //自身の当たり判定領域を無効にする
                GetComponent<CharacterController>().enabled = false;

                //ゲームオーバー表示
                GameOverImage.SetActive(true);
                //しばらくしたらタイトル画面へ
                Invoke("TitleScene", 4.5f);

            }

        }

    }

    void TitleScene()
    {
        SceneManager.LoadScene("Title");    }





}
