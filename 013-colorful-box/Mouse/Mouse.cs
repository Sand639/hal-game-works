using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Mouse : MonoBehaviour
{
    private GameObject selectedObject;

    // Start is called before the first frame update
    void Start()
    {

    }

    // Update is called once per frame
    void Update()
    {
        Vector2 mousePosition = Camera.main.ScreenToWorldPoint(Input.mousePosition);
        RaycastHit2D hit = Physics2D.Raycast(mousePosition, Vector2.zero);

        if (Input.GetMouseButton(0))
        {

            if (hit.collider != null)
            {
                if (hit.collider.gameObject.tag == "obj")
                {
                    selectedObject = hit.collider.gameObject;
                }
            }

            if (selectedObject != null)
            {
                selectedObject.transform.position = mousePosition;
            }
        }
        else if (Input.GetMouseButtonUp(0))
        {
            if (selectedObject != null)
            {
                // マウスを離したときにオブジェクトの位置を四捨五入せずにそのままにする
                selectedObject.transform.position = new Vector2(selectedObject.transform.position.x, selectedObject.transform.position.y);
            }

            selectedObject = null;
        }
    }
}
