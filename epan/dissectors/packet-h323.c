/* Do not modify this file. Changes will be overwritten.                      */
/* Generated automatically by the ASN.1 to Wireshark dissector compiler       */
/* packet-h323.c                                                              */
/* asn2wrs.py -q -L -p h323 -c ./h323.cnf -s ./packet-h323-template -D . -O ../.. RAS-PROTOCOL-TUNNEL.asn ROBUSTNESS-DATA.asn */

/* packet-h323.c
 * Routines for H.323 packet dissection
 * 2007  Tomas Kukosa
 *
 * Wireshark - Network traffic analyzer
 * By Gerald Combs <gerald@wireshark.org>
 * Copyright 1998 Gerald Combs
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include "config.h"

#include <epan/packet.h>
#include <epan/oids.h>
#include <epan/asn1.h>

#include "packet-per.h"
#include "packet-h225.h"
#include "packet-h323.h"

#define PNAME  "H.323"
#define PSNAME "H.323"
#define PFNAME "h323"

void proto_register_h323(void);
void proto_reg_handoff_h323(void);

/* Generic Extensible Framework */
gef_ctx_t* gef_ctx_alloc(wmem_allocator_t *pool, gef_ctx_t *parent, const gchar *type) {
  gef_ctx_t *gefx;

  gefx = wmem_new0(pool, gef_ctx_t);
  gefx->signature = GEF_CTX_SIGNATURE;
  gefx->parent = parent;
  gefx->type = type;
  return gefx;
}

gboolean gef_ctx_check_signature(gef_ctx_t *gefx) {
  return gefx && (gefx->signature == GEF_CTX_SIGNATURE);
}

gef_ctx_t* gef_ctx_get(void *ptr) {
  gef_ctx_t *gefx = (gef_ctx_t*)ptr;
  asn1_ctx_t *actx = (asn1_ctx_t*)ptr;

  if (!asn1_ctx_check_signature(actx))
    actx = NULL;

  if (actx)
    gefx = (gef_ctx_t *)actx->private_data;

  if (!gef_ctx_check_signature(gefx))
    gefx = NULL;

  return gefx;
}

void gef_ctx_update_key(wmem_allocator_t *pool, gef_ctx_t *gefx) {
  const gchar *parent_key;

  if (!gefx) return;
  parent_key = (gefx->parent) ? gefx->parent->key : NULL;
  gefx->key = wmem_strdup_printf(pool,
    "%s%s"    /* parent prefix */
    "%s%s%s"  /* type, id */
    "%s%s"    /* subid */,
    (parent_key) ? parent_key : "", (parent_key) ? "/" : "",
    (gefx->type) ? gefx->type : "", (gefx->type && (gefx->id || gefx->subid)) ? "/" : "", (gefx->id) ? gefx->id : "",
    (gefx->subid) ? "-" : "", (gefx->subid) ? gefx->subid : ""
  );
}

/* Initialize the protocol and registered fields */
static int proto_h323;
static int hf_h323_RasTunnelledSignallingMessage_PDU;  /* RasTunnelledSignallingMessage */
static int hf_h323_RobustnessData_PDU;            /* RobustnessData */
static int hf_h323_tunnelledProtocolID;           /* TunnelledProtocol */
static int hf_h323_messageContent;                /* T_messageContent */
static int hf_h323_messageContent_item;           /* OCTET_STRING */
static int hf_h323_tunnellingRequired;            /* NULL */
static int hf_h323_nonStandardData;               /* NonStandardParameter */
static int hf_h323_versionID;                     /* INTEGER_1_256 */
static int hf_h323_robustnessData;                /* T_robustnessData */
static int hf_h323_rrqData;                       /* Rrq_RD */
static int hf_h323_rcfData;                       /* Rcf_RD */
static int hf_h323_setupData;                     /* Setup_RD */
static int hf_h323_connectData;                   /* Connect_RD */
static int hf_h323_statusData;                    /* Status_RD */
static int hf_h323_statusInquiryData;             /* StatusInquiry_RD */
static int hf_h323_BackupCallSignalAddresses_item;  /* BackupCallSignalAddresses_item */
static int hf_h323_tcp;                           /* TransportAddress */
static int hf_h323_alternateTransport;            /* AlternateTransportAddresses */
static int hf_h323_backupCallSignalAddresses;     /* BackupCallSignalAddresses */
static int hf_h323_hasSharedRepository;           /* NULL */
static int hf_h323_irrFrequency;                  /* INTEGER_1_65535 */
static int hf_h323_endpointGuid;                  /* GloballyUniqueIdentifier */
static int hf_h323_h245Address;                   /* TransportAddress */
static int hf_h323_fastStart;                     /* T_fastStart */
static int hf_h323_fastStart_item;                /* OCTET_STRING */
static int hf_h323_resetH245;                     /* NULL */
static int hf_h323_timeToLive;                    /* TimeToLive */
static int hf_h323_includeFastStart;              /* NULL */

/* Initialize the subtree pointers */
static int ett_h323_RasTunnelledSignallingMessage;
static int ett_h323_T_messageContent;
static int ett_h323_RobustnessData;
static int ett_h323_T_robustnessData;
static int ett_h323_BackupCallSignalAddresses;
static int ett_h323_BackupCallSignalAddresses_item;
static int ett_h323_Rrq_RD;
static int ett_h323_Rcf_RD;
static int ett_h323_Setup_RD;
static int ett_h323_Connect_RD;
static int ett_h323_Status_RD;
static int ett_h323_T_fastStart;
static int ett_h323_StatusInquiry_RD;



static int
dissect_h323_OCTET_STRING(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
                                       NO_BOUND, NO_BOUND, false, NULL);

  return offset;
}


static const per_sequence_t T_messageContent_sequence_of[1] = {
  { &hf_h323_messageContent_item, ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_h323_OCTET_STRING },
};

static int
dissect_h323_T_messageContent(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_per_sequence_of(tvb, offset, actx, tree, hf_index,
                                      ett_h323_T_messageContent, T_messageContent_sequence_of);

  return offset;
}



static int
dissect_h323_NULL(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_per_null(tvb, offset, actx, tree, hf_index);

  return offset;
}


static const per_sequence_t RasTunnelledSignallingMessage_sequence[] = {
  { &hf_h323_tunnelledProtocolID, ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_h225_TunnelledProtocol },
  { &hf_h323_messageContent , ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_h323_T_messageContent },
  { &hf_h323_tunnellingRequired, ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_h323_NULL },
  { &hf_h323_nonStandardData, ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_h225_NonStandardParameter },
  { NULL, 0, 0, NULL }
};

static int
dissect_h323_RasTunnelledSignallingMessage(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
                                   ett_h323_RasTunnelledSignallingMessage, RasTunnelledSignallingMessage_sequence);

  return offset;
}



static int
dissect_h323_INTEGER_1_256(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
                                                            1U, 256U, NULL, false);

  return offset;
}


static const value_string h323_BackupCallSignalAddresses_item_vals[] = {
  {   0, "tcp" },
  {   1, "alternateTransport" },
  { 0, NULL }
};

static const per_choice_t BackupCallSignalAddresses_item_choice[] = {
  {   0, &hf_h323_tcp            , ASN1_EXTENSION_ROOT    , dissect_h225_TransportAddress },
  {   1, &hf_h323_alternateTransport, ASN1_EXTENSION_ROOT    , dissect_h225_AlternateTransportAddresses },
  { 0, NULL, 0, NULL }
};

static int
dissect_h323_BackupCallSignalAddresses_item(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
                                 ett_h323_BackupCallSignalAddresses_item, BackupCallSignalAddresses_item_choice,
                                 NULL);

  return offset;
}


static const per_sequence_t BackupCallSignalAddresses_sequence_of[1] = {
  { &hf_h323_BackupCallSignalAddresses_item, ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_h323_BackupCallSignalAddresses_item },
};

static int
dissect_h323_BackupCallSignalAddresses(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_per_sequence_of(tvb, offset, actx, tree, hf_index,
                                      ett_h323_BackupCallSignalAddresses, BackupCallSignalAddresses_sequence_of);

  return offset;
}


static const per_sequence_t Rrq_RD_sequence[] = {
  { &hf_h323_backupCallSignalAddresses, ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_h323_BackupCallSignalAddresses },
  { &hf_h323_hasSharedRepository, ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_h323_NULL },
  { NULL, 0, 0, NULL }
};

static int
dissect_h323_Rrq_RD(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
                                   ett_h323_Rrq_RD, Rrq_RD_sequence);

  return offset;
}



static int
dissect_h323_INTEGER_1_65535(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
                                                            1U, 65535U, NULL, false);

  return offset;
}


static const per_sequence_t Rcf_RD_sequence[] = {
  { &hf_h323_hasSharedRepository, ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_h323_NULL },
  { &hf_h323_irrFrequency   , ASN1_NOT_EXTENSION_ROOT, ASN1_OPTIONAL    , dissect_h323_INTEGER_1_65535 },
  { NULL, 0, 0, NULL }
};

static int
dissect_h323_Rcf_RD(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
                                   ett_h323_Rcf_RD, Rcf_RD_sequence);

  return offset;
}



static int
dissect_h323_GloballyUniqueIdentifier(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_h225_GloballyUniqueID(tvb, offset, actx, tree, hf_index);

  return offset;
}


static const per_sequence_t Setup_RD_sequence[] = {
  { &hf_h323_backupCallSignalAddresses, ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_h323_BackupCallSignalAddresses },
  { &hf_h323_hasSharedRepository, ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_h323_NULL },
  { &hf_h323_endpointGuid   , ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_h323_GloballyUniqueIdentifier },
  { NULL, 0, 0, NULL }
};

static int
dissect_h323_Setup_RD(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
                                   ett_h323_Setup_RD, Setup_RD_sequence);

  return offset;
}


static const per_sequence_t Connect_RD_sequence[] = {
  { &hf_h323_backupCallSignalAddresses, ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_h323_BackupCallSignalAddresses },
  { &hf_h323_hasSharedRepository, ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_h323_NULL },
  { &hf_h323_endpointGuid   , ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_h323_GloballyUniqueIdentifier },
  { NULL, 0, 0, NULL }
};

static int
dissect_h323_Connect_RD(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
                                   ett_h323_Connect_RD, Connect_RD_sequence);

  return offset;
}


static const per_sequence_t T_fastStart_sequence_of[1] = {
  { &hf_h323_fastStart_item , ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_h323_OCTET_STRING },
};

static int
dissect_h323_T_fastStart(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_per_sequence_of(tvb, offset, actx, tree, hf_index,
                                      ett_h323_T_fastStart, T_fastStart_sequence_of);

  return offset;
}


static const per_sequence_t Status_RD_sequence[] = {
  { &hf_h323_h245Address    , ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_h225_TransportAddress },
  { &hf_h323_fastStart      , ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_h323_T_fastStart },
  { &hf_h323_resetH245      , ASN1_NOT_EXTENSION_ROOT, ASN1_OPTIONAL    , dissect_h323_NULL },
  { NULL, 0, 0, NULL }
};

static int
dissect_h323_Status_RD(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
                                   ett_h323_Status_RD, Status_RD_sequence);

  return offset;
}


static const per_sequence_t StatusInquiry_RD_sequence[] = {
  { &hf_h323_h245Address    , ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_h225_TransportAddress },
  { &hf_h323_timeToLive     , ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_h225_TimeToLive },
  { &hf_h323_includeFastStart, ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_h323_NULL },
  { NULL, 0, 0, NULL }
};

static int
dissect_h323_StatusInquiry_RD(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
                                   ett_h323_StatusInquiry_RD, StatusInquiry_RD_sequence);

  return offset;
}


static const value_string h323_T_robustnessData_vals[] = {
  {   0, "rrqData" },
  {   1, "rcfData" },
  {   2, "setupData" },
  {   3, "connectData" },
  {   4, "statusData" },
  {   5, "statusInquiryData" },
  { 0, NULL }
};

static const per_choice_t T_robustnessData_choice[] = {
  {   0, &hf_h323_rrqData        , ASN1_EXTENSION_ROOT    , dissect_h323_Rrq_RD },
  {   1, &hf_h323_rcfData        , ASN1_EXTENSION_ROOT    , dissect_h323_Rcf_RD },
  {   2, &hf_h323_setupData      , ASN1_EXTENSION_ROOT    , dissect_h323_Setup_RD },
  {   3, &hf_h323_connectData    , ASN1_EXTENSION_ROOT    , dissect_h323_Connect_RD },
  {   4, &hf_h323_statusData     , ASN1_EXTENSION_ROOT    , dissect_h323_Status_RD },
  {   5, &hf_h323_statusInquiryData, ASN1_EXTENSION_ROOT    , dissect_h323_StatusInquiry_RD },
  { 0, NULL, 0, NULL }
};

static int
dissect_h323_T_robustnessData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
                                 ett_h323_T_robustnessData, T_robustnessData_choice,
                                 NULL);

  return offset;
}


static const per_sequence_t RobustnessData_sequence[] = {
  { &hf_h323_versionID      , ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_h323_INTEGER_1_256 },
  { &hf_h323_robustnessData , ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_h323_T_robustnessData },
  { NULL, 0, 0, NULL }
};

static int
dissect_h323_RobustnessData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
  offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
                                   ett_h323_RobustnessData, RobustnessData_sequence);

  return offset;
}

/*--- PDUs ---*/

static int dissect_RasTunnelledSignallingMessage_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
  int offset = 0;
  asn1_ctx_t asn1_ctx;
  asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, true, pinfo);
  offset = dissect_h323_RasTunnelledSignallingMessage(tvb, offset, &asn1_ctx, tree, hf_h323_RasTunnelledSignallingMessage_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_RobustnessData_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
  int offset = 0;
  asn1_ctx_t asn1_ctx;
  asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, true, pinfo);
  offset = dissect_h323_RobustnessData(tvb, offset, &asn1_ctx, tree, hf_h323_RobustnessData_PDU);
  offset += 7; offset >>= 3;
  return offset;
}


/*--- proto_register_h323 ----------------------------------------------*/
void proto_register_h323(void) {

  /* List of fields */
  static hf_register_info hf[] = {
    { &hf_h323_RasTunnelledSignallingMessage_PDU,
      { "RasTunnelledSignallingMessage", "h323.RasTunnelledSignallingMessage_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_h323_RobustnessData_PDU,
      { "RobustnessData", "h323.RobustnessData_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_h323_tunnelledProtocolID,
      { "tunnelledProtocolID", "h323.tunnelledProtocolID_element",
        FT_NONE, BASE_NONE, NULL, 0,
        "TunnelledProtocol", HFILL }},
    { &hf_h323_messageContent,
      { "messageContent", "h323.messageContent",
        FT_UINT32, BASE_DEC, NULL, 0,
        NULL, HFILL }},
    { &hf_h323_messageContent_item,
      { "messageContent item", "h323.messageContent_item",
        FT_BYTES, BASE_NONE, NULL, 0,
        "OCTET_STRING", HFILL }},
    { &hf_h323_tunnellingRequired,
      { "tunnellingRequired", "h323.tunnellingRequired_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_h323_nonStandardData,
      { "nonStandardData", "h323.nonStandardData_element",
        FT_NONE, BASE_NONE, NULL, 0,
        "NonStandardParameter", HFILL }},
    { &hf_h323_versionID,
      { "versionID", "h323.versionID",
        FT_UINT32, BASE_DEC, NULL, 0,
        "INTEGER_1_256", HFILL }},
    { &hf_h323_robustnessData,
      { "robustnessData", "h323.robustnessData",
        FT_UINT32, BASE_DEC, VALS(h323_T_robustnessData_vals), 0,
        NULL, HFILL }},
    { &hf_h323_rrqData,
      { "rrqData", "h323.rrqData_element",
        FT_NONE, BASE_NONE, NULL, 0,
        "Rrq_RD", HFILL }},
    { &hf_h323_rcfData,
      { "rcfData", "h323.rcfData_element",
        FT_NONE, BASE_NONE, NULL, 0,
        "Rcf_RD", HFILL }},
    { &hf_h323_setupData,
      { "setupData", "h323.setupData_element",
        FT_NONE, BASE_NONE, NULL, 0,
        "Setup_RD", HFILL }},
    { &hf_h323_connectData,
      { "connectData", "h323.connectData_element",
        FT_NONE, BASE_NONE, NULL, 0,
        "Connect_RD", HFILL }},
    { &hf_h323_statusData,
      { "statusData", "h323.statusData_element",
        FT_NONE, BASE_NONE, NULL, 0,
        "Status_RD", HFILL }},
    { &hf_h323_statusInquiryData,
      { "statusInquiryData", "h323.statusInquiryData_element",
        FT_NONE, BASE_NONE, NULL, 0,
        "StatusInquiry_RD", HFILL }},
    { &hf_h323_BackupCallSignalAddresses_item,
      { "BackupCallSignalAddresses item", "h323.BackupCallSignalAddresses_item",
        FT_UINT32, BASE_DEC, VALS(h323_BackupCallSignalAddresses_item_vals), 0,
        NULL, HFILL }},
    { &hf_h323_tcp,
      { "tcp", "h323.tcp",
        FT_UINT32, BASE_DEC, VALS(h225_TransportAddress_vals), 0,
        "TransportAddress", HFILL }},
    { &hf_h323_alternateTransport,
      { "alternateTransport", "h323.alternateTransport_element",
        FT_NONE, BASE_NONE, NULL, 0,
        "AlternateTransportAddresses", HFILL }},
    { &hf_h323_backupCallSignalAddresses,
      { "backupCallSignalAddresses", "h323.backupCallSignalAddresses",
        FT_UINT32, BASE_DEC, NULL, 0,
        NULL, HFILL }},
    { &hf_h323_hasSharedRepository,
      { "hasSharedRepository", "h323.hasSharedRepository_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_h323_irrFrequency,
      { "irrFrequency", "h323.irrFrequency",
        FT_UINT32, BASE_DEC, NULL, 0,
        "INTEGER_1_65535", HFILL }},
    { &hf_h323_endpointGuid,
      { "endpointGuid", "h323.endpointGuid",
        FT_GUID, BASE_NONE, NULL, 0,
        "GloballyUniqueIdentifier", HFILL }},
    { &hf_h323_h245Address,
      { "h245Address", "h323.h245Address",
        FT_UINT32, BASE_DEC, VALS(h225_TransportAddress_vals), 0,
        "TransportAddress", HFILL }},
    { &hf_h323_fastStart,
      { "fastStart", "h323.fastStart",
        FT_UINT32, BASE_DEC, NULL, 0,
        NULL, HFILL }},
    { &hf_h323_fastStart_item,
      { "fastStart item", "h323.fastStart_item",
        FT_BYTES, BASE_NONE, NULL, 0,
        "OCTET_STRING", HFILL }},
    { &hf_h323_resetH245,
      { "resetH245", "h323.resetH245_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
    { &hf_h323_timeToLive,
      { "timeToLive", "h323.timeToLive",
        FT_UINT32, BASE_DEC, NULL, 0,
        NULL, HFILL }},
    { &hf_h323_includeFastStart,
      { "includeFastStart", "h323.includeFastStart_element",
        FT_NONE, BASE_NONE, NULL, 0,
        NULL, HFILL }},
  };

  /* List of subtrees */
  static gint *ett[] = {
    &ett_h323_RasTunnelledSignallingMessage,
    &ett_h323_T_messageContent,
    &ett_h323_RobustnessData,
    &ett_h323_T_robustnessData,
    &ett_h323_BackupCallSignalAddresses,
    &ett_h323_BackupCallSignalAddresses_item,
    &ett_h323_Rrq_RD,
    &ett_h323_Rcf_RD,
    &ett_h323_Setup_RD,
    &ett_h323_Connect_RD,
    &ett_h323_Status_RD,
    &ett_h323_T_fastStart,
    &ett_h323_StatusInquiry_RD,
  };

  /* Register protocol */
  proto_h323 = proto_register_protocol(PNAME, PSNAME, PFNAME);

  /* Register fields and subtrees */
  proto_register_field_array(proto_h323, hf, array_length(hf));
  proto_register_subtree_array(ett, array_length(ett));

}


/*--- proto_reg_handoff_h323 -------------------------------------------*/
void proto_reg_handoff_h323(void)
{
  dissector_handle_t q931_handle;

  q931_handle = find_dissector("q931");

  /* H.323, Annex M1, Tunnelling of signalling protocols (QSIG) in H.323 */
  dissector_add_string("h225.tp", "1.3.12.9", q931_handle);

  /* H.323, Annex M4, Tunnelling of narrow-band signalling syntax (NSS) for H.323 */
  dissector_add_string("h225.gef.content", "GenericData/1000/1",
                       create_dissector_handle(dissect_RasTunnelledSignallingMessage_PDU, proto_h323));

  /* H.323, Annex R, Robustness methods for H.323 entities */
  dissector_add_string("h225.gef.content", "GenericData/1/1",
                       create_dissector_handle(dissect_RobustnessData_PDU, proto_h323));
}

