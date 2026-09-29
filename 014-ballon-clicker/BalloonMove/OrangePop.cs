using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class OrangePop : MonoBehaviour
{
    public int PlusScore = 0;
    public AudioClip balloonPopSound; // 風船が割れる音
    private AudioSource audioSource;
    public GameObject effectPrefab; // 追加：エフェクトのプレハブ

    void Start()
    {
        audioSource = Camera.main.GetComponent<AudioSource>();
    }

    // Update is called once per frame
    void Update()
    {
        if (Input.GetMouseButtonDown(0))
        {
            Vector2 mousePosition = Camera.main.ScreenToWorldPoint(Input.mousePosition);

            if (GetComponent<Collider2D>() == Physics2D.OverlapPoint(mousePosition))
            {
                // ScoreManagerのインスタンスを取得
                ScoreManager scoreManager = FindObjectOfType<ScoreManager>();

                // スコアを1点加算
                if (scoreManager != null)
                {
                    scoreManager.AddScore(PlusScore);
                }

                // 風船が割れる音を再生
                audioSource.PlayOneShot(balloonPopSound);

                // エフェクトを表示
                Instantiate(effectPrefab, transform.position, Quaternion.identity);

                // 風船を割る
                Destroy(gameObject);
            }
        }
    }
}
