using UnityEngine;

public class EnemyA : MonoBehaviour
{
    [SerializeField, Header("移動速度")]
    private float MoveSpeed;
    [SerializeField, Header("攻撃力")]
    private int AttackPower;
    [SerializeField, Header("往復速度半分")]
    private float half_time;

    private int num = 1;
    private Rigidbody2D Rigid;
    private Vector2 pos;
    private float step_time;
    private Vector2 MoveDirection;



    // Start is called before the first frame update
    void Start()
    {
        Rigid = GetComponent<Rigidbody2D>();
        MoveDirection = Vector2.left;
    }

    // Update is called once per frame
    void Update()
    {
        Move();
        time();
        //ChangeMoveDirection();
        //LookMoveDirection();
    }

    private void Move()
    {
        Rigid.velocity = new Vector2(MoveDirection.x * MoveSpeed * num, Rigid.velocity.y);
        if (step_time < half_time)
        {
            num = -1;
        }
        if (step_time > half_time)
        {
            num = 1;
        }
    }

    //private void ChangeMoveDirection()
    //{
    //    Vector2 halfSize = transform.lossyScale / 2.0f;
    //    int layerMask = LayerMask.GetMask("Floor");
    //    RaycastHit2D ray = Physics2D.Raycast(transform.position, -transform.right, halfSize.x + 0.1f, layerMask);
    //    if (ray.transform == null) return;
    //    if(ray.transform.tag == "Floor")
    //    {
    //        MoveDirection = -MoveDirection;
    //    }
    //}
    //private void LookMoveDirection()
    //{
    //    if (MoveDirection.x < 0.0f)
    //    {
    //        transform.eulerAngles = Vector3.zero;
    //    }
    //    else if (MoveDirection.y > 0.0f)
    //    {
    //        transform.eulerAngles = new Vector3(0.0f, 180.0f, 0.0f);
    //    }
    //}

    private void time()
    {
        step_time += Time.deltaTime;

        if (step_time > half_time * 2)
        {
            step_time = 0;
        }
    }

    public void PlayerDamage(Player player)
    {
        player.Damage(AttackPower);
    }

}
