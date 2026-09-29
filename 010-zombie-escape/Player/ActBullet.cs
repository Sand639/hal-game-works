using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ActBullet : MonoBehaviour
{
    //破壊時の音声クリップをUnityエディタのインスペクターで割り当てる
    public AudioClip breakSound;

    //破壊した時のパーティクルエフェクト
    public GameObject breakEffect;

    // Start is called before the first frame update
    void Start()
    {
        //弾自身を破壊する自作関数を3秒後に呼ぶ
        Invoke("DestroyBullet", 5.0f);
    }


    //弾自身を破棄する自作関数
    private void DestroyBullet()
    {
        Destroy(gameObject);    //自身を破棄
    }

    //何かぶつかったら
    private void OnCollisionEnter(Collision collision)
    {
        //ぶつかった相手にZombiタグが付いていたら
        if (collision.gameObject.CompareTag("Zombi"))
        {
            //ぶつかった位置に一時的にAudioSouceが付いたゲームオブジェクトを生成し、
            //再生時に自動削除してくれる関数
            //AudioSource.PlayClipAtPoint（オーディオクリップ,音を鳴らしたい位置）
            AudioSource.PlayClipAtPoint(breakSound, this.transform.position);

            //エフェクトを生成する
            GameObject effect = Instantiate(breakEffect);
            //エフェクトが発生する場所を決定する（敵オブジェクトの場所）
            effect.transform.position = gameObject.transform.position;
            //エフェクトを2秒後に削除
            Destroy(effect, 2.0f);

            //ぶつかった相手を破棄
            Destroy(collision.gameObject);

            //自身を破棄
            Destroy(gameObject);
        }
    }
}
