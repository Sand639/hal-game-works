using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerController : MonoBehaviour
{
    public Transform Camera;
    public float PlayerSpeed;
    public float PlayerRotation;

    Vector3 speed = Vector3.zero;
    Vector3 rot = Vector3.zero;

    public Animator PlayerAnimator;
    bool isRun;

    public Collider WerponCollider;
    bool canMove = true;

    public AudioSource audioSource;
    public AudioClip AttackSE;

    public EnemyListManager enemyListManager;
    public Transform Target;
    int TargetCount;

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        Move();
        Rotation();
        Attack();

        TargetLook();

        Camera.transform.position = transform.position;
    }

    void Move()
    {
        if(!canMove)    //canMove == false
        {
            return;
        }
        speed = Vector3.zero;
        rot = Vector3.zero;
        isRun = false;

        if (Input.GetKey(KeyCode.W))
        {
            rot.y = 0;
            MoveSet();
        }
        if (Input.GetKey(KeyCode.A))
        {
            rot.y = -90;
            MoveSet();
        }
        if (Input.GetKey(KeyCode.S))
        {
            rot.y = 180;
            MoveSet();
        }
        if (Input.GetKey(KeyCode.D))
        {
            rot.y = 90;
            MoveSet();
        }

        transform.Translate(speed);
        PlayerAnimator.SetBool("bRun",isRun);

    }

    void MoveSet()
    {
        speed.z = PlayerSpeed;
        transform.eulerAngles = Camera.transform.eulerAngles + rot;
        isRun = true;

    }


    void Rotation()
    {
        var speed = Vector3.zero;
        if (Input.GetKey(KeyCode.LeftArrow))
        {
            speed.y = -PlayerRotation;
        }
        if (Input.GetKey(KeyCode.RightArrow))
        {
            speed.y = PlayerRotation;
        }
        Camera.transform.eulerAngles += speed;
    }

    void Attack()
    {
        if(Input.GetKeyDown(KeyCode.Space))
        {
            PlayerAnimator.SetBool("bAttack", true);
            canMove = false;
            audioSource.PlayOneShot(AttackSE);
        }
    }


    void WerponON()
    {
        WerponCollider.enabled = true;
    }

    void WerponOFF()
    {
        WerponCollider.enabled = false;
        PlayerAnimator.SetBool("bAttack", false);
    }

    void CanMove()
    {
        canMove = true;
    }

    //ターゲットロック
    void TargetLook()
    {
        //ターゲットをセットする
        if(Input.GetKeyDown(KeyCode.RightShift))
        {
            //リストが0なら止める
            if (enemyListManager.EnemyList.Count == 0)
            {
                return;
            }

            //リストの数をカウントが超えたら0にリセット
            if (enemyListManager.EnemyList.Count <= TargetCount)
            {
                TargetCount = 0;
            }

            //ターゲットをリストからセットする
            Target = enemyListManager.EnemyList[TargetCount];
            //カウントを進める
            TargetCount++;
        }

        //ロックを解除する
        if(Input.GetKeyDown(KeyCode.RightControl))
        {
            Target = null;
        }

        //ターゲットがセットされていたら
        if(Target)
        {
            //ターゲットの座標を保管
            var pos = Vector3.zero;
            pos = Target.position;
            //カメラが上下しないように、高さはカメラ基準にする
            pos.y = Camera.transform.position.y;

            //ターゲットを見る
            Camera.transform.LookAt(pos);
        }
    }

}


