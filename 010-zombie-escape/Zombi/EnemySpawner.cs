using UnityEngine;
using System.Collections;

public class EnemySpawner : MonoBehaviour
{
    public GameObject enemyPrefab; // 敵のプレハブ
    public GameObject player; // プレイヤー
    public float spawnInterval = 5.0f; // スポーン間隔（秒）
    public int enemiesPerSpawn = 10; // 一度にスポーンする敵の数
    public float spawnRadius = 10.0f; // スポーンする範囲の半径
    public float safeZone = 5.0f; // プレイヤー周囲の安全ゾーン

    void Start()
    {
        StartCoroutine(SpawnEnemies());
    }

    IEnumerator SpawnEnemies()
    {
        while (player != null)
        {
            for (int i = 0; i < enemiesPerSpawn; i++)
            {
                Vector3 spawnPosition;
                do
                {
                    // プレイヤーの周りにランダムな位置を生成
                    spawnPosition = player.transform.position + Random.insideUnitSphere * spawnRadius;
                    spawnPosition.y = player.transform.position.y + 0.5f; // 高さはプレイヤーの高さ+0.5に設定
                }
                while (Vector3.Distance(spawnPosition, player.transform.position) < safeZone); // 安全ゾーン内にスポーンしないようにする

                // 敵のプレハブからインスタンスを生成
                Instantiate(enemyPrefab, spawnPosition, Quaternion.identity);
            }

            // 次のスポーンまで待機
            yield return new WaitForSeconds(spawnInterval);
        }
    }
}
