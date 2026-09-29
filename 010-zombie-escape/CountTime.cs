using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class CountTime : MonoBehaviour
{
    float startTime;        //ステージ開始時間
    public static float elapsedTime;      //経過時間
    Text tx;                //Textコンポーネントを入れる変数


    // Start is called before the first frame update
    void Start()
    {
        startTime = Time.time;      //ステージ開始時の経過時間を覚えておく
        elapsedTime = 0.0f;         //経過時間を初期化
        tx = GetComponent<Text>();  //テキストコンポーネントを見つけておく
    }

    // Update is called once per frame
    void Update()
    {
        elapsedTime = Time.time - startTime;    //経過時間を計算
        tx.text = elapsedTime.ToString("0.00"); //数値を書式に伴い文字列にして代入
    }
}

