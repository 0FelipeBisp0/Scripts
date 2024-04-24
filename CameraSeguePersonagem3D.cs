using UnityEngine;

public class CameraSeguePersonagem : MonoBehaviour
{
    public Transform target; 
    public Vector3 offset = new Vector3(0f, 0f, 0f);     
    public float velocidadeMovimento = 0f; 
    public float velocidadeRotacao = 0f; 

    void LateUpdate()
    {

        Vector3 desiredPosition = target.position - target.forward * Mathf.Abs(offset.z) + target.up * offset.y;
       
        transform.position = Vector3.Lerp(transform.position, desiredPosition, velocidadeMovimento * Time.deltaTime);
        
        Vector3 lookAtPos = target.position;
        
        Quaternion targetRotation = Quaternion.LookRotation(lookAtPos - transform.position);
       
        transform.rotation = Quaternion.Slerp(transform.rotation, targetRotation, velocidadeRotacao * Time.deltaTime);
    }
}
