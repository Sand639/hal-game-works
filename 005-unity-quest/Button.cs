using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Button : MonoBehaviour
{
    //フィールド
    public GameObject optionPanel;  //オプションパネル

    public GameObject optionButton; //オプションボタン

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    public void OnOptionPush()  //オプションボタンが押された時
    {
        //オプションパネルを開く
        optionPanel.SetActive(true);
        Invoke("OpenOptionPanel", 0.5f);
    }

    void OpenOptionPanel()
    {
        //オプションボタンを消す
        gameObject.SetActive(false);
    }

    public void OnQuitPush()    //ゲーム終了ボタン
    {
        Invoke("QuitGame", 0.5f);       
    }

    void QuitGame()
    {
        //ゲームを終了させる
        Application.Quit();
    }

    public void OnBackPush()    //戻るボタンが押された時
    {
        Invoke("CloseOptionPanel", 0.5f);        
    }

    void CloseOptionPanel()
    {
        //オプションパネルを閉じる
        optionPanel.SetActive(false);

        //オプションボタンを表示
        optionButton.SetActive(true);
    }
}
