using UnityEngine;
using UnityEngine.UI;

public class PlayerHP : MonoBehaviour
{

    [SerializeField, Header("HPアイコン")]
    private GameObject PlayerIcon;

    private Player player;
    private int BeforeHp;

    // Start is called before the first frame update
    void Start()
    {
        player = FindObjectOfType<Player>();
        BeforeHp = player.GetHP();
        CreateHPIcon();
    }

    private void CreateHPIcon()
    {
        for (int i = 0; i < player.GetHP(); i++)
        {
            GameObject PlayerHPObj = Instantiate(PlayerIcon);
            PlayerHPObj.transform.parent = transform;
        }
    }

    // Update is called once per frame
    void Update()
    {
        ShowHPIcon();
    }

    private void ShowHPIcon()
    {
        if (BeforeHp == player.GetHP()) return;

        Image[] Icons = transform.GetComponentsInChildren<Image>();
        for (int i = 0; i < Icons.Length; i++)
        {
            Icons[i].gameObject.SetActive(i < player.GetHP());
        }
        BeforeHp = player.GetHP();
    }

}
