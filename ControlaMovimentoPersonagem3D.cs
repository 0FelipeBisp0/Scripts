using UnityEngine;

public class ControlaMovimentoPersonagem : MonoBehaviour
{
    public float velocidade = 5.0f;
    public float giro = 90.0f;
    
    Vector3 inicio;

    void start()
    {
        inicio = transform.position;
    }

    void Update()
    {
        if(Input.GetKey(KeyCode.D))
        {
            transform.Rotate(Vector3.up,giro * Time.deltaTime);
        }
        else if(Input.GetKey(KeyCode.A))
        {
            transform.Rotate(Vector3.up, -giro*Time.deltaTime);
        }
        if(Input.GetKey(KeyCode.W))
        {
            transform.Translate(Vector3.forward * velocidade * Time.deltaTime);
        }
        else if (Input.GetKey(KeyCode.S))
        {
            transform.Translate(-Vector3.forward * velocidade * Time.deltaTime);
        }
    }
}
