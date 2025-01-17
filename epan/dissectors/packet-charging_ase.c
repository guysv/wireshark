/* Do not modify this file. Changes will be overwritten.                      */
/* Generated automatically by the ASN.1 to Wireshark dissector compiler       */
/* packet-charging_ase.c                                                      */
/* asn2wrs.py -b -q -L -p charging_ase -c ./charging_ase.cnf -s ./packet-charging_ase-template -D . -O ../.. Tariffing-Data-Types.asn */

/* packet-charging_ase-template.c
 * Copyright 2009 , Anders Broman <anders.broman [AT] ericsson.com>
 *
 * Wireshark - Network traffic analyzer
 * By Gerald Combs <gerald@wireshark.org>
 * Copyright 1998 Gerald Combs
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 * References: ETSI ES 201 296 V1.3.1 (2003-04)
 */

#include "config.h"

#include <epan/packet.h>
#include <epan/expert.h>
#include <epan/asn1.h>

#include "packet-ber.h"
#include "packet-charging_ase.h"

#define PNAME  "Charging ASE"
#define PSNAME "ChargingASE"
#define PFNAME "chargingase"

void proto_register_charging_ase(void);
void proto_reg_handoff_charging_ase(void);

/* Define the Charging ASE proto */
static int proto_charging_ase;

static int hf_charging_ase_charging_ase_ChargingMessageType_PDU;  /* ChargingMessageType */
static int hf_charging_ase_crgt;                  /* ChargingTariffInformation */
static int hf_charging_ase_aocrg;                 /* AddOnChargingInformation */
static int hf_charging_ase_crga;                  /* ChargingAcknowledgementInformation */
static int hf_charging_ase_start;                 /* StartCharging */
static int hf_charging_ase_stop;                  /* StopCharging */
static int hf_charging_ase_acknowledgementIndicators;  /* T_acknowledgementIndicators */
static int hf_charging_ase_extensions;            /* SEQUENCE_SIZE_1_numOfExtensions_OF_ExtensionField */
static int hf_charging_ase_extensions_item;       /* ExtensionField */
static int hf_charging_ase_originationIdentification;  /* ChargingReferenceIdentification */
static int hf_charging_ase_destinationIdentification;  /* ChargingReferenceIdentification */
static int hf_charging_ase_chargingControlIndicators;  /* ChargingControlIndicators */
static int hf_charging_ase_addOncharge;           /* T_addOncharge */
static int hf_charging_ase_addOnChargeCurrency;   /* CurrencyFactorScale */
static int hf_charging_ase_addOnChargePulse;      /* PulseUnits */
static int hf_charging_ase_currency;              /* Currency */
static int hf_charging_ase_chargingTariff;        /* T_chargingTariff */
static int hf_charging_ase_tariffCurrency;        /* TariffCurrency */
static int hf_charging_ase_tariffPulse;           /* TariffPulse */
static int hf_charging_ase_local;                 /* INTEGER */
static int hf_charging_ase_global;                /* OBJECT_IDENTIFIER */
static int hf_charging_ase_currencyFactorScale;   /* CurrencyFactorScale */
static int hf_charging_ase_tariffDuration;        /* TariffDuration */
static int hf_charging_ase_subTariffControl;      /* SubTariffControl */
static int hf_charging_ase_pulseUnits;            /* PulseUnits */
static int hf_charging_ase_chargeUnitTimeInterval;  /* ChargeUnitTimeInterval */
static int hf_charging_ase_currencyFactor;        /* CurrencyFactor */
static int hf_charging_ase_currencyScale;         /* CurrencyScale */
static int hf_charging_ase_type;                  /* Code */
static int hf_charging_ase_criticality;           /* CriticalityType */
static int hf_charging_ase_value;                 /* T_value */
static int hf_charging_ase_networkOperators;      /* SEQUENCE_SIZE_1_maxNetworkOperators_OF_NetworkIdentification */
static int hf_charging_ase_networkOperators_item;  /* NetworkIdentification */
static int hf_charging_ase_stopIndicators;        /* T_stopIndicators */
static int hf_charging_ase_currentTariffCurrency;  /* TariffCurrencyFormat */
static int hf_charging_ase_tariffSwitchCurrency;  /* TariffSwitchCurrency */
static int hf_charging_ase_nextTariffCurrency;    /* TariffCurrencyFormat */
static int hf_charging_ase_tariffSwitchoverTime;  /* TariffSwitchoverTime */
static int hf_charging_ase_communicationChargeSequenceCurrency;  /* SEQUENCE_SIZE_minCommunicationTariffNum_maxCommunicationTariffNum_OF_CommunicationChargeCurrency */
static int hf_charging_ase_communicationChargeSequenceCurrency_item;  /* CommunicationChargeCurrency */
static int hf_charging_ase_tariffControlIndicators;  /* T_tariffControlIndicators */
static int hf_charging_ase_callAttemptChargeCurrency;  /* CurrencyFactorScale */
static int hf_charging_ase_callSetupChargeCurrency;  /* CurrencyFactorScale */
static int hf_charging_ase_currentTariffPulse;    /* TariffPulseFormat */
static int hf_charging_ase_tariffSwitchPulse;     /* TariffSwitchPulse */
static int hf_charging_ase_nextTariffPulse;       /* TariffPulseFormat */
static int hf_charging_ase_communicationChargeSequencePulse;  /* SEQUENCE_SIZE_minCommunicationTariffNum_maxCommunicationTariffNum_OF_CommunicationChargePulse */
static int hf_charging_ase_communicationChargeSequencePulse_item;  /* CommunicationChargePulse */
static int hf_charging_ase_tariffControlIndicators_01;  /* T_tariffControlIndicators_01 */
static int hf_charging_ase_callAttemptChargePulse;  /* PulseUnits */
static int hf_charging_ase_callSetupChargePulse;  /* PulseUnits */
static int hf_charging_ase_networkIdentification;  /* NetworkIdentification */
static int hf_charging_ase_referenceID;           /* ReferenceID */
/* named bits */
static int hf_charging_ase_T_acknowledgementIndicators_accepted;
static int hf_charging_ase_ChargingControlIndicators_subscriberCharge;
static int hf_charging_ase_ChargingControlIndicators_immediateChangeOfActuallyAppliedTariff;
static int hf_charging_ase_ChargingControlIndicators_delayUntilStart;
static int hf_charging_ase_T_stopIndicators_callAttemptChargesApplicable;
static int hf_charging_ase_SubTariffControl_oneTimeCharge;
static int hf_charging_ase_T_tariffControlIndicators_non_cyclicTariff;
static int hf_charging_ase_T_tariffControlIndicators_01_non_cyclicTariff;

static int ett_charging_ase;
static int ett_charging_ase_ChargingMessageType;
static int ett_charging_ase_ChargingAcknowledgementInformation;
static int ett_charging_ase_T_acknowledgementIndicators;
static int ett_charging_ase_SEQUENCE_SIZE_1_numOfExtensions_OF_ExtensionField;
static int ett_charging_ase_ChargingControlIndicators;
static int ett_charging_ase_AddOnChargingInformation;
static int ett_charging_ase_T_addOncharge;
static int ett_charging_ase_ChargingTariffInformation;
static int ett_charging_ase_T_chargingTariff;
static int ett_charging_ase_Code;
static int ett_charging_ase_CommunicationChargeCurrency;
static int ett_charging_ase_CommunicationChargePulse;
static int ett_charging_ase_CurrencyFactorScale;
static int ett_charging_ase_ExtensionField;
static int ett_charging_ase_StartCharging;
static int ett_charging_ase_SEQUENCE_SIZE_1_maxNetworkOperators_OF_NetworkIdentification;
static int ett_charging_ase_StopCharging;
static int ett_charging_ase_T_stopIndicators;
static int ett_charging_ase_SubTariffControl;
static int ett_charging_ase_TariffCurrency;
static int ett_charging_ase_TariffSwitchCurrency;
static int ett_charging_ase_TariffCurrencyFormat;
static int ett_charging_ase_SEQUENCE_SIZE_minCommunicationTariffNum_maxCommunicationTariffNum_OF_CommunicationChargeCurrency;
static int ett_charging_ase_T_tariffControlIndicators;
static int ett_charging_ase_TariffPulse;
static int ett_charging_ase_TariffSwitchPulse;
static int ett_charging_ase_TariffPulseFormat;
static int ett_charging_ase_SEQUENCE_SIZE_minCommunicationTariffNum_maxCommunicationTariffNum_OF_CommunicationChargePulse;
static int ett_charging_ase_T_tariffControlIndicators_01;
static int ett_charging_ase_ChargingReferenceIdentification;

static expert_field ei_charging_ase_extensions_not_dissected;

static dissector_handle_t charging_ase_handle;


static int * const ChargingControlIndicators_bits[] = {
  &hf_charging_ase_ChargingControlIndicators_subscriberCharge,
  &hf_charging_ase_ChargingControlIndicators_immediateChangeOfActuallyAppliedTariff,
  &hf_charging_ase_ChargingControlIndicators_delayUntilStart,
  NULL
};

static int
dissect_charging_ase_ChargingControlIndicators(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
                                    ChargingControlIndicators_bits, 3, hf_index, ett_charging_ase_ChargingControlIndicators,
                                    NULL);

  return offset;
}



static int
dissect_charging_ase_CurrencyFactor(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
                                                NULL);

  return offset;
}



static int
dissect_charging_ase_CurrencyScale(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
                                                NULL);

  return offset;
}


static const ber_sequence_t CurrencyFactorScale_sequence[] = {
  { &hf_charging_ase_currencyFactor, BER_CLASS_CON, 0, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_charging_ase_CurrencyFactor },
  { &hf_charging_ase_currencyScale, BER_CLASS_CON, 1, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_charging_ase_CurrencyScale },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_charging_ase_CurrencyFactorScale(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
                                   CurrencyFactorScale_sequence, hf_index, ett_charging_ase_CurrencyFactorScale);

  return offset;
}



static int
dissect_charging_ase_TariffDuration(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
                                                NULL);

  return offset;
}


static int * const SubTariffControl_bits[] = {
  &hf_charging_ase_SubTariffControl_oneTimeCharge,
  NULL
};

static int
dissect_charging_ase_SubTariffControl(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
                                    SubTariffControl_bits, 1, hf_index, ett_charging_ase_SubTariffControl,
                                    NULL);

  return offset;
}


static const ber_sequence_t CommunicationChargeCurrency_sequence[] = {
  { &hf_charging_ase_currencyFactorScale, BER_CLASS_CON, 0, BER_FLAGS_IMPLTAG, dissect_charging_ase_CurrencyFactorScale },
  { &hf_charging_ase_tariffDuration, BER_CLASS_CON, 1, BER_FLAGS_IMPLTAG, dissect_charging_ase_TariffDuration },
  { &hf_charging_ase_subTariffControl, BER_CLASS_CON, 2, BER_FLAGS_IMPLTAG, dissect_charging_ase_SubTariffControl },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_charging_ase_CommunicationChargeCurrency(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
                                   CommunicationChargeCurrency_sequence, hf_index, ett_charging_ase_CommunicationChargeCurrency);

  return offset;
}


static const ber_sequence_t SEQUENCE_SIZE_minCommunicationTariffNum_maxCommunicationTariffNum_OF_CommunicationChargeCurrency_sequence_of[1] = {
  { &hf_charging_ase_communicationChargeSequenceCurrency_item, BER_CLASS_UNI, BER_UNI_TAG_SEQUENCE, BER_FLAGS_NOOWNTAG, dissect_charging_ase_CommunicationChargeCurrency },
};

static int
dissect_charging_ase_SEQUENCE_SIZE_minCommunicationTariffNum_maxCommunicationTariffNum_OF_CommunicationChargeCurrency(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
                                      SEQUENCE_SIZE_minCommunicationTariffNum_maxCommunicationTariffNum_OF_CommunicationChargeCurrency_sequence_of, hf_index, ett_charging_ase_SEQUENCE_SIZE_minCommunicationTariffNum_maxCommunicationTariffNum_OF_CommunicationChargeCurrency);

  return offset;
}


static int * const T_tariffControlIndicators_bits[] = {
  &hf_charging_ase_T_tariffControlIndicators_non_cyclicTariff,
  NULL
};

static int
dissect_charging_ase_T_tariffControlIndicators(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
                                    T_tariffControlIndicators_bits, 1, hf_index, ett_charging_ase_T_tariffControlIndicators,
                                    NULL);

  return offset;
}


static const ber_sequence_t TariffCurrencyFormat_sequence[] = {
  { &hf_charging_ase_communicationChargeSequenceCurrency, BER_CLASS_CON, 0, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_charging_ase_SEQUENCE_SIZE_minCommunicationTariffNum_maxCommunicationTariffNum_OF_CommunicationChargeCurrency },
  { &hf_charging_ase_tariffControlIndicators, BER_CLASS_CON, 1, BER_FLAGS_IMPLTAG, dissect_charging_ase_T_tariffControlIndicators },
  { &hf_charging_ase_callAttemptChargeCurrency, BER_CLASS_CON, 2, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_charging_ase_CurrencyFactorScale },
  { &hf_charging_ase_callSetupChargeCurrency, BER_CLASS_CON, 3, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_charging_ase_CurrencyFactorScale },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_charging_ase_TariffCurrencyFormat(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
                                   TariffCurrencyFormat_sequence, hf_index, ett_charging_ase_TariffCurrencyFormat);

  return offset;
}



static int
dissect_charging_ase_TariffSwitchoverTime(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}


static const ber_sequence_t TariffSwitchCurrency_sequence[] = {
  { &hf_charging_ase_nextTariffCurrency, BER_CLASS_CON, 0, BER_FLAGS_IMPLTAG, dissect_charging_ase_TariffCurrencyFormat },
  { &hf_charging_ase_tariffSwitchoverTime, BER_CLASS_CON, 1, BER_FLAGS_IMPLTAG, dissect_charging_ase_TariffSwitchoverTime },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_charging_ase_TariffSwitchCurrency(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
                                   TariffSwitchCurrency_sequence, hf_index, ett_charging_ase_TariffSwitchCurrency);

  return offset;
}


static const ber_sequence_t TariffCurrency_sequence[] = {
  { &hf_charging_ase_currentTariffCurrency, BER_CLASS_CON, 0, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_charging_ase_TariffCurrencyFormat },
  { &hf_charging_ase_tariffSwitchCurrency, BER_CLASS_CON, 1, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_charging_ase_TariffSwitchCurrency },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_charging_ase_TariffCurrency(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
                                   TariffCurrency_sequence, hf_index, ett_charging_ase_TariffCurrency);

  return offset;
}



static int
dissect_charging_ase_PulseUnits(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}



static int
dissect_charging_ase_ChargeUnitTimeInterval(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_octet_string(implicit_tag, actx, tree, tvb, offset, hf_index,
                                       NULL);

  return offset;
}


static const ber_sequence_t CommunicationChargePulse_sequence[] = {
  { &hf_charging_ase_pulseUnits, BER_CLASS_CON, 0, BER_FLAGS_IMPLTAG, dissect_charging_ase_PulseUnits },
  { &hf_charging_ase_chargeUnitTimeInterval, BER_CLASS_CON, 1, BER_FLAGS_IMPLTAG, dissect_charging_ase_ChargeUnitTimeInterval },
  { &hf_charging_ase_tariffDuration, BER_CLASS_CON, 2, BER_FLAGS_IMPLTAG, dissect_charging_ase_TariffDuration },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_charging_ase_CommunicationChargePulse(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
                                   CommunicationChargePulse_sequence, hf_index, ett_charging_ase_CommunicationChargePulse);

  return offset;
}


static const ber_sequence_t SEQUENCE_SIZE_minCommunicationTariffNum_maxCommunicationTariffNum_OF_CommunicationChargePulse_sequence_of[1] = {
  { &hf_charging_ase_communicationChargeSequencePulse_item, BER_CLASS_UNI, BER_UNI_TAG_SEQUENCE, BER_FLAGS_NOOWNTAG, dissect_charging_ase_CommunicationChargePulse },
};

static int
dissect_charging_ase_SEQUENCE_SIZE_minCommunicationTariffNum_maxCommunicationTariffNum_OF_CommunicationChargePulse(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
                                      SEQUENCE_SIZE_minCommunicationTariffNum_maxCommunicationTariffNum_OF_CommunicationChargePulse_sequence_of, hf_index, ett_charging_ase_SEQUENCE_SIZE_minCommunicationTariffNum_maxCommunicationTariffNum_OF_CommunicationChargePulse);

  return offset;
}


static int * const T_tariffControlIndicators_01_bits[] = {
  &hf_charging_ase_T_tariffControlIndicators_01_non_cyclicTariff,
  NULL
};

static int
dissect_charging_ase_T_tariffControlIndicators_01(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
                                    T_tariffControlIndicators_01_bits, 1, hf_index, ett_charging_ase_T_tariffControlIndicators_01,
                                    NULL);

  return offset;
}


static const ber_sequence_t TariffPulseFormat_sequence[] = {
  { &hf_charging_ase_communicationChargeSequencePulse, BER_CLASS_CON, 0, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_charging_ase_SEQUENCE_SIZE_minCommunicationTariffNum_maxCommunicationTariffNum_OF_CommunicationChargePulse },
  { &hf_charging_ase_tariffControlIndicators_01, BER_CLASS_CON, 1, BER_FLAGS_IMPLTAG, dissect_charging_ase_T_tariffControlIndicators_01 },
  { &hf_charging_ase_callAttemptChargePulse, BER_CLASS_CON, 2, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_charging_ase_PulseUnits },
  { &hf_charging_ase_callSetupChargePulse, BER_CLASS_CON, 3, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_charging_ase_PulseUnits },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_charging_ase_TariffPulseFormat(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
                                   TariffPulseFormat_sequence, hf_index, ett_charging_ase_TariffPulseFormat);

  return offset;
}


static const ber_sequence_t TariffSwitchPulse_sequence[] = {
  { &hf_charging_ase_nextTariffPulse, BER_CLASS_CON, 0, BER_FLAGS_IMPLTAG, dissect_charging_ase_TariffPulseFormat },
  { &hf_charging_ase_tariffSwitchoverTime, BER_CLASS_CON, 1, BER_FLAGS_IMPLTAG, dissect_charging_ase_TariffSwitchoverTime },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_charging_ase_TariffSwitchPulse(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
                                   TariffSwitchPulse_sequence, hf_index, ett_charging_ase_TariffSwitchPulse);

  return offset;
}


static const ber_sequence_t TariffPulse_sequence[] = {
  { &hf_charging_ase_currentTariffPulse, BER_CLASS_CON, 0, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_charging_ase_TariffPulseFormat },
  { &hf_charging_ase_tariffSwitchPulse, BER_CLASS_CON, 1, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_charging_ase_TariffSwitchPulse },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_charging_ase_TariffPulse(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
                                   TariffPulse_sequence, hf_index, ett_charging_ase_TariffPulse);

  return offset;
}


static const value_string charging_ase_T_chargingTariff_vals[] = {
  {   0, "tariffCurrency" },
  {   1, "tariffPulse" },
  { 0, NULL }
};

static const ber_choice_t T_chargingTariff_choice[] = {
  {   0, &hf_charging_ase_tariffCurrency, BER_CLASS_CON, 0, BER_FLAGS_IMPLTAG, dissect_charging_ase_TariffCurrency },
  {   1, &hf_charging_ase_tariffPulse, BER_CLASS_CON, 1, BER_FLAGS_IMPLTAG, dissect_charging_ase_TariffPulse },
  { 0, NULL, 0, 0, 0, NULL }
};

static int
dissect_charging_ase_T_chargingTariff(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_choice(actx, tree, tvb, offset,
                                 T_chargingTariff_choice, hf_index, ett_charging_ase_T_chargingTariff,
                                 NULL);

  return offset;
}



static int
dissect_charging_ase_INTEGER(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
                                                NULL);

  return offset;
}



static int
dissect_charging_ase_OBJECT_IDENTIFIER(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_object_identifier(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);

  return offset;
}


static const value_string charging_ase_Code_vals[] = {
  {   0, "local" },
  {   1, "global" },
  { 0, NULL }
};

static const ber_choice_t Code_choice[] = {
  {   0, &hf_charging_ase_local  , BER_CLASS_UNI, BER_UNI_TAG_INTEGER, BER_FLAGS_NOOWNTAG, dissect_charging_ase_INTEGER },
  {   1, &hf_charging_ase_global , BER_CLASS_UNI, BER_UNI_TAG_OID, BER_FLAGS_NOOWNTAG, dissect_charging_ase_OBJECT_IDENTIFIER },
  { 0, NULL, 0, 0, 0, NULL }
};

static int
dissect_charging_ase_Code(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_choice(actx, tree, tvb, offset,
                                 Code_choice, hf_index, ett_charging_ase_Code,
                                 NULL);

  return offset;
}


static const value_string charging_ase_CriticalityType_vals[] = {
  {   0, "ignore" },
  {   1, "abort" },
  { 0, NULL }
};


static int
dissect_charging_ase_CriticalityType(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
                                  NULL);

  return offset;
}



static int
dissect_charging_ase_T_value(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {

	proto_tree_add_expert(tree, actx->pinfo, &ei_charging_ase_extensions_not_dissected, tvb, offset, -1);
	return tvb_reported_length(tvb);

  return offset;
}


static const ber_sequence_t ExtensionField_sequence[] = {
  { &hf_charging_ase_type   , BER_CLASS_ANY/*choice*/, -1/*choice*/, BER_FLAGS_NOOWNTAG|BER_FLAGS_NOTCHKTAG, dissect_charging_ase_Code },
  { &hf_charging_ase_criticality, BER_CLASS_UNI, BER_UNI_TAG_ENUMERATED, BER_FLAGS_OPTIONAL|BER_FLAGS_NOOWNTAG, dissect_charging_ase_CriticalityType },
  { &hf_charging_ase_value  , BER_CLASS_CON, 1, BER_FLAGS_IMPLTAG, dissect_charging_ase_T_value },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_charging_ase_ExtensionField(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
                                   ExtensionField_sequence, hf_index, ett_charging_ase_ExtensionField);

  return offset;
}


static const ber_sequence_t SEQUENCE_SIZE_1_numOfExtensions_OF_ExtensionField_sequence_of[1] = {
  { &hf_charging_ase_extensions_item, BER_CLASS_UNI, BER_UNI_TAG_SEQUENCE, BER_FLAGS_NOOWNTAG, dissect_charging_ase_ExtensionField },
};

static int
dissect_charging_ase_SEQUENCE_SIZE_1_numOfExtensions_OF_ExtensionField(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
                                      SEQUENCE_SIZE_1_numOfExtensions_OF_ExtensionField_sequence_of, hf_index, ett_charging_ase_SEQUENCE_SIZE_1_numOfExtensions_OF_ExtensionField);

  return offset;
}



static int
dissect_charging_ase_NetworkIdentification(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_object_identifier(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);

  return offset;
}



static int
dissect_charging_ase_ReferenceID(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
                                                NULL);

  return offset;
}


static const ber_sequence_t ChargingReferenceIdentification_sequence[] = {
  { &hf_charging_ase_networkIdentification, BER_CLASS_CON, 0, BER_FLAGS_IMPLTAG, dissect_charging_ase_NetworkIdentification },
  { &hf_charging_ase_referenceID, BER_CLASS_CON, 1, BER_FLAGS_IMPLTAG, dissect_charging_ase_ReferenceID },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_charging_ase_ChargingReferenceIdentification(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
                                   ChargingReferenceIdentification_sequence, hf_index, ett_charging_ase_ChargingReferenceIdentification);

  return offset;
}


static const value_string charging_ase_Currency_vals[] = {
  {   0, "noIndication" },
  {   1, "australianDollar" },
  {   2, "austrianSchilling" },
  {   3, "belgianFranc" },
  {   4, "britishPound" },
  {   5, "czechKoruna" },
  {   6, "danishKrone" },
  {   7, "dutchGuilder" },
  {   8, "euro" },
  {   9, "finnishMarkka" },
  {  10, "frenchFranc" },
  {  11, "germanMark" },
  {  12, "greekDrachma" },
  {  13, "hungarianForint" },
  {  14, "irishPunt" },
  {  15, "italianLira" },
  {  16, "japaneseYen" },
  {  17, "luxembourgian-Franc" },
  {  18, "norwegianKrone" },
  {  19, "polishZloty" },
  {  20, "portugeseEscudo" },
  {  21, "russianRouble" },
  {  22, "slovakKoruna" },
  {  23, "spanishPeseta" },
  {  24, "swedishKrone" },
  {  25, "swissFranc" },
  {  26, "turkishLira" },
  {  27, "uSDollar" },
  { 0, NULL }
};


static int
dissect_charging_ase_Currency(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
                                  NULL);

  return offset;
}


static const ber_sequence_t ChargingTariffInformation_sequence[] = {
  { &hf_charging_ase_chargingControlIndicators, BER_CLASS_CON, 0, BER_FLAGS_IMPLTAG, dissect_charging_ase_ChargingControlIndicators },
  { &hf_charging_ase_chargingTariff, BER_CLASS_CON, 1, BER_FLAGS_IMPLTAG, dissect_charging_ase_T_chargingTariff },
  { &hf_charging_ase_extensions, BER_CLASS_CON, 2, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_charging_ase_SEQUENCE_SIZE_1_numOfExtensions_OF_ExtensionField },
  { &hf_charging_ase_originationIdentification, BER_CLASS_CON, 3, BER_FLAGS_IMPLTAG, dissect_charging_ase_ChargingReferenceIdentification },
  { &hf_charging_ase_destinationIdentification, BER_CLASS_CON, 4, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_charging_ase_ChargingReferenceIdentification },
  { &hf_charging_ase_currency, BER_CLASS_CON, 5, BER_FLAGS_IMPLTAG, dissect_charging_ase_Currency },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_charging_ase_ChargingTariffInformation(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
                                   ChargingTariffInformation_sequence, hf_index, ett_charging_ase_ChargingTariffInformation);

  return offset;
}


static const value_string charging_ase_T_addOncharge_vals[] = {
  {   0, "addOnChargeCurrency" },
  {   1, "addOnChargePulse" },
  { 0, NULL }
};

static const ber_choice_t T_addOncharge_choice[] = {
  {   0, &hf_charging_ase_addOnChargeCurrency, BER_CLASS_CON, 0, BER_FLAGS_IMPLTAG, dissect_charging_ase_CurrencyFactorScale },
  {   1, &hf_charging_ase_addOnChargePulse, BER_CLASS_CON, 1, BER_FLAGS_IMPLTAG, dissect_charging_ase_PulseUnits },
  { 0, NULL, 0, 0, 0, NULL }
};

static int
dissect_charging_ase_T_addOncharge(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_choice(actx, tree, tvb, offset,
                                 T_addOncharge_choice, hf_index, ett_charging_ase_T_addOncharge,
                                 NULL);

  return offset;
}


static const ber_sequence_t AddOnChargingInformation_sequence[] = {
  { &hf_charging_ase_chargingControlIndicators, BER_CLASS_CON, 0, BER_FLAGS_IMPLTAG, dissect_charging_ase_ChargingControlIndicators },
  { &hf_charging_ase_addOncharge, BER_CLASS_CON, 1, BER_FLAGS_IMPLTAG, dissect_charging_ase_T_addOncharge },
  { &hf_charging_ase_extensions, BER_CLASS_CON, 2, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_charging_ase_SEQUENCE_SIZE_1_numOfExtensions_OF_ExtensionField },
  { &hf_charging_ase_originationIdentification, BER_CLASS_CON, 3, BER_FLAGS_IMPLTAG, dissect_charging_ase_ChargingReferenceIdentification },
  { &hf_charging_ase_destinationIdentification, BER_CLASS_CON, 4, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_charging_ase_ChargingReferenceIdentification },
  { &hf_charging_ase_currency, BER_CLASS_CON, 5, BER_FLAGS_IMPLTAG, dissect_charging_ase_Currency },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_charging_ase_AddOnChargingInformation(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
                                   AddOnChargingInformation_sequence, hf_index, ett_charging_ase_AddOnChargingInformation);

  return offset;
}


static int * const T_acknowledgementIndicators_bits[] = {
  &hf_charging_ase_T_acknowledgementIndicators_accepted,
  NULL
};

static int
dissect_charging_ase_T_acknowledgementIndicators(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
                                    T_acknowledgementIndicators_bits, 1, hf_index, ett_charging_ase_T_acknowledgementIndicators,
                                    NULL);

  return offset;
}


static const ber_sequence_t ChargingAcknowledgementInformation_sequence[] = {
  { &hf_charging_ase_acknowledgementIndicators, BER_CLASS_CON, 0, BER_FLAGS_IMPLTAG, dissect_charging_ase_T_acknowledgementIndicators },
  { &hf_charging_ase_extensions, BER_CLASS_CON, 1, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_charging_ase_SEQUENCE_SIZE_1_numOfExtensions_OF_ExtensionField },
  { &hf_charging_ase_originationIdentification, BER_CLASS_CON, 2, BER_FLAGS_IMPLTAG, dissect_charging_ase_ChargingReferenceIdentification },
  { &hf_charging_ase_destinationIdentification, BER_CLASS_CON, 3, BER_FLAGS_IMPLTAG, dissect_charging_ase_ChargingReferenceIdentification },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_charging_ase_ChargingAcknowledgementInformation(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
                                   ChargingAcknowledgementInformation_sequence, hf_index, ett_charging_ase_ChargingAcknowledgementInformation);

  return offset;
}


static const ber_sequence_t SEQUENCE_SIZE_1_maxNetworkOperators_OF_NetworkIdentification_sequence_of[1] = {
  { &hf_charging_ase_networkOperators_item, BER_CLASS_UNI, BER_UNI_TAG_OID, BER_FLAGS_NOOWNTAG, dissect_charging_ase_NetworkIdentification },
};

static int
dissect_charging_ase_SEQUENCE_SIZE_1_maxNetworkOperators_OF_NetworkIdentification(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
                                      SEQUENCE_SIZE_1_maxNetworkOperators_OF_NetworkIdentification_sequence_of, hf_index, ett_charging_ase_SEQUENCE_SIZE_1_maxNetworkOperators_OF_NetworkIdentification);

  return offset;
}


static const ber_sequence_t StartCharging_sequence[] = {
  { &hf_charging_ase_networkOperators, BER_CLASS_CON, 0, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_charging_ase_SEQUENCE_SIZE_1_maxNetworkOperators_OF_NetworkIdentification },
  { &hf_charging_ase_extensions, BER_CLASS_CON, 1, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_charging_ase_SEQUENCE_SIZE_1_numOfExtensions_OF_ExtensionField },
  { &hf_charging_ase_originationIdentification, BER_CLASS_CON, 2, BER_FLAGS_IMPLTAG, dissect_charging_ase_ChargingReferenceIdentification },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_charging_ase_StartCharging(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
                                   StartCharging_sequence, hf_index, ett_charging_ase_StartCharging);

  return offset;
}


static int * const T_stopIndicators_bits[] = {
  &hf_charging_ase_T_stopIndicators_callAttemptChargesApplicable,
  NULL
};

static int
dissect_charging_ase_T_stopIndicators(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
                                    T_stopIndicators_bits, 1, hf_index, ett_charging_ase_T_stopIndicators,
                                    NULL);

  return offset;
}


static const ber_sequence_t StopCharging_sequence[] = {
  { &hf_charging_ase_stopIndicators, BER_CLASS_CON, 0, BER_FLAGS_IMPLTAG, dissect_charging_ase_T_stopIndicators },
  { &hf_charging_ase_networkOperators, BER_CLASS_CON, 1, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_charging_ase_SEQUENCE_SIZE_1_maxNetworkOperators_OF_NetworkIdentification },
  { &hf_charging_ase_extensions, BER_CLASS_CON, 2, BER_FLAGS_OPTIONAL|BER_FLAGS_IMPLTAG, dissect_charging_ase_SEQUENCE_SIZE_1_numOfExtensions_OF_ExtensionField },
  { &hf_charging_ase_originationIdentification, BER_CLASS_CON, 3, BER_FLAGS_IMPLTAG, dissect_charging_ase_ChargingReferenceIdentification },
  { NULL, 0, 0, 0, NULL }
};

static int
dissect_charging_ase_StopCharging(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
                                   StopCharging_sequence, hf_index, ett_charging_ase_StopCharging);

  return offset;
}


const value_string charging_ase_ChargingMessageType_vals[] = {
  {   0, "crgt" },
  {   1, "aocrg" },
  {   2, "crga" },
  {   3, "start" },
  {   4, "stop" },
  { 0, NULL }
};

static const ber_choice_t ChargingMessageType_choice[] = {
  {   0, &hf_charging_ase_crgt   , BER_CLASS_CON, 0, BER_FLAGS_IMPLTAG, dissect_charging_ase_ChargingTariffInformation },
  {   1, &hf_charging_ase_aocrg  , BER_CLASS_CON, 1, BER_FLAGS_IMPLTAG, dissect_charging_ase_AddOnChargingInformation },
  {   2, &hf_charging_ase_crga   , BER_CLASS_CON, 2, BER_FLAGS_IMPLTAG, dissect_charging_ase_ChargingAcknowledgementInformation },
  {   3, &hf_charging_ase_start  , BER_CLASS_CON, 3, BER_FLAGS_IMPLTAG, dissect_charging_ase_StartCharging },
  {   4, &hf_charging_ase_stop   , BER_CLASS_CON, 4, BER_FLAGS_IMPLTAG, dissect_charging_ase_StopCharging },
  { 0, NULL, 0, 0, 0, NULL }
};

int
dissect_charging_ase_ChargingMessageType(bool implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_ber_choice(actx, tree, tvb, offset,
                                 ChargingMessageType_choice, hf_index, ett_charging_ase_ChargingMessageType,
                                 NULL);

  return offset;
}

/*--- PDUs ---*/

int dissect_charging_ase_ChargingMessageType_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
  int offset = 0;
  asn1_ctx_t asn1_ctx;
  asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
  offset = dissect_charging_ase_ChargingMessageType(false, tvb, offset, &asn1_ctx, tree, hf_charging_ase_charging_ase_ChargingMessageType_PDU);
  return offset;
}


static int
dissect_charging_ase(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
    proto_item *it;
    proto_tree *tr;

    it=proto_tree_add_protocol_format(tree, proto_charging_ase, tvb, 0, -1, "Charging ASE");
    tr=proto_item_add_subtree(it, ett_charging_ase);

    if(tvb_reported_length(tvb)>0)
    {
        dissect_charging_ase_ChargingMessageType_PDU(tvb , pinfo, tr, NULL);
    }
    return tvb_captured_length(tvb);
}

/* Register all the bits needed with the filtering engine */
void
proto_register_charging_ase(void)
{
  /* List of fields */
  static hf_register_info hf[] = {
    { &hf_charging_ase_charging_ase_ChargingMessageType_PDU,
      { "ChargingMessageType", "charging_ase.ChargingMessageType",
        FT_UINT32, BASE_DEC, VALS(charging_ase_ChargingMessageType_vals), 0,
        NULL, HFILL }},
    { &hf_charging_ase_crgt,
      { "crgt", "charging_ase.crgt_element",
        FT_NONE, BASE_NONE, NULL, 0,
        "ChargingTariffInformation", HFILL }},
    { &hf_charging_ase_aocrg,
      { "aocrg", "charging_ase.aocrg_element",
        FT_NONE, BASE_NONE, NULL, 0,
        "AddOnChargingInformation", HFILL }},
    { &hf_charging_ase_crga,
      { "crga", "charging_ase.crga_element",
        FT_NONE, BASE_NONE, NULL, 0,
        "ChargingAcknowledgementInformation", HFILL }},
    { &hf_charging_ase_start,
      { "start", "charging_ase.start_element",
        FT_NONE, BASE_NONE, NULL, 0,
        "StartCharging", HFILL }},
    { &hf_charging_ase_stop,
      { "stop", "charging_ase.stop_element",
        FT_NONE, BASE_NONE, NULL, 0,
        "StopCharging", HFILL }},
    { &hf_charging_ase_acknowledgementIndicators,
      { "acknowledgementIndicators", "charging_ase.acknowledgementIndicators",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_charging_ase_extensions,
      { "extensions", "charging_ase.extensions",
        FT_UINT32, BASE_DEC, NULL, 0,
        "SEQUENCE_SIZE_1_numOfExtensions_OF_ExtensionField", HFILL }},
    { &hf_charging_ase_extensions_item,
      { "ExtensionField", "charging_ase.ExtensionField_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_charging_ase_originationIdentification,
      { "originationIdentification", "charging_ase.originationIdentification_element",
        FT_NONE, BASE_NONE, NULL, 0,
        "ChargingReferenceIdentification", HFILL }},
    { &hf_charging_ase_destinationIdentification,
      { "destinationIdentification", "charging_ase.destinationIdentification_element",
        FT_NONE, BASE_NONE, NULL, 0,
        "ChargingReferenceIdentification", HFILL }},
    { &hf_charging_ase_chargingControlIndicators,
      { "chargingControlIndicators", "charging_ase.chargingControlIndicators",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_charging_ase_addOncharge,
      { "addOncharge", "charging_ase.addOncharge",
        FT_UINT32, BASE_DEC, VALS(charging_ase_T_addOncharge_vals), 0,
        NULL, HFILL }},
    { &hf_charging_ase_addOnChargeCurrency,
      { "addOnChargeCurrency", "charging_ase.addOnChargeCurrency_element",
        FT_NONE, BASE_NONE, NULL, 0,
        "CurrencyFactorScale", HFILL }},
    { &hf_charging_ase_addOnChargePulse,
      { "addOnChargePulse", "charging_ase.addOnChargePulse",
        FT_BYTES, BASE_NONE, NULL, 0,
        "PulseUnits", HFILL }},
    { &hf_charging_ase_currency,
      { "currency", "charging_ase.currency",
        FT_UINT32, BASE_DEC, VALS(charging_ase_Currency_vals), 0,
        NULL, HFILL }},
    { &hf_charging_ase_chargingTariff,
      { "chargingTariff", "charging_ase.chargingTariff",
        FT_UINT32, BASE_DEC, VALS(charging_ase_T_chargingTariff_vals), 0,
        NULL, HFILL }},
    { &hf_charging_ase_tariffCurrency,
      { "tariffCurrency", "charging_ase.tariffCurrency_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_charging_ase_tariffPulse,
      { "tariffPulse", "charging_ase.tariffPulse_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_charging_ase_local,
      { "local", "charging_ase.local",
        FT_INT32, BASE_DEC, NULL, 0,
        "INTEGER", HFILL }},
    { &hf_charging_ase_global,
      { "global", "charging_ase.global",
        FT_OID, BASE_NONE, NULL, 0,
        "OBJECT_IDENTIFIER", HFILL }},
    { &hf_charging_ase_currencyFactorScale,
      { "currencyFactorScale", "charging_ase.currencyFactorScale_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_charging_ase_tariffDuration,
      { "tariffDuration", "charging_ase.tariffDuration",
        FT_UINT32, BASE_DEC, NULL, 0,
        NULL, HFILL }},
    { &hf_charging_ase_subTariffControl,
      { "subTariffControl", "charging_ase.subTariffControl",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_charging_ase_pulseUnits,
      { "pulseUnits", "charging_ase.pulseUnits",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_charging_ase_chargeUnitTimeInterval,
      { "chargeUnitTimeInterval", "charging_ase.chargeUnitTimeInterval",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_charging_ase_currencyFactor,
      { "currencyFactor", "charging_ase.currencyFactor",
        FT_UINT32, BASE_DEC, NULL, 0,
        NULL, HFILL }},
    { &hf_charging_ase_currencyScale,
      { "currencyScale", "charging_ase.currencyScale",
        FT_INT32, BASE_DEC, NULL, 0,
        NULL, HFILL }},
    { &hf_charging_ase_type,
      { "type", "charging_ase.type",
        FT_UINT32, BASE_DEC, VALS(charging_ase_Code_vals), 0,
        "Code", HFILL }},
    { &hf_charging_ase_criticality,
      { "criticality", "charging_ase.criticality",
        FT_UINT32, BASE_DEC, VALS(charging_ase_CriticalityType_vals), 0,
        "CriticalityType", HFILL }},
    { &hf_charging_ase_value,
      { "value", "charging_ase.value_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_charging_ase_networkOperators,
      { "networkOperators", "charging_ase.networkOperators",
        FT_UINT32, BASE_DEC, NULL, 0,
        "SEQUENCE_SIZE_1_maxNetworkOperators_OF_NetworkIdentification", HFILL }},
    { &hf_charging_ase_networkOperators_item,
      { "NetworkIdentification", "charging_ase.NetworkIdentification",
        FT_OID, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_charging_ase_stopIndicators,
      { "stopIndicators", "charging_ase.stopIndicators",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_charging_ase_currentTariffCurrency,
      { "currentTariffCurrency", "charging_ase.currentTariffCurrency_element",
        FT_NONE, BASE_NONE, NULL, 0,
        "TariffCurrencyFormat", HFILL }},
    { &hf_charging_ase_tariffSwitchCurrency,
      { "tariffSwitchCurrency", "charging_ase.tariffSwitchCurrency_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_charging_ase_nextTariffCurrency,
      { "nextTariffCurrency", "charging_ase.nextTariffCurrency_element",
        FT_NONE, BASE_NONE, NULL, 0,
        "TariffCurrencyFormat", HFILL }},
    { &hf_charging_ase_tariffSwitchoverTime,
      { "tariffSwitchoverTime", "charging_ase.tariffSwitchoverTime",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_charging_ase_communicationChargeSequenceCurrency,
      { "communicationChargeSequenceCurrency", "charging_ase.communicationChargeSequenceCurrency",
        FT_UINT32, BASE_DEC, NULL, 0,
        "SEQUENCE_SIZE_minCommunicationTariffNum_maxCommunicationTariffNum_OF_CommunicationChargeCurrency", HFILL }},
    { &hf_charging_ase_communicationChargeSequenceCurrency_item,
      { "CommunicationChargeCurrency", "charging_ase.CommunicationChargeCurrency_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_charging_ase_tariffControlIndicators,
      { "tariffControlIndicators", "charging_ase.tariffControlIndicators",
        FT_BYTES, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_charging_ase_callAttemptChargeCurrency,
      { "callAttemptChargeCurrency", "charging_ase.callAttemptChargeCurrency_element",
        FT_NONE, BASE_NONE, NULL, 0,
        "CurrencyFactorScale", HFILL }},
    { &hf_charging_ase_callSetupChargeCurrency,
      { "callSetupChargeCurrency", "charging_ase.callSetupChargeCurrency_element",
        FT_NONE, BASE_NONE, NULL, 0,
        "CurrencyFactorScale", HFILL }},
    { &hf_charging_ase_currentTariffPulse,
      { "currentTariffPulse", "charging_ase.currentTariffPulse_element",
        FT_NONE, BASE_NONE, NULL, 0,
        "TariffPulseFormat", HFILL }},
    { &hf_charging_ase_tariffSwitchPulse,
      { "tariffSwitchPulse", "charging_ase.tariffSwitchPulse_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_charging_ase_nextTariffPulse,
      { "nextTariffPulse", "charging_ase.nextTariffPulse_element",
        FT_NONE, BASE_NONE, NULL, 0,
        "TariffPulseFormat", HFILL }},
    { &hf_charging_ase_communicationChargeSequencePulse,
      { "communicationChargeSequencePulse", "charging_ase.communicationChargeSequencePulse",
        FT_UINT32, BASE_DEC, NULL, 0,
        "SEQUENCE_SIZE_minCommunicationTariffNum_maxCommunicationTariffNum_OF_CommunicationChargePulse", HFILL }},
    { &hf_charging_ase_communicationChargeSequencePulse_item,
      { "CommunicationChargePulse", "charging_ase.CommunicationChargePulse_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_charging_ase_tariffControlIndicators_01,
      { "tariffControlIndicators", "charging_ase.tariffControlIndicators",
        FT_BYTES, BASE_NONE, NULL, 0,
        "T_tariffControlIndicators_01", HFILL }},
    { &hf_charging_ase_callAttemptChargePulse,
      { "callAttemptChargePulse", "charging_ase.callAttemptChargePulse",
        FT_BYTES, BASE_NONE, NULL, 0,
        "PulseUnits", HFILL }},
    { &hf_charging_ase_callSetupChargePulse,
      { "callSetupChargePulse", "charging_ase.callSetupChargePulse",
        FT_BYTES, BASE_NONE, NULL, 0,
        "PulseUnits", HFILL }},
    { &hf_charging_ase_networkIdentification,
      { "networkIdentification", "charging_ase.networkIdentification",
        FT_OID, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_charging_ase_referenceID,
      { "referenceID", "charging_ase.referenceID",
        FT_UINT32, BASE_DEC, NULL, 0,
        NULL, HFILL }},
    { &hf_charging_ase_T_acknowledgementIndicators_accepted,
      { "accepted", "charging.ase.T.acknowledgementIndicators.accepted",
        FT_BOOLEAN, 8, NULL, 0x80,
        NULL, HFILL }},
    { &hf_charging_ase_ChargingControlIndicators_subscriberCharge,
      { "subscriberCharge", "charging.ase.ChargingControlIndicators.subscriberCharge",
        FT_BOOLEAN, 8, NULL, 0x80,
        NULL, HFILL }},
    { &hf_charging_ase_ChargingControlIndicators_immediateChangeOfActuallyAppliedTariff,
      { "immediateChangeOfActuallyAppliedTariff", "charging.ase.ChargingControlIndicators.immediateChangeOfActuallyAppliedTariff",
        FT_BOOLEAN, 8, NULL, 0x40,
        NULL, HFILL }},
    { &hf_charging_ase_ChargingControlIndicators_delayUntilStart,
      { "delayUntilStart", "charging.ase.ChargingControlIndicators.delayUntilStart",
        FT_BOOLEAN, 8, NULL, 0x20,
        NULL, HFILL }},
    { &hf_charging_ase_T_stopIndicators_callAttemptChargesApplicable,
      { "callAttemptChargesApplicable", "charging.ase.T.stopIndicators.callAttemptChargesApplicable",
        FT_BOOLEAN, 8, NULL, 0x80,
        NULL, HFILL }},
    { &hf_charging_ase_SubTariffControl_oneTimeCharge,
      { "oneTimeCharge", "charging.ase.SubTariffControl.oneTimeCharge",
        FT_BOOLEAN, 8, NULL, 0x80,
        NULL, HFILL }},
    { &hf_charging_ase_T_tariffControlIndicators_non_cyclicTariff,
      { "non-cyclicTariff", "charging.ase.T.tariffControlIndicators.non.cyclicTariff",
        FT_BOOLEAN, 8, NULL, 0x80,
        NULL, HFILL }},
    { &hf_charging_ase_T_tariffControlIndicators_01_non_cyclicTariff,
      { "non-cyclicTariff", "charging.ase.T.tariffControlIndicators.01.non.cyclicTariff",
        FT_BOOLEAN, 8, NULL, 0x80,
        NULL, HFILL }},
  };

  /* List of subtrees */
    static gint *ett[] = {
    &ett_charging_ase,
    &ett_charging_ase_ChargingMessageType,
    &ett_charging_ase_ChargingAcknowledgementInformation,
    &ett_charging_ase_T_acknowledgementIndicators,
    &ett_charging_ase_SEQUENCE_SIZE_1_numOfExtensions_OF_ExtensionField,
    &ett_charging_ase_ChargingControlIndicators,
    &ett_charging_ase_AddOnChargingInformation,
    &ett_charging_ase_T_addOncharge,
    &ett_charging_ase_ChargingTariffInformation,
    &ett_charging_ase_T_chargingTariff,
    &ett_charging_ase_Code,
    &ett_charging_ase_CommunicationChargeCurrency,
    &ett_charging_ase_CommunicationChargePulse,
    &ett_charging_ase_CurrencyFactorScale,
    &ett_charging_ase_ExtensionField,
    &ett_charging_ase_StartCharging,
    &ett_charging_ase_SEQUENCE_SIZE_1_maxNetworkOperators_OF_NetworkIdentification,
    &ett_charging_ase_StopCharging,
    &ett_charging_ase_T_stopIndicators,
    &ett_charging_ase_SubTariffControl,
    &ett_charging_ase_TariffCurrency,
    &ett_charging_ase_TariffSwitchCurrency,
    &ett_charging_ase_TariffCurrencyFormat,
    &ett_charging_ase_SEQUENCE_SIZE_minCommunicationTariffNum_maxCommunicationTariffNum_OF_CommunicationChargeCurrency,
    &ett_charging_ase_T_tariffControlIndicators,
    &ett_charging_ase_TariffPulse,
    &ett_charging_ase_TariffSwitchPulse,
    &ett_charging_ase_TariffPulseFormat,
    &ett_charging_ase_SEQUENCE_SIZE_minCommunicationTariffNum_maxCommunicationTariffNum_OF_CommunicationChargePulse,
    &ett_charging_ase_T_tariffControlIndicators_01,
    &ett_charging_ase_ChargingReferenceIdentification,
        };

  static ei_register_info ei[] = {
      { &ei_charging_ase_extensions_not_dissected, { "charging_ase.extensions_not_dissected", PI_UNDECODED, PI_WARN, "Extensions not dissected", EXPFILL }},
  };

  expert_module_t* expert_charging_ase;

  proto_charging_ase = proto_register_protocol(PNAME, PSNAME, PFNAME);

  proto_register_field_array(proto_charging_ase, hf, array_length(hf));
  proto_register_subtree_array(ett, array_length(ett));
  expert_charging_ase = expert_register_protocol(proto_charging_ase);
  expert_register_field_array(expert_charging_ase, ei, array_length(ei));
  charging_ase_handle = register_dissector("charging_ase", dissect_charging_ase, proto_charging_ase);
}

/* The registration hand-off routine */
void
proto_reg_handoff_charging_ase(void)
{
}

