/*
	The following will be APIs and structs of DIO SW component.
*/

#define 4800_BR				4800
#define 9600_BR				9600
#define 19200_BR			19200
#define 38400_BR			38400
#define 57600_BR			57600
#define 115200_BR			115200
#define 921600_BR			921600

struct DIO_sPortPins{
	unsigned char u8Px0 : 1;
	unsigned char u8Px1 : 1;
	unsigned char u8Px2 : 1;
	unsigned char u8Px3 : 1;
	unsigned char u8Px4 : 1;
	unsigned char u8Px5 : 1;
	unsigned char u8Px6 : 1;
	unsigned char u8Px7 : 1;
}__attribute__((packed));
typedef struct DIO_sPortPins DIO_PortPins_s;

union DIO_sPort{
	unsigned char u8Reg;
	DIO_PortPins_s sRegBits;
};
typedef union DIO_sPort DIO_Port_s;

struct DIO_sAttributes{
	DIO_Port_s sDDR;
	DIO_Port_s sPORT;
};
typedef struct DIO_sAttributes DIO_Attributes_s;

enum DIO_eBool{
	E_NOK = 0,
	E_OK
};
typedef enum DIO_eBool BOOL_e;

BOOL_e DIO_Init( DIO_Attributes_s port );

void DIO_WritePort( DIO_Port_s port );
unsigned char DIO_ReadPort( DIO_Port_s port );
void DIO_TogglePort( DIO_Port_s port );

void DIO_WritePortPin( DIO_Port_s port );
unsigned char DIO_ReadPortPin( DIO_Port_s port );
void DIO_TogglePortPin( DIO_Port_s port );


/*
	The following will be APIs and structs of Timer SW component.
	I am assuming that I will be using only the normal mode in a given timer module.
*/

/* Constructor */
void Timer_Init( void );

/* Destructor */
void Timer_DeInit( void );
void Timer_SystemTick( unsigned short tick );

/*
	The following will be APIs and structs of UART SW component.
*/

enum UART_eDataBits{
	E_5_DATA_BITS = 5,
	E_6_DATA_BITS = 6,
	E_7_DATA_BITS = 7,
	E_8_DATA_BITS = 8,
	E_9_DATA_BITS = 9
};
typedef enum UART_eDataBits UART_DataBits_e;

enum UART_eStopBits{
	E_1_STOP_BITS = 1,
	E_2_STOP_BITS = 2,
};
typedef enum UART_eStopBits UART_StopBits_e;

enum UART_eEvenOddParity{
	E_EVEN_PARITY = 0,
	E_ODD_PARITY = 1
};
typedef enum UART_eEvenOddParity UART_EvenOddParity_e;

struct UART_sAttributes{
	unsigned int u32BaudRate;
	unsigned char u8DataBits;
	unsigned char u8StopBits;
	unsigned char u8EvenOddParity;
};
typedef struct UART_sAttributes UART_Attributes_s;

/* Constructor */
void UART_Init( UART_Attributes_s UART_Attributes );

/* Destructor */
void UART_DeInit( void );

void UART_Transmit( unsigned char character );
unsigned char UART_Receive( void );