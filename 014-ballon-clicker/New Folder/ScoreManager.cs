using UnityEngine;
using UnityEngine.UI;

public class ScoreManager : MonoBehaviour
{
    public static int score = 0; // スコアを保持する変数
    public Text scoreText; // スコアを表示するTextコンポーネント

    // スコアを加算するメソッド
    public void AddScore(int amount)
    {
        score += amount;
        scoreText.text = score.ToString();
    }
}
