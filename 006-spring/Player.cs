using System.Collections;
using UnityEngine;
using UnityEngine.InputSystem;

public class Player : MonoBehaviour
{
    [SerializeField, Header("移動速度")]
    private float MoveSpeed;
    [SerializeField, Header("ジャンプ速度")]
    private float JumpSpeed;
    [SerializeField, Header("体力")]
    private int HP;
    [SerializeField, Header("無敵時間")]
    private float DamageTime;
    [SerializeField, Header("点滅時間")]
    private float FlashTime;

    private Vector2 InputDirection;
    private Rigidbody2D Rigid;
    //private Animator anim;
    private SpriteRenderer spriteRenderer;
    private bool bJump;


    bool canInputKey = true;    //キー入力が可能か？
    public AudioClip SE1;
    public AudioClip SE2;



    AudioSource audioSource;

    void EndAttack()
    {
        canInputKey = true;     //キー入力を可能にする
        transform.Find("FxAttack").gameObject.SetActive(false);
    }


    // Start is called before the first frame update
    void Start()
    {
        Rigid = GetComponent<Rigidbody2D>();
        bJump = false;
        spriteRenderer = GetComponent<SpriteRenderer>();
        audioSource = GetComponent<AudioSource>();
    }

    // Update is called once per frame
    void Update()
    {
        Move();
        //Debug.Log(HP);
        LookMoveDirect();
        HitFloor();
    }

    private void Move()
    {
        //if (bJump) return;
        Rigid.velocity = new Vector2(InputDirection.x * MoveSpeed, Rigid.velocity.y);
    }

    private void LookMoveDirect()
    {
        if (InputDirection.x < 0.0f)
        {
            transform.eulerAngles = Vector3.zero;
        }
        else if (InputDirection.x > 0.0f)
        {
            transform.eulerAngles = new Vector3(0.0f, 180f, 0.0f);
        }
    }

    private void OnCollisionEnter2D(Collision2D collision)
    {

        if (collision.gameObject.tag == "Enemy")
        {
            HitEnemy(collision.gameObject);
        }
    }

    private void HitFloor()
    {
        int layerMask = LayerMask.GetMask("Floor");
        Vector2 collisionSize = GetComponent<BoxCollider2D>().size;
        Vector2 boxSize = transform.lossyScale * collisionSize;
        Vector3 rayPos = transform.position - new Vector3(0.0f, boxSize.y / 2.0f);
        Vector3 raySize = new Vector3(boxSize.x - 0.1f, 0.1f);
        RaycastHit2D rayHit = Physics2D.BoxCast(rayPos, raySize, 0.0f, Vector2.zero, 0.0f, layerMask);
        if (rayHit.transform == null)
        {
            bJump = true;
            return;
        }

        if (rayHit.transform.tag == "Floor" && bJump)
        {
            bJump = false;
        }
    }


    private void HitEnemy(GameObject enemy)
    {
        //当たり判定
        float halfScaleY = transform.lossyScale.y / 2.0f;
        float enemyHalfScaleY = enemy.transform.lossyScale.y / 2.0f;

        if (transform.position.y - (halfScaleY - 0.1f) >= enemy.transform.position.y + (enemyHalfScaleY - 0.1f))
        {
            Destroy(enemy);
            Rigid.AddForce(Vector2.up * JumpSpeed, ForceMode2D.Impulse);
            audioSource.PlayOneShot(SE2);
        }
        else
        {
            enemy.GetComponent<EnemyA>().PlayerDamage(this);
            gameObject.layer = LayerMask.NameToLayer("PlayerDamage");
            StartCoroutine(Damage());
            audioSource.PlayOneShot(SE1);
        }

    }

    IEnumerator Damage()
    {
        Color color = spriteRenderer.color;
        for (int i = 0; i < DamageTime; i++)
        {
            yield return new WaitForSeconds(FlashTime);
            spriteRenderer.color = new Color(color.r, color.g, color.b, 0.0f);

            yield return new WaitForSeconds(FlashTime);
            spriteRenderer.color = new Color(color.r, color.g, color.b, 1.0f);
        }
        spriteRenderer.color = color;
        gameObject.layer = LayerMask.NameToLayer("Default");
    }

    private void Dead()
    {
        if (HP <= 0)
        {
            Destroy(gameObject);
        }
    }

    private void OnBecameInvisible()
    {
        Camera camera = Camera.main;
        if (camera.name == "Main Camera" && camera.transform.position.y > transform.position.y)
        {
            Destroy(gameObject);
        }
    }

    public void OnMove(InputAction.CallbackContext context)
    {
        InputDirection = context.ReadValue<Vector2>();
    }

    public void OnJump(InputAction.CallbackContext context)
    {
        if (!context.performed || bJump) return;
        Rigid.AddForce(Vector2.up * JumpSpeed, ForceMode2D.Impulse);
    }

    public void OnAttack(InputAction.CallbackContext context)
    {
        if (canInputKey == true)
        {
            GetComponent<Animator>().SetTrigger("tAttack");    //攻撃アニメーション
            canInputKey = false;

            ////エフェクト再生
            //transform.Find("FxAttack").gameObject.SetActive(true);

            Invoke("EndAttack", 0.5f);

        }
    }

    public void Damage(int damage)
    {
        HP = Mathf.Max(HP - damage, 0);
        Dead();
    }

    public int GetHP()
    {
        return HP;
    }
}
