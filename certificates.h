#ifndef _CERTIFICATES_H_
#define _CERTIFICATES_H_

#ifdef __cplusplus
extern "C"
{
#endif

/* This file is auto-generated by the pycert_bearssl tool.  Do not change it manually.
 * Certificates are BearSSL br_x509_trust_anchor format.  Included certs:
 *
 * Index:    0
 * Label:    GlobalSign Root CA
 * Subject:  CN=GlobalSign Root CA,OU=Root CA,O=GlobalSign nv-sa,C=BE
 * Domain(s): chatgpt.com, inference.memgpt.ai
 */

#define TAs_NUM 1

static const unsigned char TA_DN0[] = {
    0x30, 0x57, 0x31, 0x0b, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x06, 0x13,
    0x02, 0x42, 0x45, 0x31, 0x19, 0x30, 0x17, 0x06, 0x03, 0x55, 0x04, 0x0a,
    0x13, 0x10, 0x47, 0x6c, 0x6f, 0x62, 0x61, 0x6c, 0x53, 0x69, 0x67, 0x6e,
    0x20, 0x6e, 0x76, 0x2d, 0x73, 0x61, 0x31, 0x10, 0x30, 0x0e, 0x06, 0x03,
    0x55, 0x04, 0x0b, 0x13, 0x07, 0x52, 0x6f, 0x6f, 0x74, 0x20, 0x43, 0x41,
    0x31, 0x1b, 0x30, 0x19, 0x06, 0x03, 0x55, 0x04, 0x03, 0x13, 0x12, 0x47,
    0x6c, 0x6f, 0x62, 0x61, 0x6c, 0x53, 0x69, 0x67, 0x6e, 0x20, 0x52, 0x6f,
    0x6f, 0x74, 0x20, 0x43, 0x41,
};

static const unsigned char TA_RSA_N0[] = {
    0xda, 0x0e, 0xe6, 0x99, 0x8d, 0xce, 0xa3, 0xe3, 0x4f, 0x8a, 0x7e, 0xfb,
    0xf1, 0x8b, 0x83, 0x25, 0x6b, 0xea, 0x48, 0x1f, 0xf1, 0x2a, 0xb0, 0xb9,
    0x95, 0x11, 0x04, 0xbd, 0xf0, 0x63, 0xd1, 0xe2, 0x67, 0x66, 0xcf, 0x1c,
    0xdd, 0xcf, 0x1b, 0x48, 0x2b, 0xee, 0x8d, 0x89, 0x8e, 0x9a, 0xaf, 0x29,
    0x80, 0x65, 0xab, 0xe9, 0xc7, 0x2d, 0x12, 0xcb, 0xab, 0x1c, 0x4c, 0x70,
    0x07, 0xa1, 0x3d, 0x0a, 0x30, 0xcd, 0x15, 0x8d, 0x4f, 0xf8, 0xdd, 0xd4,
    0x8c, 0x50, 0x15, 0x1c, 0xef, 0x50, 0xee, 0xc4, 0x2e, 0xf7, 0xfc, 0xe9,
    0x52, 0xf2, 0x91, 0x7d, 0xe0, 0x6d, 0xd5, 0x35, 0x30, 0x8e, 0x5e, 0x43,
    0x73, 0xf2, 0x41, 0xe9, 0xd5, 0x6a, 0xe3, 0xb2, 0x89, 0x3a, 0x56, 0x39,
    0x38, 0x6f, 0x06, 0x3c, 0x88, 0x69, 0x5b, 0x2a, 0x4d, 0xc5, 0xa7, 0x54,
    0xb8, 0x6c, 0x89, 0xcc, 0x9b, 0xf9, 0x3c, 0xca, 0xe5, 0xfd, 0x89, 0xf5,
    0x12, 0x3c, 0x92, 0x78, 0x96, 0xd6, 0xdc, 0x74, 0x6e, 0x93, 0x44, 0x61,
    0xd1, 0x8d, 0xc7, 0x46, 0xb2, 0x75, 0x0e, 0x86, 0xe8, 0x19, 0x8a, 0xd5,
    0x6d, 0x6c, 0xd5, 0x78, 0x16, 0x95, 0xa2, 0xe9, 0xc8, 0x0a, 0x38, 0xeb,
    0xf2, 0x24, 0x13, 0x4f, 0x73, 0x54, 0x93, 0x13, 0x85, 0x3a, 0x1b, 0xbc,
    0x1e, 0x34, 0xb5, 0x8b, 0x05, 0x8c, 0xb9, 0x77, 0x8b, 0xb1, 0xdb, 0x1f,
    0x20, 0x91, 0xab, 0x09, 0x53, 0x6e, 0x90, 0xce, 0x7b, 0x37, 0x74, 0xb9,
    0x70, 0x47, 0x91, 0x22, 0x51, 0x63, 0x16, 0x79, 0xae, 0xb1, 0xae, 0x41,
    0x26, 0x08, 0xc8, 0x19, 0x2b, 0xd1, 0x46, 0xaa, 0x48, 0xd6, 0x64, 0x2a,
    0xd7, 0x83, 0x34, 0xff, 0x2c, 0x2a, 0xc1, 0x6c, 0x19, 0x43, 0x4a, 0x07,
    0x85, 0xe7, 0xd3, 0x7c, 0xf6, 0x21, 0x68, 0xef, 0xea, 0xf2, 0x52, 0x9f,
    0x7f, 0x93, 0x90, 0xcf,
};

static const unsigned char TA_RSA_E0[] = {
    0x01, 0x00, 0x01,
};

static const br_x509_trust_anchor TAs[] = {
    {
        { (unsigned char *)TA_DN0, sizeof TA_DN0 },
        BR_X509_TA_CA,
        {
            BR_KEYTYPE_RSA,
            { {
                (unsigned char *)TA_RSA_N0, sizeof TA_RSA_N0,
                (unsigned char *)TA_RSA_E0, sizeof TA_RSA_E0,
            } }
        }
    },
};

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* ifndef _CERTIFICATES_H_ */