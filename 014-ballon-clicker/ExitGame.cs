using UnityEngine;

public class ExitOnBackspace : MonoBehaviour
{
    void Update()
    {
        if (Input.GetKeyDown(KeyCode.Backspace))
        {
#if UNITY_EDITOR
            UnityEditor.EditorApplication.isPlaying = false;
#else
                Application.Quit();
#endif
        }
    }
}
