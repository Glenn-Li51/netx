/**************************************************************************/
/*                                                                        */
/*       Copyright (c) Microsoft Corporation. All rights reserved.        */
/*                                                                        */
/*       This software is licensed under the Microsoft Software License   */
/*       Terms for Microsoft Azure RTOS. Full text of the license can be  */
/*       found in the LICENSE file at https://aka.ms/AzureRTOS_EULA       */
/*       and in the root directory of this software.                      */
/*                                                                        */
/**************************************************************************/


/**************************************************************************/
/**************************************************************************/
/**                                                                       */
/** NetX Component                                                        */
/**                                                                       */
/**   Reverse Address Resolution Protocol (RARP)                          */
/**                                                                       */
/**************************************************************************/
/**************************************************************************/

#define NX_SOURCE_CODE


/* Include necessary system files.  */

#include "nx_api.h"
#include "nx_rarp.h"


/**************************************************************************/
/*                                                                        */
/*  FUNCTION                                               RELEASE        */
/*                                                                        */
/*    _nx_rarp_info_get                                   PORTABLE C      */
/*                                                           6.0          */
/*  AUTHOR                                                                */
/*                                                                        */
/*    Yuxin Zhou, Microsoft Corporation                                   */
/*                                                                        */
/*  DESCRIPTION                                                           */
/*                                                                        */
/*    This function obtains RARP information for the specified IP         */
/*    instance.                                                           */
/*                                                                        */
/*  INPUT                                                                 */
/*                                                                        */
/*    ip_ptr                                IP instance pointer           */
/*    rarp_requests_sent                    Destination for the number of */
/*                                            RARP requests sent          */
/*    rarp_responses_received               Destination for the number of */
/*                                            RARP responses received     */
/*    rarp_invalid_messages                 Destination for the number of */
/*                                            RARP invalid messages (or   */
/*                                            unhandled)                  */
/*                                                                        */
/*  OUTPUT                                                                */
/*                                                                        */
/*    status                                Completion status             */
/*                                                                        */
/*  CALLS                                                                 */
/*                                                                        */
/*    None                                                                */
/*                                                                        */
/*  CALLED BY                                                             */
/*                                                                        */
/*    Application Code                                                    */
/*                                                                        */
/*  RELEASE HISTORY                                                       */
/*                                                                        */
/*    DATE              NAME                      DESCRIPTION             */
/*                                                                        */
/*  05-19-2020     Yuxin Zhou               Initial Version 6.0           */
/*                                                                        */
/**************************************************************************/
UINT  _nx_rarp_info_get(NX_IP *ip_ptr, ULONG *rarp_requests_sent, ULONG *rarp_responses_received,
                        ULONG *rarp_invalid_messages)
{

TX_INTERRUPT_SAVE_AREA


    /* If trace is enabled, insert this event into the trace buffer.  */
    NX_TRACE_IN_LINE_INSERT(NX_TRACE_RARP_INFO_GET, ip_ptr, ip_ptr -> nx_ip_rarp_requests_sent, ip_ptr -> nx_ip_rarp_responses_received, ip_ptr -> nx_ip_rarp_invalid_messages, NX_TRACE_RARP_EVENTS, 0, 0)

    /* Disable interrupts.  */
    TX_DISABLE

    /* Determine if RARP requests sent is wanted.  */
    if (rarp_requests_sent)
    {

        /* Return the number of RARP requests sent by this IP instance.  */
        *rarp_requests_sent =  ip_ptr -> nx_ip_rarp_requests_sent;
    }

    /* Determine if RARP responses received is wanted.  */
    if (rarp_responses_received)
    {

        /* Return the number of RARP responses received by this IP instance.  */
        *rarp_responses_received =  ip_ptr -> nx_ip_rarp_responses_received;
    }

    /* Determine if RARP invalid (or unhandled) messages is wanted.  */
    if (rarp_invalid_messages)
    {

        /* Return the number of RARP invalid messages received by this IP instance.  */
        *rarp_invalid_messages =  ip_ptr -> nx_ip_rarp_invalid_messages;
    }

    /* Restore interrupts.  */
    TX_RESTORE

    /* Return successful completion.  */
    return(NX_SUCCESS);
}

