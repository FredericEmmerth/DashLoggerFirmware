#include "shortprotocol.h"

SHORTPROTOCOL_status SHORTPROTOCOL_Send(SHORTPROTOCOL_Instance* inst,
        uint8_t* data, uint32_t length){
    /* If the last Command is not yet send, cant accept a new one */
    if(inst->newCommand == SHORTPROTOCOL_NOT_AVAILABLE){
        return SHORTPROTOCOL_NOT_AVAILABLE;
    }
    
    /* Check that the Command will fit in the Buffer */
    if(length > SHORTPROTOCOL_MAXIMUM_COMMAND_LENGTH){
        length = SHORTPROTOCOL_MAXIMUM_COMMAND_LENGTH;
    }
    
    /* Check that it is not zero length */
    if(length == 0){
        return SHORTPROTOCOL_ERROR;
    }
    
    /* Copy the Command and the length of the Command */
    inst->command_buffer.length = length;
    for(uint32_t i=0; i<length; i++){
        inst->command_buffer.data[i] = data[i];
    }
    /* Tell the Update Function a Command is ready */
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
            
            if(inst->writeCounter == inst->command_buffer.length){
                /* Command was completly written, a new Command is writable */
                inst->newCommand = SHORTPROTOCOL_AVAILABLE;
                break;
            }
            
            inst->writeCounter += 1;
            package_length += 1;
        }
    }
}

void SHORTPROTOCOL_Initialize(SHORTPROTOCOL_Instance* inst){
    inst->writeCounter = 0;
    inst->newCommand = SHORTPROTOCOL_AVAILABLE;
}