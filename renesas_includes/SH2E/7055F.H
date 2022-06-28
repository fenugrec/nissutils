/************************************************************************/
/*      SH7055F Include File                                 Ver 2.2    */
/************************************************************************/
struct st_hcan {                                        /* struct HCAN  */
               union {                                  /* MCR          */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char SLPMR:1;      /*    SLPMR     */
                            unsigned char      :1;      /*              */
                            unsigned char SLPM :1;      /*    SLPM      */
                            unsigned char      :2;      /*              */
                            unsigned char MTM  :1;      /*    MTM       */
                            unsigned char HLTRQ:1;      /*    HLTRQ     */
                            unsigned char RSTRQ:1;      /*    RSTRQ     */
                            }      BIT;                 /*              */
                     }          MCR;                    /*              */
               union {                                  /* GSR          */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char     :4;       /*              */
                            unsigned char RSB :1;       /*    RSB       */
                            unsigned char MTSF:1;       /*    MTSF      */
                            unsigned char TRWF:1;       /*    TRWF      */
                            unsigned char BOF :1;       /*    BOF       */
                            }      BIT;                 /*              */
                     }          GSR;                    /*              */
               union {                                  /* BCR          */
                     unsigned short WORD;               /*  Word Access */
                     struct {                           /*  Bit  Access */
                            unsigned char SJW  :2;      /*    SJW       */
                            unsigned char BRP  :6;      /*    BRP       */
                            unsigned char BSP  :1;      /*    BSP       */
                            unsigned char TSEG2:3;      /*    TSEG2     */
                            unsigned char TSEG1:4;      /*    TSEG1     */
                            }       BIT;                /*              */
                     }          BCR;                    /*              */
               union {                                  /* MBCR         */
                     unsigned short WORD;               /*  Word Access */
                     struct {                           /*  Bit  Access */
                            unsigned char MB7 :1;       /*    MB7       */
                            unsigned char MB6 :1;       /*    MB6       */
                            unsigned char MB5 :1;       /*    MB5       */
                            unsigned char MB4 :1;       /*    MB4       */
                            unsigned char MB3 :1;       /*    MB3       */
                            unsigned char MB2 :1;       /*    MB2       */
                            unsigned char MB1 :1;       /*    MB1       */
                            unsigned char     :1;       /*              */
                            unsigned char MB15:1;       /*    MB15      */
                            unsigned char MB14:1;       /*    MB14      */
                            unsigned char MB13:1;       /*    MB13      */
                            unsigned char MB12:1;       /*    MB12      */
                            unsigned char MB11:1;       /*    MB11      */
                            unsigned char MB10:1;       /*    MB10      */
                            unsigned char MB9 :1;       /*    MB9       */
                            unsigned char MB8 :1;       /*    MB8       */
                            }       BIT;                /*              */
                     }          MBCR;                   /*              */
               union {                                  /* TXPR         */
                     unsigned short WORD;               /*  Word Access */
                     struct {                           /*  Bit  Access */
                            unsigned char MB7 :1;       /*    MB7       */
                            unsigned char MB6 :1;       /*    MB6       */
                            unsigned char MB5 :1;       /*    MB5       */
                            unsigned char MB4 :1;       /*    MB4       */
                            unsigned char MB3 :1;       /*    MB3       */
                            unsigned char MB2 :1;       /*    MB2       */
                            unsigned char MB1 :1;       /*    MB1       */
                            unsigned char     :1;       /*              */
                            unsigned char MB15:1;       /*    MB15      */
                            unsigned char MB14:1;       /*    MB14      */
                            unsigned char MB13:1;       /*    MB13      */
                            unsigned char MB12:1;       /*    MB12      */
                            unsigned char MB11:1;       /*    MB11      */
                            unsigned char MB10:1;       /*    MB10      */
                            unsigned char MB9 :1;       /*    MB9       */
                            unsigned char MB8 :1;       /*    MB8       */
                            }       BIT;                /*              */
                     }          TXPR;                   /*              */
               union {                                  /* TXCR         */
                     unsigned short WORD;               /*  Word Access */
                     struct {                           /*  Bit  Access */
                            unsigned char MB7 :1;       /*    MB7       */
                            unsigned char MB6 :1;       /*    MB6       */
                            unsigned char MB5 :1;       /*    MB5       */
                            unsigned char MB4 :1;       /*    MB4       */
                            unsigned char MB3 :1;       /*    MB3       */
                            unsigned char MB2 :1;       /*    MB2       */
                            unsigned char MB1 :1;       /*    MB1       */
                            unsigned char     :1;       /*              */
                            unsigned char MB15:1;       /*    MB15      */
                            unsigned char MB14:1;       /*    MB14      */
                            unsigned char MB13:1;       /*    MB13      */
                            unsigned char MB12:1;       /*    MB12      */
                            unsigned char MB11:1;       /*    MB11      */
                            unsigned char MB10:1;       /*    MB10      */
                            unsigned char MB9 :1;       /*    MB9       */
                            unsigned char MB8 :1;       /*    MB8       */
                            }       BIT;                /*              */
                     }          TXCR;                   /*              */
               union {                                  /* TXACK        */
                     unsigned short WORD;               /*  Word Access */
                     struct {                           /*  Bit  Access */
                            unsigned char MB7 :1;       /*    MB7       */
                            unsigned char MB6 :1;       /*    MB6       */
                            unsigned char MB5 :1;       /*    MB5       */
                            unsigned char MB4 :1;       /*    MB4       */
                            unsigned char MB3 :1;       /*    MB3       */
                            unsigned char MB2 :1;       /*    MB2       */
                            unsigned char MB1 :1;       /*    MB1       */
                            unsigned char     :1;       /*              */
                            unsigned char MB15:1;       /*    MB15      */
                            unsigned char MB14:1;       /*    MB14      */
                            unsigned char MB13:1;       /*    MB13      */
                            unsigned char MB12:1;       /*    MB12      */
                            unsigned char MB11:1;       /*    MB11      */
                            unsigned char MB10:1;       /*    MB10      */
                            unsigned char MB9 :1;       /*    MB9       */
                            unsigned char MB8 :1;       /*    MB8       */
                            }       BIT;                /*              */
                     }          TXACK;                  /*              */
               union {                                  /* ABACK        */
                     unsigned short WORD;               /*  Word Access */
                     struct {                           /*  Bit  Access */
                            unsigned char MB7 :1;       /*    MB7       */
                            unsigned char MB6 :1;       /*    MB6       */
                            unsigned char MB5 :1;       /*    MB5       */
                            unsigned char MB4 :1;       /*    MB4       */
                            unsigned char MB3 :1;       /*    MB3       */
                            unsigned char MB2 :1;       /*    MB2       */
                            unsigned char MB1 :1;       /*    MB1       */
                            unsigned char     :1;       /*              */
                            unsigned char MB15:1;       /*    MB15      */
                            unsigned char MB14:1;       /*    MB14      */
                            unsigned char MB13:1;       /*    MB13      */
                            unsigned char MB12:1;       /*    MB12      */
                            unsigned char MB11:1;       /*    MB11      */
                            unsigned char MB10:1;       /*    MB10      */
                            unsigned char MB9 :1;       /*    MB9       */
                            unsigned char MB8 :1;       /*    MB8       */
                            }       BIT;                /*              */
                     }          ABACK;                  /*              */
               union {                                  /* RXPR         */
                     unsigned short WORD;               /*  Word Access */
                     struct {                           /*  Bit  Access */
                            unsigned char MB7 :1;       /*    MB7       */
                            unsigned char MB6 :1;       /*    MB6       */
                            unsigned char MB5 :1;       /*    MB5       */
                            unsigned char MB4 :1;       /*    MB4       */
                            unsigned char MB3 :1;       /*    MB3       */
                            unsigned char MB2 :1;       /*    MB2       */
                            unsigned char MB1 :1;       /*    MB1       */
                            unsigned char MB0 :1;       /*    MB0       */
                            unsigned char MB15:1;       /*    MB15      */
                            unsigned char MB14:1;       /*    MB14      */
                            unsigned char MB13:1;       /*    MB13      */
                            unsigned char MB12:1;       /*    MB12      */
                            unsigned char MB11:1;       /*    MB11      */
                            unsigned char MB10:1;       /*    MB10      */
                            unsigned char MB9 :1;       /*    MB9       */
                            unsigned char MB8 :1;       /*    MB8       */
                            }       BIT;                /*              */
                     }          RXPR;                   /*              */
               union {                                  /* RFPR         */
                     unsigned short WORD;               /*  Word Access */
                     struct {                           /*  Bit  Access */
                            unsigned char MB7 :1;       /*    MB7       */
                            unsigned char MB6 :1;       /*    MB6       */
                            unsigned char MB5 :1;       /*    MB5       */
                            unsigned char MB4 :1;       /*    MB4       */
                            unsigned char MB3 :1;       /*    MB3       */
                            unsigned char MB2 :1;       /*    MB2       */
                            unsigned char MB1 :1;       /*    MB1       */
                            unsigned char MB0 :1;       /*    MB0       */
                            unsigned char MB15:1;       /*    MB15      */
                            unsigned char MB14:1;       /*    MB14      */
                            unsigned char MB13:1;       /*    MB13      */
                            unsigned char MB12:1;       /*    MB12      */
                            unsigned char MB11:1;       /*    MB11      */
                            unsigned char MB10:1;       /*    MB10      */
                            unsigned char MB9 :1;       /*    MB9       */
                            unsigned char MB8 :1;       /*    MB8       */
                            }       BIT;                /*              */
                     }          RFPR;                   /*              */
               union {                                  /* IRR          */
                     unsigned short WORD;               /*  Word Access */
                     struct {                           /*  Bit  Access */
                            unsigned char OLFIF:1;      /*    OLFIF     */
                            unsigned char BOFIF:1;      /*    BOFIF     */
                            unsigned char EPIF :1;      /*    EPIF      */
                            unsigned char ROWIF:1;      /*    ROWIF     */
                            unsigned char TOWIF:1;      /*    TOWIF     */
                            unsigned char RFRIF:1;      /*    RFRIF     */
                            unsigned char RMIF :1;      /*    RMIF      */
                            unsigned char RSTIF:1;      /*    RSTIF     */
                            unsigned char      :3;      /*              */
                            unsigned char BOIF :1;      /*    BOIF      */
                            unsigned char      :2;      /*              */
                            unsigned char URIF :1;      /*    URIF      */
                            unsigned char MBEIF:1;      /*    MBEIF     */
                            }       BIT;                /*              */
                     }          IRR;                    /*              */
               union {                                  /* MBIMR        */
                     unsigned short WORD;               /*  Word Access */
                     struct {                           /*  Bit  Access */
                            unsigned char MB7 :1;       /*    MB7       */
                            unsigned char MB6 :1;       /*    MB6       */
                            unsigned char MB5 :1;       /*    MB5       */
                            unsigned char MB4 :1;       /*    MB4       */
                            unsigned char MB3 :1;       /*    MB3       */
                            unsigned char MB2 :1;       /*    MB2       */
                            unsigned char MB1 :1;       /*    MB1       */
                            unsigned char MB0 :1;       /*    MB0       */
                            unsigned char MB15:1;       /*    MB15      */
                            unsigned char MB14:1;       /*    MB14      */
                            unsigned char MB13:1;       /*    MB13      */
                            unsigned char MB12:1;       /*    MB12      */
                            unsigned char MB11:1;       /*    MB11      */
                            unsigned char MB10:1;       /*    MB10      */
                            unsigned char MB9 :1;       /*    MB9       */
                            unsigned char MB8 :1;       /*    MB8       */
                            }       BIT;                /*              */
                     }          MBIMR;                  /*              */
               union {                                  /* IMR          */
                     unsigned short WORD;               /*  Word Access */
                     struct {                           /*  Bit  Access */
                            unsigned char OLFIM:1;      /*    OLFIM     */
                            unsigned char BOFIM:1;      /*    BOFIM     */
                            unsigned char EPIM :1;      /*    EPIM      */
                            unsigned char ROWIM:1;      /*    ROWIM     */
                            unsigned char TOWIM:1;      /*    TOWIM     */
                            unsigned char RFRIM:1;      /*    RFRIM     */
                            unsigned char RMIM :1;      /*    RMIM      */
                            unsigned char      :1;      /*              */
                            unsigned char      :3;      /*              */
                            unsigned char BOIM :1;      /*    BOIM      */
                            unsigned char      :2;      /*              */
                            unsigned char URIM :1;      /*    URIM      */
                            unsigned char MBEIM:1;      /*    MBEIM     */
                            }       BIT;                /*              */
                     }          IMR;                    /*              */
               unsigned char    REC;                    /* REC          */
               unsigned char    TEC;                    /* TEC          */
               union {                                  /* UMSR         */
                     unsigned short WORD;               /*  Word Access */
                     struct {                           /*  Bit  Access */
                            unsigned char MB7 :1;       /*    MB7       */
                            unsigned char MB6 :1;       /*    MB6       */
                            unsigned char MB5 :1;       /*    MB5       */
                            unsigned char MB4 :1;       /*    MB4       */
                            unsigned char MB3 :1;       /*    MB3       */
                            unsigned char MB2 :1;       /*    MB2       */
                            unsigned char MB1 :1;       /*    MB1       */
                            unsigned char MB0 :1;       /*    MB0       */
                            unsigned char MB15:1;       /*    MB15      */
                            unsigned char MB14:1;       /*    MB14      */
                            unsigned char MB13:1;       /*    MB13      */
                            unsigned char MB12:1;       /*    MB12      */
                            unsigned char MB11:1;       /*    MB11      */
                            unsigned char MB10:1;       /*    MB10      */
                            unsigned char MB9 :1;       /*    MB9       */
                            unsigned char MB8 :1;       /*    MB8       */
                            }       BIT;                /*              */
                     }          UMSR;                   /*              */
               union {                                  /* LAFML        */
                     unsigned short WORD;               /*  Word Access */
                     struct {                           /*  Byte Access */
                            unsigned char L;            /*    Low       */
                            unsigned char H;            /*    High      */
                            }       BYTE;               /*              */
                     }          LAFML;                  /*              */
               union {                                  /* LAFMH        */
                     unsigned short WORD;               /*  Word Access */
                     struct {                           /*  Byte Access */
                            unsigned char L;            /*    Low       */
                            unsigned char H;            /*    High      */
                            }       BYTE;               /*              */
                     }          LAFMH;                  /*              */
               unsigned char    MC[16][8];              /* MC[x][y]     */
               char             wk[16];                 /*              */
               unsigned char    MD[16][8];              /* MD[x][y]     */
};                                                      /*              */
struct st_flash {                                       /* struct FLASH */
                union {                                 /* FLMCR1       */
                      unsigned char BYTE;               /*  Byte Access */
                      struct {                          /*  Bit  Access */
                             unsigned char FWE :1;      /*    FWE       */
                             unsigned char SWE1:1;      /*    SWE1      */
                             unsigned char ESU1:1;      /*    ESU1      */
                             unsigned char PSU1:1;      /*    PSU1      */
                             unsigned char EV1 :1;      /*    EV1       */
                             unsigned char PV1 :1;      /*    PV1       */
                             unsigned char E1  :1;      /*    E1        */
                             unsigned char P1  :1;      /*    P1        */
                             }      BIT;                /*              */
                      }         FLMCR1;                 /*              */
                union {                                 /* FLMCR2       */
                      unsigned char BYTE;               /*  Byte Access */
                      struct {                          /*  Bit  Access */
                             unsigned char FLER:1;      /*    FLER      */
                             unsigned char SWE2:1;      /*    SWE2      */
                             unsigned char ESU2:1;      /*    ESU2      */
                             unsigned char PSU2:1;      /*    PSU2      */
                             unsigned char EV2 :1;      /*    EV2       */
                             unsigned char PV2 :1;      /*    PV2       */
                             unsigned char E2  :1;      /*    E2        */
                             unsigned char P2  :1;      /*    P2        */
                             }      BIT;                /*              */
                      }         FLMCR2;                 /*              */
                union {                                 /* EBR1         */
                      unsigned char BYTE;               /*  Byte Access */
                      struct {                          /*  Bit  Access */
                             unsigned char EB7:1;       /*    EB7       */
                             unsigned char EB6:1;       /*    EB6       */
                             unsigned char EB5:1;       /*    EB5       */
                             unsigned char EB4:1;       /*    EB4       */
                             unsigned char EB3:1;       /*    EB3       */
                             unsigned char EB2:1;       /*    EB2       */
                             unsigned char EB1:1;       /*    EB1       */
                             unsigned char EB0:1;       /*    EB0       */
                             }      BIT;                /*              */
                      }         EBR1;                   /*              */
                union {                                 /* EBR2         */
                      unsigned char BYTE;               /*  Byte Access */
                      struct {                          /*  Bit  Access */
                             unsigned char EB15:1;      /*    EB15      */
                             unsigned char EB14:1;      /*    EB14      */
                             unsigned char EB13:1;      /*    EB13      */
                             unsigned char EB12:1;      /*    EB12      */
                             unsigned char EB11:1;      /*    EB11      */
                             unsigned char EB10:1;      /*    EB10      */
                             unsigned char EB9 :1;      /*    EB9       */
                             unsigned char EB8 :1;      /*    EB8       */
                             }      BIT;                /*              */
                      }         EBR2;                   /*              */
                char            wk[1059];               /*              */
                union {                                 /* RAMER        */
                      unsigned char BYTE;               /*  Byte Access */
                      struct {                          /*  Bit  Access */
                             unsigned char     :4;      /*              */
                             unsigned char RAMS:1;      /*    RAMS      */
                             unsigned char RAM :3;      /*    RAM       */
                             }      BIT;                /*              */
                      }         RAMER;                  /*              */
};                                                      /*              */
struct st_ubc {                                         /* struct UBC   */
              void             *UBAR;                   /* UBAR         */
              unsigned int      UBAMR;                  /* UBAMR        */
              union {                                   /* UBBR         */
                    unsigned short WORD;                /*  Word Access */
                    struct {                            /*  Bit  Access */
                           unsigned char   :8;          /*              */
                           unsigned char CP:2;          /*    CP        */
                           unsigned char ID:2;          /*    ID        */
                           unsigned char RW:2;          /*    RW        */
                           unsigned char SZ:2;          /*    SZ        */
                           }       BIT;                 /*              */
                    }           UBBR;                   /*              */
              union {                                   /* UBCR         */
                    unsigned short WORD;                /*  Word Access */
                    struct {                            /*  Bit  Access */
                           unsigned char     :8;        /*              */
                           unsigned char     :5;        /*              */
                           unsigned char CKS :2;        /*    CKS       */
                           unsigned char UBID:1;        /*    UBID      */
                           }       BIT;                 /*              */
                    }           UBCR;                   /*              */
};                                                      /*              */
union un_wdt {                                          /* union WDT    */
             struct {                                   /* Read  Access */
                    union {                             /* TCSR         */
                          unsigned char BYTE;           /*  Byte Access */
                          struct {                      /*  Bit  Access */
                                 unsigned char OVF :1;  /*    OVF       */
                                 unsigned char WTIT:1;  /*    WT/IT     */
                                 unsigned char TME :1;  /*    TME       */
                                 unsigned char     :2;  /*              */
                                 unsigned char CKS :3;  /*    CKS       */
                                 }      BIT;            /*              */
                          }       TCSR;                 /*              */
                    unsigned char TCNT;                 /* TCNT         */
                    char          wk;                   /*              */
                    union {                             /* RSTCSR       */
                          unsigned char BYTE;           /*  Byte Access */
                          struct {                      /*              */
                                 unsigned char WRST:1;  /*    WSRT      */
                                 unsigned char RSTE:1;  /*    RSTE      */
                                 unsigned char RSTS:1;  /*    RSTS      */
                                 }      BIT;            /*              */
                          }       RSTCSR;               /*              */
                    } READ;                             /*              */
             struct {                                   /* Write Access */
                    unsigned short TCSR;                /* TCSR/TCNT    */
                    unsigned short RSTCSR;              /* RSTCSR       */
                    } WRITE;                            /*              */
};                                                      /*              */
union un_sbycr {                                        /* SBYCR        */
               unsigned char BYTE ;                     /*  Byte Access */
               struct {                                 /*  Bit  Access */
                      unsigned char SSBY:1;             /*    SSBY      */
                      unsigned char HIZ :1;             /*    HIZ       */
                      }      BIT;                       /*              */
};                                                      /*              */
struct st_bsc {                                         /* struct BSC   */
              union {                                   /* BCR1         */
                    unsigned short WORD;                /*  Word Access */
                    struct {                            /*  Bit  Access */
                           unsigned char     :8;        /*              */
                           unsigned char     :4;        /*              */
                           unsigned char A3SZ:1;        /*    A3SZ      */
                           unsigned char A2SZ:1;        /*    A2SZ      */
                           unsigned char A1SZ:1;        /*    A1SZ      */
                           unsigned char A0SZ:1;        /*    A0SZ      */
                           }       BIT;                 /*              */
                    }           BCR1;                   /*              */
              union {                                   /* BCR2         */
                    unsigned short WORD;                /*  Word Access */
                    struct {                            /*  Bit  Access */
                           unsigned char IW3:2;         /*    IW3       */
                           unsigned char IW2:2;         /*    IW2       */
                           unsigned char IW1:2;         /*    IW1       */
                           unsigned char IW0:2;         /*    IW0       */
                           unsigned char CW3:1;         /*    CW3       */
                           unsigned char CW2:1;         /*    CW2       */
                           unsigned char CW1:1;         /*    CW1       */
                           unsigned char CW0:1;         /*    CW0       */
                           unsigned char SW3:1;         /*    SW3       */
                           unsigned char SW2:1;         /*    SW2       */
                           unsigned char SW1:1;         /*    SW1       */
                           unsigned char SW0:1;         /*    SW0       */
                           }       BIT;                 /*              */
                    }           BCR2;                   /*              */
              union {                                   /* WCR          */
                    unsigned short WORD;                /*  Word Access */
                    struct {                            /*  Bit  Access */
                           unsigned char W3:4;          /*    W3        */
                           unsigned char W2:4;          /*    W2        */
                           unsigned char W1:4;          /*    W1        */
                           unsigned char W0:4;          /*    W0        */
                           }       BIT;                 /*              */
                    }           WCR;                    /*              */
};                                                      /*              */
struct st_dmac {                                        /* struct DMAC  */
               union {                                  /* DMAOR        */
                     unsigned short WORD;               /*  Word Access */
                     struct {                           /*  Bit  Access */
                            unsigned short     :13;     /*              */
                            unsigned short AE  : 1;     /*    AE        */
                            unsigned short NMIF: 1;     /*    NMIF      */
                            unsigned short DME : 1;     /*    DME       */
                            }       BIT;                /*              */
                     }          DMAOR;                  /*              */
};                                                      /*              */
struct st_dmac0 {                                       /* struct DMAC0 */
                void           *SAR;                    /* SAR          */
                void           *DAR;                    /* DAR          */
                unsigned int    DMATCR;                 /* DMATCR       */
                union {                                 /* CHCR         */
                      unsigned int LONG;                /*  Long Access */
                      struct {                          /*  Word Access */
                             unsigned short H;          /*    High Word */
                             unsigned short L;          /*    Low  Word */
                             }     WORD;                /*              */
                      struct {                          /*  Bit  Access */
                             unsigned short   :11;      /*              */
                             unsigned short RS: 5;      /*    RS        */
                             unsigned short   : 2;      /*              */
                             unsigned short SM: 2;      /*    SM        */
                             unsigned short   : 2;      /*              */
                             unsigned short DM: 2;      /*    DM        */
                             unsigned short   : 2;      /*              */
                             unsigned short TS: 2;      /*    TS        */
                             unsigned short TM: 1;      /*    TM        */
                             unsigned short IE: 1;      /*    IE        */
                             unsigned short TE: 1;      /*    TE        */
                             unsigned short DE: 1;      /*    DE        */
                             }     BIT;                 /*              */
                      }         CHCR;                   /*              */
};                                                      /*              */
struct st_dmac2 {                                       /* struct DMAC2 */
                void           *SAR;                    /* SAR          */
                void           *DAR;                    /* DAR          */
                unsigned int    DMATCR;                 /* DMATCR       */
                union {                                 /* CHCR         */
                      unsigned int LONG;                /*  Long Access */
                      struct {                          /*  Word Access */
                             unsigned short H;          /*    High Word */
                             unsigned short L;          /*    Low  Word */
                             }     WORD;                /*              */
                      struct {                          /*  Bit  Access */
                             unsigned short   :7;       /*              */
                             unsigned short RO:1;       /*    RO        */
                             unsigned short   :3;       /*              */
                             unsigned short RS:5;       /*    RS        */
                             unsigned short   :2;       /*              */
                             unsigned short SM:2;       /*    SM        */
                             unsigned short   :2;       /*              */
                             unsigned short DM:2;       /*    DM        */
                             unsigned short   :2;       /*              */
                             unsigned short TS:2;       /*    TS        */
                             unsigned short TM:1;       /*    TM        */
                             unsigned short IE:1;       /*    IE        */
                             unsigned short TE:1;       /*    TE        */
                             unsigned short DE:1;       /*    DE        */
                             }     BIT;                 /*              */
                      }         CHCR;                   /*              */
};                                                      /*              */
struct st_dmac3 {                                       /* struct DMAC3 */
                void           *SAR;                    /* SAR          */
                void           *DAR;                    /* DAR          */
                unsigned int    DMATCR;                 /* DMATCR       */
                union {                                 /* CHCR         */
                      unsigned int LONG;                /*  Long Access */
                      struct {                          /*  Word Access */
                             unsigned short H;          /*    High Word */
                             unsigned short L;          /*    Low  Word */
                             }     WORD;                /*              */
                      struct {                          /*  Bit  Access */
                             unsigned short   :3;       /*              */
                             unsigned short DI:1;       /*    DI        */
                             unsigned short   :7;       /*              */
                             unsigned short RS:5;       /*    RS        */
                             unsigned short   :2;       /*              */
                             unsigned short SM:2;       /*    SM        */
                             unsigned short   :2;       /*              */
                             unsigned short DM:2;       /*    DM        */
                             unsigned short   :2;       /*              */
                             unsigned short TS:2;       /*    TS        */
                             unsigned short TM:1;       /*    TM        */
                             unsigned short IE:1;       /*    IE        */
                             unsigned short TE:1;       /*    TE        */
                             unsigned short DE:1;       /*    DE        */
                             }     BIT;                 /*              */
                      }         CHCR;                   /*              */
};                                                      /*              */
struct st_intc {                                        /* struct INTC  */
               union {                                  /* IPRA         */
                     unsigned short WORD;               /*  Word Access */
                     struct {                           /*  Bit  Access */
                            unsigned char _IRQ0:4;      /*    IRQ0      */
                            unsigned char _IRQ1:4;      /*    IRQ1      */
                            unsigned char _IRQ2:4;      /*    IRQ2      */
                            unsigned char _IRQ3:4;      /*    IRQ3      */
                            }       BIT;                /*              */
                     }          IPRA;                   /*              */
               union {                                  /* IPRB         */
                     unsigned short WORD;               /*  Word Access */
                     struct {                           /*  Bit  Access */
                            unsigned char _IRQ4:4;      /*    IRQ4      */
                            unsigned char _IRQ5:4;      /*    IRQ5      */
                            unsigned char _IRQ6:4;      /*    IRQ6      */
                            unsigned char _IRQ7:4;      /*    IRQ7      */
                            }       BIT;                /*              */
                     }          IPRB;                   /*              */
               union {                                  /* IPRC         */
                     unsigned short WORD;               /*  Word Access */
                     struct {                           /*  Bit  Access */
                            unsigned char _DMAC01:4;    /*    DMAC0,1   */
                            unsigned char _DMAC23:4;    /*    DMAC2,3   */
                            unsigned char _ATU01 :4;    /*    ATU01     */
                            unsigned char _ATU02 :4;    /*    ATU02     */
                            }       BIT;                /*              */
                     }          IPRC;                   /*              */
               union {                                  /* IPRD         */
                     unsigned short WORD;               /*  Word Access */
                     struct {                           /*  Bit  Access */
                            unsigned char _ATU03:4;     /*    ATU03     */
                            unsigned char _ATU04:4;     /*    ATU04     */
                            unsigned char _ATU11:4;     /*    ATU11     */
                            unsigned char _ATU12:4;     /*    ATU12     */
                            }       BIT;                /*              */
                     }          IPRD;                   /*              */
               union {                                  /* IPRE         */
                     unsigned short WORD;               /*  Word Access */
                     struct {                           /*  Bit  Access */
                            unsigned char _ATU13:4;     /*    ATU13     */
                            unsigned char _ATU21:4;     /*    ATU21     */
                            unsigned char _ATU22:4;     /*    ATU22     */
                            unsigned char _ATU23:4;     /*    ATU23     */
                            }       BIT;                /*              */
                     }          IPRE;                   /*              */
               union {                                  /* IPRF         */
                     unsigned short WORD;               /*  Word Access */
                     struct {                           /*  Bit  Access */
                            unsigned char _ATU31:4;     /*    ATU31     */
                            unsigned char _ATU32:4;     /*    ATU32     */
                            unsigned char _ATU41:4;     /*    ATU41     */
                            unsigned char _ATU42:4;     /*    ATU42     */
                            }       BIT;                /*              */
                     }          IPRF;                   /*              */
               union {                                  /* IPRG         */
                     unsigned short WORD;               /*  Word Access */
                     struct {                           /*  Bit  Access */
                            unsigned char _ATU51:4;     /*    ATU51     */
                            unsigned char _ATU52:4;     /*    ATU52     */
                            unsigned char _ATU6 :4;     /*    ATU6      */
                            unsigned char _ATU7 :4;     /*    ATU7      */
                            }       BIT;                /*              */
                     }          IPRG;                   /*              */
               union {                                  /* IPRH         */
                     unsigned short WORD;               /*  Word Access */
                     struct {                           /*  Bit  Access */
                            unsigned char _ATU81:4;     /*    ATU81     */
                            unsigned char _ATU82:4;     /*    ATU82     */
                            unsigned char _ATU83:4;     /*    ATU83     */
                            unsigned char _ATU84:4;     /*    ATU84     */
                            }       BIT;                /*              */
                     }          IPRH;                   /*              */
               union {                                  /* IPRI         */
                     unsigned short WORD;               /*  Word Access */
                     struct {                           /*  Bit  Access */
                            unsigned char _ATU91 :4;    /*    ATU91     */
                            unsigned char _ATU92 :4;    /*    ATU92     */
                            unsigned char _ATU101:4;    /*    ATU101    */
                            unsigned char _ATU102:4;    /*    ATU102    */
                            }       BIT;                /*              */
                     }          IPRI;                   /*              */
               union {                                  /* IPRJ         */
                     unsigned short WORD;               /*  Word Access */
                     struct {                           /*  Bit  Access */
                            unsigned char _ATU11:4;     /*    ATU11     */
                            unsigned char _CMT0 :4;     /*    CMT0,AD0  */
                            unsigned char _CMT1 :4;     /*    CMT1,AD1  */
                            unsigned char _AD2  :4;     /*    AD2       */
                            }       BIT;                /*              */
                     }          IPRJ;                   /*              */
               union {                                  /* IPRK         */
                     unsigned short WORD;               /*  Word Access */
                     struct {                           /*  Bit  Access */
                            unsigned char _SCI0:4;      /*    SCI0      */
                            unsigned char _SCI1:4;      /*    SCI1      */
                            unsigned char _SCI2:4;      /*    SCI2      */
                            unsigned char _SCI3:4;      /*    SCI3      */
                            }       BIT;                /*              */
                     }          IPRK;                   /*              */
               union {                                  /* IPRL         */
                     unsigned short WORD;               /*  Word Access */
                     struct {                           /*  Bit  Access */
                            unsigned char _SCI4 :4;     /*    SCI4      */
                            unsigned char _HCAN0:4;     /*    HCAN0     */
                            unsigned char _WDT  :4;     /*    WDT       */
                            unsigned char _HCAN1:4;     /*    HCAN1     */
                            }       BIT;                /*              */
                     }          IPRL;                   /*              */
               union {                                  /* ICR          */
                     unsigned short WORD;               /*  Word Access */
                     struct {                           /*  Bit  Access */
                            unsigned char NMIL :1;      /*    NMIL      */
                            unsigned char      :6;      /*              */
                            unsigned char NMIE :1;      /*    NMIE      */
                            unsigned char IRQ0S:1;      /*    IRQ0S     */
                            unsigned char IRQ1S:1;      /*    IRQ1S     */
                            unsigned char IRQ2S:1;      /*    IRQ2S     */
                            unsigned char IRQ3S:1;      /*    IRQ3S     */
                            unsigned char IRQ4S:1;      /*    IRQ4S     */
                            unsigned char IRQ5S:1;      /*    IRQ5S     */
                            unsigned char IRQ6S:1;      /*    IRQ6S     */
                            unsigned char IRQ7S:1;      /*    IRQ7S     */
                            }       BIT;                /*              */
                     }          ICR;                    /*              */
               union {                                  /* ISR          */
                     unsigned short WORD;               /*  Word Access */
                     struct {                           /*  Bit  Access */
                            unsigned char      :8;      /*              */
                            unsigned char IRQ0F:1;      /*    IRQ0F     */
                            unsigned char IRQ1F:1;      /*    IRQ1F     */
                            unsigned char IRQ2F:1;      /*    IRQ2F     */
                            unsigned char IRQ3F:1;      /*    IRQ3F     */
                            unsigned char IRQ4F:1;      /*    IRQ4F     */
                            unsigned char IRQ5F:1;      /*    IRQ5F     */
                            unsigned char IRQ6F:1;      /*    IRQ6F     */
                            unsigned char IRQ7F:1;      /*    IRQ7F     */
                            }       BIT;                /*              */
                     }          ISR;                    /*              */
};                                                      /*              */
struct st_sci {                                         /* struct SCI   */
              union {                                   /* SMR          */
                    unsigned char BYTE;                 /*  Byte Access */
                    struct {                            /*  Bit  Access */
                           unsigned char CA  :1;        /*    C/A       */
                           unsigned char CHR :1;        /*    CHR       */
                           unsigned char _PE :1;        /*    PE        */
                           unsigned char OE  :1;        /*    O/E       */
                           unsigned char STOP:1;        /*    STOP      */
                           unsigned char MP  :1;        /*    MP        */
                           unsigned char CKS :2;        /*    CKS       */
                           }      BIT;                  /*              */
                    }           SMR;                    /*              */
              unsigned char     BRR;                    /* BRR          */
              union {                                   /* SCR          */
                    unsigned char BYTE;                 /*  Byte Access */
                    struct {                            /*  Bit  Access */
                           unsigned char TIE :1;        /*    TIE       */
                           unsigned char RIE :1;        /*    RIE       */
                           unsigned char TE  :1;        /*    TE        */
                           unsigned char RE  :1;        /*    RE        */
                           unsigned char MPIE:1;        /*    MPIE      */
                           unsigned char TEIE:1;        /*    TEIE      */
                           unsigned char CKE :2;        /*    CKE       */
                           }      BIT;                  /*              */
                    }           SCR;                    /*              */
              unsigned char     TDR;                    /* TDR          */
              union {                                   /* SSR          */
                    unsigned char BYTE;                 /*  Byte Access */
                    struct {                            /*  Bit  Access */
                           unsigned char TDRE:1;        /*    TDRE      */
                           unsigned char RDRF:1;        /*    RDRF      */
                           unsigned char ORER:1;        /*    ORER      */
                           unsigned char FER :1;        /*    FER       */
                           unsigned char PER :1;        /*    PER       */
                           unsigned char TEND:1;        /*    TEND      */
                           unsigned char MPB :1;        /*    MPB       */
                           unsigned char MPBT:1;        /*    MPBT      */
                           }      BIT;                  /*              */
                    }           SSR;                    /*              */
              unsigned char     RDR;                    /* RDR          */
              union {                                   /* SDCR         */
                    unsigned char BYTE;                 /*  Byte Access */
                    struct {                            /*  Bit  Access */
                           unsigned char    :4;         /*              */
                           unsigned char DIR:1;         /*    DIR       */
                           }      BIT;                  /*              */
                    }           SDCR;                   /*              */
};                                                      /*              */
struct st_atu {                                         /* struct ATU-II*/
              union {                                   /* TSTR2        */
                    unsigned char BYTE;                 /*  Byte Access */
                    struct {                            /*  Bit  Access */
                           unsigned char STR7D:1;       /*    STR7D     */
                           unsigned char STR7C:1;       /*    STR7C     */
                           unsigned char STR7B:1;       /*    STR7B     */
                           unsigned char STR7A:1;       /*    STR7A     */
                           unsigned char STR6D:1;       /*    STR6D     */
                           unsigned char STR6C:1;       /*    STR6C     */
                           unsigned char STR6B:1;       /*    STR6B     */
                           unsigned char STR6A:1;       /*    STR6A     */
                           }      BIT;                  /*              */
                    }           TSTR2;                  /*              */
              union {                                   /* TSTR1        */
                    unsigned char BYTE;                 /*  Byte Access */
                    struct {                            /*  Bit  Access */
                           unsigned char STR10 :1;      /*    STR10     */
                           unsigned char STR5  :1;      /*    STR5      */
                           unsigned char STR4  :1;      /*    STR4      */
                           unsigned char STR3  :1;      /*    STR3      */
                           unsigned char STR12B:1;      /*    STR1B,2B  */
                           unsigned char STR2A :1;      /*    STR2A     */
                           unsigned char STR1A :1;      /*    STR1A     */
                           unsigned char STR0  :1;      /*    STR0      */
                           }      BIT;                  /*              */
                    }           TSTR1;                  /*              */
              union {                                   /* TSTR3        */
                    unsigned char BYTE;                 /*  Byte Access */
                    struct {                            /*  Bit  Access */
                           unsigned char      :7;       /*              */
                           unsigned char STR11:1;       /*    STR11     */
                           }      BIT;                  /*              */
                    }           TSTR3;                  /*              */
              char              wk1;                    /*              */
              union {                                   /* PSCR1        */
                    unsigned char BYTE;                 /*  Byte Access */
                    struct {                            /*  Bit  Access */
                           unsigned char      :3;       /*              */
                           unsigned char PSC1E:1;       /*    PSC1E     */
                           unsigned char PSC1D:1;       /*    PSC1D     */
                           unsigned char PSC1C:1;       /*    PSC1C     */
                           unsigned char PSC1B:1;       /*    PSC1B     */
                           unsigned char PSC1A:1;       /*    PSC1A     */
                           }      BIT;                  /*              */
                    }           PSCR1;                  /*              */
              char              wk2;                    /*              */
              union {                                   /* PSCR2        */
                    unsigned char BYTE;                 /*  Byte Access */
                    struct {                            /*  Bit  Access */
                           unsigned char      :3;       /*              */
                           unsigned char PSC2E:1;       /*    PSC2E     */
                           unsigned char PSC2D:1;       /*    PSC2D     */
                           unsigned char PSC2C:1;       /*    PSC2C     */
                           unsigned char PSC2B:1;       /*    PSC2B     */
                           unsigned char PSC2A:1;       /*    PSC2A     */
                           }      BIT;                  /*              */
                    }           PSCR2;                  /*              */
              char              wk3;                    /*              */
              union {                                   /* PSCR3        */
                    unsigned char BYTE;                 /*  Byte Access */
                    struct {                            /*  Bit  Access */
                           unsigned char      :3;       /*              */
                           unsigned char PSC3E:1;       /*    PSC3E     */
                           unsigned char PSC3D:1;       /*    PSC3D     */
                           unsigned char PSC3C:1;       /*    PSC3C     */
                           unsigned char PSC3B:1;       /*    PSC3B     */
                           unsigned char PSC3A:1;       /*    PSC3A     */
                           }      BIT;                  /*              */
                    }           PSCR3;                  /*              */
              char              wk4;                    /*              */
              union {                                   /* PSCR4        */
                    unsigned char BYTE;                 /*  Byte Access */
                    struct {                            /*  Bit  Access */
                           unsigned char      :3;       /*              */
                           unsigned char PSC4E:1;       /*    PSC4E     */
                           unsigned char PSC4D:1;       /*    PSC4D     */
                           unsigned char PSC4C:1;       /*    PSC4C     */
                           unsigned char PSC4B:1;       /*    PSC4B     */
                           unsigned char PSC4A:1;       /*    PSC4A     */
                           }      BIT;                  /*              */
                    }           PSCR4;                  /*              */
};                                                      /*              */
struct st_atu0 {                                        /* struct ATU0  */
               unsigned int     ICRD;                   /* ICRD         */
               union {                                  /* ITVRR1       */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char ITVA9:1;      /*    ITVA9     */
                            unsigned char ITVA8:1;      /*    ITVA8     */
                            unsigned char ITVA7:1;      /*    ITVA7     */
                            unsigned char ITVA6:1;      /*    ITVA6     */
                            unsigned char ITVE9:1;      /*    ITVE9     */
                            unsigned char ITVE8:1;      /*    ITVE8     */
                            unsigned char ITVE7:1;      /*    ITVE7     */
                            unsigned char ITVE6:1;      /*    ITVE6     */
                            }      BIT;                 /*              */
                     }          ITVRR1;                 /*              */
               char             wk1;                    /*              */
               union {                                  /* ITVRR2A      */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char ITVA13A:1;    /*    ITVA13A   */
                            unsigned char ITVA12A:1;    /*    ITVA12A   */
                            unsigned char ITVA11A:1;    /*    ITVA11A   */
                            unsigned char ITVA10A:1;    /*    ITVA10A   */
                            unsigned char ITVE13A:1;    /*    ITVE13A   */
                            unsigned char ITVE12A:1;    /*    ITVE12A   */
                            unsigned char ITVE11A:1;    /*    ITVE11A   */
                            unsigned char ITVE10A:1;    /*    ITVE10A   */
                            }      BIT;                 /*              */
                     }          ITVRR2A;                /*              */
               char             wk2;                    /*              */
               union {                                  /* ITVRR2B      */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char ITVA13B:1;    /*    ITVA13B   */
                            unsigned char ITVA12B:1;    /*    ITVA12B   */
                            unsigned char ITVA11B:1;    /*    ITVA11B   */
                            unsigned char ITVA10B:1;    /*    ITVA10B   */
                            unsigned char ITVE13B:1;    /*    ITVE13B   */
                            unsigned char ITVE12B:1;    /*    ITVE12B   */
                            unsigned char ITVE11B:1;    /*    ITVE11B   */
                            unsigned char ITVE10B:1;    /*    ITVE10B   */
                            }      BIT;                 /*              */
                     }          ITVRR2B;                /*              */
               char             wk3;                    /*              */
               union {                                  /* TIOR         */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char IOD:2;        /*    IOD       */
                            unsigned char IOC:2;        /*    IOC       */
                            unsigned char IOB:2;        /*    IOB       */
                            unsigned char IOA:2;        /*    IOA       */
                            }      BIT;                 /*              */
                     }          TIOR;                   /*              */
               char             wk4;                    /*              */
               union {                                  /* TSR          */
                     unsigned short WORD;               /*  Word Access */
                     struct {                           /*  Bit  Access */
                            unsigned short      :8;     /*              */
                            unsigned short IIF2B:1;     /*    IIF2B     */
                            unsigned short IIF2A:1;     /*    IIF2A     */
                            unsigned short IIF1 :1;     /*    IIF1      */
                            unsigned short OVF  :1;     /*    OVF       */
                            unsigned short ICFD :1;     /*    ICFD      */
                            unsigned short ICFC :1;     /*    ICFC      */
                            unsigned short ICFB :1;     /*    ICFB      */
                            unsigned short ICFA :1;     /*    ICFA      */
                            }       BIT;                /*              */
                     }          TSR;                    /*              */
               union {                                  /* TIER         */
                     unsigned short WORD;               /*  Word Access */
                     struct {                           /*  Bit  Access */
                            unsigned short     :11;     /*              */
                            unsigned short OVE : 1;     /*    OVE       */
                            unsigned short ICED: 1;     /*    ICED      */
                            unsigned short ICEC: 1;     /*    ICEC      */
                            unsigned short ICEB: 1;     /*    ICEB      */
                            unsigned short ICEA: 1;     /*    ICEA      */
                            }       BIT;                /*              */
                     }          TIER;                   /*              */
               unsigned int     TCNT;                   /* TCNT         */
               unsigned int     ICRA;                   /* ICRA         */
               unsigned int     ICRB;                   /* ICRB         */
               unsigned int     ICRC;                   /* ICRC         */
};                                                      /*              */
struct st_atu1 {                                        /* struct ATU1  */
               unsigned short   TCNTA;                  /* TCNTA        */
               unsigned short   TCNTB;                  /* TCNTB        */
               unsigned short   GRA;                    /* GRA          */
               unsigned short   GRB;                    /* GRB          */
               unsigned short   GRC;                    /* GRC          */
               unsigned short   GRD;                    /* GRD          */
               unsigned short   GRE;                    /* GRE          */
               unsigned short   GRF;                    /* GRF          */
               unsigned short   GRG;                    /* GRG          */
               unsigned short   GRH;                    /* GRH          */
               unsigned short   OCR;                    /* OCR          */
               unsigned short   OSBR;                   /* OSBR         */
               union {                                  /* TIORB        */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char    :1;        /*              */
                            unsigned char IOD:3;        /*    IOD       */
                            unsigned char    :1;        /*              */
                            unsigned char IOC:3;        /*    IOC       */
                            }      BIT;                 /*              */
                     }          TIORB;                  /*              */
               union {                                  /* TIORA        */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char    :1;        /*              */
                            unsigned char IOB:3;        /*    IOB       */
                            unsigned char    :1;        /*              */
                            unsigned char IOA:3;        /*    IOA       */
                            }      BIT;                 /*              */
                     }          TIORA;                  /*              */
               union {                                  /* TIORD        */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char    :1;        /*              */
                            unsigned char IOH:3;        /*    IOH       */
                            unsigned char    :1;        /*              */
                            unsigned char IOG:3;        /*    IOG       */
                            }      BIT;                 /*              */
                     }          TIORD;                  /*              */
               union {                                  /* TIORC        */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char    :1;        /*              */
                            unsigned char IOF:3;        /*    IOF       */
                            unsigned char    :1;        /*              */
                            unsigned char IOE:3;        /*    IOE       */
                            }      BIT;                 /*              */
                     }          TIORC;                  /*              */
               union {                                  /* TCRB         */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char       :2;     /*              */
                            unsigned char CKEGB :2;     /*    CKEGB     */
                            unsigned char CKSELB:4;     /*    CKSELB    */
                            }      BIT;                 /*              */
                     }          TCRB;                   /*              */
               union {                                  /* TCRA         */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char       :2;     /*              */
                            unsigned char CKEGA :2;     /*    CKEGA     */
                            unsigned char CKSELA:4;     /*    CKSELA    */
                            }      BIT;                 /*              */
                     }          TCRA;                   /*              */
               union {                                  /* TSRA         */
                     unsigned short WORD;               /*  Word Access */
                     struct {                           /*  Bit  Access */
                            unsigned short     :7;      /*              */
                            unsigned short OVFA:1;      /*    OVFA      */
                            unsigned short IMFH:1;      /*    IMF1H     */
                            unsigned short IMFG:1;      /*    IMF1G     */
                            unsigned short IMFF:1;      /*    IMF1F     */
                            unsigned short IMFE:1;      /*    IMF1E     */
                            unsigned short IMFD:1;      /*    IMF1D     */
                            unsigned short IMFC:1;      /*    IMF1C     */
                            unsigned short IMFB:1;      /*    IMF1B     */
                            unsigned short IMFA:1;      /*    IMF1A     */
                            }       BIT;                /*              */
                     }          TSRA;                   /*              */
               union {                                  /* TSRB         */
                     unsigned short WORD;               /*  Word Access */
                     struct {                           /*  Bit  Access */
                            unsigned short     :7;      /*              */
                            unsigned short OVFB:1;      /*    OVFB      */
                            unsigned short     :7;      /*              */
                            unsigned short CMF :1;      /*    CMF       */
                            }       BIT;                /*              */
                     }          TSRB;                   /*              */
               union {                                  /* TIERA        */
                     unsigned short WORD;               /*  Word Access */
                     struct {                           /*  Bit  Access */
                            unsigned short     :7;      /*              */
                            unsigned short OVEA:1;      /*    OVEA      */
                            unsigned short IMEH:1;      /*    IME1H     */
                            unsigned short IMEG:1;      /*    IME1G     */
                            unsigned short IMEF:1;      /*    IME1F     */
                            unsigned short IMEE:1;      /*    IME1E     */
                            unsigned short IMED:1;      /*    IME1D     */
                            unsigned short IMEC:1;      /*    IME1C     */
                            unsigned short IMEB:1;      /*    IME1B     */
                            unsigned short IMEA:1;      /*    IME1A     */
                            }       BIT;                /*              */
                     }          TIERA;                  /*              */
               union {                                  /* TIERB        */
                     unsigned short WORD;               /*  Word Access */
                     struct {                           /*  Bit  Access */
                            unsigned short     :7;      /*              */
                            unsigned short OVEB:1;      /*    OVEB      */
                            unsigned short     :7;      /*              */
                            unsigned short CME :1;      /*    CME       */
                            }       BIT;                /*              */
                     }          TIERB;                  /*              */
               union {                                  /* TRGMDR       */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char TRGMD:1;      /*    TRGMD     */
                            }      BIT;                 /*              */
                     }          TRGMDR;                 /*              */
};                                                      /*              */
struct st_atu2 {                                        /* struct ATU2  */
               unsigned short   TCNTA;                  /* TCNTA        */
               unsigned short   TCNTB;                  /* TCNTB        */
               unsigned short   GRA;                    /* GRA          */
               unsigned short   GRB;                    /* GRB          */
               unsigned short   GRC;                    /* GRC          */
               unsigned short   GRD;                    /* GRD          */
               unsigned short   GRE;                    /* GRE          */
               unsigned short   GRF;                    /* GRF          */
               unsigned short   GRG;                    /* GRG          */
               unsigned short   GRH;                    /* GRH          */
               unsigned short   OCRA;                   /* OCRA         */
               unsigned short   OCRB;                   /* OCRB         */
               unsigned short   OCRC;                   /* OCRC         */
               unsigned short   OCRD;                   /* OCRD         */
               unsigned short   OCRE;                   /* OCRE         */
               unsigned short   OCRF;                   /* OCRF         */
               unsigned short   OCRG;                   /* OCRG         */
               unsigned short   OCRH;                   /* OCRH         */
               unsigned short   OSBR;                   /* OSBR         */
               union {                                  /* TIORB        */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char    :1;        /*              */
                            unsigned char IOD:3;        /*    IOD       */
                            unsigned char    :1;        /*              */
                            unsigned char IOC:3;        /*    IOC       */
                            }      BIT;                 /*              */
                     }          TIORB;                  /*              */
               union {                                  /* TIORA        */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char    :1;        /*              */
                            unsigned char IOB:3;        /*    IOB       */
                            unsigned char    :1;        /*              */
                            unsigned char IOA:3;        /*    IOA       */
                            }      BIT;                 /*              */
                     }          TIORA;                  /*              */
               union {                                  /* TIORD        */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char    :1;        /*              */
                            unsigned char IOH:3;        /*    IOH       */
                            unsigned char    :1;        /*              */
                            unsigned char IOG:3;        /*    IOG       */
                            }      BIT;                 /*              */
                     }          TIORD;                  /*              */
               union {                                  /* TIORC        */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char    :1;        /*              */
                            unsigned char IOF:3;        /*    IOF       */
                            unsigned char    :1;        /*              */
                            unsigned char IOE:3;        /*    IOE       */
                            }      BIT;                 /*              */
                     }          TIORC;                  /*              */
               union {                                  /* TCRB         */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char       :2;     /*              */
                            unsigned char CKEGB :2;     /*    CKEGB     */
                            unsigned char CKSELB:4;     /*    CKSELB    */
                            }      BIT;                 /*              */
                     }          TCRB;                   /*              */
               union {                                  /* TCRA         */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char       :2;     /*              */
                            unsigned char CKEGA :2;     /*    CKEGA     */
                            unsigned char CKSELA:4;     /*    CKSELA    */
                            }      BIT;                 /*              */
                     }          TCRA;                   /*              */
               union {                                  /* TSRA         */
                     unsigned short WORD;               /*  Word Access */
                     struct {                           /*  Bit  Access */
                            unsigned short     :7;      /*              */
                            unsigned short OVFA:1;      /*    OVFA      */
                            unsigned short IMFH:1;      /*    IMFH      */
                            unsigned short IMFG:1;      /*    IMFG      */
                            unsigned short IMFF:1;      /*    IMFF      */
                            unsigned short IMFE:1;      /*    IMFE      */
                            unsigned short IMFD:1;      /*    IMFD      */
                            unsigned short IMFC:1;      /*    IMFC      */
                            unsigned short IMFB:1;      /*    IMFB      */
                            unsigned short IMFA:1;      /*    IMFA      */
                            }       BIT;                /*              */
                     }          TSRA;                   /*              */
               union {                                  /* TSRB         */
                     unsigned short WORD;               /*  Word Access */
                     struct {                           /*  Bit  Access */
                            unsigned short     :7;      /*              */
                            unsigned short OVFB:1;      /*    OVFB      */
                            unsigned short CMFH:1;      /*    CMFH      */
                            unsigned short CMFG:1;      /*    CMFG      */
                            unsigned short CMFF:1;      /*    CMFF      */
                            unsigned short CMFE:1;      /*    CMFE      */
                            unsigned short CMFD:1;      /*    CMFD      */
                            unsigned short CMFC:1;      /*    CMFC      */
                            unsigned short CMFB:1;      /*    CMFB      */
                            unsigned short CMFA:1;      /*    CMFA      */
                            }       BIT;                /*              */
                     }          TSRB;                   /*              */
               union {                                  /* TIERA        */
                     unsigned short WORD;               /*  Word Access */
                     struct {                           /*  Bit  Access */
                            unsigned short     :7;      /*              */
                            unsigned short OVEA:1;      /*    OVEA      */
                            unsigned short IMEH:1;      /*    IMEH      */
                            unsigned short IMEG:1;      /*    IMEG      */
                            unsigned short IMEF:1;      /*    IMEF      */
                            unsigned short IMEE:1;      /*    IMEE      */
                            unsigned short IMED:1;      /*    IMED      */
                            unsigned short IMEC:1;      /*    IMEC      */
                            unsigned short IMEB:1;      /*    IMEB      */
                            unsigned short IMEA:1;      /*    IMEA      */
                            }       BIT;                /*              */
                     }          TIERA;                  /*              */
               union {                                  /* TIERB        */
                     unsigned short WORD;               /*  Word Access */
                     struct {                           /*  Bit  Access */
                            unsigned short     :7;      /*              */
                            unsigned short OVEB:1;      /*    OVEB      */
                            unsigned short CMEH:1;      /*    CMEH      */
                            unsigned short CMEG:1;      /*    CMEG      */
                            unsigned short CMEF:1;      /*    CMEF      */
                            unsigned short CMEE:1;      /*    CMEE      */
                            unsigned short CMED:1;      /*    CMED      */
                            unsigned short CMEC:1;      /*    CMEC      */
                            unsigned short CMEB:1;      /*    CMEB      */
                            unsigned short CMEA:1;      /*    CMEA      */
                            }       BIT;                /*              */
                     }          TIERB;                  /*              */
};                                                      /*              */
struct st_atu3 {                                        /* struct ATU3  */
               union {                                  /* TSR          */
                     unsigned short WORD;               /*  Word Access */
                     struct {                           /*  Bit  Access */
                            unsigned short     :11;     /*              */
                            unsigned short OVF : 1;     /*    OVF       */
                            unsigned short IMFD: 1;     /*    IMFD      */
                            unsigned short IMFC: 1;     /*    IMFC      */
                            unsigned short IMFB: 1;     /*    IMFB      */
                            unsigned short IMFA: 1;     /*    IMFA      */
                            }       BIT;                /*              */
                     }          TSR;                    /*              */
               union {                                  /* TIER         */
                     unsigned short WORD;               /*  Word Access */
                     struct {                           /*  Bit  Access */
                            unsigned short     :11;     /*              */
                            unsigned short OVE : 1;     /*    OVE       */
                            unsigned short IMED: 1;     /*    IMED      */
                            unsigned short IMEC: 1;     /*    IMEC      */
                            unsigned short IMEB: 1;     /*    IMEB      */
                            unsigned short IMEA: 1;     /*    IMEA      */
                            }       BIT;                /*              */
                     }          TIER;                   /*              */
               union {                                  /* TMDR         */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char    :7;        /*              */
                            unsigned char PWM:1;        /*    T3PWM     */
                            }      BIT;                 /*              */
                     }          TMDR;                   /*              */
               char             wk[27];                 /*              */
               unsigned short   TCNT;                   /* TCNT         */
               unsigned short   GRA;                    /* GRA          */
               unsigned short   GRB;                    /* GRB          */
               unsigned short   GRC;                    /* GRC          */
               unsigned short   GRD;                    /* GRD          */
               union {                                  /* TIORB        */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char CCID:1;       /*    CCID      */
                            unsigned char IOD :3;       /*    IOD       */
                            unsigned char CCIC:1;       /*    CCIC      */
                            unsigned char IOC :3;       /*    IOC       */
                            }      BIT;                 /*              */
                     }          TIORB;                  /*              */
               union {                                  /* TIORA        */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char CCIB:1;       /*    CCIB      */
                            unsigned char IOB :3;       /*    IOB       */
                            unsigned char CCIA:1;       /*    CCIA      */
                            unsigned char IOA :3;       /*    IOA       */
                            }      BIT;                 /*              */
                     }          TIORA;                  /*              */
               union {                                  /* TCR          */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char      :2;      /*              */
                            unsigned char CKEG :2;      /*    CKEG      */
                            unsigned char CKSEL:4;      /*    CKSEL     */
                            }      BIT;                 /*              */
                     }          TCR;                    /*              */
};                                                      /*              */
struct st_atu4 {                                        /* struct ATU4  */
               union {                                  /* TSR          */
                     unsigned short WORD;               /*  Word Access */
                     struct {                           /*  Bit  Access */
                            unsigned short     :6;      /*              */
                            unsigned short OVF :1;      /*    OVF       */
                            unsigned short IMFD:1;      /*    IMFD      */
                            unsigned short IMFC:1;      /*    IMFC      */
                            unsigned short IMFB:1;      /*    IMFB      */
                            unsigned short IMFA:1;      /*    IMFA      */
                            }       BIT;                /*              */
                     }          TSR;                    /*              */
               union {                                  /* TIER         */
                     unsigned short WORD;               /*  Word Access */
                     struct {                           /*  Bit  Access */
                            unsigned short     :6;      /*              */
                            unsigned short OVE :1;      /*    OVE       */
                            unsigned short IMED:1;      /*    IMED      */
                            unsigned short IMEC:1;      /*    IMEC      */
                            unsigned short IMEB:1;      /*    IMEB      */
                            unsigned short IMEA:1;      /*    IMEA      */
                            }       BIT;                /*              */
                     }          TIER;                   /*              */
               union {                                  /* TMDR         */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char    :6;        /*              */
                            unsigned char PWM:1;        /*    T4PWM     */
                            }      BIT;                 /*              */
                     }          TMDR;                   /*              */
               char             wk[59];                 /*              */
               unsigned short   TCNT;                   /* TCNT         */
               unsigned short   GRA;                    /* GRA          */
               unsigned short   GRB;                    /* GRB          */
               unsigned short   GRC;                    /* GRC          */
               unsigned short   GRD;                    /* GRD          */
               union {                                  /* TIORB        */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char CCID:1;       /*    CCID      */
                            unsigned char IOD :3;       /*    IOD       */
                            unsigned char CCIC:1;       /*    CCIC      */
                            unsigned char IOC :3;       /*    IOC       */
                            }      BIT;                 /*              */
                     }          TIORB;                  /*              */
               union {                                  /* TIORA        */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char CCIB:1;       /*    CCIB      */
                            unsigned char IOB :3;       /*    IOB       */
                            unsigned char CCIA:1;       /*    CCIA      */
                            unsigned char IOA :3;       /*    IOA       */
                            }      BIT;                 /*              */
                     }          TIORA;                  /*              */
               union {                                  /* TCR          */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char      :2;      /*              */
                            unsigned char CKEG :2;      /*    CKEG      */
                            unsigned char CKSEL:4;      /*    CKSEL     */
                            }      BIT;                 /*              */
                     }          TCR;                    /*              */
};                                                      /*              */
struct st_atu5 {                                        /* struct ATU5  */
               union {                                  /* TSR          */
                     unsigned short WORD;               /*  Word Access */
                     struct {                           /*  Bit  Access */
                            unsigned short     :1;      /*              */
                            unsigned short OVF :1;      /*    OVF       */
                            unsigned short IMFD:1;      /*    IMFD      */
                            unsigned short IMFC:1;      /*    IMFC      */
                            unsigned short IMFB:1;      /*    IMFB      */
                            unsigned short IMFA:1;      /*    IMFA      */
                            }       BIT;                /*              */
                     }          TSR;                    /*              */
               union {                                  /* TIER         */
                     unsigned short WORD;               /*  Word Access */
                     struct {                           /*  Bit  Access */
                            unsigned short     :1;      /*              */
                            unsigned short OVE :1;      /*    OVE       */
                            unsigned short IMED:1;      /*    IMED      */
                            unsigned short IMEC:1;      /*    IMEC      */
                            unsigned short IMEB:1;      /*    IMEB      */
                            unsigned short IMEA:1;      /*    IMEA      */
                            }       BIT;                /*              */
                     }          TIER;                   /*              */
               union {                                  /* TMDR         */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char    :5;        /*              */
                            unsigned char PWM:1;        /*    T5PWM     */
                            }      BIT;                 /*              */
                     }          TMDR;                   /*              */
               char             wk[91];                 /*              */
               unsigned short   TCNT;                   /* TCNT         */
               unsigned short   GRA;                    /* GRA          */
               unsigned short   GRB;                    /* GRB          */
               unsigned short   GRC;                    /* GRC          */
               unsigned short   GRD;                    /* GRD          */
               union {                                  /* TIORB        */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char CCID:1;       /*    CCID      */
                            unsigned char IOD :3;       /*    IOD       */
                            unsigned char CCIC:1;       /*    CCIC      */
                            unsigned char IOC :3;       /*    IOC       */
                            }      BIT;                 /*              */
                     }          TIORB;                  /*              */
               union {                                  /* TIOR5A       */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char CCIB:1;       /*    CCIB      */
                            unsigned char IOB :3;       /*    IOB       */
                            unsigned char CCIA:1;       /*    CCIA      */
                            unsigned char IOA :3;       /*    IOA       */
                            }      BIT;                 /*              */
                     }          TIORA;                  /*              */
               union {                                  /* TCR5         */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char      :2;      /*              */
                            unsigned char CKEG :2;      /*    CKEG      */
                            unsigned char CKSEL:4;      /*    CKSEL     */
                            }      BIT;                 /*              */
                     }          TCR;                    /*              */
};                                                      /*              */
struct st_atu6 {                                        /* struct ATU6  */
               unsigned short   TCNTA;                  /* TCNT6A       */
               unsigned short   TCNTB;                  /* TCNT6B       */
               unsigned short   TCNTC;                  /* TCNT6C       */
               unsigned short   TCNTD;                  /* TCNT6D       */
               unsigned short   CYLRA;                  /* CYLR6A       */
               unsigned short   CYLRB;                  /* CYLR6B       */
               unsigned short   CYLRC;                  /* CYLR6C       */
               unsigned short   CYLRD;                  /* CYLR6D       */
               unsigned short   BFRA;                   /* BFR6A        */
               unsigned short   BFRB;                   /* BFR6B        */
               unsigned short   BFRC;                   /* BFR6C        */
               unsigned short   BFRD;                   /* BFR6D        */
               unsigned short   DTRA;                   /* DTR6A        */
               unsigned short   DTRB;                   /* DTR6B        */
               unsigned short   DTRC;                   /* DTR6C        */
               unsigned short   DTRD;                   /* DTR6D        */
               union {                                  /* TCR6B        */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char       :1;     /*              */
                            unsigned char CKSELD:3;     /*    CKSELD    */
                            unsigned char       :1;     /*              */
                            unsigned char CKSELC:3;     /*    CKSELC    */
                            }      BIT;                 /*              */
                     }          TCRB;                   /*              */
               union {                                  /* TCR6A        */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char       :1;     /*              */
                            unsigned char CKSELB:3;     /*    CKSELB    */
                            unsigned char       :1;     /*              */
                            unsigned char CKSELA:3;     /*    CKSELA    */
                            }      BIT;                 /*              */
                     }          TCRA;                   /*              */
               union {                                  /* TSR6         */
                     unsigned short WORD;               /*  Word Access */
                     struct {                           /*  Bit  Access */
                            unsigned short     :8;      /*              */
                            unsigned short UDD :1;      /*    UD6D      */
                            unsigned short UDC :1;      /*    UD6C      */
                            unsigned short UDB :1;      /*    UD6B      */
                            unsigned short UDA :1;      /*    UD6A      */
                            unsigned short CMFD:1;      /*    CMF6D     */
                            unsigned short CMFC:1;      /*    CMF6C     */
                            unsigned short CMFB:1;      /*    CMF6B     */
                            unsigned short CMFA:1;      /*    CMF6A     */
                            }       BIT;                /*              */
                     }          TSR;                    /*              */
               union {                                  /* TIER6        */
                     unsigned short WORD;               /*  Word Access */
                     struct {                           /*  Bit  Access */
                            unsigned short     :12;     /*              */
                            unsigned short CMED: 1;     /*    CME6D     */
                            unsigned short CMEC: 1;     /*    CME6C     */
                            unsigned short CMEB: 1;     /*    CME6B     */
                            unsigned short CMEA: 1;     /*    CME6A     */
                            }       BIT;                /*              */
                     }          TIER;                   /*              */
               union {                                  /* PMDR6        */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char DTSELD :1;    /*    DTSELD    */
                            unsigned char DTSELC :1;    /*    DTSELC    */
                            unsigned char DTSELB :1;    /*    DTSELB    */
                            unsigned char DTSELA :1;    /*    DTSELA    */
                            unsigned char CNTSELD:1;    /*    CNTSELD   */
                            unsigned char CNTSELC:1;    /*    CNTSELC   */
                            unsigned char CNTSELB:1;    /*    CNTSELB   */
                            unsigned char CNTSELA:1;    /*    CNTSELA   */
                            }      BIT;                 /*              */
                     }          PMDR;                   /*              */
};                                                      /*              */
struct st_atu7 {                                        /* struct ATU7  */
               unsigned short   TCNTA;                  /* TCNTA        */
               unsigned short   TCNTB;                  /* TCNTB        */
               unsigned short   TCNTC;                  /* TCNTC        */
               unsigned short   TCNTD;                  /* TCNTD        */
               unsigned short   CYLRA;                  /* CYLRA        */
               unsigned short   CYLRB;                  /* CYLRB        */
               unsigned short   CYLRC;                  /* CYLRC        */
               unsigned short   CYLRD;                  /* CYLRD        */
               unsigned short   BFRA;                   /* BFRA         */
               unsigned short   BFRB;                   /* BFRB         */
               unsigned short   BFRC;                   /* BFRC         */
               unsigned short   BFRD;                   /* BFRD         */
               unsigned short   DTRA;                   /* DTRA         */
               unsigned short   DTRB;                   /* DTRB         */
               unsigned short   DTRC;                   /* DTRC         */
               unsigned short   DTRD;                   /* DTRD         */
               union {                                  /* TCRB         */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char       :1;     /*              */
                            unsigned char CKSELD:3;     /*    CKSELD    */
                            unsigned char       :1;     /*              */
                            unsigned char CKSELC:3;     /*    CKSELC    */
                            }      BIT;                 /*              */
                     }          TCRB;                   /*              */
               union {                                  /* TCRA         */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char       :1;     /*              */
                            unsigned char CKSELB:3;     /*    CKSELB    */
                            unsigned char       :1;     /*              */
                            unsigned char CKSELA:3;     /*    CKSELA    */
                            }      BIT;                 /*              */
                     }          TCRA;                   /*              */
               union {                                  /* TSR          */
                     unsigned short WORD;               /*  Word Access */
                     struct {                           /*  Bit  Access */
                            unsigned short     :8;      /*              */
                            unsigned short UDD :1;      /*    UDD       */
                            unsigned short UDC :1;      /*    UDC       */
                            unsigned short UDB :1;      /*    UDB       */
                            unsigned short UDA :1;      /*    UDA       */
                            unsigned short CMFD:1;      /*    CMFD      */
                            unsigned short CMFC:1;      /*    CMFC      */
                            unsigned short CMFB:1;      /*    CMFB      */
                            unsigned short CMFA:1;      /*    CMFA      */
                            }       BIT;                /*              */
                     }          TSR;                    /*              */
               union {                                  /* TIER         */
                     unsigned short WORD;               /*  Word Access */
                     struct {                           /*  Bit  Access */
                            unsigned short     :12;     /*              */
                            unsigned short CMED: 1;     /*    CMED      */
                            unsigned short CMEC: 1;     /*    CMEC      */
                            unsigned short CMEB: 1;     /*    CMEB      */
                            unsigned short CMEA: 1;     /*    CMEA      */
                            }       BIT;                /*              */
                     }          TIER;                   /*              */
};                                                      /*              */
struct st_atu8 {                                        /* struct ATU8  */
               unsigned short   DCNTA;                  /* DCNTA        */
               unsigned short   DCNTB;                  /* DCNTB        */
               unsigned short   DCNTC;                  /* DCNTC        */
               unsigned short   DCNTD;                  /* DCNTD        */
               unsigned short   DCNTE;                  /* DCNTE        */
               unsigned short   DCNTF;                  /* DCNTF        */
               unsigned short   DCNTG;                  /* DCNTG        */
               unsigned short   DCNTH;                  /* DCNTH        */
               unsigned short   DCNTI;                  /* DCNTI        */
               unsigned short   DCNTJ;                  /* DCNTJ        */
               unsigned short   DCNTK;                  /* DCNTK        */
               unsigned short   DCNTL;                  /* DCNTL        */
               unsigned short   DCNTM;                  /* DCNTM        */
               unsigned short   DCNTN;                  /* DCNTN        */
               unsigned short   DCNTO;                  /* DCNTO        */
               unsigned short   DCNTP;                  /* DCNTP        */
               unsigned short   RLDR;                   /* RLDR         */
               union {                                  /* TCNR         */
                     unsigned short WORD;               /*  Word Access */
                     struct {                           /*  Bit  Access */
                            unsigned short CNP:1;       /*    CNP       */
                            unsigned short CNO:1;       /*    CNO       */
                            unsigned short CNN:1;       /*    CNN       */
                            unsigned short CNM:1;       /*    CNM       */
                            unsigned short CNL:1;       /*    CNL       */
                            unsigned short CNK:1;       /*    CNK       */
                            unsigned short CNJ:1;       /*    CNJ       */
                            unsigned short CNI:1;       /*    CNI       */
                            unsigned short CNH:1;       /*    CNH       */
                            unsigned short CNG:1;       /*    CNG       */
                            unsigned short CNF:1;       /*    CNF       */
                            unsigned short CNE:1;       /*    CNE       */
                            unsigned short CND:1;       /*    CND       */
                            unsigned short CNC:1;       /*    CNC       */
                            unsigned short CNB:1;       /*    CNB       */
                            unsigned short CNA:1;       /*    CNA       */
                            }       BIT;                /*              */
                     }          TCNR;                   /*              */
               union {                                  /* OTR          */
                     unsigned short WORD;               /*  Word Access */
                     struct {                           /*  Bit  Access */
                            unsigned short OTEP:1;      /*    OTEP      */
                            unsigned short OTEO:1;      /*    OTEO      */
                            unsigned short OTEN:1;      /*    OTEN      */
                            unsigned short OTEM:1;      /*    OTEM      */
                            unsigned short OTEL:1;      /*    OTEL      */
                            unsigned short OTEK:1;      /*    OTEK      */
                            unsigned short OTEJ:1;      /*    OTEJ      */
                            unsigned short OTEI:1;      /*    OTEI      */
                            unsigned short OTEH:1;      /*    OTEH      */
                            unsigned short OTEG:1;      /*    OTEG      */
                            unsigned short OTEF:1;      /*    OTEF      */
                            unsigned short OTEE:1;      /*    OTEE      */
                            unsigned short OTED:1;      /*    OTED      */
                            unsigned short OTEC:1;      /*    OTEC      */
                            unsigned short OTEB:1;      /*    OTEB      */
                            unsigned short OTEA:1;      /*    OTEA      */
                            }       BIT;                /*              */
                     }          OTR;                    /*              */
               union {                                  /* DSTR         */
                     unsigned short WORD;               /*  Word Access */
                     struct {                           /*  Bit  Access */
                            unsigned short DSTP:1;      /*    DSTP      */
                            unsigned short DSTO:1;      /*    DSTO      */
                            unsigned short DSTN:1;      /*    DSTN      */
                            unsigned short DSTM:1;      /*    DSTM      */
                            unsigned short DSTL:1;      /*    DSTL      */
                            unsigned short DSTK:1;      /*    DSTK      */
                            unsigned short DSTJ:1;      /*    DSTJ      */
                            unsigned short DSTI:1;      /*    DSTI      */
                            unsigned short DSTH:1;      /*    DSTH      */
                            unsigned short DSTG:1;      /*    DSTG      */
                            unsigned short DSTF:1;      /*    DSTF      */
                            unsigned short DSTE:1;      /*    DSTE      */
                            unsigned short DSTD:1;      /*    DSTD      */
                            unsigned short DSTC:1;      /*    DSTC      */
                            unsigned short DSTB:1;      /*    DSTB      */
                            unsigned short DSTA:1;      /*    DSTA      */
                            }       BIT;                /*              */
                     }          DSTR;                   /*              */
               union {                                  /* TCR          */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char       :1;     /*              */
                            unsigned char CKSELB:3;     /*    CKSELB    */
                            unsigned char       :1;     /*              */
                            unsigned char CKSELA:3;     /*    CKSELA    */
                            }      BIT;                 /*              */
                     }          TCR;                    /*              */
               char             wk;                     /*              */
               union {                                  /* TSR          */
                     unsigned short WORD;               /*  Word Access */
                     struct {                           /*  Bit  Access */
                            unsigned short OSFP:1;      /*    OSFP      */
                            unsigned short OSFO:1;      /*    OSFO      */
                            unsigned short OSFN:1;      /*    OSFN      */
                            unsigned short OSFM:1;      /*    OSFM      */
                            unsigned short OSFL:1;      /*    OSFL      */
                            unsigned short OSFK:1;      /*    OSFK      */
                            unsigned short OSFJ:1;      /*    OSFJ      */
                            unsigned short OSFI:1;      /*    OSFI      */
                            unsigned short OSFH:1;      /*    OSFH      */
                            unsigned short OSFG:1;      /*    OSFG      */
                            unsigned short OSFF:1;      /*    OSFF      */
                            unsigned short OSFE:1;      /*    OSFE      */
                            unsigned short OSFD:1;      /*    OSFD      */
                            unsigned short OSFC:1;      /*    OSFC      */
                            unsigned short OSFB:1;      /*    OSFB      */
                            unsigned short OSFA:1;      /*    OSFA      */
                            }       BIT;                /*              */
                     }          TSR;                    /*              */
               union {                                  /* TIER         */
                     unsigned short WORD;               /*  Word Access */
                     struct {                           /*  Bit  Access */
                            unsigned short OSEP:1;      /*    OSEP      */
                            unsigned short OSEO:1;      /*    OSEO      */
                            unsigned short OSEN:1;      /*    OSEN      */
                            unsigned short OSEM:1;      /*    OSEM      */
                            unsigned short OSEL:1;      /*    OSEL      */
                            unsigned short OSEK:1;      /*    OSEK      */
                            unsigned short OSEJ:1;      /*    OSEJ      */
                            unsigned short OSEI:1;      /*    OSEI      */
                            unsigned short OSEH:1;      /*    OSEH      */
                            unsigned short OSEG:1;      /*    OSEG      */
                            unsigned short OSEF:1;      /*    OSEF      */
                            unsigned short OSEE:1;      /*    OSEE      */
                            unsigned short OSED:1;      /*    OSED      */
                            unsigned short OSEC:1;      /*    OSEC      */
                            unsigned short OSEB:1;      /*    OSEB      */
                            unsigned short OSEA:1;      /*    OSEA      */
                            }       BIT;                /*              */
                     }          TIER;                   /*              */
               union {                                  /* RLDENR       */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char RLDEN:1;      /*    RLDEN     */
                            }      BIT;                 /*              */
                     }          RLDENR;                 /*              */
};                                                      /*              */
struct st_atu9 {                                        /* struct ATU9  */
               unsigned char    ECNTA;                  /* ECNTA        */
               char             wk1;                    /*              */
               unsigned char    ECNTB;                  /* ECNTB        */
               char             wk2;                    /*              */
               unsigned char    ECNTC;                  /* ECNTC        */
               char             wk3;                    /*              */
               unsigned char    ECNTD;                  /* ECNTD        */
               char             wk4;                    /*              */
               unsigned char    ECNTE;                  /* ECNTE        */
               char             wk5;                    /*              */
               unsigned char    ECNTF;                  /* ECNTF        */
               char             wk6;                    /*              */
               unsigned char    GRA;                    /* GRA          */
               char             wk7;                    /*              */
               unsigned char    GRB;                    /* GRB          */
               char             wk8;                    /*              */
               unsigned char    GRC;                    /* GRC          */
               char             wk9;                    /*              */
               unsigned char    GRD;                    /* GRD          */
               char             wk10;                   /*              */
               unsigned char    GRE;                    /* GRE          */
               char             wk11;                   /*              */
               unsigned char    GRF;                    /* GRF          */
               char             wk12;                   /*              */
               union {                                  /* TCRA         */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char        :1;    /*              */
                            unsigned char TRG3BEN:1;    /*    TRG3BEN   */
                            unsigned char EGSELB :2;    /*    EGSELB    */
                            unsigned char        :1;    /*              */
                            unsigned char TRG3AEN:1;    /*    TRG3AEN   */
                            unsigned char EGSELA :2;    /*    EGSELA    */
                            }      BIT;                 /*              */
                     }          TCRA;                   /*              */
               char             wk13;                   /*              */
               union {                                  /* TCRB         */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char        :1;    /*              */
                            unsigned char TRG3DEN:1;    /*    TRG3DEN   */
                            unsigned char EGSELD :2;    /*    EGSELD    */
                            unsigned char        :1;    /*              */
                            unsigned char TRG3CEN:1;    /*    TRG3CEN   */
                            unsigned char EGSELC :2;    /*    EGSELC    */
                            }      BIT;                 /*              */
                     }          TCRB;                   /*              */
               char             wk14;                   /*              */
               union {                                  /* TCRC         */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char       :2;     /*              */
                            unsigned char EGSELF:2;     /*    EGSELF    */
                            unsigned char       :2;     /*              */
                            unsigned char EGSELE:2;     /*    EGSELE    */
                            }      BIT;                 /*              */
                     }          TCRC;                   /*              */
               char             wk15;                   /*              */
               union {                                  /* TSR          */
                     unsigned short WORD;               /*  Word Access */
                     struct {                           /*  Bit  Access */
                            unsigned short     :10;     /*              */
                            unsigned short CMFF: 1;     /*    CMFF      */
                            unsigned short CMFE: 1;     /*    CMFE      */
                            unsigned short CMFD: 1;     /*    CMFD      */
                            unsigned short CMFC: 1;     /*    CMFC      */
                            unsigned short CMFB: 1;     /*    CMFB      */
                            unsigned short CMFA: 1;     /*    CMFA      */
                            }       BIT;                /*              */
                     }          TSR;                    /*              */
               union {                                  /* TIER         */
                     unsigned short WORD;               /*  Word Access */
                     struct {                           /*  Bit  Access */
                            unsigned short     :10;     /*              */
                            unsigned short CMEF: 1;     /*    CMEF      */
                            unsigned short CMEE: 1;     /*    CMEE      */
                            unsigned short CMED: 1;     /*    CMED      */
                            unsigned short CMEC: 1;     /*    CMEC      */
                            unsigned short CMEB: 1;     /*    CMEB      */
                            unsigned short CMEA: 1;     /*    CMEA      */
                            }       BIT;                /*              */
                     }          TIER;                   /*              */
};                                                      /*              */
struct st_atu10 {                                       /* struct ATU10 */
                unsigned int    TCNTA;                  /* TCNTA        */
                unsigned char   TCNTB;                  /* TCNTB        */
                char            wk1;                    /*              */
                unsigned short  TCNTC;                  /* TCNTC        */
                unsigned char   TCNTD;                  /* TCNTD        */
                char            wk2;                    /*              */
                unsigned short  TCNTE;                  /* TCNTE        */
                unsigned short  TCNTF;                  /* TCNTF        */
                unsigned short  TCNTG;                  /* TCNTG        */
                unsigned int    ICRA;                   /* ICRA         */
                unsigned int    OCRA;                   /* OCRA         */
                unsigned char   OCRB;                   /* OCRB         */
                char            wk3;                    /*              */
                unsigned short  RLDC;                   /* RLDC         */
                unsigned short  GRG;                    /* GRG          */
                unsigned char   TCNTH;                  /* TCNTH        */
                char            wk4;                    /*              */
                unsigned char   NCR;                    /* NCR          */
                char            wk5;                    /*              */
                union {                                 /* TIOR         */
                      unsigned char BYTE;               /*  Byte Access */
                      struct {                          /*  Bit  Access */
                             unsigned char RLDEN:1;     /*    RLDEN     */
                             unsigned char CCS  :1;     /*    CCS       */
                             unsigned char PIM  :2;     /*    PIM       */
                             unsigned char      :1;     /*              */
                             unsigned char IOG  :3;     /*    IOG       */
                             }      BIT;                /*              */
                      }         TIOR;                   /*              */
                char            wk6;                    /*              */
                union {                                 /* TCR          */
                      unsigned char BYTE;               /*  Byte Access */
                      struct {                          /*  Bit  Access */
                             unsigned char TRG2BEN:1;   /*    TRG2BEN   */
                             unsigned char TRG1BEN:1;   /*    TRG1BEN   */
                             unsigned char TRG2AEN:1;   /*    TRG2AEN   */
                             unsigned char TRG1AEN:1;   /*    TRG1AEN   */
                             unsigned char TRG0DEN:1;   /*    TRG0DEN   */
                             unsigned char NCE    :1;   /*    NCE       */
                             unsigned char CKEG   :2;   /*    CKEG      */
                             }      BIT;                /*              */
                      }         TCR;                    /*              */
                char            wk7;                    /*              */
                unsigned short  TCCLR;                  /* TCCLR        */
                union {                                 /* TSR          */
                      unsigned short WORD;              /*  Word Access */
                      struct {                          /*  Bit  Access */
                             unsigned short     :12;    /*              */
                             unsigned short CMFG: 1;    /*    CMFG      */
                             unsigned short CMFB: 1;    /*    CMFB      */
                             unsigned short ICFA: 1;    /*    ICFA      */
                             unsigned short CMFA: 1;    /*    CMFA      */
                             }       BIT;               /*              */
                      }         TSR;                    /*              */
                union {                                 /* TIER         */
                      unsigned short WORD;              /*  Word Access */
                      struct {                          /*  Bit  Access */
                             unsigned short     :11;    /*              */
                             unsigned short IREG: 1;    /*    IREG      */
                             unsigned short CMEG: 1;    /*    CMEG      */
                             unsigned short CMEB: 1;    /*    CMEB      */
                             unsigned short ICEA: 1;    /*    ICEA      */
                             unsigned short CMEA: 1;    /*    CMEA      */
                             }       BIT;               /*              */
                      }         TIER;                   /*              */
};                                                      /*              */
struct st_atu11 {                                       /* struct ATU11 */
                unsigned short  TCNT;                   /* TCNT         */
                unsigned short  GRA;                    /* GRA          */
                unsigned short  GRB;                    /* GRB          */
                union {                                 /* TIOR         */
                      unsigned char BYTE;               /*  Byte Access */
                      struct {                          /*  Bit  Access */
                             unsigned char    :1;       /*              */
                             unsigned char IOB:3;       /*    IOB       */
                             unsigned char    :1;       /*              */
                             unsigned char IOA:3;       /*    IOA       */
                             }      BIT;                /*              */
                      }         TIOR;                   /*              */
                char            wk1;                    /*              */
                union {                                 /* TCR          */
                      unsigned char BYTE;               /*  Byte Access */
                      struct {                          /*  Bit  Access */
                             unsigned char       :2;    /*              */
                             unsigned char CKEG  :2;    /*    CKEG      */
                             unsigned char       :1;    /*              */
                             unsigned char CKSELA:3;    /*    CKSELA    */
                             }      BIT;                /*              */
                      }         TCR;                    /*              */
                char            wk2;                    /*              */
                union {                                 /* TSR          */
                      unsigned short WORD;              /*  Word Access */
                      struct {                          /*  Bit  Access */
                             unsigned short     :7;     /*              */
                             unsigned short OVF :1;     /*    OVF       */
                             unsigned short     :6;     /*              */
                             unsigned short IMFB:1;     /*    IMFB      */
                             unsigned short IMFA:1;     /*    IMFA      */
                             }       BIT;               /*              */
                      }         TSR;                    /*              */
                union {                                 /* TIER         */
                      unsigned short WORD;              /*  Word Access */
                      struct {                          /*  Bit  Access */
                             unsigned short     :7;     /*              */
                             unsigned short OVE :1;     /*    OVF       */
                             unsigned short     :6;     /*              */
                             unsigned short IMEB:1;     /*    IMEB      */
                             unsigned short IMEA:1;     /*    IMEA      */
                             }       BIT;               /*              */
                      }         TIER;                   /*              */
};                                                      /*              */
struct st_apc {                                         /* struct APC   */
              union {                                   /* POPCR        */
                    unsigned short WORD;                /*  Word Access */
                    struct {                            /*  Byte Access */
                           unsigned char ROE;           /*    High      */
                           unsigned char SOE;           /*    Low       */
                           }       BYTE;                /*              */
                    struct {                            /*  Bit  Access */
                           unsigned char PULS7ROE:1;    /*    PULS7ROE  */
                           unsigned char PULS6ROE:1;    /*    PULS6ROE  */
                           unsigned char PULS5ROE:1;    /*    PULS5ROE  */
                           unsigned char PULS4ROE:1;    /*    PULS4ROE  */
                           unsigned char PULS3ROE:1;    /*    PULS3ROE  */
                           unsigned char PULS2ROE:1;    /*    PULS2ROE  */
                           unsigned char PULS1ROE:1;    /*    PULS1ROE  */
                           unsigned char PULS0ROE:1;    /*    PULS0ROE  */
                           unsigned char PULS7SOE:1;    /*    PULS7SOE  */
                           unsigned char PULS6SOE:1;    /*    PULS6SOE  */
                           unsigned char PULS5SOE:1;    /*    PULS5SOE  */
                           unsigned char PULS4SOE:1;    /*    PULS4SOE  */
                           unsigned char PULS3SOE:1;    /*    PULS3SOE  */
                           unsigned char PULS2SOE:1;    /*    PULS2SOE  */
                           unsigned char PULS1SOE:1;    /*    PULS1SOE  */
                           unsigned char PULS0SOE:1;    /*    PULS0SOE  */
                           }       BIT;                 /*              */
                    }           POPCR;                  /*              */
};                                                      /*              */
union un_syscr {                                        /* union SYSCR  */
               unsigned char BYTE;                      /*  Byte Access */
               struct {                                 /*  Bit  Access */
                      unsigned char        :6;          /*              */
                      unsigned char AUDSRST:1;          /*    AUDSRST   */
                      unsigned char RAME   :1;          /*    RAME      */
                      }      BIT;                       /*              */
};                                                      /*              */
union un_mstcr {                                        /* union MSTCR  */
               unsigned short WRITE;                    /*  Write Access*/
               union {                                  /*  Read  Access*/
                     unsigned char BYTE[2];             /*   Byte Access*/
                     struct {                           /*   Bit  Access*/
                            unsigned char      :8;      /*              */
                            unsigned char      :4;      /*              */
                            unsigned char _AUD :1;      /*    MSTOP3    */
                            unsigned char _HUDI:1;      /*    MSTOP2    */
                            unsigned char _FPU :1;      /*    MSTOP1    */
                            unsigned char _UBC :1;      /*    MSTOP0    */
                            }      BIT;                 /*              */
                     }        READ;                     /*              */
};                                                      /*              */
struct st_cmt {                                         /* struct CMT   */
              union {                                   /* CMSTR        */
                    unsigned short WORD;                /*  Word Access */
                    struct {                            /*  Bit  Access */
                           unsigned char     :8;        /*              */
                           unsigned char     :6;        /*              */
                           unsigned char STR1:1;        /*    STR1      */
                           unsigned char STR0:1;        /*    STR0      */
                           }       BIT;                 /*              */
                    }           CMSTR;                  /*              */
};                                                      /*              */
struct st_cmt0 {                                        /* struct CMT0  */
               union {                                  /* CMCSR        */
                     unsigned short WORD;               /*  Word Access */
                     struct {                           /*  Byte Access */
                            unsigned char     :8;       /*              */
                            unsigned char CMF :1;       /*    CMF       */
                            unsigned char CMIE:1;       /*    CMIE      */
                            unsigned char     :4;       /*              */
                            unsigned char CKS :2;       /*    CKS       */
                            }       BIT;                /*              */
                     }          CMCSR;                  /*              */
               unsigned short   CMCNT;                  /* CMCNT        */
               unsigned short   CMCOR;                  /* CMCOR        */
};                                                      /*              */
struct st_pa {                                          /* struct PA    */
             union {                                    /* PADR         */
                   unsigned short WORD;                 /*  Word Access */
                   struct {                             /*  Byte Access */
                          unsigned char H;              /*    High      */
                          unsigned char L;              /*    Low       */
                          }       BYTE;                 /*              */
                   struct {                             /*  Bit  Access */
                          unsigned char B15:1;          /*    Bit 15    */
                          unsigned char B14:1;          /*    Bit 14    */
                          unsigned char B13:1;          /*    Bit 13    */
                          unsigned char B12:1;          /*    Bit 12    */
                          unsigned char B11:1;          /*    Bit 11    */
                          unsigned char B10:1;          /*    Bit 10    */
                          unsigned char B9 :1;          /*    Bit  9    */
                          unsigned char B8 :1;          /*    Bit  8    */
                          unsigned char B7 :1;          /*    Bit  7    */
                          unsigned char B6 :1;          /*    Bit  6    */
                          unsigned char B5 :1;          /*    Bit  5    */
                          unsigned char B4 :1;          /*    Bit  4    */
                          unsigned char B3 :1;          /*    Bit  3    */
                          unsigned char B2 :1;          /*    Bit  2    */
                          unsigned char B1 :1;          /*    Bit  1    */
                          unsigned char B0 :1;          /*    Bit  0    */
                          }       BIT;                  /*              */
                   }            DR;                     /*              */
};                                                      /*              */
struct st_pb {                                          /* struct PB    */
             union {                                    /* PBDR         */
                   unsigned short WORD;                 /*  Word Access */
                   struct {                             /*  Byte Access */
                          unsigned char H;              /*    High      */
                          unsigned char L;              /*    Low       */
                          }       BYTE;                 /*              */
                   struct {                             /*  Bit  Access */
                          unsigned char B15:1;          /*    Bit 15    */
                          unsigned char B14:1;          /*    Bit 14    */
                          unsigned char B13:1;          /*    Bit 13    */
                          unsigned char B12:1;          /*    Bit 12    */
                          unsigned char B11:1;          /*    Bit 11    */
                          unsigned char B10:1;          /*    Bit 10    */
                          unsigned char B9 :1;          /*    Bit  9    */
                          unsigned char B8 :1;          /*    Bit  8    */
                          unsigned char B7 :1;          /*    Bit  7    */
                          unsigned char B6 :1;          /*    Bit  6    */
                          unsigned char B5 :1;          /*    Bit  5    */
                          unsigned char B4 :1;          /*    Bit  4    */
                          unsigned char B3 :1;          /*    Bit  3    */
                          unsigned char B2 :1;          /*    Bit  2    */
                          unsigned char B1 :1;          /*    Bit  1    */
                          unsigned char B0 :1;          /*    Bit  0    */
                          }       BIT;                  /*              */
                   }            DR;                     /*              */
};                                                      /*              */
struct st_pc {                                          /* struct PC    */
             union {                                    /* PCDR         */
                   unsigned short WORD;                 /*  Word Access */
                   struct {                             /*  Byte Access */
                          unsigned char H;              /*    High      */
                          unsigned char L;              /*    Low       */
                          }       BYTE;                 /*              */
                   struct {                             /*  Bit  Access */
                          unsigned char   :8;           /*              */
                          unsigned char   :3;           /*              */
                          unsigned char B4:1;           /*    Bit 4     */
                          unsigned char B3:1;           /*    Bit 3     */
                          unsigned char B2:1;           /*    Bit 2     */
                          unsigned char B1:1;           /*    Bit 1     */
                          unsigned char B0:1;           /*    Bit 0     */
                          }       BIT;                  /*              */
                   }            DR;                     /*              */
};                                                      /*              */
struct st_pd {                                          /* struct PD    */
             union {                                    /* PDDR         */
                   unsigned short WORD;                 /*  Word Access */
                   struct {                             /*  Byte Access */
                          unsigned char H;              /*    High      */
                          unsigned char L;              /*    Low       */
                          }       BYTE;                 /*              */
                   struct {                             /*  Bit  Access */
                          unsigned char    :2;          /*              */
                          unsigned char B13:1;          /*    Bit 13    */
                          unsigned char B12:1;          /*    Bit 12    */
                          unsigned char B11:1;          /*    Bit 11    */
                          unsigned char B10:1;          /*    Bit 10    */
                          unsigned char B9 :1;          /*    Bit  9    */
                          unsigned char B8 :1;          /*    Bit  8    */
                          unsigned char B7 :1;          /*    Bit  7    */
                          unsigned char B6 :1;          /*    Bit  6    */
                          unsigned char B5 :1;          /*    Bit  5    */
                          unsigned char B4 :1;          /*    Bit  4    */
                          unsigned char B3 :1;          /*    Bit  3    */
                          unsigned char B2 :1;          /*    Bit  2    */
                          unsigned char B1 :1;          /*    Bit  1    */
                          unsigned char B0 :1;          /*    Bit  0    */
                          }       BIT;                  /*              */
                   }            DR;                     /*              */
};                                                      /*              */
struct st_pe {                                          /* struct PE    */
             union {                                    /* PEDR         */
                   unsigned short WORD;                 /*  Word Access */
                   struct {                             /*  Byte Access */
                          unsigned char H;              /*    High      */
                          unsigned char L;              /*    Low       */
                          }       BYTE;                 /*              */
                   struct {                             /*  Bit  Access */
                          unsigned char B15:1;          /*    Bit 15    */
                          unsigned char B14:1;          /*    Bit 14    */
                          unsigned char B13:1;          /*    Bit 13    */
                          unsigned char B12:1;          /*    Bit 12    */
                          unsigned char B11:1;          /*    Bit 11    */
                          unsigned char B10:1;          /*    Bit 10    */
                          unsigned char B9 :1;          /*    Bit  9    */
                          unsigned char B8 :1;          /*    Bit  8    */
                          unsigned char B7 :1;          /*    Bit  7    */
                          unsigned char B6 :1;          /*    Bit  6    */
                          unsigned char B5 :1;          /*    Bit  5    */
                          unsigned char B4 :1;          /*    Bit  4    */
                          unsigned char B3 :1;          /*    Bit  3    */
                          unsigned char B2 :1;          /*    Bit  2    */
                          unsigned char B1 :1;          /*    Bit  1    */
                          unsigned char B0 :1;          /*    Bit  0    */
                          }       BIT;                  /*              */
                   }            DR;                     /*              */
};                                                      /*              */
struct st_pf {                                          /* struct PF    */
             union {                                    /* PFDR         */
                   unsigned short WORD;                 /*  Word Access */
                   struct {                             /*  Byte Access */
                          unsigned char H;              /*    High      */
                          unsigned char L;              /*    Low       */
                          }       BYTE;                 /*              */
                   struct {                             /*  Bit  Access */
                          unsigned char B15:1;          /*    Bit 15    */
                          unsigned char B14:1;          /*    Bit 14    */
                          unsigned char B13:1;          /*    Bit 13    */
                          unsigned char B12:1;          /*    Bit 12    */
                          unsigned char B11:1;          /*    Bit 11    */
                          unsigned char B10:1;          /*    Bit 10    */
                          unsigned char B9 :1;          /*    Bit  9    */
                          unsigned char B8 :1;          /*    Bit  8    */
                          unsigned char B7 :1;          /*    Bit  7    */
                          unsigned char B6 :1;          /*    Bit  6    */
                          unsigned char B5 :1;          /*    Bit  5    */
                          unsigned char B4 :1;          /*    Bit  4    */
                          unsigned char B3 :1;          /*    Bit  3    */
                          unsigned char B2 :1;          /*    Bit  2    */
                          unsigned char B1 :1;          /*    Bit  1    */
                          unsigned char B0 :1;          /*    Bit  0    */
                          }       BIT;                  /*              */
                   }            DR;                     /*              */
};                                                      /*              */
struct st_pg {                                          /* struct PG    */
             union {                                    /* PGDR         */
                   unsigned short WORD;                 /*  Word Access */
                   struct {                             /*  Byte Access */
                          unsigned char H;              /*    High      */
                          unsigned char L;              /*    Low       */
                          }       BYTE;                 /*              */
                   struct {                             /*  Bit  Access */
                          unsigned char   :8;           /*              */
                          unsigned char   :4;           /*              */
                          unsigned char B3:1;           /*    Bit 3     */
                          unsigned char B2:1;           /*    Bit 2     */
                          unsigned char B1:1;           /*    Bit 1     */
                          unsigned char B0:1;           /*    Bit 0     */
                          }       BIT;                  /*              */
                   }            DR;                     /*              */
};                                                      /*              */
struct st_ph {                                          /* struct PH    */
             union {                                    /* PHDR         */
                   unsigned short WORD;                 /*  Word Access */
                   struct {                             /*  Byte Access */
                          unsigned char H;              /*    High      */
                          unsigned char L;              /*    Low       */
                          }       BYTE;                 /*              */
                   struct {                             /*  Bit  Access */
                          unsigned char B15:1;          /*    Bit 15    */
                          unsigned char B14:1;          /*    Bit 14    */
                          unsigned char B13:1;          /*    Bit 13    */
                          unsigned char B12:1;          /*    Bit 12    */
                          unsigned char B11:1;          /*    Bit 11    */
                          unsigned char B10:1;          /*    Bit 10    */
                          unsigned char B9 :1;          /*    Bit  9    */
                          unsigned char B8 :1;          /*    Bit  8    */
                          unsigned char B7 :1;          /*    Bit  7    */
                          unsigned char B6 :1;          /*    Bit  6    */
                          unsigned char B5 :1;          /*    Bit  5    */
                          unsigned char B4 :1;          /*    Bit  4    */
                          unsigned char B3 :1;          /*    Bit  3    */
                          unsigned char B2 :1;          /*    Bit  2    */
                          unsigned char B1 :1;          /*    Bit  1    */
                          unsigned char B0 :1;          /*    Bit  0    */
                          }       BIT;                  /*              */
                   }            DR;                     /*              */
};                                                      /*              */
struct st_pj {                                          /* struct PJ    */
             union {                                    /* PJDR         */
                   unsigned short WORD;                 /*  Word Access */
                   struct {                             /*  Byte Access */
                          unsigned char H;              /*    High      */
                          unsigned char L;              /*    Low       */
                          }       BYTE;                 /*              */
                   struct {                             /*  Bit  Access */
                          unsigned char B15:1;          /*    Bit 15    */
                          unsigned char B14:1;          /*    Bit 14    */
                          unsigned char B13:1;          /*    Bit 13    */
                          unsigned char B12:1;          /*    Bit 12    */
                          unsigned char B11:1;          /*    Bit 11    */
                          unsigned char B10:1;          /*    Bit 10    */
                          unsigned char B9 :1;          /*    Bit  9    */
                          unsigned char B8 :1;          /*    Bit  8    */
                          unsigned char B7 :1;          /*    Bit  7    */
                          unsigned char B6 :1;          /*    Bit  6    */
                          unsigned char B5 :1;          /*    Bit  5    */
                          unsigned char B4 :1;          /*    Bit  4    */
                          unsigned char B3 :1;          /*    Bit  3    */
                          unsigned char B2 :1;          /*    Bit  2    */
                          unsigned char B1 :1;          /*    Bit  1    */
                          unsigned char B0 :1;          /*    Bit  0    */
                          }       BIT;                  /*              */
                   }            DR;                     /*              */
};                                                      /*              */
struct st_pk {                                          /* struct PK    */
             union {                                    /* PKDR         */
                   unsigned short WORD;                 /*  Word Access */
                   struct {                             /*  Byte Access */
                          unsigned char H;              /*    High      */
                          unsigned char L;              /*    Low       */
                          }       BYTE;                 /*              */
                   struct {                             /*  Bit  Access */
                          unsigned char B15:1;          /*    Bit 15    */
                          unsigned char B14:1;          /*    Bit 14    */
                          unsigned char B13:1;          /*    Bit 13    */
                          unsigned char B12:1;          /*    Bit 12    */
                          unsigned char B11:1;          /*    Bit 11    */
                          unsigned char B10:1;          /*    Bit 10    */
                          unsigned char B9 :1;          /*    Bit  9    */
                          unsigned char B8 :1;          /*    Bit  8    */
                          unsigned char B7 :1;          /*    Bit  7    */
                          unsigned char B6 :1;          /*    Bit  6    */
                          unsigned char B5 :1;          /*    Bit  5    */
                          unsigned char B4 :1;          /*    Bit  4    */
                          unsigned char B3 :1;          /*    Bit  3    */
                          unsigned char B2 :1;          /*    Bit  2    */
                          unsigned char B1 :1;          /*    Bit  1    */
                          unsigned char B0 :1;          /*    Bit  0    */
                          }       BIT;                  /*              */
                   }            DR;                     /*              */
};                                                      /*              */
struct st_pl {                                          /* struct PL    */
             union {                                    /* PLDR         */
                   unsigned short WORD;                 /*  Word Access */
                   struct {                             /*  Byte Access */
                          unsigned char H;              /*    High      */
                          unsigned char L;              /*    Low       */
                          }       BYTE;                 /*              */
                   struct {                             /*  Bit  Access */
                          unsigned char    :2;          /*              */
                          unsigned char B13:1;          /*    Bit 13    */
                          unsigned char B12:1;          /*    Bit 12    */
                          unsigned char B11:1;          /*    Bit 11    */
                          unsigned char B10:1;          /*    Bit 10    */
                          unsigned char B9 :1;          /*    Bit  9    */
                          unsigned char B8 :1;          /*    Bit  8    */
                          unsigned char B7 :1;          /*    Bit  7    */
                          unsigned char B6 :1;          /*    Bit  6    */
                          unsigned char B5 :1;          /*    Bit  5    */
                          unsigned char B4 :1;          /*    Bit  4    */
                          unsigned char B3 :1;          /*    Bit  3    */
                          unsigned char B2 :1;          /*    Bit  2    */
                          unsigned char B1 :1;          /*    Bit  1    */
                          unsigned char B0 :1;          /*    Bit  0    */
                          }       BIT;                  /*              */
                   }            DR;                     /*              */
};                                                      /*              */
struct st_pfc {                                         /* struct PFC   */
              union {                                   /* PAIOR        */
                    unsigned short WORD;                /*  Word Access */
                    struct {                            /*  Byte Access */
                           unsigned char H;             /*    High      */
                           unsigned char L;             /*    Low       */
                           }       BYTE;                /*              */
                    struct {                            /*  Bit  Access */
                           unsigned char B15:1;         /*    Bit 15    */
                           unsigned char B14:1;         /*    Bit 14    */
                           unsigned char B13:1;         /*    Bit 13    */
                           unsigned char B12:1;         /*    Bit 12    */
                           unsigned char B11:1;         /*    Bit 11    */
                           unsigned char B10:1;         /*    Bit 10    */
                           unsigned char B9 :1;         /*    Bit  9    */
                           unsigned char B8 :1;         /*    Bit  8    */
                           unsigned char B7 :1;         /*    Bit  7    */
                           unsigned char B6 :1;         /*    Bit  6    */
                           unsigned char B5 :1;         /*    Bit  5    */
                           unsigned char B4 :1;         /*    Bit  4    */
                           unsigned char B3 :1;         /*    Bit  3    */
                           unsigned char B2 :1;         /*    Bit  2    */
                           unsigned char B1 :1;         /*    Bit  1    */
                           unsigned char B0 :1;         /*    Bit  0    */
                           }       BIT;                 /*              */
                    }           PAIOR;                  /*              */
              union {                                   /* PACRH        */
                    unsigned short WORD;                /*  Word Access */
                    struct {                            /*  Byte Access */
                           unsigned char H;             /*    High      */
                           unsigned char L;             /*    Low       */
                           }       BYTE;                /*              */
                    struct {                            /*  Bit  Access */
                           unsigned char       :1;      /*              */
                           unsigned char PA15MD:1;      /*    PA15MD    */
                           unsigned char       :1;      /*              */
                           unsigned char PA14MD:1;      /*    PA14MD    */
                           unsigned char       :1;      /*              */
                           unsigned char PA13MD:1;      /*    PA13MD    */
                           unsigned char       :1;      /*              */
                           unsigned char PA12MD:1;      /*    PA12MD    */
                           unsigned char       :1;      /*              */
                           unsigned char PA11MD:1;      /*    PA11MD    */
                           unsigned char       :1;      /*              */
                           unsigned char PA10MD:1;      /*    PA10MD    */
                           unsigned char       :1;      /*              */
                           unsigned char PA9MD :1;      /*    PA9MD     */
                           unsigned char       :1;      /*              */
                           unsigned char PA8MD :1;      /*    PA8MD     */
                           }       BIT;                 /*              */
                    }           PACRH;                  /*              */
              union {                                   /* PACRL        */
                    unsigned short WORD;                /*  Word Access */
                    struct {                            /*  Byte Access */
                           unsigned char H;             /*    High      */
                           unsigned char L;             /*    Low       */
                           }       BYTE;                /*              */
                    struct {                            /*  Bit  Access */
                           unsigned char      :1;       /*              */
                           unsigned char PA7MD:1;       /*    PA7MD     */
                           unsigned char      :1;       /*              */
                           unsigned char PA6MD:1;       /*    PA6MD     */
                           unsigned char      :1;       /*              */
                           unsigned char PA5MD:1;       /*    PA5MD     */
                           unsigned char      :1;       /*              */
                           unsigned char PA4MD:1;       /*    PA4MD     */
                           unsigned char      :1;       /*              */
                           unsigned char PA3MD:1;       /*    PA3MD     */
                           unsigned char      :1;       /*              */
                           unsigned char PA2MD:1;       /*    PA2MD     */
                           unsigned char      :1;       /*              */
                           unsigned char PA1MD:1;       /*    PA1MD     */
                           unsigned char      :1;       /*              */
                           unsigned char PA0MD:1;       /*    PA0MD     */
                           }       BIT;                 /*              */
                    }           PACRL;                  /*              */
              char              wk1[2];                 /*              */
              union {                                   /* PHIOR        */
                    unsigned short WORD;                /*  Word Access */
                    struct {                            /*  Byte Access */
                           unsigned char H;             /*    High      */
                           unsigned char L;             /*    Low       */
                           }       BYTE;                /*              */
                    struct {                            /*  Bit  Access */
                           unsigned char B15:1;         /*    Bit 15    */
                           unsigned char B14:1;         /*    Bit 14    */
                           unsigned char B13:1;         /*    Bit 13    */
                           unsigned char B12:1;         /*    Bit 12    */
                           unsigned char B11:1;         /*    Bit 11    */
                           unsigned char B10:1;         /*    Bit 10    */
                           unsigned char B9 :1;         /*    Bit  9    */
                           unsigned char B8 :1;         /*    Bit  8    */
                           unsigned char B7 :1;         /*    Bit  7    */
                           unsigned char B6 :1;         /*    Bit  6    */
                           unsigned char B5 :1;         /*    Bit  5    */
                           unsigned char B4 :1;         /*    Bit  4    */
                           unsigned char B3 :1;         /*    Bit  3    */
                           unsigned char B2 :1;         /*    Bit  2    */
                           unsigned char B1 :1;         /*    Bit  1    */
                           unsigned char B0 :1;         /*    Bit  0    */
                           }       BIT;                 /*              */
                    }           PHIOR;                  /*              */
              union {                                   /* PHCR         */
                    unsigned short WORD;                /*  Word Access */
                    struct {                            /*  Byte Access */
                           unsigned char H;             /*    High      */
                           unsigned char L;             /*    Low       */
                           }       BYTE;                /*              */
                    struct {                            /*  Bit  Access */
                           unsigned char PH15MD:1;      /*    PH15MD    */
                           unsigned char PH14MD:1;      /*    PH14MD    */
                           unsigned char PH13MD:1;      /*    PH13MD    */
                           unsigned char PH12MD:1;      /*    PH12MD    */
                           unsigned char PH11MD:1;      /*    PH11MD    */
                           unsigned char PH10MD:1;      /*    PH10MD    */
                           unsigned char PH9MD :1;      /*    PH9MD     */
                           unsigned char PH8MD :1;      /*    PH8MD     */
                           unsigned char PH7MD :1;      /*    PH7MD     */
                           unsigned char PH6MD :1;      /*    PH6MD     */
                           unsigned char PH5MD :1;      /*    PH5MD     */
                           unsigned char PH4MD :1;      /*    PH4MD     */
                           unsigned char PH3MD :1;      /*    PH3MD     */
                           unsigned char PH2MD :1;      /*    PH2MD     */
                           unsigned char PH1MD :1;      /*    PH1MD     */
                           unsigned char PH0MD :1;      /*    PH0MD     */
                           }       BIT;                 /*              */
                    }           PHCR;                   /*              */
              char              wk2[4];                 /*              */
              union {                                   /* PBIOR        */
                    unsigned short WORD;                /*  Word Access */
                    struct {                            /*  Byte Access */
                           unsigned char H;             /*    High      */
                           unsigned char L;             /*    Low       */
                           }       BYTE;                /*              */
                    struct {                            /*  Bit  Access */
                           unsigned char B15:1;         /*    Bit 15    */
                           unsigned char B14:1;         /*    Bit 14    */
                           unsigned char B13:1;         /*    Bit 13    */
                           unsigned char B12:1;         /*    Bit 12    */
                           unsigned char B11:1;         /*    Bit 11    */
                           unsigned char B10:1;         /*    Bit 10    */
                           unsigned char B9 :1;         /*    Bit  9    */
                           unsigned char B8 :1;         /*    Bit  8    */
                           unsigned char B7 :1;         /*    Bit  7    */
                           unsigned char B6 :1;         /*    Bit  6    */
                           unsigned char B5 :1;         /*    Bit  5    */
                           unsigned char B4 :1;         /*    Bit  4    */
                           unsigned char B3 :1;         /*    Bit  3    */
                           unsigned char B2 :1;         /*    Bit  2    */
                           unsigned char B1 :1;         /*    Bit  1    */
                           unsigned char B0 :1;         /*    Bit  0    */
                           }       BIT;                 /*              */
                    }           PBIOR;                  /*              */
              union {                                   /* PBCRH        */
                    unsigned short WORD;                /*  Word Access */
                    struct {                            /*  Byte Access */
                           unsigned char H;             /*    High      */
                           unsigned char L;             /*    Low       */
                           }       BYTE;                /*              */
                    struct {                            /*  Bit  Access */
                           unsigned char PB15MD:2;      /*    PB15MD    */
                           unsigned char PB14MD:2;      /*    PB14MD    */
                           unsigned char       :1;      /*              */
                           unsigned char PB13MD:1;      /*    PB13MD    */
                           unsigned char PB12MD:2;      /*    PB12MD    */
                           unsigned char PB11MD:2;      /*    PB11MD    */
                           unsigned char PB10MD:2;      /*    PB10MD    */
                           unsigned char PB9MD :2;      /*    PB9MD     */
                           unsigned char PB8MD :2;      /*    PB8MD     */
                           }       BIT;                 /*              */
                    }           PBCRH;                  /*              */
              union {                                   /* PBCRL        */
                    unsigned short WORD;                /*  Word Access */
                    struct {                            /*  Byte Access */
                           unsigned char H;             /*    High      */
                           unsigned char L;             /*    Low       */
                           }       BYTE;                /*              */
                    struct {                            /*  Bit  Access */
                           unsigned char PB7MD:2;       /*    PB7MD     */
                           unsigned char PB6MD:2;       /*    PB6MD     */
                           unsigned char PB5MD:2;       /*    PB5MD     */
                           unsigned char PB4MD:2;       /*    PB4MD     */
                           unsigned char      :1;       /*              */
                           unsigned char PB3MD:1;       /*    PB3MD     */
                           unsigned char      :1;       /*              */
                           unsigned char PB2MD:1;       /*    PB2MD     */
                           unsigned char      :1;       /*              */
                           unsigned char PB1MD:1;       /*    PB1MD     */
                           unsigned char      :1;       /*              */
                           unsigned char PB0MD:1;       /*    PB0MD     */
                           }       BIT;                 /*              */
                    }           PBCRL;                  /*              */
              union {                                   /* PBIR         */
                    unsigned short WORD;                /*  Word Access */
                    struct {                            /*  Byte Access */
                           unsigned char H;             /*    High      */
                           unsigned char L;             /*    Low       */
                           }       BYTE;                /*              */
                    struct {                            /*  Bit  Access */
                           unsigned char B15:1;         /*    Bit 15    */
                           unsigned char B14:1;         /*    Bit 14    */
                           unsigned char B13:1;         /*    Bit 13    */
                           unsigned char    :1;         /*              */
                           unsigned char B11:1;         /*    Bit 11    */
                           unsigned char B10:1;         /*    Bit 10    */
                           unsigned char B9 :1;         /*    Bit  9    */
                           unsigned char B8 :1;         /*    Bit  8    */
                           unsigned char B7 :1;         /*    Bit  7    */
                           unsigned char B6 :1;         /*    Bit  6    */
                           unsigned char B5 :1;         /*    Bit  5    */
                           unsigned char B4 :1;         /*    Bit  4    */
                           unsigned char B3 :1;         /*    Bit  3    */
                           unsigned char B2 :1;         /*    Bit  2    */
                           unsigned char B1 :1;         /*    Bit  1    */
                           unsigned char B0 :1;         /*    Bit  0    */
                           }       BIT;                 /*              */
                    }           PBIR;                   /*              */
              char              wk3[2];                 /*              */
              union {                                   /* PCIOR        */
                    unsigned short WORD;                /*  Word Access */
                    struct {                            /*  Byte Access */
                           unsigned char H;             /*    High      */
                           unsigned char L;             /*    Low       */
                           }       BYTE;                /*              */
                    struct {                            /*  Bit  Access */
                           unsigned char   :8;          /*              */
                           unsigned char   :3;          /*              */
                           unsigned char B4:1;          /*    Bit 4     */
                           unsigned char B3:1;          /*    Bit 3     */
                           unsigned char B2:1;          /*    Bit 2     */
                           unsigned char B1:1;          /*    Bit 1     */
                           unsigned char B0:1;          /*    Bit 0     */
                           }       BIT;                 /*              */
                    }           PCIOR;                  /*              */
              union {                                   /* PCCR         */
                    unsigned short WORD;                /*  Word Access */
                    struct {                            /*  Byte Access */
                           unsigned char H;             /*    High      */
                           unsigned char L;             /*    Low       */
                           }       BYTE;                /*              */
                    struct {                            /*  Bit  Access */
                           unsigned char      :7;       /*              */
                           unsigned char PC4MD:1;       /*    PC4MD     */
                           unsigned char      :1;       /*              */
                           unsigned char PC3MD:1;       /*    PC3MD     */
                           unsigned char      :1;       /*              */
                           unsigned char PC2MD:1;       /*    PC2MD     */
                           unsigned char      :1;       /*              */
                           unsigned char PC1MD:1;       /*    PC1MD     */
                           unsigned char      :1;       /*              */
                           unsigned char PC0MD:1;       /*    PC0MD     */
                           }       BIT;                 /*              */
                    }           PCCR;                   /*              */
              char              wk4[2];                 /*              */
              union {                                   /* PDIOR        */
                    unsigned short WORD;                /*  Word Access */
                    struct {                            /*  Byte Access */
                           unsigned char H;             /*    High      */
                           unsigned char L;             /*    Low       */
                           }       BYTE;                /*              */
                    struct {                            /*  Bit  Access */
                           unsigned char    :2;         /*              */
                           unsigned char B13:1;         /*    Bit 13    */
                           unsigned char B12:1;         /*    Bit 12    */
                           unsigned char B11:1;         /*    Bit 11    */
                           unsigned char B10:1;         /*    Bit 10    */
                           unsigned char B9 :1;         /*    Bit  9    */
                           unsigned char B8 :1;         /*    Bit  8    */
                           unsigned char B7 :1;         /*    Bit  7    */
                           unsigned char B6 :1;         /*    Bit  6    */
                           unsigned char B5 :1;         /*    Bit  5    */
                           unsigned char B4 :1;         /*    Bit  4    */
                           unsigned char B3 :1;         /*    Bit  3    */
                           unsigned char B2 :1;         /*    Bit  2    */
                           unsigned char B1 :1;         /*    Bit  1    */
                           unsigned char B0 :1;         /*    Bit  0    */
                           }       BIT;                 /*              */
                    }           PDIOR;                  /*              */
              union {                                   /* PDCRH        */
                    unsigned short WORD;                /*  Word Access */
                    struct {                            /*  Byte Access */
                           unsigned char H;             /*    High      */
                           unsigned char L;             /*    Low       */
                           }       BYTE;                /*              */
                    struct {                            /*  Bit  Access */
                           unsigned char       :4;      /*              */
                           unsigned char PD13MD:2;      /*    PD13MD    */
                           unsigned char       :1;      /*              */
                           unsigned char PD12MD:1;      /*    PD12MD    */
                           unsigned char       :1;      /*              */
                           unsigned char PD11MD:1;      /*    PD11MD    */
                           unsigned char       :1;      /*              */
                           unsigned char PD10MD:1;      /*    PD10MD    */
                           unsigned char       :1;      /*              */
                           unsigned char PD9MD :1;      /*    PD9MD     */
                           unsigned char       :1;      /*              */
                           unsigned char PD8MD :1;      /*    PD8MD     */
                           }       BIT;                 /*              */
                    }           PDCRH;                  /*              */
              union {                                   /* PDCRL        */
                    unsigned short WORD;                /*  Word Access */
                    struct {                            /*  Byte Access */
                           unsigned char H;             /*    High      */
                           unsigned char L;             /*    Low       */
                           }       BYTE;                /*              */
                    struct {                            /*  Bit  Access */
                           unsigned char      :1;       /*              */
                           unsigned char PD7MD:1;       /*    PD7MD     */
                           unsigned char      :1;       /*              */
                           unsigned char PD6MD:1;       /*    PD6MD     */
                           unsigned char      :1;       /*              */
                           unsigned char PD5MD:1;       /*    PD5MD     */
                           unsigned char      :1;       /*              */
                           unsigned char PD4MD:1;       /*    PD4MD     */
                           unsigned char      :1;       /*              */
                           unsigned char PD3MD:1;       /*    PD3MD     */
                           unsigned char      :1;       /*              */
                           unsigned char PD2MD:1;       /*    PD2MD     */
                           unsigned char      :1;       /*              */
                           unsigned char PD1MD:1;       /*    PD1MD     */
                           unsigned char      :1;       /*              */
                           unsigned char PD0MD:1;       /*    PD0MD     */
                           }       BIT;                 /*              */
                    }           PDCRL;                  /*              */
              char              wk5[2];                 /*              */
              union {                                   /* PFIOR        */
                    unsigned short WORD;                /*  Word Access */
                    struct {                            /*  Byte Access */
                           unsigned char H;             /*    High      */
                           unsigned char L;             /*    Low       */
                           }       BYTE;                /*              */
                    struct {                            /*  Bit  Access */
                           unsigned char B15:1;         /*    Bit 15    */
                           unsigned char B14:1;         /*    Bit 14    */
                           unsigned char B13:1;         /*    Bit 13    */
                           unsigned char B12:1;         /*    Bit 12    */
                           unsigned char B11:1;         /*    Bit 11    */
                           unsigned char B10:1;         /*    Bit 10    */
                           unsigned char B9 :1;         /*    Bit  9    */
                           unsigned char B8 :1;         /*    Bit  8    */
                           unsigned char B7 :1;         /*    Bit  7    */
                           unsigned char B6 :1;         /*    Bit  6    */
                           unsigned char B5 :1;         /*    Bit  5    */
                           unsigned char B4 :1;         /*    Bit  4    */
                           unsigned char B3 :1;         /*    Bit  3    */
                           unsigned char B2 :1;         /*    Bit  2    */
                           unsigned char B1 :1;         /*    Bit  1    */
                           unsigned char B0 :1;         /*    Bit  0    */
                           }       BIT;                 /*              */
                    }           PFIOR;                  /*              */
              union {                                   /* PFCRH        */
                    unsigned short WORD;                /*  Word Access */
                    struct {                            /*  Byte Access */
                           unsigned char H;             /*    High      */
                           unsigned char L;             /*    Low       */
                           }       BYTE;                /*              */
                    struct {                            /*  Bit  Access */
                           unsigned char CKHIZ :1;      /*    CKHIZ     */
                           unsigned char PF15MD:1;      /*    PF15MD    */
                           unsigned char       :1;      /*              */
                           unsigned char PF14MD:1;      /*    PF14MD    */
                           unsigned char       :1;      /*              */
                           unsigned char PF13MD:1;      /*    PF13MD    */
                           unsigned char       :1;      /*              */
                           unsigned char PF12MD:1;      /*    PF12MD    */
                           unsigned char       :1;      /*              */
                           unsigned char PF11MD:1;      /*    PF11MD    */
                           unsigned char       :1;      /*              */
                           unsigned char PF10MD:1;      /*    PF10MD    */
                           unsigned char       :1;      /*              */
                           unsigned char PF9MD :1;      /*    PF9MD     */
                           unsigned char       :1;      /*              */
                           unsigned char PF8MD :1;      /*    PF8MD     */
                           }       BIT;                 /*              */
                    }           PFCRH;                  /*              */
              union {                                   /* PFCRL        */
                    unsigned short WORD;                /*  Word Access */
                    struct {                            /*  Byte Access */
                           unsigned char H;             /*    High      */
                           unsigned char L;             /*    Low       */
                           }       BYTE;                /*              */
                    struct {                            /*  Bit  Access */
                           unsigned char      :1;       /*              */
                           unsigned char PF7MD:1;       /*    PF7MD     */
                           unsigned char      :1;       /*              */
                           unsigned char PF6MD:1;       /*    PF6MD     */
                           unsigned char PF5MD:2;       /*    PF5MD     */
                           unsigned char      :1;       /*              */
                           unsigned char PF4MD:1;       /*    PF4MD     */
                           unsigned char      :1;       /*              */
                           unsigned char PF3MD:1;       /*    PF3MD     */
                           unsigned char      :1;       /*              */
                           unsigned char PF2MD:1;       /*    PF2MD     */
                           unsigned char      :1;       /*              */
                           unsigned char PF1MD:1;       /*    PF1MD     */
                           unsigned char      :1;       /*              */
                           unsigned char PF0MD:1;       /*    PF0MD     */
                           }       BIT;                 /*              */
                    }           PFCRL;                  /*              */
              char              wk6[2];                 /*              */
              union {                                   /* PEIOR        */
                    unsigned short WORD;                /*  Word Access */
                    struct {                            /*  Byte Access */
                           unsigned char H;             /*    High      */
                           unsigned char L;             /*    Low       */
                           }       BYTE;                /*              */
                    struct {                            /*  Bit  Access */
                           unsigned char B15:1;         /*    Bit 15    */
                           unsigned char B14:1;         /*    Bit 14    */
                           unsigned char B13:1;         /*    Bit 13    */
                           unsigned char B12:1;         /*    Bit 12    */
                           unsigned char B11:1;         /*    Bit 11    */
                           unsigned char B10:1;         /*    Bit 10    */
                           unsigned char B9 :1;         /*    Bit  9    */
                           unsigned char B8 :1;         /*    Bit  8    */
                           unsigned char B7 :1;         /*    Bit  7    */
                           unsigned char B6 :1;         /*    Bit  6    */
                           unsigned char B5 :1;         /*    Bit  5    */
                           unsigned char B4 :1;         /*    Bit  4    */
                           unsigned char B3 :1;         /*    Bit  3    */
                           unsigned char B2 :1;         /*    Bit  2    */
                           unsigned char B1 :1;         /*    Bit  1    */
                           unsigned char B0 :1;         /*    Bit  0    */
                           }       BIT;                 /*              */
                    }           PEIOR;                  /*              */
              union {                                   /* PECR         */
                    unsigned short WORD;                /*  Word Access */
                    struct {                            /*  Byte Access */
                           unsigned char H;             /*    High      */
                           unsigned char L;             /*    Low       */
                           }       BYTE;                /*              */
                    struct {                            /*  Bit  Access */
                           unsigned char PE15MD:1;      /*    PE15MD    */
                           unsigned char PE14MD:1;      /*    PE14MD    */
                           unsigned char PE13MD:1;      /*    PE13MD    */
                           unsigned char PE12MD:1;      /*    PE12MD    */
                           unsigned char PE11MD:1;      /*    PE11MD    */
                           unsigned char PE10MD:1;      /*    PE10MD    */
                           unsigned char PE9MD :1;      /*    PE9MD     */
                           unsigned char PE8MD :1;      /*    PE8MD     */
                           unsigned char PE7MD :1;      /*    PE7MD     */
                           unsigned char PE6MD :1;      /*    PE6MD     */
                           unsigned char PE5MD :1;      /*    PE5MD     */
                           unsigned char PE4MD :1;      /*    PE4MD     */
                           unsigned char PE3MD :1;      /*    PE3MD     */
                           unsigned char PE2MD :1;      /*    PE2MD     */
                           unsigned char PE1MD :1;      /*    PE1MD     */
                           unsigned char PE0MD :1;      /*    PE0MD     */
                           }       BIT;                 /*              */
                    }           PECR;                   /*              */
              char              wk7[2];                 /*              */
              union {                                   /* PLIOR        */
                    unsigned short WORD;                /*  Word Access */
                    struct {                            /*  Byte Access */
                           unsigned char H;             /*    High      */
                           unsigned char L;             /*    Low       */
                           }       BYTE;                /*              */
                    struct {                            /*  Bit  Access */
                           unsigned char    :2;         /*              */
                           unsigned char B13:1;         /*    Bit 13    */
                           unsigned char B12:1;         /*    Bit 12    */
                           unsigned char B11:1;         /*    Bit 11    */
                           unsigned char B10:1;         /*    Bit 10    */
                           unsigned char B9 :1;         /*    Bit  9    */
                           unsigned char B8 :1;         /*    Bit  8    */
                           unsigned char B7 :1;         /*    Bit  7    */
                           unsigned char B6 :1;         /*    Bit  6    */
                           unsigned char B5 :1;         /*    Bit  5    */
                           unsigned char B4 :1;         /*    Bit  4    */
                           unsigned char B3 :1;         /*    Bit  3    */
                           unsigned char B2 :1;         /*    Bit  2    */
                           unsigned char B1 :1;         /*    Bit  1    */
                           unsigned char B0 :1;         /*    Bit  0    */
                           }       BIT;                 /*              */
                    }           PLIOR;                  /*              */
              union {                                   /* PLCRH        */
                    unsigned short WORD;                /*  Word Access */
                    struct {                            /*  Byte Access */
                           unsigned char H;             /*    High      */
                           unsigned char L;             /*    Low       */
                           }       BYTE;                /*              */
                    struct {                            /*  Bit  Access */
                           unsigned char       :4;      /*              */
                           unsigned char PL13MD:2;      /*    PL13MD    */
                           unsigned char       :1;      /*              */
                           unsigned char PL12MD:1;      /*    PL12MD    */
                           unsigned char PL11MD:2;      /*    PL11MD    */
                           unsigned char PL10MD:2;      /*    PL10MD    */
                           unsigned char PL9MD :2;      /*    PL9MD     */
                           unsigned char       :1;      /*              */
                           unsigned char PL8MD :1;      /*    PL8MD     */
                           }       BIT;                 /*              */
                    }           PLCRH;                  /*              */
              union {                                   /* PLCRL        */
                    unsigned short WORD;                /*  Word Access */
                    struct {                            /*  Byte Access */
                           unsigned char H;             /*    High      */
                           unsigned char L;             /*    Low       */
                           }       BYTE;                /*              */
                    struct {                            /*  Bit  Access */
                           unsigned char      :1;       /*              */
                           unsigned char PL7MD:1;       /*    PL7MD     */
                           unsigned char      :1;       /*              */
                           unsigned char PL6MD:1;       /*    PL6MD     */
                           unsigned char      :1;       /*              */
                           unsigned char PL5MD:1;       /*    PL5MD     */
                           unsigned char      :1;       /*              */
                           unsigned char PL4MD:1;       /*    PL4MD     */
                           unsigned char      :1;       /*              */
                           unsigned char PL3MD:1;       /*    PL3MD     */
                           unsigned char PL2MD:2;       /*    PL2MD     */
                           unsigned char PL1MD:2;       /*    PL1MD     */
                           unsigned char      :1;       /*              */
                           unsigned char PL0MD:1;       /*    PL0MD     */
                           }       BIT;                 /*              */
                    }           PLCRL;                  /*              */
              union {                                   /* PLIR         */
                    unsigned short WORD;                /*  Word Access */
                    struct {                            /*  Byte Access */
                           unsigned char H;             /*    High      */
                           unsigned char L;             /*    Low       */
                           }       BYTE;                /*              */
                    struct {                            /*  Bit  Access */
                           unsigned char   :6;          /*              */
                           unsigned char B9:1;          /*    Bit 9     */
                           unsigned char B8:1;          /*    Bit 8     */
                           unsigned char B7:1;          /*    Bit 7     */
                           }       BIT;                 /*              */
                    }           PLIR;                   /*              */
              char              wk8[2];                 /*              */
              union {                                   /* PGIOR        */
                    unsigned short WORD;                /*  Word Access */
                    struct {                            /*  Byte Access */
                           unsigned char H;             /*    High      */
                           unsigned char L;             /*    Low       */
                           }       BYTE;                /*              */
                    struct {                            /*  Bit  Access */
                           unsigned char   :8;          /*              */
                           unsigned char   :4;          /*              */
                           unsigned char B3:1;          /*    Bit 3     */
                           unsigned char B2:1;          /*    Bit 2     */
                           unsigned char B1:1;          /*    Bit 1     */
                           unsigned char B0:1;          /*    Bit 0     */
                           }       BIT;                 /*              */
                    }           PGIOR;                  /*              */
              union {                                   /* PGCR         */
                    unsigned short WORD;                /*  Word Access */
                    struct {                            /*  Byte Access */
                           unsigned char H;             /*    High      */
                           unsigned char L;             /*    Low       */
                           }       BYTE;                /*              */
                    struct {                            /*  Bit  Access */
                           unsigned char      :8;       /*              */
                           unsigned char PG3MD:2;       /*    PG3MD     */
                           unsigned char PG2MD:2;       /*    PG2MD     */
                           unsigned char      :1;       /*              */
                           unsigned char PG1MD:1;       /*    PG1MD     */
                           unsigned char PG0MD:2;       /*    PG0MD     */
                           }       BIT;                 /*              */
                    }           PGCR;                   /*              */
              char              wk9[2];                 /*              */
              union {                                   /* PJIOR        */
                    unsigned short WORD;                /*  Word Access */
                    struct {                            /*  Byte Access */
                           unsigned char H;             /*    High      */
                           unsigned char L;             /*    Low       */
                           }       BYTE;                /*              */
                    struct {                            /*  Bit  Access */
                           unsigned char B15:1;         /*    Bit 15    */
                           unsigned char B14:1;         /*    Bit 14    */
                           unsigned char B13:1;         /*    Bit 13    */
                           unsigned char B12:1;         /*    Bit 12    */
                           unsigned char B11:1;         /*    Bit 11    */
                           unsigned char B10:1;         /*    Bit 10    */
                           unsigned char B9 :1;         /*    Bit  9    */
                           unsigned char B8 :1;         /*    Bit  8    */
                           unsigned char B7 :1;         /*    Bit  7    */
                           unsigned char B6 :1;         /*    Bit  6    */
                           unsigned char B5 :1;         /*    Bit  5    */
                           unsigned char B4 :1;         /*    Bit  4    */
                           unsigned char B3 :1;         /*    Bit  3    */
                           unsigned char B2 :1;         /*    Bit  2    */
                           unsigned char B1 :1;         /*    Bit  1    */
                           unsigned char B0 :1;         /*    Bit  0    */
                           }       BIT;                 /*              */
                    }           PJIOR;                  /*              */
              union {                                   /* PJCRH        */
                    unsigned short WORD;                /*  Word Access */
                    struct {                            /*  Byte Access */
                           unsigned char H;             /*    High      */
                           unsigned char L;             /*    Low       */
                           }       BYTE;                /*              */
                    struct {                            /*  Bit  Access */
                           unsigned char       :1;      /*              */
                           unsigned char PJ15MD:1;      /*    PJ15MD    */
                           unsigned char       :1;      /*              */
                           unsigned char PJ14MD:1;      /*    PJ14MD    */
                           unsigned char       :1;      /*              */
                           unsigned char PJ13MD:1;      /*    PJ13MD    */
                           unsigned char       :1;      /*              */
                           unsigned char PJ12MD:1;      /*    PJ12MD    */
                           unsigned char       :1;      /*              */
                           unsigned char PJ11MD:1;      /*    PJ11MD    */
                           unsigned char       :1;      /*              */
                           unsigned char PJ10MD:1;      /*    PJ10MD    */
                           unsigned char       :1;      /*              */
                           unsigned char PJ9MD :1;      /*    PJ9MD     */
                           unsigned char       :1;      /*              */
                           unsigned char PJ8MD :1;      /*    PJ8MD     */
                           }       BIT;                 /*              */
                    }           PJCRH;                  /*              */
              union {                                   /* PJCRL        */
                    unsigned short WORD;                /*  Word Access */
                    struct {                            /*  Byte Access */
                           unsigned char H;             /*    High      */
                           unsigned char L;             /*    Low       */
                           }       BYTE;                /*              */
                    struct {                            /*  Bit  Access */
                           unsigned char      :1;       /*              */
                           unsigned char PJ7MD:1;       /*    PJ7MD     */
                           unsigned char      :1;       /*              */
                           unsigned char PJ6MD:1;       /*    PJ6MD     */
                           unsigned char      :1;       /*              */
                           unsigned char PJ5MD:1;       /*    PJ5MD     */
                           unsigned char      :1;       /*              */
                           unsigned char PJ4MD:1;       /*    PJ4MD     */
                           unsigned char      :1;       /*              */
                           unsigned char PJ3MD:1;       /*    PJ3MD     */
                           unsigned char      :1;       /*              */
                           unsigned char PJ2MD:1;       /*    PJ2MD     */
                           unsigned char      :1;       /*              */
                           unsigned char PJ1MD:1;       /*    PJ1MD     */
                           unsigned char      :1;       /*              */
                           unsigned char PJ0MD:1;       /*    PJ0MD     */
                           }       BIT;                 /*              */
                    }           PJCRL;                  /*              */
              char              wk10[4];                /*              */
              union {                                   /* PKIOR        */
                    unsigned short WORD;                /*  Word Access */
                    struct {                            /*  Byte Access */
                           unsigned char H;             /*    High      */
                           unsigned char L;             /*    Low       */
                           }       BYTE;                /*              */
                    struct {                            /*  Bit  Access */
                           unsigned char B15:1;         /*    Bit 15    */
                           unsigned char B14:1;         /*    Bit 14    */
                           unsigned char B13:1;         /*    Bit 13    */
                           unsigned char B12:1;         /*    Bit 12    */
                           unsigned char B11:1;         /*    Bit 11    */
                           unsigned char B10:1;         /*    Bit 10    */
                           unsigned char B9 :1;         /*    Bit  9    */
                           unsigned char B8 :1;         /*    Bit  8    */
                           unsigned char B7 :1;         /*    Bit  7    */
                           unsigned char B6 :1;         /*    Bit  6    */
                           unsigned char B5 :1;         /*    Bit  5    */
                           unsigned char B4 :1;         /*    Bit  4    */
                           unsigned char B3 :1;         /*    Bit  3    */
                           unsigned char B2 :1;         /*    Bit  2    */
                           unsigned char B1 :1;         /*    Bit  1    */
                           unsigned char B0 :1;         /*    Bit  0    */
                           }       BIT;                 /*              */
                    }           PKIOR;                  /*              */
              union {                                   /* PKCRH        */
                    unsigned short WORD;                /*  Word Access */
                    struct {                            /*  Byte Access */
                           unsigned char H;             /*    High      */
                           unsigned char L;             /*    Low       */
                           }       BYTE;                /*              */
                    struct {                            /*  Bit  Access */
                           unsigned char       :1;      /*              */
                           unsigned char PK15MD:1;      /*    PK15MD    */
                           unsigned char       :1;      /*              */
                           unsigned char PK14MD:1;      /*    PK14MD    */
                           unsigned char       :1;      /*              */
                           unsigned char PK13MD:1;      /*    PK13MD    */
                           unsigned char       :1;      /*              */
                           unsigned char PK12MD:1;      /*    PK12MD    */
                           unsigned char       :1;      /*              */
                           unsigned char PK11MD:1;      /*    PK11MD    */
                           unsigned char       :1;      /*              */
                           unsigned char PK10MD:1;      /*    PK10MD    */
                           unsigned char       :1;      /*              */
                           unsigned char PK9MD :1;      /*    PK9MD     */
                           unsigned char       :1;      /*              */
                           unsigned char PK8MD :1;      /*    PK8MD     */
                           }       BIT;                 /*              */
                    }           PKCRH;                  /*              */
              union {                                   /* PKCRL        */
                    unsigned short WORD;                /*  Word Access */
                    struct {                            /*  Byte Access */
                           unsigned char H;             /*    High      */
                           unsigned char L;             /*    Low       */
                           }       BYTE;                /*              */
                    struct {                            /*  Bit  Access */
                           unsigned char      :1;       /*              */
                           unsigned char PK7MD:1;       /*    PK7MD     */
                           unsigned char      :1;       /*              */
                           unsigned char PK6MD:1;       /*    PK6MD     */
                           unsigned char      :1;       /*              */
                           unsigned char PK5MD:1;       /*    PK5MD     */
                           unsigned char      :1;       /*              */
                           unsigned char PK4MD:1;       /*    PK4MD     */
                           unsigned char      :1;       /*              */
                           unsigned char PK3MD:1;       /*    PK3MD     */
                           unsigned char      :1;       /*              */
                           unsigned char PK2MD:1;       /*    PK2MD     */
                           unsigned char      :1;       /*              */
                           unsigned char PK1MD:1;       /*    PK1MD     */
                           unsigned char      :1;       /*              */
                           unsigned char PK0MD:1;       /*    PK0MD     */
                           }       BIT;                 /*              */
                    }           PKCRL;                  /*              */
              union {                                   /* PKIR         */
                    unsigned short WORD;                /*  Word Access */
                    struct {                            /*  Byte Access */
                           unsigned char H;             /*    High      */
                           unsigned char L;             /*    Low       */
                           }       BYTE;                /*              */
                    struct {                            /*  Bit  Access */
                           unsigned char B15:1;         /*    Bit 15    */
                           unsigned char B14:1;         /*    Bit 14    */
                           unsigned char B13:1;         /*    Bit 13    */
                           unsigned char B12:1;         /*    Bit 12    */
                           unsigned char B11:1;         /*    Bit 11    */
                           unsigned char B10:1;         /*    Bit 10    */
                           unsigned char B9 :1;         /*    Bit  9    */
                           unsigned char B8 :1;         /*    Bit  8    */
                           unsigned char B7 :1;         /*    Bit  7    */
                           unsigned char B6 :1;         /*    Bit  6    */
                           unsigned char B5 :1;         /*    Bit  5    */
                           unsigned char B4 :1;         /*    Bit  4    */
                           unsigned char B3 :1;         /*    Bit  3    */
                           unsigned char B2 :1;         /*    Bit  2    */
                           unsigned char B1 :1;         /*    Bit  1    */
                           unsigned char B0 :1;         /*    Bit  0    */
                           }       BIT;                 /*              */
                    }           PKIR;                   /*              */
};                                                      /*              */
struct st_ad0 {                                         /* struct A/D0  */
              union {                                   /* ADTRGR0      */
                    unsigned char BYTE;                 /*  Byte Access */
                    struct {                            /*  Bit  Access */
                           unsigned char EXTRG:1;       /*    EXTRG     */
                           }      BIT;                  /*              */
                    }           ADTRGR;                 /*              */
              char              wk[145];                /*              */
              union {                                   /* ADDR0        */
                    unsigned short WORD;                /*  Word Access */
                    unsigned char  BYTE;                /*  Byte Access */
                    }           ADDR0;                  /*              */
              union {                                   /* ADDR1        */
                    unsigned short WORD;                /*  Word Access */
                    unsigned char  BYTE;                /*  Byte AWcess */
                    }           ADDR1;                  /*              */
              union {                                   /* ADDR2        */
                    unsigned short WORD;                /*  Word Access */
                    unsigned char  BYTE;                /*  Byte Access */
                    }           ADDR2;                  /*              */
              union {                                   /* ADDR3        */
                    unsigned short WORD;                /*  Word Access */
                    unsigned char  BYTE;                /*  Byte Access */
                    }           ADDR3;                  /*              */
              union {                                   /* ADDR4        */
                    unsigned short WORD;                /*  Word Access */
                    unsigned char  BYTE;                /*  Byte Access */
                    }           ADDR4;                  /*              */
              union {                                   /* ADDR5        */
                    unsigned short WORD;                /*  Word Access */
                    unsigned char  BYTE;                /*  Byte Access */
                    }           ADDR5;                  /*              */
              union {                                   /* ADDR6        */
                    unsigned short WORD;                /*  Word Access */
                    unsigned char  BYTE;                /*  Byte Access */
                    }           ADDR6;                  /*              */
              union {                                   /* ADDR7        */
                    unsigned short WORD;                /*  Word Access */
                    unsigned char  BYTE;                /*  Byte Access */
                    }           ADDR7;                  /*              */
              union {                                   /* ADDR8        */
                    unsigned short WORD;                /*  Word Access */
                    unsigned char  BYTE;                /*  Byte Access */
                    }           ADDR8;                  /*              */
              union {                                   /* ADDR9        */
                    unsigned short WORD;                /*  Word Access */
                    unsigned char  BYTE;                /*  Byte Access */
                    }           ADDR9;                  /*              */
              union {                                   /* ADDR10       */
                    unsigned short WORD;                /*  Word Access */
                    unsigned char  BYTE;                /*  Byte Access */
                    }           ADDR10;                 /*              */
              union {                                   /* ADDR11       */
                    unsigned short WORD;                /*  Word Access */
                    unsigned char  BYTE;                /*  Byte Access */
                    }           ADDR11;                 /*              */
              union {                                   /* ADCSR        */
                    unsigned char BYTE;                 /*  Byte Access */
                    struct {                            /*  Bit  Access */
                           unsigned char ADF :1;        /*    ADF       */
                           unsigned char ADIE:1;        /*    ADIE      */
                           unsigned char ADM :2;        /*    ADM       */
                           unsigned char CH  :4;        /*    CH        */
                           }      BIT;                  /*              */
                    }           ADCSR;                  /*              */
              union {                                   /* ADCR         */
                    unsigned char BYTE;                 /*  Byte Access */
                    struct {                            /*  Bit  Access */
                           unsigned char TRGE:1;        /*    TRGE      */
                           unsigned char CKS :1;        /*    CKS       */
                           unsigned char ADST:1;        /*    ADST      */
                           unsigned char ADCS:1;        /*    ADCS      */
                           }      BIT;                  /*              */
                    }           ADCR;                   /*              */
};                                                      /*              */
struct st_ad1 {                                         /* struct A/D1  */
              union {                                   /* ADTRGR1      */
                    unsigned char BYTE;                 /*  Byte Access */
                    struct {                            /*  Bit  Access */
                           unsigned char EXTRG:1;       /*    EXTRG     */
                           }      BIT;                  /*              */
                    }           ADTRGR;                 /*              */
              char              wk[241];                /*              */
              union {                                   /* ADDR12       */
                    unsigned short WORD;                /*  Word Access */
                    unsigned char  BYTE;                /*  Byte Access */
                    }           ADDR12;                 /*              */
              union {                                   /* ADDR13       */
                    unsigned short WORD;                /*  Word Access */
                    unsigned char  BYTE;                /*  Byte Access */
                    }           ADDR13;                 /*              */
              union {                                   /* ADDR14       */
                    unsigned short WORD;                /*  Word Access */
                    unsigned char  BYTE;                /*  Byte Access */
                    }           ADDR14;                 /*              */
              union {                                   /* ADDR15       */
                    unsigned short WORD;                /*  Word Access */
                    unsigned char  BYTE;                /*  Byte Access */
                    }           ADDR15;                 /*              */
              union {                                   /* ADDR16       */
                    unsigned short WORD;                /*  Word Access */
                    unsigned char  BYTE;                /*  Byte Access */
                    }           ADDR16;                 /*              */
              union {                                   /* ADDR17       */
                    unsigned short WORD;                /*  Word Access */
                    unsigned char  BYTE;                /*  Byte Access */
                    }           ADDR17;                 /*              */
              union {                                   /* ADDR18       */
                    unsigned short WORD;                /*  Word Access */
                    unsigned char  BYTE;                /*  Byte Access */
                    }           ADDR18;                 /*              */
              union {                                   /* ADDR19       */
                    unsigned short WORD;                /*  Word Access */
                    unsigned char  BYTE;                /*  Byte Access */
                    }           ADDR19;                 /*              */
              union {                                   /* ADDR20       */
                    unsigned short WORD;                /*  Word Access */
                    unsigned char  BYTE;                /*  Byte Access */
                    }           ADDR20;                 /*              */
              union {                                   /* ADDR21       */
                    unsigned short WORD;                /*  Word Access */
                    unsigned char  BYTE;                /*  Byte Access */
                    }           ADDR21;                 /*              */
              union {                                   /* ADDR22       */
                    unsigned short WORD;                /*  Word Access */
                    unsigned char  BYTE;                /*  Byte Access */
                    }           ADDR22;                 /*              */
              union {                                   /* ADDR23       */
                    unsigned short WORD;                /*  Word Access */
                    unsigned char  BYTE;                /*  Byte Access */
                    }           ADDR23;                 /*              */
              union {                                   /* ADCSR1       */
                    unsigned char BYTE;                 /*  Byte Access */
                    struct {                            /*  Bit  Access */
                           unsigned char ADF :1;        /*    ADF       */
                           unsigned char ADIE:1;        /*    ADIE      */
                           unsigned char ADM :2;        /*    ADM       */
                           unsigned char CH  :4;        /*    CH        */
                           }      BIT;                  /*              */
                    }           ADCSR;                  /*              */
              union {                                   /* ADCR1        */
                    unsigned char BYTE;                 /*  Byte Access */
                    struct {                            /*  Bit  Access */
                           unsigned char TRGE:1;        /*    TRGE      */
                           unsigned char CKS :1;        /*    CKS       */
                           unsigned char ADST:1;        /*    ADST      */
                           unsigned char ADCS:1;        /*    ADCS      */
                           }      BIT;                  /*              */
                    }           ADCR;                   /*              */
};                                                      /*              */
struct st_ad2 {                                         /* struct A/D2  */
              char              wk1;                    /*              */
              union {                                   /* ADTRGR2      */
                    unsigned char BYTE;                 /*  Byte Access */
                    struct {                            /*  Bit  Access */
                           unsigned char EXTRG:1;       /*    EXTRG     */
                           }      BIT;                  /*              */
                    }           ADTRGR;                 /*              */
              char              wk2[272];               /*              */
              union {                                   /* ADDR24       */
                    unsigned short WORD;                /*  Word Access */
                    unsigned char  BYTE;                /*  Byte Access */
                    }           ADDR24;                 /*              */
              union {                                   /* ADDR25       */
                    unsigned short WORD;                /*  Word Access */
                    unsigned char  BYTE;                /*  Byte Access */
                    }           ADDR25;                 /*              */
              union {                                   /* ADDR26       */
                    unsigned short WORD;                /*  Word Access */
                    unsigned char  BYTE;                /*  Byte Access */
                    }           ADDR26;                 /*              */
              union {                                   /* ADDR27       */
                    unsigned short WORD;                /*  Word Access */
                    unsigned char  BYTE;                /*  Byte Access */
                    }           ADDR27;                 /*              */
              union {                                   /* ADDR28       */
                    unsigned short WORD;                /*  Word Access */
                    unsigned char  BYTE;                /*  Byte Access */
                    }           ADDR28;                 /*              */
              union {                                   /* ADDR29       */
                    unsigned short WORD;                /*  Word Access */
                    unsigned char  BYTE;                /*  Byte Access */
                    }           ADDR29;                 /*              */
              union {                                   /* ADDR30       */
                    unsigned short WORD;                /*  Word Access */
                    unsigned char  BYTE;                /*  Byte Access */
                    }           ADDR30;                 /*              */
              union {                                   /* ADDR31       */
                    unsigned short WORD;                /*  Word Access */
                    unsigned char  BYTE;                /*  Byte Access */
                    }           ADDR31;                 /*              */
              char              wk3[8];                 /*              */
              union {                                   /* ADCSR2       */
                    unsigned char BYTE;                 /*  Byte Access */
                    struct {                            /*  Bit  Access */
                           unsigned char ADF :1;        /*    ADF       */
                           unsigned char ADIE:1;        /*    ADIE      */
                           unsigned char ADM :2;        /*    ADM       */
                           unsigned char     :1;        /*              */
                           unsigned char CH  :3;        /*    CH        */
                           }      BIT;                  /*              */
                    }           ADCSR;                  /*              */
              union {                                   /* ADCR2        */
                    unsigned char BYTE;                 /*  Byte Access */
                    struct {                            /*  Bit  Access */
                           unsigned char TRGE:1;        /*    TRGE      */
                           unsigned char CKS :1;        /*    CKS       */
                           unsigned char ADST:1;        /*    ADST      */
                           unsigned char ADCS:1;        /*    ADCS      */
                           }      BIT;                  /*              */
                    }           ADCR;                   /*              */
};                                                      /*              */
struct st_hudi {                                        /* struct H-UDI */
               union {                                  /* SDIR         */
                     unsigned short WORD;               /*  Word Access */
                     struct {                           /*  Bit Access  */
                            unsigned char TS:4;         /*    TS        */
                            }       BIT;                /*              */
                     }          SDIR;                   /*              */
               union {                                  /* SDSR         */
                     unsigned short WORD;               /*  Word Access */
                     struct {                           /*  Bit Access  */
                            unsigned char      :8;      /*              */
                            unsigned char      :7;      /*              */
                            unsigned char SDTRF:1;      /*    SDTRF     */
                            }       BIT;                /*              */
                      }         SDSR;                   /*              */
               unsigned int     SDDR;                   /* SDDR         */
};                                                      /*              */
#define HCAN0 (*(volatile struct st_hcan  *)0xFFFFE400) /* HCAN0 Address*/
#define HCAN1 (*(volatile struct st_hcan  *)0xFFFFE600) /* HCAN1 Address*/
#define FLASH (*(volatile struct st_flash *)0xFFFFE800) /* FLASH Address*/
#define UBC   (*(volatile struct st_ubc   *)0xFFFFEC00) /* UBC   Address*/
#define WDT   (*(volatile union  un_wdt   *)0xFFFFEC10) /* WDT   Address*/
#define SBYCR (*(volatile union  un_sbycr *)0xFFFFEC14) /* SBYCR Address*/
#define BSC   (*(volatile struct st_bsc   *)0xFFFFEC20) /* BSC   Address*/
#define DMAC  (*(volatile struct st_dmac  *)0xFFFFECB0) /* DMAC  Address*/
#define DMAC0 (*(volatile struct st_dmac0 *)0xFFFFECC0) /* DMAC0 Address*/
#define DMAC1 (*(volatile struct st_dmac0 *)0xFFFFECD0) /* DMAC1 Address*/
#define DMAC2 (*(volatile struct st_dmac2 *)0xFFFFECE0) /* DMAC2 Address*/
#define DMAC3 (*(volatile struct st_dmac3 *)0xFFFFECF0) /* DMAC3 Address*/
#define INTC  (*(volatile struct st_intc  *)0xFFFFED00) /* INTC  Address*/
#define SCI0  (*(volatile struct st_sci   *)0xFFFFF000) /* SCI0  Address*/
#define SCI1  (*(volatile struct st_sci   *)0xFFFFF008) /* SCI1  Address*/
#define SCI2  (*(volatile struct st_sci   *)0xFFFFF010) /* SCI2  Address*/
#define SCI3  (*(volatile struct st_sci   *)0xFFFFF018) /* SCI3  Address*/
#define SCI4  (*(volatile struct st_sci   *)0xFFFFF020) /* SCI4  Address*/
#define ATU   (*(volatile struct st_atu   *)0xFFFFF400) /* ATU   Address*/
#define ATU0  (*(volatile struct st_atu0  *)0xFFFFF420) /* ATU0  Address*/
#define ATU1  (*(volatile struct st_atu1  *)0xFFFFF440) /* ATU1  Address*/
#define ATU2  (*(volatile struct st_atu2  *)0xFFFFF600) /* ATU2  Address*/
#define ATU3  (*(volatile struct st_atu3  *)0xFFFFF480) /* ATU3  Address*/
#define ATU4  (*(volatile struct st_atu4  *)0xFFFFF480) /* ATU4  Address*/
#define ATU5  (*(volatile struct st_atu5  *)0xFFFFF480) /* ATU5  Address*/
#define ATU6  (*(volatile struct st_atu6  *)0xFFFFF500) /* ATU6  Address*/
#define ATU7  (*(volatile struct st_atu7  *)0xFFFFF580) /* ATU7  Address*/
#define ATU8  (*(volatile struct st_atu8  *)0xFFFFF640) /* ATU8  Address*/
#define ATU9  (*(volatile struct st_atu9  *)0xFFFFF680) /* ATU9  Address*/
#define ATU10 (*(volatile struct st_atu10 *)0xFFFFF6C0) /* ATU10 Address*/
#define ATU11 (*(volatile struct st_atu11 *)0xFFFFF5C0) /* ATU11 Address*/
#define APC   (*(volatile struct st_apc   *)0xFFFFF700) /* APC   Address*/
#define SYSCR (*(volatile union  un_syscr *)0xFFFFF708) /* SYSCR Address*/
#define MSTCR (*(volatile union  un_mstcr *)0xFFFFF70A) /* MSTCR Address*/
#define CMT   (*(volatile struct st_cmt   *)0xFFFFF710) /* CMT   Address*/
#define CMT0  (*(volatile struct st_cmt0  *)0xFFFFF712) /* CMT0  Address*/
#define CMT1  (*(volatile struct st_cmt0  *)0xFFFFF718) /* CMT1  Address*/
#define PA    (*(volatile struct st_pa    *)0xFFFFF726) /* PA    Address*/
#define PB    (*(volatile struct st_pb    *)0xFFFFF738) /* PB    Address*/
#define PC    (*(volatile struct st_pc    *)0xFFFFF73E) /* PC    Address*/
#define PD    (*(volatile struct st_pd    *)0xFFFFF746) /* PD    Address*/
#define PE    (*(volatile struct st_pe    *)0xFFFFF754) /* PE    Address*/
#define PF    (*(volatile struct st_pf    *)0xFFFFF74E) /* PF    Address*/
#define PG    (*(volatile struct st_pg    *)0xFFFFF764) /* PG    Address*/
#define PH    (*(volatile struct st_ph    *)0xFFFFF72C) /* PH    Address*/
#define PJ    (*(volatile struct st_pj    *)0xFFFFF76C) /* PJ    Address*/
#define PK    (*(volatile struct st_pk    *)0xFFFFF778) /* PK    Address*/
#define PL    (*(volatile struct st_pl    *)0xFFFFF75E) /* PL    Address*/
#define PFC   (*(volatile struct st_pfc   *)0xFFFFF720) /* PFC   Address*/
#define AD0   (*(volatile struct st_ad0   *)0xFFFFF76E) /* A/D0  Address*/
#define AD1   (*(volatile struct st_ad1   *)0xFFFFF72E) /* A/D1  Address*/
#define AD2   (*(volatile struct st_ad2   *)0xFFFFF72E) /* A/D2  Address*/
#define HUDI  (*(volatile struct st_hudi  *)0xFFFFF7C0) /* H-UDI Address*/
