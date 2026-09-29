using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class ReStart : MonoBehaviour
{
    // Update is called once per frame
    void Update()
    {
        if (Input.GetKeyDown(KeyCode.R))
        {
            // 現在のシーンを再読み込み
            SceneManager.LoadScene(SceneManager.GetActiveScene().name);
        }
    }
}
