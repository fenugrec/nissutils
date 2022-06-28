/************************************************************************/
/*      SH7050 Series Include File                          Ver 2.0     */
/************************************************************************/
struct st_flash {                                       /* struct FLASH */
                union {                                 /* FLMCR1       */
                      unsigned char BYTE;               /*  Byte Access */
                      struct {                          /*  Bit  Access */
                             unsigned char FWE:1;       /*    FWE       */
                             unsigned char VPP:1;       /*    VPP       */
                             unsigned char ESU:1;       /*    ESU       */
                             unsigned char PSU:1;       /*    PSU       */
                             unsigned char EV :1;       /*    EV        */
                             unsigned char PV :1;       /*    PV        */
                             unsigned char E  :1;       /*    E         */
                             unsigned char P  :1;       /*    P         */
                             }      BIT;                /*              */
                      }         FLMCR1;                 /*              */
                union {                                 /* FLMCR2       */
                      unsigned char BYTE;               /*  Byte Access */
                      struct {                          /*  Bit  Access */
                             unsigned char FLER:1;      /*    FLER      */
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
                char            wk[166];                /*              */
                union {                                 /* RAMER        */
                      unsigned char BYTE;               /*  Byte Access */
                      struct {                          /*  Bit  Access */
                             unsigned char     :5;      /*              */
                             unsigned char RAMS:1;      /*    RAMS      */
                             unsigned char RAM :2;      /*    RAM       */
                             }      BIT;                /*              */
                      }         RAMER;                  /*              */
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
};                                                      /*              */
struct st_atu {                                         /* struct ATU   */
              char              wk;                     /*              */
              union {                                   /* PSCR1        */
                    unsigned char BYTE;                 /*  Byte Access */
                    struct {                            /*  Bit  Access */
                           unsigned char     :3;        /*              */
                           unsigned char PSCE:1;        /*              */
                           unsigned char PSCD:1;        /*              */
                           unsigned char PSCC:1;        /*              */
                           unsigned char PSCB:1;        /*              */
                           unsigned char PSCA:1;        /*              */
                           }     BIT;                   /*              */
                    }           PSCR1;                  /*              */
              union {                                   /* TSTR         */
                    unsigned short WORD;                /*  Word Access */
                    struct {                            /*  Bit  Access */
                           unsigned short     :6;       /*              */
                           unsigned short STR9:1;       /*    STR9      */
                           unsigned short STR8:1;       /*    STR8      */
                           unsigned short STR7:1;       /*    STR7      */
                           unsigned short STR6:1;       /*    STR6      */
                           unsigned short STR5:1;       /*    STR5      */
                           unsigned short STR4:1;       /*    STR4      */
                           unsigned short STR3:1;       /*    STR3      */
                           unsigned short STR2:1;       /*    STR2      */
                           unsigned short STR1:1;       /*    STR1      */
                           unsigned short STR0:1;       /*    STR0      */
                           }      BIT;                  /*              */
                    }           TSTR;                   /*              */
};                                                      /*              */
struct st_atu0 {                                        /* struct ATU0  */
               union {                                  /* TGSR         */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char     :5;       /*              */
                            unsigned char TRGD:1;       /*    TRG0D     */
                            unsigned char     :1;       /*              */
                            unsigned char TRGA:1;       /*    TRG0A     */
                            }      BIT;                 /*              */
                     }          TGSR;                   /*              */
               union {                                  /* TIOR0A       */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char IOD:2;        /*    IO0D      */
                            unsigned char IOC:2;        /*    IO0C      */
                            unsigned char IOB:2;        /*    IO0B      */
                            unsigned char IOA:2;        /*    IO0A      */
                            }      BIT;                 /*              */
                     }          TIORA;                  /*              */
               union {                                  /* ITVRR        */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char ITVAD:4;      /*    ITVAD     */
                            unsigned char ITVE :4;      /*    ITVE      */
                            }      BIT;                 /*              */
                     }          ITVRR;                  /*              */
               union {                                  /* TSRAH        */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char    :4;        /*              */
                            unsigned char IIF:4;        /*    IIF       */
                            }      BIT;                 /*              */
                     }          TSRAH;                  /*              */
               union {                                  /* TIERA        */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char     :3;       /*              */
                            unsigned char OVE :1;       /*    OVE0      */
                            unsigned char ICED:1;       /*    ICE0D     */
                            unsigned char ICEC:1;       /*    ICE0C     */
                            unsigned char ICEB:1;       /*    ICE0B     */
                            unsigned char ICEA:1;       /*    ICE0A     */
                            }      BIT;                 /*              */
                     }          TIERA;                  /*              */
               union {                                  /* TSRAL        */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char     :3;       /*              */
                            unsigned char OVF :1;       /*    OVF0      */
                            unsigned char ICFD:1;       /*    ICF0D     */
                            unsigned char ICFC:1;       /*    ICF0C     */
                            unsigned char ICFB:1;       /*    ICF0B     */
                            unsigned char ICFA:1;       /*    ICF0A     */
                            }      BIT;                 /*              */
                     }          TSRAL;                  /*              */
               unsigned int     TCNT;                   /* TCNT0        */
               unsigned int     ICRA;                   /* ICR0A        */
               unsigned int     ICRB;                   /* ICR0B        */
               unsigned int     ICRC;                   /* ICR0C        */
               unsigned int     ICRD;                   /* ICR0D        */
};                                                      /*              */
struct st_atu1 {                                        /* struct ATU1  */
               union {                                  /* TCR1         */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char      :2;      /*              */
                            unsigned char CKEG :2;      /*    CKEG      */
                            unsigned char      :1;      /*              */
                            unsigned char CKSEL:3;      /*    CKSEL     */
                            }      BIT;                 /*              */
                     }          TCR;                    /*              */
               union {                                  /* TIOR1A       */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char    :1;        /*              */
                            unsigned char IOB:3;        /*    IO1B      */
                            unsigned char    :1;        /*              */
                            unsigned char IOA:3;        /*    IO1A      */
                            }      BIT;                 /*              */
                     }          TIORA;                  /*              */
               union {                                  /* TIOR1B       */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char    :1;        /*              */
                            unsigned char IOD:3;        /*    IO1D      */
                            unsigned char    :1;        /*              */
                            unsigned char IOC:3;        /*    IO1C      */
                            }      BIT;                 /*              */
                     }          TIORB;                  /*              */
               union {                                  /* TIOR1C       */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char    :1;        /*              */
                            unsigned char IOF:3;        /*    IO1F      */
                            unsigned char    :1;        /*              */
                            unsigned char IOE:3;        /*    IO1E      */
                            }      BIT;                 /*              */
                     }          TIORC;                  /*              */
               union {                                  /* TIERB        */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char     :1;       /*              */
                            unsigned char OVE :1;       /*    OVE1      */
                            unsigned char IMEF:1;       /*    IME1F     */
                            unsigned char IMEE:1;       /*    IME1E     */
                            unsigned char IMED:1;       /*    IME1D     */
                            unsigned char IMEC:1;       /*    IME1C     */
                            unsigned char IMEB:1;       /*    IME1B     */
                            unsigned char IMEA:1;       /*    IME1A     */
                            }      BIT;                 /*              */
                     }          TIERB;                  /*              */
               union {                                  /* TSRB         */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char     :1;       /*              */
                            unsigned char OVF :1;       /*    OVF1      */
                            unsigned char IMFF:1;       /*    IMF1F     */
                            unsigned char IMFE:1;       /*    IMF1E     */
                            unsigned char IMFD:1;       /*    IMF1D     */
                            unsigned char IMFC:1;       /*    IMF1C     */
                            unsigned char IMFB:1;       /*    IMF1B     */
                            unsigned char IMFA:1;       /*    IMF1A     */
                            }      BIT;                 /*              */
                     }          TSRB;                   /*              */
               char             wk[10];                 /*              */
               unsigned short   TCNT;                   /* TCNT1        */
               unsigned short   GRA;                    /* GR1A         */
               unsigned short   GRB;                    /* GR1B         */
               unsigned short   GRC;                    /* GR1C         */
               unsigned short   GRD;                    /* GR1D         */
               unsigned short   GRE;                    /* GR1E         */
               unsigned short   GRF;                    /* GR1F         */
               unsigned short   OSBR;                   /* OSBR         */
};                                                      /*              */
struct st_atu2 {                                        /* struct ATU2  */
               union {                                  /* TCR2         */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char      :2;      /*              */
                            unsigned char CKEG :2;      /*    CKEG      */
                            unsigned char      :1;      /*              */
                            unsigned char CKSEL:3;      /*    CKSEL     */
                            }      BIT;                 /*              */
                     }          TCR;                    /*              */
               union {                                  /* TIOR2A       */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char    :1;        /*              */
                            unsigned char IOB:3;        /*    IO2B      */
                            unsigned char    :1;        /*              */
                            unsigned char IOA:3;        /*    IO2A      */
                            }      BIT;                 /*              */
                     }          TIORA;                  /*              */
               union {                                  /* TIERC        */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char     :5;       /*              */
                            unsigned char OVE :1;       /*    OVE2      */
                            unsigned char IMEB:1;       /*    IME2B     */
                            unsigned char IMEA:1;       /*    IME2A     */
                            }      BIT;                 /*              */
                     }          TIERC;                  /*              */
               union {                                  /* TSRC         */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char     :5;       /*              */
                            unsigned char OVF :1;       /*    OVF2      */
                            unsigned char IMFB:1;       /*    IMF2B     */
                            unsigned char IMFA:1;       /*    IMF2A     */
                            }      BIT;                 /*              */
                     }          TSRC;                   /*              */
               unsigned short   TCNT;                   /* TCNT2        */
               unsigned short   GRA;                    /* GR2A         */
               unsigned short   GRB;                    /* GR2B         */
};                                                      /*              */
struct st_atu3 {                                        /* struct ATU3  */
               union {                                  /* TMDR         */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char    :7;        /*              */
                            unsigned char PWM:1;        /*    T3PWM     */
                            }      BIT;                 /*              */
                     }          TMDR;                   /*              */
               char             wk1;                    /*              */
               union {                                  /* TIERDH       */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char     :3;       /*              */
                            unsigned char OVE :1;       /*    OVE3      */
                            unsigned char IMED:1;       /*    IME3D     */
                            unsigned char IMEC:1;       /*    IME3C     */
                            unsigned char IMEB:1;       /*    IME3B     */
                            unsigned char IMEA:1;       /*    IME3A     */
                            }      BIT;                 /*              */
                     }          TIERDH;                 /*              */
               union {                                  /* TSRDH        */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char     :3;       /*              */
                            unsigned char OVF :1;       /*    OVF3      */
                            unsigned char IMFD:1;       /*    IMF3D     */
                            unsigned char IMFC:1;       /*    IMF3C     */
                            unsigned char IMFB:1;       /*    IMF3B     */
                            unsigned char IMFA:1;       /*    IMF3A     */
                            }      BIT;                 /*              */
                     }          TSRDH;                  /*              */
               char             wk2[2];                 /*              */
               union {                                  /* TCR3         */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char      :2;      /*              */
                            unsigned char CKEG :2;      /*    CKEG      */
                            unsigned char      :1;      /*              */
                            unsigned char CKSEL:3;      /*    CKSEL     */
                            }      BIT;                 /*              */
                     }          TCR;                    /*              */
               char             wk3;                    /*              */
               union {                                  /* TIOR3A       */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char CCIB:1;       /*    CCI3B     */
                            unsigned char IOB :3;       /*    IO3B      */
                            unsigned char CCIA:1;       /*    CCI3A     */
                            unsigned char IOA :3;       /*    IO3A      */
                            }      BIT;                 /*              */
                     }          TIORA;                  /*              */
               union {                                  /* TIOR3B       */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char CCID:1;       /*    CCI3D     */
                            unsigned char IOD :3;       /*    IO3D      */
                            unsigned char CCIC:1;       /*    CCI3C     */
                            unsigned char IOC :3;       /*    IO3C      */
                            }      BIT;                 /*              */
                     }          TIORB;                  /*              */
               char             wk4[4];                 /*              */
               unsigned short   TCNT;                   /* TCNT3        */
               unsigned short   GRA;                    /* GR3A         */
               unsigned short   GRB;                    /* GR3B         */
               unsigned short   GRC;                    /* GR3C         */
               unsigned short   GRD;                    /* GR3D         */
};                                                      /*              */
struct st_atu4 {                                        /* struct ATU4  */
               union {                                  /* TMDR         */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char    :6;        /*              */
                            unsigned char PWM:1;        /*    T4PWM     */
                            }      BIT;                 /*              */
                     }          TMDR;                   /*              */
               char             wk1[3];                 /*              */
               union {                                  /* TIERDL       */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char OVE :1;       /*    OVE4      */
                            unsigned char IMED:1;       /*    IME4D     */
                            unsigned char IMEC:1;       /*    IME4C     */
                            unsigned char IMEB:1;       /*    IME4B     */
                            unsigned char IMEA:1;       /*    IME4A     */
                            }      BIT;                 /*              */
                     }          TIERDL;                 /*              */
               union {                                  /* TSRDL        */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char OVF :1;       /*    OVF4      */
                            unsigned char IMFD:1;       /*    IMF4D     */
                            unsigned char IMFC:1;       /*    IMF4C     */
                            unsigned char IMFB:1;       /*    IMF4B     */
                            unsigned char IMFA:1;       /*    IMF4A     */
                            }      BIT;                 /*              */
                     }          TSRDL;                  /*              */
               char             wk2;                    /*              */
               union {                                  /* TCR4         */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char      :2;      /*              */
                            unsigned char CKEG :2;      /*    CKEG      */
                            unsigned char      :1;      /*              */
                            unsigned char CKSEL:3;      /*    CKSEL     */
                            }      BIT;                 /*              */
                     }          TCR;                    /*              */
               char             wk3[2];                 /*              */
               union {                                  /* TIOR4A       */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char CCIB:1;       /*    CCI4A     */
                            unsigned char IOB :3;       /*    IO4B      */
                            unsigned char CCIA:1;       /*    CCI4A     */
                            unsigned char IOA :3;       /*    IO4A      */
                            }      BIT;                 /*              */
                     }          TIORA;                  /*              */
               union {                                  /* TIOR4B       */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char CCID:1;       /*    CCI4D     */
                            unsigned char IOD :3;       /*    IO4D      */
                            unsigned char CCIC:1;       /*    CCI4C     */
                            unsigned char IOC :3;       /*    IO4C      */
                            }      BIT;                 /*              */
                     }          TIORB;                  /*              */
               char             wk4[12];                /*              */
               unsigned short   TCNT;                   /* TCNT4        */
               unsigned short   GRA;                    /* GR4A         */
               unsigned short   GRB;                    /* GR4B         */
               unsigned short   GRC;                    /* GR4C         */
               unsigned short   GRD;                    /* GR4D         */
};                                                      /*              */
struct st_atu5 {                                        /* struct ATU5  */
               union {                                  /* TMDR         */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char    :5;        /*              */
                            unsigned char PWM:1;        /*    T5PWM     */
                            }      BIT;                 /*              */
                     }          TMDR;                   /*              */
               char             wk1[3];                 /*              */
               union {                                  /* TIERDL       */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char     :5;       /*              */
                            unsigned char OVE :1;       /*    OVE5      */
                            unsigned char IMEB:1;       /*    IME5B     */
                            unsigned char IMEA:1;       /*    IME5A     */
                            }      BIT;                 /*              */
                     }          TIERDL;                 /*              */
               union {                                  /* TSRDL        */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char     :5;       /*              */
                            unsigned char OVF :1;       /*    OVF5      */
                            unsigned char IMFB:1;       /*    IMF5B     */
                            unsigned char IMFA:1;       /*    IMF5A     */
                            }      BIT;                 /*              */
                     }          TSRDL;                  /*              */
               char             wk2[6];                 /*              */
               union {                                  /* TCR5         */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char      :2;      /*              */
                            unsigned char CKEG :2;      /*    CKEG      */
                            unsigned char      :1;      /*              */
                            unsigned char CKSEL:3;      /*    CKSEL     */
                            }      BIT;                 /*              */
                     }          TCR;                    /*              */
               union {                                  /* TIOR5A       */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char CCIB:1;       /*    CCI5B     */
                            unsigned char IOB :3;       /*    IO5B      */
                            unsigned char CCIA:1;       /*    CCI5A     */
                            unsigned char IOA :3;       /*    IO5A      */
                            }      BIT;                 /*              */
                     }          TIORA;                  /*              */
               char             wk3[20];                /*              */
               unsigned short   TCNT;                   /* TCNT5        */
               unsigned short   GRA;                    /* GR5A         */
               unsigned short   GRB;                    /* GR5B         */
};                                                      /*              */
struct st_atu6 {                                        /* struct ATU6  */
               union {                                  /* TIERE        */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char    :1;        /*              */
                            unsigned char CME:1;        /*    CME6      */
                            }      BIT;                 /*              */
                     }          TIERE;                  /*              */
               union {                                  /* TSRE         */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char    :1;        /*              */
                            unsigned char CMF:1;        /*    CMF6      */
                            }      BIT;                 /*              */
                     }          TSRE;                   /*              */
               char             wk1;                    /*              */
               union {                                  /* TCR6         */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char      :5;      /*              */
                            unsigned char CKSEL:3;      /*    CKSEL     */
                            }      BIT;                 /*              */
                     }          TCR;                    /*              */
               char             wk2[2];                 /*              */
               unsigned short   TCNT;                   /* TCNT6        */
               unsigned short   CYLR;                   /* CYLR6        */
               unsigned short   BFR;                    /* BFR6         */
               unsigned short   DTR;                    /* DTR6         */
};                                                      /*              */
struct st_atu7 {                                        /* struct ATU7  */
               union {                                  /* TIERE        */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char    :3;        /*              */
                            unsigned char CME:1;        /*    CME7      */
                            }      BIT;                 /*              */
                     }          TIERE;                  /*              */
               union {                                  /* TSRE         */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char    :3;        /*              */
                            unsigned char CMF:1;        /*    CMF7      */
                            }      BIT;                 /*              */
                     }          TSRE;                   /*              */
               union {                                  /* TCR7         */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char      :5;      /*              */
                            unsigned char CKSEL:3;      /*    CKSEL     */
                            }      BIT;                 /*              */
                     }          TCR;                    /*              */
               char             wk[11];                 /*              */
               unsigned short   TCNT;                   /* TCNT7        */
               unsigned short   CYLR;                   /* CYLR7        */
               unsigned short   BFR;                    /* BFR7         */
               unsigned short   DTR;                    /* DTR7         */
};                                                      /*              */
struct st_atu8 {                                        /* struct ATU8  */
               union {                                  /* TIERE        */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char    :5;        /*              */
                            unsigned char CME:1;        /*    CME8      */
                            }      BIT;                 /*              */
                     }          TIERE;                  /*              */
               union {                                  /* TSRE         */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char    :5;        /*              */
                            unsigned char CMF:1;        /*    CMF8      */
                            }      BIT;                 /*              */
                     }          TSRE;                   /*              */
               char             wk1[3];                 /*              */
               union {                                  /* TCR8         */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char      :5;      /*              */
                            unsigned char CKSEL:3;      /*    CKSEL     */
                            }      BIT;                 /*              */
                     }          TCR;                    /*              */
               char             wk2[16];                /*              */
               unsigned short   TCNT;                   /* TCNT8        */
               unsigned short   CYLR;                   /* CYLR8        */
               unsigned short   BFR;                    /* BFR8         */
               unsigned short   DTR;                    /* DTR8         */
};                                                      /*              */
struct st_atu9 {                                        /* struct ATU9  */
               union {                                  /* TIERE        */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char    :7;        /*              */
                            unsigned char CME:1;        /*    CME9      */
                            }      BIT;                 /*              */
                     }          TIERE;                  /*              */
               union {                                  /* TSRE         */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char    :7;        /*              */
                            unsigned char CMF:1;        /*    CMF9      */
                            }      BIT;                 /*              */
                     }          TSRE;                   /*              */
               char             wk1[2];                 /*              */
               union {                                  /* TCR9         */
                     unsigned char BYTE;                /*  Byte Access */
                     struct {                           /*  Bit  Access */
                            unsigned char      :5;      /*              */
                            unsigned char CKSEL:3;      /*    CKSEL     */
                            }      BIT;                 /*              */
                     }          TCR;                    /*              */
               char             wk2[25];                /*              */
               unsigned short   TCNT;                   /* TCNT9        */
               unsigned short   CYLR;                   /* CYLR9        */
               unsigned short   BFR;                    /* BFR9         */
               unsigned short   DTR;                    /* DTR9         */
};                                                      /*              */
struct st_atu10 {                                       /* struct ATU10 */
                union {                                 /* TCR10        */
                      unsigned char BYTE;               /*  Byte Access */
                      struct {                          /*  Bit  Access */
                             unsigned char       :1;    /*              */
                             unsigned char CKSELA:3;    /*    CKSELA    */
                             unsigned char       :1;    /*              */
                             unsigned char CKSELB:3;    /*    CKSELB    */
                             }      BIT;                /*              */
                      }         TCR;                    /*              */
                union {                                 /* TCNR         */
                      unsigned char BYTE;               /*  Byte Access */
                      struct {                          /*  Bit  Access */
                             unsigned char CNH:1;       /*    CN10H     */
                             unsigned char CNG:1;       /*    CN10G     */
                             unsigned char CNF:1;       /*    CN10F     */
                             unsigned char CNE:1;       /*    CN10E     */
                             unsigned char CND:1;       /*    CN10D     */
                             unsigned char CNC:1;       /*    CN10C     */
                             unsigned char CNB:1;       /*    CN10B     */
                             unsigned char CNA:1;       /*    CN10A     */
                             }      BIT;                /*              */
                      }         TCNR;                   /*              */
                union {                                 /* TIERF        */
                      unsigned char BYTE;               /*  Byte Access */
                      struct {                          /*  Bit  Access */
                             unsigned char OSEH:1;      /*    OSE10H    */
                             unsigned char OSEG:1;      /*    OSE10G    */
                             unsigned char OSEF:1;      /*    OSE10F    */
                             unsigned char OSEE:1;      /*    OSE10E    */
                             unsigned char OSED:1;      /*    OSE10D    */
                             unsigned char OSEC:1;      /*    OSE10C    */
                             unsigned char OSEB:1;      /*    OSE10B    */
                             unsigned char OSEA:1;      /*    OSE10A    */
                             }      BIT;                /*              */
                      }         TIERF;                  /*              */
                union {                                 /* TSRF         */
                      unsigned char BYTE;               /*  Byte Access */
                      struct {                          /*  Bit  Access */
                             unsigned char OSFH:1;      /*    OSF10H    */
                             unsigned char OSFG:1;      /*    OSF10G    */
                             unsigned char OSFF:1;      /*    OSF10F    */
                             unsigned char OSFE:1;      /*    OSF10E    */
                             unsigned char OSFD:1;      /*    OSF10D    */
                             unsigned char OSFC:1;      /*    OSF10C    */
                             unsigned char OSFB:1;      /*    OSF10B    */
                             unsigned char OSFA:1;      /*    OSF10A    */
                             }      BIT;                /*              */
                      }         TSRF;                   /*              */
                char            wk1;                    /*              */
                union {                                 /* DSTR         */
                      unsigned char BYTE;               /*  Byte Access */
                      struct {                          /*  Bit  Access */
                             unsigned char DSTH:1;      /*    DST10H    */
                             unsigned char DSTG:1;      /*    DST10G    */
                             unsigned char DSTF:1;      /*    DST10F    */
                             unsigned char DSTE:1;      /*    DST10E    */
                             unsigned char DSTD:1;      /*    DST10D    */
                             unsigned char DSTC:1;      /*    DST10C    */
                             unsigned char DSTB:1;      /*    DST10B    */
                             unsigned char DSTA:1;      /*    DST10A    */
                             }      BIT;                /*              */
                      }         DSTR;                   /*              */
                char            wk2[10];                /*              */
                unsigned short  DCNTA;                  /* DCNT10A      */
                unsigned short  DCNTB;                  /* DCNT10B      */
                unsigned short  DCNTC;                  /* DCNT10C      */
                unsigned short  DCNTD;                  /* DCNT10D      */
                unsigned short  DCNTE;                  /* DCNT10E      */
                unsigned short  DCNTF;                  /* DCNT10F      */
                unsigned short  DCNTG;                  /* DCNT10G      */
                unsigned short  DCNTH;                  /* DCNT10H      */
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
                            unsigned char _DMAC01:4;    /*    DMAC0     */
                            unsigned char _DMAC23:4;    /*    DMAC1     */
                            unsigned char _ATU01 :4;    /*    ATU01     */
                            unsigned char _ATU02 :4;    /*    ATU02     */
                            }       BIT;                /*              */
                     }          IPRC;                   /*              */
               union {                                  /* IPRD         */
                     unsigned short WORD;               /*  Word Access */
                     struct {                           /*  Bit  Access */
                            unsigned char _ATU03:4;     /*    ATU03     */
                            unsigned char _ATU11:4;     /*    ATU11     */
                            unsigned char _ATU12:4;     /*    ATU12     */
                            unsigned char _ATU13:4;     /*    ATU13     */
                            }       BIT;                /*              */
                     }          IPRD;                   /*              */
               union {                                  /* IPRE         */
                     unsigned short WORD;               /*  Word Access */
                     struct {                           /*  Bit  Access */
                            unsigned char _ATU2 :4;     /*    ATU2      */
                            unsigned char _ATU31:4;     /*    ATU31     */
                            unsigned char _ATU32:4;     /*    ATU32     */
                            unsigned char _ATU41:4;     /*    ATU41     */
                            }       BIT;                /*              */
                     }          IPRE;                   /*              */
               union {                                  /* IPRF         */
                     unsigned short WORD;               /*  Word Access */
                     struct {                           /*  Bit  Access */
                            unsigned char _ATU42 :4;    /*    ATU42     */
                            unsigned char _ATU5  :4;    /*    ATU5      */
                            unsigned char _ATU69 :4;    /*    ATU6-9    */
                            unsigned char _ATU101:4;    /*    ATU101    */
                            }       BIT;                /*              */
                     }          IPRF;                   /*              */
               union {                                  /* IPRG         */
                     unsigned short WORD;               /*  Word Access */
                     struct {                           /*  Bit  Access */
                            unsigned char _ATU102:4;    /*    ATU10     */
                            unsigned char _ATU103:4;    /*    ATU10     */
                            unsigned char _CMT0  :4;    /*    CMT0,A/D0 */
                            unsigned char _CMT1  :4;    /*    CMT1,A/D1 */
                            }       BIT;                /*              */
                     }          IPRG;                   /*              */
               union {                                  /* IPRH         */
                     unsigned short WORD;               /*  Word Access */
                     struct {                           /*  Bit  Access */
                            unsigned char _SCI0:4;      /*    SCI0      */
                            unsigned char _SCI1:4;      /*    SCI1      */
                            unsigned char _SCI2:4;      /*    SCI2      */
                            unsigned char _WDT :4;      /*    WDT       */
                            }       BIT;                /*              */
                     }          IPRH;                   /*              */
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
                          unsigned char    :2;          /*              */
                          unsigned char B11:1;          /*    Bit 11    */
                          unsigned char B10:1;          /*    Bit 10    */
                          unsigned char B9 :1;          /*    Bit  9    */
                          unsigned char B8 :1;          /*    Bit  8    */
                          unsigned char B7 :1;          /*    Bit  7    */
                          unsigned char B6 :1;          /*    Bit  6    */
                          unsigned char    :2;          /*              */
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
                          unsigned char    :1;          /*              */
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
struct st_pd {                                          /* struct PD    */
             union {                                    /* PDDR         */
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
struct st_pe {                                          /* struct PE    */
             union {                                    /* PEDR         */
                   unsigned short WORD;                 /*  Word Access */
                   struct {                             /*  Byte Access */
                          unsigned char H;              /*    High      */
                          unsigned char L;              /*    Low       */
                          }       BYTE;                 /*              */
                   struct {                             /*  Bit  Access */
                          unsigned char    :1;          /*              */
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
                          unsigned char    :4;          /*              */
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
              union {                                   /* PACR         */
                    unsigned short WORD;                /*  Word Access */
                    struct {                            /*  Byte Access */
                           unsigned char H;             /*    High      */
                           unsigned char L;             /*    Low       */
                           }       BYTE;                /*              */
                    struct {                            /*  Bit  Access */
                           unsigned char PA15MD:1;      /*    PA15MD    */
                           unsigned char PA14MD:1;      /*    PA14MD    */
                           unsigned char PA13MD:1;      /*    PA13MD    */
                           unsigned char PA12MD:1;      /*    PA12MD    */
                           unsigned char PA11MD:1;      /*    PA11MD    */
                           unsigned char PA10MD:1;      /*    PA10MD    */
                           unsigned char PA9MD :1;      /*    PA9MD     */
                           unsigned char PA8MD :1;      /*    PA8MD     */
                           unsigned char PA7MD :1;      /*    PA7MD     */
                           unsigned char PA6MD :1;      /*    PA6MD     */
                           unsigned char PA5MD :1;      /*    PA5MD     */
                           unsigned char PA4MD :1;      /*    PA4MD     */
                           unsigned char PA3MD :1;      /*    PA3MD     */
                           unsigned char PA2MD :1;      /*    PA2MD     */
                           unsigned char PA1MD :1;      /*    PA1MD     */
                           unsigned char PA0MD :1;      /*    PA0MD     */
                           }       BIT;                 /*              */
                    }           PACR;                   /*              */
              char              wk1[2];                 /*              */
              union {                                   /* PBIOR        */
                    unsigned short WORD;                /*  Word Access */
                    struct {                            /*  Byte Access */
                           unsigned char H;             /*    High      */
                           unsigned char L;             /*    Low       */
                           }       BYTE;                /*              */
                    struct {                            /*  Bit  Access */
                           unsigned char    :2;         /*              */
                           unsigned char B11:1;         /*    Bit 11    */
                           unsigned char B10:1;         /*    Bit 10    */
                           unsigned char B9 :1;         /*    Bit  9    */
                           unsigned char B8 :1;         /*    Bit  8    */
                           unsigned char B7 :1;         /*    Bit  7    */
                           unsigned char B6 :1;         /*    Bit  6    */
                           unsigned char    :2;         /*              */
                           unsigned char B5 :1;         /*    Bit  5    */
                           unsigned char B4 :1;         /*    Bit  4    */
                           unsigned char B3 :1;         /*    Bit  3    */
                           unsigned char B2 :1;         /*    Bit  2    */
                           unsigned char B1 :1;         /*    Bit  1    */
                           unsigned char B0 :1;         /*    Bit  0    */
                           }       BIT;                 /*              */
                    }           PBIOR;                  /*              */
              union {                                   /* PBCR         */
                    unsigned short WORD;                /*  Word Access */
                    struct {                            /*  Byte Access */
                           unsigned char H;             /*    High      */
                           unsigned char L;             /*    Low       */
                           }       BYTE;                /*              */
                    struct {                            /*  Bit  Access */
                           unsigned char       :1;      /*              */
                           unsigned char PB11MD:2;      /*    PB11MD    */
                           unsigned char PB10MD:1;      /*    PB10MD    */
                           unsigned char PB9MD :1;      /*    PB9MD     */
                           unsigned char PB8MD :1;      /*    PB8MD     */
                           unsigned char PB7MD :1;      /*    PB7MD     */
                           unsigned char PB6MD :1;      /*    PB6MD     */
                           unsigned char       :2;      /*              */
                           unsigned char PB5MD :1;      /*    PB5MD     */
                           unsigned char PB4MD :1;      /*    PB4MD     */
                           unsigned char PB3MD :1;      /*    PB3MD     */
                           unsigned char PB2MD :1;      /*    PB2MD     */
                           unsigned char PB1MD :1;      /*    PB1MD     */
                           unsigned char PB0MD :1;      /*    PB0MD     */
                           }       BIT;                 /*              */
                    }           PBCR;                   /*              */
              char              wk2[6];                 /*              */
              union {                                   /* PCIOR        */
                    unsigned short WORD;                /*  Word Access */
                    struct {                            /*  Byte Access */
                           unsigned char H;             /*    High      */
                           unsigned char L;             /*    Low       */
                           }       BYTE;                /*              */
                    struct {                            /*  Bit  Access */
                           unsigned char    :1;         /*              */
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
                    }           PCIOR;                  /*              */
              union {                                   /* PCCR1        */
                    unsigned short WORD;                /*  Word Access */
                    struct {                            /*  Byte Access */
                           unsigned char H;             /*    High      */
                           unsigned char L;             /*    Low       */
                           }       BYTE;                /*              */
                    struct {                            /*  Bit  Access */
                           unsigned char       :2;      /*              */
                           unsigned char PC14MD:2;      /*    PC14MD    */
                           unsigned char PC13MD:2;      /*    PC13MD    */
                           unsigned char PC12MD:2;      /*    PC12MD    */
                           unsigned char PC11MD:2;      /*    PC11MD    */
                           unsigned char PC10MD:2;      /*    PC10MD    */
                           unsigned char PC9MD :2;      /*    PC9MD     */
                           unsigned char PC8MD :2;      /*    PC8MD     */
                           }       BIT;                 /*              */
                    }           PCCR1;                  /*              */
              union {                                   /* PCCR2        */
                    unsigned short WORD;                /*  Word Access */
                    struct {                            /*  Byte Access */
                           unsigned char H;             /*    High      */
                           unsigned char L;             /*    Low       */
                           }       BYTE;                /*              */
                    struct {                            /*  Bit  Access */
                           unsigned char PC7MD:2;       /*    PC7MD     */
                           unsigned char PC6MD:2;       /*    PC6MD     */
                           unsigned char      :1;       /*              */
                           unsigned char PC5MD:1;       /*    PC5MD     */
                           unsigned char      :1;       /*              */
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
                    }           PCCR2;                  /*              */
              char              wk3[2];                 /*              */
              union {                                   /* PDIOR        */
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
                    }           PDIOR;                  /*              */
              union {                                   /* PDCR         */
                    unsigned short WORD;                /*  Word Access */
                    struct {                            /*  Byte Access */
                           unsigned char H;             /*    High      */
                           unsigned char L;             /*    Low       */
                           }       BYTE;                /*              */
                    struct {                            /*  Bit  Access */
                           unsigned char PD15MD:1;      /*    PD15MD    */
                           unsigned char PD14MD:1;      /*    PD14MD    */
                           unsigned char PD13MD:1;      /*    PD13MD    */
                           unsigned char PD12MD:1;      /*    PD12MD    */
                           unsigned char PD11MD:1;      /*    PD11MD    */
                           unsigned char PD10MD:1;      /*    PD10MD    */
                           unsigned char PD9MD :1;      /*    PD9MD     */
                           unsigned char PD8MD :1;      /*    PD8MD     */
                           unsigned char PD7MD :1;      /*    PD7MD     */
                           unsigned char PD6MD :1;      /*    PD6MD     */
                           unsigned char PD5MD :1;      /*    PD5MD     */
                           unsigned char PD4MD :1;      /*    PD4MD     */
                           unsigned char PD3MD :1;      /*    PD3MD     */
                           unsigned char PD2MD :1;      /*    PD2MD     */
                           unsigned char PD1MD :1;      /*    PD1MD     */
                           unsigned char PD0MD :1;      /*    PD0MD     */
                           }       BIT;                 /*              */
                    }           PDCR;                   /*              */
              union {                                   /* CKCR         */
                    unsigned short WORD;                /*  Word Access */
                    struct {                            /*  Byte Access */
                           unsigned char H;             /*    High      */
                           unsigned char L;             /*    Low       */
                           }       BYTE;                /*              */
                    struct {                            /*  Bit  Access */
                           unsigned char     :8;        /*              */
                           unsigned char     :7;        /*              */
                           unsigned char CKLO:1;        /*    CKLO      */
                           }       BIT;                 /*              */
                    }           CKCR;                   /*              */
              char              wk4[2];                 /*              */
              union {                                   /* PEIOR        */
                    unsigned short WORD;                /*  Word Access */
                    struct {                            /*  Byte Access */
                           unsigned char H;             /*    High      */
                           unsigned char L;             /*    Low       */
                           }       BYTE;                /*              */
                    struct {                            /*  Bit  Access */
                           unsigned char    :1;         /*              */
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
                           unsigned char       :1;      /*              */
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
              char              wk5[2];                 /*              */
              union {                                   /* PFIOR        */
                    unsigned short WORD;                /*  Word Access */
                    struct {                            /*  Byte Access */
                           unsigned char H;             /*    High      */
                           unsigned char L;             /*    Low       */
                           }       BYTE;                /*              */
                    struct {                            /*  Bit  Access */
                           unsigned char    :4;         /*              */
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
              union {                                   /* PFCR1        */
                    unsigned short WORD;                /*  Word Access */
                    struct {                            /*  Byte Access */
                           unsigned char H;             /*    High      */
                           unsigned char L;             /*    Low       */
                           }       BYTE;                /*              */
                    struct {                            /*  Bit  Access */
                           unsigned char       :8;      /*              */
                           unsigned char PF11MD:2;      /*    PF11MD    */
                           unsigned char PF10MD:2;      /*    PF10MD    */
                           unsigned char PF9MD :2;      /*    PF9MD     */
                           unsigned char PF8MD :2;      /*    PF8MD     */
                           }       BIT;                 /*              */
                    }           PFCR1;                  /*              */
              union {                                   /* PFCR2        */
                    unsigned short WORD;                /*  Word Access */
                    struct {                            /*  Byte Access */
                           unsigned char H;             /*    High      */
                           unsigned char L;             /*    Low       */
                           }       BYTE;                /*              */
                    struct {                            /*  Bit  Access */
                           unsigned char PF7MD:2;       /*    PF7MD     */
                           unsigned char PF6MD:2;       /*    PF6MD     */
                           unsigned char PF5MD:2;       /*    PF5MD     */
                           unsigned char PF4MD:2;       /*    PF4MD     */
                           unsigned char      :1;       /*              */
                           unsigned char PF3MD:1;       /*    PF3MD     */
                           unsigned char      :1;       /*              */
                           unsigned char PF2MD:1;       /*    PF2MD     */
                           unsigned char      :1;       /*              */
                           unsigned char PF1MD:1;       /*    PF1MD     */
                           unsigned char      :1;       /*              */
                           unsigned char PF0MD:1;       /*    PF0MD     */
                           }       BIT;                 /*              */
                    }           PFCR2;                  /*              */
              char              wk6[2];                 /*              */
              union {                                   /* PGIOR        */
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
                    }           PGIOR;                  /*              */
              union {                                   /* PGCR1        */
                    unsigned short WORD;                /*  Word Access */
                    struct {                            /*  Byte Access */
                           unsigned char H;             /*    High      */
                           unsigned char L;             /*    Low       */
                           }       BYTE;                /*              */
                    struct {                            /*  Bit  Access */
                           unsigned char PG15MD:2;      /*    PG15MD    */
                           unsigned char PG14MD:2;      /*    PG14MD    */
                           unsigned char       :1;      /*              */
                           unsigned char PG13MD:1;      /*    PG13MD    */
                           unsigned char       :1;      /*              */
                           unsigned char PG12MD:1;      /*    PG12MD    */
                           unsigned char       :1;      /*              */
                           unsigned char PG11MD:1;      /*    PG11MD    */
                           unsigned char       :1;      /*              */
                           unsigned char PG10MD:1;      /*    PG10MD    */
                           unsigned char       :1;      /*              */
                           unsigned char PG9MD :1;      /*    PG9MD     */
                           unsigned char       :1;      /*              */
                           unsigned char PG8MD :1;      /*    PG8MD     */
                           }       BIT;                 /*              */
                    }           PGCR1;                  /*              */
              union {                                   /* PGCR2        */
                    unsigned short WORD;                /*  Word Access */
                    struct {                            /*  Byte Access */
                           unsigned char H;             /*    High      */
                           unsigned char L;             /*    Low       */
                           }       BYTE;                /*              */
                    struct {                            /*  Bit  Access */
                           unsigned char      :1;       /*              */
                           unsigned char PG7MD:1;       /*    PG7MD     */
                           unsigned char      :1;       /*              */
                           unsigned char PG6MD:1;       /*    PG6MD     */
                           unsigned char      :1;       /*              */
                           unsigned char PG5MD:1;       /*    PG5MD     */
                           unsigned char      :1;       /*              */
                           unsigned char PG4MD:1;       /*    PG4MD     */
                           unsigned char      :1;       /*              */
                           unsigned char PG3MD:1;       /*    PG3MD     */
                           unsigned char PG2MD:1;       /*    PG2MD     */
                           unsigned char PG1MD:1;       /*    PG1MD     */
                           unsigned char PG0MD:2;       /*    PG0MD     */
                           unsigned char IRQMD:2;       /*    IRQMD     */
                           }       BIT;                 /*              */
                    }           PGCR2;                  /*              */
};                                                      /*              */
struct st_ad0 {                                         /* struct A/D0  */
              union {                                   /* ADTRGR       */
                    unsigned char BYTE;                 /*  Byte Access */
                    struct {                            /*  Bit  Access */
                           unsigned char EXTRG:1;       /*    EXTRG     */
                           unsigned char      :7;       /*              */
                           }      BIT;                  /*              */
                    }           ADTRGR;                 /*              */
              char              wk[535];                /*              */
              union {                                   /* ADDR0        */
                    unsigned short WORD;                /*  Word Access */
                    unsigned char  BYTE;                /*  Byte Access */
                    }           ADDR0;                  /*              */
              union {                                   /* ADDR1        */
                    unsigned short WORD;                /*  Word Access */
                    unsigned char  BYTE;                /*  Byte Access */
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
                           }      BIT;                  /*              */
                    }           ADCR;                   /*              */
};                                                      /*              */
struct st_ad1 {                                         /* struct A/D1  */
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
              union {                                   /* ADCSR1       */
                    unsigned char BYTE;                 /*  Byte Access */
                    struct {                            /*  Bit  Access */
                           unsigned char ADF :1;        /*    ADF       */
                           unsigned char ADIE:1;        /*    ADIE      */
                           unsigned char ADST:1;        /*    ADST      */
                           unsigned char SCAN:1;        /*    SCAN      */
                           unsigned char CKS :1;        /*    CKS       */
                           unsigned char     :1;        /*              */
                           unsigned char CH  :2;        /*    CH        */
                           }      BIT;                  /*              */
                    }           ADCSR ;                 /*              */
              union {                                   /* ADCR1        */
                    unsigned char BYTE;                 /*  Byte Access */
                    struct {                            /*  Bit  Access */
                           unsigned char TRGE:1;        /*    TRGE      */
                           }      BIT;                  /*              */
                    }           ADCR;                   /*              */
};                                                      /*              */
struct st_apc {                                         /* struct APC   */
              union {                                   /* POPCR        */
                    unsigned short WORD;                /*  Word Access */
                    struct {                            /*  Byte Access */
                           unsigned char ROE;           /*    High      */
                           unsigned char SOE;           /*    Low       */
                           }       BYTE;                /*              */
                    struct {                            /*  Bit  Access */
                           unsigned char PULSE7ROE:1;   /*    PULSE7ROE */
                           unsigned char PULSE6ROE:1;   /*    PULSE6ROE */
                           unsigned char PULSE5ROE:1;   /*    PULSE5ROE */
                           unsigned char PULSE4ROE:1;   /*    PULSE4ROE */
                           unsigned char PULSE3ROE:1;   /*    PULSE3ROE */
                           unsigned char PULSE2ROE:1;   /*    PULSE2ROE */
                           unsigned char PULSE1ROE:1;   /*    PULSE1ROE */
                           unsigned char PULSE0ROE:1;   /*    PULSE0ROE */
                           unsigned char PULSE7SOE:1;   /*    PULSE7SOE */
                           unsigned char PULSE6SOE:1;   /*    PULSE6SOE */
                           unsigned char PULSE5SOE:1;   /*    PULSE5SOE */
                           unsigned char PULSE4SOE:1;   /*    PULSE4SOE */
                           unsigned char PULSE3SOE:1;   /*    PULSE3SOE */
                           unsigned char PULSE2SOE:1;   /*    PULSE2SOE */
                           unsigned char PULSE1SOE:1;   /*    PULSE1SOE */
                           unsigned char PULSE0SOE:1;   /*    PULSE0SOE */
                           }       BIT;                 /*              */
                    }           POPCR;                  /*              */
};                                                      /*              */
union un_syscr {                                        /* union SYSCR  */
               unsigned char    BYTE;                   /*  Byte Access */
               struct {                                 /*  Bit  Access */
                      unsigned char     :7;             /*              */
                      unsigned char RAME:1;             /*    RAME      */
                      }         BIT;                    /*              */
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
                                 }      BIT;            /*              */
                          }       RSTCSR;               /*              */
                    } READ;                             /*              */
             struct {                                   /* Write Access */
                    unsigned int  TCSR;                 /* TCSR/TCNT    */
                    unsigned int  RSTCSR;               /* RSTCSR       */
                    } WRITE;                            /*              */
};                                                      /*              */
union un_sbycr {                                        /* union SBYCR  */
               unsigned char    BYTE;                   /*  Byte Access */
               struct {                                 /*  Bit  Access */
                      unsigned char SSBY:1;             /*    SBY       */
                      unsigned char HIZ :1;             /*    HIZ       */
                      }         BIT;                    /*              */
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
              union {                                   /* WCR1         */
                    unsigned short WORD;                /*  Word Access */
                    struct {                            /*  Bit  Access */
                           unsigned char W3:4;          /*    W3        */
                           unsigned char W2:4;          /*    W2        */
                           unsigned char W1:4;          /*    W1        */
                           unsigned char W0:4;          /*    W0        */
                           }       BIT;                 /*              */
                    }           WCR1;                   /*              */
              union {                                   /* WCR2         */
                    unsigned short WORD;                /*  Word Access */
                    struct {                            /*  Bit  Access */
                           unsigned char    :8;         /*              */
                           unsigned char    :4;         /*              */
                           unsigned char DDW:2;         /*    DDW       */
                           unsigned char DSW:4;         /*    DSW       */
                           }       BIT;                 /*              */
                    }           WCR2;                   /*              */
};                                                      /*              */
struct st_dmac {                                        /* struct DMAC  */
               union {                                  /* DMAOR        */
                     unsigned short WORD;               /*  Word Access */
                     struct {                           /*  Bit  Access */
                            unsigned short     :6;      /*              */
                            unsigned short PR  :2;      /*    PR        */
                            unsigned short     :5;      /*              */
                            unsigned short AE  :1;      /*    AE        */
                            unsigned short NMIF:1;      /*    NMIF      */
                            unsigned short DME :1;      /*    DME       */
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
                             unsigned short   :13;      /*              */
                             unsigned short RL: 1;      /*    RL        */
                             unsigned short AM: 1;      /*    AM        */
                             unsigned short AL: 1;      /*    AL        */
                             unsigned short DM: 2;      /*    DM        */
                             unsigned short SM: 2;      /*    SM        */
                             unsigned short RS: 4;      /*    RS        */
                             unsigned short   : 1;      /*              */
                             unsigned short DS: 1;      /*    DS        */
                             unsigned short TM: 1;      /*    TM        */
                             unsigned short TS: 2;      /*    TS        */
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
                             unsigned short   :12;      /*              */
                             unsigned short RO: 1;      /*    RO        */
                             unsigned short   : 3;      /*              */
                             unsigned short DM: 2;      /*    DM        */
                             unsigned short SM: 2;      /*    SM        */
                             unsigned short RS: 4;      /*    RS        */
                             unsigned short   : 2;      /*              */
                             unsigned short TM: 1;      /*    TM        */
                             unsigned short TS: 2;      /*    TS        */
                             unsigned short IE: 1;      /*    IE        */
                             unsigned short TE: 1;      /*    TE        */
                             unsigned short DE: 1;      /*    DE        */
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
                             unsigned short   :11;      /*              */
                             unsigned short DI: 1;      /*    DI        */
                             unsigned short   : 4;      /*              */
                             unsigned short DM: 2;      /*    DM        */
                             unsigned short SM: 2;      /*    SM        */
                             unsigned short RS: 4;      /*    RS        */
                             unsigned short   : 2;      /*              */
                             unsigned short TM: 1;      /*    TM        */
                             unsigned short TS: 2;      /*    TS        */
                             unsigned short IE: 1;      /*    IE        */
                             unsigned short TE: 1;      /*    TE        */
                             unsigned short DE: 1;      /*    DE        */
                             }     BIT;                 /*              */
                      }         CHCR;                   /*              */
};                                                      /*              */
#define SCI0  (*(volatile struct st_sci   *)0xFFFF81A0) /* SCI0  Address*/
#define SCI1  (*(volatile struct st_sci   *)0xFFFF81B0) /* SCI1  Address*/
#define SCI2  (*(volatile struct st_sci   *)0xFFFF81C0) /* SCI2  Address*/
#define ATU   (*(volatile struct st_atu   *)0xFFFF82E8) /* ATU   Address*/
#define ATU0  (*(volatile struct st_atu0  *)0xFFFF8280) /* ATU0  Address*/
#define ATU1  (*(volatile struct st_atu1  *)0xFFFF82C0) /* ATU1  Address*/
#define ATU2  (*(volatile struct st_atu2  *)0xFFFF82C6) /* ATU2  Address*/
#define ATU3  (*(volatile struct st_atu3  *)0xFFFF8200) /* ATU3  Address*/
#define ATU4  (*(volatile struct st_atu4  *)0xFFFF8200) /* ATU4  Address*/
#define ATU5  (*(volatile struct st_atu5  *)0xFFFF8200) /* ATU5  Address*/
#define ATU6  (*(volatile struct st_atu6  *)0xFFFF8240) /* ATU6  Address*/
#define ATU7  (*(volatile struct st_atu7  *)0xFFFF8240) /* ATU7  Address*/
#define ATU8  (*(volatile struct st_atu8  *)0xFFFF8240) /* ATU8  Address*/
#define ATU9  (*(volatile struct st_atu9  *)0xFFFF8240) /* ATU9  Address*/
#define ATU10 (*(volatile struct st_atu10 *)0xFFFF82E0) /* ATU10 Address*/
#define INTC  (*(volatile struct st_intc  *)0xFFFF8348) /* INTC  Address*/
#define PA    (*(volatile struct st_pa    *)0xFFFF8380) /* PA    Address*/
#define PB    (*(volatile struct st_pb    *)0xFFFF8386) /* PB    Address*/
#define PC    (*(volatile struct st_pc    *)0xFFFF8390) /* PC    Address*/
#define PD    (*(volatile struct st_pd    *)0xFFFF8398) /* PD    Address*/
#define PE    (*(volatile struct st_pe    *)0xFFFF83A0) /* PE    Address*/
#define PF    (*(volatile struct st_pf    *)0xFFFF83A6) /* PF    Address*/
#define PG    (*(volatile struct st_pg    *)0xFFFF83AE) /* PG    Address*/
#define PH    (*(volatile struct st_ph    *)0xFFFF83B6) /* PH    Address*/
#define PFC   (*(volatile struct st_pfc   *)0xFFFF8382) /* PFC   Address*/
#define AD0   (*(volatile struct st_ad0   *)0xFFFF83B8) /* A/D0  Address*/
#define AD1   (*(volatile struct st_ad1   *)0xFFFF85F0) /* A/D1  Address*/
#define APC   (*(volatile struct st_apc   *)0xFFFF83C0) /* APC   Address*/
#define SYSCR (*(volatile union  un_syscr *)0xFFFF83C8) /* SYSCR Address*/
#define WDT   (*(volatile union  un_wdt   *)0xFFFF8610) /* WDT   Address*/
#define SBYCR (*(volatile union  un_sbycr *)0xFFFF8614) /* SBYCR Address*/
#define CMT   (*(volatile struct st_cmt   *)0xFFFF83D0) /* CMT   Address*/
#define CMT0  (*(volatile struct st_cmt0  *)0xFFFF83D2) /* CMT0  Address*/
#define CMT1  (*(volatile struct st_cmt0  *)0xFFFF83D8) /* CMT1  Address*/
#define FLASH (*(volatile struct st_flash *)0xFFFF8580) /* FLASH Address*/
#define UBC   (*(volatile struct st_ubc   *)0xFFFF8600) /* UBC   Address*/
#define BSC   (*(volatile struct st_bsc   *)0xFFFF8620) /* BSC   Address*/
#define DMAC  (*(volatile struct st_dmac  *)0xFFFF86B0) /* DMAC  Address*/
#define DMAC0 (*(volatile struct st_dmac0 *)0xFFFF86C0) /* DMAC0 Address*/
#define DMAC1 (*(volatile struct st_dmac0 *)0xFFFF86D0) /* DMAC1 Address*/
#define DMAC2 (*(volatile struct st_dmac2 *)0xFFFF86E0) /* DMAC2 Address*/
#define DMAC3 (*(volatile struct st_dmac3 *)0xFFFF86F0) /* DMAC3 Address*/
