/*******************************************************************************
  CANFD Peripheral Library Interface Source File

  Company:
    Microchip Technology Inc.

  File Name:
    plib_canfd3.c

  Summary:
    CANFD peripheral library interface.

  Description:
    This file defines the interface to the CANFD peripheral library. This
    library provides access to and control of the associated peripheral
    instance.

  Remarks:
    None.
*******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2019 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/
//DOM-IGNORE-END
// *****************************************************************************
// *****************************************************************************
// Header Includes
// *****************************************************************************
// *****************************************************************************
#include <sys/kmem.h>
#include "plib_canfd3.h"


// *****************************************************************************
// *****************************************************************************
// Global Data
// *****************************************************************************
// *****************************************************************************
/* CAN3 Message memory size */
#define CANFD_MESSAGE_RAM_CONFIG_SIZE 1236
/* Number of configured FIFO */
#define CANFD_NUM_OF_FIFO             2
/* Maximum number of CAN Message buffers in each FIFO */
#define CANFD_FIFO_MESSAGE_BUFFER_MAX 32

#define CANFD_CONFIGURATION_MODE      0x4
#define CANFD_OPERATION_MODE          0x6
#define CANFD_NUM_OF_FILTER           1
/* FIFO Offset in word (4 bytes) */
#define CANFD_FIFO_OFFSET             0xc
/* Filter Offset in word (4 bytes) */
#define CANFD_FILTER_OFFSET           0x4
#define CANFD_FILTER_OBJ_OFFSET       0x8
/* Acceptance Mask Offset in word (4 bytes) */
#define CANFD_ACCEPTANCE_MASK_OFFSET  0x8
#define CANFD_MSG_SID_MASK            0x7FF
#define CANFD_MSG_EID_MASK            0x1FFFFFFF
#define CANFD_MSG_DLC_MASK            0x0000000F
#define CANFD_MSG_IDE_MASK            0x00000010
#define CANFD_MSG_RTR_MASK            0x00000020
#define CANFD_MSG_BRS_MASK            0x00000040
#define CANFD_MSG_FDF_MASK            0x00000080
#define CANFD_MSG_SEQ_MASK            0xFFFFFE00
#define CANFD_MSG_TX_EXT_SID_MASK     0x1FFC0000
#define CANFD_MSG_TX_EXT_EID_MASK     0x0003FFFF
#define CANFD_MSG_RX_EXT_SID_MASK     0x000007FF
#define CANFD_MSG_RX_EXT_EID_MASK     0x1FFFF800
#define CANFD_MSG_FLT_EXT_SID_MASK    0x1FFC0000
#define CANFD_MSG_FLT_EXT_EID_MASK    0x0003FFFF

static uint8_t __attribute__((coherent, aligned(16))) can_message_buffer[CANFD_MESSAGE_RAM_CONFIG_SIZE];
static const uint8_t dlcToLength[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 12, 16, 20, 24, 32, 48, 64};


// *****************************************************************************
// *****************************************************************************
// CAN3 PLib Interface Routines
// *****************************************************************************
// *****************************************************************************
// *****************************************************************************
/* Function:
    void CAN3_Initialize(void)

   Summary:
    Initializes given instance of the CAN peripheral.

   Precondition:
    None.

   Parameters:
    None.

   Returns:
    None
*/
void CAN3_Initialize(void)
{
    /* Switch the CAN module ON */
    CFD3CON |= _CFD3CON_ON_MASK;

    /* Switch the CAN module to Configuration mode. Wait until the switch is complete */
    CFD3CON = (CFD3CON & ~_CFD3CON_REQOP_MASK) | ((CANFD_CONFIGURATION_MODE << _CFD3CON_REQOP_POSITION) & _CFD3CON_REQOP_MASK);
    while(((CFD3CON & _CFD3CON_OPMOD_MASK) >> _CFD3CON_OPMOD_POSITION) != CANFD_CONFIGURATION_MODE);

    /* Set the Nominal bitrate to 500 Kbps */
    CFD3NBTCFG = ((14 << _CFD3NBTCFG_BRP_POSITION) & _CFD3NBTCFG_BRP_MASK)
               | ((10 << _CFD3NBTCFG_TSEG1_POSITION) & _CFD3NBTCFG_TSEG1_MASK)
               | ((3 << _CFD3NBTCFG_TSEG2_POSITION) & _CFD3NBTCFG_TSEG2_MASK)
               | ((3 << _CFD3NBTCFG_SJW_POSITION) & _CFD3NBTCFG_SJW_MASK);

    /* Set Message memory base address for all FIFOs/Queue */
    CFD3FIFOBA = (uint32_t)KVA_TO_PA(can_message_buffer);

    /* Tx Event FIFO Configuration */
    CFD3TEFCON = (((1 - 1) << _CFD3TEFCON_FSIZE_POSITION) & _CFD3TEFCON_FSIZE_MASK) | _CFD3TEFCON_TEFTSEN_MASK;
    CFD3CON |= _CFD3CON_STEF_MASK;

    /* Tx Queue Configuration */
    CFD3TXQCON = (((1 - 1) << _CFD3TXQCON_FSIZE_POSITION) & _CFD3TXQCON_FSIZE_MASK)
               | ((0x7 << _CFD3TXQCON_PLSIZE_POSITION) & _CFD3TXQCON_PLSIZE_MASK)
               | ((0x0 << _CFD3TXQCON_TXPRI_POSITION) & _CFD3TXQCON_TXPRI_MASK);
    CFD3CON |= _CFD3CON_TXQEN_MASK;


    /* Configure CAN FIFOs */
    CFD3FIFOCON1 = (((32 - 1) << _CFD3FIFOCON1_FSIZE_POSITION) & _CFD3FIFOCON1_FSIZE_MASK) | _CFD3FIFOCON1_TXEN_MASK | ((0x0 << _CFD3FIFOCON1_TXPRI_POSITION) & _CFD3FIFOCON1_TXPRI_MASK) | ((0x0 << _CFD3FIFOCON1_RTREN_POSITION) & _CFD3FIFOCON1_RTREN_MASK) | ((0x0 << _CFD3FIFOCON1_PLSIZE_POSITION) & _CFD3FIFOCON1_PLSIZE_MASK);
    CFD3FIFOCON2 = (((32 - 1) << _CFD3FIFOCON2_FSIZE_POSITION) & _CFD3FIFOCON2_FSIZE_MASK) | _CFD3FIFOCON2_RXTSEN_MASK  | ((0x0 << _CFD3FIFOCON2_PLSIZE_POSITION) & _CFD3FIFOCON2_PLSIZE_MASK);

    /* Configure CAN Filters */
    /* Filter 0 configuration */
    CFD3FLTOBJ0 = (0 & CANFD_MSG_SID_MASK);
    CFD3MASK0 = (0 & CANFD_MSG_SID_MASK);
    CFD3FLTCON0 |= (((0x2 << _CFD3FLTCON0_F0BP_POSITION) & _CFD3FLTCON0_F0BP_MASK)| _CFD3FLTCON0_FLTEN0_MASK);

    /* Enable Timestamp */
    CFD3TSCON = (0 & _CFD3TSCON_TBCPRE_MASK)
                                | ((0x0 << _CFD3TSCON_TSEOF_POSITION) & _CFD3TSCON_TSEOF_MASK)

                                | _CFD3TSCON_TBCEN_MASK;

    /* Switch the CAN module to CANFD_OPERATION_MODE. Wait until the switch is complete */
    CFD3CON = (CFD3CON & ~_CFD3CON_REQOP_MASK) | ((CANFD_OPERATION_MODE << _CFD3CON_REQOP_POSITION) & _CFD3CON_REQOP_MASK);
    while(((CFD3CON & _CFD3CON_OPMOD_MASK) >> _CFD3CON_OPMOD_POSITION) != CANFD_OPERATION_MODE);
}

// *****************************************************************************
/* Function:
    bool CAN3_MessageTransmit(uint32_t id, uint8_t length, uint8_t* data, uint8_t fifoQueueNum, CANFD_MODE mode, CANFD_MSG_TX_ATTRIBUTE msgAttr)

   Summary:
    Transmits a message into CAN bus.

   Precondition:
    CAN3_Initialize must have been called for the associated CAN instance.

   Parameters:
    id           - 11-bit / 29-bit identifier (ID).
    length       - Length of data buffer in number of bytes.
    data         - Pointer to source data buffer
    fifoQueueNum - If fifoQueueNum is 0 then Transmit Queue otherwise FIFO
    mode         - CAN mode Classic CAN or CAN FD without BRS or CAN FD with BRS
    msgAttr      - Data frame or Remote frame to be transmitted

   Returns:
    Request status.
    true  - Request was successful.
    false - Request has failed.
*/
bool CAN3_MessageTransmit(uint32_t id, uint8_t length, uint8_t* data, uint8_t fifoQueueNum, CANFD_MODE mode, CANFD_MSG_TX_ATTRIBUTE msgAttr)
{
    CANFD_TX_MSG_OBJECT *txMessage = NULL;
    static uint32_t sequence = 0;
    uint8_t count = 0;
    bool status = false;

    if (fifoQueueNum == 0)
    {
        if ((CFD3TXQSTA & _CFD3TXQSTA_TXQNIF_MASK) == _CFD3TXQSTA_TXQNIF_MASK)
        {
            txMessage = (CANFD_TX_MSG_OBJECT *)PA_TO_KVA1(CFD3TXQUA);
            status = true;
        }
    }
    else if (fifoQueueNum <= CANFD_NUM_OF_FIFO)
    {
        if ((*(volatile uint32_t *)(&CFD3FIFOSTA1 + ((fifoQueueNum - 1) * CANFD_FIFO_OFFSET)) & _CFD3FIFOSTA1_TFNRFNIF_MASK) == _CFD3FIFOSTA1_TFNRFNIF_MASK)
        {
            txMessage = (CANFD_TX_MSG_OBJECT *)PA_TO_KVA1(*(volatile uint32_t *)(&CFD3FIFOUA1 + ((fifoQueueNum - 1) * CANFD_FIFO_OFFSET)));
            status = true;
        }
    }

    if (status)
    {
        /* Check the id whether it falls under SID or EID,
         * SID max limit is 0x7FF, so anything beyond that is EID */
        if (id > CANFD_MSG_SID_MASK)
        {
            txMessage->t0 = (((id & CANFD_MSG_TX_EXT_SID_MASK) >> 18) | ((id & CANFD_MSG_TX_EXT_EID_MASK) << 11)) & CANFD_MSG_EID_MASK;
            txMessage->t1 = CANFD_MSG_IDE_MASK;
        }
        else
        {
            txMessage->t0 = id;
            txMessage->t1 = 0;
        }
        /* Limit length */
        if (length > 8)
            length = 8;
        txMessage->t1 |= length;
        if (msgAttr == CANFD_MSG_TX_REMOTE_FRAME)
        {
            txMessage->t1 |= CANFD_MSG_RTR_MASK;
        }
        else
        {
            while(count < length)
            {
                txMessage->data[count++] = *data++;
            }
        }

        txMessage->t1 |= ((++sequence << 9) & CANFD_MSG_SEQ_MASK);

        if (fifoQueueNum == 0)
        {
            /* Request the transmit */
            CFD3TXQCON |= _CFD3TXQCON_UINC_MASK;
            CFD3TXQCON |= _CFD3TXQCON_TXREQ_MASK;
        }
        else
        {
            /* Request the transmit */
            *(volatile uint32_t *)(&CFD3FIFOCON1 + ((fifoQueueNum - 1) * CANFD_FIFO_OFFSET)) |= _CFD3FIFOCON1_UINC_MASK;
            *(volatile uint32_t *)(&CFD3FIFOCON1 + ((fifoQueueNum - 1) * CANFD_FIFO_OFFSET)) |= _CFD3FIFOCON1_TXREQ_MASK;
        }
    }
    return status;
}

// *****************************************************************************
/* Function:
    bool CAN3_MessageReceive(uint32_t *id, uint8_t *length, uint8_t *data, uint32_t *timestamp, uint8_t fifoNum, CANFD_MSG_RX_ATTRIBUTE *msgAttr)

   Summary:
    Receives a message from CAN bus.

   Precondition:
    CAN3_Initialize must have been called for the associated CAN instance.

   Parameters:
    id          - Pointer to 11-bit / 29-bit identifier (ID) to be received.
    length      - Pointer to data length in number of bytes to be received.
    data        - Pointer to destination data buffer
    timestamp   - Pointer to Rx message timestamp, timestamp value is 0 if Timestamp is disabled in CFD3TSCON
    fifoNum     - FIFO number
    msgAttr     - Data frame or Remote frame to be received

   Returns:
    Request status.
    true  - Request was successful.
    false - Request has failed.
*/
bool CAN3_MessageReceive(uint32_t *id, uint8_t *length, uint8_t *data, uint32_t *timestamp, uint8_t fifoNum, CANFD_MSG_RX_ATTRIBUTE *msgAttr)
{
    CANFD_RX_MSG_OBJECT *rxMessage = NULL;
    uint8_t count = 0;
    uint8_t dataIndex = 4;
    bool status = false;

    if ((fifoNum > CANFD_NUM_OF_FIFO) || (id == NULL))
    {
        return status;
    }

    /* Check if there is a message available in FIFO */
    if ((*(volatile uint32_t *)(&CFD3FIFOSTA1 + ((fifoNum - 1) * CANFD_FIFO_OFFSET)) & _CFD3FIFOSTA1_TFNRFNIF_MASK) == _CFD3FIFOSTA1_TFNRFNIF_MASK)
    {
        /* Get a pointer to RX message buffer */
        rxMessage = (CANFD_RX_MSG_OBJECT *)PA_TO_KVA1(*(volatile uint32_t *)(&CFD3FIFOUA1 + ((fifoNum - 1) * CANFD_FIFO_OFFSET)));

        /* Check if it's a extended message type */
        if (rxMessage->r1 & CANFD_MSG_IDE_MASK)
        {
            *id = (((rxMessage->r0 & CANFD_MSG_RX_EXT_SID_MASK) << 18) | ((rxMessage->r0 & CANFD_MSG_RX_EXT_EID_MASK) >> 11)) & CANFD_MSG_EID_MASK;
        }
        else
        {
            *id = rxMessage->r0 & CANFD_MSG_SID_MASK;
        }

        if ((rxMessage->r1 & CANFD_MSG_RTR_MASK) && ((rxMessage->r1 & CANFD_MSG_FDF_MASK) == 0))
        {
            *msgAttr = CANFD_MSG_RX_REMOTE_FRAME;
        }
        else
        {
            *msgAttr = CANFD_MSG_RX_DATA_FRAME;
        }

        *length = dlcToLength[(rxMessage->r1 & CANFD_MSG_DLC_MASK)];

        if (timestamp != NULL)
        {
            *timestamp =  (rxMessage->data[3] << 24) | (rxMessage->data[2] << 16) | (rxMessage->data[1] << 8) | rxMessage->data[0];
        }

        /* Copy the data into the payload */
        while (count < *length)
        {
            *data++ = rxMessage->data[dataIndex + count++];
        }

        /* Message processing is done, update the message buffer pointer. */
        *(volatile uint32_t *)(&CFD3FIFOCON1 + ((fifoNum - 1) * CANFD_FIFO_OFFSET)) |= _CFD3FIFOCON1_UINC_MASK;

        /* Message is processed successfully, so return true */
        status = true;
    }

    return status;
}

// *****************************************************************************
/* Function:
    void CAN3_MessageAbort(uint8_t fifoQueueNum)

   Summary:
    Abort request for a Queue/FIFO.

   Precondition:
    CAN3_Initialize must have been called for the associated CAN instance.

   Parameters:
    fifoQueueNum - If fifoQueueNum is 0 then Transmit Queue otherwise FIFO

   Returns:
    None.
*/
void CAN3_MessageAbort(uint8_t fifoQueueNum)
{
    if (fifoQueueNum == 0)
    {
        CFD3TXQCON &= ~_CFD3TXQCON_TXREQ_MASK;
    }
    else if (fifoQueueNum <= CANFD_NUM_OF_FIFO)
    {
        *(volatile uint32_t *)(&CFD3FIFOCON1 + ((fifoQueueNum - 1) * CANFD_FIFO_OFFSET)) &= ~_CFD3FIFOCON1_TXREQ_MASK;
    }
}

// *****************************************************************************
/* Function:
    void CAN3_MessageAcceptanceFilterSet(uint8_t filterNum, uint32_t id)

   Summary:
    Set Message acceptance filter configuration.

   Precondition:
    CAN3_Initialize must have been called for the associated CAN instance.

   Parameters:
    filterNum - Filter number
    id        - 11-bit or 29-bit identifier

   Returns:
    None.
*/
void CAN3_MessageAcceptanceFilterSet(uint8_t filterNum, uint32_t id)
{
    uint32_t filterEnableBit = 0;
    uint8_t filterRegIndex = 0;

    if (filterNum < CANFD_NUM_OF_FILTER)
    {
        filterRegIndex = filterNum >> 2;
        filterEnableBit = (filterNum % 4 == 0)? _CFD3FLTCON0_FLTEN0_MASK : 1 << ((((filterNum % 4) + 1) * 8) - 1);

        *(volatile uint32_t *)(&CFD3FLTCON0 + (filterRegIndex * CANFD_FILTER_OFFSET)) &= ~filterEnableBit;

        if (id > CANFD_MSG_SID_MASK)
        {
            *(volatile uint32_t *)(&CFD3FLTOBJ0 + (filterNum * CANFD_FILTER_OBJ_OFFSET)) = ((((id & CANFD_MSG_FLT_EXT_SID_MASK) >> 18) | ((id & CANFD_MSG_FLT_EXT_EID_MASK) << 11)) & CANFD_MSG_EID_MASK) | _CFD3FLTOBJ0_EXIDE_MASK;
        }
        else
        {
            *(volatile uint32_t *)(&CFD3FLTOBJ0 + (filterNum * CANFD_FILTER_OBJ_OFFSET)) = id & CANFD_MSG_SID_MASK;
        }
        *(volatile uint32_t *)(&CFD3FLTCON0 + (filterRegIndex * CANFD_FILTER_OFFSET)) |= filterEnableBit;
    }
}

// *****************************************************************************
/* Function:
    uint32_t CAN3_MessageAcceptanceFilterGet(uint8_t filterNum)

   Summary:
    Get Message acceptance filter configuration.

   Precondition:
    CAN3_Initialize must have been called for the associated CAN instance.

   Parameters:
    filterNum - Filter number

   Returns:
    Returns Message acceptance filter identifier
*/
uint32_t CAN3_MessageAcceptanceFilterGet(uint8_t filterNum)
{
    uint32_t id = 0;

    if (filterNum < CANFD_NUM_OF_FILTER)
    {
        if (*(volatile uint32_t *)(&CFD3FLTOBJ0 + (filterNum * CANFD_FILTER_OBJ_OFFSET)) & _CFD3FLTOBJ0_EXIDE_MASK)
        {
            id = (((*(volatile uint32_t *)(&CFD3FLTOBJ0 + (filterNum * CANFD_FILTER_OBJ_OFFSET)) & CANFD_MSG_RX_EXT_SID_MASK) << 18)
               | ((*(volatile uint32_t *)(&CFD3FLTOBJ0 + (filterNum * CANFD_FILTER_OBJ_OFFSET)) & CANFD_MSG_RX_EXT_EID_MASK) >> 11))
               & CANFD_MSG_EID_MASK;
        }
        else
        {
            id = (*(volatile uint32_t *)(&CFD3FLTOBJ0 + (filterNum * CANFD_FILTER_OBJ_OFFSET)) & CANFD_MSG_SID_MASK);
        }
    }
    return id;
}

// *****************************************************************************
/* Function:
    void CAN3_MessageAcceptanceFilterMaskSet(uint8_t acceptanceFilterMaskNum, uint32_t id)

   Summary:
    Set Message acceptance filter mask configuration.

   Precondition:
    CAN3_Initialize must have been called for the associated CAN instance.

   Parameters:
    acceptanceFilterMaskNum - Acceptance Filter Mask number
    id                      - 11-bit or 29-bit identifier

   Returns:
    None.
*/
void CAN3_MessageAcceptanceFilterMaskSet(uint8_t acceptanceFilterMaskNum, uint32_t id)
{
    /* Switch the CAN module to Configuration mode. Wait until the switch is complete */
    CFD3CON = (CFD3CON & ~_CFD3CON_REQOP_MASK) | ((CANFD_CONFIGURATION_MODE << _CFD3CON_REQOP_POSITION) & _CFD3CON_REQOP_MASK);
    while(((CFD3CON & _CFD3CON_OPMOD_MASK) >> _CFD3CON_OPMOD_POSITION) != CANFD_CONFIGURATION_MODE);

    if (id > CANFD_MSG_SID_MASK)
    {
        *(volatile uint32_t *)(&CFD3MASK0 + (acceptanceFilterMaskNum * CANFD_ACCEPTANCE_MASK_OFFSET)) = ((((id & CANFD_MSG_FLT_EXT_SID_MASK) >> 18) | ((id & CANFD_MSG_FLT_EXT_EID_MASK) << 11)) & CANFD_MSG_EID_MASK) | _CFD3MASK0_MIDE_MASK;
    }
    else
    {
        *(volatile uint32_t *)(&CFD3MASK0 + (acceptanceFilterMaskNum * CANFD_ACCEPTANCE_MASK_OFFSET)) = id & CANFD_MSG_SID_MASK;
    }

    /* Switch the CAN module to CANFD_OPERATION_MODE. Wait until the switch is complete */
    CFD3CON = (CFD3CON & ~_CFD3CON_REQOP_MASK) | ((CANFD_OPERATION_MODE << _CFD3CON_REQOP_POSITION) & _CFD3CON_REQOP_MASK);
    while(((CFD3CON & _CFD3CON_OPMOD_MASK) >> _CFD3CON_OPMOD_POSITION) != CANFD_OPERATION_MODE);
}

// *****************************************************************************
/* Function:
    uint32_t CAN3_MessageAcceptanceFilterMaskGet(uint8_t acceptanceFilterMaskNum)

   Summary:
    Get Message acceptance filter mask configuration.

   Precondition:
    CAN3_Initialize must have been called for the associated CAN instance.

   Parameters:
    acceptanceFilterMaskNum - Acceptance Filter Mask number

   Returns:
    Returns Message acceptance filter mask.
*/
uint32_t CAN3_MessageAcceptanceFilterMaskGet(uint8_t acceptanceFilterMaskNum)
{
    uint32_t id = 0;

    if (*(volatile uint32_t *)(&CFD3MASK0 + (acceptanceFilterMaskNum * CANFD_ACCEPTANCE_MASK_OFFSET)) & _CFD3MASK0_MIDE_MASK)
    {
        id = (((*(volatile uint32_t *)(&CFD3MASK0 + (acceptanceFilterMaskNum * CANFD_ACCEPTANCE_MASK_OFFSET)) & CANFD_MSG_RX_EXT_SID_MASK) << 18)
           | ((*(volatile uint32_t *)(&CFD3MASK0 + (acceptanceFilterMaskNum * CANFD_ACCEPTANCE_MASK_OFFSET)) & CANFD_MSG_RX_EXT_EID_MASK) >> 11))
           & CANFD_MSG_EID_MASK;
    }
    else
    {
        id = (*(volatile uint32_t *)(&CFD3MASK0 + (acceptanceFilterMaskNum * CANFD_ACCEPTANCE_MASK_OFFSET)) & CANFD_MSG_SID_MASK);
    }
    return id;
}

// *****************************************************************************
/* Function:
    bool CAN3_TransmitEventFIFOElementGet(uint32_t *id, uint32_t *sequence, uint32_t *timestamp)

   Summary:
    Get the Transmit Event FIFO Element for the transmitted message.

   Precondition:
    CAN3_Initialize must have been called for the associated CAN instance.

   Parameters:
    id          - Pointer to 11-bit / 29-bit identifier (ID) to be received.
    sequence    - Pointer to Tx message sequence number to be received
    timestamp   - Pointer to Tx message timestamp to be received, timestamp value is 0 if Timestamp is disabled in CFD3TSCON

   Returns:
    Request status.
    true  - Request was successful.
    false - Request has failed.
*/
bool CAN3_TransmitEventFIFOElementGet(uint32_t *id, uint32_t *sequence, uint32_t *timestamp)
{
    CANFD_TX_EVENT_FIFO_ELEMENT *txEventFIFOElement = NULL;
    bool status = false;

    /* Check if there is a message available in Tx Event FIFO */
    if ((CFD3TEFSTA & _CFD3TEFSTA_TEFNEIF_MASK) == _CFD3TEFSTA_TEFNEIF_MASK)
    {
        /* Get a pointer to Tx Event FIFO Element */
        txEventFIFOElement = (CANFD_TX_EVENT_FIFO_ELEMENT *)PA_TO_KVA1(CFD3TEFUA);

        /* Check if it's a extended message type */
        if (txEventFIFOElement->te1 & CANFD_MSG_IDE_MASK)
        {
            *id = txEventFIFOElement->te0 & CANFD_MSG_EID_MASK;
        }
        else
        {
            *id = txEventFIFOElement->te0 & CANFD_MSG_SID_MASK;
        }

        *sequence = ((txEventFIFOElement->te1 & CANFD_MSG_SEQ_MASK) >> 9);

        if (timestamp != NULL)
        {
            *timestamp =  (txEventFIFOElement->timestamp[3] << 24) | (txEventFIFOElement->timestamp[2] << 16) | (txEventFIFOElement->timestamp[1] << 8) | txEventFIFOElement->timestamp[0];
        }

        /* Tx Event FIFO Element read done, update the Tx Event FIFO tail */
        CFD3TEFCON |= _CFD3TEFCON_UINC_MASK;

        /* Tx Event FIFO Element read successfully, so return true */
        status = true;
    }
    return status;
}

// *****************************************************************************
/* Function:
    CANFD_ERROR CAN3_ErrorGet(void)

   Summary:
    Returns the error during transfer.

   Precondition:
    CAN3_Initialize must have been called for the associated CAN instance.

   Parameters:
    None.

   Returns:
    Error during transfer.
*/
CANFD_ERROR CAN3_ErrorGet(void)
{
    CANFD_ERROR error = CANFD_ERROR_NONE;
    uint32_t errorStatus = CFD3TREC;

    /* Check if error occurred */
    error = (CANFD_ERROR)((errorStatus & _CFD3TREC_EWARN_MASK) |
                        (errorStatus & _CFD3TREC_RXWARN_MASK) |
                        (errorStatus & _CFD3TREC_TXWARN_MASK) |
                        (errorStatus & _CFD3TREC_RXBP_MASK) |
                        (errorStatus & _CFD3TREC_TXBP_MASK) |
                        (errorStatus & _CFD3TREC_TXBO_MASK));

    return error;
}

// *****************************************************************************
/* Function:
    void CAN3_ErrorCountGet(uint8_t *txErrorCount, uint8_t *rxErrorCount)

   Summary:
    Returns the transmit and receive error count during transfer.

   Precondition:
    CAN3_Initialize must have been called for the associated CAN instance.

   Parameters:
    txErrorCount - Transmit Error Count to be received
    rxErrorCount - Receive Error Count to be received

   Returns:
    None.
*/
void CAN3_ErrorCountGet(uint8_t *txErrorCount, uint8_t *rxErrorCount)
{
    *txErrorCount = (uint8_t)((CFD3TREC & _CFD3TREC_TERRCNT_MASK) >> _CFD3TREC_TERRCNT_POSITION);
    *rxErrorCount = (uint8_t)(CFD3TREC & _CFD3TREC_RERRCNT_MASK);
}

// *****************************************************************************
/* Function:
    bool CAN3_InterruptGet(uint8_t fifoQueueNum, CANFD_FIFO_INTERRUPT_FLAG_MASK fifoInterruptFlagMask)

   Summary:
    Returns the FIFO Interrupt status.

   Precondition:
    CAN3_Initialize must have been called for the associated CAN instance.

   Parameters:
    fifoQueueNum          - FIFO number
    fifoInterruptFlagMask - FIFO interrupt flag mask

   Returns:
    true - Requested fifo interrupt is occurred.
    false - Requested fifo interrupt is not occurred.
*/
bool CAN3_InterruptGet(uint8_t fifoQueueNum, CANFD_FIFO_INTERRUPT_FLAG_MASK fifoInterruptFlagMask)
{
    if (fifoQueueNum == 0)
    {
        return ((CFD3TXQSTA & fifoInterruptFlagMask) != 0x0);
    }
    else
    {
        return ((*(volatile uint32_t *)(&CFD3FIFOSTA1 + ((fifoQueueNum - 1) * CANFD_FIFO_OFFSET)) & fifoInterruptFlagMask) != 0x0);
    }
}

// *****************************************************************************
/* Function:
    bool CAN3_TxFIFOQueueIsFull(uint8_t fifoQueueNum)

   Summary:
    Returns true if Tx FIFO/Queue is full otherwise false.

   Precondition:
    CAN3_Initialize must have been called for the associated CAN instance.

   Parameters:
    fifoQueueNum - FIFO/Queue number

   Returns:
    true  - Tx FIFO/Queue is full.
    false - Tx FIFO/Queue is not full.
*/
bool CAN3_TxFIFOQueueIsFull(uint8_t fifoQueueNum)
{
    if (fifoQueueNum == 0)
    {
        return ((CFD3TXQSTA & _CFD3TXQSTA_TXQNIF_MASK) != _CFD3TXQSTA_TXQNIF_MASK);
    }
    else
    {
        return ((*(volatile uint32_t *)(&CFD3FIFOSTA1 + ((fifoQueueNum - 1) * CANFD_FIFO_OFFSET)) & _CFD3FIFOSTA1_TFNRFNIF_MASK) != _CFD3FIFOSTA1_TFNRFNIF_MASK);
    }
}

// *****************************************************************************
/* Function:
    bool CAN3_AutoRTRResponseSet(uint32_t id, uint8_t length, uint8_t* data, uint8_t fifoNum)

   Summary:
    Set the Auto RTR response for remote transmit request.

   Precondition:
    CAN3_Initialize must have been called for the associated CAN instance.
    Auto RTR Enable must be set to 0x1 for the requested Transmit FIFO in MHC configuration.

   Parameters:
    id           - 11-bit / 29-bit identifier (ID).
    length       - Length of data buffer in number of bytes.
    data         - Pointer to source data buffer
    fifoNum      - FIFO Number

   Returns:
    Request status.
    true  - Request was successful.
    false - Request has failed.
*/
bool CAN3_AutoRTRResponseSet(uint32_t id, uint8_t length, uint8_t* data, uint8_t fifoNum)
{
    CANFD_TX_MSG_OBJECT *txMessage = NULL;
    uint8_t count = 0;
    bool status = false;

    if (fifoNum <= CANFD_NUM_OF_FIFO)
    {
        if ((*(volatile uint32_t *)(&CFD3FIFOSTA1 + ((fifoNum - 1) * CANFD_FIFO_OFFSET)) & _CFD3FIFOSTA1_TFNRFNIF_MASK) == _CFD3FIFOSTA1_TFNRFNIF_MASK)
        {
            txMessage = (CANFD_TX_MSG_OBJECT *)PA_TO_KVA1(*(volatile uint32_t *)(&CFD3FIFOUA1 + ((fifoNum - 1) * CANFD_FIFO_OFFSET)));
            status = true;
        }
    }

    if (status)
    {
        /* Check the id whether it falls under SID or EID,
         * SID max limit is 0x7FF, so anything beyond that is EID */
        if (id > CANFD_MSG_SID_MASK)
        {
            txMessage->t0 = (((id & CANFD_MSG_TX_EXT_SID_MASK) >> 18) | ((id & CANFD_MSG_TX_EXT_EID_MASK) << 11)) & CANFD_MSG_EID_MASK;
            txMessage->t1 = CANFD_MSG_IDE_MASK;
        }
        else
        {
            txMessage->t0 = id;
            txMessage->t1 = 0;
        }

        /* Limit length */
        if (length > 8)
            length = 8;
        txMessage->t1 |= length;

        while(count < length)
        {
            txMessage->data[count++] = *data++;
        }

        /* Set UINC to respond to RTR */
        *(volatile uint32_t *)(&CFD3FIFOCON1 + ((fifoNum - 1) * CANFD_FIFO_OFFSET)) |= _CFD3FIFOCON1_UINC_MASK;
    }
    return status;
}

