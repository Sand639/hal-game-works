using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class Goal1 : MonoBehaviour
{
    public GameObject stageClearImage;  //ステージクリアImage

    public string nextScene;    //次のステージ

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
        if (other.gameObject.name =="Player")
        {
            //花火を上げる
            transform.Find("FxHanabi").gameObject.SetActive(true);

            //一定時間待つ
            Invoke("MoveNextScene", 3.0f);

            //プレイヤーにばんざいさせる
            GameObject.Find("Player").GetComponent<Animator>().SetTrigger("tYeah");

            //ステージクリア表示をONにする
            stageClearImage.SetActive(true);
        }
    }

    //ゴール到達後、一定時間経過後に呼びだすメソッド
    void MoveNextScene()
    {
        //シーンを遷移する
        SceneManager.LoadScene(nextScene);
    }
    
}