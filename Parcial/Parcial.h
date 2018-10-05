



typedef struct {

    int id;
    char nombre[32];
    char apellido[32];
    int cuit;
    int isEmpy;




}Cliente;

typedef struct {

    int id;
    int idCliente;
    int cantidadAfiches;
    char nombreArchivo[32];
    char zona[16];
    int isEmpy;
    int estado;


}Venta;

int parcial_altaCliente(Cliente* pBuffer,int limite);

int parcial_altaVenta(Venta* pBuffer,Cliente* pBufferCLiente,int limite);

int parcial_inicializarCliente(Cliente* pBuffer,int limite);

int parcial_ventaCobrada(Venta* pBuffer,int limite);

int parcial_inicializarVenta(Venta* pBuffer,int limite);

int parcial_menu(Cliente* pBuffer,int limite);

int parcial_modificarPantalla(Cliente* pBuffer);

int parcial_modificarVenta(Venta* pBuffer);

int menu(Cliente* pBuffer,Venta* pBufferSecundario,int limite,int limiteVentas);
