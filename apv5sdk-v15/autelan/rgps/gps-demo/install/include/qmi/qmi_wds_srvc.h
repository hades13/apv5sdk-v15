#ifndef QMI_WDS_SRVC_H
#define QMI_WDS_SRVC_H

/******************************************************************************
  @file    qmi_wds_srvc.h
  @brief   QMI message library WDS service definitions

  DESCRIPTION
  This file contains common, external header file definitions for QMI
  interface library.

  INITIALIZATION AND SEQUENCING REQUIREMENTS
  qmi_wds_srvc_init_client() must be called to create one or more clients
  qmi_wds_srvc_release_client() must be called to delete each client when
  finished.

  $Header: //source/qcom/qct/modem/datacommon/qmimsglib/dev/work/inc/qmi_wds_srvc.h#5 $
  $DateTime: 2009/07/15 10:38:12 $
  ---------------------------------------------------------------------------
  Copyright (c) 2007 - 2012 QUALCOMM Incorporated.
  All Rights Reserved. QUALCOMM Proprietary and Confidential.
  ---------------------------------------------------------------------------
******************************************************************************/

#include "qmi.h"

#ifdef __cplusplus
extern "C" {
#endif

#define QMI_WDS_MAX_PROFILE_STR_SIZE  (32)
#define QMI_WDS_MAX_APN_STR_SIZE              (100 + 1) // Max APN size should be 100
                                                       // terminated by a NULL.
#define QMI_WDS_MAX_USERNAME_PASS_STR_SIZE    (127 + 1)
#define QMI_WDS_MOBILE_IP_PROFILE_MAX_STR_SIZE (127 + 1)
#define QMI_WDS_UMTS_QOS_SIZE       33
#define QMI_WDS_GPRS_QOS_SIZE       20
#define QMI_WDS_LTE_QOS_SIZE        17
#define QMI_WDS_TFT_FILTER_SIZE     39
#define QMI_WDS_MIP_SERVICE_PROGRAMMING_CODE_SIZE    6
#define QMI_WDS_MAX_SOFTAP_SNAT_ENTRIES 50

#define QMI_WDS_MAX_P_CSCF_IPV4_ADDRS   6
#define QMI_WDS_MAX_P_CSCF_IPV6_ADDRS   6
#define QMI_WDS_MAX_MCAST_ADDRS         25
#define QMI_WDS_MAX_MCAST_HNDLS         10
#define QMI_WDS_IPV6_ADDR_SIZE_IN_BYTES 16
#define QMI_WDS_IPV4_ADDR_SIZE_IN_BYTES 4
#define QMI_WDS_MAX_ERR_CODES_IN_RSP    10 // ? TODO : FIND OUT HOW MANY ?
#define QMI_WDS_MAX_FQDN_STRINGS       QMI_WDS_MAX_P_CSCF_IPV4_ADDRS
#define QMI_WDS_MAX_DOMAIN_NAMES       QMI_WDS_MAX_P_CSCF_IPV4_ADDRS

#define QMI_WDS_MAX_DATA_SYS_STATUS_NETWORK_INFO_LEN  (16)

/************************************************************************
* Definitions associated with ip_addr type declarations
************************************************************************/
typedef unsigned long ipv4_addr_type;
typedef unsigned char ipv6_addr_type[QMI_WDS_IPV6_ADDR_SIZE_IN_BYTES];

/*CE denotes CALL END*/
typedef enum
{
  /* Call-end reason was not received, value undefined */
  QMI_WDS_CE_REASON_UNDEFINED                 = -1,

  /* Technology-Agnostic Call End Reasons */
  QMI_WDS_CE_REASON_UNSPECIFIED               = 1,
  QMI_WDS_CE_REASON_CLIENT_END                = 2,
  QMI_WDS_CE_REASON_NO_SRV                    = 3,
  QMI_WDS_CE_REASON_FADE                      = 4,
  QMI_WDS_CE_REASON_REL_NORMAL                = 5,
  QMI_WDS_CE_REASON_ACC_IN_PROG               = 6,
  QMI_WDS_CE_REASON_ACC_FAIL                  = 7,
  QMI_WDS_CE_REASON_REDIR_OR_HANDOFF          = 8,
  QMI_WDS_CE_REASON_CLOSE_IN_PROGRESS         = 9,
  QMI_WDS_CE_REASON_AUTH_FAILED               = 10,
  QMI_WDS_CE_REASON_INTERNAL_CALL_END         = 11,

  /* CDMA Call End Reasons */
  QMI_WDS_CE_REASON_CDMA_LOCK                 = 500,
  QMI_WDS_CE_REASON_INTERCEPT                 = 501,
  QMI_WDS_CE_REASON_REORDER                   = 502,
  QMI_WDS_CE_REASON_REL_SO_REJ                = 503,
  QMI_WDS_CE_REASON_INCOM_CALL                = 504,
  QMI_WDS_CE_REASON_ALERT_STOP                = 505,
  QMI_WDS_CE_REASON_ACTIVATION                = 506,
  QMI_WDS_CE_REASON_MAX_ACCESS_PROBE          = 507,
  QMI_WDS_CE_REASON_CCS_NOT_SUPPORTED_BY_BS   = 508,
  QMI_WDS_CE_REASON_NO_RESPONSE_FROM_BS       = 509,
  QMI_WDS_CE_REASON_REJECTED_BY_BS            = 510,
  QMI_WDS_CE_REASON_INCOMPATIBLE              = 511,
  QMI_WDS_CE_REASON_ALREADY_IN_TC             = 512,
  QMI_WDS_CE_REASON_USER_CALL_ORIG_DURING_GPS = 513,
  QMI_WDS_CE_REASON_USER_CALL_ORIG_DURING_SMS = 514,
  QMI_WDS_CE_REASON_NO_CDMA_SRV               = 515,

  /* WCDMA/GSM Call End Reasons */
  QMI_WDS_CE_REASON_CONF_FAILED               = 1000,
  QMI_WDS_CE_REASON_INCOM_REJ                 = 1001,
  QMI_WDS_CE_REASON_NO_GW_SRV                 = 1002,
  QMI_WDS_CE_REASON_NETWORK_END               = 1003,
  QMI_WDS_CE_REASON_LLC_SNDCP_FAILURE         = 1004,
  QMI_WDS_CE_REASON_INSUFFICIENT_RESOURCES    = 1005,
  QMI_WDS_CE_REASON_OPTION_TEMP_OOO           = 1006,
  QMI_WDS_CE_REASON_NSAPI_ALREADY_USED        = 1007,
  QMI_WDS_CE_REASON_REGULAR_DEACTIVATION      = 1008,
  QMI_WDS_CE_REASON_NETWORK_FAILURE           = 1009,
  QMI_WDS_CE_REASON_UMTS_REATTACH_REQ         = 1010,
  QMI_WDS_CE_REASON_PROTOCOL_ERROR            = 1011,

  QMI_WDS_CE_REASON_OPERATOR_DETERMINED_BARRING         = 1012,
  QMI_WDS_CE_REASON_UNKNOWN_APN                         = 1013,
  QMI_WDS_CE_REASON_UNKNOWN_PDP                         = 1014,
  QMI_WDS_CE_REASON_GGSN_REJECT                         = 1015,
  QMI_WDS_CE_REASON_ACTIVATION_REJECT                   = 1016,
  QMI_WDS_CE_REASON_OPTION_NOT_SUPPORTED                = 1017,
  QMI_WDS_CE_REASON_OPTION_UNSUBSCRIBED                 = 1018,
  QMI_WDS_CE_REASON_QOS_NOT_ACCEPTED                    = 1019,
  QMI_WDS_CE_REASON_TFT_SEMANTIC_ERROR                  = 1020,
  QMI_WDS_CE_REASON_TFT_SYNTAX_ERROR                    = 1021,
  QMI_WDS_CE_REASON_UNKNOWN_PDP_CONTEXT                 = 1022,
  QMI_WDS_CE_REASON_FILTER_SEMANTIC_ERROR               = 1023,
  QMI_WDS_CE_REASON_FILTER_SYNTAX_ERROR                 = 1024,
  QMI_WDS_CE_REASON_PDP_WITHOUT_ACTIVE_TFT              = 1025,
  QMI_WDS_CE_REASON_INVALID_TRANSACTION_ID              = 1026,
  QMI_WDS_CE_REASON_MESSAGE_INCORRECT_SEMANTIC          = 1027,
  QMI_WDS_CE_REASON_INVALID_MANDATORY_INFO              = 1028,
  QMI_WDS_CE_REASON_MESSAGE_TYPE_UNSUPPORTED            = 1029,
  QMI_WDS_CE_REASON_MSG_TYPE_NONCOMPATIBLE_STATE        = 1030,
  QMI_WDS_CE_REASON_UNKNOWN_INFO_ELEMENT                = 1031,
  QMI_WDS_CE_REASON_CONDITIONAL_IE_ERROR                = 1032,
  QMI_WDS_CE_REASON_MSG_AND_PROTOCOL_STATE_UNCOMPATIBLE = 1033,
  QMI_WDS_CE_REASON_APN_TYPE_CONFLICT                   = 1034,

  QMI_WDS_CE_REASON_NO_GPRS_CONTEXT                     = 1035,
  QMI_WDS_CE_REASON_FEATURE_NOT_SUPPORTED               = 1036,
  QMI_WDS_CE_REASON_ILLEGAL_MS                          = 1037,
  QMI_WDS_CE_REASON_ILLEGAL_ME                          = 1038,
  QMI_WDS_CE_REASON_GPRS_SERVICES_AND_NON_GPRS_SERVICES_NOT_ALLOWED = 1039,
  QMI_WDS_CE_REASON_GPRS_SERVICES_NOT_ALLOWED                       = 1040,
  QMI_WDS_CE_REASON_MS_IDENTITY_CANNOT_BE_DERIVED_BY_THE_NETWORK    = 1041,
  QMI_WDS_CE_REASON_IMPLICITLY_DETACHED                 = 1042,
  QMI_WDS_CE_REASON_PLMN_NOT_ALLOWED                    = 1043,
  QMI_WDS_CE_REASON_LA_NOT_ALLOWED                      = 1044,
  QMI_WDS_CE_REASON_GPRS_SERVICES_NOT_ALLOWED_IN_THIS_PLMN = 1045,
  QMI_WDS_CE_REASON_PDP_DUPLICATE                       = 1046,
  QMI_WDS_CE_REASON_UE_RAT_CHANGE                       = 1047,

  /* 1xEV-DO Call End Reasons */
  QMI_WDS_CE_REASON_CD_GEN_OR_BUSY                      = 1500,
  QMI_WDS_CE_REASON_CD_BILL_OR_AUTH                     = 1501,
  QMI_WDS_CE_REASON_CHG_HDR                             = 1502,
  QMI_WDS_CE_REASON_EXIT_HDR                            = 1503,
  QMI_WDS_CE_REASON_HDR_NO_SESSION                      = 1504,
  QMI_WDS_CE_REASON_HDR_ORIG_DURING_GPS_FIX             = 1505,
  QMI_WDS_CE_REASON_HDR_CS_TIMEOUT                      = 1506,
  QMI_WDS_CE_REASON_HDR_RELEASED_BY_CM                  = 1507,

  QMI_WDS_CE_REASON_MAX                               /* DO NOT USE. Used for bounds check */
} qmi_wds_ce_reason_legacy_type;

/* Profile ID technoloty type values */
typedef enum
{
  QMI_WDS_PROFILE_TECH_TYPE_MIN = 0x00,
  QMI_WDS_PROFILE_TECH_3GPP  = QMI_WDS_PROFILE_TECH_TYPE_MIN,
  QMI_WDS_PROFILE_TECH_3GPP2 = 0x01,
  QMI_WDS_PROFILE_TECH_TYPE_MAX = QMI_WDS_PROFILE_TECH_3GPP2
} qmi_wds_profile_tech_type;

typedef enum
{
  QMI_WDS_CE_TYPE_INVALID               = 0XFF,
  QMI_WDS_CE_TYPE_MOBILE_IP             = 0x01,
  QMI_WDS_CE_TYPE_INTERNAL              = 0x02,
  QMI_WDS_CE_TYPE_CALL_MANAGER_DEFINED  = 0x03,
  QMI_WDS_CE_TYPE_3GPP_SPEC_DEFINED     = 0x06,
  QMI_WDS_CE_TYPE_PPP                   = 0x07,
  QMI_WDS_CE_TYPE_EHRPD                 = 0x08,
  QMI_WDS_CE_TYPE_IPV6                  = 0x09
}qmi_wds_verbose_ce_reason_type;

typedef enum
{
  QMI_WDS_VERBOSE_CE_INVALID                                                           = -1,
  /*Mobile IP Call End reasons*/
  QMI_WDS_VERBOSE_CE_MIP_FA_ERR_REASON_UNSPECIFIED                                     = 64,
  QMI_WDS_VERBOSE_CE_MIP_FA_ERR_ADMINISTRATIVELY_PROHIBITED                            = 65,
  QMI_WDS_VERBOSE_CE_MIP_FA_ERR_INSUFFICIENT_RESOURCES                                 = 66,
  QMI_WDS_VERBOSE_CE_MIP_FA_ERR_MOBILE_NODE_AUTHENTICATION_FAILURE                     = 67,
  QMI_WDS_VERBOSE_CE_MIP_FA_ERR_HA_AUTHENTICATION_FAILURE                              = 68,
  QMI_WDS_VERBOSE_CE_MIP_FA_ERR_REQUESTED_LIFETIME_TOO_LONG                            = 69,
  QMI_WDS_VERBOSE_CE_MIP_FA_ERR_MALFORMED_REQUEST                                      = 70,
  QMI_WDS_VERBOSE_CE_MIP_FA_ERR_MALFORMED_REPLY                                        = 71,
  QMI_WDS_VERBOSE_CE_MIP_FA_ERR_ENCAPSULATION_UNAVAILABLE                              = 72,
  QMI_WDS_VERBOSE_CE_MIP_FA_ERR_VJHC_UNAVAILABLE                                       = 73,
  QMI_WDS_VERBOSE_CE_MIP_FA_ERR_REVERSE_TUNNEL_UNAVAILABLE                             = 74,
  QMI_WDS_VERBOSE_CE_MIP_FA_ERR_REVERSE_TUNNEL_IS_MANDATORY_AND_T_BIT_NOT_SET          = 75,
  QMI_WDS_VERBOSE_CE_MIP_FA_ERR_DELIVERY_STYLE_NOT_SUPPORTED                           = 79,
  QMI_WDS_VERBOSE_CE_MIP_FA_ERR_MISSING_NAI                                            = 97,
  QMI_WDS_VERBOSE_CE_MIP_FA_ERR_MISSING_HA                                             = 98,
  QMI_WDS_VERBOSE_CE_MIP_FA_ERR_MISSING_HOME_ADDR                                      = 99,
  QMI_WDS_VERBOSE_CE_MIP_FA_ERR_UNKNOWN_CHALLENGE                                      = 104,
  QMI_WDS_VERBOSE_CE_MIP_FA_ERR_MISSING_CHALLENGE                                      = 105,
  QMI_WDS_VERBOSE_CE_MIP_FA_ERR_STALE_CHALLENGE                                        = 106,
  QMI_WDS_VERBOSE_CE_MIP_HA_ERR_REASON_UNSPECIFIED                                     = 128,
  QMI_WDS_VERBOSE_CE_MIP_HA_ERR_ADMINISTRATIVELY_PROHIBITED                            = 129,
  QMI_WDS_VERBOSE_CE_MIP_HA_ERR_INSUFFICIENT_RESOURCES                                 = 130,
  QMI_WDS_VERBOSE_CE_MIP_HA_ERR_MOBILE_NODE_AUTHENTICATION_FAILURE                     = 131,
  QMI_WDS_VERBOSE_CE_MIP_HA_ERR_FA_AUTHENTICATION_FAILURE                              = 132,
  QMI_WDS_VERBOSE_CE_MIP_HA_ERR_REGISTRATION_ID_MISMATCH                               = 133,
  QMI_WDS_VERBOSE_CE_MIP_HA_ERR_MALFORMED_REQUEST                                      = 134,
  QMI_WDS_VERBOSE_CE_MIP_HA_ERR_UNKNOWN_HA_ADDR                                        = 136,
  QMI_WDS_VERBOSE_CE_MIP_HA_ERR_REVERSE_TUNNEL_UNAVAILABLE                             = 137,
  QMI_WDS_VERBOSE_CE_MIP_HA_ERR_REVERSE_TUNNEL_IS_MANDATORY_AND_T_BIT_NOT_SET          = 138,
  QMI_WDS_VERBOSE_CE_MIP_HA_ERR_ENCAPSULATION_UNAVAILABLE                              = 139,
  QMI_WDS_VERBOSE_CE_MIP_ERR_REASON_UNKNOWN                                            = 65535,

  /*Internal Error Call End reasons*/
  QMI_WDS_VERBOSE_CE_INTERNAL_ERROR                                = 201,
  QMI_WDS_VERBOSE_CE_CALL_ENDED                                    = 202,
  QMI_WDS_VERBOSE_CE_INTERNAL_UNKNOWN_CAUSE_CODE                   = 203,
  QMI_WDS_VERBOSE_CE_UNKNOWN_CAUSE_CODE                            = 204,
  QMI_WDS_VERBOSE_CE_CLOSE_IN_PROGRESS                             = 205,
  QMI_WDS_VERBOSE_CE_NW_INITIATED_TERMINATION                      = 206,
  QMI_WDS_VERBOSE_CE_APP_PREEMPTED                                 = 207,


  /*CM defined Call End reasons*/
  QMI_WDS_VERBOSE_CE_CDMA_LOCK                                              = 500,
  QMI_WDS_VERBOSE_CE_INTERCEPT                                              = 501,
  QMI_WDS_VERBOSE_CE_REORDER                                                = 502,
  QMI_WDS_VERBOSE_CE_REL_SO_REJ                                             = 503,
  QMI_WDS_VERBOSE_CE_INCOM_CALL                                             = 504,
  QMI_WDS_VERBOSE_CE_ALERT_STOP                                             = 505,
  QMI_WDS_VERBOSE_CE_ACTIVATION                                             = 506,
  QMI_WDS_VERBOSE_CE_MAX_ACCESS_PROBE                                       = 507,
  QMI_WDS_VERBOSE_CE_CCS_NOT_SUPPORTED_BY_BS                                = 508,
  QMI_WDS_VERBOSE_CE_NO_RESPONSE_FROM_BS                                    = 509,
  QMI_WDS_VERBOSE_CE_REJECTED_BY_BS                                         = 510,
  QMI_WDS_VERBOSE_CE_INCOMPATIBLE                                           = 511,
  QMI_WDS_VERBOSE_CE_ALREADY_IN_TC                                          = 512,
  QMI_WDS_VERBOSE_CE_USER_CALL_ORIG_DURING_GPS                              = 513,
  QMI_WDS_VERBOSE_CE_USER_CALL_ORIG_DURING_SMS                              = 514,
  QMI_WDS_VERBOSE_CE_NO_CDMA_SRV                                            = 515,
  QMI_WDS_VERBOSE_CE_CONF_FAILED                                            = 1000,
  QMI_WDS_VERBOSE_CE_INCOM_REJ                                              = 1001,
  QMI_WDS_VERBOSE_CE_NO_GW_SRV                                              = 1002,
  QMI_WDS_VERBOSE_CE_NO_GPRS_CONTEXT                                        = 1003,
  QMI_WDS_VERBOSE_CE_ILLEGAL_MS                                             = 1004,
  QMI_WDS_VERBOSE_CE_ILLEGAL_ME                                             = 1005,
  QMI_WDS_VERBOSE_CE_GPRS_SERVICES_AND_NON_GPRS_SERVICES_NOT_ALLOWED        = 1006,
  QMI_WDS_VERBOSE_CE_GPRS_SERVICES_NOT_ALLOWED                              = 1007,
  QMI_WDS_VERBOSE_CE_MS_IDENTITY_CANNOT_BE_DERIVED_BY_THE_NETWORK           = 1008,
  QMI_WDS_VERBOSE_CE_IMPLICITLY_DETACHED                                    = 1009,
  QMI_WDS_VERBOSE_CE_PLMN_NOT_ALLOWED                                       = 1010,
  QMI_WDS_VERBOSE_CE_LA_NOT_ALLOWED                                         = 1011,
  QMI_WDS_VERBOSE_CE_GPRS_SERVICES_NOT_ALLOWED_IN_THIS_PLMN                 = 1012,
  QMI_WDS_VERBOSE_CE_PDP_DUPLICATE                                          = 1013,
  QMI_WDS_VERBOSE_CE_UE_RAT_CHANGE                                          = 1014,
  QMI_WDS_VERBOSE_CE_CONGESTION                                             = 1015,
  QMI_WDS_VERBOSE_CE_NO_PDP_CONTEXT_ACTIVATED                               = 1016,
  QMI_WDS_VERBOSE_CE_ACCESS_CLASS_DSAC_REJECTION                            = 1017,
  QMI_WDS_VERBOSE_CE_CD_GEN_OR_BUSY                                         = 1500,
  QMI_WDS_VERBOSE_CE_CD_BILL_OR_AUTH                                        = 1501,
  QMI_WDS_VERBOSE_CE_CHG_HDR                                                = 1502,
  QMI_WDS_VERBOSE_CE_EXIT_HDR                                               = 1503,
  QMI_WDS_VERBOSE_CE_HDR_NO_SESSION                                         = 1504,
  QMI_WDS_VERBOSE_CE_HDR_ORIG_DURING_GPS_FIX                                = 1505,
  QMI_WDS_VERBOSE_CE_HDR_CS_TIMEOUT                                         = 1506,
  QMI_WDS_VERBOSE_CE_HDR_RELEASED_BY_CM                                     = 1507,
  QMI_WDS_VERBOSE_CE_CLIENT_END                                             = 2000,
  QMI_WDS_VERBOSE_CE_NO_SRV                                                 = 2001,
  QMI_WDS_VERBOSE_CE_FADE                                                   = 2002,
  QMI_WDS_VERBOSE_CE_REL_NORMAL                                             = 2003,
  QMI_WDS_VERBOSE_CE_ACC_IN_PROG                                            = 2004,
  QMI_WDS_VERBOSE_CE_ACC_FAIL                                               = 2005,
  QMI_WDS_VERBOSE_CE_REDIR_OR_HANDOFF                                       = 2006,

  /*3GPP spec defined Call End reasons*/
  QMI_WDS_VERBOSE_CE_OPERATOR_DETERMINED_BARRING                            = 8,
  QMI_WDS_VERBOSE_CE_LLC_SNDCP_FAILURE                                      = 25,
  QMI_WDS_VERBOSE_CE_INSUFFICIENT_RESOURCES                                 = 26,
  QMI_WDS_VERBOSE_CE_UNKNOWN_APN                                            = 27,
  QMI_WDS_VERBOSE_CE_UNKNOWN_PDP                                            = 28,
  QMI_WDS_VERBOSE_CE_AUTH_FAILED                                            = 29,
  QMI_WDS_VERBOSE_CE_GGSN_REJECT                                            = 30,
  QMI_WDS_VERBOSE_CE_ACTIVATION_REJECT                                      = 31,
  QMI_WDS_VERBOSE_CE_OPTION_NOT_SUPPORTED                                   = 32,
  QMI_WDS_VERBOSE_CE_OPTION_UNSUBSCRIBED                                    = 33,
  QMI_WDS_VERBOSE_CE_OPTION_TEMP_OOO                                        = 34,
  QMI_WDS_VERBOSE_CE_NSAPI_ALREADY_USED                                     = 35,
  QMI_WDS_VERBOSE_CE_REGULAR_DEACTIVATION                                   = 36,
  QMI_WDS_VERBOSE_CE_QOS_NOT_ACCEPTED                                       = 37,
  QMI_WDS_VERBOSE_CE_NETWORK_FAILURE                                        = 38,
  QMI_WDS_VERBOSE_CE_UMTS_REACTIVATION_REQ                                  = 39,
  QMI_WDS_VERBOSE_CE_FEATURE_NOT_SUPPORTED                                  = 40,
  QMI_WDS_VERBOSE_CE_TFT_SEMANTIC_ERROR                                     = 41,
  QMI_WDS_VERBOSE_CE_TFT_SYNTAX_ERROR                                       = 42,
  QMI_WDS_VERBOSE_CE_UNKNOWN_PDP_CONTEXT                                    = 43,
  QMI_WDS_VERBOSE_CE_FILTER_SEMANTIC_ERROR                                  = 44,
  QMI_WDS_VERBOSE_CE_FILTER_SYNTAX_ERROR                                    = 45,
  QMI_WDS_VERBOSE_CE_PDP_WITHOUT_ACTIVE_TFT                                 = 46,
  QMI_WDS_VERBOSE_CE_IP_V4_ONLY_ALLOWED                                     = 50,
  QMI_WDS_VERBOSE_CE_IP_V6_ONLY_ALLOWED                                     = 51,
  QMI_WDS_VERBOSE_CE_SINGLE_ADDR_BEARER_ONLY                                = 52,
  QMI_WDS_VERBOSE_CE_INVALID_TRANSACTION_ID                                 = 81,
  QMI_WDS_VERBOSE_CE_MESSAGE_INCORRECT_SEMANTIC                             = 95,
  QMI_WDS_VERBOSE_CE_INVALID_MANDATORY_INFO                                 = 96,
  QMI_WDS_VERBOSE_CE_MESSAGE_TYPE_UNSUPPORTED                               = 97,
  QMI_WDS_VERBOSE_CE_MSG_TYPE_NONCOMPATIBLE_STATE                           = 98,
  QMI_WDS_VERBOSE_CE_UNKNOWN_INFO_ELEMENT                                   = 99,
  QMI_WDS_VERBOSE_CE_CONDITIONAL_IE_ERROR                                   = 100,
  QMI_WDS_VERBOSE_CE_MSG_AND_PROTOCOL_STATE_UNCOMPATIBLE                    = 101,
  QMI_WDS_VERBOSE_CE_PROTOCOL_ERROR                                         = 111,
  QMI_WDS_VERBOSE_CE_APN_TYPE_CONFLICT                                      = 112,

  /*Enumeration for the PPP verbose call end reason*/
  QMI_WDS_VERBOSE_CE_PPP_TIMEOUT                                            = 1,
  QMI_WDS_VERBOSE_CE_PPP_AUTH_FAILURE                                       = 2,
  QMI_WDS_VERBOSE_CE_PPP_OPTION_MISMATCH                                    = 3,
  QMI_WDS_VERBOSE_CE_PPP_PAP_FAILURE                                        = 31,
  QMI_WDS_VERBOSE_CE_PPP_CHAP_FAILURE                                       = 32,
  QMI_WDS_VERBOSE_CE_PPP_UNKNOWN                                            = -1,

  /* Enumeration for the EHRPD verbose call end reason */
  QMI_WDS_VERBOSE_CE_EHRPD_SUBS_LIMITED_TO_V4                               = 1,
  QMI_WDS_VERBOSE_CE_EHRPD_SUBS_LIMITED_TO_V6                               = 2,
  QMI_WDS_VERBOSE_CE_EHRPD_VSNCP_TIMEOUT                                    = 4,
  QMI_WDS_VERBOSE_CE_EHRPD_VSNCP_FAILURE                                    = 5,
  QMI_WDS_VERBOSE_CE_EHRPD_VSNCP_3GPP2I_GEN_ERROR                           = 6,
  QMI_WDS_VERBOSE_CE_EHRPD_VSNCP_3GPP2I_UNAUTH_APN                          = 7,
  QMI_WDS_VERBOSE_CE_EHRPD_VSNCP_3GPP2I_PDN_LIMIT_EXCEED                    = 8,
  QMI_WDS_VERBOSE_CE_EHRPD_VSNCP_3GPP2I_NO_PDN_GW                           = 9,
  QMI_WDS_VERBOSE_CE_EHRPD_VSNCP_3GPP2I_PDN_GW_UNREACH                      = 10,
  QMI_WDS_VERBOSE_CE_EHRPD_VSNCP_3GPP2I_PDN_GW_REJ                          = 11,
  QMI_WDS_VERBOSE_CE_EHRPD_VSNCP_3GPP2I_INSUFF_PARAM                        = 12,
  QMI_WDS_VERBOSE_CE_EHRPD_VSNCP_3GPP2I_RESOURCE_UNAVAIL                    = 13,
  QMI_WDS_VERBOSE_CE_EHRPD_VSNCP_3GPP2I_ADMIN_PROHIBIT                      = 14,
  QMI_WDS_VERBOSE_CE_EHRPD_VSNCP_3GPP2I_PDN_ID_IN_USE                       = 15,
  QMI_WDS_VERBOSE_CE_EHRPD_VSNCP_3GPP2I_SUBSCR_LIMITATION                   = 16,
  QMI_WDS_VERBOSE_CE_EHRPD_VSNCP_3GPP2I_PDN_EXISTS_FOR_THIS_APN             = 17,

  /*IPV6 defined Call End reasons*/
  QMI_WDS_VERBOSE_CE_PREFIX_UNAVAILABLE                                     = 1,
  QMI_WDS_VERBOSE_CE_IPV6_ERR_HRPD_IPV6_DISABLED                            = 2

}qmi_wds_verbose_ce_reason_codes;

typedef struct
{
  qmi_wds_ce_reason_legacy_type   legacy_reason;
  struct
  {
    qmi_wds_verbose_ce_reason_type    verbose_reason_type;
    qmi_wds_verbose_ce_reason_codes   verbose_reason;
  }call_end_reason_verbose;
}qmi_wds_call_end_reason_type;

/*************************************************************************
* SoftAP Definitions
*************************************************************************/
typedef enum
{
  QMI_WDS_SOFTAP_WWAN_CONNECTING    = 0x01,
  QMI_WDS_SOFTAP_WWAN_CONNECTED     = 0x02,
  QMI_WDS_SOFTAP_WWAN_DISCONNECTING = 0x03,
  QMI_WDS_SOFTAP_WWAN_DISCONNECTED  = 0x04
} qmi_wds_softap_wwan_status_type;

#define QMI_WDS_SOFTAP_STATUS_IND_CALL_END_REASON QMI_WDS_PKT_SRVC_IND_CALL_END_REASON

typedef struct
{
  //mask to denote validity of call_end_reason;
  unsigned short                      param_mask;

  qmi_wds_softap_wwan_status_type     wwan_status;
  /*Optional Params: Use param_mask to denote validity*/
  qmi_wds_call_end_reason_type        call_end_reason;
} qmi_wds_softap_wwan_status_ind_type;


typedef struct
{
  /* Addresses should be in host order type */
  unsigned long subnet_mask;
  unsigned long nat_ip_addr;
  unsigned long nat_dns_addr;
  unsigned long rmnet_usb_te_ip_addr;
  unsigned long rmnet_usb_te_gateway_addr;
  unsigned long rmnet_embedded_te_ip_addr;
  unsigned long rmnet_embedded_te_gateway_addr;
} qmi_wds_softap_ip_info_type;

typedef struct
{
  qmi_wds_profile_tech_type  technology;
  unsigned short             umts_profile_index;
  unsigned char              cdma_profile_index;
  unsigned char              ip_family;
} qmi_wds_softap_net_policy_info_type;

#define QMI_WDS_SOFTAP_IP_INFO_PARAM_MASK                          0x00000001
#define QMI_WDS_SOFTAP_NET_POLICY_INFO_PARAM_MASK                  0x00000002
#define QMI_WDS_SOFTAP_MTU_PARAM_MASK                              0x00000004

typedef struct
{
  unsigned long params_mask;

  qmi_wds_softap_ip_info_type         ip_info;
  qmi_wds_softap_net_policy_info_type net_policy;
}qmi_wds_softap_enable_params_type;

typedef enum
{
  QMI_WDS_SOFTAP_SET_IPSEC = 0x01,
  QMI_WDS_SOFTAP_GET_IPSEC = 0x02,
  QMI_WDS_SOFTAP_SET_L2TP = 0x03,
  QMI_WDS_SOFTAP_GET_L2TP = 0x04,
  QMI_WDS_SOFTAP_SET_PPTP = 0x05,
  QMI_WDS_SOFTAP_GET_PPTP = 0x06
}qmi_wds_softap_vpn_req_enum;

typedef enum
{
  QMI_WDS_SOFTAP_SET_NAT_ENTRY_TIMEOUT = 0x01,
  QMI_WDS_SOFTAP_GET_NAT_ENTRY_TIMEOUT = 0x02
} qmi_wds_softap_timeout_req_enum;

typedef enum
{
  QMI_WDS_SOFTAP_ADD_SNAT = 0x01,
  QMI_WDS_SOFTAP_GET_SNAT = 0x02,
  QMI_WDS_SOFTAP_DELETE_SNAT = 0x03
} qmi_wds_softap_snat_req_enum_type;

typedef struct
{
  /* Address should be in host order type */
  unsigned long  private_ip_addr;
  unsigned short private_port;
  unsigned short global_port;
  unsigned char  protocol;
}qmi_wds_softap_snat_config_type;

#define QMI_WDS_SOFTAP_SNAT_CONFIG_PARAM                  0x00000001
#define QMI_WDS_SOFTAP_NUM_AVAILABLE_SNAT_CONFIG_PARAM    0x00000002

typedef struct
{
  int param_mask;

  qmi_wds_softap_snat_req_enum_type  snat_op;

  /*Optional Params: Use param mask to denote validity*/
  unsigned char                   num_available_nats; // should be <= QMI_WDS_MAX_SOFTAP_SNAT_ENTRIES
  qmi_wds_softap_snat_config_type snat_config[QMI_WDS_MAX_SOFTAP_SNAT_ENTRIES];
}qmi_wds_softap_static_nat_config_req_type;


typedef struct
{
  int param_mask;

  /*Optional Params: Use param mask to denote validity*/
  unsigned char                   num_available_nats; // should be <= QMI_WDS_MAX_SOFTAP_SNAT_ENTRIES
  qmi_wds_softap_snat_config_type snat_config[QMI_WDS_MAX_SOFTAP_SNAT_ENTRIES];
}qmi_wds_softap_static_nat_config_resp_type;

//Enumeration for DMZ config
typedef enum
{
  QMI_WDS_SOFTAP_ADD_DMZ = 0x01,
  QMI_WDS_SOFTAP_GET_DMZ = 0x02,
  QMI_WDS_SOFTAP_DELETE_DMZ = 0x03
} qmi_wds_softap_dmz_req_enum;

//Enumeration for WWAN config
typedef enum
{
  QMI_WDS_SOFTAP_V4_ADDR = 0x01,
  QMI_WDS_SOFTAP_V6_ADDR = 0x02,
  QMI_WDS_SOFTAP_V4_DNS_ADDR = 0X03,
  QMI_WDS_SOFTAP_V6_DNS_ADDR = 0X04
} qmi_wds_softap_wwan_addr_req_enum_type;

#define QMI_WDS_SOFTAP_IPADDR_V4_PARAM                          0x00000001
#define QMI_WDS_SOFTAP_IPADDR_V6_PARAM                          0x00000002
#define QMI_WDS_SOFTAP_IPADDR_V4_PRIMARY_DNS_PARAM              0x00000004
#define QMI_WDS_SOFTAP_IPADDR_V4_SECONDARY_DNS_PARAM            0x00000008
#define QMI_WDS_SOFTAP_IPADDR_V6_PRIMARY_DNS_PARAM              0x00000010
#define QMI_WDS_SOFTAP_IPADDR_V6_SECONDARY_DNS_PARAM            0x00000020

typedef struct
{
  int param_mask;

  ipv4_addr_type v4_addr;
  ipv6_addr_type v6_addr;
  ipv4_addr_type v4_prim_dns_addr;
  ipv4_addr_type v4_sec_dns_addr;
  ipv6_addr_type v6_prim_dns_addr;
  ipv6_addr_type v6_sec_dns_addr;

}qmi_wds_softap_wwan_ip_addr_type;

typedef enum
{
  QMI_WDS_SOFTAP_ADD_FIREWALL_RULE = 0x01,
  QMI_WDS_SOFTAP_GET_FIREWALL_RULE = 0x02,
  QMI_WDS_SOFTAP_DELETE_FIREWALL_RULE = 0x03
} qmi_wds_softap_firewall_req_enum_type;

typedef struct {
  unsigned char   prot;
  unsigned short dest_port;
  unsigned short dest_port_range;
} qmi_wds_softap_firewall_filter_spec_type;

/*Param masks used for firewall config request and response*/
#define QMI_WDS_SOFTAP_FIREWALL_CONFIG_FILTER_SPEC_PARAM           0x00000001
#define QMI_WDS_SOFTAP_FIREWALL_CONFIG_FIREWALL_HANDLE_PARAM       0x00000002

typedef struct
{
  int param_mask;

  qmi_wds_softap_firewall_req_enum_type      firewall_config_op;

  /*optional: Use param_mask to denote validity*/
  qmi_wds_softap_firewall_filter_spec_type   filter_spec;
  int                                        firewall_handle;
}qmi_wds_softap_config_firewall_req_type;

typedef struct
{
  int param_mask;

  /*optional: Use param_mask to denote validity*/
  qmi_wds_softap_firewall_filter_spec_type   filter_spec;
  int                                        firewall_handle;
}qmi_wds_softap_config_firewall_resp_type;


/* Distinguishes asynchronous response message types */
typedef enum
{
  QMI_WDS_SRVC_INVALID_ASYNC_RSP_MSG,
  QMI_WDS_SRVC_RESET_ASYNC_RSP_MSG,
  QMI_WDS_SRVC_START_NW_ASYNC_RSP_MSG,
  QMI_WDS_SRVC_STOP_NW_ASYNC_RSP_MSG,
  QMI_WDS_SRVC_ABORT_ASYNC_RSP_MSG,
  QMI_WDS_SOFTAP_INVALID_ASYNC_RSP_MSG,
  QMI_WDS_SOFTAP_BRING_UP_WWAN_ASYNC_RSP_MSG,
  QMI_WDS_SOFTAP_TEAR_DOWN_WWAN_ASYNC_RSP_MSG
} qmi_wds_async_rsp_id_type;

/* Packet service status indication definitions */



/* Indication message ID's */
#define QMI_WDS_EVENT_REPORT_IND_MSG_ID                 0x0001
#define QMI_WDS_PKT_SRVC_STATUS_IND_MSG_ID              0x0022
#define QMI_WDS_INTERNAL_IFACE_EV_REGISTER_IND_MSG_ID   0xFFFE
#define QMI_WDS_INTERNAL_MT_REQ_IND_MSG_ID              0xFFFA
#define QMI_WDS_MCAST_STATUS_IND_MSG_ID                 0x0033
#define QMI_WDS_MBMS_MCAST_CONTEXT_STATUS_IND_MSG_ID    0x003B
#define QMI_WDS_DUN_CALL_INFO_IND_MSG_ID                0x0038
#define QMI_WDS_SOFTAP_WWAN_STATUS_IND_MSG_ID           0x006F
#define QMI_WDS_EMBMS_TMGI_ACTIVATE_IND_MSG_ID          0x0065
#define QMI_WDS_EMBMS_TMGI_DEACTIVATE_IND_MSG_ID        0x0066
#define QMI_WDS_EMBMS_TMGI_LIST_IND_MSG_ID              0x0068




/* Placeholder for any data that might be returned by an asynchronous
** driver call.
*/
typedef union
{
  struct
  {
    unsigned long pkt_data_handle;
    qmi_wds_call_end_reason_type       call_end_reason;
  } start_nw_rsp;

  qmi_wds_softap_wwan_status_type   wwan_status;

} qmi_wds_async_rsp_data_type;


/* WDS service user async callback function prototype.  The callback that is
** registered with any WDS service asynchronous function and will be called
** when the QMI reply is received
*/
typedef  void (*qmi_wds_user_async_cb_type)
(
  int                          user_handle,
  qmi_service_id_type          service_id,
  int                          sys_err_code,
  int                          qmi_err_code,
  void                         *user_data,
  qmi_wds_async_rsp_id_type    rsp_id,
  qmi_wds_async_rsp_data_type  *rsp_data
);

/************************************************************************
* Definitions associated with qmi_wds_set_event_report()
************************************************************************/
#define QMI_WDS_EVENT_CHAN_RATE_IND               0x00000001
#define QMI_WDS_EVENT_XFER_STATS_IND              0x00000002
#define QMI_WDS_EVENT_BEARER_TECH_IND             0x00000004
#define QMI_WDS_EVENT_DORM_STATUS_IND             0x00000008
#define QMI_WDS_EVENT_DATA_CAPABILITIES_IND       0x00000010
#define QMI_WDS_EVENT_DATA_CALL_STATUS_CHG_IND    0x00000020
#define QMI_WDS_EVENT_PREF_DATA_SYS_IND           0x00000040
#define QMI_WDS_EVENT_DATA_CALL_TYPE_IND          0x00000080
#define QMI_WDS_EVENT_DATA_SYS_STATUS_IND         0x00000100





#define QMI_WDS_XFER_STATS_TX_PKTS_GOOD         0x00000001
#define QMI_WDS_XFER_STATS_RX_PKTS_GOOD         0x00000002
#define QMI_WDS_XFER_STATS_TX_PKTS_ERR          0x00000004
#define QMI_WDS_XFER_STATS_RX_PKTS_ERR          0x00000008
#define QMI_WDS_XFER_STATS_TX_OVERFLOW          0x00000010
#define QMI_WDS_XFER_STATS_RX_OVERFLOW          0x00000020
#define QMI_WDS_XFER_STATS_TX_BYTES_OK          0x00000040
#define QMI_WDS_XFER_STATS_RX_BYTES_OK          0x00000080
#define QMI_WDS_XFER_STATS_TX_PACKETS_DROPPED   0x00000100
#define QMI_WDS_XFER_STATS_RX_PACKETS_DROPPED   0x00000200
#define QMI_WDS_XFER_STATS_ALL                  0x000000FF

typedef struct
{
  /* Bitmask which indicates which of the below parameters has been set.  One
  ** or more of QMI_WDS_EVENT_CHAN_RATE_IND, QMI_WDS_EVENT_XFER_STATS_IND,
  ** QMI_WDS_EVENT_BEARER_TECH_IND and QMI_WDS_EVENT_DORM_STATUS_IND
  */
  unsigned long  param_mask;

  /* If QMI_WDS_EVENT_CHAN_RATE_IND is set */
  unsigned char  report_chan_rate;  /* TRUE to turn reporting on, FALSE is off */

  /* If QMI_WDS_EVENT_XFER_STATS_IND is set */
  struct
  {
    unsigned char period; /* report period in seconds, 0 turns off */
    unsigned long mask;   /* Mask of which statistics to report, one or more
                          ** of QMI_WDS_XFER_STATS_TX_PKTS_GOOD,
                          ** QMI_WDS_XFER_STATS_RX_PKTS_GOOD, etc.
                          */
  } report_xfer_stats;

  /* If QMI_WDS_EVENT_BEARER_TECH_IND is set */
  unsigned char report_bearer_tech; /* TRUE to turn reporting on, FALSE is off */

  /* If QMI_WDS_EVENT_DORM_STATUS_IND is set */
  unsigned char report_dorm_status; /* TRUE to turn reporting on, FALSE is off */

  /* If QMI_WDS_EVENT_DATA_CAPABILITIES_IND is set */
  unsigned char report_data_capabilities;

  /* If QMI_WDS_EVENT_DATA_CALL_STATUS_CHG_IND is set */
  unsigned char report_data_call_status_chg;

  /* If QMI_WDS_EVENT_PREF_DATA_SYS_IND is set */
  unsigned char report_pref_data_sys;

  /* If QMI_WDS_EVENT_DATA_SYS_STATUS_IND is set */
  unsigned char report_data_sys_status;

} qmi_wds_event_report_params_type;


/************************************************************************
* Definitions associated with qmi_wds_get_pkt_stats()
************************************************************************/
typedef struct
{
  /* Bitmask that indicates which of the following fields are valid.
  ** One or more of QMI_WDS_XFER_STATS_TX_PKTS_GOOD,
  ** QMI_WDS_XFER_STATS_RX_PKTS_GOOD, etc.
  */
  unsigned long mask;

  unsigned long tx_good_pkt_cnt;
  unsigned long rx_good_pkt_cnt;
  unsigned long tx_err_pkt_cnt;
  unsigned long rx_err_pkt_cnt;
  unsigned long tx_overflow_cnt;
  unsigned long rx_overflow_cnt;
  long long     tx_good_byte_cnt;
  long long     rx_good_byte_cnt;
  unsigned long tx_pkts_dropped;
  unsigned long rx_pkts_dropped;
} qmi_wds_xfer_stats;

/************************************************************************
* Definitions associated with qmi_wds_internal_iface_event_register
************************************************************************/

/*Parame to be used only for Iface events registations request*/
#define QMI_WDS_IFACE_EVENT_REG_OUTAGE_NOTIFICATION                 0x00000001
#define QMI_WDS_IFACE_EVENT_REG_EXTENDED_IP_CONFIG                  0x00000002
#define QMI_WDS_IFACE_EVENT_REG_HDR_REV0_RATE_INERTIA_SUCCESS       0x00000004
#define QMI_WDS_IFACE_EVENT_REG_HDR_REV0_RATE_INERTIA_FAILURE       0x00000008
#define QMI_WDS_IFACE_EVENT_REG_HDR_SLOTTED_MODE_SUCCESS            0x00000010
#define QMI_WDS_IFACE_EVENT_REG_HDR_SLOTTED_MODE_FAILURE            0x00000020
#define QMI_WDS_IFACE_EVENT_REG_HDR_SLOTTED_SESSION_CHANGED         0x00000040
#define QMI_WDS_IFACE_EVENT_REG_RF_CONDITIONS                       0x00000080
#define QMI_WDS_IFACE_EVENT_REG_DOS_ACK_EVENT                       0x00000100

/* Above defines should be used to request
   different event indications*/
typedef unsigned long qmi_wds_iface_event_register_param_type ;

/*Event indication related definitions*/

typedef enum
{
  QMI_WDS_UNKNOWN_TYPE  = 0x00,
  QMI_WDS_CDMA_TYPE     = 0x01,
  QMI_WDS_UMTS_TYPE     = 0x02
} qmi_wds_data_bearer_type;

typedef enum
{
  OUTAGE_NOTIFICATION                     = 0x0001,
  EXTENDED_IP_CONFIG                      = 0x0002,
  HDR_REV0_RATE_INERTIA_SUCCESS           = 0x0003,
  HDR_REV0_RATE_INERTIA_FAILURE           = 0x0004,
  HDR_REV0_SET_EIDLE_SLOTTED_MODE_SUCCESS = 0x0005,
  HDR_REV0_SET_EIDLE_SLOTTED_MODE_FAILURE = 0x0006,
  HDR_REV0_SLOTTED_MODE_SESSION_CHANGED   = 0x0007,
  RF_CONDITIONS_CHANGED                   = 0x0008,
  DOS_ACK_INFORMATION                     = 0x0009
}qmi_wds_iface_event_name;

typedef enum
{
  FAIL    = 0x000,
  SUCCESS = 0x001
}qmi_wds_extended_ip_config_status;

typedef enum
{
  FAIL_REQUEST_REJECTED   = 0x00,
  FAIL_REQUEST_FAILED_TX  = 0x01,
  FAIL_NOT_SUPPORTED      = 0x02,
  FAIL_NO_NET             = 0x03
}qmi_wds_hdr_related_failure_codes;

typedef enum
{
  INVALID    =  0x00,
  BAD        =  0x01,
  GOOD       =  0x02,
  DONT_CARE  =  0x03
}qmi_wds_rf_conditions;


typedef enum
{
  CDMA_DONT_CARE   = 0x00,
  CDMA_1X          = 0x01,
  CDMA_EVDO_REV0   = 0x02,
  CDMA_EVDO_REVA   = 0x04,
  CDMA_EVDO_REVB   = 0x08,
  CDMA_EHRPD       = 0x10,
  CDMA_FMC         = 0x20,
  CDMA_NULL_BEARER = 0x8000
}qmi_wds_cdma_rat_mask;

typedef enum
{
  UMTS_DONT_CARE     = 0x0000,
  UMTS_WCDMA         = 0x0001,
  UMTS_GPRS          = 0x0002,
  UMTS_HSDPA         = 0x0004,
  UMTS_HSUPA         = 0x0008,
  UMTS_EDGE          = 0x0010,
  UMTS_LTE           = 0x0020,
  UMTS_HSDPA_PLUS    = 0x0040,
  UMTS_DC_HSDPA_PLUS = 0x0080,
  UMTS_64_QAM        = 0x0100,
  UMTS_TDSCDMA       = 0x0200,
  UMTS_NULL_BEARER   = 0x8000
}qmi_wds_umts_rat_mask;

typedef union
{
 qmi_wds_cdma_rat_mask   cdma_rat_mask;
 qmi_wds_umts_rat_mask   umts_rat_mask;
}qmi_wds_db_rat_mask;

typedef enum
{
  CDMA_1X_DONT_CARE       = 0x00,
  CDMA_1X_IS95            = 0x01,
  CDMA_1X_IS2000          = 0x02,
  CDMA_1X_IS2000_REL_A    = 0x04
}qmi_wds_cdma_1x_db_so_mask;

typedef enum
{
  CDMA_EVDO_REV0_DONT_CARE = 0x00,
  CDMA_EVDO_REV0_DPA       = 0x01,
}qmi_wds_cdma_evdo_rev0_db_so_mask;

typedef enum
{
  CDMA_EVDO_DONT_CARE       = 0x00,
  CDMA_EVDO_REVA_DONT_CARE  = CDMA_EVDO_DONT_CARE,
  CDMA_EVDO_REVA_DPA        = 0x01,
  CDMA_EVDO_REVA_MFPA       = 0x02,
  CDMA_EVDO_REVA_EMPA       = 0x04,
  CDMA_EVDO_REVA_EMPA_EHRPD = 0x08,
}qmi_wds_cdma_evdo_reva_db_so_mask;

/* Required for legacy uses */
typedef qmi_wds_cdma_evdo_reva_db_so_mask qmi_wds_cdma_evdo_db_so_mask;

typedef enum
{
  CDMA_EVDO_REVB_DONT_CARE  = 0x00,
  CDMA_EVDO_REVB_DPA        = 0x01,
  CDMA_EVDO_REVB_MFPA       = 0x02,
  CDMA_EVDO_REVB_EMPA       = 0x04,
  CDMA_EVDO_REVB_EMPA_EHRPD = 0x08,
  CDMA_EVDO_REVB_MMPA       = 0x10,
  CDMA_EVDO_REVB_MMPA_EHRPD = 0x20
}qmi_wds_cdma_evdo_revb_db_so_mask;

typedef union
{
  int                                so_mask_value;
  qmi_wds_cdma_1x_db_so_mask         so_mask_1x;
  qmi_wds_cdma_evdo_rev0_db_so_mask  so_mask_evdo_rev0;
  qmi_wds_cdma_evdo_db_so_mask       so_mask_evdo;
  qmi_wds_cdma_evdo_reva_db_so_mask  so_mask_evdo_reva;
  qmi_wds_cdma_evdo_revb_db_so_mask  so_mask_evdo_revb;
}qmi_wds_db_so_mask;

/*Masks for the optional TLVs*/

#define QMI_WDS_OUTAGE_INFO_PARAM_TYPE                             0x00000001
#define QMI_WDS_XTENDED_IP_CONFIG_PARAM_TYPE                       0x00000002
#define QMI_WDS_HDR_REV0_INTERTIA_FAILURE_PARAM_TYPE               0x00000004
#define QMI_WDS_HDR_SET_EIDLE_SLOT_MODE_FAIL_PARAM_TYPE            0x00000008
#define QMI_WDS_HDR_SET_EIDLE_SLOT_MODE_SESSION_CHANGED_PARAM_TYPE 0x00000010
#define QMI_WDS_RF_CONDITIONS_PARAM_TYPE                           0x00000020
#define QMI_WDS_DOS_ACK_INFO_PARAM_TYPE                            0x00000040

typedef struct
{
  unsigned long  param_mask;

  qmi_wds_iface_event_name iface_event_name;

  struct
  {
    unsigned long time_to_outage;
    unsigned long duration;
  }outage_information;

  qmi_wds_extended_ip_config_status      extended_ip_config_status;
  qmi_wds_hdr_related_failure_codes      hdr_rev0_rate_inertia_failure_status;
  qmi_wds_hdr_related_failure_codes      hdr_set_eidle_slottedmode_failure_status;
  unsigned char                          hdr_set_eidle_slot_cycle_changed;

  struct
  {
    qmi_wds_data_bearer_type       current_db_nw;
    qmi_wds_db_rat_mask            rat_mask;
    qmi_wds_db_so_mask             db_so_mask;
    qmi_wds_rf_conditions          rf_conditions;
  }rf_conditions;

  struct
  {
    int handle;
    unsigned long overflow;
    unsigned long dos_ack_status;
  }dos_ack_information;

}qmi_wds_internal_iface_event_ind_data_type;


/************************************************************************
* Definitions associated with qmi_wds_start_nw_if()
************************************************************************/
/* Technology preference parameter */
#define QMI_WDS_TECH_PREF_UMTS                     0x01
#define QMI_WDS_TECH_PREF_CDMA                     0x02
#define QMI_WDS_TECH_PREF_DVBH                     0x04
#define QMI_WDS_TECH_PREF_MBMS                     0x08
#define QMI_WDS_TECH_PREF_BCMCS                    0x10
#define QMI_WDS_TECH_PREF_SLIP                     0x20

/* MAKE SURE TO UPDATE IF TECHNOLOGY PREFERENCES ARE ADDED !!! */
#define QMI_WDS_TECH_PREF_ALL ( QMI_WDS_TECH_PREF_UMTS | \
                                QMI_WDS_TECH_PREF_CDMA | \
                                QMI_WDS_TECH_PREF_DVBH | \
                                QMI_WDS_TECH_PREF_MBMS | \
                                QMI_WDS_TECH_PREF_BCMCS | \
                                QMI_WDS_TECH_PREF_SLIP )

#define QMI_WDS_START_NW_TECH_3GPP       QMI_WDS_TECH_PREF_UMTS
#define QMI_WDS_START_NW_TECH_3GPP2      QMI_WDS_TECH_PREF_CDMA
#define QMI_WDS_START_NW_TECH_ALL_TECHS  QMI_WDS_TECH_PREF_ALL

/* Deprecated, use qmi_ip_family_pref_type directly */
#define qmi_wds_ip_family_pref_type        qmi_ip_family_pref_type
#define QMI_WDS_IP_FAMILY_PREF_ANY         QMI_IP_FAMILY_PREF_ANY
#define QMI_WDS_IP_FAMILY_PREF_IPV4        QMI_IP_FAMILY_PREF_IPV4
#define QMI_WDS_IP_FAMILY_PREF_IPV6        QMI_IP_FAMILY_PREF_IPV6
#define QMI_WDS_IP_FAMILY_PREF_UNSPECIFIED QMI_IP_FAMILY_PREF_UNSPECIFIED

typedef enum
{
  QMI_WDS_DATA_CALL_ORIGIN_LAPTOP       = 0x00,
  QMI_WDS_DATA_CALL_ORIGIN_EMBEDDED     = 0x01
}qmi_wds_data_call_origin_type;

/* Parameter indication bits */
#define QMI_WDS_START_NW_TECH_PREF_PARAM                      0x00000001
#define QMI_WDS_START_NW_PROFILE_IDX_PARAM                    0x00000002
#define QMI_WDS_START_NW_APN_NAME_PARAM                       0x00000004
#define QMI_WDS_START_NW_IP_FAMILY_PREF_PARAM                 0x00000008
#define QMI_WDS_START_NW_PRIM_DNS_IPV4_ADDR_PREF_PARAM        0x00000010
#define QMI_WDS_START_NW_SECONDRY_DNS_IPV4_ADDR_PREF_PARAM    0x00000020
#define QMI_WDS_START_NW_PRIMARY_NBNS_ADDR_PREF_PARAM         0x00000040
#define QMI_WDS_START_NW_SECONDARY_NBNS_ADDR_PREF_PARAM       0x00000080
#define QMI_WDS_START_NW_IPV4_ADDR_PREF_PARAM                 0x00000100
#define QMI_WDS_START_NW_USERNAME_PARAM                       0x00000200
#define QMI_WDS_START_NW_PASSWORD_PARAM                       0x00000400
#define QMI_WDS_START_NW_AUTH_PREF_PARAM                      0x00000800
#define QMI_WDS_START_NW_IFACE_HNDL_PARAM                     0x00001000
#define QMI_WDS_START_NW_PROFILE_IDX_3GPP2_PARAM              0x00002000
#define QMI_WDS_START_NW_XTENDED_TECH_PREF_PARAM              0x00004000
#define QMI_WDS_START_NW_DATA_CALL_ORIGIN_PARAM               0x00008000

/* Authentication option values */
typedef enum
{
  QMI_WDS_AUTH_PREF_PAP_CHAP_NOT_ALLOWED  = 0x00,
  QMI_WDS_AUTH_PREF_PAP_ONLY_ALLOWED      = 0x01,
  QMI_WDS_AUTH_PREF_CHAP_ONLY_ALLOWED     = 0x02,
  QMI_WDS_AUTH_PREF_PAP_CHAP_BOTH_ALLOWED = 0x03
} qmi_wds_auth_pref_type;

typedef enum
{
  INTERFACE_LOOKUP  = 1,
  DATAPATH_LOOKUP   = 2
}qmi_wds_route_lookup_type;

/* this maps with ps iface name */
typedef enum
{
  QMI_WDS_IFACE_NAME_CDMA             = 0x8001,
  QMI_WDS_IFACE_NAME_UTMS             = 0x8004,/* typo of name */
  /* correct name, keep it backward compatible */
  QMI_WDS_IFACE_NAME_UMTS             = QMI_WDS_IFACE_NAME_UTMS,
  QMI_WDS_IFACE_NAME_EMBMS            = 0x8882,
  QMI_WDS_IFACE_NAME_MODEM_LINK_LOCAL = 0x8888,
  QMI_WDS_IFACE_NAME_NOT_REPORTED     = 0xFFFF
} qmi_wds_iface_name_type;

/* Tech Type maps to PS iface name */		
typedef qmi_wds_iface_name_type qmi_wds_technology_type;

/* Parameter structure for start network interface command */
typedef struct
{
  /* Bitmask which indicates which of the below
  ** parameters has been set
  */
  /*Mandatory only valid for route lookup*/
  qmi_wds_route_lookup_type               route_lookup;

  unsigned long params_mask;

  /* Parameters, more will be added later */
  unsigned char                     profile_index;
  unsigned char                     tech_pref;
  qmi_wds_iface_name_type           xtended_tech_pref;
  unsigned char                     profile_index_3gpp2;
  qmi_ip_family_pref_type           ip_family_pref;
  char                              apn_name[QMI_WDS_MAX_APN_STR_SIZE];
  unsigned long                     primary_dns_ip4_addr_pref;
  unsigned long                     secondar_dns_ip4_addr_pref;
  unsigned long                     primary_nbns_addr_pref;
  unsigned long                     secondary_nbns_addr_pref;
  unsigned long                     ipv4_addr_pref;
  char                              username[QMI_WDS_MAX_USERNAME_PASS_STR_SIZE];
  char                              password[QMI_WDS_MAX_USERNAME_PASS_STR_SIZE];
  qmi_wds_auth_pref_type            auth_pref;
  unsigned long                     iface_handle;
  qmi_wds_data_call_origin_type     data_call_origin;
} qmi_wds_start_nw_if_params_type;

/* Parameters for route lookup... note these are just a subset of
** the start NW IF parameters and are just aliased.  Also note that if
** you add any, they must be added to the route lookup valid params define
** below
*/
#define QMI_WDS_ROUTE_LOOK_UP_TECH_PREF_PARAM          QMI_WDS_START_NW_XTENDED_TECH_PREF_PARAM
#define QMI_WDS_ROUTE_LOOK_UP_PROFILE_IDX_PARAM        QMI_WDS_START_NW_PROFILE_IDX_PARAM
#define QMI_WDS_ROUTE_LOOK_UP_IP_FAMILY_PREF_PARAM     QMI_WDS_START_NW_IP_FAMILY_PREF_PARAM
#define QMI_WDS_ROUTE_LOOK_UP_APN_NAME_PARAM           QMI_WDS_START_NW_APN_NAME_PARAM


typedef qmi_wds_start_nw_if_params_type qmi_wds_route_look_up_params_type;

typedef struct qmi_wds_route_look_up_rsp
{
  unsigned long iface_handle;
  unsigned long             priority;
  qmi_wds_iface_name_type   tech_name;
  unsigned char             qmi_inst_is_valid; /* TRUE if qmi_inst is valid, FALSE if not */
  unsigned char             qmi_inst;

} qmi_wds_route_look_up_rsp_type;

/************************************************************************
* Definitions associated with profile related functions
************************************************************************/



/* QOS related enums and structure */
/* Traffic class enum */
typedef enum
{
  QMI_WDS_TC_SUBSCRIBED = 0,
  QMI_WDS_TC_CONVERSATIONAL = 1,
  QMI_WDS_TC_STREAMING = 2,
  QMI_WDS_TC_INTERACTIVE = 3,
  QMI_WDS_TC_BACKGROUND = 4
} qmi_wds_traffic_class_type;

/* Delivery order enum */
typedef enum
{
  QMI_WDS_DO_SUBSCRIBED = 0,
  QMI_WDS_DO_ON = 1,
  QMI_WDS_DO_OFF = 2
}qmi_wds_qos_delivery_order_type;

/* SDU error ratio values */
typedef enum
{
  QMI_WDS_SDU_ERR_RATIO_SUBSCRIBE = 0,
  QMI_WDS_SDU_ERR_RATIO_1ENEG2    = 1,
  QMI_WDS_SDU_ERR_RATIO_7ENEG3    = 2,
  QMI_WDS_SDU_ERR_RATIO_1ENEG3    = 3,
  QMI_WDS_SDU_ERR_RATIO_1ENEG4    = 4,
  QMI_WDS_SDU_ERR_RATIO_1ENEG5    = 5,
  QMI_WDS_SDU_ERR_RATIO_1ENEG6    = 6,
  QMI_WDS_SDU_ERR_RATIO_1ENEG1    = 7
} qmi_wds_sdu_err_ratio_type;

/* BER values */
typedef enum
{
  QMI_WDS_RESIDUAL_BER_SUBSCRIBE = 0,
  QMI_WDS_RESIDUAL_BER_5ENEG2     = 1,
  QMI_WDS_RESIDUAL_BER_1ENEG2     = 2,
  QMI_WDS_RESIDUAL_BER_5ENEG3     = 3,
  QMI_WDS_RESIDUAL_BER_4ENEG3     = 4,
  QMI_WDS_RESIDUAL_BER_1ENEG3     = 5,
  QMI_WDS_RESIDUAL_BER_1ENEG4     = 6,
  QMI_WDS_RESIDUAL_BER_1ENEG5     = 7,
  QMI_WDS_RESIDUAL_BER_1ENEG6     = 8,
  QMI_WDS_RESIDUAL_BER_6ENEG8     = 9
} qmi_wds_residual_ber_ratio_type;


/* Delivery err SDU values */
typedef enum
{
  QMI_WDS_DELIVER_ERR_SDU_SUBSCRIBE  = 0,
  QMI_WDS_DELIVER_ERR_SDU_NO_DETECT  = 1,
  QMI_WDS_DELIVER_ERR_SDU_DELIVER    = 2,
  QMI_WDS_DELIVER_ERR_SDU_NO_DELIVER = 3
} qmi_wds_deliver_err_sdu_type;

typedef enum
{
  QMI_WDS_FALSE   = 0x00,
  QMI_WDS_TRUE    = 0x01
}qmi_wds_bool_type;

/* UMTS QOS params structure */
typedef struct
{
  qmi_wds_traffic_class_type          traffic_class;
  unsigned long                       max_ul_bitrate;
  unsigned long                       max_dl_bitrate;
  unsigned long                       guaranteed_ul_bitrate;
  unsigned long                       guaranteed_dl_bitrate;
  qmi_wds_qos_delivery_order_type     qos_delivery_order;
  unsigned long                       max_sdu_size;
  qmi_wds_sdu_err_ratio_type          sdu_error_ratio;
  qmi_wds_residual_ber_ratio_type     residual_ber_ratio;
  qmi_wds_deliver_err_sdu_type        deliver_error_sdu;
  unsigned long                       transfer_delay;
  unsigned long                       traffic_handling_prio;
  qmi_wds_bool_type                   signal_indication; //field valid only for umts_qos with signal indication
} qmi_wds_umts_qos_params_type;


/* GPRS QOS params structure */
typedef struct
{
  unsigned long precedence_class;
  unsigned long delay_class;
  unsigned long reliability_class;
  unsigned long peak_throughput_class;
  unsigned long mean_throughput_class;
} qmi_wds_gprs_qos_params_type;


/* PDP type */
typedef enum
{
  QMI_WDS_PDP_TYPE_IP = 0x00,
  QMI_WDS_PDP_TYPE_IPV4 = QMI_WDS_PDP_TYPE_IP,
  QMI_WDS_PDP_TYPE_IPV6 = 0x02,
  QMI_WDS_PDP_TYPE_IPV4V6 = 0x03
} qmi_wds_pdp_type;

/* PDP type */
typedef enum
{
  QMI_WDS_PCSCF_ADDR_VIA_PCO_DISABLED = 0,
  QMI_WDS_PCSCF_ADDR_VIA_PCO_ENABLED = 1
} qmi_wds_pcscf_via_pco_type;

typedef enum
{
  QMI_WDS_IPV4_TYPE = 0x04,
  QMI_WDS_IPV6_TYPE = 0x06
}qmi_wds_ip_family;

typedef enum
{
  CN_FLAG_TRUE  = 0x01,
  CN_FLAG_FALSE = 0x00
}qmi_wds_cn_flag_true_false;

typedef struct
{
  /*Long aligned on word boundary,
    short aligned on 2byte boundary
    char aligned on byte boundary*/
  unsigned long             ipsec_param_index;
  unsigned long             flow_lable;
  unsigned short            destination_port_range_start;
  unsigned short            destination_port_range_end;
  unsigned short            source_port_range_start;
  unsigned short            source_port_range_end;
  unsigned short            tos_mask;
  ipv6_addr_type            source_ip; //If ipv4 fill only 1st 4 bytes
  unsigned char             ip_family; //4 - IPV4 , 6 - IPV6
  unsigned char             source_ip_mask;
  unsigned char             next_header;
  unsigned char             filter_id;
  unsigned char             eval_id;
}qmi_wds_tft_params_type;


#define QMI_WDS_UMTS_PROFILE_NAME_PARAM_MASK                            0x00000001 /* profile_name */
#define QMI_WDS_UMTS_PROFILE_PDP_TYPE_PARAM_MASK                        0x00000002 /* pdp_type */
#define QMI_WDS_UMTS_PROFILE_APN_NAME_PARAM_MASK                        0x00000004 /* apn_name */
#define QMI_WDS_UMTS_PROFILE_PRIM_DNS_PARAM_MASK                        0x00000008 /* primary_dns_pref_addr*/
#define QMI_WDS_UMTS_PROFILE_SEC_DNS_PARAM_MASK                         0x00000010 /* secondary_dns_pref_addr*/
#define QMI_WDS_UMTS_PROFILE_UMTS_REQ_QOS_PARAM_MASK                    0x00000020 /* umts_requested_qos*/
#define QMI_WDS_UMTS_PROFILE_UMTS_MIN_QOS_PARAM_MASK                    0x00000040 /* umts_minimum_qos*/
#define QMI_WDS_UMTS_PROFILE_GPRS_REQ_QOS_PARAM_MASK                    0x00000080 /* umts_requested_qos*/
#define QMI_WDS_UMTS_PROFILE_GPRS_MIN_QOS_PARAM_MASK                    0x00000100 /* umts_minimum_qos*/
#define QMI_WDS_UMTS_PROFILE_USERNAME_PARAM_MASK                        0x00000200 /* username*/
#define QMI_WDS_UMTS_PROFILE_PASSWORD_PARAM_MASK                        0x00000400 /* password*/
#define QMI_WDS_UMTS_PROFILE_AUTH_PREF_PARAM_MASK                       0x00000800 /* auth_pref*/
#define QMI_WDS_UMTS_PROFILE_IPV4_ADDR_PREF_PARAM_MASK                  0x00001000 /* ipv4_pref_addr*/
#define QMI_WDS_UMTS_PROFILE_PCSCF_ADDR_VIA_PCO_PARAM_MASK              0x00002000 /* pcscf_addr_via_pco*/
#define QMI_WDS_UMTS_PROFILE_HEADER_COMPRESSION_PARAM_MASK              0x00004000
#define QMI_WDS_UMTS_PROFILE_DATA_COMPRESSION_PARAM_MASK                0x00008000
#define QMI_WDS_UMTS_PROFILE_PDP_ACCESS_CONTROL_PARAM_MASK              0x00010000
#define QMI_WDS_UMTS_PROFILE_PCSCF_VIA_DHCP_PARAM_MASK                  0x00020000
#define QMI_WDS_UMTS_PROFILE_IM_CN_FLAG_PARAM_MASK                      0x00040000
#define QMI_WDS_UMTS_PROFILE_TFT_FILTER_ID_1_PARAM_MASK                 0x00080000
#define QMI_WDS_UMTS_PROFILE_TFT_FILTER_ID_2_PARAM_MASK                 0x00100000
#define QMI_WDS_UMTS_PROFILE_PDP_CONTEXT_NUMBER_PARAM_MASK              0x00200000
#define QMI_WDS_UMTS_PROFILE_PDP_CONTEXT_SECONDARY_PARAM_MASK           0x00400000
#define QMI_WDS_UMTS_PROFILE_PDP_PRIMARY_ID_PARAM_MASK                  0x00800000
#define QMI_WDS_UMTS_PROFILE_UMTS_REQ_QOS_EXT_PARAM_MASK                0x01000000
#define QMI_WDS_UMTS_PROFILE_UMTS_MIN_QOS_EXT_PARAM_MASK                0x02000000
#define QMI_WDS_UMTS_PROFILE_PRIMARY_DNS_IPV6_ADDR_PREF_PARAM_MASK      0x04000000
#define QMI_WDS_UMTS_PROFILE_SECONDARY_DNS_IPV6_ADDR_PREF_PARAM_MASK    0x08000000
#define QMI_WDS_UMTS_PROFILE_IPV6_ADDR_PREF_PARAM_MASK                  0x10000000
#define QMI_WDS_UMTS_PROFILE_IS_PERSISTENT_PARAM_MASK                   0x20000000

/* Profile information */
typedef struct
{

  /* bit mask which indicates which of the below parameter fields
  ** contain valid values
  */
  unsigned long                 param_mask;

  /* All parameters are optional, and their inclusion/validity
  ** is indicated by set bit in param_mask
  */
  char                          profile_name[QMI_WDS_MAX_PROFILE_STR_SIZE];
  qmi_wds_pdp_type              pdp_type;
  char                          apn_name[QMI_WDS_MAX_APN_STR_SIZE];
  unsigned long                 primary_dns_pref_addr;
  unsigned long                 secondary_dns_pref_addr;
  qmi_wds_umts_qos_params_type  umts_requested_qos;
  qmi_wds_umts_qos_params_type  umts_minimum_qos;
  qmi_wds_gprs_qos_params_type  gprs_requested_qos;
  qmi_wds_gprs_qos_params_type  gprs_minimum_qos;
  char                          username[QMI_WDS_MAX_USERNAME_PASS_STR_SIZE];
  char                          password[QMI_WDS_MAX_USERNAME_PASS_STR_SIZE];
  qmi_wds_auth_pref_type        auth_pref;
  unsigned long                 ipv4_pref_addr;
  qmi_wds_pcscf_via_pco_type    pcscf_addr_via_pco;

  unsigned char                 header_compression;
  unsigned char                 data_compression;
  unsigned char                 pdp_access_control;
  unsigned char                 pcscf_via_dhcp;
  unsigned char                 im_cn_flag;
  qmi_wds_tft_params_type       tft_filter_id_1;
  qmi_wds_tft_params_type       tft_filter_id_2;
  unsigned char                 pdp_context_number;
  unsigned char                 pdp_context_secondary;
  unsigned char                 pdp_context_primary_id_number;
  ipv6_addr_type                ipv6_addr_pref;
  qmi_wds_umts_qos_params_type  umts_minimum_qos_sig_ind;
  qmi_wds_umts_qos_params_type  umts_requested_qos_sig_ind;
  ipv6_addr_type                primary_dns_ipv6_addr_pref;
  ipv6_addr_type                secondary_dns_ipv6_addr_pref;
  qmi_wds_bool_type             is_persistent;
} qmi_wds_umts_profile_params_type;


typedef enum
{
  QMI_WDS_LOW_SO15              = 0x00,
  QMI_WDS_MED_SO33_LOW_RSCH     = 0x01,
  QMI_WDS_HIGH_SO33_HIGH_RSCH   = 0x02
}qmi_wds_cdma_data_rate_type;

typedef enum
{
  QMI_WDS_CDMA_HYBRID_EVDO      =  0x00,
  QMI_WDS_CDMA_ONLY             =  0x01,
  QMI_WDS_HDR_ONLY              =  0x02
}qmi_wds_cdma_data_mode_type;


typedef enum
{
  QMI_WDS_CDMA_DEFAULT_APP   =   0x00000001,
  QMI_WDS_CDMA_LBS_APP       =   0x00000020,
  QMI_WDS_CDMA_TETHERED_APP  =   0x00000040
}qmi_wds_cdma_app_type;

typedef enum
{
  QMI_WDS_IPV4_PDN_TYPE          =   0x00,
  QMI_WDS_IPV6_PDN_TYPE          =   0x01,
  QMI_WDS_IPV4_OR_IPV6_PDN_TYPE  =   0x02,
  QMI_WDS_UNSPECIFIED_PDN_TYPE   =   0x03  // No preference in PDN type
}qmi_wds_cdma_pdn_type;

typedef enum
{
  QMI_WDS_RAT_HRPD_TYPE        = 0x01,
  QMI_WDS_RAT_EHRPD_TYPE       = 0x02,
  QMI_WDS_RAT_HRPD_EHRPD_TYPE  = 0x03
}qmi_wds_cdma_rat_type;


#define QMI_WDS_CDMA_PROFILE_DNS_SERVER_PREF_PARAM_MASK                   0x00000001
#define QMI_WDS_CDMA_PROFILE_PPP_SESSION_CLOSE_TIMER_DO_PARAM_MASK        0x00000002
#define QMI_WDS_CDMA_PROFILE_PPP_SESSION_CLOSE_TIMER_1X_PARAM_MASK        0x00000004
#define QMI_WDS_CDMA_PROFILE_ALLOW_LINGER_PARAM_MASK                      0x00000008
#define QMI_WDS_CDMA_PROFILE_LCP_ACK_TIMEOUT_PARAM_MASK                   0x00000010
#define QMI_WDS_CDMA_PROFILE_AUTH_TIMEOUT_PARAM_MASK                      0x00000020
#define QMI_WDS_CDMA_PROFILE_LCP_CONFIG_RETRY_RECOUNT_PARAM_MASK          0x00000040
#define QMI_WDS_CDMA_PROFILE_AUTH_RETRY_RECOUNT_PARAM_MASK                0x00000080
#define QMI_WDS_CDMA_PROFILE_AUTH_PROTOCOL_PARAM_MASK                     0x00000100
#define QMI_WDS_CDMA_PROFILE_USERNAME_PARAM_MASK                          0x00000200
#define QMI_WDS_CDMA_PROFILE_PASSWORD_PARAM_MASK                          0x00000400
#define QMI_WDS_CDMA_PROFILE_DATA_RATE_PARAM_MASK                         0x00000800
#define QMI_WDS_CDMA_PROFILE_DATA_MODE_PARAM_MASK                         0x00001000
#define QMI_WDS_CDMA_PROFILE_APP_TYPE_PARAM_MASK                          0x00002000
#define QMI_WDS_CDMA_PROFILE_APP_PRIORITY_PARAM_MASK                      0x00004000
#define QMI_WDS_CDMA_PROFILE_APN_STRING_PARAM_MASK                        0x00008000
#define QMI_WDS_CDMA_PROFILE_PDN_TYPE_PARAM_MASK                          0x00010000
#define QMI_WDS_CDMA_PROFILE_IS_PCSCF_ADDR_NEEDED_PARAM_MASK              0x00020000
#define QMI_WDS_CDMA_PROFILE_PRIM_V4_DNS_ADDR_PARAM_MASK                  0x00040000
#define QMI_WDS_CDMA_PROFILE_SEC_V4_DNS_ADDR_PARAM_MASK                   0x00080000
#define QMI_WDS_CDMA_PROFILE_PRIM_V6_DNS_ADDR_PARAM_MASK                  0x00100000
#define QMI_WDS_CDMA_PROFILE_SEC_V6_DNS_ADDR_PARAM_MASK                   0x00200000
#define QMI_WDS_CDMA_PROFILE_IPCP_ACK_TIMEOUT_PARAM_MASK                  0x00400000
#define QMI_WDS_CDMA_PROFILE_IPCP_CONFIG_RETRY_RECOUNT_PARAM_MASK         0x00800000
#define QMI_WDS_CDMA_PROFILE_RAT_TYPE_PARAM_MASK                          0x01000000
#define QMI_WDS_CDMA_PROFILE_IS_PERSISTENT_PARAM_MASK                     0x02000000


typedef struct
{
  /* bit mask which indicates which of the below parameter fields
  ** contain valid values
  */
  unsigned long                 param_mask;

  qmi_wds_bool_type             dns_server_pref;
  unsigned long                 ppp_session_close_timer_do;
  unsigned long                 ppp_session_close_timer_1x;
  unsigned char                 allow_linger;
  unsigned short                lcp_ack_timeout;
  unsigned short                ipcp_ack_timeout;
  unsigned short                auth_timeout;
  unsigned char                 lcp_config_req_retry_count;
  unsigned char                 ipcp_config_req_retry_count;
  unsigned char                 auth_retry_count;
  qmi_wds_auth_pref_type        auth_protocol;
  char                          username[QMI_WDS_MAX_USERNAME_PASS_STR_SIZE];
  char                          password[QMI_WDS_MAX_USERNAME_PASS_STR_SIZE];
  qmi_wds_cdma_data_rate_type   data_rate;
  qmi_wds_cdma_data_mode_type   data_mode;
  qmi_wds_cdma_app_type         app_type;   // Cannot be used for modification;
                                            // Is only used to search profiles with the specified app type.
  unsigned char                 app_priority; // Cannot be used for modification
  char                          apn_name[QMI_WDS_MAX_APN_STR_SIZE];
  qmi_wds_cdma_pdn_type         pdn_type;
  qmi_wds_bool_type             is_pcscf_addr_needed;
  unsigned long                 primary_dns_ipv4_pref_addr;
  unsigned long                 secondary_dns_ipv4_pref_addr;
  ipv6_addr_type                primary_dns_ipv6_addr_pref;
  ipv6_addr_type                secondary_dns_ipv6_addr_pref;
  qmi_wds_cdma_rat_type         rat_type;
  qmi_wds_bool_type             is_persistent;
}qmi_wds_cdma_profile_params_type;


typedef union
{
  qmi_wds_umts_profile_params_type   umts_profile_params;
  qmi_wds_cdma_profile_params_type   cdma_profile_params;
} qmi_wds_profile_params_type;

typedef enum
{
  QMI_WDS_PROFILE_PARAM_ID_MIN  = 0x17,
  QMI_WDS_UMTS_REQ_QOS          = QMI_WDS_PROFILE_PARAM_ID_MIN,
  QMI_WDS_UMTS_MIN_QOS          = 0x18,
  QMI_WDS_GPRS_REQ_QOS          = 0x19,
  QMI_WDS_GPRS_MIN_QOS          = 0x1A,
  QMI_WDS_TFT_FILTER_ID_1       = 0x23,
  QMI_WDS_TFT_FILTER_ID_2       = 0x24,
  QMI_WDS_PROFILE_PARAM_ID_MAX  = QMI_WDS_TFT_FILTER_ID_2
}qmi_wds_reset_profile_param_type;

typedef enum
{
  QMI_WDS_PROFILE_SOCKETS_FAMILY  = 0x00,
  QMI_WDS_PROFILE_ATCOP_FAMILY    = 0x01,
  QMI_WDS_PROFILE_RMNET_FAMILY    = QMI_WDS_PROFILE_ATCOP_FAMILY
}qmi_wds_profile_family;


/************************************************************************
* Definitions associated with qmi_wds_start_nw_if()
************************************************************************/

#define QMI_WDS_GET_CURR_CALL_INFO_PROFILE_ID_PARAM_MASK              (1<<0)
#define QMI_WDS_GET_CURR_CALL_INFO_PROFILE_NAME_PARAM_MASK            (1<<1)
#define QMI_WDS_GET_CURR_CALL_INFO_PDP_TYPE_PARAM_MASK                (1<<2)
#define QMI_WDS_GET_CURR_CALL_INFO_APN_NAME_PARAM_MASK                (1<<3)
#define QMI_WDS_GET_CURR_CALL_INFO_DNS_ADDR_PARAM_MASK                (1<<4)
#define QMI_WDS_GET_CURR_CALL_INFO_UMTS_GPRS_GRNTD_QOS_PARAM_MASK     (1<<5)
#define QMI_WDS_GET_CURR_CALL_INFO_USERNAME_PARAM_MASK                (1<<6)
#define QMI_WDS_GET_CURR_CALL_INFO_AUTH_PROTOCOL_PARAM_MASK           (1<<7)
#define QMI_WDS_GET_CURR_CALL_INFO_IP_ADDRESS_PARAM_MASK              (1<<8)
#define QMI_WDS_GET_CURR_CALL_INFO_GATEWAY_INFO_PARAM_MASK            (1<<9)
#define QMI_WDS_GET_CURR_CALL_INFO_PCSCF_ADDR_USING_PCO_PARAM_MASK    (1<<10)
#define QMI_WDS_GET_CURR_CALL_INFO_PCSCF_SERV_ADDR_PARAM_MASK         (1<<11)
#define QMI_WDS_GET_CURR_CALL_INFO_PCSCF_DOMAIN_NAME_LIST_PARAM_MASK  (1<<12)
#define QMI_WDS_GET_CURR_CALL_INFO_MTU_PARAM_MASK                     (1<<13)
#define QMI_WDS_GET_CURR_CALL_INFO_DOMAIN_NAME_LIST_PARAM_MASK        (1<<14)
#define QMI_WDS_GET_CURR_CALL_INFO_IP_FAMILY_PARAM_MASK               (1<<15)
#define QMI_WDS_GET_CURR_CALL_INFO_IM_CN_FLAG_PARAM_MASK              (1<<16)
#define QMI_WDS_GET_CURR_CALL_INFO_TECHNOLOGY_NAME_PARAM_MASK         (1<<17)

typedef unsigned long       qmi_wds_req_runtime_settings_params_type ; /* Set this
                                                                          Param type to any of the above
                                                                          Params for the request*/

/* Profile ID structure */
typedef struct
{
  unsigned long              valid_data_read;
  qmi_wds_profile_tech_type  technology;
  unsigned long              profile_index;
} qmi_wds_profile_id_type;

/************************************************************************
* Definitions associated with QMI_WDS_GET_SESSION_SETTINGS
************************************************************************/
#define QMI_WDS_CURR_CALL_INFO_IPV4_GATEWAY_ADDR       0x00000001 /* gateway address         */
#define QMI_WDS_CURR_CALL_INFO_SUBNET_MASK             0x00000002 /* subnet mask             */
#define QMI_WDS_CURR_CALL_INFO_PCSCF_ADDR_USNG_PCO     0x00000004
#define QMI_WDS_CURR_CALL_INFO_PCSCF_IPV4_ADDR_LIST    0x00000008
#define QMI_WDS_CURR_CALL_INFO_PCSCF_FQDN_LIST         0x00000010
#define QMI_WDS_CURR_CALL_INFO_IPV6_ADDR               0x00000020
#define QMI_WDS_CURR_CALL_INFO_IPV6_GTWY_ADDR          0x00000040
#define QMI_WDS_CURR_CALL_INFO_PRIMARY_DNS_IPV6_ADDR   0x00000080
#define QMI_WDS_CURR_CALL_INFO_MTU                     0x00000100
#define QMI_WDS_CURR_CALL_INFO_DOMAIN_NAME_LIST        0x00000200
#define QMI_WDS_CURR_CALL_INFO_IP_FAMILY               0x00000400
#define QMI_WDS_CURR_CALL_INFO_IM_CN_FLAG              0x00000800
#define QMI_WDS_CURR_CALL_INFO_TECHNOLOGY              0x00001000
#define QMI_WDS_CURR_CALL_INFO_IPV4_ADDR               0x00002000
#define QMI_WDS_CURR_CALL_INFO_PRIMARY_DNS_IPV4_ADDR   0x00004000
#define QMI_WDS_CURR_CALL_INFO_SECONDARY_DNS_IPV4_ADDR 0x00008000
#define QMI_WDS_CURR_CALL_INFO_SECONDARY_DNS_IPV6_ADDR 0x00010000
#define QMI_WDS_CURR_CALL_INFO_PCSCF_IPV6_ADDR_LIST    0x00020000

typedef struct
{
  int                         fqdn_length;
  unsigned char               fqdn_string[QMI_WDS_MAX_PROFILE_STR_SIZE];
}qmi_wds_fqdn_strings;

typedef struct
{
  int                  domain_name_len;
  unsigned char        domain_name[QMI_WDS_MAX_PROFILE_STR_SIZE];
}qmi_wds_domain_names;

typedef struct
{
  ipv6_addr_type                 ipv6_addr;
  int                            ipv6_prefix_len;
}qmi_ipv6_addr_type;


/* Run-time settings information */
typedef struct
{

  /* bit mask which indicates which of the below fields
  ** contain valid values.  Use above QMI_WDS_CALL_SETTINGS mask values
  */
  unsigned long                 mask;

  /* All values are optional, and their validity
  ** is indicated by set bit in param_mask
  */
  ipv4_addr_type                 ipv4_addr;
  ipv4_addr_type                 primary_dns_ipv4_addr;
  ipv4_addr_type                 secondary_dns_ipv4_addr;
  ipv4_addr_type                 ipv4_gateway_addr;
  ipv4_addr_type                 ipv4_subnet_mask;
  unsigned char                  p_cscf_addr_using_pco;

  struct
  {
    unsigned char num_instances;
    ipv4_addr_type p_cscf_ipv4_addr[QMI_WDS_MAX_P_CSCF_IPV4_ADDRS];
  }p_cscf_ipv4_addrs;

  struct
  {
    unsigned char num_instances;
    ipv6_addr_type p_cscf_ipv6_addr[QMI_WDS_MAX_P_CSCF_IPV6_ADDRS];
  }p_cscf_ipv6_addrs;

  struct
  {
    unsigned char num_instances;
    qmi_wds_fqdn_strings   fqdn_strings[QMI_WDS_MAX_FQDN_STRINGS];
  }fqdn_list;

  qmi_ipv6_addr_type               ipv6_addr_info;
  qmi_ipv6_addr_type               ipv6_gateway_addr_info;
  ipv6_addr_type                   primary_dns_ipv6_addr;
  ipv6_addr_type                   secondary_dns_ipv6_addr;
  unsigned long                    mtu;

  struct
  {
    unsigned char num_instances;
    qmi_wds_domain_names domain_names[QMI_WDS_MAX_DOMAIN_NAMES];
  }domain_name_list;

  qmi_wds_ip_family               ip_family;
  qmi_wds_cn_flag_true_false      im_cn_flag;
  qmi_wds_iface_name_type         curr_technology;
} qmi_wds_curr_call_info_type;

/************************************************************************
* Definitions associated with QMI_WDS_GET_CURRENT_SESSION_SETTINGS
************************************************************************/

#define QMI_WDS_REQ_INTERNAL_SETTINGS_PARAM           0x00000001
#define QMI_WDS_REQ_SESSION_TIMER_SELECT_PARAM        0x00000002
#define QMI_WDS_REQ_SDB_FLAGS_PARAM                   0x00000004

/* Parameter structure for requesting current runtime settings*/
typedef enum
{
  SESSION_TIMER_DO         =  0x01,
  SESSION_TIMER_1X         =  0x02,
  SESSION_TIMER_1X_AND_DO  =  0x03
}qmi_wds_session_timer_select;

typedef enum
{
  QMI_MSG_EXPEDITE         = 0x00000001,
  QMI_MSG_FAST_EXPEDITE    = 0x00000002
}qmi_wds_req_sdb_flags;

#define QMI_WDS_RUNTIME_SETTINGS_RF_CONDITIONS_REQ_PARAM                  (1<<0) //0x00000001
#define QMI_WDS_RUNTIME_SETTINGS_DORM_TIMER_1X_REQ_PARAM                  (1<<1) //0x00000002
#define QMI_WDS_RUNTIME_SETTINGS_SESSION_TIMER_1X_REQ_PARAM               (1<<2) //0x00000004
#define QMI_WDS_RUNTIME_SETTINGS_HANDDOWN_OPT_HDR_1X_REQ_PARAM            (1<<3) //0x00000008
#define QMI_WDS_RUNTIME_SETTINGS_HYSTERISIS_ACT_TIMER_REQ_PARAM           (1<<4) //0x00000010
#define QMI_WDS_RUNTIME_SETTINGS_HDR_EIDLE_SLOTTED_MODE_OPT_REQ_PARAM     (1<<5) //0x00000020
#define QMI_WDS_RUNTIME_SETTINGS_SDB_SUPPORT_REQ_PARAM                    (1<<6) //0x00000040

typedef struct
{
  /* Bitmask which indicates which of the below
  ** parameters has been set
  */
  unsigned long params_mask;

  unsigned long                 req_internal_settings;
  qmi_wds_session_timer_select  timer_info;
  qmi_wds_req_sdb_flags         sdb_flags;

}qmi_wds_internal_runtime_setings_params_type;

typedef struct
{
  unsigned char bit_number;
  int           dss_errno;
}qmi_wds_operation_failure_param_type;

typedef enum
{
  HDR_OPTION_TRUE  = 0x00,
  HDR_OPTION_FALSE = 0x01
}qmi_wds_hdr_handdown_option_1x;

typedef enum
{
  SDB_SUPPORT_TRUE  = 0x00,
  SDB_SUPPORT_FALSE = 0x01
}qmi_wds_sdb_support;

/*MASK defines for both get and set internal runtime settings*/
#define QMI_WDS_RUNTIME_SETTINGS_RSP_OP_FAILURE                  0x00000001
#define QMI_WDS_RUNTIME_SETTINGS_DORM_TIMER_1X                   0x00000002
#define QMI_WDS_RUNTIME_SETTINGS_SESSION_TIMER_1X                0x00000004
#define QMI_WDS_RUNTIME_SETTINGS_HANDDOWN_OPT_HDR_1X             0x00000008
#define QMI_WDS_RUNTIME_SETTINGS_HYSTERISIS_ACT_TIMER            0x00000010
#define QMI_WDS_RUNTIME_SETTINGS_SDB_SUPPORT                     0x00000020
#define QMI_WDS_RUNTIME_SETTINGS_RF_CONDITIONS                   0x00000040
#define QMI_WDS_RUNTIME_SETTINGS_HDR_EIDLE_SLOTTED_MODE_OPT      0x00000080


typedef struct
{
  /* Bitmask which indicates which of the below
  ** parameters has been set
  */
  unsigned long                             params_mask;
  struct
  {
    unsigned char                           num_instances;
    qmi_wds_operation_failure_param_type    failure_info[QMI_WDS_MAX_ERR_CODES_IN_RSP];
  }op_failure_info;

  unsigned long                    dorm_timer_for_1x;
  int                              session_timer_for_1x;
  qmi_wds_hdr_handdown_option_1x   hdr_handdown_option;
  unsigned long                    hysteresis_activation_timer;
  qmi_wds_sdb_support              sdb_support;

  struct
  {
    qmi_wds_data_bearer_type       current_db_nw;
    qmi_wds_db_rat_mask            rat_mask;
    qmi_wds_db_so_mask             db_so_mask;
    qmi_wds_rf_conditions          rf_conditions;
  }rf_conditions;

  unsigned long   hdr_eidle_slot_cycle_value;

}qmi_wds_internal_runtime_settings_rsp_type;

/************************************************************************
* Definitions associated with QMI_WDS_SET_INTERNAL_RUNTIME_SETTINGS
************************************************************************/
#define QMI_WDS_SET_INTERNAL_RUNTIME_1X_DORM_TIMER_PARAM                  0x00000001
#define QMI_WDS_SET_INTERNAL_RUNTIME_1X_SESSION_TIMER_PARAM               0x00000002
#define QMI_WDS_SET_INTERNAL_RUNTIME_HDR_1X_HANDDOWN_OPT_PARAM            0x00000004
#define QMI_WDS_SET_INTERNAL_RUNTIME_HYSTERISIS_ACTIVATION_TIMER_PARAM    0x00000008
#define QMI_WDS_SET_INTERNAL_RUNTIME_ENABLE_HOLDDOWN_PARAM                0x00000010
#define QMI_WDS_SET_INTERNAL_RUNTIME_ENABLE_HDR_HPT_MODE_PARAM            0x00000020
#define QMI_WDS_SET_INTERNAL_RUNTIME_ENABLE_REV0_RATE_INERTIA_PARAM       0x00000040
#define QMI_WDS_SET_INTERNAL_RUNTIME_HDR_SLOTTED_MODE_PARAM               0x00000080

typedef enum
{
  DISABLE  = 0x00,
  ENABLE   = 0x01
}qmi_wds_enable_disable;

typedef qmi_wds_enable_disable  qmi_wds_enable_holdown;

typedef qmi_wds_enable_holdown qmi_wds_enable_hdr_hpt_mode;
typedef qmi_wds_enable_holdown qmi_wds_enable_hdr_rev0_rate_inertia;

typedef struct
{

   /* Bitmask which indicates which of the below
  ** parameters has been set
  */
  unsigned long                         params_mask;

  qmi_wds_enable_holdown                holddown_enable;
  unsigned long                         dorm_timer_for_1x;

  struct
  {
    qmi_wds_session_timer_select        timer_select;
    int                                 timer_value;
  }session_timer_1x;

  qmi_wds_hdr_handdown_option_1x        hdr_handdown_option;
  unsigned long                         hysteresis_activation_timer;

  qmi_wds_enable_hdr_hpt_mode           hdr_htp_mode_enable;
  qmi_wds_enable_hdr_rev0_rate_inertia  hdr_rev0_rate_inertia_enable;
  unsigned long                         slot_cycle_value;

}qmi_wds_set_internal_runtime_settings_params_type;

/*TODO: duplicating this again, discuss*/
typedef struct
{
  unsigned char tlv_type;
  int           dss_errno;
}qmi_wds_operation_failure;

typedef struct
{
   /* Bitmask which indicates which of the below
  ** parameters has been set
  */
  unsigned long                         params_mask;

  struct
  {
    unsigned char                       num_failures;
    qmi_wds_operation_failure           op_failure[QMI_WDS_MAX_ERR_CODES_IN_RSP];
  }op_failures;
}qmi_wds_set_internal_runtime_settings_rsp_type;

/************************************************************************
* Definitions associated with QMI_WDS_MT_DEREG_CB_REQ
* and MT_CALL_REG_INDICATIONS
************************************************************************/

#define QMI_WDS_MT_REG_CB_IP_FAMILY_PARAM                  0x00000001
#define QMI_WDS_MT_REG_CB_PROFILE_INDEX_PARAM              0x00000002
#define QMI_WDS_MT_REG_CB_TECH_PREF_PARAM                  0x00000004


/*req */

typedef struct
{
  unsigned long                 params_mask;

  qmi_ip_family_pref_type       ip_family;
  unsigned char                 profile_index;
  qmi_wds_iface_name_type       xtended_tech_pref;
}qmi_wds_reg_mob_term_call_req_params;

/*resp */

typedef int             qmi_wds_dss_errno;
typedef unsigned long   mob_terminated_packet_handle;

typedef struct
{
  mob_terminated_packet_handle              pkt_hndl;
  qmi_wds_dss_errno                         dss_errno;
}qmi_wds_reg_mob_terminated_call_rsp_type;


/*DE REGISTER RSP DATA TYPE*/

#define QMI_WDS_EXTENDED_ERROR_INFO_PARAM       0x0001

typedef struct
{
  unsigned short          param_mask;
  qmi_wds_dss_errno       dss_errno;
}qmi_wds_dss_errno_type;

typedef qmi_wds_dss_errno_type      qmi_wds_de_reg_mob_terminated_call_rsp_type;
typedef qmi_wds_dss_errno_type      qmi_wds_bcmcs_db_updt_rsp_type;
typedef qmi_wds_dss_errno_type      qmi_wds_initiate_mcast_reg_ex_rsp_type;
typedef qmi_wds_dss_errno_type      qmi_wds_bcmcs_enable_handoff_reg_rsp_type;
typedef qmi_wds_dss_errno_type      qmi_wds_bcmcs_bom_caching_setup_rsp_type;
typedef qmi_wds_dss_errno_type      qmi_wds_initiate_mcast_leave_ex_rsp_type;

/************************************************************************
* Definitions associated with qmi_wds_bcmcs_db_update_req
************************************************************************/
typedef enum
{
  ZONE_1x  = 0x00,
  ZONE_HDR = 0x01
}qmi_wds_dsbcmcs_zone_type;

typedef qmi_wds_ip_family  multicast_ip_family;

typedef enum
{
  FRAMING_SEGMENT     =  0x00,
  FRAMING_HDLC        =  0x01
}qmi_wds_bcmcs_framing_type;

typedef enum
{
  BCMCS_PPP     =  0x00,
  BCMCS_IPV4    =  0x01,
  BCMCS_IPV6    =  0x02
}qmi_wds_bcmcs_protocol_type;

typedef enum
{
  BCMCS_OVERWRITE       = 0x00,
  BCMCS_DONT_OVERWRITE  = 0x01
}qmi_wds_bcmcs_overwrite;

typedef union
{
  ipv4_addr_type     ipv4;
  ipv6_addr_type     ipv6;
}qmi_wds_ipv4_ipv6_addr_type;


typedef struct
{
  qmi_wds_dsbcmcs_zone_type        zone_type;
  unsigned char                    subnet_hdr[16];
  multicast_ip_family              ip_family;
  qmi_wds_ipv4_ipv6_addr_type      ip_addr;

  unsigned long                    prog_id;
  unsigned char                    prog_id_len;
  unsigned char                    flow_discrim_len;
  unsigned char                    flow_discrim;
  unsigned short                   port;
  qmi_wds_bcmcs_framing_type       frame_type;
  qmi_wds_bcmcs_protocol_type      protocol_type;
  unsigned char                    crc_length;
  unsigned char                    flow_format;
  unsigned long                    flow_id;
  qmi_wds_bcmcs_overwrite          overwrite;
  unsigned char                    flow_priority;
}qmi_wds_bcmcs_db_updt_params_type;




/************************************************************************
* Definitions associated with qmi_wds_bcmcs_enbl_handoff_reg_req
************************************************************************/

typedef struct
{
  multicast_ip_family              ip_family;
  qmi_wds_ipv4_ipv6_addr_type      ip_addr;
  unsigned short                   mcast_port;
}qmi_wds_mcast_ip_port_info;

typedef struct
{
  unsigned char                 num_mcast_addr;  /*value cannot be more than 25 */
  qmi_wds_mcast_ip_port_info    ip_info[QMI_WDS_MAX_MCAST_ADDRS];
}qmi_wds_bcmcs_handoff_optimization_info;

/************************************************************************
* Definitions associated with qmi_wds_bcmcs_bom_caching_setup_req
************************************************************************/

typedef enum
{
  BOM_ENABLE  = 0x00,
  BOM_DISABLE = 0x01
}qmi_wds_enbl_dsbl_bom;

typedef struct
{
  qmi_wds_enbl_dsbl_bom       bom_enbl_dsbl;
  unsigned char               bom_cache_timeout;
}qmi_wds_bom_caching_setup_req_param_type;

/************************************************************************
* Definitions associated with QMI_WDS_INITIATE_MCAST_JOIN_EX
* (bundled multicast ip addr's version)
************************************************************************/
/* Req Related */
typedef enum
{
  MCAST_REG_SETUP_ALLOWED       = 0x00000000,
  MCAST_REG_SETUP_NOT_ALLOWED   = 0x00000001
}qmi_wds_mcast_req_config_flag;

typedef struct
{
  qmi_wds_mcast_ip_port_info        mcast_ip_info;
  qmi_wds_mcast_req_config_flag     config_flag;
}qmi_wds_mcast_ip_port_config_info;

typedef struct
{
  unsigned char                         num_flows;
  qmi_wds_mcast_ip_port_config_info     ip_info[QMI_WDS_MAX_MCAST_ADDRS];/*TODO:Max instances ? FIND OUT*/
}qmi_wds_mcast_join_req_params_type;

/* Rsp Related */

typedef struct
{
  unsigned char               num_handles;
  unsigned long               mcast_handle_list[QMI_WDS_MAX_MCAST_HNDLS];
}qmi_wds_mcast_hndl_list_type;

typedef struct
{

  qmi_wds_mcast_hndl_list_type    hndl_list;
  qmi_wds_dss_errno_type          dss_errno;
}qmi_wds_initiate_mcast_join_ex_rsp_type;

/************************************************************************
* Definitions associated with QMI_WDS_INITIATE_MCAST_JOIN
************************************************************************/

#define QMI_WDS_MCAST_JOIN_IPV4_ADDR_INFO_PARAM                  0x00000001
#define QMI_WDS_MCAST_JOIN_MBMS_SPECIFIC_JOIN_INFO_PARAM         0x00000002

typedef enum
{
  BROADCAST_SERVICE_METHOD = 0x00,
  MULTICAST_SERVICE_METHOD = 0x01
}qmi_wds_mbms_service_method;

typedef enum
{
  STREAMING_SERVICE_TYPE = 0x00,
  DOWNLOAD_SERVICE_TYPE  = 0x01
}qmi_wds_mbms_service_type;

typedef struct
{
  unsigned long                     params_mask;

  struct
  {
    unsigned long       mcast_ip_addr;
    unsigned short      mcast_port;
  }mcast_ip_addr_info;

  struct
  {
    unsigned char                   tmgi[8];//What is this ?
    unsigned char                   session_start_timer[8];
    unsigned char                   session_end_timer[8];
    int                             priority;
    qmi_wds_mbms_service_method     service_method;
    qmi_wds_mbms_service_type       service_type;
    qmi_wds_bool_type               selected_service;
    qmi_wds_bool_type               service_security;
  }mbms_specific_join_info;
}qmi_wds_mcast_ipv4_join_info_param_type;

/*resp*/
typedef unsigned long     qmi_wds_mcast_hndl_rsp_type;
/*MCAST LEAVE*/
typedef unsigned long     qmi_wds_mcast_hndl_param_type;


/************************************************************************
* Definitions associated with qmi_wds_initiate_mbms_context_activate
************************************************************************/
/* Req Related */
#define QMI_WDS_IPV4_CONTEXT_ACTIVATION_INFO_PARAM              0x00000001

typedef struct
{
  unsigned long param_mask;
  struct
  {
    ipv4_addr_type      multicast_ip_addr;/*Addr to join Mcast*/
    unsigned char       profile_id;
  }ipv4_context_activate_info;
}qmi_wds_mbms_context_req_params_type;

/*Resp Related*/
typedef unsigned long           qmi_wds_mbms_context_handle;

/************************************************************************
* Definitions associated with qmi_wds_get_profile_list()
************************************************************************/
typedef struct
{
  qmi_wds_profile_tech_type   profile_type;
  unsigned long               profile_index;
  char                        profile_name[QMI_WDS_MAX_PROFILE_STR_SIZE];
} qmi_wds_profile_list_type;


/************************************************************************
* Definitions associated with asyncronous indications
************************************************************************/

typedef enum
{
  QMI_WDS_PACKET_DATA_DISCONNECTED    = 0x01,
  QMI_WDS_PACKET_DATA_CONNECTED       = 0x02,
  QMI_WDS_PACKET_DATA_SUSPENDED       = 0x03,
  QMI_WDS_PACKET_DATA_AUTHENTICATING  = 0x04
} qmi_wds_link_status_type;

#define QMI_WDS_PKT_SRVC_IND_CALL_END_REASON      0x0001
#define QMI_WDS_PKT_SRVC_IND_IP_FAMILY            0x0002
#define QMI_WDS_PKT_SRVC_IND_TECH_NAME            0x0004

typedef struct
{
  unsigned short                param_mask; //mask to denote validity of call_end_reason;

  qmi_wds_link_status_type      link_status;
  unsigned char                 reconfig_required; /* TRUE if reconfig required, FALSE otherwise */
  qmi_wds_call_end_reason_type  call_end_reason;
  qmi_ip_family_pref_type       ip_family;
  qmi_wds_iface_name_type       tech_name;
} qmi_wds_pkt_srvc_status_type;

/************************************************************************
* Definitions associated with TMGI Status indications
************************************************************************/
#define QMI_WDS_EMBMS_TMGI_SIZE   6
#define QMI_WDS_EMBMS_TMGI_STATUS_IND_LIST_SIZE 1

typedef enum
{
  QMI_WDS_EMBMS_TMGI_ACTIVATE_SUCCESS                  = 0x00000000,
  QMI_WDS_EMBMS_TMGI_ACTIVATE_FAIL_RADIO_CONFIG        = 0x00010000,
  QMI_WDS_EMBMS_TMGI_ACTIVATE_FAIL_CHANNEL_UNAVAILABLE = 0x00010001,
  QMI_WDS_EMBMS_TMGI_ACTIVATE_FAIL_EMBMS_NOT_ENABLED   = 0x00010002,
  QMI_WDS_EMBMS_TMGI_ACTIVATE_FAIL_OUT_OF_COVERAGE     = 0x00010003,
}qmi_wds_embms_tmgi_activate_status_type;

typedef enum
{
  QMI_WDS_EMBMS_TMGI_DEACTIVATE_SUCCESS  = 0x00000000
}qmi_wds_embms_tmgi_deactivate_status_type;

typedef struct
{
  unsigned char                tmgi[QMI_WDS_EMBMS_TMGI_SIZE];
  unsigned char                session_id_valid;
  unsigned char                session_id;
}qmi_wds_embms_tmgi_type;

typedef enum
{
  QMI_WDS_EMBMS_TMGI_DEACTIVATED_TYPE_INVALID                      = -1,
  QMI_WDS_EMBMS_TMGI_DEACTIVATED_TYPE_DEACTIVATION_IN_PROGRESS     = 0x000000CB,
  QMI_WDS_EMBMS_TMGI_DEACTIVATED_TYPE_NOT_SUPPORT                  = 0x0000006C,
  QMI_WDS_EMBMS_TMGI_DEACTIVATED_TYPE_TMGI_NOT_ACTIVATE            = 0x0000007C,
  QMI_WDS_EMBMS_TMGI_DEACTIVATED_REASON_UNSPECIFIED                = 0x00000000,
  QMI_WDS_EMBMS_TMGI_DEACTIVATED_REASON_ACT_FAIL_RADIO_CONFIG      = 0x00010000,
  QMI_WDS_EMBMS_TMGI_DEACTIVATED_REASON_ACT_FAIL_CHANNEL_UNAVAIL   = 0x00010001,
  QMI_WDS_EMBMS_TMGI_DEACTIVATED_REASON_ACT_FAIL_EMBMS_NOT_ENABLED = 0x00010002,
  QMI_WDS_EMBMS_TMGI_DEACTIVATED_REASON_ACT_FAIL_OUT_OF_COVERAGE   = 0x00010003,
  QMI_WDS_EMBMS_TMGI_DEACTIVATED_REASON_CLIENT_INIT_DEACTIVATION   = 0x00020000,
  QMI_WDS_EMBMS_TMGI_DEACTIVATED_REASON_SESSION_END                = 0x00030000,
  QMI_WDS_EMBMS_TMGI_DEACTIVATED_REASON_LTE_STOPPED                = 0x00030001,
  QMI_WDS_EMBMS_TMGI_DEACTIVATED_REASON_EMBMS_DISABLED             = 0x00030002,
  QMI_WDS_EMBMS_TMGI_DEACTIVATED_REASON_OUT_OF_COVERAGE            = 0x00030003
}qmi_wds_embms_tmgi_deactivate_reason_type ;

typedef struct
{
  qmi_wds_embms_tmgi_activate_status_type  active_status;
  unsigned char                            tmgi_list_len;
  qmi_wds_embms_tmgi_type                  *tmgi_list_ptr;
}qmi_wds_embms_tmgi_activate_status_ind_type;


typedef struct
{
  qmi_wds_embms_tmgi_deactivate_status_type  deactive_status;
  unsigned char                              tmgi_list_len;
  qmi_wds_embms_tmgi_type                    *tmgi_list_ptr;
}qmi_wds_embms_tmgi_deactivate_status_ind_type;

/************************************************************************
* Definitions associated with TMGI list indications
************************************************************************/
typedef enum
{
  QMI_WDS_EMBMS_TMGI_LIST_INVALID   = -1,
  QMI_WDS_EMBMS_TMGI_LIST_ACTIVE    = 0x00,
  QMI_WDS_EMBMS_TMGI_LIST_AVAILABLE = 0x01
}qmi_wds_embms_tmgi_list_type;

#define QMI_WDS_EMBMS_LIST_IND_TMGI_LIST_PARAM_MASK 0x01

typedef struct
{
  unsigned short                       param_mask;

  qmi_wds_embms_tmgi_list_type         list_type;
  unsigned char                        tmgi_list_len;
  qmi_wds_embms_tmgi_type              *tmgi_list_ptr;
}qmi_wds_embms_tmgi_list_ind_type;

/* The following structure is also used for qmi_wds_get_current_bearer_tech()*/

typedef struct
{
  qmi_wds_data_bearer_type       current_db_nw;
  qmi_wds_db_rat_mask            rat_mask;
  qmi_wds_db_so_mask             db_so_mask;
} qmi_wds_data_bearer_tech_type;

/* Event report indication definitions */

/* Following bitmasks are used for event report data_capabilities field */
/* Following are for data_capabilities[0] */
#define QMI_WDS_EVENT_REPORT_DATA_CAPABILITY_0_FMC             0x00000001
#define QMI_WDS_EVENT_REPORT_DATA_CAPABILITY_0_CDMA_1X         0x00000002
#define QMI_WDS_EVENT_REPORT_DATA_CAPABILITY_0_EVDO_REV_0      0x00000004
#define QMI_WDS_EVENT_REPORT_DATA_CAPABILITY_0_EVDO_REV_A      0x00000008
#define QMI_WDS_EVENT_REPORT_DATA_CAPABILITY_0_EVDO_REV_B      0x00000010
#define QMI_WDS_EVENT_REPORT_DATA_CAPABILITY_0_NULL_BEARER     0x00000020

/* Following are for data_capabilities[1] (none defined yet) */


typedef enum
{
  QMI_WDS_DORM_STATUS_DORMANT = 1,
  QMI_WDS_DORM_STATUS_ACTIVE  = 2
} qmi_wds_dorm_status_type;

typedef enum
{
  QMI_WDS_DATA_CALL_ACTIVATED  = 1,
  QMI_WDS_DATA_CALL_TERMINATED = 2
} qmi_wds_data_call_status_type;

typedef enum
{
  QMI_WDS_DATA_SYS_UNKNOWN = 0,
  QMI_WDS_DATA_SYS_CDMA_1X = 1,
  QMI_WDS_DATA_SYS_EVDO    = 2,
  QMI_WDS_DATA_SYS_GPRS    = 3,
  QMI_WDS_DATA_SYS_WCDMA   = 4,
  QMI_WDS_DATA_SYS_LTE     = 5
} qmi_wds_pref_data_sys_type;

typedef enum
{
  QMI_WDS_DATA_CALL_TYPE_INVALID  = 0,
  QMI_WDS_DATA_CALL_TYPE_EMBEDDED = 1,
  QMI_WDS_DATA_CALL_TYPE_TETHERED = 2
} qmi_wds_data_call_type_type;

typedef enum
{
  QMI_WDS_TETHERED_CALL_TYPE_INVALID = 0,
  QMI_WDS_TETHERED_CALL_TYPE_RMNET   = 1,
  QMI_WDS_TETHERED_CALL_TYPE_DUN     = 2
} qmi_wds_tethered_call_type_type;


/* QMI_WDS_EVENT_DATA_SYS_STATUS_IND related defines */
typedef enum
{
  QMI_WDS_DATA_NETWORK_TYPE_INVALID = -1,
  QMI_WDS_DATA_NETWORK_TYPE_3GPP    = 0,
  QMI_WDS_DATA_NETWORK_TYPE_3GPP2   = 1
} qmi_wds_data_network_type;

typedef struct
{
  qmi_wds_data_network_type  network;
  qmi_wds_db_rat_mask        rat_mask;
  qmi_wds_db_so_mask         db_so_mask;
} qmi_wds_data_sys_status_network_info_type;

typedef struct
{
  qmi_wds_data_network_type                  pref_network;
  qmi_wds_data_sys_status_network_info_type  *network_info;
  unsigned int                               network_info_len;
} qmi_wds_data_sys_status_type;

/* Event reporting indication structure definition */
typedef struct
{
  /* Bitmask that inicates which of the following event fields contain valid
  ** data.  One or more of QMI_WDS_EVENT_CHAN_RATE_IND,
  ** QMI_WDS_EVENT_XFER_STATS_IND, QMI_WDS_EVENT_BEARER_TECH_IND
  ** and QMI_WDS_EVENT_DORM_STATUS_IND
  */
  unsigned long event_mask;

  /* If QMI_WDS_EVENT_CHAN_RATE_IND is set in event_mask */
  struct
  {
    unsigned long tx_curr_channel_rate;
    unsigned long rx_curr_channel_rate;
  } chan_rate;

  /* If QMI_WDS_EVENT_XFER_STATS_IND is set in event_mask */
  struct
  {
    /* Bitmask that indicates which of the following fields are valid.
    ** One or more of QMI_WDS_XFER_STATS_TX_PKTS_GOOD,
    ** QMI_WDS_XFER_STATS_RX_PKTS_GOOD, etc.
    */
    unsigned long mask;

    unsigned long tx_good_pkt_cnt;
    unsigned long rx_good_pkt_cnt;
    unsigned long tx_err_pkt_cnt;
    unsigned long rx_err_pkt_cnt;
    unsigned long tx_overflow_cnt;
    unsigned long rx_overflow_cnt;
    long long     tx_good_byte_cnt;
    long long     rx_good_byte_cnt;
    unsigned long tx_pkts_dropped;
    unsigned long rx_pkts_dropped;
  } xfer_stats;

  qmi_wds_data_bearer_tech_type   data_bearer_tech_type;
  /* If QMI_WDS_EVENT_DORM_STATUS_IND is set in event_mask */
  qmi_wds_dorm_status_type dorm_status;

  /* 64-bits of data capabilities */
  unsigned long data_capabilities[2];

  /* IFACE name (reported when data capabilities are enabled) */
  qmi_wds_iface_name_type         iface_name;

  /* Valid if QMI_WDS_EVENT_DATA_CALL_STATUS_CHG_IND bit is set */
  qmi_wds_data_call_status_type   data_call_status;

  /* Valid if QMI_WDS_EVENT_PREF_DATA_SYS_IND bit is set */
  qmi_wds_pref_data_sys_type      pref_data_sys;

  /* Valid if QMI_WDS_EVENT_DATA_CALL_TYPE_IND bit is set */
  struct
  {
    qmi_wds_data_call_type_type       data_call_type;
    qmi_wds_tethered_call_type_type   tethered_call_type;
  } data_call_type;

  /* Valid if QMI_WDS_EVENT_DATA_SYS_STATUS_IND bit is set */
  qmi_wds_data_sys_status_type    data_sys_status;

} qmi_wds_event_report_type;


/* Distinguishes indication message types */
typedef enum
{
  QMI_WDS_SRVC_INVALID_IND_MSG,
  QMI_WDS_SRVC_PKT_SRVC_STATUS_IND_MSG,
  QMI_WDS_SRVC_EVENT_REPORT_IND_MSG,
  QMI_WDS_SRVC_INTERNAL_IFACE_EVNT_REG_MSG,
  QMI_WDS_SRVC_MT_REQUEST_IND_MSG,
  QMI_WDS_SRVC_MCAST_STATUS_IND_MSG,
  QMI_WDS_SRVC_MBMS_MCAST_CONTEXT_STATUS_IND_MSG,
  QMI_WDS_SRVC_DUN_CALL_INFO_IND_MSG,
  QMI_WDS_SRVC_SOFTAP_WWAN_STATUS_IND_MSG,
  QMI_WDS_SRVC_EMBMS_TMGI_ACTIVATE_IND_MSG,
  QMI_WDS_SRVC_EMBMS_TMGI_DEACTIVATE_IND_MSG,
  QMI_WDS_SRVC_EMBMS_TMGI_LIST_IND_MSG
} qmi_wds_indication_id_type;

/*Mcast Status Related*/
#define QMI_WDS_MCAST_REASON_CODE_PARAM      0x00000001

typedef enum
{
  QMI_WDS_MCAST_REGISTER_SUCCESS    = 0x01,
  QMI_WDS_MCAST_REGISTER_FAILURE    = 0x02,
  QMI_WDS_MCAST_DEREGISTERED        = 0x03,
  QMI_WDS_MCAST_STATUS_EX           = 0x04
} qmi_wds_mcast_status;

typedef enum
{
  IC_NOT_SPECIFIED                                = 0,
  /*bcmcs related*/
  BCMCS_FLOW_STATUS_CANCELLED                     = 100,
  BCMCS_FLOW_STATUS_UNABLE_TO_MONITOR             = 300,
  BCMCS_FLOW_STATUS_REQUESTED                     = 301,
  BCMCS_FLOW_STATUS_TIMEOUT                       = 302,
  BCMCS_FLOW_STATUS_LOST                          = 303,
  BCMCS_FLOW_STATUS_SYS_UNAVAILABLE               = 304,
  BCMCS_FLOW_STATUS_AN_REJECT_NOT_AVAILABLE       = 400,
  BCMCS_FLOW_STATUS_AN_REJECT_NOT_TRANSMITTED     = 401,
  BCMCS_FLOW_STATUS_AN_REJECT_INVALID_AUTH_SIG    = 402,
  BCMCS_FLOW_STATUS_UNAVAILABLE                   = 500,
  BCMCS_FLOW_STATUS_NO_MAPPING                    = 501,
  BCMCS_FLOW_STATUS_ID_NOT_FOUND_FOR_GIVEN_MULTICAST_IP = 502,
  BCMCS_MAX_FLOWS_REACHED                         = 503,
  BCMCS_MAX_DEPRECATED_INFO_CODE                  = 504,

  BCMCS_JOIN_REQ_IN_PROGRESS                      = 613,
  BCMCS_FLOW_REQUEST_SENT                         = 614,
  BCMCS_FLOW_STATUS_MAX_MONITORED_FLOWS           = 615,
  BCMCS_FLOW_STATUS_MONITORED                     = 616,
  BCMCS_REGISTRATION_SUCCESS                      = 617,
  BCMCS_REGISTRATION_NOT_ALLOWED                  = 618,
  BCMCS_REGISTRATION_FAILED                       = 619,
  BCMCS_FLOW_DEREGISTERED                         = 620,

  /*bcmcs2po related*/
  BCMCS2P0_FLOW_STATUS_CANCELLED                  = 600,
  BCMCS2P0_FLOW_STATUS_UNABLE_TO_MONITOR          = 601,
  BCMCS2P0_FLOW_STATUS_TIMEOUT                    = 602,
  BCMCS2P0_FLOW_STATUS_LOST                       = 603,
  BCMCS2p0_FLOW_STATUS_SYS_UNAVAILABLE            = 604,
  BCMCS2P0_FLOW_STATUS_UNAVAILABLE                = 605,
  BCMCS2P0_FLOW_STATUS_AN_REJECT_NOT_AVAILABLE    = 606,
  BCMCS2P0_FLOW_STATUS_AN_REJECT_NOT_TRANSMITTED  = 607,
  BCMCS2P0_FLOW_STATUS_AN_REJECT_INVALID_AUTH_SIG = 608,
  BCMCS2P0_FLOW_STATUS_NO_MAPPING                 = 609,
  BCMCS2P0_FLOW_STATUS_ID_NOT_FOUND_FOR_GIVEN_MULTICAST_IP  = 610,
  BCMCS2P0_FLOW_STATUS_REQUESTED                  = 611,
  BCMCS2P0_MAX_FLOWS_REACHED                      = 612,

  FLO_IP_OR_PORT_NOT_SUPPORTED                    = 1051,
  FLO_NO_AUTHORIZATION                            = 1052,
  FLO_NO_SYSTEM_COVERAGE                          = 1053,
  FLO_MAX_FLOW_REACHED                            = 1054,

  /*DVBH related*/
  DVBH_IP_OR_PORT_NOT_FOUND                       = 1101,
  DVBH_SYSTEM_UNAVAILABLE                         = 1102,
  DVBH_BAD_REQUEST                                = 1103,
  DVBH_REQUEST_CONFLICT                           = 1104,
  DVBH_DUP_REQUEST                                = 1105,
  DVBH_MAX_FLOWS_REACHED                          = 1106

}qmi_wds_mcast_info_reason_code;/*No Description available, TODO: change name accordingly*/

typedef struct
{

  unsigned long param_mask;

  struct
  {
    unsigned long         mcast_handle;
    qmi_wds_mcast_status  mcast_status;
  }multicast_status;

  qmi_wds_mcast_info_reason_code  reason_code;

}qmi_wds_mcast_status_ind_type;

#define QMI_WDS_MBMS_MCAST_REASON_CODE_PARAM      0x00000001

typedef enum
{
  MBMS_MCAST_CONTEXT_ACTIVATE_SUCCESS     = 0x01,
  MBMS_MCAST_CONTEXT_ACTIVATE_FAILURE     = 0x02,
  MBMS_MCAST_CONTEXT_DEACTIVATE_SUCCESS   = 0x03,
  MBMS_MCAST_CONTEXT_DEACTIVATE_FAILURE   = 0x04
}qmi_wds_mbms_mcast_status;

typedef enum
{
  MBMS_SYSTEM_UNAVAILABLE = 1151
}qmi_wds_mbms_mcast_reason_code;

typedef struct
{
  unsigned long param_mask;

  qmi_wds_mbms_mcast_status        mcast_status;
  /*optional*/
  qmi_wds_mbms_mcast_reason_code   reason_code;
}qmi_wds_mbms_mcast_context_status_type;

typedef mob_terminated_packet_handle    qmi_wds_mob_terminated_packet_handle;


/************************************************************************
* Definitions associated with qmi_wds_get_dun_call_info and
* corresponding indication
************************************************************************/

/* Bit definitions for curr_info_mask fields
** below.  More will be added later
*/
#define QMI_WDS_DUN_CURR_CONN_STATUS              0x00000001
#define QMI_WDS_DUN_CURR_TX_RX_BYTE_COUNT         0x00000004

/* Bit definitions for ind_info_mask fields
** below.  More will be added later
*/
#define QMI_WDS_DUN_CALL_INFO_CONN_STATUS_IND_PARAM_MASK      0x00000001
#define QMI_WDS_DUN_CALL_INFO_TX_RX_STATS_IND_PARAM_MASK      0x00000002

#define QMI_WDS_DUN_IND_TX_STATS_MASK  0x00000040
#define QMI_WDS_DUN_IND_RX_STATS_MASK  0x00000080

/* qmi_wds_get_dun_call_info input/output structure */
typedef struct
{
  /* Mask of current DUN call info to retrieve */
  unsigned long curr_info_mask;

  /* Each bit in the id_info_mask corresponds to one of the
  ** fields below it in this structure.  If the bit is set,
  ** the field must be correctly initialized.  Each of these
  ** fields instructs QMI about which items should be reported
  ** in the DUN indication message
  */
  unsigned long ind_info_mask;

  /* Indication fields */
  unsigned char conn_status_rpt; /* boolean, 0 for off, 1 for on */
  struct
  {
    unsigned long stats_mask;   /*QMI_WDS_DUN_IND_TX_STATS_MASK, QMI_WDS_DUN_IND_RX_STATS_MASK*/
    unsigned char stats_period; /*0 - Do not report, >0 - interval between stats report(in seconds) */
  }tx_rx_stats_rpt;
  /* More will be added later... */

} qmi_wds_dun_call_info_cmd_type;


/* DUN info return values */
typedef enum
{
  QMI_WDS_DUN_CALL_DISCONNECTED = 0x01,
  QMI_WDS_DUN_CALL_CONNECTED = 0x02
} qmi_wds_dun_conn_state_type;

#define QMI_WDS_DUN_CALL_INFO_CONN_STATUS_RSP_PARAM_MASK                        0x00000001
#define QMI_WDS_DUN_CALL_INFO_TX_OK_BYTE_COUNT_RSP_PARAM_MASK                   0x00000002
#define QMI_WDS_DUN_CALL_INFO_RX_OK_BYTE_COUNT_RSP_PARAM_MASK                   0x00000004
#define QMI_WDS_DUN_CALL_INFO_LAST_CALL_TX_OK_BYTE_COUNT_RSP_PARAM_MASK         0x00000008
#define QMI_WDS_DUN_CALL_INFO_LAST_CALL_RX_OK_BYTE_COUNT_RSP_PARAM_MASK         0x00000010

/* qmi_wds_get_dun_call_info input/output structure */
typedef struct
{
  /* Each bit in the curr_info_mask corresponds to one of the
  ** fields below it in this structure.  If the bit is set,
  ** the field the field will have valid data
  */
  unsigned long curr_info_mask;

  /* Response fields */
  /* If QMI_WDS_DUN_CALL_INFO_CONN_STATUS_RSP_PARAM_MASK bit is set... */
  struct
  {
    qmi_wds_dun_conn_state_type  conn_state;
    unsigned long                duration[2];
  } conn_status;
  double     tx_ok_byte_cnt;
  double     rx_ok_byte_cnt;
  double     last_call_tx_ok_byte_count;
  double     last_call_rx_ok_byte_count;
  /* More will be added later... */

} qmi_wds_dun_call_info_rsp_type;


#define QMI_WDS_DUN_CALL_INFO_CONN_STATUS_IND_PARAM_MASK               0x00000001
#define QMI_WDS_DUN_CALL_INFO_TX_OK_BYTE_COUNT_IND_PARAM_MASK          0x00000002
#define QMI_WDS_DUN_CALL_INFO_RX_OK_BYTE_COUNT_IND_PARAM_MASK          0x00000004

/* QMI WDS DUN call info indication data structure */
typedef struct
{
  unsigned long ind_info_mask;

  /* Valid if QMI_WDS_DUN_CALL_INFO_CONN_STATUS_IND_PARAM_MASK bit is set in info_mask */
  qmi_wds_dun_conn_state_type   conn_state;

  double     tx_ok_byte_cnt;
  double     rx_ok_byte_cnt;
} qmi_wds_dun_call_info_ind_type;


/*************************************************************************
* FMC related
*************************************************************************/
#define QMI_WDS_FMC_TUNNEL_PARAMS_IPV4_SOCKET_ADDR 0x00000001
#define QMI_WDS_FMC_TUNNEL_PARAMS_IPV6_SOCKET_ADDR 0x00000002

typedef enum
{
  NAT_ABSENT = 0,
  NAT_PRESENT = 1
} qmi_wds_nat_presence_type;

typedef struct
{
  unsigned long param_mask;

  struct
  {
    unsigned long              stream_id;
    qmi_wds_nat_presence_type  nat_presence_indicator;
    unsigned short             port_id;
  } tunnel_params;

  /* Below are optional parameters and are only valid if
  ** corresponding bit is set in param mask
  */

  /* Valid if QMI_WDS_FMC_TUNNEL_PARAMS_IPV4_SOCKET_ADDR is set */
  unsigned char v4_socket_addr[4];

  /* Valid if QMI_WDS_FMC_TUNNEL_PARAMS_IPV6_SOCKET_ADDR is set */
  unsigned char v6_socket_addr[16];

} qmi_wds_fmc_tunnel_params_type;


/*************************************************************************
* Async notification reporting structure
*************************************************************************/
typedef union
{
  qmi_wds_pkt_srvc_status_type                   pkt_srvc_status;
  qmi_wds_event_report_type                      event_report;
  qmi_wds_internal_iface_event_ind_data_type     iface_event_report;
  qmi_wds_mob_terminated_packet_handle           mt_handle;
  qmi_wds_mcast_status_ind_type                  mcast_status;
  qmi_wds_mbms_mcast_context_status_type         mbms_mcast_context_status;
  qmi_wds_dun_call_info_ind_type                 dun_call_info;
  qmi_wds_softap_wwan_status_ind_type            softap_wwan_status;
  qmi_wds_embms_tmgi_activate_status_ind_type    embms_activate_status;
  qmi_wds_embms_tmgi_deactivate_status_ind_type  embms_deactivate_status;
  qmi_wds_embms_tmgi_list_ind_type               embms_list;
} qmi_wds_indication_data_type;


typedef void (*qmi_wds_indication_hdlr_type)
(
  int                           user_handle,
  qmi_service_id_type           service_id,
  void                          *user_data,
  qmi_wds_indication_id_type    ind_id,
  qmi_wds_indication_data_type  *ind_data
);

/************************************************************************
* Definitions associated with qmi_wds_get_current_channel_rate
************************************************************************/
/*RESP*/
typedef struct
{
  unsigned long         current_channel_tx_rate;
  unsigned long         current_channel_rx_rate;
  unsigned long         max_channel_tx_rate;
  unsigned long         max_channel_rx_rate;
}qmi_wds_channel_rate_type;

typedef enum
{
  QMI_WDS_MOBILE_IP_MODE_INVALID = -0x01,
  QMI_WDS_MOBILE_IP_OFF          = 0x00, /*will deafault to simple ip*/
  QMI_WDS_MOBILE_IP_PREFFERED    = 0x01,
  QMI_WDS_MOBILE_IP_ONLY         = 0x02,
  QMI_WDS_MOBILE_IP_MAX          = 0x03
}qmi_wds_mobile_ip_mode_type;

typedef unsigned char srvc_programming_code_type[QMI_WDS_MIP_SERVICE_PROGRAMMING_CODE_SIZE];

typedef enum
{
  QMI_WDS_MOBILE_IP_HA_KEY_UNSET                = 0x00,
  QMI_WDS_MOBILE_IP_HA_KEY_SET_TO_DEFAULT       = 0x01,
  QMI_WDS_MOBILE_IP_HA_KEY_SET_TO_NONDEFAULT    = 0x02
}qmi_wds_mobile_ip_profile_ha_key_state_type;

typedef enum
{

  QMI_WDS_MOBILE_IP_AAA_KEY_UNSET                = 0x00,
  QMI_WDS_MOBILE_IP_AAA_KEY_SET_TO_DEFAULT       = 0x01,
  QMI_WDS_MOBILE_IP_AAA_KEY_SET_TO_NONDEFAULT    = 0x02
}qmi_wds_mobile_ip_profile_aaa_key_state_type;


#define QMI_WDS_READ_MIP_PROFILE_HA_KEY_PARAM_MASK              0x01
#define QMI_WDS_READ_MIP_PROFILE_AAA_KEY_PARAM_MASK             0x02
#define QMI_WDS_READ_MIP_PROFILE_NAI_PARAM_MASK                 0x04

typedef struct
{
  /* Bitmask which indicates which of the below
  ** parameters has been set
  */
  unsigned char                                     param_mask;

  qmi_wds_mobile_ip_profile_ha_key_state_type       ha_key_state ;
  qmi_wds_mobile_ip_profile_aaa_key_state_type      aaa_key_state;
  unsigned char         nai_len;
  unsigned char         nai[QMI_WDS_MOBILE_IP_PROFILE_MAX_STR_SIZE];
}qmi_wds_read_mobile_ip_profile_resp_type;


/* Parameter indication bits */
#define QMI_WDS_MODIFY_MIP_PROFILE_PROFILE_STATE_PARAM_MASK                      0x00000001
#define QMI_WDS_MODIFY_MIP_PROFILE_HOME_ADDR_PARAM_MASK                          0x00000002
#define QMI_WDS_MODIFY_MIP_PROFILE_HOME_AGENT_PRIMARY_ADDR_PARAM_MASK            0x00000004
#define QMI_WDS_MODIFY_MIP_PROFILE_HOME_AGENT_SECONDARY_ADDR_PARAM_MASK          0x00000008
#define QMI_WDS_MODIFY_MIP_PROFILE_REVERSE_TUNNEL_PREF_PARAM_MASK                0x00000010
#define QMI_WDS_MODIFY_MIP_PROFILE_NAI_PARAM_MASK                                0x00000020
#define QMI_WDS_MODIFY_MIP_PROFILE_HA_SPI_PARAM_MASK                             0x00000040
#define QMI_WDS_MODIFY_MIP_PROFILE_AAA_SPI_PARAM_MASK                            0x00000080
#define QMI_WDS_MODIFY_MIP_PROFILE_MN_HA_KEY_PARAM_MASK                          0x00000100
#define QMI_WDS_MODIFY_MIP_PROFILE_MN_AAA_KEY_PARAM_MASK                         0x00000200

typedef struct
{

  /* Bitmask which indicates which of the below
  ** parameters has been set
  */
  unsigned long                                     param_mask;

  unsigned char         profile_state;/*0x00 disabled, 0x01 enabled*/
  ipv4_addr_type        home_address;/*ipv4 format*/
  ipv4_addr_type        home_agent_primary_address;/*ipv4 format*/
  ipv4_addr_type        home_agent_secondary_address;/*ipv4 format*/
  unsigned char         reverse_tunnel_preference;/*0x00 disabled, 0x01 enabled*/
  unsigned char         nai_len;
  unsigned char         nai[QMI_WDS_MOBILE_IP_PROFILE_MAX_STR_SIZE];
  unsigned long         ha_spi;/*secrutiy parameter index*/
  unsigned long         aaa_spi;
  unsigned char         mn_ha_key[QMI_WDS_MOBILE_IP_PROFILE_MAX_STR_SIZE];
  unsigned char         mn_aaa_key[QMI_WDS_MOBILE_IP_PROFILE_MAX_STR_SIZE];
}qmi_wds_modify_mobile_ip_profile_req_type;


/************************************************************************
* Definitions associated with qmi_wds_indication_register
************************************************************************/
#define QMI_WDS_EMBMS_TMGI_INDICATION_REG_LIST_PARAM_MASK    0x01

typedef enum
{
  QMI_WDS_EMBMS_TMGI_IND_NO_REPORT           = 0x00,
  QMI_WDS_EMBMS_TMGI_IND_REPORT              = 0x01
}qmi_wds_embms_tmgi_ind_pref_type;

typedef struct
{
  /* Bitmask which indicates which of the below
  ** parameters has been set
  */
  unsigned char                        param_mask;

  qmi_wds_embms_tmgi_ind_pref_type     tmgi_list_pref;
}qmi_wds_indication_reg_req_type;

/************************************************************************
* Function prototypes
************************************************************************/

/*===========================================================================
  FUNCTION  qmi_wds_srvc_init_client
===========================================================================*/
/*!
@brief
  This function is called to initialize the WDS service.  This function
  must be called prior to calling any other WDS service functions.
  For the time being, the indication handler callback and user data
  should be set to NULL until this is implemented.  Also note that this
  function may be called multiple times to allow for multiple, independent
  clients.

@return
  0 if abort operation was sucessful, < 0 if not.  If return code is
  QMI_SERVICE_ERR, then the qmi_err_code will be valid and will
  indicate which QMI error occurred.

@note

  - Dependencies
    - qmi_connection_init() must be called for the associated port first.

  - Side Effects
    - Talks to modem processor
*/
/*=========================================================================*/
EXTERN qmi_client_handle_type
qmi_wds_srvc_init_client
(
  const char                    *dev_id,
  qmi_wds_indication_hdlr_type  user_ind_msg_hdlr,
  void                          *user_ind_msg_hdlr_user_data,
  int                           *qmi_err_code
);



/*===========================================================================
  FUNCTION  qmi_wds_srvc_release_client
===========================================================================*/
/*!
@brief
  This function is called to release a client created by the
  qmi_wds_srvc_init_client() function.  This function should be called
  for any client created when terminating a client process, especially
  if the modem processor is not reset.  The modem side QMI server has
  a limited number of clients that it will allocate, and if they are not
  released, we will run out.

@return
  0 if abort operation was sucessful, < 0 if not.  If return code is
  QMI_SERVICE_ERR, then the qmi_err_code will be valid and will
  indicate which QMI error occurred.

@note

  - Dependencies
    - qmi_connection_init() must be called for the associated port first.

  - Side Effects
    - Talks to modem processor
*/
/*=========================================================================*/
EXTERN int
qmi_wds_srvc_release_client
(
  int      user_handle,
  int      *qmi_err_code
);



/*===========================================================================
  FUNCTION  qmi_wds_start_nw_if
===========================================================================*/
/*!
@brief
  Brings up a data call.  Call profile parameters can be specified in the
  params parameter, or this pointer can be set to NULL, in which case
  the default profile will be brought up.

  If the user_cb function pointer is set to NULL,
  then this function will be invoked synchronously, otherwise it will
  be invoked asynchronously.

@return
  In the synchronous case, if return code < 0, the operation failed.  In
  the failure case, if the return code is QMI_SERVICE_ERR, then the
  qmi_err_code value will give you the QMI error reason.  Otherwise,
  qmi_err_code will have meaningless data.

  In the asynchronous case, if the return code < 0, the operation failed and
  you will not get an asynchronous response.  If the operation doesn't fail
  (return code >=0), the returned value will be a transaction handle which
  can be used to cancel the transaction via the qmi_wds_abort() command.

@note

  - Dependencies
    - qmi_wds_srvc_init_client() must be called before calling this.

  - Side Effects
    - Brings up a data call
*/
/*=========================================================================*/
EXTERN int
qmi_wds_start_nw_if
(
  int                              user_handle,
  qmi_wds_start_nw_if_params_type  *params,
  qmi_wds_user_async_cb_type       user_cb,
  void                             *user_data,
  qmi_wds_call_end_reason_type     *call_end_reason_resp,
  int                              *qmi_err_code
);


/*===========================================================================
  FUNCTION  qmi_wds_stop_nw_if
===========================================================================*/
/*!
@brief
  Brings down a data call.  If the user_cb function pointer is set to NULL,
  then this function will be invoked synchronously, otherwise it will
  be invoked asynchronously.

@return
  In the synchronous case, if return code < 0, the operation failed.  In
  the failure case, if the return code is QMI_SERVICE_ERR, then the
  qmi_err_code value will give you the QMI error reason.  Otherwise,
  qmi_err_code will have meaningless data.

  In the asynchronous case, if the return code < 0, the operation failed and
  you will not get an asynchronous response.  If the operation doesn't fail
  (return code >=0), the returned value will be a transaction handle which
  can be used to cancel the transaction via the qmi_wds_abort() command.

@note

  - Dependencies
    - qmi_wds_srvc_init_client() must be called before calling this.

  - Side Effects
    - Brings up a data call
*/
/*=========================================================================*/
EXTERN int
qmi_wds_stop_nw_if
(
  int                         client_handle,
  qmi_wds_user_async_cb_type  user_cb,
  void                        *user_data,
  int                         *qmi_err_code
);




/*===========================================================================
  FUNCTION  qmi_wds_reset
===========================================================================*/
/*!
@brief
  Resets WDS service.  If the user_cb function pointer is set to NULL,
  then this function will be invoked synchronously, otherwise it will
  be invoked asynchronously.

@return
  In the synchronous case, if return code < 0, the operation failed.  In
  the failure case, if the return code is QMI_SERVICE_ERR, then the
  qmi_err_code value will give you the QMI error reason.  Otherwise,
  qmi_err_code will have meaningless data.

  In the asynchronous case, if the return code < 0, the operation failed and
  you will not get an asynchronous response.  If the operation doesn't fail
  (return code >=0), the returned value will be a transaction handle which
  can be used to cancel the transaction via the qmi_wds_abort() command.

@note

  - Dependencies
    - qmi_wds_srvc_init_client() must be called before calling this.

  - Side Effects
    - Resets WDS service
*/
/*=========================================================================*/
EXTERN int
qmi_wds_reset
(
  int                         client_handle,
  qmi_wds_user_async_cb_type  user_cb,
  void                        *user_data,
  int                         *qmi_err_code
);


/*===========================================================================
  FUNCTION  qmi_wds_abort
===========================================================================*/
/*!
@brief
  Aborts an asynchronous WDS operation. If the user_cb function pointer is
  set to NULL, then this function will be invoked synchronously, otherwise
  it will be invoked asynchronously.  The txn_handle parameter is the
  return code returned from any other asynchronous WDS call.  Note that
  synchronous API calls cannot be aborted.

@return
  0 if abort operation was sucessful, < 0 if not.  In the case where the
  abort is successful, an asychronous reply to the aborted command will NOT
  be returned, otherwise, it will.  If return code is
  QMI_SERVICE_ERR, then the qmi_err_code will be valid and will
  indicate which QMI error.  Note that asynchronous abort commands cannot
  themselves be aborted.

@note

  - Dependencies
    - qmi_wds_srvc_init_client() must be called before calling this.

  - Side Effects
    - Resets WDS service
*/
/*=========================================================================*/
EXTERN int
qmi_wds_abort
(
  int                         client_handle,
  int                         txn_handle,
  qmi_wds_user_async_cb_type  user_cb,
  void                        *user_data,
  int                         *qmi_err_code
);

/*===========================================================================
  FUNCTION  qmi_wds_indication_register
===========================================================================*/
/*!
@brief
  Register/deregister for different QMI_WDS indications. Indication includes
  EMBMS TMGI Status indication and EMBMS TMGI List indication. At lease one
  indication must be present. It is invoked synchronously.

@return
  0 if register/deregister was sucessful, < 0 if not.

@note

  - Dependencies
    - qmi_wds_srvc_init_client() must be called before calling this.

  - Side Effects
    - Resets WDS service
*/
/*=========================================================================*/
EXTERN int
qmi_wds_indication_register
(
  int                                         user_handle,
  qmi_wds_indication_reg_req_type             ind_reg_req,
  int                                         *qmi_err_code
);

/*===========================================================================
  FUNCTION  qmi_wds_embms_tmgi_activate
===========================================================================*/
/*!
@brief
  Activates a TMGI for EMBMS. It is invoked synchronously.

@return
  0 if activate operation was sucessful, < 0 if not.  In the case where the
  activate operation is successful, a Status indication will
  be returned, otherwise, it will not.  If return code is
  QMI_SERVICE_ERR, then the qmi_err_code will be valid and will
  indicate which QMI error.

@note

  - Dependencies
    - qmi_wds_srvc_init_client() must be called before calling this.

  - Side Effects
    - Resets WDS service
*/
/*=========================================================================*/
EXTERN int
qmi_wds_embms_tmgi_activate
(
  int                               user_handle,
  qmi_wds_embms_tmgi_type           *tmgi,
  int                               *qmi_err_code
);

/*===========================================================================
  FUNCTION  qmi_wds_embms_tmgi_deactivate
===========================================================================*/
/*!
@brief
  Deactivates a TMGI for EMBMS. It is invoked synchronously.

@return
  0 if deactivate operation was sucessful, < 0 if not.  In the case where the
  deactivate operation is successful, a Status indication will
  be returned, otherwise, it will not.  If return code is
  QMI_SERVICE_ERR, then the qmi_err_code will be valid and will
  indicate which QMI error.


@note

  - Dependencies
    - qmi_wds_srvc_init_client() must be called before calling this.

  - Side Effects
    - Resets WDS service
*/
/*=========================================================================*/
EXTERN int
qmi_wds_embms_tmgi_deactivate
(
  int                               user_handle,
  qmi_wds_embms_tmgi_type           *tmgi,
  int                               *qmi_err_code
);

/*===========================================================================
  FUNCTION  qmi_wds_embms_tmgi_list_query
===========================================================================*/
/*!
@brief
  Queries active or available TMGI list. It is invoked synchronously.

@return
  0 if query operation was sucessful, < 0 if not.  In the case where the
  query operation is successful, a Status indication will
  be returned, otherwise, it will not.  If return code is
  QMI_SERVICE_ERR, then the qmi_err_code will be valid and will
  indicate which QMI error.


@note

  - Dependencies
    - qmi_wds_srvc_init_client() must be called before calling this.

  - Side Effects
    - Resets WDS service
*/
/*=========================================================================*/
EXTERN int
qmi_wds_embms_tmgi_list_query
(
  int                               user_handle,
  qmi_wds_embms_tmgi_list_type      list_type,
  qmi_wds_embms_tmgi_list_ind_type  *list_query,
  int                               *qmi_err_code
);

/*===========================================================================
  FUNCTION  qmi_wds_create_profile
===========================================================================*/
/*!
@brief
  Takes as input a user client handle, WDS profile parameters and a WDS
  profile ID structure and creates a QMI profile (on modem processor) based
  on these parameters.  The input profile ID MUST have the 'technology'
  field set to a valid value.

  Note that each of the 'profile_params' structure values are optional.
  To indicate that a particular structure field is valid in the input
  parameters, the corresponding bit should be set in the 'param_mask'
  field of the structure.  For example if the 'secondary_dns_pref_addr'
  field has been filled in and is valid, the QMI_WDS_PROFILE_PARAM_SEC_DNS
  bit should be set in the 'param_mask'

@return
  QMI_INTERNAL_ERR if an error occurred, QMI_NO_ERR if not.  Upon successful
  return, the profile ID parameter will have the 'profile_index' field set to
  the profile index of the newly created profile.
  If return is QMI_EXTENDED_ERR, then qmi_err_code does not contain
  QMI_SERVICE_ERR_* error codes, but contains subsystem(module which modem QMI
  talks to, ex: ds_profile) specific error codes.
@note

  - This function executes synchronously, there is not currently an
    asynchronous option for this functionality.

  - Dependencies
    - None.

  - Side Effects
    - Creates a new profile on the modem processor.
*/
/*=========================================================================*/
EXTERN int
qmi_wds_create_profile
(
  int                         user_handle,
  qmi_wds_profile_id_type     *profile_id,
  qmi_wds_profile_params_type *profile_params,
  int                         *qmi_err_code
);



/*===========================================================================
  FUNCTION  qmi_wds_modify_profile
===========================================================================*/
/*!
@brief
  Takes as input a user client handle, WDS profile parameters and a WDS
  profile ID structure and modifies parameters of an existing profile
  on the modem processor. The input profile ID MUST have the 'technology'
  field and 'profile_index' set to an existing valid profile index value.

  Note that each of the 'profile_params' structure values are optional.
  To indicate that a particular structure field is valid in the input
  parameters, the corresponding bit should be set in the 'param_mask'
  field of the structure.  For example if the 'secondary_dns_pref_addr'
  field has been filled in and is valid, the QMI_WDS_PROFILE_PARAM_SEC_DNS
  bit should be set in the 'param_mask'

@return
  QMI_INTERNAL_ERR if an error occurred, QMI_NO_ERR if not.
  If return is QMI_EXTENDED_ERR, then qmi_err_code does not contain
  QMI_SERVICE_ERR_* error codes, but contains subsystem(module which modem QMI
  talks to, ex: ds_profile) specific error codes.
@note

  - This function executes synchronously, there is not currently an
    asynchronous option for this functionality.

  - Dependencies
    - None.

  - Side Effects
    - Creates a new profile on the modem processor.
*/
/*=========================================================================*/
EXTERN int
qmi_wds_modify_profile
(
  int                         user_handle,
  qmi_wds_profile_id_type     *profile_id,
  qmi_wds_profile_params_type *profile_params,
  int                         *qmi_err_code
);



/*===========================================================================
  FUNCTION  qmi_wds_query_profile
===========================================================================*/
/*!
@brief
  Takes as input a user client handle, and a WDS
  profile ID structure and queries the parameters of an existing profile
  on the modem processor. The input profile ID MUST have the 'technology'
  field and 'profile_index' set to an existing valid profile index value.
  The current values of the parameters will be returned in the
  profile_params structure.

  Note that each of the 'profile_params' structure values are optional.
  To indicate that a particular structure field is valid in the output
  parameters, the corresponding bit will be set in the 'param_mask'
  field of the structure.  For example if the 'secondary_dns_pref_addr'
  field has been filled in and is valid, the QMI_WDS_PROFILE_PARAM_SEC_DNS
  bit will be set in the 'param_mask'

@return
  QMI_INTERNAL_ERR if an error occurred, QMI_NO_ERR if not.

  If return is QMI_EXTENDED_ERR, then qmi_err_code does not contain
  QMI_SERVICE_ERR_* error codes, but contains subsystem(module which modem QMI
  talks to, ex: ds_profile) specific error codes.
@note

  - This function executes synchronously, there is not currently an
    asynchronous option for this functionality.

  - Dependencies
    - None.

  - Side Effects
    - Creates a new profile on the modem processor.
*/
/*=========================================================================*/
EXTERN int
qmi_wds_query_profile
(
  int                         user_handle,
  qmi_wds_profile_id_type     *profile_id,
  qmi_wds_profile_params_type *profile_params,
  int                         *qmi_err_code
);


/*===========================================================================
  FUNCTION  qmi_wds_delete_profile
===========================================================================*/
/*!
@brief
  Takes as input a user client handle, and a WDS
  profile ID structure and deletes an existing profile
  on the modem processor. The input profile ID MUST have the 'technology'
  field and 'profile_index' set to an existing valid profile index value.


@return
  QMI_INTERNAL_ERR if an error occurred, QMI_NO_ERR if not.
  If return is QMI_EXTENDED_ERR, then qmi_err_code does not contain
  QMI_SERVICE_ERR_* error codes, but contains subsystem(module which modem QMI
  talks to, ex: ds_profile) specific error codes.
@note

  - This function executes synchronously, there is not currently an
    asynchronous option for this functionality.

  - Dependencies
    - None.

  - Side Effects
    - Creates a new profile on the modem processor.
*/
/*=========================================================================*/
EXTERN int
qmi_wds_delete_profile
(
  int                         user_handle,
  qmi_wds_profile_id_type     *profile_id,
  int                         *qmi_err_code
);



/*===========================================================================
  FUNCTION  qmi_wds_get_profile_list
===========================================================================*/
/*!
@brief
  Takes as input a user client handle, and an array of profile query
  structures in which to place response, and the number of elements in that
  array.

  Note that the num_profile_list_elements is both an input and output
  parameter.  It should be used to indicated the number of elements in
  the profile_list array when calling the function, and will contain the
  number of elements returned when the function returns.

@return
  Returned is the array filled in with return data, and the number of
  elements of the array that have been returned.
  QMI_INTERNAL_ERR or QMI_SERVICE_ERR if an error occurred, QMI_NO_ERR if not.
  If QMI_SERVICE_ERR is returned, the qmi_err_code return parameter
  will be valid, otherwise it won't
  If return is QMI_EXTENDED_ERR, then qmi_err_code does not contain
  QMI_SERVICE_ERR_* error codes, but contains subsystem(module which modem QMI
  talks to, ex: ds_profile) specific error codes.
@note

  - This function executes synchronously, there is not currently an
    asynchronous option for this functionality.

  - Dependencies
    - None.

  - Side Effects
    - None.
*/
/*=========================================================================*/
EXTERN int
qmi_wds_get_profile_list
(
  int                        user_handle,
  qmi_wds_profile_list_type  *profile_list,
  int                        *num_profile_list_elements,
  int                        *qmi_err_code
);


/*===========================================================================
  FUNCTION  qmi_wds_route_look_up
===========================================================================*/
/*!
@brief
  Takes as input a user client handle, and an array of profile query
  structures in which to place response, and the number of elements in that
  array.

  Note that the num_profile_list_elements is both an input and output
  parameter.  It should be used to indicated the number of elements in
  the profile_list array when calling the function, and will contain the
  number of elements returned when the function returns.

@return
  Returned is the array filled in with return data, and the number of
  elements of the array that have been returned.
  QMI_INTERNAL_ERR or QMI_SERVICE_ERR if an error occurred, QMI_NO_ERR if not.

@note

  - This function executes synchronously, there is not currently an
    asynchronous option for this functionality.

  - Dependencies
    - None.

  - Side Effects
    - None.
*/
/*=========================================================================*/
EXTERN int
qmi_wds_route_look_up
(
  int                               user_handle,
  qmi_wds_route_look_up_params_type *params,
  qmi_wds_route_look_up_rsp_type    *rsp_data,
  int                               *qmi_err_code
);

/*===========================================================================
  FUNCTION  qmi_wds_get_internal_runtime_settings
===========================================================================*/
/*!
@brief
  Takes as input the intenal settings request params type and returns the
  data sessions settings currently in use.

@return
  QMI_NO_ERR if operation was sucessful, < 0 if not.  If return code is
  QMI_SERVICE_ERR, then the qmi_err_code will be valid and will
  indicate which QMI error occurred.

@note

  - This function executes synchronously, there is not currently an
    asynchronous option for this functionality.

  - Dependencies
    - None.

  - Side Effects
    - None.
*/
/*=========================================================================*/
EXTERN int
qmi_wds_get_internal_runtime_settings
(
  int                                            user_handle,
  qmi_wds_internal_runtime_setings_params_type   *params,
  qmi_wds_internal_runtime_settings_rsp_type     *rsp_data,
  int                                            *qmi_err_code
);

/*===========================================================================
  FUNCTION  qmi_wds_refresh_dhcp_config_info
===========================================================================*/
/*!
@brief
  This message will trigger DHCP in the background and allow the control point
  to refresh the dhcp configuration.

@return
  QMI_NO_ERR if operation was sucessful, < 0 if not.  If return code is
  QMI_SERVICE_ERR, then the qmi_err_code will be valid and will
  indicate which QMI error occurred.

@note

  - This function executes synchronously, there is not currently an
    asynchronous option for this functionality.

  - Dependencies
    - None.

  - Side Effects
    - None.
*/
/*=========================================================================*/

EXTERN int
qmi_wds_refresh_dhcp_config_info
(
  int                    user_handle,
  int                    *qmi_err_code
);

/*===========================================================================
  FUNCTION  qmi_wds_reg_mobile_terminated_call_req
===========================================================================*/
/*!
@brief
  This message will allow a control point to register for a mobile terminated
  (MT) call request event. 3GPP profile ID is the input along with ip family
  preference and tech preference.

@return
  QMI_NO_ERR if operation was sucessful, < 0 if not.  If return code is
  QMI_SERVICE_ERR, then the qmi_err_code will be valid and will
  indicate which QMI error occurred.

@note

  - This function executes synchronously, there is not currently an
    asynchronous option for this functionality.

  - Dependencies
    - None.

  - Side Effects
    - None.
*/
/*=========================================================================*/
EXTERN int
qmi_wds_reg_mobile_terminated_call_req
(
  int                                         user_handle,
  qmi_wds_reg_mob_term_call_req_params        *params,
  qmi_wds_reg_mob_terminated_call_rsp_type    *rsp_data,
  int                                         *qmi_err_code
);

/*===========================================================================
  FUNCTION  qmi_wds_dereg_mobile_terminated_call_req
===========================================================================*/
/*!
@brief
  This message will take as input a mobile terminated related packet handle
  allow the control point to de register for mob term call request event.

@return
  QMI_NO_ERR if operation was sucessful, < 0 if not.  If return code is
  QMI_SERVICE_ERR, then the qmi_err_code will be valid and will
  indicate which QMI error occurred.

@note

  - This function executes synchronously, there is not currently an
    asynchronous option for this functionality.

  - Dependencies
    - None.

  - Side Effects
    - None.
*/
/*=========================================================================*/
EXTERN int
qmi_wds_dereg_mobile_terminated_call_req
(
  int                                           user_handle,
  mob_terminated_packet_handle                  *mt_handle,
  qmi_wds_de_reg_mob_terminated_call_rsp_type   *rsp_data,
  int                                           *qmi_err_code
);

/*===========================================================================
  FUNCTION  qmi_wds_bcmcs_db_update_req
===========================================================================*/
/*!
@brief
  This message will take as input the bcmcs database info and allow the
  control point to update the bcmcs database table.

@return
  QMI_NO_ERR if operation was sucessful, < 0 if not.  If return code is
  QMI_SERVICE_ERR, then the qmi_err_code will be valid and will
  indicate which QMI error occurred.

@note

  - This function executes synchronously, there is not currently an
    asynchronous option for this functionality.

  - Dependencies
    - None.

  - Side Effects
    - None.
*/
/*=========================================================================*/
EXTERN int
qmi_wds_bcmcs_db_update_req
(
  int                                    user_handle,
  qmi_wds_bcmcs_db_updt_params_type      *bcmcs_db_data,
  qmi_wds_bcmcs_db_updt_rsp_type         *rsp_data,
  int                                    *qmi_err_code
);
/*===========================================================================
  FUNCTION  qmi_wds_bcmcs_enable_handoff_reg_req
===========================================================================*/
/*!
@brief
  This message will take as input a bcmcs handoff optimization info and allows
  a control point to perform bcmcs handoff optimization for registration.

@return
  QMI_NO_ERR if operation was sucessful, < 0 if not.  If return code is
  QMI_SERVICE_ERR, then the qmi_err_code will be valid and will
  indicate which QMI error occurred.

@note

  - This function executes synchronously, there is not currently an
    asynchronous option for this functionality.

  - Dependencies
    - None.

  - Side Effects
    - None.
*/
/*=========================================================================*/
EXTERN int
qmi_wds_bcmcs_enable_handoff_reg_req
(
  int                                          user_handle,
  qmi_wds_bcmcs_handoff_optimization_info      *handoff_optization_info,
  qmi_wds_bcmcs_enable_handoff_reg_rsp_type    *rsp_data,
  int                                          *qmi_err_code
);

/*===========================================================================
  FUNCTION  qmi_wds_bcmcs_bom_caching_setup_req
===========================================================================*/
/*!
@brief
  This message will take as input a bmccs caching setup info and thereby
  allows a control point to enable or disable bcmcs bom caching.

@return
  QMI_NO_ERR if operation was sucessful, < 0 if not.  If return code is
  QMI_SERVICE_ERR, then the qmi_err_code will be valid and will
  indicate which QMI error occurred.

@note

  - This function executes synchronously, there is not currently an
    asynchronous option for this functionality.

  - Dependencies
    - None.

  - Side Effects
    - None.
*/
/*=========================================================================*/
EXTERN int
qmi_wds_bcmcs_bom_caching_setup_req
(
  int                                          user_handle,
  qmi_wds_bom_caching_setup_req_param_type     *bom_setup_info,
  qmi_wds_bcmcs_bom_caching_setup_rsp_type     *rsp_data,
  int                                          *qmi_err_code
);

/*===========================================================================
  FUNCTION  qmi_wds_initiate_mcast_join_ex
===========================================================================*/
/*!
@brief
  This message will take as input a list of multicast ip addresses and
  initiates a join on those addresses to a session.

@return
  QMI_NO_ERR if operation was sucessful, < 0 if not.  If return code is
  QMI_SERVICE_ERR, then the qmi_err_code will be valid and will
  indicate which QMI error occurred.

@note

  - This function executes synchronously, there is not currently an
    asynchronous option for this functionality.

  - Dependencies
    - None.

  - Side Effects
    - None.
*/
/*=========================================================================*/
EXTERN int
qmi_wds_initiate_mcast_join_ex
(
  int                                          user_handle,
  qmi_wds_mcast_join_req_params_type           *mcast_info,
  qmi_wds_initiate_mcast_join_ex_rsp_type      *rsp_data,
  int                                          *qmi_err_code
);

/*===========================================================================
  FUNCTION  qmi_wds_initiate_mcast_leave_ex
===========================================================================*/
/*!
@brief
   This message will take as input the list of mulitcast handles and initiates
  them to leave the flows/sessions .

@return
  QMI_NO_ERR if operation was sucessful, < 0 if not.  If return code is
  QMI_SERVICE_ERR, then the qmi_err_code will be valid and will
  indicate which QMI error occurred.

@note

  - This function executes synchronously, there is not currently an
    asynchronous option for this functionality.

  - Dependencies
    - None.

  - Side Effects
    - None.
*/
/*=========================================================================*/
EXTERN int
qmi_wds_initiate_mcast_leave_ex
(
  int                                          user_handle,
  qmi_wds_mcast_hndl_list_type                 *mcast_hndl_list,
  qmi_wds_initiate_mcast_leave_ex_rsp_type     *rsp_data,
  int                                          *qmi_err_code
);

/*===========================================================================
  FUNCTION  qmi_wds_get_curr_call_info
===========================================================================*/
/*!
@brief
  Takes as input a user client handle, and returns the current call
  info for that client in the profile_id, profile_params and call_settings

@return
  QMI_INTERNAL_ERR or QMI_SERVICE_ERR if an error occurred, QMI_NO_ERR if not.
  If QMI_SERVICE_ERR is returned, the qmi_err_code return parameter
  will be valid, otherwise it won't

@note

  - This function executes synchronously, there is not currently an
    asynchronous option for this functionality.

  - Dependencies
    - None.

  - Side Effects
    - Creates a new profile on the modem processor.
*/
/*=========================================================================*/
EXTERN int
qmi_wds_get_curr_call_info
(
  int                                        user_handle,
  qmi_wds_req_runtime_settings_params_type   requested_settings,
  qmi_wds_profile_id_type                    *profile_id,
  qmi_wds_profile_params_type                *profile_params,
  qmi_wds_curr_call_info_type                *call_settings,
  int                                        *qmi_err_code
);

/*===========================================================================
  FUNCTION  qmi_wds_internal_iface_event_reg_req
===========================================================================*/
/*!
@brief
  Registers the control point for events which can be specified by an event
  mask.


@return
  QMI_INTERNAL_ERR if an error occurred, QMI_NO_ERR if not.

@note

  - This function executes synchronously, there is not currently an
    asynchronous option for this functionality.

  - Dependencies
    - None.

  - Side Effects
*/
/*=========================================================================*/
EXTERN int
qmi_wds_internal_iface_event_reg_req
(
  int                                       user_handle,
  qmi_wds_iface_event_register_param_type   event_mask,
  int                                       *qmi_err_code
);

/*===========================================================================
  FUNCTION  qmi_wds_go_active_req
===========================================================================*/
/*!
@brief
  This message will force the device to re-establish the traffic channel on
  serving radio interface immediately. This message has no user specified
  params required.

@return
  QMI_NO_ERR if operation was sucessful, < 0 if not.  If return code is
  QMI_SERVICE_ERR, then the qmi_err_code will be valid and will
  indicate which QMI error occurred.

@note

  - This function executes synchronously, there is not currently an
    asynchronous option for this functionality.

  - Dependencies
    - None.

  - Side Effects
    - None.
*/
/*=========================================================================*/
EXTERN int
qmi_wds_go_active_req
(
  int user_handle,
  int *qmi_err_code
);

/*===========================================================================
  FUNCTION  qmi_wds_set_internal_runtime_settings
===========================================================================*/
/*!
@brief
  Takes as input the intenal settings request params type and allows the
  control point to set or modify some internal packet data session settings.

@return
  QMI_NO_ERR if operation was sucessful, < 0 if not.  If return code is
  QMI_SERVICE_ERR, then the qmi_err_code will be valid and will
  indicate which QMI error occurred.

@note

  - This function executes synchronously, there is not currently an
    asynchronous option for this functionality.

  - Dependencies
    - None.

  - Side Effects
    - None.
*/
/*=========================================================================*/

EXTERN int
qmi_wds_set_internal_runtime_settings
(
  int                                                 user_handle,
  qmi_wds_set_internal_runtime_settings_params_type   *params,
  qmi_wds_set_internal_runtime_settings_rsp_type      *rsp_data,
  int                                                 *qmi_err_code
);
/*===========================================================================
  FUNCTION  qmi_wds_initiate_mcast_register_ex
===========================================================================*/
/*!
@brief
  This message will take as input the list of mulitcast handles and initiates
  them to leave the flows/sessions .

@return
  QMI_NO_ERR if operation was sucessful, < 0 if not.  If return code is
  QMI_SERVICE_ERR, then the qmi_err_code will be valid and will
  indicate which QMI error occurred.

@note

  - This function executes synchronously, there is not currently an
    asynchronous option for this functionality.

  - Dependencies
    - None.

  - Side Effects
    - None.
*/
/*=========================================================================*/
EXTERN int
qmi_wds_initiate_mcast_register_ex
(
  int                                     user_handle,
  qmi_wds_mcast_hndl_list_type            *mcast_handle_list,
  qmi_wds_initiate_mcast_reg_ex_rsp_type  *rsp_data,
  int                                     *qmi_err_code
);

/*===========================================================================
  FUNCTION  qmi_wds_initiate_mcast_join
===========================================================================*/
/*!
@brief
  This message will take as input the multicast ip addr, and joins the ip addr
  to the multicast session. The differece from the ex version is that only a
  single ip addr message is handled here to be joined.

@return
  QMI_NO_ERR if operation was sucessful, < 0 if not.  If return code is
  QMI_SERVICE_ERR, then the qmi_err_code will be valid and will
  indicate which QMI error occurred.

@note

  - This function executes synchronously, there is not currently an
    asynchronous option for this functionality.

  - Dependencies
    - None.

  - Side Effects
    - None.
*/
/*=========================================================================*/
EXTERN int
qmi_wds_initiate_mcast_join
(
  int                                       user_handle,
  qmi_wds_mcast_ipv4_join_info_param_type   *mcast_join_info,
  qmi_wds_mcast_hndl_rsp_type               *mcast_hndl_resp,
  int                                       *qmi_err_code
);
/*===========================================================================
  FUNCTION  qmi_wds_initiate_mcast_leave
===========================================================================*/
/*!
@brief
  This message will take as input the multicast ip addr, and joins the ip addr
  to the multicast session. The differece from the ex version is that only a
  single ip addr message is handled here to be joined.

@return
  QMI_NO_ERR if operation was sucessful, < 0 if not.  If return code is
  QMI_SERVICE_ERR, then the qmi_err_code will be valid and will
  indicate which QMI error occurred.

@note

  - This function executes synchronously, there is not currently an
    asynchronous option for this functionality.

  - Dependencies
    - None.

  - Side Effects
    - None.
*/
/*=========================================================================*/
EXTERN int
qmi_wds_initiate_mcast_leave
(
  int                            user_handle,
  qmi_wds_mcast_hndl_param_type  *mcast_handle,
  int                            *qmi_err_code
);

/*===========================================================================
  FUNCTION  qmi_wds_initiate_mbms_context_activate
===========================================================================*/
/*!
@brief
  This message will take as input the ipv4 context activation info consisting
  of ipv4 addr to join and profile id and then activates the MBMS context.

@return
  QMI_NO_ERR if operation was sucessful, < 0 if not.  If return code is
  QMI_SERVICE_ERR, then the qmi_err_code will be valid and will
  indicate which QMI error occurred.

@note

  - This function executes synchronously, there is not currently an
    asynchronous option for this functionality.

  - Dependencies
    - None.

  - Side Effects
    - None.
*/
/*=========================================================================*/
EXTERN int
qmi_wds_initiate_mbms_context_activate
(
  int                                   user_handle,
  qmi_wds_mbms_context_req_params_type  *params,
  qmi_wds_mbms_context_handle           *rsp_data,
  int                                   *qmi_err_code
);
/*===========================================================================
  FUNCTION  qmi_wds_initiate_mbms_context_deactivate
===========================================================================*/
/*!
@brief
  This message will take as input the multicast context handle and deactivates
  the mbms context.


@return
  QMI_NO_ERR if operation was sucessful, < 0 if not.  If return code is
  QMI_SERVICE_ERR, then the qmi_err_code will be valid and will
  indicate which QMI error occurred.

@note

  - This function executes synchronously, there is not currently an
    asynchronous option for this functionality.

  - Dependencies
    - None.

  - Side Effects
    - None.
*/
/*=========================================================================*/
EXTERN int
qmi_wds_initiate_mbms_context_deactivate
(
  int                          user_handle,
  qmi_wds_mbms_context_handle  *param,
  int                          *qmi_err_code
);

/*===========================================================================
  FUNCTION  qmi_wds_get_current_bearer_tech
===========================================================================*/
/*!
@brief
  This message will take as input the multicast context handle and deactivates
  the mbms context.


@return
  QMI_NO_ERR if operation was sucessful, < 0 if not.  If return code is
  QMI_SERVICE_ERR, then the qmi_err_code will be valid and will
  indicate which QMI error occurred.

@note

  - This function executes synchronously, there is not currently an
    asynchronous option for this functionality.

  - Dependencies
    - None.

  - Side Effects
    - None.
*/
/*=========================================================================*/
EXTERN int
qmi_wds_get_current_bearer_tech
(
  int                            user_handle,
  qmi_wds_data_bearer_tech_type  *rsp_data,
  int                            *qmi_err_code
);

/*===========================================================================
  FUNCTION  qmi_wds_get_current_channel_rate
===========================================================================*/
/*!
@brief
  This message will force the device to re-establish the traffic channel on
  serving radio interface immediately. This message has no user specified
  params required.

@return
  QMI_NO_ERR if operation was sucessful, < 0 if not.  If return code is
  QMI_SERVICE_ERR, then the qmi_err_code will be valid and will
  indicate which QMI error occurred.

@note

  - This function executes synchronously, there is not currently an
    asynchronous option for this functionality.

  - Dependencies
    - None.

  - Side Effects
    - None.
*/
/*=========================================================================*/
EXTERN int
qmi_wds_get_current_channel_rate
(
  int                         user_handle,
  qmi_wds_channel_rate_type   *resp_data,
  int                         *qmi_err_code
);

/*===========================================================================
  FUNCTION  qmi_wds_go_dormant_req
===========================================================================*/
/*!
@brief
  This message will force the device to drop the traffic channel on
  serving radio interface immediately. This message has no user specified
  params required.

@return
  QMI_NO_ERR if operation was sucessful, < 0 if not.  If return code is
  QMI_SERVICE_ERR, then the qmi_err_code will be valid and will
  indicate which QMI error occurred.

@note

  - This function executes synchronously, there is not currently an
    asynchronous option for this functionality.

  - Dependencies
    - None.

  - Side Effects
    - None.
*/
/*=========================================================================*/
EXTERN int
qmi_wds_go_dormant_req
(
  int   user_handle,
  int   *qmi_err_code
);
/*===========================================================================
  FUNCTION  qmi_wds_get_pkt_statistics
===========================================================================*/
/*!
@brief
  Takes as input the route lookup params type and returns the route
  lookup response.

@return
  QMI_NO_ERR if operation was sucessful, < 0 if not.  If return code is
  QMI_SERVICE_ERR, then the qmi_err_code will be valid and will
  indicate which QMI error occurred.

@note

  - This function executes synchronously, there is not currently an
    asynchronous option for this functionality.

  - Dependencies
    - None.

  - Side Effects
    - None.
*/
/*=========================================================================*/
EXTERN int
qmi_wds_get_pkt_statistics
(
int                               user_handle,
unsigned long                     stats_mask,
qmi_wds_xfer_stats                *stats_resp,
int                               *qmi_err_code
);
/*===========================================================================
  FUNCTION  qmi_wds_set_event_report
===========================================================================*/
/*!
@brief
  Takes as input a user client handle and an event reporting parameters
  structure and registers for the specified events.  The events will
  be reported as asynchronous indications


@return
  QMI_INTERNAL_ERR if an error occurred, QMI_NO_ERR if not.

@note

  - This function executes synchronously, there is not currently an
    asynchronous option for this functionality.

  - Dependencies
    - None.

  - Side Effects
    - Creates a new profile on the modem processor.
*/
/*=========================================================================*/
EXTERN int
qmi_wds_set_event_report
(
  int                               user_handle,
  qmi_wds_event_report_params_type  *event_params,
  int                               *qmi_err_code
);

/*===========================================================================
  FUNCTION  qmi_wds_get_dormancy_status
===========================================================================*/
/*!
@brief
  Gets current dormancy status.

@return
  QMI_NO_ERR (0) if no error occurred, one of the other QMI_*_ERR codes (< 0)
  if an error occurred.  If return is QMI_SERVICE_ERR, the the qmi_err_code
  is valid and contains one of the QMI_SERVICE_ERR_* error codes.

@note

  - This function executes synchronously, there is not currently an
    asynchronous option for this functionality.

  - Dependencies
    - None.

  - Side Effects
    - None.
*/
/*=========================================================================*/
EXTERN int
qmi_wds_get_dormancy_status
(
  int                       user_handle,
  qmi_wds_dorm_status_type  *dorm_status,
  int                       *qmi_err_code
);

/*===========================================================================
  FUNCTION  qmi_wds_get_default_settings
===========================================================================*/
/*!
@brief
  Takes as input a user client handle, and a WDS
  profile ID structure and queries the parameters of the default profile
  modem processor. The input profile_id field MUST have the 'technology'
  field set to a valid profile technology type value before function is called.
  The current values of the parameters will be returned in the
  profile_params structure.

  Note that each of the 'profile_params' structure values are optional.
  To indicate that a particular structure field is valid in the output
  parameters, the corresponding bit will be set in the 'param_mask'
  field of the structure.  For example if the 'secondary_dns_pref_addr'
  field has been filled in and is valid, the QMI_WDS_PROFILE_PARAM_SEC_DNS
  bit will be set in the 'param_mask'

@return
  QMI_INTERNAL_ERR if an error occurred, QMI_NO_ERR if not.

@note

  - This function executes synchronously, there is not currently an
    asynchronous option for this functionality.

  - Dependencies
    - None.

  - Side Effects
    - Creates a new profile on the modem processor.
*/
/*=========================================================================*/
EXTERN int
qmi_wds_get_default_settings
(
  int                         user_handle,
  qmi_wds_profile_tech_type   profile_tech,
  qmi_wds_profile_params_type *profile_params,
  int                         *qmi_err_code
);


/*===========================================================================
  FUNCTION  qmi_wds_get_pkt_srvc_status
===========================================================================*/
/*!
@brief
  Takes as input a user client handle and returns the packet service status
  of the associated connection.

@return
  Value < 0 if error occurred, QMI_NO_ERR (0) if not.
  If QMI_NO_ERR is returned, the returned packet service status will be valid,
  otherwise it won't be.

  If QMI_SERVICE_ERR error code is returned, the qmi_err_code return parameter
  will be valid, otherwise it won't

@note

  - This function executes synchronously, there is not currently an
    asynchronous option for this functionality.

  - Dependencies
    - None.

  - Side Effects
    - None.
*/
/*=========================================================================*/
EXTERN int
qmi_wds_get_pkt_srvc_status
(
  int                       user_handle,
  qmi_wds_link_status_type  *pkt_srvc_status,
  int                       *qmi_err_code
);


/*===========================================================================
  FUNCTION  qmi_wds_get_dun_call_info
===========================================================================*/
/*!
@brief
  Gets DUN call state and also sets items for reporting in DUN indications.

@return
  QMI_NO_ERR (0) if no error occurred, one of the other QMI_*_ERR codes (< 0)
  if an error occurred.  If return is QMI_SERVICE_ERR, the the qmi_err_code
  is valid and contains one of the QMI_SERVICE_ERR_* error codes.

  cmd_info is an input paramter which indicates which current call info to
  retrieve as well as which fields to report in the DUN indication message

  rsp_info is an output parameter which contains the current call info requested
  in the command.

@note

  - This function executes synchronously, there is not currently an
    asynchronous option for this functionality.

  - Dependencies
    - None.

  - Side Effects
    - None.
*/
/*=========================================================================*/
EXTERN int
qmi_wds_get_dun_call_info
(
  int                             user_handle,
  qmi_wds_dun_call_info_cmd_type  *cmd_info,
  qmi_wds_dun_call_info_rsp_type  *rsp_info,
  int                             *qmi_err_code
);
/*===========================================================================
  FUNCTION  qmi_wds_get_default_profile_number
===========================================================================*/
/*!
@brief
  This messages retrieves the default profile number configured on the wireless
  device for the specified technology

@return
  QMI_NO_ERR (0) if no error occurred, one of the other QMI_*_ERR codes (< 0)
  if an error occurred.  If return is QMI_SERVICE_ERR, the the qmi_err_code
  is valid and contains one of the QMI_SERVICE_ERR_* error codes.

  If return is QMI_EXTENDED_ERR, then qmi_err_code does not contain
  QMI_SERVICE_ERR_* error codes, but contains subsystem(module which modem QMI
  talks to, ex: ds_profile) specific error codes.
@note

  - This function executes synchronously, there is not currently an
    asynchronous option for this functionality.

  - Dependencies
    - None.

  - Side Effects
    - None.
*/
/*=========================================================================*/
EXTERN int
qmi_wds_get_default_profile_number
(
  int                                            user_handle,
  qmi_wds_profile_tech_type                      profile_tech,
  qmi_wds_profile_family                         profile_family,
  unsigned char                                  *default_profile_number,
  int                                            *qmi_err_code
);


/*===========================================================================
  FUNCTION  qmi_wds_set_default_profile_number
===========================================================================*/
/*!
@brief
  This messages sets the default profile number on the wireless device for
  the specifed technology

@return
  QMI_NO_ERR (0) if no error occurred, one of the other QMI_*_ERR codes (< 0)
  if an error occurred.  If return is QMI_SERVICE_ERR, the the qmi_err_code
  is valid and contains one of the QMI_SERVICE_ERR_* error codes.

  If return is QMI_EXTENDED_ERR, then qmi_err_code does not contain
  QMI_SERVICE_ERR_* error codes, but contains subsystem(module which modem QMI
  talks to, ex: ds_profile) specific error codes.
@note

  - This function executes synchronously, there is not currently an
    asynchronous option for this functionality.

  - Dependencies
    - None.

  - Side Effects
    - None.
*/
/*=========================================================================*/
EXTERN int
qmi_wds_set_default_profile_number
(
  int                                            user_handle,
  qmi_wds_profile_tech_type                      profile_tech,
  qmi_wds_profile_family                         profile_family,
  unsigned char                                  profile_index,
  int                                            *qmi_err_code
);


/*===========================================================================
  FUNCTION  qmi_wds_reset_profile_to_default
===========================================================================*/
/*!
@brief
  This messages resets all the parameters of the given profile and technology
  to default values.

@return
  QMI_NO_ERR (0) if no error occurred, one of the other QMI_*_ERR codes (< 0)
  if an error occurred.  If return is QMI_SERVICE_ERR, the the qmi_err_code
  is valid and contains one of the QMI_SERVICE_ERR_* error codes.

  If return is QMI_EXTENDED_ERR, then qmi_err_code does not contain
  QMI_SERVICE_ERR_* error codes, but contains subsystem(module which modem QMI
  talks to, ex: ds_profile) specific error codes.
@note

  - This function executes synchronously, there is not currently an
    asynchronous option for this functionality.

  - Dependencies
    - None.

  - Side Effects
    - None.
*/
/*=========================================================================*/
EXTERN int
qmi_wds_reset_profile_to_default
(
  int                                            user_handle,
  qmi_wds_profile_tech_type                      profile_tech,
  unsigned char                                  profile_index,
  int                                            *qmi_err_code
);

/*===========================================================================
  FUNCTION  qmi_wds_reset_profile_param_invalid
===========================================================================*/
/*!
@brief
  This messages resets the given profile param type to invalid for the given
  technology

@return
  QMI_NO_ERR (0) if no error occurred, one of the other QMI_*_ERR codes (< 0)
  if an error occurred.  If return is QMI_SERVICE_ERR, the the qmi_err_code
  is valid and contains one of the QMI_SERVICE_ERR_* error codes.
  TODO: Add information about Extended error codes.

  If return is QMI_EXTENDED_ERR, then qmi_err_code does not contain
  QMI_SERVICE_ERR_* error codes, but contains subsystem(module which modem QMI
  talks to, ex: ds_profile) specific error codes.

@note

  - This function executes synchronously, there is not currently an
    asynchronous option for this functionality.

  - Dependencies
    - None.

  - Side Effects
    - None.
*/
/*=========================================================================*/
EXTERN int
qmi_wds_reset_profile_param_invalid
(
  int                                            user_handle,
  qmi_wds_profile_tech_type                      profile_tech,
  unsigned char                                  profile_index,
  qmi_wds_reset_profile_param_type               profile_param_id,
  int                                            *qmi_err_code
);

/*===========================================================================
  FUNCTION  qmi_wds_set_client_ip_pref
===========================================================================*/
/*!
@brief
  This message sends the prefered client IP family preference to the modem
  to support dual-IP over single RmNet.

@return
  QMI_NO_ERR if operation was sucessful, < 0 if not.  If return code is
  QMI_SERVICE_ERR, then the qmi_err_code will be valid and will
  indicate which QMI error occurred.

@note
  - This function executes synchronously, there is not currently an
    asynchronous option for this functionality.

  - Dependencies
    - None.

  - Side Effects
    - None.
*/
/*=========================================================================*/
int
qmi_wds_set_client_ip_pref
(
  int                          user_handle,
  qmi_ip_family_pref_type      ip_family,
  int                          *qmi_err_code
);

/*===========================================================================
  FUNCTION  qmi_wds_fmc_set_tunnel_params
===========================================================================*/
/*!
@brief
  This message sends the FMC tunnel parameters to the modem to support FMC
  mode.

@return
  QMI_NO_ERR if operation was sucessful, < 0 if not.  If return code is
  QMI_SERVICE_ERR, then the qmi_err_code will be valid and will
  indicate which QMI error occurred.

@note

  - This function executes synchronously, there is not currently an
    asynchronous option for this functionality.

  - Dependencies
    - None.

  - Side Effects
    - None.
*/
/*=========================================================================*/
EXTERN int
qmi_wds_fmc_set_tunnel_params
(
  int                             user_handle,
  qmi_wds_fmc_tunnel_params_type  *tunnel_params,
  int                             *qmi_err_code
);

/*===========================================================================
  FUNCTION  qmi_wds_fmc_clear_tunnel_params
===========================================================================*/
/*!
@brief
  This message clears the FMC tunnel parameters from the modem

@return
  QMI_NO_ERR if operation was sucessful, < 0 if not.  If return code is
  QMI_SERVICE_ERR, then the qmi_err_code will be valid and will
  indicate which QMI error occurred.

@note

  - This function executes synchronously, there is not currently an
    asynchronous option for this functionality.

  - Dependencies
    - None.

  - Side Effects
    - None.
*/
/*=========================================================================*/
EXTERN int
qmi_wds_fmc_clear_tunnel_params
(
  int    user_handle,
  int    *qmi_err_code
);


/*===========================================================================
  FUNCTION  qmi_wds_fmc_get_tunnel_params
===========================================================================*/
/*!
@brief
  This command gets the FMC tunnel parameters from the modem.

@return
  QMI_NO_ERR if operation was sucessful, < 0 if not.  If return code is
  QMI_SERVICE_ERR, then the qmi_err_code will be valid and will
  indicate which QMI error occurred.

@note

  - This function executes synchronously, there is not currently an
    asynchronous option for this functionality.

  - Dependencies
    - None.

  - Side Effects
    - None.
*/
/*=========================================================================*/
EXTERN int
qmi_wds_fmc_get_tunnel_params
(
  int                             user_handle,
  qmi_wds_fmc_tunnel_params_type  *tunnel_params,
  int                             *qmi_err_code
);
/*===========================================================================
  FUNCTION  qmi_wds_set_mip_mode
===========================================================================*/
/*!
@brief
  This command sets the current Mobile IP setting for the device.

@return
  QMI_NO_ERR if operation was sucessful, < 0 if not.  If return code is
  QMI_SERVICE_ERR, then the qmi_err_code will be valid and will
  indicate which QMI error occurred.

@note

  - This function executes synchronously, there is not currently an
    asynchronous option for this functionality.

  - Dependencies
    - None.

  - Side Effects
    - None.
*/
/*=========================================================================*/
EXTERN int
qmi_wds_set_mip_mode
(
  int                             user_handle,
  qmi_wds_mobile_ip_mode_type     mip_mode,
  int                             *qmi_err_code
);

/*===========================================================================
  FUNCTION  qmi_wds_get_mip_mode
===========================================================================*/
/*!
@brief
  This command gets the current Mobile IP setting for the device.

@return
  QMI_NO_ERR if operation was sucessful, < 0 if not.  If return code is
  QMI_SERVICE_ERR, then the qmi_err_code will be valid and will
  indicate which QMI error occurred.

@note

  - This function executes synchronously, there is not currently an
    asynchronous option for this functionality.

  - Dependencies
    - None.

  - Side Effects
    - None.
*/
/*=========================================================================*/
EXTERN int
qmi_wds_get_mip_mode
(
  int                             user_handle,
  qmi_wds_mobile_ip_mode_type     *mip_mode_resp,
  int                             *qmi_err_code
);


/*===========================================================================
  FUNCTION  qmi_wds_get_active_mip_profile
===========================================================================*/
/*!
@brief
  This command queries the current mobile IP profile index for the device.

@return
  QMI_NO_ERR if operation was sucessful, < 0 if not.  If return code is
  QMI_SERVICE_ERR, then the qmi_err_code will be valid and will
  indicate which QMI error occurred.

@note

  - This function executes synchronously, there is not currently an
    asynchronous option for this functionality.

  - Dependencies
    - None.

  - Side Effects
    - None.
*/
/*=========================================================================*/
EXTERN int
qmi_wds_get_active_mip_profile
(
  int                             user_handle,
  unsigned char                   *mip_profile_index,
  int                             *qmi_err_code
);


/*===========================================================================
  FUNCTION  qmi_wds_set_active_mip_profile
===========================================================================*/
/*!
@brief
  This command sets the current mobile IP profile index for the device.

@return
  QMI_NO_ERR if operation was sucessful, < 0 if not.  If return code is
  QMI_SERVICE_ERR, then the qmi_err_code will be valid and will
  indicate which QMI error occurred.

@note

  - This function executes synchronously, there is not currently an
    asynchronous option for this functionality.

  - Dependencies
    - None.

  - Side Effects
    - None.
*/
/*=========================================================================*/
EXTERN int
qmi_wds_set_active_mip_profile
(
  int                             user_handle,
  srvc_programming_code_type      service_code,
  unsigned char                   profile_index,
  int                             *qmi_err_code
);


/*===========================================================================
  FUNCTION  qmi_wds_read_mip_profile
===========================================================================*/
/*!
@brief
  This command queries a mobile IP profile from the modem.

@return
  QMI_NO_ERR if operation was sucessful, < 0 if not.  If return code is
  QMI_SERVICE_ERR, then the qmi_err_code will be valid and will
  indicate which QMI error occurred.

@note

  - This function executes synchronously, there is not currently an
    asynchronous option for this functionality.

  - Dependencies
    - None.

  - Side Effects
    - None.
*/
/*=========================================================================*/
EXTERN int
qmi_wds_read_mip_profile
(
  int                                         user_handle,
  unsigned char                               profile_id,
  qmi_wds_read_mobile_ip_profile_resp_type    *profile_resp,
  int                                         *qmi_err_code
);

/*===========================================================================
  FUNCTION  qmi_wds_modify_mip_profile
===========================================================================*/
/*!
@brief
  This command modifies a mobile IP profile on the device.

@return
  QMI_NO_ERR if operation was sucessful, < 0 if not.  If return code is
  QMI_SERVICE_ERR, then the qmi_err_code will be valid and will
  indicate which QMI error occurred.

@note

  - This function executes synchronously, there is not currently an
    asynchronous option for this functionality.

  - Dependencies
    - None.

  - Side Effects
    - None.
*/
/*=========================================================================*/
EXTERN int
qmi_wds_modify_mip_profile
(
  int                                         user_handle,
  srvc_programming_code_type                  service_code,
  unsigned char                               profile_index,
  qmi_wds_modify_mobile_ip_profile_req_type   *modify_profile_req,
  int                                         *qmi_err_code
);


/*===========================================================================
  FUNCTION  qmi_wds_get_pref_data_system
===========================================================================*/
/*!
@brief
  This message queries the current preferred data system.

@return
  QMI_NO_ERR if operation was sucessful, < 0 if not.  If return code is
  QMI_SERVICE_ERR, then the qmi_err_code will be valid and will
  indicate which QMI error occurred.

@note

  - This function executes synchronously, there is not currently an
    asynchronous option for this functionality.

  - Dependencies
    - None.

  - Side Effects
    - None.
*/
/*=========================================================================*/
EXTERN int
qmi_wds_get_pref_data_system
(
  int                         user_handle,
  qmi_wds_pref_data_sys_type  *cur_pref_sys,
  int                         *qmi_err_code
);


/*===========================================================================
  FUNCTION  qmi_wds_get_current_data_system_status
===========================================================================*/
/*!
@brief
  This message queries the current data system status.

@return
  QMI_NO_ERR if operation was sucessful, < 0 if not.  If return code is
  QMI_SERVICE_ERR, then the qmi_err_code will be valid and will
  indicate which QMI error occurred.

@param
  user_handle  [in]       - QMI user handle
  pref_network [out]      - Preferred network
  network_info [in]       - Pointer to an array for storing the network info
                            data
  network_info_len[inout] - Size of network_info array
  qmi_err_code [out]      - QMI error code when return value < 0

@note

  - This function executes synchronously, there is not currently an
    asynchronous option for this functionality.

  - It is assumed that sufficient memory is allocated by the client for the
    network_info buffer. The number of entries actually stored is returned
    via network_info_len

  - Dependencies
    - None.

  - Side Effects
    - None.
*/
/*=========================================================================*/
EXTERN int
qmi_wds_get_current_data_system_status
(
  int                                        user_handle,
  qmi_wds_data_network_type                  *pref_network,
  qmi_wds_data_sys_status_network_info_type  *network_info,
  unsigned int                               *network_info_len,
  int                                        *qmi_err_code
);

/*===========================================================================
  FUNCTION  qmi_wds_reset_pkt_statistics
===========================================================================*/
/*!
@brief
  This message is used to reset packet data statistics of the interface
  associated with the user_handle.

@return
  QMI_NO_ERR if operation was sucessful, < 0 if not.  If return code is
  QMI_SERVICE_ERR, then the qmi_err_code will be valid and will
  indicate which QMI error occurred.

@note

  - This function executes synchronously, there is not currently an
    asynchronous option for this functionality.

  - Dependencies
    - None.

  - Side Effects
    - None.
*/
/*=========================================================================*/
int
qmi_wds_reset_pkt_statistics
(
  int                               user_handle,
  int                               *qmi_err_code
);

#ifdef __cplusplus
}
#endif

#endif /* QMI_WDS_SRVC_H  */