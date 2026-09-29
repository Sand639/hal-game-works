using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;  //Scene切替メソッドで必要

public class TitleCanvas : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        if(Input.GetKeyDown(KeyCode.Mouse0))    //左クリック
        {
            //フェード開始
            transform.Find("FadeImage").gameObject.GetComponent<Fade>().StartFadeIn();

            Invoke("NextScene", 0.9f);
        }
    }

    void NextScene()
    {
        //sceneをGameに切り替える
        SceneManager.LoadScene("Stage1");
    }
}
