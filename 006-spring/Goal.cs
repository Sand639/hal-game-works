using UnityEngine;
using UnityEngine.SceneManagement;

public class Goal : MonoBehaviour
{
    AudioSource audioSource;

    public AudioClip SE4;

    // Start is called before the first frame update
    void Start()
    {

    }

    // Update is called once per frame
    void Update()
    {
        audioSource = GetComponent<AudioSource>();
    }

    private void OnCollisionEnter2D(Collision2D collision)
    {

        if (collision.gameObject.tag == "Player")
        {
            //プレイヤーにばんざいさせる
            GameObject.Find("Player").GetComponent<Animator>().SetTrigger("tClear");

            audioSource.PlayOneShot(SE4);

            //一定時間待つ
            Invoke("MoveNextScene", 1.0f);
        }
    }
    void MoveNextScene()
    {
        //シーンを遷移する
        SceneManager.LoadScene("GameClear");
    }
}
