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
 * A Signal is therefore defined by its type and data_type.
 * 
 * @todo Combine the Different Signal Types to a Union to use less RAM
 * 
 */
struct signals_signal_struct{
    /** The ID of the CAN Message */
    uint32_t id;
    
    /** The CAN Interface Number (unique Identifier for a CAN Interface)*/
    uint8_t interface_number;
    
    /** Type of the Signal */
    signals_signal_type type;
    
    /** Data Type of the Signal */
    signals_data_type data_type;
    
    /** Callback Function for type=SIGNALS_CAN_MESSAGE and 
     * data_type=SIGNALS_FLOAT_SIGNAL */
    float(*can_convert_float)(uint8_t* data);
    
    /** Callback Function for type=SIGNALS_INTERNAL_SIGNAL and 
     * data_type=SIGNALS_FLOAT_SIGNAL */
    float(*internal_convert_float)(signals_signal* signal_list,
            uint32_t signal_list_len);
    
    /** The Float Value of this Signal, only used when 
     * data_type=SIGNALS_FLOAT_SIGNAL*/
    float value_float;
    
    /** Callback Function for type=SIGNALS_CAN_MESSAGE and 
     * data_type=SIGNALS_UINT32_T_SIGNAL*/
    uint32_t(*can_convert_uint32_t)(uint8_t* data);
    
    /** Callback Function for type=SIGNALS_INTERNAL_SIGNAL and 
     * data_type=SIGNALS_UINT32_T_SIGNAL*/
    uint32_t(*internal_convert_uint32_t)(signals_signal* signal_list,
            uint32_t signal_list_len);
    
    /** The uint32_t Value of this Signal, only used when 
     * data_type=SIGNALS_UINT32_T_SIGNAL*/
    uint32_t value_uint32_t;
    
    /** Callback Function for type=SIGNALS_CAN_MESSAGE and 
     * data_type=SIGNALS_STRING_SIGNAL*/
    void (*can_convert_string)(uint8_t* data, SIGNALS_string* string);
    
    /** Callback Function for type=SIGNALS_INTERNAL_SIGNAL or 
     * type=SIGNALS_DISPLAY_SIGNAL. and data_type SIGNALS_STRING_SIGNAL*/
    void (*internal_convert_string)(signals_signal* signal_list,
            uint32_t signal_list_len, SIGNALS_string* string);
    
    /** The String Value of this Signal, only used when 
     * data_type=SIGNALS_STRING_SIGNAL*/
    SIGNALS_string value_string;
    
    /** A friendly Name of the Signal, only used for Debugging */
    uint8_t friendly_name[SIGNALS_MAXIMUM_NAME_LENGTH];
    
    /** The Timestamp of the Signal */
    uint32_t timestamp;
};

/**
 * This Function takes a signal_list and a message_list and interprets each
 * Signal either from other Signals or from a CAN message. The Callback 
 * Functions defined in each Signal are called here.
 * 
 * @param signal_list A List of \ref signals_signal Structs
 * @param signal_list_len The Length of \p signal_list
 * @param message_list A List of \ref cancomm_message Structs
 * @param message_list_len The Length of \p signal_list
 */
void SIGNALS_Interpret(signals_signal* signal_list, uint32_t signal_list_len,
        cancomm_message* message_list, uint32_t message_list_len);

/**
 * This function finds the data from a CAN Message and writes it to the Buffer 
 * \p data
 * 
 * @param id The CAN Message ID
 * @param interface The CAN Interface (wich uniquely identifies a CAN Interface)
 * @param message_list List of \ref cancomm_message Structs with the data in it
 * @param message_list_len The Length of \p message_list
 * @param data The Buffer the Data of the requested Message gets written to
 * @return A \ref signals_result. Returns SIGNALS_FOUND if the Data of the
 * Message was found, and SIGNALS_NOT_FOUND if the Message is not in the List.
 */
signals_result signals_find_data(uint32_t id, uint8_t interface,
        cancomm_message* message_list, uint32_t message_list_len,
        uint8_t* data);

/**
 * This function finds a singnal from signal_list by its Callback. This is 
 * needed for the Conversion Functions of Internal Signals, as they need to 
 * read other Signal Values in thier Conversion Function.
 * 
 * @param signal_list List of \ref signals_signal to be searched in
 * @param signal_list_len The Length of \p signal_list
 * @param Callback The Callback Function of the searched signal
 * @return Pointer to the Signal if it is found, else NULL is returned
 */
signals_signal* signals_find_signal( signals_signal* signal_list,
        uint32_t signal_list_len, void(*Callback)(void));

/**
 * Function to compare two Signals Names.
 * @param first First Name
 * @param firstlen Length of \p first
 * @param second Second Name
 * @param secondlen Length of \p second
 * @return SIGNALS_MATCH if the Names match, and SIGNALS_NO_MATCH if they dont
 */
signals_result signals_compare_names(uint8_t* first, uint32_t firstlen,
        uint8_t* second, uint32_t secondlen);

/**
 * Function to return the first, second, third ... display Signal. If needle is
 * for example five, the fifth display Signal is returned. Also, the total Count
 * of Display Signals is written to \p dispSignalCount.
 * 
 * @param signal_list The signal_list to be searched in.
 * @param signal_list_len The Length of \p signal_list
 * @param dispSignalCount The total Count of Display Signals in \p signal_list
 * is written to this Pointer.
 * @param needle The Display Signal to return
 * @return Pointer to the display Signal in place of \p needle
 */
signals_signal* signals_find_display_signal(signals_signal* signal_list,
        uint32_t signal_list_len, uint32_t* dispSignalCount, uint32_t needle);

#ifdef	__cplusplus
}
#endif

#endif	/* SIGNALS_H */

/**
 * \}
 */

