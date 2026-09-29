using UnityEngine;
using UnityEngine.UI;

public class ClickButton : MonoBehaviour
{
    public AudioSource audioSource; // Audio SourceをInspectorからアタッチします

    void Start()
    {
        // ボタンのOnClickイベントにPlaySound関数を追加します
        GetComponent<Button>().onClick.AddListener(PlaySound);
    }

    public void PlaySound()
    {
        // ボタンが押されたときに音を再生します
        audioSource.Play();
    }
}