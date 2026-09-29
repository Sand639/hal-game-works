using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;   //textを使うためのコード

public class TextWP : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        //プレイヤーのWPを取ってくる
        var playerWP = GameObject.Find("Player").GetComponent<Player>().wp;
        GetComponent<Text>().text = playerWP.ToString();
    }
}
