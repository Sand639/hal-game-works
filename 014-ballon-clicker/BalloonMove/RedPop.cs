using UnityEngine;

public class RedPop : MonoBehaviour
{
    public float speed = 2.0f; // 風船の移動速度
    public float amplitude = 2.0f; // 風船の振幅
    public int PlusScore = 0;
    public AudioClip balloonPopSound; // 風船が割れる音
    public GameObject effectPrefab; // 追加：エフェクトのプレハブ

    private Vector2 startPosition; // 風船の初期位置
    private AudioSource audioSource;

    // Start is called before the first frame update
    void Start()
    {
        startPosition = transform.position;
        audioSource = Camera.main.GetComponent<AudioSource>();
    }

    // Update is called once per frame
    void Update()
    {
        float x = startPosition.x + amplitude * Mathf.Sin(Time.time * speed);
        float y = transform.position.y;

        transform.position = new Vector2(x, y);

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
