using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ViewRange : MonoBehaviour
{
    //フィールド
    public bool canSee = false; //ターゲットが見えているか



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
        //ぶつかってきた物体otherの名前がPlayerか？
        if (other.gameObject.name == "Player")
        {
            canSee = true;

        }

    }

    private void OnTriggerExit(Collider other)  //衝突から抜けたとき
    {
        //抜けた物体otherの名前はPlayerか？
        if (other.gameObject.name == "Player")
        {
            canSee = false;

        }



    }




}
