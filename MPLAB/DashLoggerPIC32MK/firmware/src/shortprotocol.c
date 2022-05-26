#include "shortprotocol.h"

SHORTPROTOCOL_status SHORTPROTOCOL_Send(SHORTPROTOCOL_Instance* inst,
        uint8_t* data, uint32_t length){
    /* Command Length without Zero Termination */
    /* This Function generates a Shortprotocol Packet from a Command */
    
    /* If the last Packet is not yet send, cant accept a new Command */
    if(inst->newCommand == SHORTPROTOCOL_NOT_AVAILABLE){
        return SHORTPROTOCOL_NOT_AVAILABLE;
    }
    
    /* Check that the Command will fit in the Packet Buffer */
    if(length > SHORTPROTOCOL_MAXIMUM_COMMAND_LENGTH){
        length = SHORTPROTOCOL_MAXIMUM_COMMAND_LENGTH;
    }
    
    /* Check that the Command is not zero length */
    if(length == 0){
        return SHORTPROTOCOL_ERROR;
    }
    
    /* First Byte of Packet is Always the Same */
    inst->command_buffer.data[SHORTPROTOCOL_BEGIN_OFFSET] = SHORTPROTOCOL_BEGIN;
    
    /* Second and third Byte is the Length of the Command */
    inst->command_buffer.data[SHORTPROTOCOL_LENGTH_LSB_OFFSET] = 
            (length & SHORTPROTOCOL_FIRST_BYTE_MASK);
    
    inst->command_buffer.data[SHORTPROTOCOL_LENGTH_MSB_OFFSET] = 
            ((length & SHORTPROTOCOL_SECOND_BYTE_MASK) 
            >> SHORTPROTOCOL_BYTE_LENGTH);
    
    /* The Command begins on the fourth byte */
    for(uint32_t i=0; i<length; i++){
        inst->command_buffer.data[i + SHORTPROTOCOL_COMMAND_OFFSET] = data[i];
    }
    
    /* Calculate the CRC of the Packet */
    uint32_t crc_temp;
    crc_temp = CRC_Calculate(inst->command_buffer.data,
            length + SHORTPROTOCOL_OVERHEAD_WITHOUT_CRC_BYTES);
    
    /* The last two Bytes are the CRC */
    inst->command_buffer.data[SHORTPROTOCOL_OVERHEAD_WITHOUT_CRC_BYTES +
                                    length + SHORTPROTOCOL_CRC_LSB_OFFSET] =
            crc_temp & SHORTPROTOCOL_FIRST_BYTE_MASK;
    
    inst->command_buffer.data[SHORTPROTOCOL_OVERHEAD_WITHOUT_CRC_BYTES +
                                    length + SHORTPROTOCOL_CRC_MSB_OFFSET] =
            (crc_temp & SHORTPROTOCOL_SECOND_BYTE_MASK) 
                    >> SHORTPROTOCOL_BYTE_LENGTH;
    
    /* Calculate the Length of the Full Packet */
    inst->command_buffer.length = length + SHORTPROTOCOL_OVERHEAD_BYTES;
            
    /* Tell the Update Function a Packet is ready */
    inst->writeCounter = 0;
    inst->newCommand = SHORTPROTOCOL_NOT_AVAILABLE;
    
    return SHORTPROTOCOL_SUCCESS;
}

void SHORTPROTOCOL_Update(SHORTPROTOCOL_Instance* inst){
    /* 
     * If a New Command is not available 
     * (therefore the current one is not completed)
     */
    if(inst->newCommand == SHORTPROTOCOL_NOT_AVAILABLE){
        /* Counter to control the length of this package being sent */
        uint32_t package_length = 0;
        while(package_length < inst->maximumPackageLength){
            
            inst->writeByte(inst->command_buffer.data[inst->writeCounter]);
            
            while(inst->writeAvailable() == SHORTPROTOCOL_NOT_AVAILABLE);
            
            if(inst->writeCounter == inst->command_buffer.length - 1){
                /* Command was completly written, a new Command is writable */
                inst->newCommand = SHORTPROTOCOL_AVAILABLE;
                break;
            }
            
            inst->writeCounter += 1;
            package_length += 1;
        }
    }
}

SHORTPROTOCOL_status SHORTPROTOCOL_Available(SHORTPROTOCOL_Instance* inst){
    return inst->newCommand;
}

void SHORTPROTOCOL_Initialize(SHORTPROTOCOL_Instance* inst){
    inst->writeCounter = 0;
    inst->newCommand = SHORTPROTOCOL_AVAILABLE;
}