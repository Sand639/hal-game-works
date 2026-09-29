using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class HpUp : MonoBehaviour
{
    //フィールド
    public int hpUpValue = 3;   //回復量


    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    private void OnTriggerEnter(Collider other)
    {
        //ぶつかってきたのがプレイヤーか？
        if(other.gameObject.name == "Player")
        {
            //アイテムを消す
            gameObject.SetActive(false);

            //プレイヤーのHPを回復させる
            var player = GameObject.Find("Player");
            var playerScript = player.GetComponent<Player>();
            playerScript.hp = playerScript.hp + hpUpValue;

            //プレイヤーのHP回復エフェクト
            player.transform.Find("FxHpUp").gameObject.SetActive(true);
        }
    }
}
