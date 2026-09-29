using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;


public class Player : MonoBehaviour
{
    Rigidbody rb;
    Animator anim;
    GameObject cameraObj;

    public int MaxHP = 100;  //HP変数
    public int hp = 100;  //HP変数
    public Image HPGage;

    Vector3 moveForward; //移動度

    [Header("カメラオブジェクト名")]
    public string cameraName = "Main Camera"; //カメラオブジェクト名

    [Header("移動速度・ジャンプ力")]
    public float speed = 1.0f;             //キャラクターの移動スピード
    public float jumpPower = 5.0f;         //ジャンプ力

    bool isRun;     //走ってるか

    float currentSpeed = 1.0f;

    // Start is called before the first frame update
    void Start()
    {
        rb = this.GetComponent<Rigidbody>();            //コンポーネントを取得
        anim = this.GetComponent<Animator>();           //Animatorコンポーネントを取得
        cameraObj = GameObject.Find(cameraName);        //カメラオブジェクトを見つけておく
    }

    // Update is called once per frame
    void Update()
    {

        isRun = false;

        //入力ベクトルの取得
        var inputX = Input.GetAxisRaw("Horizontal");
        var inputY = Input.GetAxisRaw("Vertical");

        //カメラの方向ベクトルから、Yをゼロにすることで、X-Z平面の単位ベクトルを取得
        Vector3 cameraForward = Vector3.Scale(cameraObj.transform.forward, new Vector3(1, 0, 1)).normalized;

        //キー入力値とカメラの向きから、移動方向を決定
        moveForward = cameraForward * inputY + cameraObj.transform.right * inputX;
        moveForward.y = 0; // Y軸方向の移動は無視
        moveForward = moveForward.normalized;

        //接地判定用の球体の、
        //中心位置を足元から10センチ上にする
        Vector3 center = transform.position + Vector3.up * -0.10f;
        //半径も設定
        float radius = 0.2f;
        //判定対象を、Groundレイヤーのオブジェクトのみにしぼる
        LayerMask layer = LayerMask.GetMask("Ground");

        //球体にGroundレイヤーのオブジェクトが重なったらisGroundフラグをtrueにする
        bool isGround = Physics.CheckSphere(center, radius, layer);


        //ジャンプ
        if (Input.GetKeyDown(KeyCode.Space) && isGround)
        {
            rb.AddForce(Vector3.up * jumpPower, ForceMode.Impulse);
        }



        // プレイヤーがカメラの前を向く
        // 新しい回転を計算
        Quaternion newRotation = Quaternion.LookRotation(Camera.main.transform.forward, Vector3.up);

        // 新しい回転のX軸を現在のX軸の回転に設定
        newRotation.eulerAngles = new Vector3(0.0f, newRotation.eulerAngles.y, newRotation.eulerAngles.z);

        // 新しい回転を適用
        transform.rotation = newRotation;

        // Shiftキーが押されている場合は速度を3倍にし、右クリックが押されている場合は速度を5分の1にし、それ以外の場合は速度を1倍にする
        if (Input.GetMouseButton(1))
        {
            currentSpeed = speed / 3.0f;
        }
        else if (Input.GetKey(KeyCode.LeftShift))
        {       
            currentSpeed = speed * 3;
        }
        else
        {
            currentSpeed = speed;
        }

        //プレイヤーを移動させる
        rb.AddForce(moveForward * currentSpeed, ForceMode.VelocityChange);

        //プレイヤーが動いているかどうかを判定
        if (moveForward.magnitude > 0)
        {
            isRun = true;
        }

        anim.SetFloat("fSpeed",currentSpeed/1.5f);
        anim.SetBool("bRun", isRun);


        //速さの制限
        float yVelocity = rb.velocity.y;
        Vector3 velocityWithoutY = new Vector3(rb.velocity.x, 0, rb.velocity.z);
        velocityWithoutY = Vector3.ClampMagnitude(velocityWithoutY, currentSpeed);
        rb.velocity = new Vector3(velocityWithoutY.x, yVelocity, velocityWithoutY.z);
    }

    private void OnTriggerEnter(Collider other)
    {
        if (other.gameObject.name == "HitRange")
        {
            //ダメージ量を取ってくる
            var damage = other.gameObject.GetComponent<HitRange>().damage;

            //ヒットエフェクトを表示
            var fxHit = transform.Find("FxHit").gameObject;
            fxHit.SetActive(true);

            //Hpを減らす
            hp = hp - damage;

            float percent = (float)hp / MaxHP;
            HPGage.fillAmount = percent;

            //HPが0以下か？
            if (hp <= 0)
            {
                ////死亡エフェクト
                //var fxDie = transform.Find("FxDie").gameObject;
                //fxDie.SetActive(true);

                ////自身の当たり判定領域を無効にする
                //GetComponent<CharacterController>().enabled = false;

                Destroy(this.gameObject);

                Cursor.visible = true;
                Cursor.lockState = CursorLockMode.None;

                SceneManager.LoadScene("GameOver");    //シーンを読み込む

            }

        }

    }

}
