using UnityEngine;

public class FollowPlayer : MonoBehaviour
{
    public string charaName = "Player";//キャラクターのオブジェクト名

    public Vector3 offset1stPerson; // プレイヤーとカメラの距離（一人称視点）
    public Vector3 offset3rdPerson; // プレイヤーとカメラの距離（三人称視点）
    public float rotateSpeed = 2.0f; // カメラの回転速度
    Vector3 targetPos; //注視点の位置

    GameObject charaObj; //キャラクターオブジェクト

    void Start()
    {
        //名前検索でScene中からオブジェクトを見つける
        charaObj = GameObject.Find(charaName);

        // カメラの初期位置を設定
        transform.position = charaObj.transform.position + offset3rdPerson;
    }

    void Update()
    {
        // 右クリックが押されている場合は一人称視点、それ以外の場合は三人称視点にする
        Vector3 offset = Input.GetMouseButton(1) ? offset1stPerson : offset3rdPerson;
        float currentRotateSpeed = Input.GetMouseButton(1) ? rotateSpeed / 5.0f : rotateSpeed;

        // マウスの入力に基づいてカメラを回転させる
        float mouseX = Input.GetAxis("Mouse X") * currentRotateSpeed;
        float mouseY = Input.GetAxis("Mouse Y") * currentRotateSpeed * -1;

        // プレイヤーの周りでカメラを左右に回転させる
        transform.RotateAround(charaObj.transform.position, Vector3.up, mouseX);

        // プレイヤーの周りでカメラを上下に回転させる
        Vector3 backupPos = transform.position;
        Vector3 backupAngle = transform.eulerAngles;
        Vector3 right = Vector3.Cross(Vector3.up, transform.forward).normalized; // Compute the world-space right vector
        transform.RotateAround(charaObj.transform.position, right, mouseY); // Rotate around the world-space right vector

        if (transform.eulerAngles.x > 30 && transform.eulerAngles.x < 90) //もし45°以上傾けたらそれ以上傾かないようにする
        {
            transform.position = backupPos;
            transform.eulerAngles = backupAngle;
        }
        else if (transform.eulerAngles.x > 275 && transform.eulerAngles.x < 355) //もし45°以上傾けたらそれ以上傾かないようにする
        {
            transform.position = backupPos;
            transform.eulerAngles = backupAngle;
        }

        transform.eulerAngles = new Vector3(transform.eulerAngles.x, transform.eulerAngles.y, 0.0f);

        // プレイヤーの向きをカメラの向きに合わせる
        if (!Input.GetMouseButton(1) && Mathf.Abs(mouseX) > 0.1f)
        {
            Quaternion playerRotation = Quaternion.Euler(0.0f, transform.eulerAngles.y, 0.0f);
            charaObj.transform.rotation = Quaternion.Slerp(charaObj.transform.rotation, playerRotation, Time.deltaTime * rotateSpeed);
        }


        // プレイヤーの位置にオフセットを加えてカメラの位置を更新
        transform.position = charaObj.transform.position + Quaternion.Euler(0, transform.eulerAngles.y, 0) * offset;
    }
}
