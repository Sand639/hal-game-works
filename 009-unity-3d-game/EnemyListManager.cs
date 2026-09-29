using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class EnemyListManager : MonoBehaviour
{
   public List<Transform> EnemyList = new List<Transform>();

    // Update is called once per frame
    void Update()
    {
        //リスト内で重複しないようにする
        for (int i = 0; i < EnemyList.Count; i++)
        {
            //次のやつから比較する
            for(int k = i + 1; k < EnemyList.Count; k++)
            {
                //重複していたら削除
                if (EnemyList[i] == EnemyList[k])
                {
                    EnemyList.RemoveAt(k);
                }
            }

            //敵が削除済みならリストからも削除
            if (!EnemyList[i])
            {
                EnemyList.RemoveAt(i);
            }

        }
    }

    void OnTriggerEnter(Collider collider)
    {
        if(collider.tag == "Enemy")
        {
            EnemyList.Add(collider.gameObject.transform);
        }
    }

    void OnTriggerExit(Collider collider)
    {
        if (collider.tag == "Enemy")
        {
            for(int i =0; i<EnemyList.Count; i++)
            {
                //リストから同じ敵を見つけて削除する
                if (EnemyList[i] == collider.gameObject.transform)
                {
                    EnemyList.RemoveAt(i);
                }
            }
        }

    }
}
