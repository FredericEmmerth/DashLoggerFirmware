void print_menu(void) 

{ 

printf("Menu :\r\n" 

" -- Select the action:\r\n" 

" 1: Send FD standard message with ID: 0x45A and 64 byte data 0 to 63. \r\n" 

" 2: Send normal standard message with ID: 0x469 and 8 byte data 0 to 7. \r\n" 

" 3: To receive CAN FD or Normal message \r\n" 

" m: Display menu \r\n\r\n"); 

} 

 

int main ( void ) 

{ 

uint32_t messageID = 0; 

uint32_t rx_messageID = 0; 

uint32_t status = 0; 

uint8_t messageLength = 0; 

uint8_t rx_messageLength = 0; 

uint8_t count = 0; 

uint8_t user_input = 0; 

CANFD_MSG_RX_ATTRIBUTE msgAttr = CANFD_MSG_RX_DATA_FRAME; 

 

/* Initialize all modules */ 

SYS_Initialize ( NULL ); 

 

printf(" ------------------------------ \r\n"); 

printf(" CAN FD Demo \r\n"); 

printf(" ------------------------------ \r\n"); 

 

print_menu(); 

 

/* Prepare the message to send*/ 

for (count = 0; count < 64; count++) 

{ 

message[count] = count; 

} 

 

while ( true ) 

{ 

/* Maintain state machines of all polled Harmony modules. */ 

/* Check if there is a received character */ 

if(UART2_ReceiverIsReady() == true) 

{ 

if(UART2_ErrorGet() == UART_ERROR_NONE) 

{ 

UART2_Read((void *)&user_input, 1); 

} 

switch (user_input) 

{ 

case '1': 

printf(" Transmitting CAN FD Message:"); 

messageID = 0x45A; 

messageLength = 64; 

if (CAN1_MessageTransmit(messageID, messageLength, message, 1, CANFD_MODE_FD_WITH_BRS, CANFD_MSG_TX_DATA_FRAME) == true) 

{ 

printf("Success \r\n"); 

LED_Toggle(); 

} 

else 

{ 

printf("Failed \r\n"); 

} 

break; 

case '2': 

printf(" Transmitting CAN Normal Message:"); 

messageID = 0x469; 

messageLength = 8; 

if (CAN1_MessageTransmit(messageID, messageLength, message, 1, CANFD_MODE_NORMAL, CANFD_MSG_TX_DATA_FRAME) == true) 

{ 

printf("Success \r\n"); 

LED_Toggle(); 

} 

else 

{ 

printf("Failed \r\n"); 

} 

break; 

case '3': 

printf(" Waiting for message: \r\n"); 

while (true) 

{ 

if (CAN1_InterruptGet(2, CANFD_FIFO_INTERRUPT_TFNRFNIF_MASK)) 

{ 

/* Check CAN Status */ 

status = CAN1_ErrorGet(); 

 

if (status == CANFD_ERROR_NONE) 

{ 

memset(rx_message, 0x00, sizeof(rx_message)); 

 

/* Receive New Message */ 

if (CAN1_MessageReceive(&rx_messageID, &rx_messageLength, rx_message, 0, 2, &msgAttr) == true) 

{ 

printf(" New Message Received \r\n"); 

status = CAN1_ErrorGet(); 

if (status == CANFD_ERROR_NONE) 

{ 

/* Print message to Console */ 

uint8_t length = rx_messageLength; 

printf(" Message - ID : 0x%x Length : 0x%x ", (unsigned int) rx_messageID,(unsigned int) rx_messageLength); 

printf("Message : "); 

while(length) 

{ 

printf("0x%x ", rx_message[rx_messageLength - length--]); 

} 

printf("\r\n"); 

LED_Toggle(); 

break; 

} 

else 

{ 

printf("Error in received message"); 

} 

} 

else 

{ 

printf("Message Reception Failed \r"); 

} 

} 

else 

{ 

printf("Error in last received message"); 

} 

} 

} 

break; 

default: 

printf(" Invalid Input \r\n"); 

break; 

} 

print_menu(); 

} 

} 

 

/* Execution should not come here during normal operation */ 

 

return ( EXIT_FAILURE ); 

} 

 

CAN FD operation with interrupt 

The following example shows the CAN FD mode operation with interrupt implementation. 

 

/* Application's state machine enum */ 

typedef enum 

{ 

APP_STATE_CAN_RECEIVE, 

APP_STATE_CAN_TRANSMIT, 

APP_STATE_CAN_IDLE, 

APP_STATE_CAN_USER_INPUT, 

APP_STATE_CAN_XFER_SUCCESSFUL, 

APP_STATE_CAN_XFER_ERROR 

} APP_STATES; 

 

/* Variable to save application state */ 

static APP_STATES state = APP_STATE_CAN_USER_INPUT; 

 

void APP_CAN_Callback(uintptr_t context) 

{ 

xferContext = context; 

 

/* Check CAN Status */ 

status = CAN1_ErrorGet(); 

 

if ((status & (CANFD_ERROR_TX_RX_WARNING_STATE | CANFD_ERROR_RX_WARNING_STATE | 

CANFD_ERROR_TX_WARNING_STATE | CANFD_ERROR_RX_BUS_PASSIVE_STATE | 

CANFD_ERROR_TX_BUS_PASSIVE_STATE | CANFD_ERROR_TX_BUS_OFF_STATE)) == CANFD_ERROR_NONE) 

{ 

switch ((APP_STATES)context) 

{ 

case APP_STATE_CAN_RECEIVE: 

case APP_STATE_CAN_TRANSMIT: 

{ 

state = APP_STATE_CAN_XFER_SUCCESSFUL; 

break; 

} 

default: 

break; 

} 

} 

else 

{ 

state = APP_STATE_CAN_XFER_ERROR; 

} 

} 

 

int main ( void ) 

{ 

uint8_t count = 0; 

bool user_input = 0; 

 

/* Initialize all modules */ 

SYS_Initialize ( NULL ); 

 

/* Prepare the message to send*/ 

messageID = 0x45A; 

messageLength = 64; 

for (count = 0; count < 64; count++) 

{ 

message[count] = count; 

} 

 

while ( true ) 

{ 

if (state == APP_STATE_CAN_USER_INPUT) 

{ 

if(SWITCH_Get() == SWITCH_PRESSED_STATE) 

{ 

while(SWITCH_Get() == SWITCH_PRESSED_STATE); 

 

switch (user_input) 

{ 

case 0: 

CAN1_CallbackRegister( APP_CAN_Callback, (uintptr_t)APP_STATE_CAN_TRANSMIT, 1 ); 

state = APP_STATE_CAN_IDLE; 

CAN1_MessageTransmit(messageID, messageLength, message, 1, CANFD_MODE_FD_WITH_BRS, CANFD_MSG_TX_DATA_FRAME); 

break; 

case 1: 

CAN1_CallbackRegister( APP_CAN_Callback, (uintptr_t)APP_STATE_CAN_RECEIVE, 2 ); 

state = APP_STATE_CAN_IDLE; 

memset(rx_message, 0x00, sizeof(rx_message)); 

/* Receive New Message */ 

CAN1_MessageReceive(&rx_messageID, &rx_messageLength, rx_message, 0, 2, &msgAttr); 

break; 

default: 

break; 

} 

} 

else 

{ 

continue; 

} 

} 

/* Check the application's current state. */ 

switch (state) 

{ 

case APP_STATE_CAN_IDLE: 

{ 

/* Application can do other task here */ 

break; 

} 

case APP_STATE_CAN_XFER_SUCCESSFUL: 

{ 

if ((APP_STATES)xferContext == APP_STATE_CAN_RECEIVE) 

{ 

} 

else if ((APP_STATES)xferContext == APP_STATE_CAN_TRANSMIT) 

{ 

} 

LED_Toggle(); 

state = APP_STATE_CAN_USER_INPUT; 

break; 

} 

case APP_STATE_CAN_XFER_ERROR: 

{ 

if ((APP_STATES)xferContext == APP_STATE_CAN_RECEIVE) 

{ 

} 

else 

{ 

} 

state = APP_STATE_CAN_USER_INPUT; 

break; 

} 

default: 

break; 

} 

 

} 

 

/* Execution should not come here during normal operation */ 

 

return ( EXIT_FAILURE );