/************************************************************************
 *
 * NAME
 *  cruise-sm.c
 *
 * State machine: cruise_control
 *
 * This file was automatically generated from: cruise.smc
 *
 * DO NOT EDIT THIS FILE. YOUR CHANGES WILL BE
 * OVER-WRITTEN THE NEXT TIME THAT DDL IS RUN.
 *
 * GENERATED
 *  Tue May 22 16:18:00 2007
 *
 ************************************************************************/

#include "stm.h"
#include "cruise-sm.h"

#if !defined( NULL )
#   define NULL 0
#endif

static STM_Input cruise_control_inputQueue[ 10 ];

static uint8_t cruise_control_stateData[ 5 * 16 ] =
{
    /* S00 */ 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    /* S01 */ 0, 0, 0, 1, 2, 0, 3, 2, 0, 1, 2, 3, 0, 1, 0, 1,
    /* S02 */ 0, 0, 0, 2, 4, 0, 0, 2, 5, 1, 4, 3, 0, 2, 0, 2,
    /* S03 */ 0, 0, 0, 3, 6, 0, 0, 3, 0, 3, 0, 3, 7, 4, 0, 3,
    /* S04 */ 0, 0, 0, 4, 8, 0, 0, 4, 0, 4, 8, 3, 0, 4, 5, 1
};

static STM_Action cruise_control_action[ 9 ] =
{
    NULL,
    ccac_read_rotation_rate,
    ccac_dis_maint_const_spd,
    ccac_enab_increase_spd,
    ccac_dis_increase_spd,
    ccac_enab_maint_const_spd,
    ccac_do_nothing,
    ccac_enab_ret_to_prev_spd,
    ccac_dis_ret_to_prev_spd
};

#if defined( STM_DEBUG )

static char     *cruise_control_actionStr[ 9 ] =
{
    "",
    "read_rotation_rate",
    "dis_maint_const_spd",
    "enab_increase_spd",
    "dis_increase_spd",
    "enab_maint_const_spd",
    "do_nothing",
    "enab_ret_to_prev_spd",
    "dis_ret_to_prev_spd"
};

static char     *cruise_control_inputStr[ 7 ] =
{
    "enable_cruise",
    "disable_cruise",
    "start_incr_speed",
    "stop_incr_speed",
    "apply_brake",
    "resume_speed",
    "prev_speed_reached"
};

static char     *cruise_control_stateStr[ 5 ] =
{
    "cruise_off",
    "maintain_speed",
    "increasing_speed",
    "cruise_interrupted",
    "resuming_speed"
};

#endif

STM_StateMachine cruise_controlSm =
{
        9,  /* numActions           */
        7,  /* numInputs            */
        5,  /* numStates            */
        0,  /* currState            */
    cruise_control_inputQueue,
        0,  /* queueLen             */
        0,  /* queuePutIdx          */
        0,  /* queueGetIdx          */
       10,  /* queueMax             */
       16,  /* stateBytes           */
    cruise_control_stateData,
    cruise_control_action,
    NULL,   /* actionProc           */
    NULL    /* userParm             */

#if defined( STM_DEBUG )
    ,
    STM_MAGIC,
    "cruise_control",
    cruise_control_actionStr,
    cruise_control_inputStr,
    cruise_control_stateStr,
    0,  /* FALSE - dbgActions       */
    0,  /* FALSE - dbgInputs        */
    0   /* FALSE - dbgStates        */
#endif
};
