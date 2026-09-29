using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;   //textを使うためのコード

public class TextHP : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        //プレイヤーのHPを取ってくる
        var playerHP = GameObject.Find("Player").GetComponent<Player>().hp;
        GetComponent<Text>().text = playerHP.ToString();      //playerHPをint型からstring型（テキストの型）に帰る

    }
}
