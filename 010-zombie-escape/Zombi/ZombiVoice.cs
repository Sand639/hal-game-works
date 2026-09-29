using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ZombiVoice : MonoBehaviour
{
    private AudioSource audioSource;

    void Start()
    {
        audioSource = GetComponent<AudioSource>();
        StartCoroutine(PlayAudioClip());
    }

    IEnumerator PlayAudioClip()
    {
        while (true)
        {
            audioSource.Play();
            yield return new WaitForSeconds(10);
        }
    }
}
