using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class StageStart : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        //しばらくしたらフェードアウト
        Invoke("FadeOutStageStart", 1.0f);
        Invoke("HideStageStart", 2.0f);
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    void HideStageStart()
    {
        gameObject.SetActive(false);
    }

    void FadeOutStageStart()
    {
        GetComponent<Fade>().StartFadeOut();
    }

}
