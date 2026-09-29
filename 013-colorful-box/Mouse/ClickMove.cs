using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ClickMove : MonoBehaviour
{
    private GameObject selectedObject;
    private Vector3 offset;
    private bool isDragging = false;

    // Start is called before the first frame update
    void Start()
    {

    }

    // Update is called once per frame
    void Update()
    {
        Vector2 mousePosition = Camera.main.ScreenToWorldPoint(Input.mousePosition);
        RaycastHit2D hit = Physics2D.Raycast(mousePosition, Vector2.zero);

        if (Input.GetMouseButtonDown(0))
        {
            if (hit.collider != null)
            {
                if (hit.collider.gameObject.tag == "obj")
                {
                    isDragging = true;
                    selectedObject = hit.collider.gameObject;
                    offset = selectedObject.transform.position - Camera.main.ScreenToWorldPoint(new Vector3(Input.mousePosition.x, Input.mousePosition.y, 10.0f));
                }
            }
        }
        else if (Input.GetMouseButton(0))
        {
            if (isDragging)
            {
                Vector3 newPosition = new Vector3(Input.mousePosition.x, Input.mousePosition.y, 10.0f);
                selectedObject.transform.position = Camera.main.ScreenToWorldPoint(newPosition) + offset;
            }
        }
        else if (Input.GetMouseButtonUp(0))
        {
            isDragging = false;
        }
    }
}
