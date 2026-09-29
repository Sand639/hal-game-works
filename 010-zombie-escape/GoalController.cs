using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class GoalController : MonoBehaviour
{
    //衝突したとき
    private void OnCollisionEnter(Collision collision)
    {
        if(collision.gameObject.name == "Player")//←自分のキャラクター名にすること
        {
            //リザルト画面でマウス操作ができるよう、
            //下記2つのカーソル復活処理を追加

            //カーソルを表示
            Cursor.visible = true;
            //カーソルのロックを外す
            Cursor.lockState = CursorLockMode.None;

            SceneManager.LoadScene("Result");
        }
    }

}
