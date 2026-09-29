using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Player : MonoBehaviour
{
    public float speed = 5.0f; // 移動速度
    public float jumpPower = 5.0f; // ジャンプ力
    public LayerMask groundLayer; // 地面のレイヤー

    private Rigidbody2D rb2d;
    private BoxCollider2D boxCollider;

    // Start is called before the first frame update
    void Start()
    {
        rb2d = GetComponent<Rigidbody2D>();
        boxCollider = GetComponent<BoxCollider2D>();
    }

    // Update is called once per frame
    void Update()
    {
        float inputX = Input.GetAxisRaw("Horizontal");

        // 水平移動
        rb2d.velocity = new Vector2(inputX * speed, rb2d.velocity.y);

        // ジャンプ
        if (IsGrounded() && Input.GetButtonDown("Jump"))
        {
            rb2d.AddForce(Vector2.up * jumpPower, ForceMode2D.Impulse);
        }
    }

    private bool IsGrounded()
    {
        RaycastHit2D raycastHit = Physics2D.BoxCast(boxCollider.bounds.center, boxCollider.bounds.size, 0f, Vector2.down, 0.1f, groundLayer);
        return raycastHit.collider != null;
    }
}
