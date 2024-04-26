using UnityEngine;

public class Player : MonoBehaviour
{
    public float velocidadeMovimento = 5f;
    public float velocidadeCorrer = 10f;

    private float mouseX;
    private float mouseY;

    public float limiteSuperior = 90f;
    public float limiteInferior = -90f;
    public float alturaDesejada = 10.5f;

    private bool colidindoComParede = false;

    void Start()
    {
        Cursor.lockState = CursorLockMode.Locked;
        Cursor.visible = false;
    }

    void Update()
    {
        float inputFrente = Input.GetAxis("Vertical");
        float inputLateral = Input.GetAxis("Horizontal");
        bool correndo = Input.GetKey(KeyCode.LeftShift) || Input.GetKey(KeyCode.RightShift);
        float velocidadeAtual = correndo ? velocidadeCorrer : velocidadeMovimento;

        
        if (colidindoComParede)
        {
            inputFrente = 0; 
        }

        Vector3 deslocamentoFrente = transform.forward * inputFrente * velocidadeAtual * Time.deltaTime;
        Vector3 deslocamentoLateral = transform.right * inputLateral * velocidadeAtual * Time.deltaTime;

        transform.position += deslocamentoFrente + deslocamentoLateral;

        mouseX += Input.GetAxis("Mouse X");
        mouseY -= Input.GetAxis("Mouse Y");
        mouseY = Mathf.Clamp(mouseY, limiteInferior, limiteSuperior);

        transform.eulerAngles = new Vector3(mouseY, mouseX, 0);

        transform.position = new Vector3(transform.position.x, alturaDesejada, transform.position.z);
    }

    private void OnCollisionEnter(Collision collision)
    {
        if (collision.gameObject.CompareTag("paredefina") || collision.gameObject.CompareTag("Wall"))
        {
            colidindoComParede = true;
        }
    }

    private void OnCollisionExit(Collision collision)
    {
        if (collision.gameObject.CompareTag("paredefina") || collision.gameObject.CompareTag("Wall"))
        {
            colidindoComParede = false;
        }
    }
}
