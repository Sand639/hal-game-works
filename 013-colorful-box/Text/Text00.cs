using UnityEngine;
using UnityEngine.UI;
using System.Collections;

public class Text00 : MonoBehaviour
{
    public Text[] texts; // InspectorでText1からText4を指定
    public float fadeSpeed = 0.01f; // フェードの速度
    private int currentIndex = 0;

    void Start()
    {
        texts[currentIndex].enabled = true; // 最初のTextを表示
        StartCoroutine(FadeIn(texts[currentIndex])); // ゲーム開始時に最初のTextをフェードイン
    }

    void Update()
    {
        if (Input.GetKeyDown(KeyCode.Return)) // エンターキーが押されたら
        {
            StartCoroutine(FadeSequence(texts[currentIndex], texts[(currentIndex + 1) % texts.Length])); // 現在のTextをフェードアウトし、その後次のTextをフェードイン
            currentIndex = (currentIndex + 1) % texts.Length; // 次のTextのインデックスを更新
        }
    }

    IEnumerator FadeIn(Text text)
    {
        text.color = new Color(text.color.r, text.color.g, text.color.b, 0); // 最初は透明にする

        while (text.color.a < 1)
        {
            text.color = new Color(text.color.r, text.color.g, text.color.b, text.color.a + fadeSpeed); // alpha値を徐々に上げる
            yield return null;
        }
    }

    IEnumerator FadeOut(Text text)
    {
        while (text.color.a > 0)
        {
            text.color = new Color(text.color.r, text.color.g, text.color.b, text.color.a - fadeSpeed); // alpha値を徐々に下げる
            yield return null;
        }
        text.enabled = false; // フェードアウトが完了した後に非表示にする
    }

    IEnumerator FadeSequence(Text textOut, Text textIn)
    {
        yield return StartCoroutine(FadeOut(textOut)); // フェードアウトが完了するまで待つ

        textIn.enabled = true; // 次のTextを表示
        StartCoroutine(FadeIn(textIn)); // フェードアウトが完了したら次のTextをフェードイン
    }
}
