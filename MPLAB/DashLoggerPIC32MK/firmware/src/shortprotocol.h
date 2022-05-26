/* 
 * File:   shortprotocol.h
 * Author: Frederic
 *
 * Created on 19. Mai 2022, 13:37
 */

#ifndef SHORTPROTOCOL_H
#define	SHORTPROTOCOL_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include "definitions.h"
#include "crc.h"

#define SHORTPROTOCOL_MAXIMUM_COMMAND_LENGTH 50
#define SHORTPROTOCOL_BEGIN 0x13
#define SHORTPROTOCOL_OVERHEAD_BYTES 5
#define SHORTPROTOCOL_OVERHEAD_WITHOUT_CRC_BYTES 3
#define SHORTPROTOCOL_FIRST_BYTE_MASK 0x00FF
#define SHORTPROTOCOL_SECOND_BYTE_MASK 0xFF00
#define SHORTPROTOCOL_BYTE_LENGTH 8
#define SHORTPROTOCOL_BEGIN_OFFSET 0
#define SHORTPROTOCOL_LENGTH_LSB_OFFSET 1
#define SHORTPROTOCOL_LENGTH_MSB_OFFSET 2
#define SHORTPROTOCOL_COMMAND_OFFSET 3
#define SHORTPROTOCOL_CRC_LSB_OFFSET 0
#define SHORTPROTOCOL_CRC_MSB_OFFSET 1
    
typedef enum{
    SHORTPROTOCOL_SUCCESS = 0,
    SHORTPROTOCOL_ERROR,
    SHORTPROTOCOL_AVAILABLE,
    SHORTPROTOCOL_NOT_AVAILABLE
}SHORTPROTOCOL_status;

typedef struct{
    uint32_t length;
    uint8_t data[SHORTPROTOCOL_MAXIMUM_COMMAND_LENGTH +
                        SHORTPROTOCOL_OVERHEAD_BYTES];
}SHORTPROTOCOL_string;
    
typedef struct{
    uint8_t (*readByte)(void);
    SHORTPROTOCOL_status (*readAvailable)(void);
    void (*writeByte)(uint8_t);
    SHORTPROTOCOL_status (*writeAvailable)(void);
    uint32_t maximumPackageLength;
    SHORTPROTOCOL_string command_buffer;
    SHORTPROTOCOL_status newCommand;
    uint32_t writeCounter;
    
}SHORTPROTOCOL_Instance;
    
SHORTPROTOCOL_status SHORTPROTOCOL_Send(SHORTPROTOCOL_Instance* inst,
        uint8_t* data, uint32_t length);

void SHORTPROTOCOL_Update(SHORTPROTOCOL_Instance* inst);

SHORTPROTOCOL_status SHORTPROTOCOL_Available(SHORTPROTOCOL_Instance* inst);

void SHORTPROTOCOL_Initialize(SHORTPROTOCOL_Instance* inst);

#ifdef	__cplusplus
}
#endif

#endif	/* SHORTPROTOCOL_H */

