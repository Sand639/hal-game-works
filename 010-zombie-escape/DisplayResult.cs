using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class DisplayResult : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        //CountTimeクラスから、
        //パブリックなスタティック変数のelapsedTimeを所得できる。GetComponent<>不要。
        float t = CountTime.elapsedTime;

        //値をタイムスコア表示の文字列にする
        string message = t.ToString("0.00");

        //文字列をテキストUIに表示
        GetComponent<Text>().text = message;
    }

    // Update is called once per frame
    void Update()
    {

    }
}
