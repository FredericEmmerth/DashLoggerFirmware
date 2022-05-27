/**
 * @file signals.h
 * @brief This File defines the Prototypes for \ref SIGNALS
 * 
 * @author Frederic Emmerth
 * 
 * \ingroup SIGNALS
 * 
 */



/**
 * \defgroup SIGNALS SIGNALS
 * This Module Handles the Information Interpretation Handling of All Inputs
 * to Outputs. Signals have a Type, wich changes how it is interpreted and used.
 * For more on this, refer to \ref signals_data_type and
 * \ref signals_signal_type. Signals can be chained together. For Example, four 
 * Signals of Type SIGNALS_CAN_MESSAGE could recieve four Temperatures, wich
 * would then be interpreted to float Values using thier respective Callback
 * Functions. Another Signal of Type SIGNALS_INTERNAL_SIGNAL could then find the
 * highest of these Temperatures using its Callback Function. To complete the
 * Chain, a Signal of Type SIGNALS_DISPLAY_SIGNAL can be used to convert the 
 * float value of the previous Maximising Function to a String Command wich can
 * be interpreted by a Display.
 * \addtogroup SIGNALS
 * \{
 */

#ifndef SIGNALS_H
#define	SIGNALS_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include "definitions.h"
#include "cancomm.h"
    
/**
 * @brief The maximum friendly name length for a signal
 */
#define SIGNALS_MAXIMUM_NAME_LENGTH     30
    
/**
 * @brief The maximum length of the string value of a signal
 */
#define SIGNALS_STRING_MAXIMUM_LENGTH   50
   
/**
 * @brief Definition of the Return Values of some Functions of this Module
 */
typedef enum{
    /**
     * Returned if a Signal is found
     */
    SIGNALS_FOUND = 0,
            
    /**
     * Returned if no Signal is found
     */
    SIGNALS_NOT_FOUND,
            
    /**
     * Returned if the Inputs match
     */
    SIGNALS_MATCH,
            
    /**
     * Returned if the Inputs dont match
     */
    SIGNALS_NO_MATCH
}signals_result;


/**
 * @brief The Data type of a Signal
 */
typedef enum{
    SIGNALS_FLOAT_SIGNAL = 0,
    SIGNALS_UINT32_T_SIGNAL,
    SIGNALS_STRING_SIGNAL
}signals_data_type;

/**
 * @brief The Signal type of a Signal
 */
typedef enum{
    SIGNALS_CAN_MESSAGE = 0,
    SIGNALS_INTERNAL_SIGNAL,
    SIGNALS_DISPLAY_SIGNAL
}signals_signal_type;

/**
 * \brief A struct to combine a String with it's length
 */
typedef struct{
    uint32_t length;
    uint8_t data[SIGNALS_STRING_MAXIMUM_LENGTH];
}SIGNALS_string;

/**
 * Type Definition of signals_signal_struct to be able to use
 * signals_signal in the definition of signals_signal, as signal structs have
 * to store pointers to other signals_signal structs.
 */
typedef struct signals_signal_struct signals_signal;
     
/**
 * \struct signals_signal_struct
 * 
 * This Struct defines a Signal. Every Signal should have a friendly Name, to be
 * easily identified by a human. Every Signal has to have a
 * \ref signals_signal.type and a \ref signals_signal.data_type. Depending on
 * the \ref signals_signal.type and \ref signals_signal.data_type other
 * members of the struct have to be defined. If a signal is of type
 * SIGNALS_CAN_MESSAGE, the id and the interface_number have to be defined.
 * The Signal can be either of data_type SIGNALS_FLOAT_SIGNAL, 
 * SIGNALS_UINT32_T_SIGNAL or SIGNALS_STRING_SIGNAL. The corresponding callback
 * function can_convert_float, can_convert_uint32_t or can_convert_string has
 * to be defined.
 * 
 * If a signal is of type SIGNALS_INTERNAL_SIGNAL, it can be of data_type 
 * SIGNALS_FLOAT_SIGNAL, SIGNALS_UINT32_T_SIGNAL or SIGNALS_STRING_SIGNAL. The
 * corresponding callback function internal_convert_float,
 * internal_convert_uint32_t or internal_convert_string has to be defined.
 * 
 * If a signal is of type SIGNALS_DISPLAY_SIGNAL, it's data_type has to be 
 * SIGNALS_STRING_SIGNAL, and its callback function internal_convert_string
 * has to be defined in a way to produce correct Commands for the Display to 
 * be interpreted. Signals of this Type are read by \ref COMMAND to be sent of
 * to the Display using the \ref SHORTPROTOCOL.
 * 
 */
struct signals_signal_struct{
    uint32_t id;
    uint8_t interface_number;
    signals_data_type data_type;
    
    float(*can_convert_float)(uint8_t* data);
    float(*internal_convert_float)(signals_signal* signal_list,
            uint32_t signal_list_len);
    float value_float;
    
    uint32_t(*can_convert_uint32_t)(uint8_t* data);
    uint32_t(*internal_convert_uint32_t)(signals_signal* signal_list,
            uint32_t signal_list_len);
    uint32_t value_uint32_t;
    
    void (*can_convert_string)(uint8_t* data, SIGNALS_string* string);
    void (*internal_convert_string)(signals_signal* signal_list,
            uint32_t signal_list_len, SIGNALS_string* string);
    SIGNALS_string value_string;
    
    uint8_t friendly_name[SIGNALS_MAXIMUM_NAME_LENGTH];
    uint32_t timestamp;
    signals_signal_type type;
    
    uint32_t object_id;
};

void SIGNALS_Interpret(signals_signal* signal_list, uint32_t signal_list_len,
        cancomm_message* message_list, uint32_t message_list_len);

signals_result signals_find_data(uint32_t id, uint8_t interface,
        cancomm_message* message_list, uint32_t message_list_len,
        uint8_t* data);

signals_signal* signals_find_signal( signals_signal* signal_list,
        uint32_t signal_list_len, void(*Callback)(void));

signals_result signals_compare_names(uint8_t* first, uint32_t firstlen,
        uint8_t* second, uint32_t secondlen);

signals_signal* signals_find_display_signal(signals_signal* signal_list,
        uint32_t signal_list_len, uint32_t* dispSignalCount, uint32_t needle);

#ifdef	__cplusplus
}
#endif

#endif	/* SIGNALS_H */

/**
 * \}
 */

