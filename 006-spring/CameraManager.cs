using System.Collections;
using UnityEngine;

public class CameraManager : MonoBehaviour
{
    [SerializeField, Header("振動する時間")]
    private float ShakeTime;

    [SerializeField, Header("振動の大きさ")]
    private float ShakeMagnitude;

    private Player player;
    private Vector3 InitPos;
    private float ShakeCount;
    private int CurrentPlayerHP;
    public GameObject target;



    // Start is called before the first frame update
    void Start()
    {
        player = FindAnyObjectByType<Player>();
        CurrentPlayerHP = player.GetHP();
        InitPos = transform.position;
    }

    // Update is called once per frame
    void Update()
    {
        ShakeCheck();
        FollowPlayer();
    }

    private void ShakeCheck()
    {
        if (CurrentPlayerHP != player.GetHP())
        {
            CurrentPlayerHP = player.GetHP();
            ShakeCount = 0.0f;
            StartCoroutine(Shake());
        }
    }

    IEnumerator Shake()
    {
        Vector3 initPos = transform.position;

        while (ShakeCount < ShakeTime)
        {
            float x = initPos.x + Random.Range(-ShakeMagnitude, ShakeMagnitude);
            float y = initPos.y + Random.Range(-ShakeMagnitude, ShakeMagnitude);
            transform.position = new Vector3(x, y, initPos.z);

            ShakeCount += Time.deltaTime;

            yield return null;
        }

        transform.position = initPos;
    }

    private void FollowPlayer()
    {
        float x = player.transform.position.x;
        x = Mathf.Clamp(x, InitPos.x, Mathf.Infinity);
        transform.position = new Vector3(x, transform.position.y, transform.position.z);
    }

}
