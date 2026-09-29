using System.Collections;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

public class FadeInOut : MonoBehaviour
{
    public Image image;
    public string nextSceneName = "NextScene";
    public float fadeTime = 3.0f;

    void Start()
    {
        StartCoroutine(FadeAndSwitchScene());
    }

    IEnumerator FadeAndSwitchScene()
    {
        // Fade out (alpha: 1 -> 0)
        for (float t = 0.0f; t < fadeTime; t += Time.deltaTime)
        {
            Color color = image.color;
            color.a = Mathf.Lerp(1, 0, t / fadeTime);
            image.color = color;
            yield return null;
        }

        // Wait for 3 seconds
        yield return new WaitForSeconds(1);

        // Fade in (alpha: 0 -> 1)
        for (float t = 0.0f; t < fadeTime; t += Time.deltaTime)
        {
            Color color = image.color;
            color.a = Mathf.Lerp(0, 1, t / fadeTime);
            image.color = color;
            yield return null;
        }

        // Switch scene
        SceneManager.LoadScene(nextSceneName);
    }
}
