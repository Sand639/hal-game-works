using UnityEngine;
using UnityEngine.UI;

public class ResultScreen : MonoBehaviour
{
    public Text scoreText; // スコアを表示するTextコンポーネント

    // Start is called before the first frame update
    void Start()
    {
        // スコアを表示
        scoreText.text = ScoreManager.score.ToString();
    }
}
