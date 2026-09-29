using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class EnemyController : MonoBehaviour
{
    Rigidbody rb;
    Animator anim;
    AttackRange AR;

    float Timer;
    public float ChangeTime;
    public float Speed;

    float currentSpeed = 1.0f;

    GameObject Target;

    bool isRun;     //プレイヤーを追従しているか

    // Start is called before the first frame update
    void Start()
    {
        rb = this.GetComponent<Rigidbody>();            //コンポーネントを取得
        anim = this.GetComponent<Animator>();           //Animatorコンポーネントを取得
        AR = transform.Find("AttackRange").GetComponent<AttackRange>();

        // 30秒後に自分自身を破壊する
        Invoke("SelfDestruct", 30f);
    }

    // Update is called once per frame
    void Update()
    {
        var Switch = AR.Switch;

        //現在再生中のアニメーションをチェック
        var animStateInfo = anim.GetCurrentAnimatorStateInfo(0);
        var hitRange = transform.Find("HitRange").gameObject;

        if (animStateInfo.IsName("Attack"))
        {
            //HItRange　→　ON
            hitRange.SetActive(true);

        }
        else
        {
            //HitRange → OFF
            hitRange.SetActive(false);

        }

        if (Switch == 1)
        {
            return;
        }

        var speed = Vector3.zero;
        speed.z = Speed;
        var rot = transform.eulerAngles;

        if (Target)
        {
            transform.LookAt(Target.transform);
            rot = transform.eulerAngles;
        }
        else
        {
            //プレイヤーを見つけていない時は探索
            Timer += Time.deltaTime;
            if (ChangeTime <= Timer)
            {
                float rand = Random.Range(0, 360);
                rot.y = rand;
                Timer = 0;
            }
        }

        rot.x = 0;
        rot.z = 0;
        transform.eulerAngles = rot;

        this.transform.Translate(speed);

        anim.SetFloat("fSpeed", currentSpeed);
        anim.SetBool("bRun", isRun);

    }

    private void OnTriggerEnter(Collider other)
    {
        if (other.tag == "Player")
        {
            Target = other.gameObject;
            isRun = true;
        }
    }

    private void OnTriggerExit(Collider other)
    {
        if (other.tag == "Player")
        {
            Target = null;
            isRun = false;
        }
    }

    void SelfDestruct()
    {
        Destroy(this.gameObject);
    }
}

