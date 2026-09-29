using System.Collections;
using System.Collections.Generic;
using System.Globalization;
using UnityEngine;

public class CreateBullet : MonoBehaviour
{
    public GameObject bulletPrefab; //弾のプレハブを入れる変数（プレハブはGameObject型になる）  
    public float shotpower = 15.0f; //弾を発射する力

    public GameObject Camera; // カメラの変数

    AudioSource audioSource;    //音の発生源を格納する変数
    public AudioClip shootSound;    //発生源の音声クリップを格納する変数


    // Start is called before the first frame update
    void Start()
    {
        audioSource = GetComponent<AudioSource>();

    }


    // Update is called once per frame
    void Update()
    {
        if (Input.GetKeyDown(KeyCode.Mouse0))    //左クリックが押し込まれた瞬間に
        {
            //音の発生源から、発射音を鳴らす　PlayOneShot（音声クリップ）
            audioSource.PlayOneShot(shootSound);

            //弾を出現させる地点(pos)を、キャラクターの位置より0.5m前方にする
            //transform.forword:キャラクターが向いている方向（Z軸の青い矢印）に1m進むための3次元ベクトル
            Vector3 pos = transform.position + transform.forward * 0.5f;

            //プレハブを元に弾の実際のオブジェクト（インスタントという）をシーン生成
            //bulletPrefabを元に、posの位置に生成。Quaternion.identityとは「回転なし」という意味
            //シーン生成されたオブジェクトが戻り値を取得できるので、それを操作できるよう変数objに入れる
            GameObject obj = Instantiate(bulletPrefab, pos, Camera.transform.rotation);

            //キャラの前方（=forword)に向けて一気に(=Impule)力を加えて(=AddForce)、弾を飛ばす
            //弾を発射する力(=shotpower)を掛け算して力を調整できるようにしている
            obj.GetComponent<Rigidbody>().AddForce(Camera.transform.forward * shotpower, ForceMode.Impulse);

            // 弾丸の向きをカメラの向きに設定
            obj.transform.rotation = Camera.transform.rotation;
        }

    }
}
