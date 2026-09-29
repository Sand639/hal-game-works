using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Enemy : MonoBehaviour
{
    [SerializeField, Header("移動速度")]
    private float MoveSpeed;
    [SerializeField, Header("攻撃力")]
    private int AttackPower;


    private Rigidbody2D Rigid;
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
    }

    private void Move()
    {
        Rigid.velocity = new Vector2(Vector2.left.x * MoveSpeed, Rigid.velocity.y);
    }

    public void PlayerDamage(Player player)
    {
        player.Damage(AttackPower);
    }

}
