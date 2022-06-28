/***********************************************************************/
/*      SH7059 Include File                                 Ver 1.1    */
/***********************************************************************/
struct st_intc {                                       /* struct INTC  */
       union {                                         /* IPRA         */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short IRQ0:4;             /*   IRQ0       */
                    unsigned short IRQ1:4;             /*   IRQ1       */
                    unsigned short IRQ2:4;             /*   IRQ2       */
                    unsigned short IRQ3:4;             /*   IRQ3       */
                    } BIT;                             /*              */
             } IPRA;                                   /*              */
       union {                                         /* IPRB         */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short IRQ4:4;             /*   IRQ4       */
                    unsigned short IRQ5:4;             /*   IRQ5       */
                    unsigned short IRQ6:4;             /*   IRQ6       */
                    unsigned short IRQ7:4;             /*   IRQ7       */
                    } BIT;                             /*              */
             } IPRB;                                   /*              */
       union {                                         /* IPRC         */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short DMAC01:4;           /*   DMAC01     */
                    unsigned short DMAC23:4;           /*   DMAC23     */
                    unsigned short ATU01:4;            /*   ATU01      */
                    unsigned short ATU02:4;            /*   ATU02      */
                    } BIT;                             /*              */
             } IPRC;                                   /*              */
       union {                                         /* IPRD         */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short ATU03:4;            /*   ATU03      */
                    unsigned short ATU04:4;            /*   ATU04      */
                    unsigned short ATU11:4;            /*   ATU11      */
                    unsigned short ATU12:4;            /*   ATU12      */
                    } BIT;                             /*              */
             } IPRD;                                   /*              */
       union {                                         /* IPRE         */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short ATU13:4;            /*   ATU13      */
                    unsigned short ATU21:4;            /*   ATU21      */
                    unsigned short ATU22:4;            /*   ATU22      */
                    unsigned short ATU23:4;            /*   ATU23      */
                    } BIT;                             /*              */
             } IPRE;                                   /*              */
       union {                                         /* IPRF         */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short ATU31:4;            /*   ATU31      */
                    unsigned short ATU32:4;            /*   ATU32      */
                    unsigned short ATU41:4;            /*   ATU41      */
                    unsigned short ATU42:4;            /*   ATU42      */
                    } BIT;                             /*              */
             } IPRF;                                   /*              */
       union {                                         /* IPRG         */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short ATU51:4;            /*   ATU51      */
                    unsigned short ATU52:4;            /*   ATU52      */
                    unsigned short ATU6:4;             /*   ATU6       */
                    unsigned short ATU7:4;             /*   ATU7       */
                    } BIT;                             /*              */
             } IPRG;                                   /*              */
       union {                                         /* IPRH         */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short ATU81:4;            /*   ATU81      */
                    unsigned short ATU82:4;            /*   ATU82      */
                    unsigned short ATU83:4;            /*   ATU83      */
                    unsigned short ATU84:4;            /*   ATU84      */
                    } BIT;                             /*              */
             } IPRH;                                   /*              */
       union {                                         /* IPRI         */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short ATU91:4;            /*   ATU91      */
                    unsigned short ATU92:4;            /*   ATU92      */
                    unsigned short ATU101:4;           /*   ATU101     */
                    unsigned short ATU102:4;           /*   ATU102     */
                    } BIT;                             /*              */
             } IPRI;                                   /*              */
       union {                                         /* IPRJ         */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short ATU11:4;            /*   ATU11      */
                    unsigned short CMT0_AD0:4;         /*   CMT0_A/D0  */
                    unsigned short CMT1_AD1:4;         /*   CMT1_A/D1  */
                    unsigned short AD2:4;              /*   A/D2       */
                    } BIT;                             /*              */
             } IPRJ;                                   /*              */
       union {                                         /* IPRK         */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short SCI0:4;             /*   SCI0       */
                    unsigned short SCI1:4;             /*   SCI1       */
                    unsigned short SCI2:4;             /*   SCI2       */
                    unsigned short SCI3:4;             /*   SCI3       */
                    } BIT;                             /*              */
             } IPRK;                                   /*              */
       union {                                         /* IPRL         */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short SCI4:4;             /*   SCI4       */
                    unsigned short HCAN0:4;            /*   HCAN0      */
                    unsigned short WDT:4;              /*   WDT        */
                    unsigned short HCAN1:4;            /*   HCAN1      */
                    } BIT;                             /*              */
             } IPRL;                                   /*              */
       union {                                         /* ICR          */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short NMIL:1;             /*   NMIL       */
                    unsigned short :6;                 /*              */
                    unsigned short NMIE:1;             /*   NMIE       */
                    unsigned short IRQ0S:1;            /*   IRQ0S      */
                    unsigned short IRQ1S:1;            /*   IRQ1S      */
                    unsigned short IRQ2S:1;            /*   IRQ2S      */
                    unsigned short IRQ3S:1;            /*   IRQ3S      */
                    unsigned short IRQ4S:1;            /*   IRQ4S      */
                    unsigned short IRQ5S:1;            /*   IRQ5S      */
                    unsigned short IRQ6S:1;            /*   IRQ6S      */
                    unsigned short IRQ7S:1;            /*   IRQ7S      */
                    } BIT;                             /*              */
             } ICR;                                    /*              */
       union {                                         /* ISR          */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short :8;                 /*              */
                    unsigned short IRQ0F:1;            /*   IRQ0F      */
                    unsigned short IRQ1F:1;            /*   IRQ1F      */
                    unsigned short IRQ2F:1;            /*   IRQ2F      */
                    unsigned short IRQ3F:1;            /*   IRQ3F      */
                    unsigned short IRQ4F:1;            /*   IRQ4F      */
                    unsigned short IRQ5F:1;            /*   IRQ5F      */
                    unsigned short IRQ6F:1;            /*   IRQ6F      */
                    unsigned short IRQ7F:1;            /*   IRQ7F      */
                    } BIT;                             /*              */
             } ISR;                                    /*              */
};                                                     /*              */
struct st_ubc {                                        /* struct UBC   */
       void             *UBAR;                         /* UBAR         */
       unsigned int      UBAMR;                        /* UBAMR        */
       union {                                         /* UBBR         */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short :8;                 /*              */
                    unsigned short CP:2;               /*   CP         */
                    unsigned short ID:2;               /*   ID         */
                    unsigned short RW:2;               /*   RW         */
                    unsigned short SZ:2;               /*   SZ         */
                    } BIT;                             /*              */
             } UBBR;                                   /*              */
       union {                                         /* UBCR         */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short :13;                /*              */
                    unsigned short CKS:2;              /*   CKS        */
                    unsigned short UBID:1;             /*   UBID       */
                    } BIT;                             /*              */
             } UBCR;                                   /*              */
};                                                     /*              */
struct st_bsc {                                        /* struct BSC   */
       union {                                         /* BCR1         */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short :12;                /*              */
                    unsigned short A3SZ:1;             /*   A3SZ       */
                    unsigned short A2SZ:1;             /*   A2SZ       */
                    unsigned short A1SZ:1;             /*   A1SZ       */
                    unsigned short A0SZ:1;             /*   A0SZ       */
                    } BIT;                             /*              */
             } BCR1;                                   /*              */
       union {                                         /* BCR2         */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short IW3:2;              /*   IW3        */
                    unsigned short IW2:2;              /*   IW2        */
                    unsigned short IW1:2;              /*   IW1        */
                    unsigned short IW0:2;              /*   IW0        */
                    unsigned short CW3:1;              /*   CW3        */
                    unsigned short CW2:1;              /*   CW2        */
                    unsigned short CW1:1;              /*   CW1        */
                    unsigned short CW0:1;              /*   CW0        */
                    unsigned short SW3:1;              /*   SW3        */
                    unsigned short SW2:1;              /*   SW2        */
                    unsigned short SW1:1;              /*   SW1        */
                    unsigned short SW0:1;              /*   SW0        */
                    } BIT;                             /*              */
             } BCR2;                                   /*              */
       union {                                         /* WCR          */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short :1;                 /*              */
                    unsigned short W3:3;               /*   W3         */
                    unsigned short :1;                 /*              */
                    unsigned short W2:3;               /*   W2         */
                    unsigned short :1;                 /*              */
                    unsigned short W1:3;               /*   W1         */
                    unsigned short :1;                 /*              */
                    unsigned short W0:3;               /*   W0         */
                    } BIT;                             /*              */
             } WCR;                                    /*              */
       union {                                         /* RAMER        */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short :12;                /*              */
                    unsigned short RAMS:1;             /*   RAMS       */
                    unsigned short RAM:3;              /*   RAM        */
                    } BIT;                             /*              */
             } RAMER;                                  /*              */
};                                                     /*              */
struct st_dmac {                                       /* struct DMAC  */
       union {                                         /* DMAOR        */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short :13;                /*              */
                    unsigned short AE:1;               /*   AE         */
                    unsigned short NMIF:1;             /*   NMIF       */
                    unsigned short DME:1;              /*   DME        */
                    } BIT;                             /*              */
             } DMAOR;                                  /*              */
};                                                     /*              */
struct st_dmac0 {                                      /* struct DMAC0 */
       void          *SAR0;                            /* SAR0         */
       void          *DAR0;                            /* DAR0         */
       unsigned long DMATCR0;                          /* DMATCR0      */
       union {                                         /* CHCR0        */
             unsigned long LONG;                       /*  Long Access */
             struct {                                  /*  Bit Access  */
                    unsigned long :11;                 /*              */
                    unsigned long RS:5;                /*   RS         */
                    unsigned long :2;                  /*              */
                    unsigned long SM:2;                /*   SM         */
                    unsigned long :2;                  /*              */
                    unsigned long DM:2;                /*   DM         */
                    unsigned long :2;                  /*              */
                    unsigned long TS:2;                /*   TS         */
                    unsigned long TM:1;                /*   TM         */
                    unsigned long IE:1;                /*   IE         */
                    unsigned long TE:1;                /*   TE         */
                    unsigned long DE:1;                /*   DE         */
                    } BIT;                             /*              */
             } CHCR0;                                  /*              */
};                                                     /*              */
struct st_dmac1 {                                      /* struct DMAC1 */
       void          *SAR1;                            /* SAR1         */
       void          *DAR1;                            /* DAR1         */
       unsigned long DMATCR1;                          /* DMATCR1      */
       union {                                         /* CHCR1        */
             unsigned long LONG;                       /*  Long Access */
             struct {                                  /*  Bit Access  */
                    unsigned long :11;                 /*              */
                    unsigned long RS:5;                /*   RS         */
                    unsigned long :2;                  /*              */
                    unsigned long SM:2;                /*   SM         */
                    unsigned long :2;                  /*              */
                    unsigned long DM:2;                /*   DM         */
                    unsigned long :2;                  /*              */
                    unsigned long TS:2;                /*   TS         */
                    unsigned long TM:1;                /*   TM         */
                    unsigned long IE:1;                /*   IE         */
                    unsigned long TE:1;                /*   TE         */
                    unsigned long DE:1;                /*   DE         */
                    } BIT;                             /*              */
             } CHCR1;                                  /*              */
};                                                     /*              */
struct st_dmac2 {                                      /* struct DMAC2 */
       void          *SAR2;                            /* SAR2         */
       void          *DAR2;                            /* DAR2         */
       unsigned long DMATCR2;                          /* DMATCR2      */
       union {                                         /* CHCR2        */
             unsigned long LONG;                       /*  Long Access */
             struct {                                  /*  Bit Access  */
                    unsigned long :7;                  /*              */
                    unsigned long RO:1;                /*   RO         */
                    unsigned long :3;                  /*              */
                    unsigned long RS:5;                /*   RS         */
                    unsigned long :2;                  /*              */
                    unsigned long SM:2;                /*   SM         */
                    unsigned long :2;                  /*              */
                    unsigned long DM:2;                /*   DM         */
                    unsigned long :2;                  /*              */
                    unsigned long TS:2;                /*   TS         */
                    unsigned long TM:1;                /*   TM         */
                    unsigned long IE:1;                /*   IE         */
                    unsigned long TE:1;                /*   TE         */
                    unsigned long DE:1;                /*   DE         */
                    } BIT;                             /*              */
             } CHCR2;                                  /*              */
};                                                     /*              */
struct st_dmac3 {                                      /* struct DMAC3 */
       void          *SAR3;                            /* SAR3         */
       void          *DAR3;                            /* DAR3         */
       unsigned long DMATCR3;                          /* DMATCR3      */
       union {                                         /* CHCR3        */
             unsigned long LONG;                       /*  Long Access */
             struct {                                  /*  Bit Access  */
                    unsigned long :3;                  /*              */
                    unsigned long DI:1;                /*   DI         */
                    unsigned long :7;                  /*              */
                    unsigned long RS:5;                /*   RS         */
                    unsigned long :2;                  /*              */
                    unsigned long SM:2;                /*   SM         */
                    unsigned long :2;                  /*              */
                    unsigned long DM:2;                /*   DM         */
                    unsigned long :2;                  /*              */
                    unsigned long TS:2;                /*   TS         */
                    unsigned long TM:1;                /*   TM         */
                    unsigned long IE:1;                /*   IE         */
                    unsigned long TE:1;                /*   TE         */
                    unsigned long DE:1;                /*   DE         */
                    } BIT;                             /*              */
             } CHCR3;                                  /*              */
};                                                     /*              */
struct st_atuii {                                      /* struct ATU-II*/
       union {                                         /* TSTR2        */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char STR7D:1;             /*   STR7D      */
                    unsigned char STR7C:1;             /*   STR7C      */
                    unsigned char STR7B:1;             /*   STR7B      */
                    unsigned char STR7A:1;             /*   STR7A      */
                    unsigned char STR6D:1;             /*   STR6D      */
                    unsigned char STR6C:1;             /*   STR6C      */
                    unsigned char STR6B:1;             /*   STR6B      */
                    unsigned char STR6A:1;             /*   STR6A      */
                    } BIT;                             /*              */
             } TSTR2;                                  /*              */
       union {                                         /* TSTR1        */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char STR10:1;             /*   STR10      */
                    unsigned char STR5:1;              /*   STR5       */
                    unsigned char STR4:1;              /*   STR4       */
                    unsigned char STR3:1;              /*   STR3       */
                    unsigned char STR1B2B:1;           /*   STR1B,2B   */
                    unsigned char STR2A:1;             /*   STR2A      */
                    unsigned char STR1A:1;             /*   STR1A      */
                    unsigned char STR0:1;              /*   STR0       */
                    } BIT;                             /*              */
             } TSTR1;                                  /*              */
       union {                                         /* TSTR3        */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char :7;                  /*              */
                    unsigned char STR11:1;             /*   STR11      */
                    } BIT;                             /*              */
             } TSTR3;                                  /*              */
       unsigned char wk0[1];                           /*              */
       union {                                         /* PSCR1        */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char :3;                  /*              */
                    unsigned char PSC1E:1;             /*   PSC1E      */
                    unsigned char PSC1D:1;             /*   PSC1D      */
                    unsigned char PSC1C:1;             /*   PSC1C      */
                    unsigned char PSC1B:1;             /*   PSC1B      */
                    unsigned char PSC1A:1;             /*   PSC1A      */
                    } BIT;                             /*              */
             } PSCR1;                                  /*              */
       unsigned char wk1[1];                           /*              */
       union {                                         /* PSCR2        */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char :3;                  /*              */
                    unsigned char PSC2E:1;             /*   PSC2E      */
                    unsigned char PSC2D:1;             /*   PSC2D      */
                    unsigned char PSC2C:1;             /*   PSC2C      */
                    unsigned char PSC2B:1;             /*   PSC2B      */
                    unsigned char PSC2A:1;             /*   PSC2A      */
                    } BIT;                             /*              */
             } PSCR2;                                  /*              */
       unsigned char wk2[1];                           /*              */
       union {                                         /* PSCR3        */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char :3;                  /*              */
                    unsigned char PSC3E:1;             /*   PSC3E      */
                    unsigned char PSC3D:1;             /*   PSC3D      */
                    unsigned char PSC3C:1;             /*   PSC3C      */
                    unsigned char PSC3B:1;             /*   PSC3B      */
                    unsigned char PSC3A:1;             /*   PSC3A      */
                    } BIT;                             /*              */
             } PSCR3;                                  /*              */
       unsigned char wk3[1];                           /*              */
       union {                                         /* PSCR4        */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char :3;                  /*              */
                    unsigned char PSC4E:1;             /*   PSC4E      */
                    unsigned char PSC4D:1;             /*   PSC4D      */
                    unsigned char PSC4C:1;             /*   PSC4C      */
                    unsigned char PSC4B:1;             /*   PSC4B      */
                    unsigned char PSC4A:1;             /*   PSC4A      */
                    } BIT;                             /*              */
             } PSCR4;                                  /*              */
};                                                     /*              */
struct st_atuii0 {                                     /* struct ATU-II0*/
       unsigned int     ICR0D;                         /* ICR0D        */
       union {                                         /* ITVRR1       */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char ITVA9:1;             /*   ITVA9      */
                    unsigned char ITVA8:1;             /*   ITVA8      */
                    unsigned char ITVA7:1;             /*   ITVA7      */
                    unsigned char ITVA6:1;             /*   ITVA6      */
                    unsigned char ITVE9:1;             /*   ITVE9      */
                    unsigned char ITVE8:1;             /*   ITVE8      */
                    unsigned char ITVE7:1;             /*   ITVE7      */
                    unsigned char TIVE6:1;             /*   TIVE6      */
                    } BIT;                             /*              */
             } ITVRR1;                                 /*              */
       unsigned char wk0[1];                           /*              */
       union {                                         /* ITVRR2A      */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char ITVA13A:1;           /*   ITVA13A    */
                    unsigned char ITVA12A:1;           /*   ITVA12A    */
                    unsigned char ITVA11A:1;           /*   ITVA11A    */
                    unsigned char ITVA10A:1;           /*   ITVA10A    */
                    unsigned char ITVE13A:1;           /*   ITVE13A    */
                    unsigned char ITVE12A:1;           /*   ITVE12A    */
                    unsigned char ITVE11A:1;           /*   ITVE11A    */
                    unsigned char ITVE10A:1;           /*   ITVE10A    */
                    } BIT;                             /*              */
             } ITVRR2A;                                /*              */
       unsigned char wk1[1];                           /*              */
       union {                                         /* ITVRR2B      */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char ITVA13B:1;           /*   ITVA13B    */
                    unsigned char ITVA12B:1;           /*   ITVA12B    */
                    unsigned char ITVA11B:1;           /*   ITVA11B    */
                    unsigned char ITVA10B:1;           /*   ITVA10B    */
                    unsigned char ITVE13B:1;           /*   ITVE13B    */
                    unsigned char ITVE12B:1;           /*   ITVE12B    */
                    unsigned char ITVE11B:1;           /*   ITVE11B    */
                    unsigned char ITVE10B:1;           /*   ITVE10B    */
                    } BIT;                             /*              */
             } ITVRR2B;                                /*              */
       unsigned char wk2[1];                           /*              */
       union {                                         /* TIOR0        */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char IO0D:2;              /*   IO0D       */
                    unsigned char IO0C:2;              /*   IO0C       */
                    unsigned char IO0B:2;              /*   IO0B       */
                    unsigned char IO0A:2;              /*   IO0A       */
                    } BIT;                             /*              */
             } TIOR0;                                  /*              */
       unsigned char wk3[1];                           /*              */
       union {                                         /* TSR0         */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short :8;                 /*              */
                    unsigned short IIF2B:1;            /*   IIF2B      */
                    unsigned short IIF2A:1;            /*   IIF2A      */
                    unsigned short IIF1:1;             /*   IIF1       */
                    unsigned short OVF0:1;             /*   OVF0       */
                    unsigned short ICF0D:1;            /*   ICF0D      */
                    unsigned short ICF0C:1;            /*   ICF0C      */
                    unsigned short ICF0B:1;            /*   ICF0B      */
                    unsigned short ICF0A:1;            /*   ICF0A      */
                    } BIT;                             /*              */
             } TSR0;                                   /*              */
       union {                                         /* TIER0        */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short :11;                /*              */
                    unsigned short OVE0:1;             /*   OVE0       */
                    unsigned short ICE0D:1;            /*   ICE0D      */
                    unsigned short ICE0C:1;            /*   ICE0C      */
                    unsigned short ICE0B:1;            /*   ICE0B      */
                    unsigned short ICE0A:1;            /*   ICE0A      */
                    } BIT;                             /*              */
             } TIER0;                                  /*              */
       unsigned int     TCNT0;                         /* TCNT0        */
       unsigned int     ICR0A;                         /* ICR0A        */
       unsigned int     ICR0B;                         /* ICR0B        */
       unsigned int     ICR0C;                         /* ICR0C        */
};                                                     /*              */
struct st_atuii1 {                                     /* struct ATU-II1*/
       unsigned short TCNT1A;                          /* TCNT1A       */
       unsigned short TCNT1B;                          /* TCNT1B       */
       unsigned short GR1A;                            /* GR1A         */
       unsigned short GR1B;                            /* GR1B         */
       unsigned short GR1C;                            /* GR1C         */
       unsigned short GR1D;                            /* GR1D         */
       unsigned short GR1E;                            /* GR1E         */
       unsigned short GR1F;                            /* GR1F         */
       unsigned short GR1G;                            /* GR1G         */
       unsigned short GR1H;                            /* GR1H         */
       unsigned short OCR1;                            /* OCR1         */
       unsigned short OSBR1;                           /* OSBR1        */
       union {                                         /* TIOR1B       */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char :1;                  /*              */
                    unsigned char IO1D:3;              /*   IO1D       */
                    unsigned char :1;                  /*              */
                    unsigned char IO1C:3;              /*   IO1C       */
                    } BIT;                             /*              */
             } TIOR1B;                                 /*              */
       union {                                         /* TIOR1A       */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char :1;                  /*              */
                    unsigned char IO1B:3;              /*   IO1B       */
                    unsigned char :1;                  /*              */
                    unsigned char IO1A:3;              /*   IO1A       */
                    } BIT;                             /*              */
             } TIOR1A;                                 /*              */
       union {                                         /* TIOR1D       */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char :1;                  /*              */
                    unsigned char IO1H:3;              /*   IO1H       */
                    unsigned char :1;                  /*              */
                    unsigned char IO1G:3;              /*   IO1G       */
                    } BIT;                             /*              */
             } TIOR1D;                                 /*              */
       union {                                         /* TIOR1C       */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char :1;                  /*              */
                    unsigned char IO1F:3;              /*   IO1F       */
                    unsigned char :1;                  /*              */
                    unsigned char IO1E:3;              /*   IO1E       */
                    } BIT;                             /*              */
             } TIOR1C;                                 /*              */
       union {                                         /* TCR1B        */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char :2;                  /*              */
                    unsigned char CKEGB:2;             /*   CKEGB      */
                    unsigned char CKSELB:4;            /*   CKSELB     */
                    } BIT;                             /*              */
             } TCR1B;                                  /*              */
       union {                                         /* TCR1A        */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char :2;                  /*              */
                    unsigned char CKEGA:2;             /*   CKEGA      */
                    unsigned char CKSELA:4;            /*   CKSELA     */
                    } BIT;                             /*              */
             } TCR1A;                                  /*              */
       union {                                         /* TSR1A        */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short :7;                 /*              */
                    unsigned short OVF1A:1;            /*   OVF1A      */
                    unsigned short IMF1H:1;            /*   IMF1H      */
                    unsigned short IMF1G:1;            /*   IMF1G      */
                    unsigned short IMF1F:1;            /*   IMF1F      */
                    unsigned short IMF1E:1;            /*   IMF1E      */
                    unsigned short IMF1D:1;            /*   IMF1D      */
                    unsigned short IMF1C:1;            /*   IMF1C      */
                    unsigned short IMF1B:1;            /*   IMF1B      */
                    unsigned short IMF1A:1;            /*   IMF1A      */
                    } BIT;                             /*              */
             } TSR1A;                                  /*              */
       union {                                         /* TSR1B        */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short :7;                 /*              */
                    unsigned short OVF1B:1;            /*   OVF1B      */
                    unsigned short :7;                 /*              */
                    unsigned short CMF1:1;             /*   CMF1       */
                    } BIT;                             /*              */
             } TSR1B;                                  /*              */
       union {                                         /* TIER1A       */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short :7;                 /*              */
                    unsigned short OVE1A:1;            /*   OVE1A      */
                    unsigned short IME1H:1;            /*   IME1H      */
                    unsigned short IME1G:1;            /*   IME1G      */
                    unsigned short IME1F:1;            /*   IME1F      */
                    unsigned short IME1E:1;            /*   IME1E      */
                    unsigned short IME1D:1;            /*   IME1D      */
                    unsigned short IME1C:1;            /*   IME1C      */
                    unsigned short IME1B:1;            /*   IME1B      */
                    unsigned short IME1A:1;            /*   IME1A      */
                    } BIT;                             /*              */
             } TIER1A;                                 /*              */
       union {                                         /* TIER1B       */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short :7;                 /*              */
                    unsigned short OVE1B:1;            /*   OVE1B      */
                    unsigned short :7;                 /*              */
                    unsigned short CME1:1;             /*   CME1       */
                    } BIT;                             /*              */
             } TIER1B;                                 /*              */
       union {                                         /* TRGMDR       */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char TRGMD:1;             /*   TRGMD      */
                    unsigned char :7;                  /*              */
                    } BIT;                             /*              */
             } TRGMDR;                                 /*              */
};                                                     /*              */
struct st_atuii2 {                                     /* struct ATU-II2*/
       unsigned short TCNT2A;                          /* TCNT2A       */
       unsigned short TCNT2B;                          /* TCNT2B       */
       unsigned short GR2A;                            /* GR2A         */
       unsigned short GR2B;                            /* GR2B         */
       unsigned short GR2C;                            /* GR2C         */
       unsigned short GR2D;                            /* GR2D         */
       unsigned short GR2E;                            /* GR2E         */
       unsigned short GR2F;                            /* GR2F         */
       unsigned short GR2G;                            /* GR2G         */
       unsigned short GR2H;                            /* GR2H         */
       unsigned short OCR2A;                           /* OCR2A        */
       unsigned short OCR2B;                           /* OCR2B        */
       unsigned short OCR2C;                           /* OCR2C        */
       unsigned short OCR2D;                           /* OCR2D        */
       unsigned short OCR2E;                           /* OCR2E        */
       unsigned short OCR2F;                           /* OCR2F        */
       unsigned short OCR2G;                           /* OCR2G        */
       unsigned short OCR2H;                           /* OCR2H        */
       unsigned short OSBR2;                           /* OSBR2        */
       union {                                         /* TIOR2B       */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char :1;                  /*              */
                    unsigned char IO2D:3;              /*   IO2D       */
                    unsigned char :1;                  /*              */
                    unsigned char IO2C:3;              /*   IO2C       */
                    } BIT;                             /*              */
             } TIOR2B;                                 /*              */
       union {                                         /* TIOR2A       */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char :1;                  /*              */
                    unsigned char IO2B:3;              /*   IO2B       */
                    unsigned char :1;                  /*              */
                    unsigned char IO2A:3;              /*   IO2A       */
                    } BIT;                             /*              */
             } TIOR2A;                                 /*              */
       union {                                         /* TIOR2D       */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char :1;                  /*              */
                    unsigned char IO2H:3;              /*   IO2H       */
                    unsigned char :1;                  /*              */
                    unsigned char IO2G:3;              /*   IO2G       */
                    } BIT;                             /*              */
             } TIOR2D;                                 /*              */
       union {                                         /* TIOR2C       */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char :1;                  /*              */
                    unsigned char IO2F:3;              /*   IO2F       */
                    unsigned char :1;                  /*              */
                    unsigned char IO2E:3;              /*   IO2E       */
                    } BIT;                             /*              */
             } TIOR2C;                                 /*              */
       union {                                         /* TCR2B        */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char :2;                  /*              */
                    unsigned char CKEGB:2;             /*   CKEGB      */
                    unsigned char CKSELB:4;            /*   CKSELB     */
                    } BIT;                             /*              */
             } TCR2B;                                  /*              */
       union {                                         /* TCR2A        */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char :2;                  /*              */
                    unsigned char CKEGA:2;             /*   CKEGA      */
                    unsigned char CKSELA:4;            /*   CKSELA     */
                    } BIT;                             /*              */
             } TCR2A;                                  /*              */
       union {                                         /* TSR2A        */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short :7;                 /*              */
                    unsigned short OVF2A:1;            /*   OVF2A      */
                    unsigned short IMF2H:1;            /*   IMF2H      */
                    unsigned short IMF2G:1;            /*   IMF2G      */
                    unsigned short IMF2F:1;            /*   IMF2F      */
                    unsigned short IMF2E:1;            /*   IMF2E      */
                    unsigned short IMF2D:1;            /*   IMF2D      */
                    unsigned short IMF2C:1;            /*   IMF2C      */
                    unsigned short IMF2B:1;            /*   IMF2B      */
                    unsigned short IMF2A:1;            /*   IMF2A      */
                    } BIT;                             /*              */
             } TSR2A;                                  /*              */
       union {                                         /* TSR2B        */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short :7;                 /*              */
                    unsigned short OVF2B:1;            /*   OVF2B      */
                    unsigned short CMF2H:1;            /*   CMF2H      */
                    unsigned short CMF2G:1;            /*   CMF2G      */
                    unsigned short CMF2F:1;            /*   CMF2F      */
                    unsigned short CMF2E:1;            /*   CMF2E      */
                    unsigned short CMF2D:1;            /*   CMF2D      */
                    unsigned short CMF2C:1;            /*   CMF2C      */
                    unsigned short CMF2B:1;            /*   CMF2B      */
                    unsigned short CMF2A:1;            /*   CMF2A      */
                    } BIT;                             /*              */
             } TSR2B;                                  /*              */
       union {                                         /* TIER2A       */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short :7;                 /*              */
                    unsigned short OVE2A:1;            /*   OVE2A      */
                    unsigned short IME2H:1;            /*   IME2H      */
                    unsigned short IME2G:1;            /*   IME2G      */
                    unsigned short IME2F:1;            /*   IME2F      */
                    unsigned short IME2E:1;            /*   IME2E      */
                    unsigned short IME2D:1;            /*   IME2D      */
                    unsigned short IME2C:1;            /*   IME2C      */
                    unsigned short IME2B:1;            /*   IME2B      */
                    unsigned short IME2A:1;            /*   IME2A      */
                    } BIT;                             /*              */
             } TIER2A;                                 /*              */
       union {                                         /* TIER2B       */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short :7;                 /*              */
                    unsigned short OVE2B:1;            /*   OVE2B      */
                    unsigned short CME2H:1;            /*   CME2H      */
                    unsigned short CME2G:1;            /*   CME2G      */
                    unsigned short CME2F:1;            /*   CME2F      */
                    unsigned short CME2E:1;            /*   CME2E      */
                    unsigned short CME2D:1;            /*   CME2D      */
                    unsigned short CME2C:1;            /*   CME2C      */
                    unsigned short CME2B:1;            /*   CME2B      */
                    unsigned short CME2A:1;            /*   CME2A      */
                    } BIT;                             /*              */
             } TIER2B;                                 /*              */
};                                                     /*              */
struct st_atuii345 {                                   /* struct ATU-II345*/
       union {                                         /* TSR3         */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short :1;                 /*              */
                    unsigned short OVF5:1;             /*   OVF5       */
                    unsigned short IMF5D:1;            /*   IMF5D      */
                    unsigned short IMF5C:1;            /*   IMF5C      */
                    unsigned short IMF5B:1;            /*   IMF5B      */
                    unsigned short IMF5A:1;            /*   IMF5A      */
                    unsigned short OVF4:1;             /*   OVF4       */
                    unsigned short IMF4D:1;            /*   IMF4D      */
                    unsigned short IMF4C:1;            /*   IMF4C      */
                    unsigned short IMF4B:1;            /*   IMF4B      */
                    unsigned short IMF4A:1;            /*   IMF4A      */
                    unsigned short OVF3:1;             /*   OVF3       */
                    unsigned short IMF3D:1;            /*   IMF3D      */
                    unsigned short IMF3C:1;            /*   IMF3C      */
                    unsigned short IMF3B:1;            /*   IMF3B      */
                    unsigned short IMF3A:1;            /*   IMF3A      */
                    } BIT;                             /*              */
             } TSR3;                                   /*              */
       union {                                         /* TIER3        */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short :1;                 /*              */
                    unsigned short OVE5:1;             /*   OVE5       */
                    unsigned short IME5D:1;            /*   IME5D      */
                    unsigned short IME5C:1;            /*   IME5C      */
                    unsigned short IME5B:1;            /*   IME5B      */
                    unsigned short IME5A:1;            /*   IME5A      */
                    unsigned short OVE4:1;             /*   OVE4       */
                    unsigned short IME4D:1;            /*   IME4D      */
                    unsigned short IME4C:1;            /*   IME4C      */
                    unsigned short IME4B:1;            /*   IME4B      */
                    unsigned short IME4A:1;            /*   IME4A      */
                    unsigned short OVE3:1;             /*   OVE3       */
                    unsigned short IME3D:1;            /*   IME3D      */
                    unsigned short IME3C:1;            /*   IME3C      */
                    unsigned short IME3B:1;            /*   IME3B      */
                    unsigned short IME3A:1;            /*   IME3A      */
                    } BIT;                             /*              */
             } TIER3;                                  /*              */
       union {                                         /* TMDR         */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char :5;                  /*              */
                    unsigned char T5PWM:1;             /*   T5PWM      */
                    unsigned char T4PWM:1;             /*   T4PWM      */
                    unsigned char T3PWM:1;             /*   T3PWM      */
                    } BIT;                             /*              */
             } TMDR;                                   /*              */
};                                                     /*              */
struct st_atuii3 {                                     /* struct ATU-II3*/
       unsigned short TCNT3;                           /* TCNT3        */
       unsigned short GR3A;                            /* GR3A         */
       unsigned short GR3B;                            /* GR3B         */
       unsigned short GR3C;                            /* GR3C         */
       unsigned short GR3D;                            /* GR3D         */
       union {                                         /* TIOR3B       */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char CCI3D:1;             /*   CCI3D      */
                    unsigned char IO3D:3;              /*   IO3D       */
                    unsigned char CCI3C:1;             /*   CCI3C      */
                    unsigned char IO3C:3;              /*   IO3C       */
                    } BIT;                             /*              */
             } TIOR3B;                                 /*              */
       union {                                         /* TIOR3A       */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char CCI3B:1;             /*   CCI3B      */
                    unsigned char IO3B:3;              /*   IO3B       */
                    unsigned char CCI3A:1;             /*   CCI3A      */
                    unsigned char IO3A:3;              /*   IO3A       */
                    } BIT;                             /*              */
             } TIOR3A;                                 /*              */
       union {                                         /* TCR3         */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char :2;                  /*              */
                    unsigned char CKEG:2;              /*   CKEG       */
                    unsigned char CKSEL:4;             /*   CKSEL      */
                    } BIT;                             /*              */
             } TCR3;                                   /*              */
};                                                     /*              */
struct st_atuii4 {                                     /* struct ATU-II4*/
       unsigned short TCNT4;                           /* TCNT4        */
       unsigned short GR4A;                            /* GR4A         */
       unsigned short GR4B;                            /* GR4B         */
       unsigned short GR4C;                            /* GR4C         */
       unsigned short GR4D;                            /* GR4D         */
       union {                                         /* TIOR4B       */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char CCI4D:1;             /*   CCI4D      */
                    unsigned char IO4D:3;              /*   IO4D       */
                    unsigned char CCI4C:1;             /*   CCI4C      */
                    unsigned char IO4C:3;              /*   IO4C       */
                    } BIT;                             /*              */
             } TIOR4B;                                 /*              */
       union {                                         /* TIOR4A       */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char CCI4B:1;             /*   CCI4B      */
                    unsigned char IO4B:3;              /*   IO4B       */
                    unsigned char CCI4A:1;             /*   CCI4A      */
                    unsigned char IO4A:3;              /*   IO4A       */
                    } BIT;                             /*              */
             } TIOR4A;                                 /*              */
       union {                                         /* TCR4         */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char :2;                  /*              */
                    unsigned char CKEG:2;              /*   CKEG       */
                    unsigned char CKSEL:4;             /*   CKSEL      */
                    } BIT;                             /*              */
             } TCR4;                                   /*              */
};                                                     /*              */
struct st_atuii5 {                                     /* struct ATU-II5*/
       unsigned short TCNT5;                           /* TCNT5        */
       unsigned short GR5A;                            /* GR5A         */
       unsigned short GR5B;                            /* GR5B         */
       unsigned short GR5C;                            /* GR5C         */
       unsigned short GR5D;                            /* GR5D         */
       union {                                         /* TIOR5B       */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char CCI5D:1;             /*   CCI5D      */
                    unsigned char IO5D:3;              /*   IO5D       */
                    unsigned char CCI5C:1;             /*   CCI5C      */
                    unsigned char IO5C:3;              /*   IO5C       */
                    } BIT;                             /*              */
             } TIOR5B;                                 /*              */
       union {                                         /* TIOR5A       */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char CCI5B:1;             /*   CCI5B      */
                    unsigned char IO5B:3;              /*   IO5B       */
                    unsigned char CCI5A:1;             /*   CCI5A      */
                    unsigned char IO5A:3;              /*   IO5A       */
                    } BIT;                             /*              */
             } TIOR5A;                                 /*              */
       union {                                         /* TCR5         */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char :2;                  /*              */
                    unsigned char CKEG:2;              /*   CKEG       */
                    unsigned char CKSEL:4;             /*   CKSEL      */
                    } BIT;                             /*              */
             } TCR5;                                   /*              */
};                                                     /*              */
struct st_atuii6 {                                     /* struct ATU-II6*/
       unsigned short TCNT6A;                          /* TCNT6A       */
       unsigned short TCNT6B;                          /* TCNT6B       */
       unsigned short TCNT6C;                          /* TCNT6C       */
       unsigned short TCNT6D;                          /* TCNT6D       */
       unsigned short CYLR6A;                          /* CYLR6A       */
       unsigned short CYLR6B;                          /* CYLR6B       */
       unsigned short CYLR6C;                          /* CYLR6C       */
       unsigned short CYLR6D;                          /* CYLR6D       */
       unsigned short BFR6A;                           /* BFR6A        */
       unsigned short BFR6B;                           /* BFR6B        */
       unsigned short BFR6C;                           /* BFR6C        */
       unsigned short BFR6D;                           /* BFR6D        */
       unsigned short DTR6A;                           /* DTR6A        */
       unsigned short DTR6B;                           /* DTR6B        */
       unsigned short DTR6C;                           /* DTR6C        */
       unsigned short DTR6D;                           /* DTR6D        */
       union {                                         /* TCR6B        */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char :1;                  /*              */
                    unsigned char CKSELD:3;            /*   CKSELD     */
                    unsigned char :1;                  /*              */
                    unsigned char CKSELC:3;            /*   CKSELC     */
                    } BIT;                             /*              */
             } TCR6B;                                  /*              */
       union {                                         /* TCR6A        */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char :1;                  /*              */
                    unsigned char CKSELB:3;            /*   CKSELB     */
                    unsigned char :1;                  /*              */
                    unsigned char CKSELA:3;            /*   CKSELA     */
                    } BIT;                             /*              */
             } TCR6A;                                  /*              */
       union {                                         /* TSR6         */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short :8;                 /*              */
                    unsigned short UD6D:1;             /*   UD6D       */
                    unsigned short UD6C:1;             /*   UD6C       */
                    unsigned short UD6B:1;             /*   UD6B       */
                    unsigned short UD6A:1;             /*   UD6A       */
                    unsigned short CMF6D:1;            /*   CMF6D      */
                    unsigned short CMF6C:1;            /*   CMF6C      */
                    unsigned short CMF6B:1;            /*   CMF6B      */
                    unsigned short CMF6A:1;            /*   CMF6A      */
                    } BIT;                             /*              */
             } TSR6;                                   /*              */
       union {                                         /* TIER6        */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short :12;                /*              */
                    unsigned short CME6D:1;            /*   CME6D      */
                    unsigned short CME6C:1;            /*   CME6C      */
                    unsigned short CME6B:1;            /*   CME6B      */
                    unsigned short CME6A:1;            /*   CME6A      */
                    } BIT;                             /*              */
             } TIER6;                                  /*              */
       union {                                         /* PMDR         */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char DTSELD:1;            /*   DTSELD     */
                    unsigned char DTSELC:1;            /*   DTSELC     */
                    unsigned char DTSELB:1;            /*   DTSELB     */
                    unsigned char DTSELA:1;            /*   DTSELA     */
                    unsigned char CNTSELD:1;           /*   CNTSELD    */
                    unsigned char CNTSELC:1;           /*   CNTSELC    */
                    unsigned char CNTSELB:1;           /*   CNTSELB    */
                    unsigned char CNTSELA:1;           /*   CNTSELA    */
                    } BIT;                             /*              */
             } PMDR;                                   /*              */
};                                                     /*              */
struct st_atuii7 {                                     /* struct ATU-II7*/
       unsigned short TCNT7A;                          /* TCNT7A       */
       unsigned short TCNT7B;                          /* TCNT7B       */
       unsigned short TCNT7C;                          /* TCNT7C       */
       unsigned short TCNT7D;                          /* TCNT7D       */
       unsigned short CYLR7A;                          /* CYLR7A       */
       unsigned short CYLR7B;                          /* CYLR7B       */
       unsigned short CYLR7C;                          /* CYLR7C       */
       unsigned short CYLR7D;                          /* CYLR7D       */
       unsigned short BFR7A;                           /* BFR7A        */
       unsigned short BFR7B;                           /* BFR7B        */
       unsigned short BFR7C;                           /* BFR7C        */
       unsigned short BFR7D;                           /* BFR7D        */
       unsigned short DTR7A;                           /* DTR7A        */
       unsigned short DTR7B;                           /* DTR7B        */
       unsigned short DTR7C;                           /* DTR7C        */
       unsigned short DTR7D;                           /* DTR7D        */
       union {                                         /* TCR7B        */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char :1;                  /*              */
                    unsigned char CKSELD:3;            /*   CKSELD     */
                    unsigned char :1;                  /*              */
                    unsigned char CKSELC:3;            /*   CKSELC     */
                    } BIT;                             /*              */
             } TCR7B;                                  /*              */
       union {                                         /* TCR7A        */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char :1;                  /*              */
                    unsigned char CKSELB:3;            /*   CKSELB     */
                    unsigned char :1;                  /*              */
                    unsigned char CKSELA:3;            /*   CKSELA     */
                    } BIT;                             /*              */
             } TCR7A;                                  /*              */
       union {                                         /* TSR7         */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short :12;                /*              */
                    unsigned short CMF7D:1;            /*   CMF7D      */
                    unsigned short CMF7C:1;            /*   CMF7C      */
                    unsigned short CMF7B:1;            /*   CMF7B      */
                    unsigned short CMF7A:1;            /*   CMF7A      */
                    } BIT;                             /*              */
             } TSR7;                                   /*              */
       union {                                         /* TIER7        */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short :12;                /*              */
                    unsigned short CME7D:1;            /*   CME7D      */
                    unsigned short CME7C:1;            /*   CME7C      */
                    unsigned short CME7B:1;            /*   CME7B      */
                    unsigned short CME7A:1;            /*   CME7A      */
                    } BIT;                             /*              */
             } TIER7;                                  /*              */
};                                                     /*              */
struct st_atuii8 {                                     /* struct ATU-II8*/
       unsigned short DCNT8A;                          /* DCNT8A       */
       unsigned short DCNT8B;                          /* DCNT8B       */
       unsigned short DCNT8C;                          /* DCNT8C       */
       unsigned short DCNT8D;                          /* DCNT8D       */
       unsigned short DCNT8E;                          /* DCNT8E       */
       unsigned short DCNT8F;                          /* DCNT8F       */
       unsigned short DCNT8G;                          /* DCNT8G       */
       unsigned short DCNT8H;                          /* DCNT8H       */
       unsigned short DCNT8I;                          /* DCNT8I       */
       unsigned short DCNT8J;                          /* DCNT8J       */
       unsigned short DCNT8K;                          /* DCNT8K       */
       unsigned short DCNT8L;                          /* DCNT8L       */
       unsigned short DCNT8M;                          /* DCNT8M       */
       unsigned short DCNT8N;                          /* DCNT8N       */
       unsigned short DCNT8O;                          /* DCNT8O       */
       unsigned short DCNT8P;                          /* DCNT8P       */
       unsigned short RLDR8;                           /* RLDR8        */
       union {                                         /* TCNR         */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short CN8P:1;             /*   CN8P       */
                    unsigned short CN8O:1;             /*   CN8O       */
                    unsigned short CN8N:1;             /*   CN8N       */
                    unsigned short CN8M:1;             /*   CN8M       */
                    unsigned short CN8L:1;             /*   CN8L       */
                    unsigned short CN8K:1;             /*   CN8K       */
                    unsigned short CN8J:1;             /*   CN8J       */
                    unsigned short CN8I:1;             /*   CN8I       */
                    unsigned short CN8H:1;             /*   CN8H       */
                    unsigned short CN8G:1;             /*   CN8G       */
                    unsigned short CN8F:1;             /*   CN8F       */
                    unsigned short CN8E:1;             /*   CN8E       */
                    unsigned short CN8D:1;             /*   CN8D       */
                    unsigned short CN8C:1;             /*   CN8C       */
                    unsigned short CN8B:1;             /*   CN8B       */
                    unsigned short CN8A:1;             /*   CN8A       */
                    } BIT;                             /*              */
             } TCNR;                                   /*              */
       union {                                         /* OTR          */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short OTEP:1;             /*   OTEP       */
                    unsigned short OTEO:1;             /*   OTEO       */
                    unsigned short OTEN:1;             /*   OTEN       */
                    unsigned short OTEM:1;             /*   OTEM       */
                    unsigned short OTEL:1;             /*   OTEL       */
                    unsigned short OTEK:1;             /*   OTEK       */
                    unsigned short OTEJ:1;             /*   OTEJ       */
                    unsigned short OTEI:1;             /*   OTEI       */
                    unsigned short OTEH:1;             /*   OTEH       */
                    unsigned short OTEG:1;             /*   OTEG       */
                    unsigned short OTEF:1;             /*   OTEF       */
                    unsigned short OTEE:1;             /*   OTEE       */
                    unsigned short OTED:1;             /*   OTED       */
                    unsigned short OTEC:1;             /*   OTEC       */
                    unsigned short OTEB:1;             /*   OTEB       */
                    unsigned short OTEA:1;             /*   OTEA       */
                    } BIT;                             /*              */
             } OTR;                                    /*              */
       union {                                         /* DSTR         */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short DST8P:1;            /*   DST8P      */
                    unsigned short DST8O:1;            /*   DST8O      */
                    unsigned short DST8N:1;            /*   DST8N      */
                    unsigned short DST8M:1;            /*   DST8M      */
                    unsigned short DST8L:1;            /*   DST8L      */
                    unsigned short DST8K:1;            /*   DST8K      */
                    unsigned short DST8J:1;            /*   DST8J      */
                    unsigned short DST8I:1;            /*   DST8I      */
                    unsigned short DST8H:1;            /*   DST8H      */
                    unsigned short DST8G:1;            /*   DST8G      */
                    unsigned short DST8F:1;            /*   DST8F      */
                    unsigned short DST8E:1;            /*   DST8E      */
                    unsigned short DST8D:1;            /*   DST8D      */
                    unsigned short DST8C:1;            /*   DST8C      */
                    unsigned short DST8B:1;            /*   DST8B      */
                    unsigned short DST8A:1;            /*   DST8A      */
                    } BIT;                             /*              */
             } DSTR;                                   /*              */
       union {                                         /* TCR8         */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char :1;                  /*              */
                    unsigned char CKSELB:3;            /*   CKSELB     */
                    unsigned char :1;                  /*              */
                    unsigned char CKSELA:3;            /*   CKSELA     */
                    } BIT;                             /*              */
             } TCR8;                                   /*              */
       unsigned char wk0[1];                           /*              */
       union {                                         /* TSR8         */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short OSF8P:1;            /*   OSF8P      */
                    unsigned short OSF8O:1;            /*   OSF8O      */
                    unsigned short OSF8N:1;            /*   OSF8N      */
                    unsigned short OSF8M:1;            /*   OSF8M      */
                    unsigned short OSF8L:1;            /*   OSF8L      */
                    unsigned short OSF8K:1;            /*   OSF8K      */
                    unsigned short OSF8J:1;            /*   OSF8J      */
                    unsigned short OSF8I:1;            /*   OSF8I      */
                    unsigned short OSF8H:1;            /*   OSF8H      */
                    unsigned short OSF8G:1;            /*   OSF8G      */
                    unsigned short OSF8F:1;            /*   OSF8F      */
                    unsigned short OSF8E:1;            /*   OSF8E      */
                    unsigned short OSF8D:1;            /*   OSF8D      */
                    unsigned short OSF8C:1;            /*   OSF8C      */
                    unsigned short OSF8B:1;            /*   OSF8B      */
                    unsigned short OSF8A:1;            /*   OSF8A      */
                    } BIT;                             /*              */
             } TSR8;                                   /*              */
       union {                                         /* TIER8        */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short OSE8P:1;            /*   OSE8P      */
                    unsigned short OSE8O:1;            /*   OSE8O      */
                    unsigned short OSE8N:1;            /*   OSE8N      */
                    unsigned short OSE8M:1;            /*   OSE8M      */
                    unsigned short OSE8L:1;            /*   OSE8L      */
                    unsigned short OSE8K:1;            /*   OSE8K      */
                    unsigned short OSE8J:1;            /*   OSE8J      */
                    unsigned short OSE8I:1;            /*   OSE8I      */
                    unsigned short OSE8H:1;            /*   OSE8H      */
                    unsigned short OSE8G:1;            /*   OSE8G      */
                    unsigned short OSE8F:1;            /*   OSE8F      */
                    unsigned short OSE8E:1;            /*   OSE8E      */
                    unsigned short OSE8D:1;            /*   OSE8D      */
                    unsigned short OSE8C:1;            /*   OSE8C      */
                    unsigned short OSE8B:1;            /*   OSE8B      */
                    unsigned short OSE8A:1;            /*   OSE8A      */
                    } BIT;                             /*              */
             } TIER8;                                  /*              */
       union {                                         /* RLDENR       */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char RLDEN:1;             /*   RLDEN      */
                    unsigned char :7;                  /*              */
                    } BIT;                             /*              */
             } RLDENR;                                 /*              */
};                                                     /*              */
struct st_atuii9 {                                     /* struct ATU-II9*/
       unsigned char ECNT9A;                           /* ECNT9A       */
       unsigned char wk0[1];                           /*              */
       unsigned char ECNT9B;                           /* ECNT9B       */
       unsigned char wk1[1];                           /*              */
       unsigned char ECNT9C;                           /* ECNT9C       */
       unsigned char wk2[1];                           /*              */
       unsigned char ECNT9D;                           /* ECNT9D       */
       unsigned char wk3[1];                           /*              */
       unsigned char ECNT9E;                           /* ECNT9E       */
       unsigned char wk4[1];                           /*              */
       unsigned char ECNT9F;                           /* ECNT9F       */
       unsigned char wk5[1];                           /*              */
       unsigned char GR9A;                             /* GR9A         */
       unsigned char wk6[1];                           /*              */
       unsigned char GR9B;                             /* GR9B         */
       unsigned char wk7[1];                           /*              */
       unsigned char GR9C;                             /* GR9C         */
       unsigned char wk8[1];                           /*              */
       unsigned char GR9D;                             /* GR9D         */
       unsigned char wk9[1];                           /*              */
       unsigned char GR9E;                             /* GR9E         */
       unsigned char wk10[1];                          /*              */
       unsigned char GR9F;                             /* GR9F         */
       unsigned char wk11[1];                          /*              */
       union {                                         /* TCR9A        */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char :1;                  /*              */
                    unsigned char TRG3BEN:1;           /*   TRG3BEN    */
                    unsigned char EGSELB:2;            /*   EGSELB     */
                    unsigned char :1;                  /*              */
                    unsigned char TRG3AEN:1;           /*   TRG3AEN    */
                    unsigned char EGSELA:2;            /*   EGSELA     */
                    } BIT;                             /*              */
             } TCR9A;                                  /*              */
       unsigned char wk12[1];                          /*              */
       union {                                         /* TCR9B        */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char :1;                  /*              */
                    unsigned char TRG3DEN:1;           /*   TRG3DEN    */
                    unsigned char EGSELD:2;            /*   EGSELD     */
                    unsigned char :1;                  /*              */
                    unsigned char TRG3CEN:1;           /*   TRG3CEN    */
                    unsigned char EGSELC:2;            /*   EGSELC     */
                    } BIT;                             /*              */
             } TCR9B;                                  /*              */
       unsigned char wk13[1];                          /*              */
       union {                                         /* TCR9C        */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char :2;                  /*              */
                    unsigned char EGSELF:2;            /*   EGSELF     */
                    unsigned char :2;                  /*              */
                    unsigned char EGSELE:2;            /*   EGSELE     */
                    } BIT;                             /*              */
             } TCR9C;                                  /*              */
       unsigned char wk14[1];                          /*              */
       union {                                         /* TSR9         */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short :10;                /*              */
                    unsigned short CMF9F:1;            /*   CMF9F      */
                    unsigned short CMF9E:1;            /*   CMF9E      */
                    unsigned short CMF9D:1;            /*   CMF9D      */
                    unsigned short CMF9C:1;            /*   CMF9C      */
                    unsigned short CMF9B:1;            /*   CMF9B      */
                    unsigned short CMF9A:1;            /*   CMF9A      */
                    } BIT;                             /*              */
             } TSR9;                                   /*              */
       union {                                         /* TIER9        */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short :10;                /*              */
                    unsigned short CME9F:1;            /*   CME9F      */
                    unsigned short CME9E:1;            /*   CME9E      */
                    unsigned short CME9D:1;            /*   CME9D      */
                    unsigned short CME9C:1;            /*   CME9C      */
                    unsigned short CME9B:1;            /*   CME9B      */
                    unsigned short CME9A:1;            /*   CME9A      */
                    } BIT;                             /*              */
             } TIER9;                                  /*              */
};                                                     /*              */
struct st_atuii10 {                                    /* struct ATU-II10*/
       unsigned int   TCNT10A;                         /* TCNT10A      */
       unsigned char TCNT10B;                          /* TCNT10B      */
       unsigned char wk0[1];                           /*              */
       unsigned short TCNT10C;                         /* TCNT10C      */
       unsigned char TCNT10D;                          /* TCNT10D      */
       unsigned char wk1[1];                           /*              */
       unsigned short TCNT10E;                         /* TCNT10E      */
       unsigned short TCNT10F;                         /* TCNT10F      */
       unsigned short TCNT10G;                         /* TCNT10G      */
       unsigned int   ICR10A;                          /* ICR10A       */
       unsigned int   OCR10A;                          /* OCR10A       */
       unsigned char OCR10B;                           /* OCR10B       */
       unsigned char wk2[1];                           /*              */
       unsigned short RLD10C;                          /* RLD10C       */
       unsigned short GR10G;                           /* GR10G        */
       unsigned char TCNT10H;                          /* TCNT10H      */
       unsigned char wk3[1];                           /*              */
       unsigned char NCR10;                            /* NCR10        */
       unsigned char wk4[1];                           /*              */
       union {                                         /* TIOR10       */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char RLDEN:1;             /*   RLDEN      */
                    unsigned char CCS:1;               /*   CCS        */
                    unsigned char PIM:2;               /*   PIM        */
                    unsigned char :1;                  /*              */
                    unsigned char IO10G:3;             /*   IO10G      */
                    } BIT;                             /*              */
             } TIOR10;                                 /*              */
       unsigned char wk5[1];                           /*              */
       union {                                         /* TCR10        */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char TRG2BEN:1;           /*   TRG2BEN    */
                    unsigned char TRG1BEN:1;           /*   TRG1BEN    */
                    unsigned char TRG2AEN:1;           /*   TRG2AEN    */
                    unsigned char TRG1AEN:1;           /*   TRG1AEN    */
                    unsigned char TRG0DEN:1;           /*   TRG0DEN    */
                    unsigned char NCE:1;               /*   NCE        */
                    unsigned char CKEG:2;              /*   CKEG       */
                    } BIT;                             /*              */
             } TCR10;                                  /*              */
       unsigned char wk6[1];                           /*              */
       unsigned short TCCLR10;                         /* TCCLR10      */
       union {                                         /* TSR10        */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short :12;                /*              */
                    unsigned short CMF10G:1;           /*   CMF10G     */
                    unsigned short CMF10B:1;           /*   CMF10B     */
                    unsigned short ICF10A:1;           /*   ICF10A     */
                    unsigned short CMF10A:1;           /*   CMF10A     */
                    } BIT;                             /*              */
             } TSR10;                                  /*              */
       union {                                         /* TIER10       */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short :11;                /*              */
                    unsigned short IREG:1;             /*   IREG       */
                    unsigned short CME10G:1;           /*   CME10G     */
                    unsigned short CME10B:1;           /*   CME10B     */
                    unsigned short ICE10A:1;           /*   ICE10A     */
                    unsigned short CME10A:1;           /*   CME10A     */
                    } BIT;                             /*              */
             } TIER10;                                 /*              */
};                                                     /*              */
struct st_atuii11 {                                    /* struct ATU-II11*/
       unsigned short TCNT11;                          /* TCNT11       */
       unsigned short GR11A;                           /* GR11A        */
       unsigned short GR11B;                           /* GR11B        */
       union {                                         /* TIOR11       */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char :1;                  /*              */
                    unsigned char IO11B:3;             /*   IO11B      */
                    unsigned char :1;                  /*              */
                    unsigned char IO11A:3;             /*   IO11A      */
                    } BIT;                             /*              */
             } TIOR11;                                 /*              */
       unsigned char wk0[1];                           /*              */
       union {                                         /* TCR11        */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char :2;                  /*              */
                    unsigned char CKEG:2;              /*   CKEG       */
                    unsigned char :1;                  /*              */
                    unsigned char CKSELA:3;            /*   CKSELA     */
                    } BIT;                             /*              */
             } TCR11;                                  /*              */
       unsigned char wk1[1];                           /*              */
       union {                                         /* TSR11        */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short :7;                 /*              */
                    unsigned short OVF11:1;            /*   OVF11      */
                    unsigned short :6;                 /*              */
                    unsigned short IMF11B:1;           /*   IMF11B     */
                    unsigned short IMF11A:1;           /*   IMF11A     */
                    } BIT;                             /*              */
             } TSR11;                                  /*              */
       union {                                         /* TIER11       */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short :7;                 /*              */
                    unsigned short OVE11:1;            /*   OVE11      */
                    unsigned short :6;                 /*              */
                    unsigned short IME11B:1;           /*   IME11B     */
                    unsigned short IME11A:1;           /*   IME11A     */
                    } BIT;                             /*              */
             } TIER11;                                 /*              */
};                                                     /*              */
struct st_apc {                                        /* struct APC   */
       union {                                         /* POPCR        */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short PULS7ROE:1;         /*   PULS7ROE   */
                    unsigned short PULS6ROE:1;         /*   PULS6ROE   */
                    unsigned short PULS5ROE:1;         /*   PULS5ROE   */
                    unsigned short PULS4ROE:1;         /*   PULS4ROE   */
                    unsigned short PULS3ROE:1;         /*   PULS3ROE   */
                    unsigned short PULS2ROE:1;         /*   PULS2ROE   */
                    unsigned short PULS1ROE:1;         /*   PULS1ROE   */
                    unsigned short PULS0ROE:1;         /*   PULS0ROE   */
                    unsigned short PULS7SOE:1;         /*   PULS7SOE   */
                    unsigned short PULS6SOE:1;         /*   PULS6SOE   */
                    unsigned short PULS5SOE:1;         /*   PULS5SOE   */
                    unsigned short PULS4SOE:1;         /*   PULS4SOE   */
                    unsigned short PULS3SOE:1;         /*   PULS3SOE   */
                    unsigned short PULS2SOE:1;         /*   PULS2SOE   */
                    unsigned short PULS1SOE:1;         /*   PULS1SOE   */
                    unsigned short PULS0SOE:1;         /*   PULS0SOE   */
                    } BIT;                             /*              */
             } POPCR;                                  /*              */
};                                                     /*              */
struct st_wdt {                                        /* struct WDT   */
       union {                                         /* TCSR         */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char OVF:1;               /*   OVF        */
                    unsigned char WTIT:1;              /*   WT/IT      */
                    unsigned char TME:1;               /*   TME        */
                    unsigned char :2;                  /*              */
                    unsigned char CKS:3;               /*   CKS        */
                    } BIT;                             /*              */
             } TCSR;                                   /*              */
       unsigned char TCNT;                             /* TCNT         */
       unsigned char wk0[1];                           /*              */
       union {                                         /* RSTCSR       */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char WOVF:1;              /*   WOVF       */
                    unsigned char RSTE:1;              /*   RSTE       */
                    unsigned char RSTS:1;              /*   RSTS       */
                    unsigned char :5;                  /*              */
                    } BIT;                             /*              */
             } RSTCSR;                                 /*              */
};                                                     /*              */
struct st_cmt {                                        /* struct CMT   */
       union {                                         /* CMSTR        */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short :14;                /*              */
                    unsigned short STR1:1;             /*   STR1       */
                    unsigned short STR0:1;             /*   STR0       */
                    } BIT;                             /*              */
             } CMSTR;                                  /*              */
       union {                                         /* CMCSR0       */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short :8;                 /*              */
                    unsigned short CMF:1;              /*   CMF        */
                    unsigned short CMIE:1;             /*   CMIE       */
                    unsigned short :4;                 /*              */
                    unsigned short CKS:2;              /*   CKS        */
                    } BIT;                             /*              */
             } CMCSR0;                                 /*              */
       unsigned short CMCNT0;                          /* CMCNT0       */
       unsigned short CMCOR0;                          /* CMCOR0       */
       union {                                         /* CMCSR1       */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short :8;                 /*              */
                    unsigned short CMF:1;              /*   CMF        */
                    unsigned short CMIE:1;             /*   CMIE       */
                    unsigned short :4;                 /*              */
                    unsigned short CKS:2;              /*   CKS        */
                    } BIT;                             /*              */
             } CMCSR1;                                 /*              */
       unsigned short CMCNT1;                          /* CMCNT1       */
       unsigned short CMCOR1;                          /* CMCOR1       */
};                                                     /*              */
struct st_sci0 {                                       /* struct SCI0  */
       union {                                         /* SMR0         */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char CA:1;                /*   C/A        */
                    unsigned char CHR:1;               /*   CHR        */
                    unsigned char PE:1;                /*   PE         */
                    unsigned char OE:1;                /*   O/E        */
                    unsigned char STOP:1;              /*   STOP       */
                    unsigned char MP:1;                /*   MP         */
                    unsigned char CKS:2;               /*   CKS        */
                    } BIT;                             /*              */
             } SMR0;                                   /*              */
       unsigned char BRR0;                             /* BRR0         */
       union {                                         /* SCR0         */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char TIE:1;               /*   TIE        */
                    unsigned char RIE:1;               /*   RIE        */
                    unsigned char TE:1;                /*   TE         */
                    unsigned char RE:1;                /*   RE         */
                    unsigned char MPIE:1;              /*   MPIE       */
                    unsigned char TEIE:1;              /*   TEIE       */
                    unsigned char CKE:2;               /*   CKE        */
                    } BIT;                             /*              */
             } SCR0;                                   /*              */
       unsigned char TDR0;                             /* TDR0         */
       union {                                         /* SSR0         */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char TDRE:1;              /*   TDRE       */
                    unsigned char RDRF:1;              /*   RDRF       */
                    unsigned char ORER:1;              /*   ORER       */
                    unsigned char FER:1;               /*   FER        */
                    unsigned char PER:1;               /*   PER        */
                    unsigned char TEND:1;              /*   TEND       */
                    unsigned char MPB:1;               /*   MPB        */
                    unsigned char MPBT:1;              /*   MPBT       */
                    } BIT;                             /*              */
             } SSR0;                                   /*              */
       unsigned char RDR0;                             /* RDR0         */
       union {                                         /* SDCR0        */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char :4;                  /*              */
                    unsigned char DIR:1;               /*   DIR        */
                    unsigned char :3;                  /*              */
                    } BIT;                             /*              */
             } SDCR0;                                  /*              */
};                                                     /*              */
struct st_sci1 {                                       /* struct SCI1  */
       union {                                         /* SMR1         */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char CA:1;                /*   C/A        */
                    unsigned char CHR:1;               /*   CHR        */
                    unsigned char PE:1;                /*   PE         */
                    unsigned char OE:1;                /*   O/E        */
                    unsigned char STOP:1;              /*   STOP       */
                    unsigned char MP:1;                /*   MP         */
                    unsigned char CKS:2;               /*   CKS        */
                    } BIT;                             /*              */
             } SMR1;                                   /*              */
       unsigned char BRR1;                             /* BRR1         */
       union {                                         /* SCR1         */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char TIE:1;               /*   TIE        */
                    unsigned char RIE:1;               /*   RIE        */
                    unsigned char TE:1;                /*   TE         */
                    unsigned char RE:1;                /*   RE         */
                    unsigned char MPIE:1;              /*   MPIE       */
                    unsigned char TEIE:1;              /*   TEIE       */
                    unsigned char CKE:2;               /*   CKE        */
                    } BIT;                             /*              */
             } SCR1;                                   /*              */
       unsigned char TDR1;                             /* TDR1         */
       union {                                         /* SSR1         */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char TDRE:1;              /*   TDRE       */
                    unsigned char RDRF:1;              /*   RDRF       */
                    unsigned char ORER:1;              /*   ORER       */
                    unsigned char FER:1;               /*   FER        */
                    unsigned char PER:1;               /*   PER        */
                    unsigned char TEND:1;              /*   TEND       */
                    unsigned char MPB:1;               /*   MPB        */
                    unsigned char MPBT:1;              /*   MPBT       */
                    } BIT;                             /*              */
             } SSR1;                                   /*              */
       unsigned char RDR1;                             /* RDR1         */
       union {                                         /* SDCR1        */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char :4;                  /*              */
                    unsigned char DIR:1;               /*   DIR        */
                    unsigned char :3;                  /*              */
                    } BIT;                             /*              */
             } SDCR1;                                  /*              */
};                                                     /*              */
struct st_sci2 {                                       /* struct SCI2  */
       union {                                         /* SMR2         */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char CA:1;                /*   C/A        */
                    unsigned char CHR:1;               /*   CHR        */
                    unsigned char PE:1;                /*   PE         */
                    unsigned char OE:1;                /*   O/E        */
                    unsigned char STOP:1;              /*   STOP       */
                    unsigned char MP:1;                /*   MP         */
                    unsigned char CKS:2;               /*   CKS        */
                    } BIT;                             /*              */
             } SMR2;                                   /*              */
       unsigned char BRR2;                             /* BRR2         */
       union {                                         /* SCR2         */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char TIE:1;               /*   TIE        */
                    unsigned char RIE:1;               /*   RIE        */
                    unsigned char TE:1;                /*   TE         */
                    unsigned char RE:1;                /*   RE         */
                    unsigned char MPIE:1;              /*   MPIE       */
                    unsigned char TEIE:1;              /*   TEIE       */
                    unsigned char CKE:2;               /*   CKE        */
                    } BIT;                             /*              */
             } SCR2;                                   /*              */
       unsigned char TDR2;                             /* TDR2         */
       union {                                         /* SSR2         */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char TDRE:1;              /*   TDRE       */
                    unsigned char RDRF:1;              /*   RDRF       */
                    unsigned char ORER:1;              /*   ORER       */
                    unsigned char FER:1;               /*   FER        */
                    unsigned char PER:1;               /*   PER        */
                    unsigned char TEND:1;              /*   TEND       */
                    unsigned char MPB:1;               /*   MPB        */
                    unsigned char MPBT:1;              /*   MPBT       */
                    } BIT;                             /*              */
             } SSR2;                                   /*              */
       unsigned char RDR2;                             /* RDR2         */
       union {                                         /* SDCR2        */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char :4;                  /*              */
                    unsigned char DIR:1;               /*   DIR        */
                    unsigned char :3;                  /*              */
                    } BIT;                             /*              */
             } SDCR2;                                  /*              */
};                                                     /*              */
struct st_sci3 {                                       /* struct SCI3  */
       union {                                         /* SMR3         */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char CA:1;                /*   C/A        */
                    unsigned char CHR:1;               /*   CHR        */
                    unsigned char PE:1;                /*   PE         */
                    unsigned char OE:1;                /*   O/E        */
                    unsigned char STOP:1;              /*   STOP       */
                    unsigned char MP:1;                /*   MP         */
                    unsigned char CKS:2;               /*   CKS        */
                    } BIT;                             /*              */
             } SMR3;                                   /*              */
       unsigned char BRR3;                             /* BRR3         */
       union {                                         /* SCR3         */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char TIE:1;               /*   TIE        */
                    unsigned char RIE:1;               /*   RIE        */
                    unsigned char TE:1;                /*   TE         */
                    unsigned char RE:1;                /*   RE         */
                    unsigned char MPIE:1;              /*   MPIE       */
                    unsigned char TEIE:1;              /*   TEIE       */
                    unsigned char CKE:2;               /*   CKE        */
                    } BIT;                             /*              */
             } SCR3;                                   /*              */
       unsigned char TDR3;                             /* TDR3         */
       union {                                         /* SSR3         */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char TDRE:1;              /*   TDRE       */
                    unsigned char RDRF:1;              /*   RDRF       */
                    unsigned char ORER:1;              /*   ORER       */
                    unsigned char FER:1;               /*   FER        */
                    unsigned char PER:1;               /*   PER        */
                    unsigned char TEND:1;              /*   TEND       */
                    unsigned char MPB:1;               /*   MPB        */
                    unsigned char MPBT:1;              /*   MPBT       */
                    } BIT;                             /*              */
             } SSR3;                                   /*              */
       unsigned char RDR3;                             /* RDR3         */
       union {                                         /* SDCR3        */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char :4;                  /*              */
                    unsigned char DIR:1;               /*   DIR        */
                    unsigned char :3;                  /*              */
                    } BIT;                             /*              */
             } SDCR3;                                  /*              */
};                                                     /*              */
struct st_sci4 {                                       /* struct SCI4  */
       union {                                         /* SMR4         */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char CA:1;                /*   C/A        */
                    unsigned char CHR:1;               /*   CHR        */
                    unsigned char PE:1;                /*   PE         */
                    unsigned char OE:1;                /*   O/E        */
                    unsigned char STOP:1;              /*   STOP       */
                    unsigned char MP:1;                /*   MP         */
                    unsigned char CKS:2;               /*   CKS        */
                    } BIT;                             /*              */
             } SMR4;                                   /*              */
       unsigned char BRR4;                             /* BRR4         */
       union {                                         /* SCR4         */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char TIE:1;               /*   TIE        */
                    unsigned char RIE:1;               /*   RIE        */
                    unsigned char TE:1;                /*   TE         */
                    unsigned char RE:1;                /*   RE         */
                    unsigned char MPIE:1;              /*   MPIE       */
                    unsigned char TEIE:1;              /*   TEIE       */
                    unsigned char CKE:2;               /*   CKE        */
                    } BIT;                             /*              */
             } SCR4;                                   /*              */
       unsigned char TDR4;                             /* TDR4         */
       union {                                         /* SSR4         */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char TDRE:1;              /*   TDRE       */
                    unsigned char RDRF:1;              /*   RDRF       */
                    unsigned char ORER:1;              /*   ORER       */
                    unsigned char FER:1;               /*   FER        */
                    unsigned char PER:1;               /*   PER        */
                    unsigned char TEND:1;              /*   TEND       */
                    unsigned char MPB:1;               /*   MPB        */
                    unsigned char MPBT:1;              /*   MPBT       */
                    } BIT;                             /*              */
             } SSR4;                                   /*              */
       unsigned char RDR4;                             /* RDR4         */
       union {                                         /* SDCR4        */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char :4;                  /*              */
                    unsigned char DIR:1;               /*   DIR        */
                    unsigned char :3;                  /*              */
                    } BIT;                             /*              */
             } SDCR4;                                  /*              */
};
struct st_ssu0 {                                       /* struct SSU0  */
       union {                                         /* SSCRH0       */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char MSS:1;               /*  MSS         */
                    unsigned char BIDE:1;              /*  BIDE        */
                    unsigned char :1;                  /*              */
                    unsigned char SOL:1;               /*  SOL         */
                    unsigned char SOLP:1;              /*  SOLP        */
                    unsigned char SCKS:1;              /*  SCKS        */
                    unsigned char CSS1:1;              /*  CSS1        */
                    unsigned char CSS0:1;              /*  CSS0        */
                    } BIT;                             /*              */
             } SSCRH0;                                 /*              */
       union {                                         /*  SSCRL0      */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char :2;                  /*              */
                    unsigned char SRES:1;              /*  SRES        */
                    unsigned char :3;                  /*              */
                    unsigned char DATS1:1;             /*  DATS1       */
                    unsigned char DATS0:1;             /*  DATS0       */
                    } BIT;                             /*              */
             } SSCRL0;                                 /*              */
       union {                                         /* SSMR0        */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char MLS:1;               /*  MLS         */
                    unsigned char CPOS:1;              /*  CPOS        */
                    unsigned char CPHS:1;              /*  CPHS        */
                    unsigned char :2;                  /*              */
                    unsigned char CKS2:1;              /*  CKS2        */
                    unsigned char CKS1:1;              /*  CKS1        */
                    unsigned char CKS0:1;              /*  CKS0        */
                    } BIT;                             /*              */
             } SSMR0;                                  /*              */
       union {                                         /* SSER0        */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char TE:1;                /*  TE          */
                    unsigned char RE:1;                /*  RE          */
                    unsigned char :2;                  /*              */
                    unsigned char TEIE:1;              /*  TEIE        */
                    unsigned char TIE:1;               /*  TIE         */
                    unsigned char RIE:1;               /*  RIE         */
                    unsigned char CEIE:1;              /*  CEIE        */
                    } BIT;                             /*              */
             } SSER0;                                  /*              */
       unsigned char SSTDR0_0;                         /* SSTDR0_0     */
       unsigned char SSTDR1_0;                         /* SSTDR1_0     */
       unsigned char SSTDR2_0;                         /* SSTDR2_0     */
       unsigned char SSTDR3_0;                         /* SSTDR3_0     */
       unsigned char SSRDR0_0;                         /* SSRDR0_0     */
       unsigned char SSRDR1_0;                         /* SSRDR1_0     */
       unsigned char SSRDR2_0;                         /* SSRDR2_0     */
       unsigned char SSRDR3_0;                         /* SSRDR3_0     */
       union {                                         /* SSSR0        */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char :1;                  /*  TE          */
                    unsigned char ORER:1;              /*  ORER        */
                    unsigned char :2;                  /*              */
                    unsigned char TEND:1;              /*  TEND        */
                    unsigned char TDRE:1;              /*  TDRE        */
                    unsigned char RDRF:1;              /*  RDRF        */
                    unsigned char CE:1;                /*  CE          */
                    } BIT;                             /*              */
             } SSSR0;                                  /*              */
};                                                     /*              */
                                                       /*              */
struct st_ssu1 {                                       /* struct SSU1  */
       union {                                         /* SSCRH1       */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char MSS:1;               /*  MSS         */
                    unsigned char BIDE:1;              /*  BIDE        */
                    unsigned char :1;                  /*              */
                    unsigned char SOL:1;               /*  SOL         */
                    unsigned char SOLP:1;              /*  SOLP        */
                    unsigned char SCKS:1;              /*  SCKS        */
                    unsigned char CSS1:1;              /*  CSS1        */
                    unsigned char CSS0:1;              /*  CSS0        */
                    } BIT;                             /*              */
             } SSCRH1;                                 /*              */
       union {                                         /*  SSCRL1      */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char :2;                  /*              */
                    unsigned char SRES:1;              /*  SRES        */
                    unsigned char :3;                  /*              */
                    unsigned char DATS1:1;             /*  DATS1       */
                    unsigned char DATS0:1;             /*  DATS0       */
                    } BIT;                             /*              */
             } SSCRL1;                                 /*              */
       union {                                         /* SSMR1        */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char MLS:1;               /*  MLS         */
                    unsigned char CPOS:1;              /*  CPOS        */
                    unsigned char CPHS:1;              /*  CPHS        */
                    unsigned char :2;                  /*              */
                    unsigned char CKS2:1;              /*  CKS2        */
                    unsigned char CKS1:1;              /*  CKS1        */
                    unsigned char CKS0:1;              /*  CKS0        */
                    } BIT;                             /*              */
             } SSMR1;                                  /*              */
       union {                                         /* SSER1        */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char TE:1;                /*  TE          */
                    unsigned char RE:1;                /*  RE          */
                    unsigned char :2;                  /*              */
                    unsigned char TEIE:1;              /*  TEIE        */
                    unsigned char TIE:1;               /*  TIE         */
                    unsigned char RIE:1;               /*  RIE         */
                    unsigned char CEIE:1;              /*  CEIE        */
                    } BIT;                             /*              */
             } SSER1;                                  /*              */
       unsigned char SSTDR0_1;                         /* SSTDR0_0     */
       unsigned char SSTDR1_1;                         /* SSTDR1_0     */
       unsigned char SSTDR2_1;                         /* SSTDR2_0     */
       unsigned char SSTDR3_1;                         /* SSTDR3_0     */
       unsigned char SSRDR0_1;                         /* SSRDR0_0     */
       unsigned char SSRDR1_1;                         /* SSRDR1_0     */
       unsigned char SSRDR2_1;                         /* SSRDR2_0     */
       unsigned char SSRDR3_1;                         /* SSRDR3_0     */
       union {                                         /* SSSR1        */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char :1;                  /*  TE          */
                    unsigned char ORER:1;              /*  ORER        */
                    unsigned char :2;                  /*              */
                    unsigned char TEND:1;              /*  TEND        */
                    unsigned char TDRE:1;              /*  TDRE        */
                    unsigned char RDRF:1;              /*  RDRF        */
                    unsigned char CE:1;                /*  CE          */
                    } BIT;                             /*              */
             } SSSR1;                                  /*              */
};                                                     /*              */
                                                       /*              */
struct st_ad {                                         /* struct A/D   */
       union {                                         /* ADTRGR1      */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char EXTRG:1;             /*   EXTRG      */
                    unsigned char :7;                  /*              */
                    } BIT;                             /*              */
             } ADTRGR1;                                /*              */
       union {                                         /* ADTRGR2      */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char EXTRG:1;             /*   EXTRG      */
                    unsigned char :7;                  /*              */
                    } BIT;                             /*              */
             } ADTRGR2;                                /*              */
       unsigned char wk0[62];                          /*              */
       union {                                         /* ADTRGR0      */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char EXTRG:1;             /*   EXTRG      */
                    unsigned char :7;                  /*              */
                    } BIT;                             /*              */
             } ADTRGR0;                                /*              */
       unsigned char wk1[145];                         /*              */
       union {                                         /* ADDR0H       */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char AD9:1;               /*   AD9        */
                    unsigned char AD8:1;               /*   AD8        */
                    unsigned char AD7:1;               /*   AD7        */
                    unsigned char AD6:1;               /*   AD6        */
                    unsigned char AD5:1;               /*   AD5        */
                    unsigned char AD4:1;               /*   AD4        */
                    unsigned char AD3:1;               /*   AD3        */
                    unsigned char AD2:1;               /*   AD2        */
                    } BIT;                             /*              */
             } ADDR0H;                                 /*              */
       union {                                         /* ADDR0L       */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char AD1:1;               /*   AD1        */
                    unsigned char AD0:1;               /*   AD0        */
                    unsigned char :6;                  /*              */
                    } BIT;                             /*              */
             } ADDR0L;                                 /*              */
       union {                                         /* ADDR1H       */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char AD9:1;               /*   AD9        */
                    unsigned char AD8:1;               /*   AD8        */
                    unsigned char AD7:1;               /*   AD7        */
                    unsigned char AD6:1;               /*   AD6        */
                    unsigned char AD5:1;               /*   AD5        */
                    unsigned char AD4:1;               /*   AD4        */
                    unsigned char AD3:1;               /*   AD3        */
                    unsigned char AD2:1;               /*   AD2        */
                    } BIT;                             /*              */
             } ADDR1H;                                 /*              */
       union {                                         /* ADDR1L       */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char AD1:1;               /*   AD1        */
                    unsigned char AD0:1;               /*   AD0        */
                    unsigned char :6;                  /*              */
                    } BIT;                             /*              */
             } ADDR1L;                                 /*              */
       union {                                         /* ADDR2H       */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char AD9:1;               /*   AD9        */
                    unsigned char AD8:1;               /*   AD8        */
                    unsigned char AD7:1;               /*   AD7        */
                    unsigned char AD6:1;               /*   AD6        */
                    unsigned char AD5:1;               /*   AD5        */
                    unsigned char AD4:1;               /*   AD4        */
                    unsigned char AD3:1;               /*   AD3        */
                    unsigned char AD2:1;               /*   AD2        */
                    } BIT;                             /*              */
             } ADDR2H;                                 /*              */
       union {                                         /* ADDR2L       */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char AD1:1;               /*   AD1        */
                    unsigned char AD0:1;               /*   AD0        */
                    unsigned char :6;                  /*              */
                    } BIT;                             /*              */
             } ADDR2L;                                 /*              */
       union {                                         /* ADDR3H       */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char AD9:1;               /*   AD9        */
                    unsigned char AD8:1;               /*   AD8        */
                    unsigned char AD7:1;               /*   AD7        */
                    unsigned char AD6:1;               /*   AD6        */
                    unsigned char AD5:1;               /*   AD5        */
                    unsigned char AD4:1;               /*   AD4        */
                    unsigned char AD3:1;               /*   AD3        */
                    unsigned char AD2:1;               /*   AD2        */
                    } BIT;                             /*              */
             } ADDR3H;                                 /*              */
       union {                                         /* ADDR3L       */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char AD1:1;               /*   AD1        */
                    unsigned char AD0:1;               /*   AD0        */
                    unsigned char :6;                  /*              */
                    } BIT;                             /*              */
             } ADDR3L;                                 /*              */
       union {                                         /* ADDR4H       */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char AD9:1;               /*   AD9        */
                    unsigned char AD8:1;               /*   AD8        */
                    unsigned char AD7:1;               /*   AD7        */
                    unsigned char AD6:1;               /*   AD6        */
                    unsigned char AD5:1;               /*   AD5        */
                    unsigned char AD4:1;               /*   AD4        */
                    unsigned char AD3:1;               /*   AD3        */
                    unsigned char AD2:1;               /*   AD2        */
                    } BIT;                             /*              */
             } ADDR4H;                                 /*              */
       union {                                         /* ADDR4L       */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char AD1:1;               /*   AD1        */
                    unsigned char AD0:1;               /*   AD0        */
                    unsigned char :6;                  /*              */
                    } BIT;                             /*              */
             } ADDR4L;                                 /*              */
       union {                                         /* ADDR5H       */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char AD9:1;               /*   AD9        */
                    unsigned char AD8:1;               /*   AD8        */
                    unsigned char AD7:1;               /*   AD7        */
                    unsigned char AD6:1;               /*   AD6        */
                    unsigned char AD5:1;               /*   AD5        */
                    unsigned char AD4:1;               /*   AD4        */
                    unsigned char AD3:1;               /*   AD3        */
                    unsigned char AD2:1;               /*   AD2        */
                    } BIT;                             /*              */
             } ADDR5H;                                 /*              */
       union {                                         /* ADDR5L       */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char AD1:1;               /*   AD1        */
                    unsigned char AD0:1;               /*   AD0        */
                    unsigned char :6;                  /*              */
                    } BIT;                             /*              */
             } ADDR5L;                                 /*              */
       union {                                         /* ADDR6H       */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char AD9:1;               /*   AD9        */
                    unsigned char AD8:1;               /*   AD8        */
                    unsigned char AD7:1;               /*   AD7        */
                    unsigned char AD6:1;               /*   AD6        */
                    unsigned char AD5:1;               /*   AD5        */
                    unsigned char AD4:1;               /*   AD4        */
                    unsigned char AD3:1;               /*   AD3        */
                    unsigned char AD2:1;               /*   AD2        */
                    } BIT;                             /*              */
             } ADDR6H;                                 /*              */
       union {                                         /* ADDR6L       */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char AD1:1;               /*   AD1        */
                    unsigned char AD0:1;               /*   AD0        */
                    unsigned char :6;                  /*              */
                    } BIT;                             /*              */
             } ADDR6L;                                 /*              */
       union {                                         /* ADDR7H       */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char AD9:1;               /*   AD9        */
                    unsigned char AD8:1;               /*   AD8        */
                    unsigned char AD7:1;               /*   AD7        */
                    unsigned char AD6:1;               /*   AD6        */
                    unsigned char AD5:1;               /*   AD5        */
                    unsigned char AD4:1;               /*   AD4        */
                    unsigned char AD3:1;               /*   AD3        */
                    unsigned char AD2:1;               /*   AD2        */
                    } BIT;                             /*              */
             } ADDR7H;                                 /*              */
       union {                                         /* ADDR7L       */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char AD1:1;               /*   AD1        */
                    unsigned char AD0:1;               /*   AD0        */
                    unsigned char :6;                  /*              */
                    } BIT;                             /*              */
             } ADDR7L;                                 /*              */
       union {                                         /* ADDR8H       */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char AD9:1;               /*   AD9        */
                    unsigned char AD8:1;               /*   AD8        */
                    unsigned char AD7:1;               /*   AD7        */
                    unsigned char AD6:1;               /*   AD6        */
                    unsigned char AD5:1;               /*   AD5        */
                    unsigned char AD4:1;               /*   AD4        */
                    unsigned char AD3:1;               /*   AD3        */
                    unsigned char AD2:1;               /*   AD2        */
                    } BIT;                             /*              */
             } ADDR8H;                                 /*              */
       union {                                         /* ADDR8L       */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char AD1:1;               /*   AD1        */
                    unsigned char AD0:1;               /*   AD0        */
                    unsigned char :6;                  /*              */
                    } BIT;                             /*              */
             } ADDR8L;                                 /*              */
       union {                                         /* ADDR9H       */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char AD9:1;               /*   AD9        */
                    unsigned char AD8:1;               /*   AD8        */
                    unsigned char AD7:1;               /*   AD7        */
                    unsigned char AD6:1;               /*   AD6        */
                    unsigned char AD5:1;               /*   AD5        */
                    unsigned char AD4:1;               /*   AD4        */
                    unsigned char AD3:1;               /*   AD3        */
                    unsigned char AD2:1;               /*   AD2        */
                    } BIT;                             /*              */
             } ADDR9H;                                 /*              */
       union {                                         /* ADDR9L       */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char AD1:1;               /*   AD1        */
                    unsigned char AD0:1;               /*   AD0        */
                    unsigned char :6;                  /*              */
                    } BIT;                             /*              */
             } ADDR9L;                                 /*              */
       union {                                         /* ADDR10H      */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char AD9:1;               /*   AD9        */
                    unsigned char AD8:1;               /*   AD8        */
                    unsigned char AD7:1;               /*   AD7        */
                    unsigned char AD6:1;               /*   AD6        */
                    unsigned char AD5:1;               /*   AD5        */
                    unsigned char AD4:1;               /*   AD4        */
                    unsigned char AD3:1;               /*   AD3        */
                    unsigned char AD2:1;               /*   AD2        */
                    } BIT;                             /*              */
             } ADDR10H;                                /*              */
       union {                                         /* ADDR10L      */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char AD1:1;               /*   AD1        */
                    unsigned char AD0:1;               /*   AD0        */
                    unsigned char :6;                  /*              */
                    } BIT;                             /*              */
             } ADDR10L;                                /*              */
       union {                                         /* ADDR11H      */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char AD9:1;               /*   AD9        */
                    unsigned char AD8:1;               /*   AD8        */
                    unsigned char AD7:1;               /*   AD7        */
                    unsigned char AD6:1;               /*   AD6        */
                    unsigned char AD5:1;               /*   AD5        */
                    unsigned char AD4:1;               /*   AD4        */
                    unsigned char AD3:1;               /*   AD3        */
                    unsigned char AD2:1;               /*   AD2        */
                    } BIT;                             /*              */
             } ADDR11H;                                /*              */
       union {                                         /* ADDR11L      */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char AD1:1;               /*   AD1        */
                    unsigned char AD0:1;               /*   AD0        */
                    unsigned char :6;                  /*              */
                    } BIT;                             /*              */
             } ADDR11L;                                /*              */
       union {                                         /* ADCSR0       */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char ADF:1;               /*   ADF        */
                    unsigned char ADIE:1;              /*   ADIE       */
                    unsigned char ADM:2;               /*   ADM        */
                    unsigned char CH:4;                /*   CH         */
                    } BIT;                             /*              */
             } ADCSR0;                                 /*              */
       union {                                         /* ADCR0        */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char TRGE:1;              /*   TRGE       */
                    unsigned char CKS:1;               /*   CKS        */
                    unsigned char ADST:1;              /*   ADST       */
                    unsigned char ADCS:1;              /*   ADCS       */
                    unsigned char :4;                  /*              */
                    } BIT;                             /*              */
             } ADCR0;                                  /*              */
       unsigned char wk2[6];                           /*              */
       union {                                         /* ADDR12H      */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char AD9:1;               /*   AD9        */
                    unsigned char AD8:1;               /*   AD8        */
                    unsigned char AD7:1;               /*   AD7        */
                    unsigned char AD6:1;               /*   AD6        */
                    unsigned char AD5:1;               /*   AD5        */
                    unsigned char AD4:1;               /*   AD4        */
                    unsigned char AD3:1;               /*   AD3        */
                    unsigned char AD2:1;               /*   AD2        */
                    } BIT;                             /*              */
             } ADDR12H;                                /*              */
       union {                                         /* ADDR12L      */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char AD1:1;               /*   AD1        */
                    unsigned char AD0:1;               /*   AD0        */
                    unsigned char :6;                  /*              */
                    } BIT;                             /*              */
             } ADDR12L;                                /*              */
       union {                                         /* ADDR13H      */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char AD9:1;               /*   AD9        */
                    unsigned char AD8:1;               /*   AD8        */
                    unsigned char AD7:1;               /*   AD7        */
                    unsigned char AD6:1;               /*   AD6        */
                    unsigned char AD5:1;               /*   AD5        */
                    unsigned char AD4:1;               /*   AD4        */
                    unsigned char AD3:1;               /*   AD3        */
                    unsigned char AD2:1;               /*   AD2        */
                    } BIT;                             /*              */
             } ADDR13H;                                /*              */
       union {                                         /* ADDR13L      */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char AD1:1;               /*   AD1        */
                    unsigned char AD0:1;               /*   AD0        */
                    unsigned char :6;                  /*              */
                    } BIT;                             /*              */
             } ADDR13L;                                /*              */
       union {                                         /* ADDR14H      */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char AD9:1;               /*   AD9        */
                    unsigned char AD8:1;               /*   AD8        */
                    unsigned char AD7:1;               /*   AD7        */
                    unsigned char AD6:1;               /*   AD6        */
                    unsigned char AD5:1;               /*   AD5        */
                    unsigned char AD4:1;               /*   AD4        */
                    unsigned char AD3:1;               /*   AD3        */
                    unsigned char AD2:1;               /*   AD2        */
                    } BIT;                             /*              */
             } ADDR14H;                                /*              */
       union {                                         /* ADDR14L      */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char AD1:1;               /*   AD1        */
                    unsigned char AD0:1;               /*   AD0        */
                    unsigned char :6;                  /*              */
                    } BIT;                             /*              */
             } ADDR14L;                                /*              */
       union {                                         /* ADDR15H      */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char AD9:1;               /*   AD9        */
                    unsigned char AD8:1;               /*   AD8        */
                    unsigned char AD7:1;               /*   AD7        */
                    unsigned char AD6:1;               /*   AD6        */
                    unsigned char AD5:1;               /*   AD5        */
                    unsigned char AD4:1;               /*   AD4        */
                    unsigned char AD3:1;               /*   AD3        */
                    unsigned char AD2:1;               /*   AD2        */
                    } BIT;                             /*              */
             } ADDR15H;                                /*              */
       union {                                         /* ADDR15L      */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char AD1:1;               /*   AD1        */
                    unsigned char AD0:1;               /*   AD0        */
                    unsigned char :6;                  /*              */
                    } BIT;                             /*              */
             } ADDR15L;                                /*              */
       union {                                         /* ADDR16H      */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char AD9:1;               /*   AD9        */
                    unsigned char AD8:1;               /*   AD8        */
                    unsigned char AD7:1;               /*   AD7        */
                    unsigned char AD6:1;               /*   AD6        */
                    unsigned char AD5:1;               /*   AD5        */
                    unsigned char AD4:1;               /*   AD4        */
                    unsigned char AD3:1;               /*   AD3        */
                    unsigned char AD2:1;               /*   AD2        */
                    } BIT;                             /*              */
             } ADDR16H;                                /*              */
       union {                                         /* ADDR16L      */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char AD1:1;               /*   AD1        */
                    unsigned char AD0:1;               /*   AD0        */
                    unsigned char :6;                  /*              */
                    } BIT;                             /*              */
             } ADDR16L;                                /*              */
       union {                                         /* ADDR17H      */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char AD9:1;               /*   AD9        */
                    unsigned char AD8:1;               /*   AD8        */
                    unsigned char AD7:1;               /*   AD7        */
                    unsigned char AD6:1;               /*   AD6        */
                    unsigned char AD5:1;               /*   AD5        */
                    unsigned char AD4:1;               /*   AD4        */
                    unsigned char AD3:1;               /*   AD3        */
                    unsigned char AD2:1;               /*   AD2        */
                    } BIT;                             /*              */
             } ADDR17H;                                /*              */
       union {                                         /* ADDR17L      */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char AD1:1;               /*   AD1        */
                    unsigned char AD0:1;               /*   AD0        */
                    unsigned char :6;                  /*              */
                    } BIT;                             /*              */
             } ADDR17L;                                /*              */
       union {                                         /* ADDR18H      */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char AD9:1;               /*   AD9        */
                    unsigned char AD8:1;               /*   AD8        */
                    unsigned char AD7:1;               /*   AD7        */
                    unsigned char AD6:1;               /*   AD6        */
                    unsigned char AD5:1;               /*   AD5        */
                    unsigned char AD4:1;               /*   AD4        */
                    unsigned char AD3:1;               /*   AD3        */
                    unsigned char AD2:1;               /*   AD2        */
                    } BIT;                             /*              */
             } ADDR18H;                                /*              */
       union {                                         /* ADDR18L      */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char AD1:1;               /*   AD1        */
                    unsigned char AD0:1;               /*   AD0        */
                    unsigned char :6;                  /*              */
                    } BIT;                             /*              */
             } ADDR18L;                                /*              */
       union {                                         /* ADDR19H      */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char AD9:1;               /*   AD9        */
                    unsigned char AD8:1;               /*   AD8        */
                    unsigned char AD7:1;               /*   AD7        */
                    unsigned char AD6:1;               /*   AD6        */
                    unsigned char AD5:1;               /*   AD5        */
                    unsigned char AD4:1;               /*   AD4        */
                    unsigned char AD3:1;               /*   AD3        */
                    unsigned char AD2:1;               /*   AD2        */
                    } BIT;                             /*              */
             } ADDR19H;                                /*              */
       union {                                         /* ADDR19L      */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char AD1:1;               /*   AD1        */
                    unsigned char AD0:1;               /*   AD0        */
                    unsigned char :6;                  /*              */
                    } BIT;                             /*              */
             } ADDR19L;                                /*              */
       union {                                         /* ADDR20H      */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char AD9:1;               /*   AD9        */
                    unsigned char AD8:1;               /*   AD8        */
                    unsigned char AD7:1;               /*   AD7        */
                    unsigned char AD6:1;               /*   AD6        */
                    unsigned char AD5:1;               /*   AD5        */
                    unsigned char AD4:1;               /*   AD4        */
                    unsigned char AD3:1;               /*   AD3        */
                    unsigned char AD2:1;               /*   AD2        */
                    } BIT;                             /*              */
             } ADDR20H;                                /*              */
       union {                                         /* ADDR20L      */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char AD1:1;               /*   AD1        */
                    unsigned char AD0:1;               /*   AD0        */
                    unsigned char :6;                  /*              */
                    } BIT;                             /*              */
             } ADDR20L;                                /*              */
       union {                                         /* ADDR21H      */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char AD9:1;               /*   AD9        */
                    unsigned char AD8:1;               /*   AD8        */
                    unsigned char AD7:1;               /*   AD7        */
                    unsigned char AD6:1;               /*   AD6        */
                    unsigned char AD5:1;               /*   AD5        */
                    unsigned char AD4:1;               /*   AD4        */
                    unsigned char AD3:1;               /*   AD3        */
                    unsigned char AD2:1;               /*   AD2        */
                    } BIT;                             /*              */
             } ADDR21H;                                /*              */
       union {                                         /* ADDR21L      */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char AD1:1;               /*   AD1        */
                    unsigned char AD0:1;               /*   AD0        */
                    unsigned char :6;                  /*              */
                    } BIT;                             /*              */
             } ADDR21L;                                /*              */
       union {                                         /* ADDR22H      */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char AD9:1;               /*   AD9        */
                    unsigned char AD8:1;               /*   AD8        */
                    unsigned char AD7:1;               /*   AD7        */
                    unsigned char AD6:1;               /*   AD6        */
                    unsigned char AD5:1;               /*   AD5        */
                    unsigned char AD4:1;               /*   AD4        */
                    unsigned char AD3:1;               /*   AD3        */
                    unsigned char AD2:1;               /*   AD2        */
                    } BIT;                             /*              */
             } ADDR22H;                                /*              */
       union {                                         /* ADDR22L      */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char AD1:1;               /*   AD1        */
                    unsigned char AD0:1;               /*   AD0        */
                    unsigned char :6;                  /*              */
                    } BIT;                             /*              */
             } ADDR22L;                                /*              */
       union {                                         /* ADDR23H      */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char AD9:1;               /*   AD9        */
                    unsigned char AD8:1;               /*   AD8        */
                    unsigned char AD7:1;               /*   AD7        */
                    unsigned char AD6:1;               /*   AD6        */
                    unsigned char AD5:1;               /*   AD5        */
                    unsigned char AD4:1;               /*   AD4        */
                    unsigned char AD3:1;               /*   AD3        */
                    unsigned char AD2:1;               /*   AD2        */
                    } BIT;                             /*              */
             } ADDR23H;                                /*              */
       union {                                         /* ADDR23L      */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char AD1:1;               /*   AD1        */
                    unsigned char AD0:1;               /*   AD0        */
                    unsigned char :6;                  /*              */
                    } BIT;                             /*              */
             } ADDR23L;                                /*              */
       union {                                         /* ADCSR1       */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char ADF:1;               /*   ADF        */
                    unsigned char ADIE:1;              /*   ADIE       */
                    unsigned char ADM:2;               /*   ADM        */
                    unsigned char CH:4;                /*   CH         */
                    } BIT;                             /*              */
             } ADCSR1;                                 /*              */
       union {                                         /* ADCR1        */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char TRGE:1;              /*   TRGE       */
                    unsigned char CKS:1;               /*   CKS        */
                    unsigned char ADST:1;              /*   ADST       */
                    unsigned char ADCS:1;              /*   ADCS       */
                    unsigned char :4;                  /*              */
                    } BIT;                             /*              */
             } ADCR1;                                  /*              */
       unsigned char wk3[6];                           /*              */
       union {                                         /* ADDR24H      */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char AD9:1;               /*   AD9        */
                    unsigned char AD8:1;               /*   AD8        */
                    unsigned char AD7:1;               /*   AD7        */
                    unsigned char AD6:1;               /*   AD6        */
                    unsigned char AD5:1;               /*   AD5        */
                    unsigned char AD4:1;               /*   AD4        */
                    unsigned char AD3:1;               /*   AD3        */
                    unsigned char AD2:1;               /*   AD2        */
                    } BIT;                             /*              */
             } ADDR24H;                                /*              */
       union {                                         /* ADDR24L      */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char AD1:1;               /*   AD1        */
                    unsigned char AD0:1;               /*   AD0        */
                    unsigned char :6;                  /*              */
                    } BIT;                             /*              */
             } ADDR24L;                                /*              */
       union {                                         /* ADDR25H      */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char AD9:1;               /*   AD9        */
                    unsigned char AD8:1;               /*   AD8        */
                    unsigned char AD7:1;               /*   AD7        */
                    unsigned char AD6:1;               /*   AD6        */
                    unsigned char AD5:1;               /*   AD5        */
                    unsigned char AD4:1;               /*   AD4        */
                    unsigned char AD3:1;               /*   AD3        */
                    unsigned char AD2:1;               /*   AD2        */
                    } BIT;                             /*              */
             } ADDR25H;                                /*              */
       union {                                         /* ADDR25L      */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char AD1:1;               /*   AD1        */
                    unsigned char AD0:1;               /*   AD0        */
                    unsigned char :6;                  /*              */
                    } BIT;                             /*              */
             } ADDR25L;                                /*              */
       union {                                         /* ADDR26H      */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char AD9:1;               /*   AD9        */
                    unsigned char AD8:1;               /*   AD8        */
                    unsigned char AD7:1;               /*   AD7        */
                    unsigned char AD6:1;               /*   AD6        */
                    unsigned char AD5:1;               /*   AD5        */
                    unsigned char AD4:1;               /*   AD4        */
                    unsigned char AD3:1;               /*   AD3        */
                    unsigned char AD2:1;               /*   AD2        */
                    } BIT;                             /*              */
             } ADDR26H;                                /*              */
       union {                                         /* ADDR26L      */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char AD1:1;               /*   AD1        */
                    unsigned char AD0:1;               /*   AD0        */
                    unsigned char :6;                  /*              */
                    } BIT;                             /*              */
             } ADDR26L;                                /*              */
       union {                                         /* ADDR27H      */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char AD9:1;               /*   AD9        */
                    unsigned char AD8:1;               /*   AD8        */
                    unsigned char AD7:1;               /*   AD7        */
                    unsigned char AD6:1;               /*   AD6        */
                    unsigned char AD5:1;               /*   AD5        */
                    unsigned char AD4:1;               /*   AD4        */
                    unsigned char AD3:1;               /*   AD3        */
                    unsigned char AD2:1;               /*   AD2        */
                    } BIT;                             /*              */
             } ADDR27H;                                /*              */
       union {                                         /* ADDR27L      */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char AD1:1;               /*   AD1        */
                    unsigned char AD0:1;               /*   AD0        */
                    unsigned char :6;                  /*              */
                    } BIT;                             /*              */
             } ADDR27L;                                /*              */
       union {                                         /* ADDR28H      */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char AD9:1;               /*   AD9        */
                    unsigned char AD8:1;               /*   AD8        */
                    unsigned char AD7:1;               /*   AD7        */
                    unsigned char AD6:1;               /*   AD6        */
                    unsigned char AD5:1;               /*   AD5        */
                    unsigned char AD4:1;               /*   AD4        */
                    unsigned char AD3:1;               /*   AD3        */
                    unsigned char AD2:1;               /*   AD2        */
                    } BIT;                             /*              */
             } ADDR28H;                                /*              */
       union {                                         /* ADDR28L      */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char AD1:1;               /*   AD1        */
                    unsigned char AD0:1;               /*   AD0        */
                    unsigned char :6;                  /*              */
                    } BIT;                             /*              */
             } ADDR28L;                                /*              */
       union {                                         /* ADDR29H      */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char AD9:1;               /*   AD9        */
                    unsigned char AD8:1;               /*   AD8        */
                    unsigned char AD7:1;               /*   AD7        */
                    unsigned char AD6:1;               /*   AD6        */
                    unsigned char AD5:1;               /*   AD5        */
                    unsigned char AD4:1;               /*   AD4        */
                    unsigned char AD3:1;               /*   AD3        */
                    unsigned char AD2:1;               /*   AD2        */
                    } BIT;                             /*              */
             } ADDR29H;                                /*              */
       union {                                         /* ADDR29L      */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char AD1:1;               /*   AD1        */
                    unsigned char AD0:1;               /*   AD0        */
                    unsigned char :6;                  /*              */
                    } BIT;                             /*              */
             } ADDR29L;                                /*              */
       union {                                         /* ADDR30H      */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char AD9:1;               /*   AD9        */
                    unsigned char AD8:1;               /*   AD8        */
                    unsigned char AD7:1;               /*   AD7        */
                    unsigned char AD6:1;               /*   AD6        */
                    unsigned char AD5:1;               /*   AD5        */
                    unsigned char AD4:1;               /*   AD4        */
                    unsigned char AD3:1;               /*   AD3        */
                    unsigned char AD2:1;               /*   AD2        */
                    } BIT;                             /*              */
             } ADDR30H;                                /*              */
       union {                                         /* ADDR30L      */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char AD1:1;               /*   AD1        */
                    unsigned char AD0:1;               /*   AD0        */
                    unsigned char :6;                  /*              */
                    } BIT;                             /*              */
             } ADDR30L;                                /*              */
       union {                                         /* ADDR31H      */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char AD9:1;               /*   AD9        */
                    unsigned char AD8:1;               /*   AD8        */
                    unsigned char AD7:1;               /*   AD7        */
                    unsigned char AD6:1;               /*   AD6        */
                    unsigned char AD5:1;               /*   AD5        */
                    unsigned char AD4:1;               /*   AD4        */
                    unsigned char AD3:1;               /*   AD3        */
                    unsigned char AD2:1;               /*   AD2        */
                    } BIT;                             /*              */
             } ADDR31H;                                /*              */
       union {                                         /* ADDR31L      */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char AD1:1;               /*   AD1        */
                    unsigned char AD0:1;               /*   AD0        */
                    unsigned char :6;                  /*              */
                    } BIT;                             /*              */
             } ADDR31L;                                /*              */
       unsigned char wk4[8];                           /*              */
       union {                                         /* ADCSR2       */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char ADF:1;               /*   ADF        */
                    unsigned char ADIE:1;              /*   ADIE       */
                    unsigned char ADM:2;               /*   ADM        */
                    unsigned char :1;                  /*              */
                    unsigned char CH:3;                /*   CH         */
                    } BIT;                             /*              */
             } ADCSR2;                                 /*              */
       union {                                         /* ADCR2        */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char TRGE:1;              /*   TRGE       */
                    unsigned char CKS:1;               /*   CKS        */
                    unsigned char ADST:1;              /*   ADST       */
                    unsigned char ADCS:1;              /*   ADCS       */
                    unsigned char :4;                  /*              */
                    } BIT;                             /*              */
             } ADCR2;                                  /*              */
};                                                     /*              */
struct st_hudi {                                       /* struct H-UDI */
       union {                                         /* SDIR         */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short TS:4;               /*   TS         */
                    unsigned short :12;                /*              */
                    } BIT;                             /*              */
             } SDIR;                                   /*              */
       union {                                         /* SDSR         */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short :15;                /*              */
                    unsigned short SDTRF:1;            /*   SDTRF      */
                    } BIT;                             /*              */
             } SDSR;                                   /*              */
       unsigned short SDDRH;                           /* SDDRH        */
       unsigned short SDDRL;                           /* SDDRL        */
};                                                     /*              */
struct st_pfc {                                        /* struct PFC   */
       union {                                         /* PAIOR        */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short PA15IOR:1;          /*   PA15IOR    */
                    unsigned short PA14IOR:1;          /*   PA14IOR    */
                    unsigned short PA13IOR:1;          /*   PA13IOR    */
                    unsigned short PA12IOR:1;          /*   PA12IOR    */
                    unsigned short PA11IOR:1;          /*   PA11IOR    */
                    unsigned short PA10IOR:1;          /*   PA10IOR    */
                    unsigned short PA9IOR:1;           /*   PA9IOR     */
                    unsigned short PA8IOR:1;           /*   PA8IOR     */
                    unsigned short PA7IOR:1;           /*   PA7IOR     */
                    unsigned short PA6IOR:1;           /*   PA6IOR     */
                    unsigned short PA5IOR:1;           /*   PA5IOR     */
                    unsigned short PA4IOR:1;           /*   PA4IOR     */
                    unsigned short PA3IOR:1;           /*   PA3IOR     */
                    unsigned short PA2IOR:1;           /*   PA2IOR     */
                    unsigned short PA1IOR:1;           /*   PA1IOR     */
                    unsigned short PA0IOR:1;           /*   PA0IOR     */
                    } BIT;                             /*              */
             } PAIOR;                                  /*              */
       union {                                         /* PACRH        */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short PA15MD:2;           /*   PA15MD     */
                    unsigned short PA14MD:2;           /*   PA14MD     */
                    unsigned short :1;                 /*              */
                    unsigned short PA13MD:1;           /*   PA13MD     */
                    unsigned short :1;                 /*              */
                    unsigned short PA12MD:1;           /*   PA12MD     */
                    unsigned short PA11MD:2;           /*   PA11MD     */
                    unsigned short PA10MD1:2;          /*   PA10MD     */
                    unsigned short PA9MD:2;            /*   PA9MD      */
                    unsigned short PA8MD:2;            /*   PA8MD      */
                    } BIT;                             /*              */
             } PACRH;                                  /*              */
       union {                                         /* PACRL        */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short :1;                 /*              */
                    unsigned short PA7MD:1;            /*   PA7MD      */
                    unsigned short :1;                 /*              */
                    unsigned short PA6MD:1;            /*   PA6MD      */
                    unsigned short :1;                 /*              */
                    unsigned short PA5MD:1;            /*   PA5MD      */
                    unsigned short :1;                 /*              */
                    unsigned short PA4MD:1;            /*   PA4MD      */
                    unsigned short :1;                 /*              */
                    unsigned short PA3MD:1;            /*   PA3MD      */
                    unsigned short :1;                 /*              */
                    unsigned short PA2MD:1;            /*   PA2MD      */
                    unsigned short :1;                 /*              */
                    unsigned short PA1MD:1;            /*   PA1MD      */
                    unsigned short :1;                 /*              */
                    unsigned short PA0MD:1;            /*   PA0MD      */
                    } BIT;                             /*              */
             } PACRL;                                  /*              */
       unsigned char wk0[2];                           /*              */
       union {                                         /* PHIOR        */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short PH15IOR:1;          /*   PH15IOR    */
                    unsigned short PH14IOR:1;          /*   PH14IOR    */
                    unsigned short PH13IOR:1;          /*   PH13IOR    */
                    unsigned short PH12IOR:1;          /*   PH12IOR    */
                    unsigned short PH11IOR:1;          /*   PH11IOR    */
                    unsigned short PH10IOR:1;          /*   PH10IOR    */
                    unsigned short PH9IOR:1;           /*   PH9IOR     */
                    unsigned short PH8IOR:1;           /*   PH8IOR     */
                    unsigned short PH7IOR:1;           /*   PH7IOR     */
                    unsigned short PH6IOR:1;           /*   PH6IOR     */
                    unsigned short PH5IOR:1;           /*   PH5IOR     */
                    unsigned short PH4IOR:1;           /*   PH4IOR     */
                    unsigned short PH3IOR:1;           /*   PH3IOR     */
                    unsigned short PH2IOR:1;           /*   PH2IOR     */
                    unsigned short PH1IOR:1;           /*   PH1IOR     */
                    unsigned short PH0IOR:1;           /*   PH0IOR     */
                    } BIT;                             /*              */
             } PHIOR;                                  /*              */
       union {                                         /* PHCR         */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short PH15MD:1;           /*   PH15MD     */
                    unsigned short PH14MD:1;           /*   PH14MD     */
                    unsigned short PH13MD:1;           /*   PH13MD     */
                    unsigned short PH12MD:1;           /*   PH12MD     */
                    unsigned short PH11MD:1;           /*   PH11MD     */
                    unsigned short PH10MD:1;           /*   PH10MD     */
                    unsigned short PH9MD:1;            /*   PH9MD      */
                    unsigned short PH8MD:1;            /*   PH8MD      */
                    unsigned short PH7MD:1;            /*   PH7MD      */
                    unsigned short PH6MD:1;            /*   PH6MD      */
                    unsigned short PH5MD:1;            /*   PH5MD      */
                    unsigned short PH4MD:1;            /*   PH4MD      */
                    unsigned short PH3MD:1;            /*   PH3MD      */
                    unsigned short PH2MD:1;            /*   PH2MD      */
                    unsigned short PH1MD:1;            /*   PH1MD      */
                    unsigned short PH0MD:1;            /*   PH0MD      */
                    } BIT;                             /*              */
             } PHCR;                                   /*              */
       unsigned char wk1[4];                           /*              */
       union {                                         /* PBIOR        */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short PB15IOR:1;          /*   PB15IOR    */
                    unsigned short PB14IOR:1;          /*   PB14IOR    */
                    unsigned short PB13IOR:1;          /*   PB13IOR    */
                    unsigned short PB12IOR:1;          /*   PB12IOR    */
                    unsigned short PB11IOR:1;          /*   PB11IOR    */
                    unsigned short PB10IOR:1;          /*   PB10IOR    */
                    unsigned short PB9IOR:1;           /*   PB9IOR     */
                    unsigned short PB8IOR:1;           /*   PB8IOR     */
                    unsigned short PB7IOR:1;           /*   PB7IOR     */
                    unsigned short PB6IOR:1;           /*   PB6IOR     */
                    unsigned short PB5IOR:1;           /*   PB5IOR     */
                    unsigned short PB4IOR:1;           /*   PB4IOR     */
                    unsigned short PB3IOR:1;           /*   PB3IOR     */
                    unsigned short PB2IOR:1;           /*   PB2IOR     */
                    unsigned short PB1IOR:1;           /*   PB1IOR     */
                    unsigned short PB0IOR:1;           /*   PB0IOR     */
                    } BIT;                             /*              */
             } PBIOR;                                  /*              */
       union {                                         /* PBCRH        */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short PB15MD:2;           /*   PB15MD     */
                    unsigned short PB14MD:2;           /*   PB14MD     */
                    unsigned short PB13MD:2;           /*   PB13MD     */
                    unsigned short PB12MD:2;           /*   PB12MD     */
                    unsigned short PB11MD:2;           /*   PB11MD     */
                    unsigned short PB10MD:2;           /*   PB10MD     */
                    unsigned short PB9MD:2;            /*   PB9MD      */
                    unsigned short PB8MD:2;            /*   PB8MD      */
                    } BIT;                             /*              */
             } PBCRH;                                  /*              */
       union {                                         /* PBCRL        */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short PB7MD:2;            /*   PB7MD      */
                    unsigned short PB6MD:2;            /*   PB6MD      */
                    unsigned short PB5MD:2;            /*   PB5MD      */
                    unsigned short PB4MD:2;            /*   PB4MD      */
                    unsigned short :1;                 /*              */
                    unsigned short PB3MD:1;            /*   PB3MD      */
                    unsigned short :1;                 /*              */
                    unsigned short PB2MD:1;            /*   PB2MD      */
                    unsigned short :1;                 /*              */
                    unsigned short PB1MD:1;            /*   PB1MD      */
                    unsigned short :1;                 /*              */
                    unsigned short PB0MD:1;            /*   PB0MD      */
                    } BIT;                             /*              */
             } PBCRL;                                  /*              */
       union {                                         /* PBIR         */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short PB15IR:1;           /*   PB15IR     */
                    unsigned short PB14IR:1;           /*   PB14IR     */
                    unsigned short PB13IR:1;           /*   PB13IR     */
                    unsigned short :1;                 /*              */
                    unsigned short PB11IR:1;           /*   PB11IR     */
                    unsigned short PB10IR:1;           /*   PB10IR     */
                    unsigned short PB9IR:1;            /*   PB9IR      */
                    unsigned short PB8IR:1;            /*   PB8IR      */
                    unsigned short PB7IR:1;            /*   PB7IR      */
                    unsigned short PB6IR:1;            /*   PB6IR      */
                    unsigned short PB5IR:1;            /*   PB5IR      */
                    unsigned short PB4IR:1;            /*   PB4IR      */
                    unsigned short PB3IR:1;            /*   PB3IR      */
                    unsigned short PB2IR:1;            /*   PB2IR      */
                    unsigned short PB1IR:1;            /*   PB1IR      */
                    unsigned short PB0IR:1;            /*   PB0IR      */
                    } BIT;                             /*              */
             } PBIR;                                   /*              */
       unsigned char wk2[2];                           /*              */
       union {                                         /* PCIOR        */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short :11;                /*              */
                    unsigned short PC4IOR:1;           /*   PC4IOR     */
                    unsigned short PC3IOR:1;           /*   PC3IOR     */
                    unsigned short PC2IOR:1;           /*   PC2IOR     */
                    unsigned short PC1IOR:1;           /*   PC1IOR     */
                    unsigned short PC0IOR:1;           /*   PC0IOR     */
                    } BIT;                             /*              */
             } PCIOR;                                  /*              */
       union {                                         /* PCCR         */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short :7;                 /*              */
                    unsigned short PC4MD:1;            /*   PC4MD      */
                    unsigned short PC3MD:2;            /*   PC3MD      */
                    unsigned short PC2MD:2;            /*   PC2MD      */
                    unsigned short :1;                 /*              */
                    unsigned short PC1MD:1;            /*   PC1MD      */
                    unsigned short :1;                 /*              */
                    unsigned short PC0MD:1;            /*   PC0MD      */
                    } BIT;                             /*              */
             } PCCR;                                   /*              */
       unsigned char wk3[2];                           /*              */
       union {                                         /* PDIOR        */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short :2;                 /*              */
                    unsigned short PD13IOR:1;          /*   PD13IOR    */
                    unsigned short PD12IOR:1;          /*   PD12IOR    */
                    unsigned short PD11IOR:1;          /*   PD11IOR    */
                    unsigned short PD10IOR:1;          /*   PD10IOR    */
                    unsigned short PD9IOR:1;           /*   PD9IOR     */
                    unsigned short PD8IOR:1;           /*   PD8IOR     */
                    unsigned short PD7IOR:1;           /*   PD7IOR     */
                    unsigned short PD6IOR:1;           /*   PD6IOR     */
                    unsigned short PD5IOR:1;           /*   PD5IOR     */
                    unsigned short PD4IOR:1;           /*   PD4IOR     */
                    unsigned short PD3IOR:1;           /*   PD3IOR     */
                    unsigned short PD2IOR:1;           /*   PD2IOR     */
                    unsigned short PD1IOR:1;           /*   PD1IOR     */
                    unsigned short PD0IOR:1;           /*   PD0IOR     */
                    } BIT;                             /*              */
             } PDIOR;                                  /*              */
       union {                                         /* PDCRH        */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short :4;                 /*              */
                    unsigned short PD13MD:2;           /*   PD13MD     */
                    unsigned short :1;                 /*              */
                    unsigned short PD12MD:1;           /*   PD12MD     */
                    unsigned short :1;                 /*              */
                    unsigned short PD11MD:1;           /*   PD11MD     */
                    unsigned short :1;                 /*              */
                    unsigned short PD10MD:1;           /*   PD10MD     */
                    unsigned short :1;                 /*              */
                    unsigned short PD9MD:1;            /*   PD9MD      */
                    unsigned short :1;                 /*              */
                    unsigned short PD8MD:1;            /*   PD8MD      */
                    } BIT;                             /*              */
             } PDCRH;                                  /*              */
       union {                                         /* PDCRL        */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short :1;                 /*              */
                    unsigned short PD7MD:1;            /*   PD7MD      */
                    unsigned short :1;                 /*              */
                    unsigned short PD6MD:1;            /*   PD6MD      */
                    unsigned short :1;                 /*              */
                    unsigned short PD5MD:1;            /*   PD5MD      */
                    unsigned short :1;                 /*              */
                    unsigned short PD4MD:1;            /*   PD4MD      */
                    unsigned short :1;                 /*              */
                    unsigned short PD3MD:1;            /*   PD3MD      */
                    unsigned short :1;                 /*              */
                    unsigned short PD2MD:1;            /*   PD2MD      */
                    unsigned short :1;                 /*              */
                    unsigned short PD1MD:1;            /*   PD1MD      */
                    unsigned short :1;                 /*              */
                    unsigned short PD0MD:1;            /*   PD0MD      */
                    } BIT;                             /*              */
             } PDCRL;                                  /*              */
       unsigned char wk4[2];                           /*              */
       union {                                         /* PFIOR        */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short PF15IOR:1;          /*   PF15IOR    */
                    unsigned short PF14IOR:1;          /*   PF14IOR    */
                    unsigned short PF13IOR:1;          /*   PF13IOR    */
                    unsigned short PF12IOR:1;          /*   PF12IOR    */
                    unsigned short PF11IOR:1;          /*   PF11IOR    */
                    unsigned short PF10IOR:1;          /*   PF10IOR    */
                    unsigned short PF9IOR:1;           /*   PF9IOR     */
                    unsigned short PF8IOR:1;           /*   PF8IOR     */
                    unsigned short PF7IOR:1;           /*   PF7IOR     */
                    unsigned short PF6IOR:1;           /*   PF6IOR     */
                    unsigned short PF5IOR:1;           /*   PF5IOR     */
                    unsigned short PF4IOR:1;           /*   PF4IOR     */
                    unsigned short PF3IOR:1;           /*   PF3IOR     */
                    unsigned short PF2IOR:1;           /*   PF2IOR     */
                    unsigned short PF1IOR:1;           /*   PF1IOR     */
                    unsigned short PF0IOR:1;           /*   PF0IOR     */
                    } BIT;                             /*              */
             } PFIOR;                                  /*              */
       union {                                         /* PFCRH        */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short CKHIZ:1;            /*   CKHIZ      */
                    unsigned short PF15MD:2;           /*   PF15MD     */
                    unsigned short PF14MD:2;           /*   PF14MD     */
                    unsigned short PF13MD:1;           /*   PF13MD     */
                    unsigned short :1;                 /*              */
                    unsigned short PF12MD:1;           /*   PF12MD     */
                    unsigned short :1;                 /*              */
                    unsigned short PF11MD:1;           /*   PF11MD     */
                    unsigned short :1;                 /*              */
                    unsigned short PF10MD:1;           /*   PF10MD     */
                    unsigned short :1;                 /*              */
                    unsigned short PF9MD:1;            /*   PF9MD      */
                    unsigned short :1;                 /*              */
                    unsigned short PF8MD:1;            /*   PF8MD      */
                    } BIT;                             /*              */
             } PFCRH;                                  /*              */
       union {                                         /* PFCRL        */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short :1;                 /*              */
                    unsigned short PF7MD:1;            /*   PF7MD      */
                    unsigned short :1;                 /*              */
                    unsigned short PF6MD:1;            /*   PF6MD      */
                    unsigned short PF5MD:2;            /*   PF5MD      */
                    unsigned short :1;                 /*              */
                    unsigned short PF4MD:1;            /*   PF4MD      */
                    unsigned short :1;                 /*              */
                    unsigned short PF3MD:1;            /*   PF3MD      */
                    unsigned short :1;                 /*              */
                    unsigned short PF2MD:1;            /*   PF2MD      */
                    unsigned short :1;                 /*              */
                    unsigned short PF1MD:1;            /*   PF1MD      */
                    unsigned short :1;                 /*              */
                    unsigned short PF0MD:1;            /*   PF0MD      */
                    } BIT;                             /*              */
             } PFCRL;                                  /*              */
       unsigned char wk5[2];                           /*              */
       union {                                         /* PEIOR        */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short PE15IOR:1;          /*   PE15IOR    */
                    unsigned short PE14IOR:1;          /*   PE14IOR    */
                    unsigned short PE13IOR:1;          /*   PE13IOR    */
                    unsigned short PE12IOR:1;          /*   PE12IOR    */
                    unsigned short PE11IOR:1;          /*   PE11IOR    */
                    unsigned short PE10IOR:1;          /*   PE10IOR    */
                    unsigned short PE9IOR:1;           /*   PE9IOR     */
                    unsigned short PE8IOR:1;           /*   PE8IOR     */
                    unsigned short PE7IOR:1;           /*   PE7IOR     */
                    unsigned short PE6IOR:1;           /*   PE6IOR     */
                    unsigned short PE5IOR:1;           /*   PE5IOR     */
                    unsigned short PE4IOR:1;           /*   PE4IOR     */
                    unsigned short PE3IOR:1;           /*   PE3IOR     */
                    unsigned short PE2IOR:1;           /*   PE2IOR     */
                    unsigned short PE1IOR:1;           /*   PE1IOR     */
                    unsigned short PE0IOR:1;           /*   PE0IOR     */
                    } BIT;                             /*              */
             } PEIOR;                                  /*              */
       union {                                         /* PECR         */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short PE15MD:1;           /*   PE15MD     */
                    unsigned short PE14MD:1;           /*   PE14MD     */
                    unsigned short PE13MD:1;           /*   PE13MD     */
                    unsigned short PE12MD:1;           /*   PE12MD     */
                    unsigned short PE11MD:1;           /*   PE11MD     */
                    unsigned short PE10MD:1;           /*   PE10MD     */
                    unsigned short PE9MD:1;            /*   PE9MD      */
                    unsigned short PE8MD:1;            /*   PE8MD      */
                    unsigned short PE7MD:1;            /*   PE7MD      */
                    unsigned short PE6MD:1;            /*   PE6MD      */
                    unsigned short PE5MD:1;            /*   PE5MD      */
                    unsigned short PE4MD:1;            /*   PE4MD      */
                    unsigned short PE3MD:1;            /*   PE3MD      */
                    unsigned short PE2MD:1;            /*   PE2MD      */
                    unsigned short PE1MD:1;            /*   PE1MD      */
                    unsigned short PE0MD:1;            /*   PE0MD      */
                    } BIT;                             /*              */
             } PECR;                                   /*              */
       unsigned char wk6[2];                           /*              */
       union {                                         /* PLIOR        */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short :2;                 /*              */
                    unsigned short PL13IOR:1;          /*   PL13IOR    */
                    unsigned short PL12IOR:1;          /*   PL12IOR    */
                    unsigned short PL11IOR:1;          /*   PL11IOR    */
                    unsigned short PL10IOR:1;          /*   PL10IOR    */
                    unsigned short PL9IOR:1;           /*   PL9IOR     */
                    unsigned short PL8IOR:1;           /*   PL8IOR     */
                    unsigned short PL7IOR:1;           /*   PL7IOR     */
                    unsigned short PL6IOR:1;           /*   PL6IOR     */
                    unsigned short PL5IOR:1;           /*   PL5IOR     */
                    unsigned short PL4IOR:1;           /*   PL4IOR     */
                    unsigned short PL3IOR:1;           /*   PL3IOR     */
                    unsigned short PL2IOR:1;           /*   PL2IOR     */
                    unsigned short PL1IOR:1;           /*   PL1IOR     */
                    unsigned short PL0IOR:1;           /*   PL0IOR     */
                    } BIT;                             /*              */
             } PLIOR;                                  /*              */
       union {                                         /* PLCRH        */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short :4;                 /*              */
                    unsigned short PL13MD:2;           /*   PL13MD     */
                    unsigned short PL12MD:2;           /*   PL12MD     */
                    unsigned short PL11MD:2;           /*   PL11MD     */
                    unsigned short PL10MD:2;           /*   PL10MD     */
                    unsigned short PL9MD:2;            /*   PL9MD      */
                    unsigned short :1;                 /*              */
                    unsigned short PL8MD:1;            /*   PL8MD      */
                    } BIT;                             /*              */
             } PLCRH;                                  /*              */
       union {                                         /* PLCRL        */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short PL7MD:2;            /*   PL7MD      */
                    unsigned short :1;                 /*              */
                    unsigned short PL6MD:1;            /*   PL6MD      */
                    unsigned short :1;                 /*              */
                    unsigned short PL5MD:1;            /*   PL5MD      */
                    unsigned short :1;                 /*              */
                    unsigned short PL4MD:1;            /*   PL4MD      */
                    unsigned short :1;                 /*              */
                    unsigned short PL3MD:1;            /*   PL3MD      */
                    unsigned short PL2MD:2;            /*   PL2MD      */
                    unsigned short PL1MD:2;            /*   PL1MD      */
                    unsigned short :1;                 /*              */
                    unsigned short PL0MD0:1;           /*   PL0MD0     */
                    } BIT;                             /*              */
             } PLCRL;                                  /*              */
       union {                                         /* PLIR         */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short :6;                 /*              */
                    unsigned short PL9IR:1;            /*   PL9IR      */
                    unsigned short PL8IR:1;            /*   PL8IR      */
                    unsigned short PL7IR:1;            /*   PL7IR      */
                    unsigned short :7;                 /*              */
                    } BIT;                             /*              */
             } PLIR;                                   /*              */
       unsigned char wk7[2];                           /*              */
       union {                                         /* PGIOR        */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short :12;                /*              */
                    unsigned short PG3IOR:1;           /*   PG3IOR     */
                    unsigned short PG2IOR:1;           /*   PG2IOR     */
                    unsigned short PG1IOR:1;           /*   PG1IOR     */
                    unsigned short PG0IOR:1;           /*   PG0IOR     */
                    } BIT;                             /*              */
             } PGIOR;                                  /*              */
       union {                                         /* PGCR         */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short :8;                 /*              */
                    unsigned short PG3MD:2;            /*   PG3MD      */
                    unsigned short PG2MD:2;            /*   PG2MD      */
                    unsigned short :1;                 /*              */
                    unsigned short PG1MD:1;            /*   PG1MD      */
                    unsigned short PG0MD:2;            /*   PG0MD      */
                    } BIT;                             /*              */
             } PGCR;                                   /*              */
       unsigned char wk8[2];                           /*              */
       union {                                         /* PJIOR        */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short PJ15IOR:1;          /*   PJ15IOR    */
                    unsigned short PJ14IOR:1;          /*   PJ14IOR    */
                    unsigned short PJ13IOR:1;          /*   PJ13IOR    */
                    unsigned short PJ12IOR:1;          /*   PJ12IOR    */
                    unsigned short PJ11IOR:1;          /*   PJ11IOR    */
                    unsigned short PJ10IOR:1;          /*   PJ10IOR    */
                    unsigned short PJ9IOR:1;           /*   PJ9IOR     */
                    unsigned short PJ8IOR:1;           /*   PJ8IOR     */
                    unsigned short PJ7IOR:1;           /*   PJ7IOR     */
                    unsigned short PJ6IOR:1;           /*   PJ6IOR     */
                    unsigned short PJ5IOR:1;           /*   PJ5IOR     */
                    unsigned short PJ4IOR:1;           /*   PJ4IOR     */
                    unsigned short PJ3IOR:1;           /*   PJ3IOR     */
                    unsigned short PJ2IOR:1;           /*   PJ2IOR     */
                    unsigned short PJ1IOR:1;           /*   PJ1IOR     */
                    unsigned short PJ0IOR:1;           /*   PJ0IOR     */
                    } BIT;                             /*              */
             } PJIOR;                                  /*              */
       union {                                         /* PJCRH        */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short :1;                 /*              */
                    unsigned short PJ15MD:1;           /*   PJ15MD     */
                    unsigned short :1;                 /*              */
                    unsigned short PJ14MD:1;           /*   PJ14MD     */
                    unsigned short :1;                 /*              */
                    unsigned short PJ13MD:1;           /*   PJ13MD     */
                    unsigned short :1;                 /*              */
                    unsigned short PJ12MD:1;           /*   PJ12MD     */
                    unsigned short :1;                 /*              */
                    unsigned short PJ11MD:1;           /*   PJ11MD     */
                    unsigned short :1;                 /*              */
                    unsigned short PJ10MD:1;           /*   PJ10MD     */
                    unsigned short :1;                 /*              */
                    unsigned short PJ9MD:1;            /*   PJ9MD      */
                    unsigned short :1;                 /*              */
                    unsigned short PJ8MD:1;            /*   PJ8MD      */
                    } BIT;                             /*              */
             } PJCRH;                                  /*              */
       union {                                         /* PJCRL        */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short :1;                 /*              */
                    unsigned short PJ7MD:1;            /*   PJ7MD      */
                    unsigned short :1;                 /*              */
                    unsigned short PJ6MD:1;            /*   PJ6MD      */
                    unsigned short :1;                 /*              */
                    unsigned short PJ5MD:1;            /*   PJ5MD      */
                    unsigned short :1;                 /*              */
                    unsigned short PJ4MD:1;            /*   PJ4MD      */
                    unsigned short :1;                 /*              */
                    unsigned short PJ3MD:1;            /*   PJ3MD      */
                    unsigned short :1;                 /*              */
                    unsigned short PJ2MD:1;            /*   PJ2MD      */
                    unsigned short :1;                 /*              */
                    unsigned short PJ1MD:1;            /*   PJ1MD      */
                    unsigned short :1;                 /*              */
                    unsigned short PJ0MD:1;            /*   PJ0MD      */
                    } BIT;                             /*              */
             } PJCRL;                                  /*              */
       unsigned char wk9[4];                           /*              */
       union {                                         /* PKIOR        */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short PK15IOR:1;          /*   PK15IOR    */
                    unsigned short PK14IOR:1;          /*   PK14IOR    */
                    unsigned short PK13IOR:1;          /*   PK13IOR    */
                    unsigned short PK12IOR:1;          /*   PK12IOR    */
                    unsigned short PK11IOR:1;          /*   PK11IOR    */
                    unsigned short PK10IOR:1;          /*   PK10IOR    */
                    unsigned short PK9IOR:1;           /*   PK9IOR     */
                    unsigned short PK8IOR:1;           /*   PK8IOR     */
                    unsigned short PK7IOR:1;           /*   PK7IOR     */
                    unsigned short PK6IOR:1;           /*   PK6IOR     */
                    unsigned short PK5IOR:1;           /*   PK5IOR     */
                    unsigned short PK4IOR:1;           /*   PK4IOR     */
                    unsigned short PK3IOR:1;           /*   PK3IOR     */
                    unsigned short PK2IOR:1;           /*   PK2IOR     */
                    unsigned short PK1IOR:1;           /*   PK1IOR     */
                    unsigned short PK0IOR:1;           /*   PK0IOR     */
                    } BIT;                             /*              */
             } PKIOR;                                  /*              */
       union {                                         /* PKCRH        */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short :1;                 /*              */
                    unsigned short PK15MD:1;           /*   PK15MD     */
                    unsigned short :1;                 /*              */
                    unsigned short PK14MD:1;           /*   PK14MD     */
                    unsigned short :1;                 /*              */
                    unsigned short PK13MD:1;           /*   PK13MD     */
                    unsigned short :1;                 /*              */
                    unsigned short PK12MD:1;           /*   PK12MD     */
                    unsigned short :1;                 /*              */
                    unsigned short PK11MD:1;           /*   PK11MD     */
                    unsigned short :1;                 /*              */
                    unsigned short PK10MD:1;           /*   PK10MD     */
                    unsigned short :1;                 /*              */
                    unsigned short PK9MD:1;            /*   PK9MD      */
                    unsigned short :1;                 /*              */
                    unsigned short PK8MD:1;            /*   PK8MD      */
                    } BIT;                             /*              */
             } PKCRH;                                  /*              */
       union {                                         /* PKCRL        */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short :1;                 /*              */
                    unsigned short PK7MD:1;            /*   PK7MD      */
                    unsigned short :1;                 /*              */
                    unsigned short PK6MD:1;            /*   PK6MD      */
                    unsigned short :1;                 /*              */
                    unsigned short PK5MD:1;            /*   PK5MD      */
                    unsigned short :1;                 /*              */
                    unsigned short PK4MD:1;            /*   PK4MD      */
                    unsigned short :1;                 /*              */
                    unsigned short PK3MD:1;            /*   PK3MD      */
                    unsigned short :1;                 /*              */
                    unsigned short PK2MD:1;            /*   PK2MD      */
                    unsigned short :1;                 /*              */
                    unsigned short PK1MD:1;            /*   PK1MD      */
                    unsigned short :1;                 /*              */
                    unsigned short PK0MD:1;            /*   PK0MD      */
                    } BIT;                             /*              */
             } PKCRL;                                  /*              */
       union {                                         /* PKIR         */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short PK15IR:1;           /*   PK15IR     */
                    unsigned short PK14IR:1;           /*   PK14IR     */
                    unsigned short PK13IR:1;           /*   PK13IR     */
                    unsigned short PK12IR:1;           /*   PK12IR     */
                    unsigned short PK11IR:1;           /*   PK11IR     */
                    unsigned short PK10IR:1;           /*   PK10IR     */
                    unsigned short PK9IR:1;            /*   PK9IR      */
                    unsigned short PK8IR:1;            /*   PK8IR      */
                    unsigned short PK7IR:1;            /*   PK7IR      */
                    unsigned short PK6IR:1;            /*   PK6IR      */
                    unsigned short PK5IR:1;            /*   PK5IR      */
                    unsigned short PK4IR:1;            /*   PK4IR      */
                    unsigned short PK3IR:1;            /*   PK3IR      */
                    unsigned short PK2IR:1;            /*   PK2IR      */
                    unsigned short PK1IR:1;            /*   PK1IR      */
                    unsigned short PK0IR:1;            /*   PK0IR      */
                    } BIT;                             /*              */
             } PKIR;                                   /*              */
};                                                     /*              */
struct st_port {                                       /* struct PORT  */
       union {                                         /* PADR         */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short PA15DR:1;           /*   PA15DR     */
                    unsigned short PA14DR:1;           /*   PA14DR     */
                    unsigned short PA13DR:1;           /*   PA13DR     */
                    unsigned short PA12DR:1;           /*   PA12DR     */
                    unsigned short PA11DR:1;           /*   PA11DR     */
                    unsigned short PA10DR:1;           /*   PA10DR     */
                    unsigned short PA9DR:1;            /*   PA9DR      */
                    unsigned short PA8DR:1;            /*   PA8DR      */
                    unsigned short PA7DR:1;            /*   PA7DR      */
                    unsigned short PA6DR:1;            /*   PA6DR      */
                    unsigned short PA5DR:1;            /*   PA5DR      */
                    unsigned short PA4DR:1;            /*   PA4DR      */
                    unsigned short PA3DR:1;            /*   PA3DR      */
                    unsigned short PA2DR:1;            /*   PA2DR      */
                    unsigned short PA1DR:1;            /*   PA1DR      */
                    unsigned short PA0DR:1;            /*   PA0DR      */
                    } BIT;                             /*              */
             } PADR;                                   /*              */
       unsigned char wk0[4];                           /*              */
       union {                                         /* PHDR         */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short PH15DR:1;           /*   PH15DR     */
                    unsigned short PH14DR:1;           /*   PH14DR     */
                    unsigned short PH13DR:1;           /*   PH13DR     */
                    unsigned short PH12DR:1;           /*   PH12DR     */
                    unsigned short PH11DR:1;           /*   PH11DR     */
                    unsigned short PH10DR:1;           /*   PH10DR     */
                    unsigned short PH9DR:1;            /*   PH9DR      */
                    unsigned short PH8DR:1;            /*   PH8DR      */
                    unsigned short PH7DR:1;            /*   PH7DR      */
                    unsigned short PH6DR:1;            /*   PH6DR      */
                    unsigned short PH5DR:1;            /*   PH5DR      */
                    unsigned short PH4DR:1;            /*   PH4DR      */
                    unsigned short PH3DR:1;            /*   PH3DR      */
                    unsigned short PH2DR:1;            /*   PH2DR      */
                    unsigned short PH1DR:1;            /*   PH1DR      */
                    unsigned short PH0DR:1;            /*   PH0DR      */
                    } BIT;                             /*              */
             } PHDR;                                   /*              */
       unsigned char wk1[10];                          /*              */
       union {                                         /* PBDR         */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short PB15DR:1;           /*   PB15DR     */
                    unsigned short PB14DR:1;           /*   PB14DR     */
                    unsigned short PB13DR:1;           /*   PB13DR     */
                    unsigned short PB12DR:1;           /*   PB12DR     */
                    unsigned short PB11DR:1;           /*   PB11DR     */
                    unsigned short PB10DR:1;           /*   PB10DR     */
                    unsigned short PB9DR:1;            /*   PB9DR      */
                    unsigned short PB8DR:1;            /*   PB8DR      */
                    unsigned short PB7DR:1;            /*   PB7DR      */
                    unsigned short PB6DR:1;            /*   PB6DR      */
                    unsigned short PB5DR:1;            /*   PB5DR      */
                    unsigned short PB4DR:1;            /*   PB4DR      */
                    unsigned short PB3DR:1;            /*   PB3DR      */
                    unsigned short PB2DR:1;            /*   PB2DR      */
                    unsigned short PB1DR:1;            /*   PB1DR      */
                    unsigned short PB0DR:1;            /*   PB0DR      */
                    } BIT;                             /*              */
             } PBDR;                                   /*              */
       unsigned char wk2[4];                           /*              */
       union {                                         /* PCDR         */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short :11;                /*              */
                    unsigned short PC4DR:1;            /*   PC4DR      */
                    unsigned short PC3DR:1;            /*   PC3DR      */
                    unsigned short PC2DR:1;            /*   PC2DR      */
                    unsigned short PC1DR:1;            /*   PC1DR      */
                    unsigned short PC0DR:1;            /*   PC0DR      */
                    } BIT;                             /*              */
             } PCDR;                                   /*              */
       unsigned char wk3[6];                           /*              */
       union {                                         /* PDDR         */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short :2;                 /*              */
                    unsigned short PD13DR:1;           /*   PD13DR     */
                    unsigned short PD12DR:1;           /*   PD12DR     */
                    unsigned short PD11DR:1;           /*   PD11DR     */
                    unsigned short PD10DR:1;           /*   PD10DR     */
                    unsigned short PD9DR:1;            /*   PD9DR      */
                    unsigned short PD8DR:1;            /*   PD8DR      */
                    unsigned short PD7DR:1;            /*   PD7DR      */
                    unsigned short PD6DR:1;            /*   PD6DR      */
                    unsigned short PD5DR:1;            /*   PD5DR      */
                    unsigned short PD4DR:1;            /*   PD4DR      */
                    unsigned short PD3DR:1;            /*   PD3DR      */
                    unsigned short PD2DR:1;            /*   PD2DR      */
                    unsigned short PD1DR:1;            /*   PD1DR      */
                    unsigned short PD0DR:1;            /*   PD0DR      */
                    } BIT;                             /*              */
             } PDDR;                                   /*              */
       unsigned char wk4[6];                           /*              */
       union {                                         /* PFDR         */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short PF15DR:1;           /*   PF15DR     */
                    unsigned short PF14DR:1;           /*   PF14DR     */
                    unsigned short PF13DR:1;           /*   PF13DR     */
                    unsigned short PF12DR:1;           /*   PF12DR     */
                    unsigned short PF11DR:1;           /*   PF11DR     */
                    unsigned short PF10DR:1;           /*   PF10DR     */
                    unsigned short PF9DR:1;            /*   PF9DR      */
                    unsigned short PF8DR:1;            /*   PF8DR      */
                    unsigned short PF7DR:1;            /*   PF7DR      */
                    unsigned short PF6DR:1;            /*   PF6DR      */
                    unsigned short PF5DR:1;            /*   PF5DR      */
                    unsigned short PF4DR:1;            /*   PF4DR      */
                    unsigned short PF3DR:1;            /*   PF3DR      */
                    unsigned short PF2DR:1;            /*   PF2DR      */
                    unsigned short PF1DR:1;            /*   PF1DR      */
                    unsigned short PF0DR:1;            /*   PF0DR      */
                    } BIT;                             /*              */
             } PFDR;                                   /*              */
       unsigned char wk5[4];                           /*              */
       union {                                         /* PEDR         */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short PE15DR:1;           /*   PE15DR     */
                    unsigned short PE14DR:1;           /*   PE14DR     */
                    unsigned short PE13DR:1;           /*   PE13DR     */
                    unsigned short PE12DR:1;           /*   PE12DR     */
                    unsigned short PE11DR:1;           /*   PE11DR     */
                    unsigned short PE10DR:1;           /*   PE10DR     */
                    unsigned short PE9DR:1;            /*   PE9DR      */
                    unsigned short PE8DR:1;            /*   PE8DR      */
                    unsigned short PE7DR:1;            /*   PE7DR      */
                    unsigned short PE6DR:1;            /*   PE6DR      */
                    unsigned short PE5DR:1;            /*   PE5DR      */
                    unsigned short PE4DR:1;            /*   PE4DR      */
                    unsigned short PE3DR:1;            /*   PE3DR      */
                    unsigned short PE2DR:1;            /*   PE2DR      */
                    unsigned short PE1DR:1;            /*   PE1DR      */
                    unsigned short PE0DR:1;            /*   PE0DR      */
                    } BIT;                             /*              */
             } PEDR;                                   /*              */
       unsigned char wk6[8];                           /*              */
       union {                                         /* PLDR         */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short :2;                 /*              */
                    unsigned short PL13DR:1;           /*   PL13DR     */
                    unsigned short PL12DR:1;           /*   PL12DR     */
                    unsigned short PL11DR:1;           /*   PL11DR     */
                    unsigned short PL10DR:1;           /*   PL10DR     */
                    unsigned short PL9DR:1;            /*   PL9DR      */
                    unsigned short PL8DR:1;            /*   PL8DR      */
                    unsigned short PL7DR:1;            /*   PL7DR      */
                    unsigned short PL6DR:1;            /*   PL6DR      */
                    unsigned short PL5DR:1;            /*   PL5DR      */
                    unsigned short PL4DR:1;            /*   PL4DR      */
                    unsigned short PL3DR:1;            /*   PL3DR      */
                    unsigned short PL2DR:1;            /*   PL2DR      */
                    unsigned short PL1DR:1;            /*   PL1DR      */
                    unsigned short PL0DR:1;            /*   PL0DR      */
                    } BIT;                             /*              */
             } PLDR;                                   /*              */
       unsigned char wk7[4];                           /*              */
       union {                                         /* PGDR         */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short :12;                /*              */
                    unsigned short PG3DR:1;            /*   PG3DR      */
                    unsigned short PG2DR:1;            /*   PG2DR      */
                    unsigned short PG1DR:1;            /*   PG1DR      */
                    unsigned short PG0DR:1;            /*   PG0DR      */
                    } BIT;                             /*              */
             } PGDR;                                   /*              */
       unsigned char wk8[6];                           /*              */
       union {                                         /* PJDR         */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short PJ15DR:1;           /*   PJ15DR     */
                    unsigned short PJ14DR:1;           /*   PJ14DR     */
                    unsigned short PJ13DR:1;           /*   PJ13DR     */
                    unsigned short PJ12DR:1;           /*   PJ12DR     */
                    unsigned short PJ11DR:1;           /*   PJ11DR     */
                    unsigned short PJ10DR:1;           /*   PJ10DR     */
                    unsigned short PJ9DR:1;            /*   PJ9DR      */
                    unsigned short PJ8DR:1;            /*   PJ8DR      */
                    unsigned short PJ7DR:1;            /*   PJ7DR      */
                    unsigned short PJ6DR:1;            /*   PJ6DR      */
                    unsigned short PJ5DR:1;            /*   PJ5DR      */
                    unsigned short PJ4DR:1;            /*   PJ4DR      */
                    unsigned short PJ3DR:1;            /*   PJ3DR      */
                    unsigned short PJ2DR:1;            /*   PJ2DR      */
                    unsigned short PJ1DR:1;            /*   PJ1DR      */
                    unsigned short PJ0DR:1;            /*   PJ0DR      */
                    } BIT;                             /*              */
             } PJDR;                                   /*              */
       unsigned char wk9[10];                          /*              */
       union {                                         /* PKDR         */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short PK15DR:1;           /*   PK15DR     */
                    unsigned short PK14DR:1;           /*   PK14DR     */
                    unsigned short PK13DR:1;           /*   PK13DR     */
                    unsigned short PK12DR:1;           /*   PK12DR     */
                    unsigned short PK11DR:1;           /*   PK11DR     */
                    unsigned short PK10DR:1;           /*   PK10DR     */
                    unsigned short PK9DR:1;            /*   PK9DR      */
                    unsigned short PK8DR:1;            /*   PK8DR      */
                    unsigned short PK7DR:1;            /*   PK7DR      */
                    unsigned short PK6DR:1;            /*   PK6DR      */
                    unsigned short PK5DR:1;            /*   PK5DR      */
                    unsigned short PK4DR:1;            /*   PK4DR      */
                    unsigned short PK3DR:1;            /*   PK3DR      */
                    unsigned short PK2DR:1;            /*   PK2DR      */
                    unsigned short PK1DR:1;            /*   PK1DR      */
                    unsigned short PK0DR:1;            /*   PK0DR      */
                    } BIT;                             /*              */
             } PKDR;                                   /*              */
       unsigned char wk10[6];                          /*              */
       union {                                         /* PAPR         */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short PA15PR:1;           /*   PA15PR     */
                    unsigned short PA14PR:1;           /*   PA14PR     */
                    unsigned short PA13PR:1;           /*   PA13PR     */
                    unsigned short PA12PR:1;           /*   PA12PR     */
                    unsigned short PA11PR:1;           /*   PA11PR     */
                    unsigned short PA10PR:1;           /*   PA10PR     */
                    unsigned short PA9PR:1;            /*   PA9PR      */
                    unsigned short PA8PR:1;            /*   PA8PR      */
                    unsigned short PA7PR:1;            /*   PA7PR      */
                    unsigned short PA6PR:1;            /*   PA6PR      */
                    unsigned short PA5PR:1;            /*   PA5PR      */
                    unsigned short PA4PR:1;            /*   PA4PR      */
                    unsigned short PA3PR:1;            /*   PA3PR      */
                    unsigned short PA2PR:1;            /*   PA2PR      */
                    unsigned short PA1PR:1;            /*   PA1PR      */
                    unsigned short PA0PR:1;            /*   PA0PR      */
                    } BIT;                             /*              */
             } PAPR;                                   /*              */
       union {                                         /* PBPR         */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short PB15PR:1;           /*   PB15PR     */
                    unsigned short PB14PR:1;           /*   PB14PR     */
                    unsigned short PB13PR:1;           /*   PB13PR     */
                    unsigned short PB12PR:1;           /*   PB12PR     */
                    unsigned short PB11PR:1;           /*   PB11PR     */
                    unsigned short PB10PR:1;           /*   PB10PR     */
                    unsigned short PB9PR:1;            /*   PB9PR      */
                    unsigned short PB8PR:1;            /*   PB8PR      */
                    unsigned short PB7PR:1;            /*   PB7PR      */
                    unsigned short PB6PR:1;            /*   PB6PR      */
                    unsigned short PB5PR:1;            /*   PB5PR      */
                    unsigned short PB4PR:1;            /*   PB4PR      */
                    unsigned short PB3PR:1;            /*   PB3PR      */
                    unsigned short PB2PR:1;            /*   PB2PR      */
                    unsigned short PB1PR:1;            /*   PB1PR      */
                    unsigned short PB0PR:1;            /*   PB0PR      */
                    } BIT;                             /*              */
             } PBPR;                                   /*              */
       union {                                         /* PDPR         */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short :2;                 /*              */
                    unsigned short PD13PR:1;           /*   PD13PR     */
                    unsigned short PD12PR:1;           /*   PD12PR     */
                    unsigned short PD11PR:1;           /*   PD11PR     */
                    unsigned short PD10PR:1;           /*   PD10PR     */
                    unsigned short PD9PR:1;            /*   PD9PR      */
                    unsigned short PD8PR:1;            /*   PD8PR      */
                    unsigned short PD7PR:1;            /*   PD7PR      */
                    unsigned short PD6PR:1;            /*   PD6PR      */
                    unsigned short PD5PR:1;            /*   PD5PR      */
                    unsigned short PD4PR:1;            /*   PD4PR      */
                    unsigned short PD3PR:1;            /*   PD3PR      */
                    unsigned short PD2PR:1;            /*   PD2PR      */
                    unsigned short PD1PR:1;            /*   PD1PR      */
                    unsigned short PD0PR:1;            /*   PD0PR      */
                    } BIT;                             /*              */
             } PDPR;                                   /*              */
       union {                                         /* PJPR         */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short PJ15PR:1;           /*   PJ15PR     */
                    unsigned short PJ14PR:1;           /*   PJ14PR     */
                    unsigned short PJ13PR:1;           /*   PJ13PR     */
                    unsigned short PJ12PR:1;           /*   PJ12PR     */
                    unsigned short PJ11PR:1;           /*   PJ11PR     */
                    unsigned short PJ10PR:1;           /*   PJ10PR     */
                    unsigned short PJ9PR:1;            /*   PJ9PR      */
                    unsigned short PJ8PR:1;            /*   PJ8PR      */
                    unsigned short PJ7PR:1;            /*   PJ7PR      */
                    unsigned short PJ6PR:1;            /*   PJ6PR      */
                    unsigned short PJ5PR:1;            /*   PJ5PR      */
                    unsigned short PJ4PR:1;            /*   PJ4PR      */
                    unsigned short PJ3PR:1;            /*   PJ3PR      */
                    unsigned short PJ2PR:1;            /*   PJ2PR      */
                    unsigned short PJ1PR:1;            /*   PJ1PR      */
                    unsigned short PJ0PR:1;            /*   PJ0PR      */
                    } BIT;                             /*              */
             } PJPR;                                   /*              */
       union {                                         /* PLPR         */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short :2;                 /*              */
                    unsigned short PL13PR:1;           /*   PL13PR     */
                    unsigned short PL12PR:1;           /*   PL12PR     */
                    unsigned short PL11PR:1;           /*   PL11PR     */
                    unsigned short PL10PR:1;           /*   PL10PR     */
                    unsigned short PL9PR:1;            /*   PL9PR      */
                    unsigned short PL8PR:1;            /*   PL8PR      */
                    unsigned short PL7PR:1;            /*   PL7PR      */
                    unsigned short PL6PR:1;            /*   PL6PR      */
                    unsigned short PL5PR:1;            /*   PL5PR      */
                    unsigned short PL4PR:1;            /*   PL4PR      */
                    unsigned short PL3PR:1;            /*   PL3PR      */
                    unsigned short PL2PR:1;            /*   PL2PR      */
                    unsigned short PL1PR:1;            /*   PL1PR      */
                    unsigned short PL0PR:1;            /*   PL0PR      */
                    } BIT;                             /*              */
             } PLPR;                                   /*              */
};                                                     /*              */
struct st_flash {                                      /* struct FLASH */
       union {                                         /* FCCS         */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char FWE:1;               /*   FWE        */
                    unsigned char :2;                  /*              */
                    unsigned char FLER:1;              /*   FLER       */
                    unsigned char :3;                  /*              */
                    unsigned char SCO:1;               /*   SCO        */
                    } BIT;                             /*              */
             } FCCS;                                   /*              */
       union {                                         /* FPCS         */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char :7;                  /*              */
                    unsigned char PPVS:1;              /*   PPVS       */
                    } BIT;                             /*              */
             } FPCS;                                   /*              */
       union {                                         /* FECS         */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char :7;                  /*              */
                    unsigned char EPVB:1;              /*   EPVB       */
                    } BIT;                             /*              */
             } FECS;                                   /*              */
       unsigned char wk0[1];                           /*              */
       unsigned char FKEY;                             /* FKEY         */
       unsigned char FMATS;                            /* FMATS        */
       union {                                         /* FTDAR        */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char TDER:1;              /*   TDER       */
                    unsigned char TDA:7;               /*   TDA        */
                    } BIT;                             /*              */
             } FTDAR;                                  /*              */
};                                                     /*              */
struct st_stby {                                       /* struct STBY  */
       union {                                         /* SBYCR        */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char SSBY:1;              /*   SSBY       */
                    unsigned char :1;                  /*              */
                    unsigned char SSBYF:1;             /*  SSBYF       */
		    unsigned char :5;                  /*              */
                    } BIT;                             /*              */
             } SBYCR;                                  /*              */
       unsigned char wk0[2803];                        /*              */
       union {                                         /* SYSCR1       */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char :6;                  /*              */
                    unsigned char AUDSRST:1;           /*   AUDSRST    */
                    unsigned char RAME:1;              /*   RAME       */
                    } BIT;                             /*              */
             } SYSCR1;                                 /*              */
       unsigned char wk1[2];                           /*              */
       union {                                         /* SYSCR2       */
             unsigned char BYTE;                       /*  Byte Access */
             struct {                                  /*  Bit Access  */
                    unsigned char :4;                  /*              */
                    unsigned char MSTOP:4;             /*   MSTOP      */
                    } BIT;                             /*              */
             } SYSCR2;                                 /*              */
};                                                     /*              */
struct st_hcan2 {                                      /* struct HCAN2 */
       union {                                         /* MCR          */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short :8;                 /*              */
                    unsigned short MCR7:1;             /*    MCR7      */
                    unsigned short :1;                 /*              */
                    unsigned short MCR5:1;             /*    MCR5      */
                    unsigned short :2;                 /*              */
                    unsigned short MCR2:1;             /*    MCR2      */
                    unsigned short MCR1:1;             /*    MCR1      */
                    unsigned short MCR0:1;             /*    MCR0      */
                    } BIT;                             /*              */
             } MCR;                                    /*              */
       union {                                         /* GSR          */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short :10;                /*              */
                    unsigned short GSR5:1;             /*    GSR5      */
                    unsigned short GSR4:1;             /*    GSR4      */
                    unsigned short GSR3:1;             /*    GSR3      */
                    unsigned short GSR2:1;             /*    GSR2      */
                    unsigned short GSR1:1;             /*    GSR1      */
                    unsigned short GSR0:1;             /*    GSR0      */
                    } BIT;                             /*              */
             } GSR;                                    /*              */
       union {                                         /* HCAN2_BCR1   */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short TSG1:4;             /*    TSG1      */
                    unsigned short :1;                 /*              */
                    unsigned short TSG2:3;             /*    TSG2      */
                    unsigned short :2;                 /*              */
                    unsigned short SJW:2;              /*    SJW       */
                    unsigned short :3;                 /*              */
                    unsigned short BSP:1;              /*    BSP       */
                    } BIT;                             /*              */
             } HCAN2_BCR1;                             /*              */
       union {                                         /* HCAN2_BCR0   */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short :8;                 /*              */
                    unsigned short BRP:8;              /*    BRP       */
                    } BIT;                             /*              */
             } HCAN2_BCR0;                             /*              */
       union {                                         /* IRR          */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short IRR15:1;            /*    IRR15     */
                    unsigned short IRR14:1;            /*    IRR14     */
                    unsigned short IRR13:1;            /*    IRR13     */
                    unsigned short IRR12:1;            /*    IRR12     */
                    unsigned short :2;                 /*              */
                    unsigned short IRR9:1;             /*    IRR9      */
                    unsigned short IRR8:1;             /*    IRR8      */
                    unsigned short IRR7:1;             /*    IRR7      */
                    unsigned short IRR6:1;             /*    IRR6      */
                    unsigned short IRR5:1;             /*    IRR5      */
                    unsigned short IRR4:1;             /*    IRR4      */
                    unsigned short IRR3:1;             /*    IRR3      */
                    unsigned short IRR2:1;             /*    IRR2      */
                    unsigned short IRR1:1;             /*    IRR1      */
                    unsigned short IRR0:1;             /*    IRR0      */
                    } BIT;                             /*              */
             } IRR;                                    /*              */
       union {                                         /* IMR          */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short IMR15:1;            /*    IMR15     */
                    unsigned short IMR14:1;            /*    IMR14     */
                    unsigned short IMR13:1;            /*    IMR13     */
                    unsigned short IMR12:1;            /*    IMR12     */
                    unsigned short :2;                 /*              */
                    unsigned short IMR9:1;             /*    IMR9      */
                    unsigned short IMR8:1;             /*    IMR8      */
                    unsigned short IMR7:1;             /*    IMR7      */
                    unsigned short IMR6:1;             /*    IMR6      */
                    unsigned short IMR5:1;             /*    IMR5      */
                    unsigned short IMR4:1;             /*    IMR4      */
                    unsigned short IMR3:1;             /*    IMR3      */
                    unsigned short IMR2:1;             /*    IMR2      */
                    unsigned short IMR1:1;             /*    IMR1      */
                    unsigned short :1;                 /*              */
                    } BIT;                             /*              */
             } IMR;                                    /*              */
       unsigned char TEC;                              /* TEC          */
       unsigned char REC;                              /* REC          */
       unsigned char wk0[18];                          /*              */
       union {                                         /* TXPR1        */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short TXPR31:1;           /*    TXPR31    */
                    unsigned short TXPR30:1;           /*    TXPR30    */
                    unsigned short TXPR29:1;           /*    TXPR29    */
                    unsigned short TXPR28:1;           /*    TXPR28    */
                    unsigned short TXPR27:1;           /*    TXPR27    */
                    unsigned short TXPR26:1;           /*    TXPR26    */
                    unsigned short TXPR25:1;           /*    TXPR25    */
                    unsigned short TXPR24:1;           /*    TXPR24    */
                    unsigned short TXPR23:1;           /*    TXPR23    */
                    unsigned short TXPR22:1;           /*    TXPR22    */
                    unsigned short TXPR21:1;           /*    TXPR21    */
                    unsigned short TXPR20:1;           /*    TXPR20    */
                    unsigned short TXPR19:1;           /*    TXPR19    */
                    unsigned short TXPR18:1;           /*    TXPR18    */
                    unsigned short TXPR17:1;           /*    TXPR17    */
                    unsigned short TXPR16:1;           /*    TXPR16    */
                    } BIT;                             /*              */
             } TXPR1;                                  /*              */
       union {                                         /* TXPR0        */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short TXPR15:1;           /*    TXPR15    */
                    unsigned short TXPR14:1;           /*    TXPR14    */
                    unsigned short TXPR13:1;           /*    TXPR13    */
                    unsigned short TXPR12:1;           /*    TXPR12    */
                    unsigned short TXPR11:1;           /*    TXPR11    */
                    unsigned short TXPR10:1;           /*    TXPR10    */
                    unsigned short TXPR9:1;            /*    TXPR9     */
                    unsigned short TXPR8:1;            /*    TXPR8     */
                    unsigned short TXPR7:1;            /*    TXPR7     */
                    unsigned short TXPR6:1;            /*    TXPR6     */
                    unsigned short TXPR5:1;            /*    TXPR5     */
                    unsigned short TXPR4:1;            /*    TXPR4     */
                    unsigned short TXPR3:1;            /*    TXPR3     */
                    unsigned short TXPR2:1;            /*    TXPR2     */
                    unsigned short TXPR1:1;            /*    TXPR1     */
                    unsigned short :1;                 /*              */
                    } BIT;                             /*              */
             } TXPR0;                                  /*              */
       unsigned char wk1[4];                           /*              */
       union {                                         /* TXCR1        */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short TXCR31:1;           /*    TXCR31    */
                    unsigned short TXCR30:1;           /*    TXCR30    */
                    unsigned short TCR29:1;            /*    TCR29     */
                    unsigned short TXCR28:1;           /*    TXCR28    */
                    unsigned short TXCR27:1;           /*    TXCR27    */
                    unsigned short TSCR26:1;           /*    TSCR26    */
                    unsigned short TXCR25:1;           /*    TXCR25    */
                    unsigned short TXCR24:1;           /*    TXCR24    */
                    unsigned short TXCR23:1;           /*    TXCR23    */
                    unsigned short TXCR22:1;           /*    TXCR22    */
                    unsigned short TXCR21:1;           /*    TXCR21    */
                    unsigned short TXCR20:1;           /*    TXCR20    */
                    unsigned short TXCR19:1;           /*    TXCR19    */
                    unsigned short TXCR18:1;           /*    TXCR18    */
                    unsigned short TXCR17:1;           /*    TXCR17    */
                    unsigned short TXCR16:1;           /*    TXCR16    */
                    } BIT;                             /*              */
             } TXCR1;                                  /*              */
       union {                                         /* TXCR0        */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short TXCR15:1;           /*    TXCR15    */
                    unsigned short TXCR14:1;           /*    TXCR14    */
                    unsigned short TCR13:1;            /*    TCR13     */
                    unsigned short TXCR12:1;           /*    TXCR12    */
                    unsigned short TXCR11:1;           /*    TXCR11    */
                    unsigned short TSCR10:1;           /*    TSCR10    */
                    unsigned short TXCR9:1;            /*    TXCR9     */
                    unsigned short TXCR8:1;            /*    TXCR8     */
                    unsigned short TXCR7:1;            /*    TXCR7     */
                    unsigned short TXCR6:1;            /*    TXCR6     */
                    unsigned short TXCR5:1;            /*    TXCR5     */
                    unsigned short TXCR4:1;            /*    TXCR4     */
                    unsigned short TXCR3:1;            /*    TXCR3     */
                    unsigned short TXCR2:1;            /*    TXCR2     */
                    unsigned short TXCR1:1;            /*    TXCR1     */
                    unsigned short :1;                 /*              */
                    } BIT;                             /*              */
             } TXCR0;                                  /*              */
       unsigned char wk2[4];                           /*              */
       union {                                         /* TXACK1       */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short TXACK31:1;          /*    TXACK31   */
                    unsigned short TXACK30:1;          /*    TXACK30   */
                    unsigned short TXACK29:1;          /*    TXACK29   */
                    unsigned short TXACK28:1;          /*    TXACK28   */
                    unsigned short TXACK27:1;          /*    TXACK27   */
                    unsigned short TXACK26:1;          /*    TXACK26   */
                    unsigned short TXACK25:1;          /*    TXACK25   */
                    unsigned short TXACK24:1;          /*    TXACK24   */
                    unsigned short TXACK23:1;          /*    TXACK23   */
                    unsigned short TXACK22:1;          /*    TXACK22   */
                    unsigned short TXACK21:1;          /*    TXACK21   */
                    unsigned short TXACK20:1;          /*    TXACK20   */
                    unsigned short TXACK19:1;          /*    TXACK19   */
                    unsigned short TXACK18:1;          /*    TXACK18   */
                    unsigned short TXACK17:1;          /*    TXACK17   */
                    unsigned short TXACK16:1;          /*    TXACK16   */
                    } BIT;                             /*              */
             } TXACK1;                                 /*              */
       union {                                         /* TXACK0       */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short TXACK15:1;          /*    TXACK15   */
                    unsigned short TXACK14:1;          /*    TXACK14   */
                    unsigned short TXACK13:1;          /*    TXACK13   */
                    unsigned short TXACK12:1;          /*    TXACK12   */
                    unsigned short TXACK11:1;          /*    TXACK11   */
                    unsigned short TXACK10:1;          /*    TXACK10   */
                    unsigned short TXACK9:1;           /*    TXACK9    */
                    unsigned short TXACK8:1;           /*    TXACK8    */
                    unsigned short TXACK7:1;           /*    TXACK7    */
                    unsigned short TXACK6:1;           /*    TXACK6    */
                    unsigned short TXACK5:1;           /*    TXACK5    */
                    unsigned short TXACK4:1;           /*    TXACK4    */
                    unsigned short TXACK3:1;           /*    TXACK3    */
                    unsigned short TXACK2:1;           /*    TXACK2    */
                    unsigned short TXACK1:1;           /*    TXACK1    */
                    unsigned short :1;                 /*              */
                    } BIT;                             /*              */
             } TXACK0;                                 /*              */
       unsigned char wk3[4];                           /*              */
       union {                                         /* ABACK1       */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short ABACK31:1;          /*    ABACK31   */
                    unsigned short ABACK30:1;          /*    ABACK30   */
                    unsigned short ABACK29:1;          /*    ABACK29   */
                    unsigned short ABACK28:1;          /*    ABACK28   */
                    unsigned short ABACK27:1;          /*    ABACK27   */
                    unsigned short ABACK26:1;          /*    ABACK26   */
                    unsigned short ABACK25:1;          /*    ABACK25   */
                    unsigned short ABACK24:1;          /*    ABACK24   */
                    unsigned short ABACK23:1;          /*    ABACK23   */
                    unsigned short ABACK22:1;          /*    ABACK22   */
                    unsigned short ABACK21:1;          /*    ABACK21   */
                    unsigned short ABACK20:1;          /*    ABACK20   */
                    unsigned short ABACK19:1;          /*    ABACK19   */
                    unsigned short ABACK18:1;          /*    ABACK18   */
                    unsigned short ABACK17:1;          /*    ABACK17   */
                    unsigned short ABACK16:1;          /*    ABACK16   */
                    } BIT;                             /*              */
             } ABACK1;                                 /*              */
       union {                                         /* ABACK0       */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short ABACK15:1;          /*    ABACK15   */
                    unsigned short ABACK14:1;          /*    ABACK14   */
                    unsigned short ABACK13:1;          /*    ABACK13   */
                    unsigned short ABACK12:1;          /*    ABACK12   */
                    unsigned short ABACK11:1;          /*    ABACK11   */
                    unsigned short ABACK10:1;          /*    ABACK10   */
                    unsigned short ABACK9:1;           /*    ABACK9    */
                    unsigned short ABACK8:1;           /*    ABACK8    */
                    unsigned short ABACK7:1;           /*    ABACK7    */
                    unsigned short ABACK6:1;           /*    ABACK6    */
                    unsigned short ABACK5:1;           /*    ABACK5    */
                    unsigned short ABACK4:1;           /*    ABACK4    */
                    unsigned short ABACK3:1;           /*    ABACK3    */
                    unsigned short ABACK2:1;           /*    ABACK2    */
                    unsigned short ABACK1:1;           /*    ABACK1    */
                    unsigned short :1;                 /*              */
                    } BIT;                             /*              */
             } ABACK0;                                 /*              */
       unsigned char wk4[4];                           /*              */
       union {                                         /* RXPR1        */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short RXPR31:1;           /*    RXPR31    */
                    unsigned short RXPR30:1;           /*    RXPR30    */
                    unsigned short RXPR29:1;           /*    RXPR29    */
                    unsigned short RXPR28:1;           /*    RXPR28    */
                    unsigned short RXPR27:1;           /*    RXPR27    */
                    unsigned short RXPR26:1;           /*    RXPR26    */
                    unsigned short RXPR25:1;           /*    RXPR25    */
                    unsigned short RXPR24:1;           /*    RXPR24    */
                    unsigned short RXPR23:1;           /*    RXPR23    */
                    unsigned short RXPR22:1;           /*    RXPR22    */
                    unsigned short RXPR21:1;           /*    RXPR21    */
                    unsigned short RXPR20:1;           /*    RXPR20    */
                    unsigned short RXPR19:1;           /*    RXPR19    */
                    unsigned short RXPR18:1;           /*    RXPR18    */
                    unsigned short RXPR17:1;           /*    RXPR17    */
                    unsigned short RXPR16:1;           /*    RXPR16    */
                    } BIT;                             /*              */
             } RXPR1;                                  /*              */
       union {                                         /* RXPR0        */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short RXPR15:1;           /*    RXPR15    */
                    unsigned short RXPR14:1;           /*    RXPR14    */
                    unsigned short RXPR13:1;           /*    RXPR13    */
                    unsigned short RXPR12:1;           /*    RXPR12    */
                    unsigned short RXPR11:1;           /*    RXPR11    */
                    unsigned short RXPR10:1;           /*    RXPR10    */
                    unsigned short RXPR9:1;            /*    RXPR9     */
                    unsigned short RXPR8:1;            /*    RXPR8     */
                    unsigned short RXPR7:1;            /*    RXPR7     */
                    unsigned short RXPR6:1;            /*    RXPR6     */
                    unsigned short RXPR5:1;            /*    RXPR5     */
                    unsigned short RXPR4:1;            /*    RXPR4     */
                    unsigned short RXPR3:1;            /*    RXPR3     */
                    unsigned short RXPR2:1;            /*    RXPR2     */
                    unsigned short RXPR1:1;            /*    RXPR1     */
                    unsigned short RXPR0:1;            /*    RXPR0     */
                    } BIT;                             /*              */
             } RXPR0;                                  /*              */
       unsigned char wk5[4];                           /*              */
       union {                                         /* RFPR1        */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short RFPR31:1;           /*    RFPR31    */
                    unsigned short RFPR30:1;           /*    RFPR30    */
                    unsigned short RFPR29:1;           /*    RFPR29    */
                    unsigned short RFPR28:1;           /*    RFPR28    */
                    unsigned short RFPR27:1;           /*    RFPR27    */
                    unsigned short RFPR26:1;           /*    RFPR26    */
                    unsigned short RFPR25:1;           /*    RFPR25    */
                    unsigned short RFPR24:1;           /*    RFPR24    */
                    unsigned short RFPR23:1;           /*    RFPR23    */
                    unsigned short RFPR22:1;           /*    RFPR22    */
                    unsigned short RFPR21:1;           /*    RFPR21    */
                    unsigned short RFPR20:1;           /*    RFPR20    */
                    unsigned short RFPR19:1;           /*    RFPR19    */
                    unsigned short RFPR18:1;           /*    RFPR18    */
                    unsigned short RFPR17:1;           /*    RFPR17    */
                    unsigned short RFPR16:1;           /*    RFPR16    */
                    } BIT;                             /*              */
             } RFPR1;                                  /*              */
       union {                                         /* RFPR0        */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short RFPR15:1;           /*    RFPR15    */
                    unsigned short RFPR14:1;           /*    RFPR14    */
                    unsigned short RFPR13:1;           /*    RFPR13    */
                    unsigned short RFPR12:1;           /*    RFPR12    */
                    unsigned short RFPR11:1;           /*    RFPR11    */
                    unsigned short RFPR10:1;           /*    RFPR10    */
                    unsigned short RFPR9:1;            /*    RFPR9     */
                    unsigned short RFPR8:1;            /*    RFPR8     */
                    unsigned short RFPR7:1;            /*    RFPR7     */
                    unsigned short RFPR6:1;            /*    RFPR6     */
                    unsigned short RFPR5:1;            /*    RFPR5     */
                    unsigned short RFPR4:1;            /*    RFPR4     */
                    unsigned short RFPR3:1;            /*    RFPR3     */
                    unsigned short RFPR2:1;            /*    RFPR2     */
                    unsigned short RFPR1:1;            /*    RFPR1     */
                    unsigned short RFPR0:1;            /*    RFPR0     */
                    } BIT;                             /*              */
             } RFPR0;                                  /*              */
       unsigned char wk6[4];                           /*              */
       union {                                         /* MBIMR1       */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short MBIMR31:1;          /*    MBIMR31   */
                    unsigned short MBIMR30:1;          /*    MBIMR30   */
                    unsigned short MBIMR29:1;          /*    MBIMR29   */
                    unsigned short MBIMR28:1;          /*    MBIMR28   */
                    unsigned short MBIMR27:1;          /*    MBIMR27   */
                    unsigned short MBIMR26:1;          /*    MBIMR26   */
                    unsigned short MBIMR25:1;          /*    MBIMR25   */
                    unsigned short MBIMR24:1;          /*    MBIMR24   */
                    unsigned short MBIMR23:1;          /*    MBIMR23   */
                    unsigned short MBIMR22:1;          /*    MBIMR22   */
                    unsigned short MBIMR21:1;          /*    MBIMR21   */
                    unsigned short MBIMR20:1;          /*    MBIMR20   */
                    unsigned short MBIMR19:1;          /*    MBIMR19   */
                    unsigned short MBIMR18:1;          /*    MBIMR18   */
                    unsigned short MBIMR17:1;          /*    MBIMR17   */
                    unsigned short MBIMR16:1;          /*    MBIMR16   */
                    } BIT;                             /*              */
             } MBIMR1;                                 /*              */
       union {                                         /* MBIMR0       */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short MBIMR15:1;          /*    MBIMR15   */
                    unsigned short MBIMR14:1;          /*    MBIMR14   */
                    unsigned short MBIMR13:1;          /*    MBIMR13   */
                    unsigned short MBIMR12:1;          /*    MBIMR12   */
                    unsigned short MBIMR11:1;          /*    MBIMR11   */
                    unsigned short MBIMR10:1;          /*    MBIMR10   */
                    unsigned short MBIMR9:1;           /*    MBIMR9    */
                    unsigned short MBIMR8:1;           /*    MBIMR8    */
                    unsigned short MBIMR7:1;           /*    MBIMR7    */
                    unsigned short MBIMR6:1;           /*    MBIMR6    */
                    unsigned short MBIMR5:1;           /*    MBIMR5    */
                    unsigned short MBIMR4:1;           /*    MBIMR4    */
                    unsigned short MBIMR3:1;           /*    MBIMR3    */
                    unsigned short MBIMR2:1;           /*    MBIMR2    */
                    unsigned short MBIMR1:1;           /*    MBIMR1    */
                    unsigned short MBIMR0:1;           /*    MBIMR0    */
                    } BIT;                             /*              */
             } MBIMR0;                                 /*              */
       unsigned char wk7[4];                           /*              */
       union {                                         /* UMSR1        */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short UMSR31:1;           /*    UMSR31    */
                    unsigned short UMSR30:1;           /*    UMSR30    */
                    unsigned short UMSR29:1;           /*    UMSR29    */
                    unsigned short UMSR28:1;           /*    UMSR28    */
                    unsigned short UMSR27:1;           /*    UMSR27    */
                    unsigned short UMSR26:1;           /*    UMSR26    */
                    unsigned short UMSR25:1;           /*    UMSR25    */
                    unsigned short UMSR24:1;           /*    UMSR24    */
                    unsigned short UMSR23:1;           /*    UMSR23    */
                    unsigned short UMSR22:1;           /*    UMSR22    */
                    unsigned short UMSR21:1;           /*    UMSR21    */
                    unsigned short UMSR20:1;           /*    UMSR20    */
                    unsigned short UMSR19:1;           /*    UMSR19    */
                    unsigned short UMSR18:1;           /*    UMSR18    */
                    unsigned short UMSR17:1;           /*    UMSR17    */
                    unsigned short UMSR16:1;           /*    UMSR16    */
                    } BIT;                             /*              */
             } UMSR1;                                  /*              */
       union {                                         /* UMSR0        */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short UMSR15:1;           /*    UMSR15    */
                    unsigned short UMSR14:1;           /*    UMSR14    */
                    unsigned short UMSR13:1;           /*    UMSR13    */
                    unsigned short UMSR12:1;           /*    UMSR12    */
                    unsigned short UMSR11:1;           /*    UMSR11    */
                    unsigned short UMSR10:1;           /*    UMSR10    */
                    unsigned short UMSR9:1;            /*    UMSR9     */
                    } BIT;                             /*              */
             } UMSR0;                                  /*              */
       unsigned char wk8[36];                          /*              */
       unsigned short TCNTR;                           /* TCNTR        */
       union {                                         /* TCR          */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short TCR15:1;            /*    TCR15     */
                    unsigned short TCR14:1;            /*    TCR14     */
                    unsigned short TCR13:1;            /*    TCR13     */
                    unsigned short TCR12:1;            /*    TCR12     */
                    unsigned short TCR11:1;            /*    TCR11     */
                    unsigned short TCR10:1;            /*    TCR10     */
                    unsigned short TCR9:1;             /*    TCR9      */
                    unsigned short TCR8:1;             /*    TCR8      */
                    unsigned short TCR7:1;             /*    TCR7      */
                    unsigned short :1;                 /*              */
                    unsigned short TPSC:6;             /*    TPSC      */
                    } BIT;                             /*              */
             } TCR;                                    /*              */
       union {                                         /* TSR          */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short :13;                /*              */
                    unsigned short TSR2:1;             /*    TSR2      */
                    unsigned short TSR1:1;             /*    TSR1      */
                    unsigned short TSR0:1;             /*    TSR0      */
                    } BIT;                             /*              */
             } TSR;                                    /*              */
       unsigned short TDCR;                            /* TDCR         */
       unsigned short LOSR;                            /* LOSR         */
       unsigned char wk9[2];                           /*              */
       unsigned short HCAN2_ICR0;                      /* HCAN2_ICR0   */
       unsigned short HCAN2_ICR1;                      /* HCAN2_ICR1   */
       unsigned short TCMR0;                           /* TCMR0        */
       unsigned short TCMR1;                           /* TCMR1        */
       unsigned char wk10[108];                        /*              */
         
    struct st_mb {	   
	   union {                                         /* CTRLH        */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short :1;                 /*              */
                    unsigned short STDID:11;           /*    STDID     */
                    unsigned short RTR:1;              /*    RTR       */
                    unsigned short IDE:1;              /*    IDE       */
                    unsigned short EXTID:2;            /*    EXTID     */
                    } BIT;                             /*              */
             } CTRLH;                                  /*              */
       union {                                         /* CTRLM        */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short EXTID:16;           /*    EXTID     */
                     } BIT;                            /*              */
             } CTRLM;                                  /*              */
       union {                                         /* CTRLL        */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short CCM:1;              /*    CCM       */
                    unsigned short TTE:1;              /*    TTE       */
                    unsigned short NMC:1;              /*    NMC       */
                    unsigned short ATX:1;              /*    ATX       */
                    unsigned short DART:1;             /*    DART      */
                    unsigned short MBC:3;              /*    MBC       */
                    unsigned short PTE:1;              /*    PTE       */
                    unsigned short TCT:1;              /*    TCT       */
                    unsigned short CBE:1;              /*    CBE       */
                    unsigned short :1;                 /*              */
                    unsigned short DLC:4;              /*    DLC       */
                    } BIT;                             /*              */
             } CTRLL;                                  /*              */
       unsigned short TIME_STAMP;                      /* TIME_STAMP   */
       unsigned char MSG_DATA[8];                      /* MSG_DATA     */
	   union {                                         /* LAFMH        */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short :1;                 /*              */
                    unsigned short STDID:11;           /*   STDID      */
                    unsigned short :2;                 /*              */
                    unsigned short EXTID:2;            /*   EXTID      */
                    } BIT;                             /*              */
             } LAFMH;  
       union {                                         /* LAFML        */
             unsigned short WORD;                      /*  Word Access */
             struct {                                  /*  Bit Access  */
                    unsigned short EXTID:16;           /*    EXTID     */
                     } BIT;                            /*              */
             } LAFML; 	   
       unsigned char wk12[12];                         /*              */
	}mb[32];
};                                                     /*              */
#define P_INTC (*(volatile struct st_intc *)0xFFFFED00)/* INTC Address */
#define P_UBC (*(volatile struct st_ubc *)0xFFFFEC00)  /* UBC Address  */
#define P_BSC (*(volatile struct st_bsc *)0xFFFFEC20)  /* BSC Address  */
#define P_DMAC (*(volatile struct st_dmac *)0xFFFFECB0)/* DMAC Address */
#define P_DMAC0 (*(volatile struct st_dmac0 *)0xFFFFECC0)/* DMAC0 Address*/
#define P_DMAC1 (*(volatile struct st_dmac1 *)0xFFFFECD0)/* DMAC1 Address*/
#define P_DMAC2 (*(volatile struct st_dmac2 *)0xFFFFECE0)/* DMAC2 Address*/
#define P_DMAC3 (*(volatile struct st_dmac3 *)0xFFFFECF0)/* DMAC3 Address*/
#define P_ATUII (*(volatile struct st_atuii *)0xFFFFF400)/* ATU-II Address*/
#define P_ATUII0 (*(volatile struct st_atuii0 *)0xFFFFF420)/* ATU-II0 Address*/
#define P_ATUII1 (*(volatile struct st_atuii1 *)0xFFFFF440)/* ATU-II1 Address*/
#define P_ATUII2 (*(volatile struct st_atuii2 *)0xFFFFF600)/* ATU-II2 Address*/
#define P_ATUII345 (*(volatile struct st_atuii345 *)0xFFFFF480)/* ATU-II345 Address*/
#define P_ATUII3 (*(volatile struct st_atuii3 *)0xFFFFF4A0)/* ATU-II3 Address*/
#define P_ATUII4 (*(volatile struct st_atuii4 *)0xFFFFF4C0)/* ATU-II4 Address*/
#define P_ATUII5 (*(volatile struct st_atuii5 *)0xFFFFF4E0)/* ATU-II5 Address*/
#define P_ATUII6 (*(volatile struct st_atuii6 *)0xFFFFF500)/* ATU-II6 Address*/
#define P_ATUII7 (*(volatile struct st_atuii7 *)0xFFFFF580)/* ATU-II7 Address*/
#define P_ATUII8 (*(volatile struct st_atuii8 *)0xFFFFF640)/* ATU-II8 Address*/
#define P_ATUII9 (*(volatile struct st_atuii9 *)0xFFFFF680)/* ATU-II9 Address*/
#define P_ATUII10 (*(volatile struct st_atuii10 *)0xFFFFF6C0)/* ATU-II10 Address*/
#define P_ATUII11 (*(volatile struct st_atuii11 *)0xFFFFF5C0)/* ATU-II11 Address*/
#define P_APC (*(volatile struct st_apc *)0xFFFFF700)  /* APC Address  */
#define P_WDT (*(volatile struct st_wdt *)0xFFFFEC10)  /* WDT Address  */
#define P_CMT (*(volatile struct st_cmt *)0xFFFFF710)  /* CMT Address  */
#define P_SCI0 (*(volatile struct st_sci0 *)0xFFFFF000)/* SCI0 Address */
#define P_SCI1 (*(volatile struct st_sci1 *)0xFFFFF008)/* SCI1 Address */
#define P_SCI2 (*(volatile struct st_sci2 *)0xFFFFF010)/* SCI2 Address */
#define P_SCI3 (*(volatile struct st_sci3 *)0xFFFFF018)/* SCI3 Address */
#define P_SCI4 (*(volatile struct st_sci4 *)0xFFFFF020)/* SCI4 Address */
#define P_SSU_0 (*(volatile struct st_ssu0 *)0xFFFFFC00)/* SSU_0 Address */
#define P_SSU_1 (*(volatile struct st_ssu1 *)0xFFFFFC10)/* SSU_1 Address */
#define P_AD (*(volatile struct st_ad *)0xFFFFF72E)    /* A/D Address  */
#define P_HUDI (*(volatile struct st_hudi *)0xFFFFF7C0)/* H-UDI Address*/
#define P_PFC (*(volatile struct st_pfc *)0xFFFFF720)  /* PFC Address  */
#define P_PORT (*(volatile struct st_port *)0xFFFFF726)/* PORT Address */
#define P_FLASH (*(volatile struct st_flash *)0xFFFFE800)/* FLASH Address*/
#define P_STBY (*(volatile struct st_stby *)0xFFFFEC14)/* STBY Address */
#define P_HCAN0 (*(volatile struct st_hcan2 *)0xFFFFD000)/* HCAN2 Address */
#define P_HCAN1 (*(volatile struct st_hcan2 *)0xFFFFD800)/* HCAN2 Address */
