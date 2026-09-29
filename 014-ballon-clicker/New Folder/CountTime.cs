using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

public class TimerManager : MonoBehaviour
{
    public float timeLeft = 60.0f; // 残り時間
    public Text timerText; // 時間を表示するTextコンポーネント
    public string nextSceneName; // 次のシーンの名前

    // Update is called once per frame
    void Update()
    {
        // 時間を減らす
        timeLeft -= Time.deltaTime;

        // 時間が0以下になったら次のシーンに遷移
        if (timeLeft <= 0)
        {
            SceneManager.LoadScene(nextSceneName);
        }

        // 時間を表示（秒:ミリ秒）
        int seconds = (int)timeLeft;
        int milliseconds = (int)((timeLeft - seconds) * 100);
        timerText.text = string.Format("{0}:{1:00}", seconds, milliseconds);
    }
}
