using UnityEngine;

public class GameStart : MonoBehaviour
{
    void Start()
    {
        // ゲーム開始時にマウスカーソルを非表示にし、ゲームウィンドウの中央にロックする
        Cursor.visible = false;
        Cursor.lockState = CursorLockMode.Locked;
    }

    // Update is called once per frame
    void Update()
    {
        if (Input.GetKeyDown(KeyCode.Escape))
        {
            Cursor.visible = true;
            Cursor.lockState = CursorLockMode.None;
        }
    }

}
