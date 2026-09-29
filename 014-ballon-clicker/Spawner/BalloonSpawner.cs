using System.Collections;
using UnityEngine;

public class BalloonSpawner : MonoBehaviour
{
    public GameObject balloonPrefab; // 風船のプレハブ
    public float spawnInterval = 2.0f; // 風船を生成する間隔（秒）

    // Start is called before the first frame update
    void Start()
    {
        StartCoroutine(SpawnBalloons());
    }

    IEnumerator SpawnBalloons()
    {
        // 次の風船を生成するまで待つ
        yield return new WaitForSeconds(spawnInterval);

        while (true)
        {
            // ランダムな位置を生成
            float randomX = Random.Range(-8f, 8f);
            Vector2 spawnPosition = new Vector2(randomX, transform.position.y);

            // 風船を生成
            Instantiate(balloonPrefab, spawnPosition, Quaternion.identity);

            // 次の風船を生成するまで待つ
            yield return new WaitForSeconds(spawnInterval);
        }
    }
}
