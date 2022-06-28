                                                                           
                                                                           
                                                                           
                                                                           
                                                                           
                                                                           
                                                                           
                                                                           
                                                                           
                                                       
/***********************************************************************************
*
* Device   : SH2A-FPU/SH7253
*
* File Name: iodefine.h
* Abstract : Definition of I/O Register.
* 
* History  : 0.8  (2008-06-06)  [Hardware Manual Revision : 0.8]
*            1.0  (2009-10-06) Full-fledged revision
*            1.11 (2014-04-03)  [Hardware Manual Revision : 1.00]
*
* NOTE       : THIS IS A TYPICAL EXAMPLE.
*
* Copyright(c) 2008(2009-2014) Renesas Electronics Corporation and
* Renesas Solutions Corp. All rights reserved.
*
***********************************************************************************/
#ifndef _SH7253_H
#define _SH7253_H

/***********************************************************************************
 *   SH725x Register Definitions                                                   *
 **********************************************************************************/


/***********************************************************************************
    Interrupt Controller (INTC)
***********************************************************************************/
struct st_intc                                /* struct INTC      */
{                                             /*                  */
    union                                     /*                  */
    {                                         /* ICR0             */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned short NMIL:1;            /*   NMIL           */
            unsigned short reserved1:6;       /*   Reserved Bits  */
            unsigned short NMIE:1;            /*   NMIE           */
            unsigned short reserved2:8;       /*   Reserved Bits  */
        }BIT;                                 /*                  */
    }ICR0;                                    /*                  */

    union                                     /*                  */
    {                                         /* ICR1             */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned short reserved:8;        /*   Reserved Bits  */
            unsigned short IRQ3S:2;           /*   IRQ3S          */
			unsigned short IRQ2S:2;           /*   IRQ2S          */
			unsigned short IRQ1S:2;           /*   IRQ1S          */
			unsigned short IRQ0S:2;           /*   IRQ0S          */
        }BIT;                                 /*                  */
    }ICR1;                                    /*                  */

    unsigned char dummy1[2];

    union                                     /*                  */
    {                                         /* IRQRR            */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned short reserved:12;       /*   Reserved Bits  */
            unsigned short IRQ3F:1;           /*   IRQ3F          */
            unsigned short IRQ2F:1;           /*   IRQ2F          */
            unsigned short IRQ1F:1;           /*   IRQ1F          */
            unsigned short IRQ0F:1;           /*   IRQ0F          */
        }BIT;                                 /*                  */
    }IRQRR;                                   /*                  */

    unsigned char dummy2[4];

    union                                     /*                  */
    {                                         /* IBCR             */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned short E15:1;             /*   E15            */
            unsigned short E14:1;             /*   E14            */
            unsigned short E13:1;             /*   E13            */
            unsigned short E12:1;             /*   E12            */
            unsigned short E11:1;             /*   E11            */
            unsigned short E10:1;             /*   E10            */
            unsigned short E9:1;              /*   E9             */
            unsigned short E8:1;              /*   E8             */
            unsigned short E7:1;              /*   E7             */
            unsigned short E6:1;              /*   E6             */
            unsigned short E5:1;              /*   E5             */
            unsigned short E4:1;              /*   E4             */
            unsigned short E3:1;              /*   E3             */
            unsigned short E2:1;              /*   E2             */
            unsigned short E1:1;              /*   E1             */
            unsigned short reserved:1;        /*   Reserved Bits  */
        }BIT;                                 /*                  */
    }IBCR;                                    /*                  */

    union                                     /*                  */
    {                                         /* IBNR             */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned short BE:2;              /*   BE[1:0]        */
            unsigned short BOVE:1;            /*   BOVE           */
            unsigned short reserved:9;        /*   Reserved Bits  */
            unsigned short BN:4;              /*   BN[3:0]        */
        }BIT;                                 /*                  */
    }IBNR;                                    /*                  */

    union                                     /*                  */
    {                                         /* SINTR1           */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved:7;         /*   Reserved Bits  */
            unsigned char SINTC:1;            /*   SINTC          */
        }BIT;                                 /*                  */
    }SINTR1;                                  /*                  */

    union                                     /*                  */
    {                                         /* SINTR2           */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved:7;         /*   Reserved Bits  */
            unsigned char SINTC:1;            /*   SINTC          */
        }BIT;                                 /*                  */
    }SINTR2;                                  /*                  */

    union                                     /*                  */
    {                                         /* SINTR3           */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved:7;         /*   Reserved Bits  */
            unsigned char SINTC:1;            /*   SINTC          */
        }BIT;                                 /*                  */
    }SINTR3;                                  /*                  */

    union                                     /*                  */
    {                                         /* SINTR4           */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved:7;         /*   Reserved Bits  */
            unsigned char SINTC:1;            /*   SINTC          */
        }BIT;                                 /*                  */
    }SINTR4;                                  /*                  */

    union                                     /*                  */
    {                                         /* SINTR5           */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved:7;         /*   Reserved Bits  */
            unsigned char SINTC:1;            /*   SINTC          */
        }BIT;                                 /*                  */
    }SINTR5;                                  /*                  */

    union                                     /*                  */
    {                                         /* SINTR6           */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved:7;         /*   Reserved Bits  */
            unsigned char SINTC:1;            /*   SINTC          */
        }BIT;                                 /*                  */
    }SINTR6;                                  /*                  */

    union                                     /*                  */
    {                                         /* SINTR7           */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved:7;         /*   Reserved Bits  */
            unsigned char SINTC:1;            /*   SINTC          */
        }BIT;                                 /*                  */
    }SINTR7;                                  /*                  */

    union                                     /*                  */
    {                                         /* SINTR8           */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved:7;         /*   Reserved Bits  */
            unsigned char SINTC:1;            /*   SINTC          */
        }BIT;                                 /*                  */
    }SINTR8;                                  /*                  */

    union                                     /*                  */
    {                                         /* IPR01            */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned short IRQ0:4;            /*   IRQ0[3:0]      */
            unsigned short IRQ1:4;            /*   IRQ1[3:0]      */
            unsigned short IRQ2:4;            /*   IRQ2[3:0]      */
            unsigned short IRQ3:4;            /*   IRQ3[3:0]      */
        }BIT;                                 /*                  */
    }IPR01;                                   /*                  */

    union                                     /*                  */
    {                                         /* IPR02            */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned short reserved1:4;       /*   Reserved Bits  */
            unsigned short reserved2:4;       /*   Reserved Bits  */
            unsigned short reserved3:4;       /*   Reserved Bits  */
            unsigned short reserved4:4;       /*   Reserved Bits  */
        }BIT;                                 /*                  */
    }IPR02;                                   /*                  */

    unsigned char dummy3[12];

    union                                     /*                  */
    {                                         /* SINTR9           */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved:7;         /*   Reserved Bits  */
            unsigned char SINTC:1;            /*   SINTC          */
        }BIT;                                 /*                  */
    }SINTR9;                                  /*                  */

    union                                     /*                  */
    {                                         /* SINTR10          */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved:7;         /*   Reserved Bits  */
            unsigned char SINTC:1;            /*   SINTC          */
        }BIT;                                 /*                  */
    }SINTR10;                                 /*                  */

    union                                     /*                  */
    {                                         /* SINTR11          */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved:7;         /*   Reserved Bits  */
            unsigned char SINTC:1;            /*   SINTC          */
        }BIT;                                 /*                  */
    }SINTR11;                                 /*                  */

    union                                     /*                  */
    {                                         /* SINTR12          */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved:7;         /*   Reserved Bits  */
            unsigned char SINTC:1;            /*   SINTC          */
        }BIT;                                 /*                  */
    }SINTR12;                                 /*                  */

    union                                     /*                  */
    {                                         /* SINTR13          */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved:7;         /*   Reserved Bits  */
            unsigned char SINTC:1;            /*   SINTC          */
        }BIT;                                 /*                  */
    }SINTR13;                                 /*                  */

    union                                     /*                  */
    {                                         /* SINTR14          */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved:7;         /*   Reserved Bits  */
            unsigned char SINTC:1;            /*   SINTC          */
        }BIT;                                 /*                  */
    }SINTR14;                                 /*                  */

    union                                     /*                  */
    {                                         /* SINTR15          */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved:7;         /*   Reserved Bits  */
            unsigned char SINTC:1;            /*   SINTC          */
        }BIT;                                 /*                  */
    }SINTR15;                                 /*                  */

    unsigned char dummy4[(0xFFFE0C00u-0xFFFE082Eu-1)];


    union                                     /*                  */
    {                                         /* IPR03            */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned short IPL_DMAC0:4;       /*   DMAC0[3:0]     */
            unsigned short IPL_DMAC1:4;       /*   DMAC1[3:0]     */
            unsigned short IPL_DMAC2:4;       /*   DMAC2[3:0]     */
            unsigned short IPL_DMAC3:4;       /*   DMAC3[3:0]     */
        }BIT;                                 /*                  */
    }IPR03;                                   /*                  */

    union                                     /*                  */
    {                                         /* IPR04            */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned short IPL_DMAC4:4;       /*   DMAC4[3:0]     */
            unsigned short IPL_DMAC5:4;       /*   DMAC5[3:0]     */
            unsigned short IPL_DMAC6:4;       /*   DMAC6[3:0]     */
            unsigned short IPL_DMAC7:4;       /*   DMAC7[3:0]     */
        }BIT;                                 /*                  */
    }IPR04;                                   /*                  */

    union                                     /*                  */
    {                                         /* IPR05            */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned short CMT0:4;            /*   CMT0[3:0]      */
            unsigned short CMT1:4;            /*   CMT1[3:0]      */
            unsigned short reserved:4;        /*   Reserved Bits  */
            unsigned short IPL_WDT:4;         /*   WDT[3:0]       */
        }BIT;                                 /*                  */
    }IPR05;                                   /*                  */

    union                                     /*                  */
    {                                         /* IPR06            */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned short ICIA0_1:4;         /*   ICIA0_1[3:0]   */
            unsigned short ICIA2_3:4;         /*   ICIA2_3[3:0]   */
            unsigned short reserved:4;        /*  Reserved Bits   */
            unsigned short OVIA:4;            /*   OVIA[3:0]      */
        }BIT;                                 /*                  */
    }IPR06;                                   /*                  */

    union                                     /*                  */
    {                                         /* IPR07            */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned short CMIB0_1:4;         /*   CMIB0_1[3:0]   */
            unsigned short CMIB6_ICIB0:4;     /* CMIB6_ICIB0[3:0] */
            unsigned short IMIC00_03:4;       /*  IMIC00_03[3:0]  */
            unsigned short OVIC0:4;           /*   OVIC0[3:0]     */
        }BIT;                                 /*                  */
    }IPR07;                                   /*                  */

    union                                     /*                  */
    {                                         /* IPR08            */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned short IMIC10_13:4;       /*  IMIC10_13[3:0]  */
            unsigned short OVIC1:4;           /*   OVIC1[3:0]     */
            unsigned short IMIC20_23:4;       /*  IMIC20_23[3:0]  */
            unsigned short OVIC2:4;           /*   OVIC2[3:0]     */
        }BIT;                                 /*                  */
    }IPR08;                                   /*                  */

    union                                     /*                  */
    {                                         /* IPR09            */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned short IMIC30_33:4;       /*  IMIC30_33[3:0]  */
            unsigned short OVIC3:4;           /*   OVIC3[3:0]     */
            unsigned short IMIC40_43:4;       /*  IMIC40_43[3:0]  */
            unsigned short OVIC4:4;           /*   OVIC4[3:0]     */
        }BIT;                                 /*                  */
    }IPR09;                                   /*                  */

    union                                     /*                  */
    {                                         /* IPR10            */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned short CMID00_03:4;       /*  CMID00_03[3:0]  */
            unsigned short OVI1D0_2D0:4;      /*  OVI1D0_2D0[3:0] */
            unsigned short UDID00_03:4;       /*  UDID00_03[3:0]  */
            unsigned short CMID10_13:4;       /*  CMID10_13[3:0]  */
        }BIT;                                 /*                  */
    }IPR10;                                   /*                  */

    union                                     /*                  */
    {                                         /* IPR11            */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned short OVI1D1_2D1:4;      /*  OVI1D1_2D1[3:0] */
            unsigned short UDID10_13:4;       /*  UDID10_13[3:0]  */
            unsigned short CMID20_23:4;       /*  CMID20_23[3:0]  */
            unsigned short OVI1D2_2D2:4;      /*  OVI1D2_2D2[3:0] */
        }BIT;                                 /*                  */
    }IPR11;                                   /*                  */

    union                                     /*                  */
    {                                         /* IPR12            */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned short UDID20_23:4;       /*  UDID20_23[3:0]  */
            unsigned short CMID30_33:4;       /*  CMID30_33[3:0]  */
            unsigned short OVI1D3_2D3:4;      /*  OVI1D3_2D3[3:0] */
            unsigned short UDID30_33:4;       /*  UDID30_33[3:0]  */
        }BIT;                                 /*                  */
    }IPR12;                                   /*                  */

    union                                     /*                  */
    {                                         /* IPR13            */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned short reserved1:4;       /*  Reserved Bits   */
            unsigned short reserved2:4;       /*  Reserved Bits   */
            unsigned short reserved3:4;       /*  Reserved Bits   */
            unsigned short reserved4:4;       /*  Reserved Bits   */
        }BIT;                                 /*                  */
    }IPR13;                                   /*                  */

    union                                     /*                  */
    {                                         /* IPR14            */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned short reserved1:4;       /*  Reserved Bits   */
            unsigned short reserved2:4;       /*  Reserved Bits   */
            unsigned short CMIE00_03:4;       /*  CMIE00_03[3:0]  */
            unsigned short CMIE10_13:4;       /*  CMIE10_13[3:0]  */
        }BIT;                                 /*                  */
    }IPR14;                                   /*                  */

    union                                     /*                  */
    {                                         /* IPR15            */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned short CMIE20_23:4;       /*  CMIE20_23[3:0]  */
            unsigned short CMIE30_33:4;       /*  CMIE30_33[3:0]  */
            unsigned short CMIE40_43:4;       /*  CMIE40_43[3:0]  */
            unsigned short reserved:4;        /*  Reserved Bits   */
        }BIT;                                 /*                  */
    }IPR15;                                   /*                  */

    union                                     /*                  */
    {                                         /* IPR16            */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned short ICIF0_3:4;         /*   ICIF0_3[3:0]   */
            unsigned short ICIF4_7:4;         /*   ICIF4_7[3:0]   */
            unsigned short ICIF8_11:4;        /*   ICIF8_11[3:0]  */
            unsigned short ICIF12_15:4;       /*   ICIF12_15[3:0] */
        }BIT;                                 /*                  */
    }IPR16;                                   /*                  */

    union                                     /*                  */
    {                                         /* IPR17            */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned short ICIF16_19:4;       /*   ICIF16_19[3:0] */
            unsigned short reserved1:4;       /*   Reserved Bits  */
            unsigned short reserved2:4;       /*   Reserved Bits  */
            unsigned short reserved3:4;       /*   Reserved Bits  */
        }BIT;                                 /*                  */
    }IPR17;                                   /*                  */

    union                                     /*                  */
    {                                         /* IPR18            */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned short OVIF0_3:4;         /*   OVIF0_3[3:0]   */
            unsigned short OVIF4_7:4;         /*   OVIF4_7[3:0]   */
            unsigned short OVIF8_11:4;        /*   OVIF8_11[3:0]  */
            unsigned short OVIF12_15:4;       /*   OVIF12_15[3:0] */
        }BIT;                                 /*                  */
    }IPR18;                                   /*                  */

    union                                     /*                  */
    {                                         /* IPR19            */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned short OVIF16_19:4;       /*   OVIF16_19[3:0] */
            unsigned short reserved1:4;       /*   Reserved Bits  */
            unsigned short reserved2:4;       /*   Reserved Bits  */
            unsigned short reserved3:4;       /*   Reserved Bits  */
        }BIT;                                 /*                  */
    }IPR19;                                   /*                  */

    union                                     /*                  */
    {                                         /* IPR20            */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned short CMIG0_3:4;         /*   CMIG0_3[3:0]   */
            unsigned short CMIG4_5:4;         /*   CMIG4_5[3:0]   */
            unsigned short CMIH:4;            /*   CMIH[3:0]      */
            unsigned short reserved:4;        /*   Reserved Bits  */
        }BIT;                                 /*                  */
    }IPR20;                                   /*                  */

    union                                     /*                  */
    {                                         /* IPR21            */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned short DFIJ0_1:4;         /*   DFIJ0_1[3:0]   */
            unsigned short OVIJ0_1:4;         /*   OVIJ0_1[3:0]   */
            unsigned short DOVIJ0_1:4;        /*   DOVIJ0_1[3:0]  */
            unsigned short reserved:4;        /*   Reserved Bits  */
        }BIT;                                 /*                  */
    }IPR21;                                   /*                  */

    union                                     /*                  */
    {                                         /* IPR22            */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned short ADI0:4;            /*   ADI0[3:0]      */
            unsigned short ADI1:4;            /*   ADI1[3:0]      */
            unsigned short ADID0_3:4;         /*   ADID0_3[3:0]   */
            unsigned short ADID4_7:4;         /*   ADID4_7[3:0]   */
        }BIT;                                 /*                  */
    }IPR22;                                   /*                  */

    union                                     /*                  */
    {                                         /* IPR23            */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned short ADID8_11:4;        /*   ADID8_11[3:0]  */
            unsigned short ADID12_15:4;       /*   ADID12_15[3:0] */
            unsigned short ADID40:4;          /*   ADID40[3:0]    */
            unsigned short ADID41:4;          /*   ADID41[3:0]    */
        }BIT;                                 /*                  */
    }IPR23;                                   /*                  */

    union                                     /*                  */
    {                                         /* IPR24            */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned short ADID42:4;          /*   ADID42[3:0]    */
            unsigned short ADID43:4;          /*   ADID43[3:0]    */
            unsigned short ADID44:4;          /*   ADID44[3:0]    */
            unsigned short ADID45:4;          /*   ADID45[3:0]    */
        }BIT;                                 /*                  */
    }IPR24;                                   /*                  */

    union                                     /*                  */
    {                                         /* IPR25            */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned short ADID46:4;          /*   ADID46[3:0]    */
            unsigned short ADID47:4;          /*   ADID47[3:0]    */
            unsigned short reserved1:4;       /*   Reserved Bits  */
            unsigned short reserved2:4;       /*   Reserved Bits  */
        }BIT;                                 /*                  */
    }IPR25;                                   /*                  */

    union                                     /*                  */
    {                                         /* IPR26            */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned short IPL_SCIA:4;        /*   SCIA[3:0]      */
            unsigned short IPL_SCIB:4;        /*   SCIB[3:0]      */
            unsigned short IPL_SCIC:4;        /*   SCIC[3:0]      */
            unsigned short reserved:4;        /*  Reserved Bits   */
        }BIT;                                 /*                  */
    }IPR26;                                   /*                  */

    union                                     /*                  */
    {                                         /* IPR27            */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned short reserved1:4;       /*   SCIE[3:0]      */
            unsigned short IPL_RSPIA:4;       /*   RSPIA[3:0]     */
            unsigned short IPL_RSPIB:4;       /*   RSPIB[3:0]     */
            unsigned short reserved2:4;       /*  Reserved Bits   */
        }BIT;                                 /*                  */
    }IPR27;                                   /*                  */

    union                                     /*                  */
    {                                         /* IPR28            */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned short IPL_RCANA:4;       /*   RCANA[3:0]     */
            unsigned short IPL_RCANB:4;       /*   RCANB[3:0]     */
            unsigned short reserved1:4;       /*   Reserved Bits  */
            unsigned short reserved2:4;       /*   Reserved Bits  */
        }BIT;                                 /*                  */
    }IPR28;                                   /*                  */

    union                                     /*                  */
    {                                         /* IPR29            */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned short A_DMAC:4;          /*   A_DMAC[3:0]    */
            unsigned short reserved1:4;       /*   Reserved Bits  */
            unsigned short reserved2:4;       /*   Reserved Bits  */
            unsigned short reserved3:4;       /*   Reserved Bits  */
        }BIT;                                 /*                  */
    }IPR29;                                   /*                  */
};

/***********************************************************************************
    User Break Controller (UBC)
***********************************************************************************/
struct st_ubc                                 /* struct UBC       */
{
    unsigned long BAR_0;                      /* BAR_0            */

    unsigned long BAMR_0;                     /* BAMR_0           */

    unsigned char dummy1[8];

    unsigned long BAR_1;                      /* BAR_1            */

    unsigned long BAMR_1;                     /* BAMR_1           */

    unsigned char dummy2[8];

    unsigned long BAR_2;                      /* BAR_2            */

    unsigned long BAMR_2;                     /* BAMR_2           */

    unsigned char dummy3[8];

    unsigned long BAR_3;                      /* BAR_3            */

    unsigned long BAMR_3;                     /* BAMR_3           */

    unsigned char dummy4[(0xFFFC04A0u-0xFFFC0434u-4)];

    union                                     /*                  */
    {                                         /* BBR_0            */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned short reserved1:2;       /*   Reserved Bits  */
            unsigned short UBID0:1;           /*   UBID0          */
            unsigned short reserved2:2;       /*   Reserved Bits  */
            unsigned short CP0_:3;            /*   CP0_ [2:0]     */
            unsigned short CD0_:2;            /*   CD0_ [1:0]     */
            unsigned short ID0_:2;            /*   ID0_ [1:0]     */
            unsigned short RW0_:2;            /*   RW0_ [1:0]     */
            unsigned short SZ0_:2;            /*   SZ0_ [1:0]     */
        }BIT;                                 /*                  */
    }BBR_0;                                   /*                  */

    unsigned char dummy5[2];

    union                                     /*                  */
    {                                         /* BBR_2            */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned short reserved1:2;       /*   Reserved Bits  */
            unsigned short UBID2:1;           /*   UBID2          */
            unsigned short reserved2:2;       /*   Reserved Bits  */
            unsigned short CP2_:3;            /*   CP2_ [2:0]     */
            unsigned short CD2_:2;            /*   CD2_ [1:0]     */
            unsigned short ID2_:2;            /*   ID2_ [1:0]     */
            unsigned short RW2_:2;            /*   RW2_ [1:0]     */
            unsigned short SZ2_:2;            /*   SZ2_ [1:0]     */
        }BIT;                                 /*                  */
    }BBR_2;                                   /*                  */

    unsigned char dummy6[10];

    union                                     /*                  */
    {                                         /* BBR_1            */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned short reserved1:2;       /*   Reserved Bits  */
            unsigned short UBID1:1;           /*   UBID1          */
            unsigned short reserved2:2;       /*   Reserved Bits  */
            unsigned short CP1_:3;            /*   CP1_ [2:0]     */
            unsigned short CD1_:2;            /*   CD1_ [1:0]     */
            unsigned short ID1_:2;            /*   ID1_ [1:0]     */
            unsigned short RW1_:2;            /*   RW1_ [1:0]     */
            unsigned short SZ1_:2;            /*   SZ1_ [1:0]     */
        }BIT;                                 /*                  */
    }BBR_1;                                   /*                  */

    unsigned char dummy7[2];

    union                                     /*                  */
    {                                         /* BBR_3            */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned short reserved1:2;       /*   Reserved Bits  */
            unsigned short UBID3:1;           /*   UBID3          */
            unsigned short reserved2:2;       /*   Reserved Bits  */
            unsigned short CP3_:3;            /*   CP3_ [2:0]     */
            unsigned short CD3_:2;            /*   CD3_ [1:0]     */
            unsigned short ID3_:2;            /*   ID3_ [1:0]     */
            unsigned short RW3_:2;            /*   RW3_ [1:0]     */
            unsigned short SZ3_:2;            /*   SZ3_ [1:0]     */
        }BIT;                                 /*                  */
    }BBR_3;                                   /*                  */

    unsigned char dummy8[10];

    union                                     /*                  */
    {                                         /* BRCR             */
        unsigned long LONG;                   /*  Long Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved1:8;        /*   Reserved Bits  */
            unsigned char reserved2:8;        /*   Reserved Bits  */
            unsigned char SCMFC0:1;           /*   SCMFC0         */
            unsigned char SCMFC1:1;           /*   SCMFC1         */
            unsigned char SCMFC2:1;           /*   SCMFC2         */
            unsigned char SCMFC3:1;           /*   SCMFC3         */
            unsigned char SCMFD0:1;           /*   SCMFD0         */
            unsigned char SCMFD1:1;           /*   SCMFD1         */
            unsigned char SCMFD2:1;           /*   SCMFD2         */
            unsigned char SCMFD3:1;           /*   SCMFD3         */
            unsigned char PCB3:1;             /*   PCB3           */
            unsigned char PCB2:1;             /*   PCB2           */
            unsigned char PCB1:1;             /*   PCB1           */
            unsigned char PCB0:1;             /*   PCB0           */
            unsigned char reserved3:4;        /*   Reserved Bits  */
        }BIT;                                 /*                  */
    }BRCR;                                    /*                  */
};

/***********************************************************************************
    Direct Memory Access Controller (DMAC)
***********************************************************************************/
struct st_dmac03                              /* struct DMAC(0-3) */
{                                             /*                  */
    unsigned long SAR;                        /* SAR              */
                                              /*                  */
    unsigned long DAR;                        /* DAR              */
                                              /*                  */
    unsigned long DMATCR;                     /* DMATCR           */
                                              /*                  */
    union                                     /*                  */
    {                                         /* CHCR             */
        unsigned long LONG;                   /*  Long Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char TC:2;               /*   TC[1:0]        */
            unsigned char reserved1:1;        /*   Reserved Bits  */
            unsigned char RLD1:1;             /*   RLD1           */
            unsigned char RLD2:2;             /*   RLD2[1:0]      */
            unsigned char reserved2:1;        /*   Reserved Bits  */
            unsigned char IFT:1;              /*   IFT            */
            unsigned char reserved3:5;        /*   Reserved Bits  */
            unsigned char HIE:1;              /*   HIE            */
            unsigned char reserved4:2;        /*   Reserved Bits  */
            unsigned char DM:2;               /*   DM[1:0]        */
            unsigned char SM:2;               /*   SM[1:0]        */
            unsigned char RS:4;               /*   RS[3:0]        */
            unsigned char reserved5:2;        /*   Reserved Bits  */
            unsigned char TB:1;               /*   TB             */
            unsigned char TS:2;               /*   TS[1:0]        */
            unsigned char IE:1;               /*   IE             */
            unsigned char reserved6:1;        /*   Reserved Bits  */
            unsigned char DE:1;               /*   DE             */
        }BIT;                                 /*                  */
    }CHCR;                                    /*                  */
                                              /*                  */
    unsigned char dummy1[0x7C];               /*                  */
                                              /*                  */
    union                                     /*                  */
    {                                         /* CHFR             */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved1:3;        /*   Reserved Bits  */
            unsigned char HE:1;               /*   HE             */
            unsigned char reserved2:3;        /*   Reserved Bits  */
            unsigned char TE:1;               /*   TE             */
        }BIT;                                 /*                  */
    }CHFR;                                    /*                  */
                                              /*                  */
    unsigned char dummy2[1];                  /*                  */

    union
    {
        unsigned short WORD;                  /*                  */
        struct
        {
            unsigned short TEMKEY:8;          /*    TEMKEY[7:0]   */
            unsigned short reserved:7;        /*    Reserved Bits */
            unsigned short TEMASK:1;          /*    TEMASK        */
        }BIT;                                 /*                  */
    }TEMSK;                                   /*                  */
                                              /*                  */

    unsigned char dummy3[(0xFFFE1100u-0xFFFE108Eu-2)];

                                              /*                  */
    unsigned long RSAR;                       /* RSAR             */
                                              /*                  */
    unsigned long RDAR;                       /* RDAR             */
                                              /*                  */
    unsigned long RDMATCR;                    /* RDMATCR          */
};

struct st_dmac47                              /* struct DMAC(4-7) */
{                                             /*                  */
    unsigned long SAR;                        /* SAR              */
                                              /*                  */
    unsigned long DAR;                        /* DAR              */
                                              /*                  */
    unsigned long DMATCR;                     /* DMATCR           */
                                              /*                  */
    union                                     /*                  */
    {                                         /* CHCR             */
        unsigned long LONG;                   /*  Long Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char TC:2;               /*   TC[1:0]        */
            unsigned char reserved1:1;        /*   Reserved Bits  */
            unsigned char RLD1:1;             /*   RLD1           */
            unsigned char RLD2:2;             /*   RLD2[1:0]      */
            unsigned char reserved2:1;        /*   Reserved Bits  */
            unsigned char IFT:1;              /*   IFT            */
            unsigned char reserved3:5;        /*   Reserved Bits  */
            unsigned char HIE:1;              /*   HIE            */
            unsigned char reserved4:2;        /*   Reserved Bits  */
            unsigned char DM:2;               /*   DM[1:0]        */
            unsigned char SM:2;               /*   SM[1:0]        */
            unsigned char RS:4;               /*   RS[3:0]        */
            unsigned char reserved5:2;        /*   Reserved Bits  */
            unsigned char TB:1;               /*   TB             */
            unsigned char TS:2;               /*   TS[1:0]        */
            unsigned char IE:1;               /*   IE             */
            unsigned char reserved6:1;        /*   Reserved Bits  */
            unsigned char DE:1;               /*   DE             */
        }BIT;                                 /*                  */
    }CHCR;                                    /*                  */
                                              /*                  */
    unsigned char dummy1[0x7C];               /*                  */
                                              /*                  */
    union                                     /*                  */
    {                                         /* CHFR             */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved1:3;        /*   Reserved Bits  */
            unsigned char HE:1;               /*   HE             */
            unsigned char reserved2:3;        /*   Reserved Bits  */
            unsigned char TE:1;               /*   TE             */
        }BIT;                                 /*                  */
    }CHFR;                                    /*                  */
                                              /*                  */
    unsigned char dummy2[1];                  /*                  */

    union
    {                                         /* TEMSK            */
        unsigned short WORD;                  /*  Word Access     */
        struct
        {
            unsigned short TEMKEY:8;          /*    TEMKEY[7:0]   */
            unsigned short reserved:7;        /*    Reserved Bits */
            unsigned short TEMASK:1;          /*    TEMASK        */
        }BIT;                                 /*                  */
    }TEMSK;                                   /*                  */
                                              /*                  */

    unsigned char dummy3[(0xFFFE1100u-0xFFFE108Eu-2)];

                                              /*                  */
    unsigned long RSAR;                       /* RSAR             */
                                              /*                  */
    unsigned long RDAR;                       /* RDAR             */
                                              /*                  */
    unsigned long RDMATCR;                    /* RDMATCR          */
                                              /*                  */
    unsigned short ARCR;                      /* ARCR             */
                                              /*                  */
    unsigned short RARCR;                     /* RARCR            */
};

/* resource select registers to be implemented as array: DMARS[3].DMARS and .dummy */

struct st_dmaccom                             /* DMAC Common      */
{
    union                                     /*                  */
    {                                         /* DMAOR            */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned short reserved1:2;       /*   Reserved Bits  */
            unsigned short CMS:2;             /*   CMS[1:0]       */
            unsigned short reserved2:2;       /*   Reserved Bits  */
            unsigned short PR:2;              /*   PR[1:0]        */
            unsigned short reserved3:7;       /*   Reserved Bits  */
            unsigned short DME:1;             /*   DME            */
        }BIT;                                 /*                  */
    }DMAOR;                                   /*                  */

    unsigned char dummy1[2];

    union                                     /*                  */
    {                                         /* DMAFR            */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved1:3;        /*   Reserved Bits  */
            unsigned char AE:1;               /*   AE             */
            unsigned char reserved2:3;        /*   Reserved Bits  */
            unsigned char NMIF:1;             /*   NMIF           */
        }BIT;                                 /*                  */
    }DMAFR;                                   /*                  */

    unsigned char dummy2[(0xFFFE1300u-0xFFFE1204u-1)];

    struct
    {
        union                                 /*                  */
        {                                     /* DMARS            */
            unsigned short WORD;              /* Word Access      */
            struct                            /*                  */
            {                                 /* Bit Access       */
                unsigned short ODDCHMID:6;    /* ODDCHMID[5:0]    */
                unsigned short ODDCHRID:2;    /* ODDCHRID[1:0]    */
                unsigned short EVENCHMID:6;   /* EVENCHMID[5:0]   */
                unsigned short EVENCHRID:2;   /* EVENCHRID[1:0]   */
            }BIT;                             /*                  */
        }DMARS;                               /*                  */

        unsigned char dummy[2];
    }DMARS[4];
};


/***********************************************************************************
    Automotive Direct Memory Access Controller (A-DMAC)
***********************************************************************************/
struct st_admac                               /* struct ADMAC     */
{                                             /*                  */
    union                                     /*                  */
    {                                         /* ADMAOR           */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved:7;         /*   Reserved Bits  */
            unsigned char DME:1;              /*   DME            */
        }BIT;                                 /*                  */
    }ADMAOR;                                  /*                  */

    unsigned char dummy1[1];

    union                                     /*                  */
    {                                         /* ADMAABR          */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved:5;         /*   Reserved Bits  */
            unsigned char AA:3;               /*   AA[2:0]        */
        }BIT;                                 /*                  */
    }ADMAABR;                                 /*                  */

    unsigned char dummy2[13];

    union                                     /*                  */
    {                                         /* ADMAIE0          */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved1:2;        /*   Reserved Bits  */
            unsigned char Channel5:1;         /*   Channel5       */
            unsigned char Channel4:1;         /*   Channel4       */
            unsigned char Channel3:1;         /*   Channel3       */
            unsigned char Channel2:1;         /*   Channel2       */
            unsigned char reserved2:2;        /*   Reserved Bits  */
        }BIT;                                 /*                  */
    }ADMAIE0;                                 /*                  */

    union                                     /*                  */
    {                                         /* ADMAIE1          */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char Channel15:1;        /*   Channel15      */
            unsigned char Channel14:1;        /*   Channel14      */
            unsigned char Channel13:1;        /*   Channel13      */
            unsigned char Channel12:1;        /*   Channel12      */
            unsigned char Channel11:1;        /*   Channel11      */
            unsigned char Channel10:1;        /*   Channel10      */
            unsigned char Channel9:1;         /*   Channel9       */
            unsigned char Channel8:1;         /*   Channel8       */
        }BIT;                                 /*                  */
    }ADMAIE1;                                 /*                  */

    union                                     /*                  */
    {                                         /* ADMAIE2          */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char Channel23:1;        /*   Channel23      */
            unsigned char Channel22:1;        /*   Channel22      */
            unsigned char Channel21:1;        /*   Channel21      */
            unsigned char Channel20:1;        /*   Channel20      */
            unsigned char Channel19:1;        /*   Channel19      */
            unsigned char Channel18:1;        /*   Channel18      */
            unsigned char Channel17:1;        /*   Channel17      */
            unsigned char Channel16:1;        /*   Channel16      */
        }BIT;                                 /*                  */
    }ADMAIE2;                                 /*                  */

    union                                     /*                  */
    {                                         /* ADMAIE3          */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char Channel31:1;        /*   Channel31      */
            unsigned char Channel30:1;        /*   Channel30      */
            unsigned char Channel29:1;        /*   Channel29      */
            unsigned char Channel28:1;        /*   Channel28      */
            unsigned char Channel27:1;        /*   Channel27      */
            unsigned char Channel26:1;        /*   Channel26      */
            unsigned char Channel25:1;        /*   Channel25      */
            unsigned char Channel24:1;        /*   Channel24      */
        }BIT;                                 /*                  */
    }ADMAIE3;                                 /*                  */

    union                                     /*                  */
    {                                         /* ADMAIE4          */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char Channel39:1;        /*   Channel39      */
            unsigned char Channel38:1;        /*   Channel38      */
            unsigned char Channel37:1;        /*   Channel37      */
            unsigned char Channel36:1;        /*   Channel36      */
            unsigned char Channel35:1;        /*   Channel35      */
            unsigned char Channel34:1;        /*   Channel34      */
            unsigned char Channel33:1;        /*   Channel33      */
            unsigned char Channel32:1;        /*   Channel32      */
        }BIT;                                 /*                  */
    }ADMAIE4;                                 /*                  */

    union                                     /*                  */
    {                                         /* ADMAIE5          */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char Channel47:1;        /*   Channel47      */
            unsigned char Channel46:1;        /*   Channel46      */
            unsigned char Channel45:1;        /*   Channel45      */
            unsigned char Channel44:1;        /*   Channel44      */
            unsigned char Channel43:1;        /*   Channel43      */
            unsigned char Channel42:1;        /*   Channel42      */
            unsigned char Channel41:1;        /*   Channel41      */
            unsigned char Channel40:1;        /*   Channel40      */
        }BIT;                                 /*                  */
    }ADMAIE5;                                 /*                  */

    unsigned char dummy3[1];

    union                                     /*                  */
    {                                         /* ADMAIE7          */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char Channel63:1;        /*   Channel63      */
            unsigned char Channel62:1;        /*   Channel62      */
            unsigned char reserved:2;         /*   Reserved Bits  */
            unsigned char Channel59:1;        /*   Channel59      */
            unsigned char Channel58:1;        /*   Channel58      */
            unsigned char Channel57:1;        /*   Channel57      */
            unsigned char Channel56:1;        /*   Channel56      */
        }BIT;                                 /*                  */
    }ADMAIE7;                                 /*                  */

    union                                     /*                  */
    {                                         /* ADMAIE8          */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved:4;         /*   Reserved Bits  */
            unsigned char Channel67:1;        /*   Channel67      */
            unsigned char Channel66:1;        /*   Channel66      */
            unsigned char Channel65:1;        /*   Channel65      */
            unsigned char Channel64:1;        /*   Channel64      */
        }BIT;                                 /*                  */
    }ADMAIE8;                                 /*                  */

    union                                     /*                  */
    {                                         /* ADMAIE9          */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved1:5;        /*   Reserved Bits  */
            unsigned char Channel74:1;        /*   Channel74      */
            unsigned char reserved2:2;        /*   Reserved Bits  */
        }BIT;                                 /*                  */
    }ADMAIE9;                                 /*                  */

    unsigned char dummy4[6];

    union                                     /*                  */
    {                                         /* ADMADV0          */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved1:2;        /*   Reserved Bits  */
            unsigned char Channel5:1;         /*   Channel5       */
            unsigned char Channel4:1;         /*   Channel4       */
            unsigned char Channel3:1;         /*   Channel3       */
            unsigned char Channel2:1;         /*   Channel2       */
            unsigned char reserved2:2;        /*   Reserved Bits  */
        }BIT;                                 /*                  */
    }ADMADV0;                                 /*                  */

    union                                     /*                  */
    {                                         /* ADMADV1          */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char Channel15:1;        /*   Channel15      */
            unsigned char Channel14:1;        /*   Channel14      */
            unsigned char Channel13:1;        /*   Channel13      */
            unsigned char Channel12:1;        /*   Channel12      */
            unsigned char Channel11:1;        /*   Channel11      */
            unsigned char Channel10:1;        /*   Channel10      */
            unsigned char Channel9:1;         /*   Channel9       */
            unsigned char Channel8:1;         /*   Channel8       */
        }BIT;                                 /*                  */
    }ADMADV1;                                 /*                  */

    union                                     /*                  */
    {                                         /* ADMADV2          */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char Channel23:1;        /*   Channel23      */
            unsigned char Channel22:1;        /*   Channel22      */
            unsigned char Channel21:1;        /*   Channel21      */
            unsigned char Channel20:1;        /*   Channel20      */
            unsigned char Channel19:1;        /*   Channel19      */
            unsigned char Channel18:1;        /*   Channel18      */
            unsigned char Channel17:1;        /*   Channel17      */
            unsigned char Channel16:1;        /*   Channel16      */
        }BIT;                                 /*                  */
    }ADMADV2;                                 /*                  */

    union                                     /*                  */
    {                                         /* ADMADV3          */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char Channel31:1;        /*   Channel31      */
            unsigned char Channel30:1;        /*   Channel30      */
            unsigned char Channel29:1;        /*   Channel29      */
            unsigned char Channel28:1;        /*   Channel28      */
            unsigned char Channel27:1;        /*   Channel27      */
            unsigned char Channel26:1;        /*   Channel26      */
            unsigned char Channel25:1;        /*   Channel25      */
            unsigned char Channel24:1;        /*   Channel24      */
        }BIT;                                 /*                  */
    }ADMADV3;                                 /*                  */

    union                                     /*                  */
    {                                         /* ADMADV4          */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char Channel39:1;        /*   Channel39      */
            unsigned char Channel38:1;        /*   Channel38      */
            unsigned char Channel37:1;        /*   Channel37      */
            unsigned char Channel36:1;        /*   Channel36      */
            unsigned char Channel35:1;        /*   Channel35      */
            unsigned char Channel34:1;        /*   Channel34      */
            unsigned char Channel33:1;        /*   Channel33      */
            unsigned char Channel32:1;        /*   Channel32      */
        }BIT;                                 /*                  */
    }ADMADV4;                                 /*                  */

    union                                     /*                  */
    {                                         /* ADMADV5          */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char Channel47:1;        /*   Channel47      */
            unsigned char Channel46:1;        /*   Channel46      */
            unsigned char Channel45:1;        /*   Channel45      */
            unsigned char Channel44:1;        /*   Channel44      */
            unsigned char Channel43:1;        /*   Channel43      */
            unsigned char Channel42:1;        /*   Channel42      */
            unsigned char Channel41:1;        /*   Channel41      */
            unsigned char Channel40:1;        /*   Channel40      */
        }BIT;                                 /*                  */
    }ADMADV5;                                 /*                  */

    unsigned char dummy5[10];

    union                                     /*                  */
    {                                         /* ADMATE0          */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char Channel63:1;        /*   Channel63      */
            unsigned char Channel62:1;        /*   Channel62      */
            unsigned char reserved:2;         /*   Reserved Bits  */
            unsigned char Channel59:1;        /*   Channel59      */
            unsigned char Channel58:1;        /*   Channel58      */
            unsigned char Channel57:1;        /*   Channel57      */
            unsigned char Channel56:1;        /*   Channel56      */
        }BIT;                                 /*                  */
    }ADMATE0;                                 /*                  */

    union                                     /*                  */
    {                                         /* ADMATE1          */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved:4;         /*   Reserved Bits  */
            unsigned char Channel67:1;        /*   Channel67      */
            unsigned char Channel66:1;        /*   Channel66      */
            unsigned char Channel65:1;        /*   Channel65      */
            unsigned char Channel64:1;        /*   Channel64      */
        }BIT;                                 /*                  */
    }ADMATE1;                                 /*                  */

    union                                     /*                  */
    {                                         /* ADMATE2          */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved1:5;        /*   Reserved Bits  */
            unsigned char Channel74:1;        /*   Channel74      */
            unsigned char reserved2:2;        /*   Reserved Bits  */
        }BIT;                                 /*                  */
    }ADMATE2;                                 /*                  */

    unsigned char dummy6[13];

    union                                     /*                  */
    {                                         /* ADMADE0          */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved1:2;        /*   Reserved Bits  */
            unsigned char Channel5:1;         /*   Channel5       */
            unsigned char Channel4:1;         /*   Channel4       */
            unsigned char Channel3:1;         /*   Channel3       */
            unsigned char Channel2:1;         /*   Channel2       */
            unsigned char reserved2:2;        /*   Reserved Bits  */
        }BIT;                                 /*                  */
    }ADMADE0;                                 /*                  */

    union                                     /*                  */
    {                                         /* ADMADE1          */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char Channel15:1;        /*   Channel15      */
            unsigned char Channel14:1;        /*   Channel14      */
            unsigned char Channel13:1;        /*   Channel13      */
            unsigned char Channel12:1;        /*   Channel12      */
            unsigned char Channel11:1;        /*   Channel11      */
            unsigned char Channel10:1;        /*   Channel10      */
            unsigned char Channel9:1;         /*   Channel9       */
            unsigned char Channel8:1;         /*   Channel8       */
        }BIT;                                 /*                  */
    }ADMADE1;                                 /*                  */

    union                                     /*                  */
    {                                         /* ADMADE2          */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char Channel23:1;        /*   Channel23      */
            unsigned char Channel22:1;        /*   Channel22      */
            unsigned char Channel21:1;        /*   Channel21      */
            unsigned char Channel20:1;        /*   Channel20      */
            unsigned char Channel19:1;        /*   Channel19      */
            unsigned char Channel18:1;        /*   Channel18      */
            unsigned char Channel17:1;        /*   Channel17      */
            unsigned char Channel16:1;        /*   Channel16      */
        }BIT;                                 /*                  */
    }ADMADE2;                                 /*                  */

    union                                     /*                  */
    {                                         /* ADMADE3          */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char Channel31:1;        /*   Channel31      */
            unsigned char Channel30:1;        /*   Channel30      */
            unsigned char Channel29:1;        /*   Channel29      */
            unsigned char Channel28:1;        /*   Channel28      */
            unsigned char Channel27:1;        /*   Channel27      */
            unsigned char Channel26:1;        /*   Channel26      */
            unsigned char Channel25:1;        /*   Channel25      */
            unsigned char Channel24:1;        /*   Channel24      */
        }BIT;                                 /*                  */
    }ADMADE3;                                 /*                  */

    union                                     /*                  */
    {                                         /* ADMADE4          */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char Channel39:1;        /*   Channel39      */
            unsigned char Channel38:1;        /*   Channel38      */
            unsigned char Channel37:1;        /*   Channel37      */
            unsigned char Channel36:1;        /*   Channel36      */
            unsigned char Channel35:1;        /*   Channel35      */
            unsigned char Channel34:1;        /*   Channel34      */
            unsigned char Channel33:1;        /*   Channel33      */
            unsigned char Channel32:1;        /*   Channel32      */
        }BIT;                                 /*                  */
    }ADMADE4;                                 /*                  */

    union                                     /*                  */
    {                                         /* ADMADE5          */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char Channel47:1;        /*   Channel47      */
            unsigned char Channel46:1;        /*   Channel46      */
            unsigned char Channel45:1;        /*   Channel45      */
            unsigned char Channel44:1;        /*   Channel44      */
            unsigned char Channel43:1;        /*   Channel43      */
            unsigned char Channel42:1;        /*   Channel42      */
            unsigned char Channel41:1;        /*   Channel41      */
            unsigned char Channel40:1;        /*   Channel40      */
        }BIT;                                 /*                  */
    }ADMADE5;                                 /*                  */

    unsigned char dummy7[1];

    union                                     /*                  */
    {                                         /* ADMADE7          */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved1:5;        /*   Reserved Bits  */
            unsigned char Channel74:1;        /*   Channel74      */
            unsigned char reserved2:1;        /*   Reserved Bits  */
            unsigned char Channel72:1;        /*   Channel72      */
        }BIT;                                 /*                  */
    }ADMADE7;                                 /*                  */

    unsigned char dummy8[8];

    union                                     /*                  */
    {                                         /* ADMAMODE0        */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char Channel31:1;        /*   Channel31      */
            unsigned char Channel30:1;        /*   Channel30      */
            unsigned char Channel29:1;        /*   Channel29      */
            unsigned char Channel28:1;        /*   Channel28      */
            unsigned char reserved:4;         /*   Reserved Bits  */
        }BIT;                                 /*                  */
    }ADMAMODE0;                               /*                  */

    union                                     /*                  */
    {                                         /* ADMAMODE1        */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char Channel39:1;        /*   Channel39      */
            unsigned char Channel38:1;        /*   Channel38      */
            unsigned char Channel37:1;        /*   Channel37      */
            unsigned char Channel36:1;        /*   Channel36      */
            unsigned char Channel35:1;        /*   Channel35      */
            unsigned char Channel34:1;        /*   Channel34      */
            unsigned char Channel33:1;        /*   Channel33      */
            unsigned char Channel32:1;        /*   Channel32      */
        }BIT;                                 /*                  */
    }ADMAMODE1;                               /*                  */

    union                                     /*                  */
    {                                         /* ADMAMODE2        */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char Channel47:1;        /*   Channel47      */
            unsigned char Channel46:1;        /*   Channel46      */
            unsigned char Channel45:1;        /*   Channel45      */
            unsigned char Channel44:1;        /*   Channel44      */
            unsigned char Channel43:1;        /*   Channel43      */
            unsigned char Channel42:1;        /*   Channel42      */
            unsigned char Channel41:1;        /*   Channel41      */
            unsigned char Channel40:1;        /*   Channel40      */
        }BIT;                                 /*                  */
    }ADMAMODE2;                               /*                  */

    unsigned char dummy9[13];

    unsigned short ADMATCR0;                  /* ADMATCR0         */

    unsigned short ADMARTCR0;                 /* ADMARTCR0        */

    unsigned short ADMATCR1;                  /* ADMATCR1         */

    unsigned short ADMARTCR1;                 /* ADMARTCR1        */

    unsigned char dummy10[8];

    unsigned short ADMATCR56;                 /* ADMATCR56        */

    unsigned short ADMATCR57;                 /* ADMATCR57        */

    unsigned short ADMATCR58;                 /* ADMATCR58        */

    unsigned short ADMATCR59;                 /* ADMATCR59        */

    unsigned char dummy101[4];

    unsigned short ADMATCR62;                 /* ADMATCR62        */

    unsigned short ADMATCR63;                 /* ADMATCR63        */

    unsigned short ADMATCR64;                 /* ADMATCR64        */

    unsigned short ADMATCR65;                 /* ADMATCR65        */

    unsigned short ADMATCR66;                 /* ADMATCR66        */

    unsigned short ADMATCR67;                 /* ADMATCR67        */

    unsigned char dummy11[8];

    unsigned short ADMAAR0;                   /* ADMAAR0          */

    unsigned short ADMARAR0;                  /* ADMARAR0         */

    unsigned short ADMAAR1;                   /* ADMAAR1          */

    unsigned short ADMARAR1;                  /* ADMARAR1         */

    unsigned char dummy12[8];

    unsigned short ADMAAR56;                  /* ADMAAR56         */

    unsigned short ADMAAR57;                  /* ADMAAR57         */

    unsigned short ADMAAR58;                  /* ADMAAR58         */

    unsigned short ADMAAR59;                  /* ADMAAR59         */

    unsigned short ADMAAR60;                  /* ADMAAR60         */

    unsigned short ADMAAR61;                  /* ADMAAR61         */

    unsigned short ADMAAR62;                  /* ADMAAR62         */

    unsigned short ADMAAR63;                  /* ADMAAR63         */

    unsigned short ADMAAR64;                  /* ADMAAR64         */

    unsigned short ADMAAR65;                  /* ADMAAR65         */

    unsigned short ADMAAR66;                  /* ADMAAR66         */

    unsigned short ADMAAR67;                  /* ADMAAR67         */

    unsigned char dummy13[8];

    unsigned long ADMABUF2;                   /* ADMABUF2         */

    unsigned long ADMABUF3;                   /* ADMABUF3         */

    unsigned long ADMABUF4;                   /* ADMABUF4         */

    unsigned long ADMABUF5;                   /* ADMABUF5         */

    unsigned char dummy14[16];

    union                                     /*                  */
    {                                         /* ADMARVPR0        */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char RCANAMB31:1;        /*   RCANAMB31      */
            unsigned char RCANAMB30:1;        /*   RCANAMB30      */
            unsigned char RCANAMB29:1;        /*   RCANAMB29      */
            unsigned char RCANAMB28:1;        /*   RCANAMB28      */
            unsigned char RCANAMB27:1;        /*   RCANAMB27      */
            unsigned char RCANAMB26:1;        /*   RCANAMB26      */
            unsigned char RCANAMB25:1;        /*   RCANAMB25      */
            unsigned char RCANAMB24:1;        /*   RCANAMB24      */
            unsigned char RCANAMB23:1;        /*   RCANAMB23      */
            unsigned char RCANAMB22:1;        /*   RCANAMB22      */
            unsigned char RCANAMB21:1;        /*   RCANAMB21      */
            unsigned char RCANAMB20:1;        /*   RCANAMB20      */
            unsigned char RCANAMB19:1;        /*   RCANAMB19      */
            unsigned char RCANAMB18:1;        /*   RCANAMB18      */
            unsigned char RCANAMB17:1;        /*   RCANAMB17      */
            unsigned char RCANAMB16:1;        /*   RCANAMB16      */
        }BIT;                                 /*                  */
    }ADMARVPR0;                               /*                  */

    union                                     /*                  */
    {                                         /* ADMARVPR1        */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char RCANAMB15:1;        /*   RCANAMB15      */
            unsigned char RCANAMB14:1;        /*   RCANAMB14      */
            unsigned char RCANAMB13:1;        /*   RCANAMB13      */
            unsigned char RCANAMB12:1;        /*   RCANAMB12      */
            unsigned char RCANAMB11:1;        /*   RCANAMB11      */
            unsigned char RCANAMB10:1;        /*   RCANAMB10      */
            unsigned char RCANAMB9:1;         /*   RCANAMB9       */
            unsigned char RCANAMB8:1;         /*   RCANAMB8       */
            unsigned char RCANAMB7:1;         /*   RCANAMB7       */
            unsigned char RCANAMB6:1;         /*   RCANAMB6       */
            unsigned char RCANAMB5:1;         /*   RCANAMB5       */
            unsigned char RCANAMB4:1;         /*   RCANAMB4       */
            unsigned char RCANAMB3:1;         /*   RCANAMB3       */
            unsigned char RCANAMB2:1;         /*   RCANAMB2       */
            unsigned char RCANAMB1:1;         /*   RCANAMB1       */
            unsigned char RCANAMB0:1;         /*   RCANAMB0       */
        }BIT;                                 /*                  */
    }ADMARVPR1;                               /*                  */

    union                                     /*                  */
    {                                         /* ADMARVPR2        */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char RCANBMB31:1;        /*   RCANBMB31      */
            unsigned char RCANBMB30:1;        /*   RCANBMB30      */
            unsigned char RCANBMB29:1;        /*   RCANBMB29      */
            unsigned char RCANBMB28:1;        /*   RCANBMB28      */
            unsigned char RCANBMB27:1;        /*   RCANBMB27      */
            unsigned char RCANBMB26:1;        /*   RCANBMB26      */
            unsigned char RCANBMB25:1;        /*   RCANBMB25      */
            unsigned char RCANBMB24:1;        /*   RCANBMB24      */
            unsigned char RCANBMB23:1;        /*   RCANBMB23      */
            unsigned char RCANBMB22:1;        /*   RCANBMB22      */
            unsigned char RCANBMB21:1;        /*   RCANBMB21      */
            unsigned char RCANBMB20:1;        /*   RCANBMB20      */
            unsigned char RCANBMB19:1;        /*   RCANBMB19      */
            unsigned char RCANBMB18:1;        /*   RCANBMB18      */
            unsigned char RCANBMB17:1;        /*   RCANBMB17      */
            unsigned char RCANBMB16:1;        /*   RCANBMB16      */
        }BIT;                                 /*                  */
    }ADMARVPR2;                               /*                  */

    union                                     /*                  */
    {                                         /* ADMARVPR3        */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char RCANBMB15:1;        /*   RCANBMB15      */
            unsigned char RCANBMB14:1;        /*   RCANBMB14      */
            unsigned char RCANBMB13:1;        /*   RCANBMB13      */
            unsigned char RCANBMB12:1;        /*   RCANBMB12      */
            unsigned char RCANBMB11:1;        /*   RCANBMB11      */
            unsigned char RCANBMB10:1;        /*   RCANBMB10      */
            unsigned char RCANBMB9:1;         /*   RCANBMB9       */
            unsigned char RCANBMB8:1;         /*   RCANBMB8       */
            unsigned char RCANBMB7:1;         /*   RCANBMB7       */
            unsigned char RCANBMB6:1;         /*   RCANBMB6       */
            unsigned char RCANBMB5:1;         /*   RCANBMB5       */
            unsigned char RCANBMB4:1;         /*   RCANBMB4       */
            unsigned char RCANBMB3:1;         /*   RCANBMB3       */
            unsigned char RCANBMB2:1;         /*   RCANBMB2       */
            unsigned char RCANBMB1:1;         /*   RCANBMB1       */
            unsigned char RCANBMB0:1;         /*   RCANBMB0       */
        }BIT;                                 /*                  */
    }ADMARVPR3;                               /*                  */


    unsigned char dummy15[8];

    union                                     /*                  */
    {                                         /* ADMATVPR0        */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char RCANAMB31:1;        /*   RCANAMB31      */
            unsigned char RCANAMB30:1;        /*   RCANAMB30      */
            unsigned char RCANAMB29:1;        /*   RCANAMB29      */
            unsigned char RCANAMB28:1;        /*   RCANAMB28      */
            unsigned char RCANAMB27:1;        /*   RCANAMB27      */
            unsigned char RCANAMB26:1;        /*   RCANAMB26      */
            unsigned char RCANAMB25:1;        /*   RCANAMB25      */
            unsigned char RCANAMB24:1;        /*   RCANAMB24      */
            unsigned char RCANAMB23:1;        /*   RCANAMB23      */
            unsigned char RCANAMB22:1;        /*   RCANAMB22      */
            unsigned char RCANAMB21:1;        /*   RCANAMB21      */
            unsigned char RCANAMB20:1;        /*   RCANAMB20      */
            unsigned char RCANAMB19:1;        /*   RCANAMB19      */
            unsigned char RCANAMB18:1;        /*   RCANAMB18      */
            unsigned char RCANAMB17:1;        /*   RCANAMB17      */
            unsigned char RCANAMB16:1;        /*   RCANAMB16      */
        }BIT;                                 /*                  */
    }ADMATVPR0;                               /*                  */

    union                                     /*                  */
    {                                         /* ADMATVPR1        */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char RCANAMB15:1;        /*   RCANAMB15      */
            unsigned char RCANAMB14:1;        /*   RCANAMB14      */
            unsigned char RCANAMB13:1;        /*   RCANAMB13      */
            unsigned char RCANAMB12:1;        /*   RCANAMB12      */
            unsigned char RCANAMB11:1;        /*   RCANAMB11      */
            unsigned char RCANAMB10:1;        /*   RCANAMB10      */
            unsigned char RCANAMB9:1;         /*   RCANAMB9       */
            unsigned char RCANAMB8:1;         /*   RCANAMB8       */
            unsigned char RCANAMB7:1;         /*   RCANAMB7       */
            unsigned char RCANAMB6:1;         /*   RCANAMB6       */
            unsigned char RCANAMB5:1;         /*   RCANAMB5       */
            unsigned char RCANAMB4:1;         /*   RCANAMB4       */
            unsigned char RCANAMB3:1;         /*   RCANAMB3       */
            unsigned char RCANAMB2:1;         /*   RCANAMB2       */
            unsigned char RCANAMB1:1;         /*   RCANAMB1       */
            unsigned char reserved:1;         /*   Reserved Bits  */
        }BIT;                                 /*                  */
    }ADMATVPR1;                               /*                  */

    union                                     /*                  */
    {                                         /* ADMATVPR2        */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char RCANBMB31:1;        /*   RCANBMB31      */
            unsigned char RCANBMB30:1;        /*   RCANBMB30      */
            unsigned char RCANBMB29:1;        /*   RCANBMB29      */
            unsigned char RCANBMB28:1;        /*   RCANBMB28      */
            unsigned char RCANBMB27:1;        /*   RCANBMB27      */
            unsigned char RCANBMB26:1;        /*   RCANBMB26      */
            unsigned char RCANBMB25:1;        /*   RCANBMB25      */
            unsigned char RCANBMB24:1;        /*   RCANBMB24      */
            unsigned char RCANBMB23:1;        /*   RCANBMB23      */
            unsigned char RCANBMB22:1;        /*   RCANBMB22      */
            unsigned char RCANBMB21:1;        /*   RCANBMB21      */
            unsigned char RCANBMB20:1;        /*   RCANBMB20      */
            unsigned char RCANBMB19:1;        /*   RCANBMB19      */
            unsigned char RCANBMB18:1;        /*   RCANBMB18      */
            unsigned char RCANBMB17:1;        /*   RCANBMB17      */
            unsigned char RCANBMB16:1;        /*   RCANBMB16      */
        }BIT;                                 /*                  */
    }ADMATVPR2;                               /*                  */

    union                                     /*                  */
    {                                         /* ADMATVPR3        */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char RCANBMB15:1;        /*   RCANBMB15      */
            unsigned char RCANBMB14:1;        /*   RCANBMB14      */
            unsigned char RCANBMB13:1;        /*   RCANBMB13      */
            unsigned char RCANBMB12:1;        /*   RCANBMB12      */
            unsigned char RCANBMB11:1;        /*   RCANBMB11      */
            unsigned char RCANBMB10:1;        /*   RCANBMB10      */
            unsigned char RCANBMB9:1;         /*   RCANBMB9       */
            unsigned char RCANBMB8:1;         /*   RCANBMB8       */
            unsigned char RCANBMB7:1;         /*   RCANBMB7       */
            unsigned char RCANBMB6:1;         /*   RCANBMB6       */
            unsigned char RCANBMB5:1;         /*   RCANBMB5       */
            unsigned char RCANBMB4:1;         /*   RCANBMB4       */
            unsigned char RCANBMB3:1;         /*   RCANBMB3       */
            unsigned char RCANBMB2:1;         /*   RCANBMB2       */
            unsigned char RCANBMB1:1;         /*   RCANBMB1       */
            unsigned char reserved:1;         /*   Reserved Bits  */
        }BIT;                                 /*                  */
    }ADMATVPR3;                               /*                  */

};

/***********************************************************************************
    Advanced Timer Unit III (ATU-III)
***********************************************************************************/
struct st_timerA                              /* TIMER A          */
{
    unsigned char dummy1[2];

    union                                     /*                  */
    {                                         /* TCRA             */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char EVOSEL2A:1;         /*   EVOSEL2A       */
            unsigned char EVOSEL2B:1;         /*   EVOSEL2B       */
            unsigned char EVOSEL1:3;          /*   EVOSEL1[2:0]   */
            unsigned char CKSELA:3;           /*   CKSELA[2:0]    */
        }BIT;                                 /*                  */
    }TCRA;                                    /*                  */

    unsigned char dummy2[1];

    union                                     /*                  */
    {                                         /* TIOR1A           */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved:8;         /*   Reserved Bits  */
            unsigned char IOA3:2;             /*   IOA3[1:0]      */
            unsigned char IOA2:2;             /*   IOA2[1:0]      */
            unsigned char IOA1:2;             /*   IOA1[1:0]      */
            unsigned char IOA0:2;             /*   IOA0[1:0]      */
        }BIT;                                 /*                  */
    }TIOR1A;                                  /*                  */

    union                                     /*                  */
    {                                         /* TIOR2A           */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved1:4;        /*   Reserved Bits  */
            unsigned char NCKA3:1;            /*   NCKA3          */
            unsigned char NCKA2:1;            /*   NCKA2          */
            unsigned char NCKA1:1;            /*   NCKA1          */
            unsigned char NCKA0:1;            /*   NCKA0          */
            unsigned char reserved2:4;        /*   Reserved Bits  */
            unsigned char NCEA3:1;            /*   NCEA3          */
            unsigned char NCEA2:1;            /*   NCEA2          */
            unsigned char NCEA1:1;            /*   NCEA1          */
            unsigned char NCEA0:1;            /*   NCEA0          */
        }BIT;                                 /*                  */
    }TIOR2A;                                  /*                  */

    union                                     /*                  */
    {                                         /* TSRA             */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char OVFA:1;             /*   OVFA           */
            unsigned char reserved:3;         /*   Reserved Bits  */
            unsigned char ICFA3:1;            /*   ICFA3          */
            unsigned char ICFA2:1;            /*   ICFA2          */
            unsigned char ICFA1:1;            /*   ICFA1          */
            unsigned char ICFA0:1;            /*   ICFA0          */
        }BIT;                                 /*                  */
    }TSRA;                                    /*                  */

    union                                     /*                  */
    {                                         /* TIERA            */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char OVEA:1;             /*   OVEA           */
            unsigned char reserved:3;         /*   Reserved Bits  */
            unsigned char ICEA3:1;            /*   ICEA3          */
            unsigned char ICEA2:1;            /*   ICEA2          */
            unsigned char ICEA1:1;            /*   ICEA1          */
            unsigned char ICEA0:1;            /*   ICEA0          */
        }BIT;                                 /*                  */
    }TIERA;                                   /*                  */

    unsigned char dummy3[6];

    unsigned char NCNTA0;                     /* NCNTA0           */

    unsigned char NCRA0;                      /* NCRA0            */

    unsigned char NCNTA1;                     /* NCNTA1           */

    unsigned char NCRA1;                      /* NCRA1            */

    unsigned char NCNTA2;                     /* NCNTA2           */

    unsigned char NCRA2;                      /* NCRA2            */

    unsigned char NCNTA3;                     /* NCNTA3           */

    unsigned char NCRA3;                      /* NCRA3            */

    unsigned char dummy4[8];

    unsigned long TCNTA;                      /* TCNTA            */

    unsigned char dummy5[4];

    unsigned long ICRA0;                      /* ICRA0            */

    unsigned long ICRA1;                      /* ICRA1            */

    unsigned long ICRA2;                      /* ICRA2            */

    unsigned long ICRA3;                      /* ICRA3            */

};

struct st_timerB                              /* TIMER B          */
{
    unsigned char dummy[4];

    union                                     /*                  */
    {                                         /* TCRB             */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved:6;         /*   Reserved Bits  */
            unsigned char CKSELB:2;           /*   CKSELB[1:0]    */
        }BIT;                                 /*                  */
    }TCRB;                                    /*                  */

    union                                     /*                  */
    {                                         /* TIORB            */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char LDSEL:1;            /*   LDSEL          */
            unsigned char CTCNTB5:1;          /*   CTCNTB5        */
            unsigned char EVCNTB:1;           /*   EVCNTB         */
            unsigned char LDEN:1;             /*   LDEN           */
            unsigned char CCS:1;              /*   CCS            */
            unsigned char reserved:2;         /*   Reserved Bits  */
            unsigned char IOB6:1;             /*   IOB6           */
        }BIT;                                 /*                  */
    }TIORB;                                   /*                  */

    union                                     /*                  */
    {                                         /* TSRB             */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved:4;         /*   Reserved Bits  */
            unsigned char CMFB6:1;            /*   CMFB6          */
            unsigned char CMFB1:1;            /*   CMFB1          */
            unsigned char ICFB0:1;            /*   ICFB0          */
            unsigned char CMFB0:1;            /*   CMFB0          */
        }BIT;                                 /*                  */
    }TSRB;                                    /*                  */

    union                                     /*                  */
    {                                         /* TIERB            */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved:2;         /*   Reserved Bits  */
            unsigned char IREG:2;             /*   IREG[1:0]      */
            unsigned char CMEB6:1;            /*   CMEB6          */
            unsigned char CMEB1:1;            /*   CMEB1          */
            unsigned char ICEB0:1;            /*   ICEB0          */
            unsigned char CMEB0:1;            /*   CMEB0          */
        }BIT;                                 /*                  */
    }TIERB;                                   /*                  */

    unsigned char dummy1[8];

    unsigned long TCNTB0;                     /* TCNTB0           */

    unsigned long ICRB0;                      /* ICRB0            */

    unsigned long OCRB0;                      /* OCRB0            */

    unsigned char TCNTB1;                     /* TCNTB1           */

    unsigned char OCRB1;                      /* OCRB1            */

    unsigned char dummy2[2];

    unsigned long ICRB1;                      /* ICRB1            */

    unsigned long ICRB2;                      /* ICRB2            */

    unsigned char dummy3[8];

    union                                     /*                  */
    {                                         /* LDB              */
        unsigned long LONG;                   /*  Long Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned long reserved:8;         /*   Reserved Bits  */
            unsigned long LDVAL:24;           /*   LDVAL[23:0]    */
        }BIT;                                 /*                  */
    }LDB;                                     /*                  */

    union                                     /*                  */
    {                                         /* RLDB             */
        unsigned long LONG;                   /*  Long Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned long RLDVAL:24;          /*   RLDVAL[23:0]   */
            unsigned long reserved:8;         /*   Reserved Bits  */
        }BIT;                                 /*                  */
    }RLDB;                                    /*                  */

    union                                     /*                  */
    {                                         /* PIMR             */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned short reserved:4;        /*   Reserved Bits  */
            unsigned short PIM:12;            /*   PIM[11:0]      */
        }BIT;                                 /*                  */
    }PIMR;                                    /*                  */

    unsigned char dummy4[2];

    union                                     /*                  */
    {                                         /* TCNTB2           */
        unsigned long LONG;                   /*  Long Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned long CNTB2:24;           /*   CNTB2[23:0]    */
            unsigned long reserved:8;         /*   Reserved Bits  */
        }BIT;                                 /*                  */
    }TCNTB2;                                  /*                  */

    union                                     /*                  */
    {                                         /* TCNTB6           */
        unsigned long LONG;                   /*  Long Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned long CNTB6:20;           /*   CNTB6[19:0]    */
            unsigned long reserved:12;        /*   Reserved Bits  */
        }BIT;                                 /*                  */
    }TCNTB6;                                  /*                  */

    union                                     /*                  */
    {                                         /* OCRB6            */
        unsigned long LONG;                   /*  Long Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned long OCB6:20;            /*   OCB6[19:0]     */
            unsigned long reserved:12;        /*   Reserved Bits  */
        }BIT;                                 /*                  */
    }OCRB6;                                   /*                  */

    union                                     /*                  */
    {                                         /* OCRB7            */
        unsigned long LONG;                   /*  Long Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned long OCB7:20;            /*   OCB7[19:0]     */
            unsigned long reserved:12;        /*   Reserved Bits  */
        }BIT;                                 /*                  */
    }OCRB7;                                   /*                  */

    unsigned char dummy5[4];

    union                                     /*                  */
    {                                         /* TCNTB3           */
        unsigned long LONG;                   /*  Long Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned long CNTB3:20;           /*   CNTB3[19:0]    */
            unsigned long reserved:12;        /*   Reserved Bits  */
        }BIT;                                 /*                  */
    }TCNTB3;                                  /*                  */

    union                                     /*                  */
    {                                         /* TCNTB4           */
        unsigned long LONG;                   /*  Long Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned long CNTB4:20;           /*   CNTB4[19:0]    */
            unsigned long reserved:12;        /*   Reserved Bits  */
        }BIT;                                 /*                  */
    }TCNTB4;                                  /*                  */

    union                                     /*                  */
    {                                         /* TCNTB5           */
        unsigned long LONG;                   /*  Long Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned long CNTB5:20;           /*   CNTB5[19:0]    */
            unsigned long reserved:12;        /*   Reserved Bits  */
        }BIT;                                 /*                  */
    }TCNTB5;                                  /*                  */

    union                                     /*                  */
    {                                         /* TCCLRB           */
        unsigned long LONG;                   /*  Long Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned long CCLRB:20;           /*   CCLRB[19:0]    */
            unsigned long reserved:12;        /*   Reserved Bits  */
        }BIT;                                 /*                  */
    }TCCLRB;                                  /*                  */

};

typedef struct st_timerC_subblock
{
   union                                      /*                  */
    {                                         /* TCRC             */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char FCMC3  :1;          /*   FCMC3          */
            unsigned char FCMC2  :1;          /*   FCMC2          */
            unsigned char FCMC1  :1;          /*   FCMC1          */
            unsigned char FCMC0  :1;          /*   FCMC0          */
            unsigned char PWMC0  :1;          /*   PWMC0          */
            unsigned char CKSELC :3;          /*   CKSELC[2:0]    */
        }BIT;                                 /*                  */
    }TCRC;                                    /*                  */

    union                                     /*                  */
    {                                         /* TIERC            */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved:3;         /*   Reserved Bits  */
            unsigned char OVEC    :1;         /*   OVEC           */
            unsigned char IMEC3   :1;         /*   IMEC3          */
            unsigned char IMEC2   :1;         /*   IMEC2          */
            unsigned char IMEC1   :1;         /*   IMEC1          */
            unsigned char IMEC0   :1;         /*   IMEC0          */
        }BIT;                                 /*                  */
    }TIERC;                                   /*                  */

    union                                     /*                  */
    {                                         /* TIORC            */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved1:1;        /*   Reserved Bits  */
            unsigned char IOC3     :3;        /*   IOC3[2:0]      */
            unsigned char reserved2:1;        /*   Reserved Bits  */
            unsigned char IOC2     :3;        /*   IOC2[2:0]      */
            unsigned char reserved3:1;        /*   Reserved Bits  */
            unsigned char IOC1     :3;        /*   IOC1[2:0]      */
            unsigned char reserved4:1;        /*   Reserved Bits  */
            unsigned char IOC0     :3;        /*   IOC0[2:0]      */
        }BIT;                                 /*                  */
    }TIORC;                                   /*                  */

    union                                     /*                  */
    {                                         /* TSRC             */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved:3;         /*   Reserved Bits  */
            unsigned char OVFC    :1;         /*   OVFC           */
            unsigned char IMFC3   :1;         /*   IMFC3          */
            unsigned char IMFC2   :1;         /*   IMFC2          */
            unsigned char IMFC1   :1;         /*   IMFC1          */
            unsigned char IMFC0   :1;         /*   IMFC0          */
        }BIT;                                 /*                  */
    }TSRC;                                    /*                  */

    unsigned char dummy1[3];

    unsigned long GRC[4];                     /* GRC              */

    unsigned long TCNTC;                      /* TCNTC            */

    unsigned char dummy2[4];

}t_timerC_subblock;

struct st_timerC                              /* TIMER C          */
{
    union                                     /*                  */
    {                                         /* TSTRC            */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved:3;         /*   Reserved Bits  */
            unsigned char STRC4:1;            /*   STRC4          */
            unsigned char STRC3:1;            /*   STRC3          */
            unsigned char STRC2:1;            /*   STRC2          */
            unsigned char STRC1:1;            /*   STRC1          */
            unsigned char STRC0:1;            /*   STRC0          */
        }BIT;                                 /*                  */
    }TSTRC;                                   /*                  */

    unsigned char dummy1[1];

    union                                     /*                  */
    {                                         /* NCCRC0           */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved:4;         /*   Reserved Bits  */
            unsigned char NCEC03:1;           /*   NCEC03         */
            unsigned char NCEC02:1;           /*   NCEC02         */
            unsigned char NCEC01:1;           /*   NCEC01         */
            unsigned char NCEC00:1;           /*   NCEC00         */
        }BIT;                                 /*                  */
    }NCCRC0;                                  /*                  */


    union                                     /*                  */
    {                                         /* NCCRC1           */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved:4;         /*   Reserved Bits  */
            unsigned char NCEC13:1;           /*   NCEC13         */
            unsigned char NCEC12:1;           /*   NCEC12         */
            unsigned char NCEC11:1;           /*   NCEC11         */
            unsigned char NCEC10:1;           /*   NCEC10         */
        }BIT;                                 /*                  */
    }NCCRC1;                                  /*                  */

    union                                     /*                  */
    {                                         /* NCCRC2           */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved:4;         /*   Reserved Bits  */
            unsigned char NCEC23:1;           /*   NCEC23         */
            unsigned char NCEC22:1;           /*   NCEC22         */
            unsigned char NCEC21:1;           /*   NCEC21         */
            unsigned char NCEC20:1;           /*   NCEC20         */
        }BIT;                                 /*                  */
    }NCCRC2;                                  /*                  */


    union                                     /*                  */
    {                                         /* NCCRC3           */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved:4;         /*   Reserved Bits  */
            unsigned char NCEC33:1;           /*   NCEC33         */
            unsigned char NCEC32:1;           /*   NCEC32         */
            unsigned char NCEC31:1;           /*   NCEC31         */
            unsigned char NCEC30:1;           /*   NCEC30         */
        }BIT;                                 /*                  */
    }NCCRC3;                                  /*                  */

    union                                     /*                  */
    {                                         /* NCCRC4           */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved:4;         /*   Reserved Bits  */
            unsigned char NCEC43:1;           /*   NCEC43         */
            unsigned char NCEC42:1;           /*   NCEC42         */
            unsigned char NCEC41:1;           /*   NCEC41         */
            unsigned char NCEC40:1;           /*   NCEC40         */
        }BIT;                                 /*                  */
    }NCCRC4;                                  /*                  */

    unsigned char dummy2[9];

    unsigned char NCNTC00;                    /* NCNTC00          */

    unsigned char NCNTC01;                    /* NCNTC01          */

    unsigned char NCNTC02;                    /* NCNTC02          */

    unsigned char NCNTC03;                    /* NCNTC03          */

    unsigned char NCRC00;                     /* NCRC00           */

    unsigned char NCRC01;                     /* NCRC01           */

    unsigned char NCRC02;                     /* NCRC02           */

    unsigned char NCRC03;                     /* NCRC03           */

    unsigned char NCNTC10;                    /* NCNTC10          */

    unsigned char NCNTC11;                    /* NCNTC11          */

    unsigned char NCNTC12;                    /* NCNTC12          */

    unsigned char NCNTC13;                    /* NCNTC13          */

    unsigned char NCRC10;                     /* NCRC10           */

    unsigned char NCRC11;                     /* NCRC11           */

    unsigned char NCRC12;                     /* NCRC12           */

    unsigned char NCRC13;                     /* NCRC13           */

    unsigned char NCNTC20;                    /* NCNTC20          */

    unsigned char NCNTC21;                    /* NCNTC21          */

    unsigned char NCNTC22;                    /* NCNTC22          */

    unsigned char NCNTC23;                    /* NCNTC23          */

    unsigned char NCRC20;                     /* NCRC20           */

    unsigned char NCRC21;                     /* NCRC21           */

    unsigned char NCRC22;                     /* NCRC22           */

    unsigned char NCRC23;                     /* NCRC23           */

    unsigned char NCNTC30;                    /* NCNTC30          */

    unsigned char NCNTC31;                    /* NCNTC31          */

    unsigned char NCNTC32;                    /* NCNTC32          */

    unsigned char NCNTC33;                    /* NCNTC33          */

    unsigned char NCRC30;                     /* NCRC30           */

    unsigned char NCRC31;                     /* NCRC31           */

    unsigned char NCRC32;                     /* NCRC32           */

    unsigned char NCRC33;                     /* NCRC33           */

    unsigned char NCNTC40;                    /* NCNTC40          */

    unsigned char NCNTC41;                    /* NCNTC41          */

    unsigned char NCNTC42;                    /* NCNTC42          */

    unsigned char NCNTC43;                    /* NCNTC43          */

    unsigned char NCRC40;                     /* NCRC40           */

    unsigned char NCRC41;                     /* NCRC41           */

    unsigned char NCRC42;                     /* NCRC42           */

    unsigned char NCRC43;                     /* NCRC43           */

    unsigned char dummy3[8];

    t_timerC_subblock SUBBLOCK[5];            /* Timer C Subblock */

};

typedef struct st_timerD_subblockA
{
    unsigned long TCNT1D;                     /* TCNT1D          */

    unsigned long TCNT2D;                     /* TCNT2D          */

    unsigned long OSBRD;                      /* OSBRD           */

    union                                     /*                  */
    {                                         /* TCRD             */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved1:1;        /*   Reserved Bits  */
            unsigned char OBRED    :1;        /*   OBRED          */
            unsigned char C2CED    :1;        /*   C2CED          */
            unsigned char C1CED    :1;        /*   C1CED          */
            unsigned char reserved2:1;        /*   Reserved Bits  */
            unsigned char CKSEL2D  :3;        /*   CKSEL2D[2:0]   */
            unsigned char reserved3:1;        /*   Reserved Bits  */
            unsigned char CKSEL1D  :3;        /*   CKSEL1D[2:0]   */
            unsigned char reserved4:1;        /*   Reserved Bits  */
            unsigned char DCSELD   :3;        /*   DCSELD[2:0]    */
        }BIT;                                 /*                  */
    }TCRD;                                    /*                  */

    union                                     /*                  */
    {                                         /* TOCRD            */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved:6;         /*   Reserved Bits  */
            unsigned char TONEBD:1;           /*   TONEBD         */
            unsigned char TONEAD:1;           /*   TONEAD         */
        }BIT;                                 /*                  */
    }TOCRD;                                   /*                  */

    union                                     /*                  */
    {                                         /* CMPOD(0-1 ONLY)  */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char CMPBD3:1;           /*   CMPBD3         */
            unsigned char CMPBD2:1;           /*   CMPBD2         */
            unsigned char CMPBD1:1;           /*   CMPBD1         */
            unsigned char CMPBD0:1;           /*   CMPBD0         */
            unsigned char CMPAD3:1;           /*   CMPAD3         */
            unsigned char CMPAD2:1;           /*   CMPAD2         */
            unsigned char CMPAD1:1;           /*   CMPAD1         */
            unsigned char CMPAD0:1;           /*   CMPAD0         */
        }BIT;                                 /*                  */
    }CMPOD;

}t_timerD_subblockA;

typedef struct st_timerD_subblockB
{
    union                                     /*                  */
    {                                         /* TIOR1D           */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned short OSSD3:2;           /*   OSSD3[1:0]     */
            unsigned short OSSD2:2;           /*   OSSD2[1:0]     */
            unsigned short OSSD1:2;           /*   OSSD1[1:0]     */
            unsigned short OSSD0:2;           /*   OSSD0[1:0]     */
            unsigned short IOAD3:2;           /*   IOAD3[1:0]     */
            unsigned short IOAD2:2;           /*   IOAD2[1:0]     */
            unsigned short IOAD1:2;           /*   IOAD1[1:0]     */
            unsigned short IOAD0:2;           /*   IOAD0[1:0]     */
        }BIT;                                 /*                  */
    }TIOR1D;                                  /*                  */

    union                                     /*                  */
    {                                         /* TIOR2D           */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned short reserved1:1;       /*   Reserved Bits  */
            unsigned short IOBD3    :3;       /*   IOBD3[2:0]     */
            unsigned short reserved2:1;       /*   Reserved Bits  */
            unsigned short IOBD2    :3;       /*   IOBD2[2:0]     */
            unsigned short reserved3:1;       /*   Reserved Bits  */
            unsigned short IOBD1    :3;       /*   IOBD1[2:0]     */
            unsigned short reserved4:1;       /*   Reserved Bits  */
            unsigned short IOBD0    :3;       /*   IOBD0[2:0]     */
        }BIT;                                 /*                  */
    }TIOR2D;                                  /*                  */

    unsigned char dummy1[1];

    union                                     /*                  */
    {                                         /* DSTRD            */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved:4;         /*   Reserved Bits  */
            unsigned char DSTD3   :1;         /*   DSTD3          */
            unsigned char DSTD2   :1;         /*   DSTD2          */
            unsigned char DSTD1   :1;         /*   DSTD1          */
            unsigned char DSTD0   :1;         /*   DSTD0          */
        }BIT;                                 /*                  */
    }DSTRD;                                   /*                  */

    unsigned char dummy2[1];

    union                                     /*                  */
    {                                         /* DSRD             */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved:4;         /*   Reserved Bits  */
            unsigned char DSFD3   :1;         /*   DSFD3          */
            unsigned char DSFD2   :1;         /*   DSFD2          */
            unsigned char DSFD1   :1;         /*   DSFD1          */
            unsigned char DSFD0   :1;         /*   DSFD0          */
        }BIT;                                 /*                  */
    }DSRD;                                    /*                  */

    union                                     /*                  */
    {                                         /* DCRD             */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned short reserved1:1;       /*   Reserved Bits  */
            unsigned short TRGSELD3 :3;       /*   TRGSELD3[2:0]  */
            unsigned short reserved2:1;       /*   Reserved Bits  */
            unsigned short TRGSELD2 :3;       /*   TRGSELD2[2:0]  */
            unsigned short reserved3:1;       /*   Reserved Bits  */
            unsigned short TRGSELD1 :3;       /*   TRGSELD1[2:0]  */
            unsigned short reserved4:1;       /*   Reserved Bits  */
            unsigned short TRGSELD0 :3;       /*   TRGSELD0[2:0]  */
        }BIT;                                 /*                  */
    }DCRD;                                    /*                  */

    unsigned char dummy3[2];

    union                                     /*                  */
    {                                         /* TSRD             */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved:2;         /*   Reserved Bits  */
            unsigned char OVF2D   :1;         /*   OVF2D          */
            unsigned char OVF1D   :1;         /*   OVF1D          */
            unsigned char UDFD3   :1;         /*   UDFD3          */
            unsigned char UDFD2   :1;         /*   UDFD2          */
            unsigned char UDFD1   :1;         /*   UDFD1          */
            unsigned char UDFD0   :1;         /*   UDFD0          */
            unsigned char CMFAD3  :1;         /*   CMFAD3         */
            unsigned char CMFAD2  :1;         /*   CMFAD2         */
            unsigned char CMFAD1  :1;         /*   CMFAD1         */
            unsigned char CMFAD0  :1;         /*   CMFAD0         */
            unsigned char CMFBD3  :1;         /*   CMFBD3         */
            unsigned char CMFBD2  :1;         /*   CMFBD2         */
            unsigned char CMFBD1  :1;         /*   CMFBD1         */
            unsigned char CMFBD0  :1;         /*   CMFBD0         */
        }BIT;                                 /*                  */
    }TSRD;                                    /*                  */

    union                                     /*                  */
    {                                         /* TIERD            */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved:2;         /*   Reserved Bits  */
            unsigned char OVE2D:1;            /*   OVE2D          */
            unsigned char OVE1D:1;            /*   OVE1D          */
            unsigned char UDED3:1;            /*   UDED3          */
            unsigned char UDED2:1;            /*   UDED2          */
            unsigned char UDED1:1;            /*   UDED1          */
            unsigned char UDED0:1;            /*   UDED0          */
            unsigned char CMEAD3:1;           /*   CMEAD3         */
            unsigned char CMEAD2:1;           /*   CMEAD2         */
            unsigned char CMEAD1:1;           /*   CMEAD1         */
            unsigned char CMEAD0:1;           /*   CMEAD0         */
            unsigned char CMEBD3:1;           /*   CMEBD3         */
            unsigned char CMEBD2:1;           /*   CMEBD2         */
            unsigned char CMEBD1:1;           /*   CMEBD1         */
            unsigned char CMEBD0:1;           /*   CMEBD0         */
        }BIT;                                 /*                  */
    }TIERD;                                   /*                  */

    unsigned long OCRD[4];                    /* OCRD             */

    unsigned long GRD[4];                     /* GRD              */

    unsigned long DCNTD[4];                   /* DCNTD            */

}t_timerD_subblockB;

struct st_timerD                              /* TIMER D          */
{
    union                                     /*                  */
    {                                         /* TSTRD            */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved:4;         /*   Reserved Bits  */
            unsigned char STRD3:1;            /*   STRD3          */
            unsigned char STRD2:1;            /*   STRD2          */
            unsigned char STRD1:1;            /*   STRD1          */
            unsigned char STRD0:1;            /*   STRD0          */
        }BIT;                                 /*                  */
    }TSTRD;                                   /*                  */

    unsigned char dummy1[31];

    /* Timer D Sub-block A contains registers
       TCNT1D, TCNT2D, OSBRD, TCRD, TOCRD & CMPOD */
    t_timerD_subblockA SUBBLOCKA[4];

    unsigned char dummy2[32];

    /* Timer D Sub-block B contains registers
       TIOR1D, TIOR2D, DSTRD, DSRD, DCRD,
       TSRD, TIERD, OCRD, GRD & DCNTD             */
    t_timerD_subblockB SUBBLOCKB[4];

};

typedef struct st_timerE_subblock
{
    union                                     /*                  */
    {                                         /* TCRE             */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved:5;         /*   Reserved Bits  */
            unsigned char CKSELE:3;           /*   CKSELE[2:0]    */
        }BIT;                                 /*                  */
    }TCRE;                                    /*                  */

    union                                     /*                  */
    {                                         /* TOCRE            */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved:4;         /*   Reserved Bits  */
            unsigned char TONEE3:1;           /*   TONEE3         */
            unsigned char TONEE2:1;           /*   TONEE2         */
            unsigned char TONEE1:1;           /*   TONEE1         */
            unsigned char TONEE0:1;           /*   TONEE0         */
        }BIT;                                 /*                  */
    }TOCRE;                                   /*                  */

    union                                     /*                  */
    {                                         /* TIERE            */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved:4;         /*   Reserved Bits  */
            unsigned char CMEE3:1;            /*   CMEE3          */
            unsigned char CMEE2:1;            /*   CMEE2          */
            unsigned char CMEE1:1;            /*   CMEE1          */
            unsigned char CMEE0:1;            /*   CMEE0          */
        }BIT;                                 /*                  */
    }TIERE;                                   /*                  */

    union                                     /*                  */
    {                                         /* RLDCRE           */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved:4;         /*   Reserved Bits  */
            unsigned char RLDENE3:1;          /*   RLDENE3        */
            unsigned char RLDENE2:1;          /*   RLDENE2        */
            unsigned char RLDENE1:1;          /*   RLDENE1        */
            unsigned char RLDENE0:1;          /*   RLDENE0        */
        }BIT;                                 /*                  */
    }RLDCRE;                                  /*                  */

    union                                     /*                  */
    {                                         /* TSRE             */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char OVFE3:1;            /*   OVFE3          */
            unsigned char OVFE2:1;            /*   OVFE2          */
            unsigned char OVFE1:1;            /*   OVFE1          */
            unsigned char OVFE0:1;            /*   OVFE0          */
            unsigned char CMFE3:1;            /*   CMFE3          */
            unsigned char CMFE2:1;            /*   CMFE2          */
            unsigned char CMFE1:1;            /*   CMFE1          */
            unsigned char CMFE0:1;            /*   CMFE0          */
        }BIT;                                 /*                  */
    }TSRE;                                    /*                  */

    unsigned char dummy1[3];

    union                                     /*                  */
    {                                         /* PSCRE            */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved:5;         /*   Reserved Bits  */
            unsigned char PSCE:3;             /*   PSCE[2:0]      */
        }BIT;                                 /*                  */
    }PSCRE;                                   /*                  */

    union                                     /*                  */
    {                                         /*  SOLVLE          */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved:4;         /*   Reserved Bits  */
            unsigned char PWMSLV3:1;
            unsigned char PWMSLV2:1;
            unsigned char PWMSLV1:1;
            unsigned char PWMSLV0:1;
        } BIT;
    }SOLVLE;

    union                                     /*                  */
    {                                         /* POECRE           */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned short POECRKEY:8;
            unsigned short reserved:3;
            unsigned short POEPOL:1;
            unsigned short POEEN3:1;
            unsigned short POEEN2:1;
            unsigned short POEEN1:1;
            unsigned short POEEN0:1;
        } BIT;
    }POECRE;

    union                                     /*                  */
    {                                         /* SSTRE            */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved:4;         /*   Reserved Bits  */
            unsigned char SSTRE3:1;           /*   SSTRE3         */
            unsigned char SSTRE2:1;           /*   SSTRE2         */
            unsigned char SSTRE1:1;           /*   SSTRE1         */
            unsigned char SSTRE0:1;           /*   SSTRE0         */
        }BIT;                                 /*                  */
    }SSTRE;                                   /*                  */

    unsigned char dummy3[3];

    unsigned short CYLRE[4];                  /* CYLRE            */

    unsigned short DTRE[4];                   /* DTRE             */

    unsigned short CRLDE[4];                  /* CRLDE            */

    unsigned short DRLDE[4];                  /* DRLDE            */

    unsigned short TCNTE[4];                  /* TCNTE            */

    unsigned char dummy4[8];

}t_timerE_subblock;

struct st_timerE                              /* TIMER E          */
{
    union                                     /*                  */
    {                                         /* TSTRE            */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved:3;         /*   Reserved Bits  */
            unsigned char STRE4:1;            /*   STRE4          */
            unsigned char STRE3:1;            /*   STRE3          */
            unsigned char STRE2:1;            /*   STRE2          */
            unsigned char STRE1:1;            /*   STRE1          */
            unsigned char STRE0:1;            /*   STRE0          */
        }BIT;                                 /*                  */
    }TSTRE;                                   /*                  */

    unsigned char dummy1[(0xFFFFF800u-0xFFFFF700u-1)];

    t_timerE_subblock SUBBLOCK[5];            /* Timer E Subblock */

};

typedef struct st_timerF_subblock
{
    union                                     /*                  */
    {                                         /* TCRF             */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char CKSELF:3;           /*   CKSELF[2:0]    */
            unsigned char MDF:3;              /*   MDF[2:0]       */
            unsigned char EGSELF:2;           /*   EGSELF[1:0]    */
        }BIT;                                 /*                  */
    }TCRF;                                    /*                  */

    union                                     /*                  */
    {                                         /* TIERF            */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved:4;         /*   Reserved Bits  */
            unsigned char OVECF:1;            /*   OVECF          */
            unsigned char OVEBF:1;            /*   OVEBF          */
            unsigned char OVEAF:1;            /*   OVEAF          */
            unsigned char ICEF:1;             /*   ICEF           */
        }BIT;                                 /*                  */
    }TIERF;                                   /*                  */

    unsigned char dummy1[1];

    union                                     /*                  */
    {                                         /* TSRF             */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved:4;         /*   Reserved Bits  */
            unsigned char OVFCF:1;            /*   OVFCF          */
            unsigned char OVFBF:1;            /*   OVFBF          */
            unsigned char OVFAF:1;            /*   OVFAF          */
            unsigned char ICFF:1;             /*   ICFF           */
        }BIT;                                 /*                  */
    }TSRF;                                    /*                  */

    unsigned long ECNTAF;                     /* ECNTAF           */

    unsigned short ECNTBF;                    /* ECNTBF           */

    unsigned short GRBF;                      /* GRBF             */

    unsigned long ECNTCF;                     /* ECNTCF           */

    unsigned long GRAF;                       /* GRAF             */

    unsigned long CDRF;                       /* CDRF             */

    unsigned long GRCF;                       /* GRCF             */

    unsigned long GRDF;                       /* GRDF(12-15ONLY)  */

}t_timerF_subblock;

struct st_timerF
{
    union                                     /*                  */
    {                                         /* TSTRF            */
        unsigned long LONG;                   /*  Long Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved1:8;        /*   Reserved Bits  */
            unsigned char reserved2:4;        /*   Reserved Bits  */
            unsigned char STRF19:1;           /*   STRF19         */
            unsigned char STRF18:1;           /*   STRF18         */
            unsigned char STRF17:1;           /*   STRF17         */
            unsigned char STRF16:1;           /*   STRF16         */
            unsigned char STRF15:1;           /*   STRF15         */
            unsigned char STRF14:1;           /*   STRF14         */
            unsigned char STRF13:1;           /*   STRF13         */
            unsigned char STRF12:1;           /*   STRF12         */
            unsigned char STRF11:1;           /*   STRF11         */
            unsigned char STRF10:1;           /*   STRF10         */
            unsigned char STRF9:1;            /*   STRF9          */
            unsigned char STRF8:1;            /*   STRF8          */
            unsigned char STRF7:1;            /*   STRF7          */
            unsigned char STRF6:1;            /*   STRF6          */
            unsigned char STRF5:1;            /*   STRF5          */
            unsigned char STRF4:1;            /*   STRF4          */
            unsigned char STRF3:1;            /*   STRF3          */
            unsigned char STRF2:1;            /*   STRF2          */
            unsigned char STRF1:1;            /*   STRF1          */
            unsigned char STRF0:1;            /*   STRF0          */
        }BIT;                                 /*                  */
    }TSTRF;                                   /*                  */

    union                                     /*                  */
    {                                         /* NCCRF            */
        unsigned long LONG;                   /*  Long Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved1:8;        /*   Reserved Bits  */
            unsigned char reserved2:4;        /*   Reserved Bits  */
            unsigned char NCEF19:1;           /*   NCEF19         */
            unsigned char NCEF18:1;           /*   NCEF18         */
            unsigned char NCEF17:1;           /*   NCEF17         */
            unsigned char NCEF16:1;           /*   NCEF16         */
            unsigned char NCEF15:1;           /*   NCEF15         */
            unsigned char NCEF14:1;           /*   NCEF14         */
            unsigned char NCEF13:1;           /*   NCEF13         */
            unsigned char NCEF12:1;           /*   NCEF12         */
            unsigned char NCEF11:1;           /*   NCEF11         */
            unsigned char NCEF10:1;           /*   NCEF10         */
            unsigned char NCEF9:1;            /*   NCEF9          */
            unsigned char NCEF8:1;            /*   NCEF8          */
            unsigned char NCEF7:1;            /*   NCEF7          */
            unsigned char NCEF6:1;            /*   NCEF6          */
            unsigned char NCEF5:1;            /*   NCEF5          */
            unsigned char NCEF4:1;            /*   NCEF4          */
            unsigned char NCEF3:1;            /*   NCEF3          */
            unsigned char NCEF2:1;            /*   NCEF2          */
            unsigned char NCEF1:1;            /*   NCEF1          */
            unsigned char NCEF0:1;            /*   NCEF0          */
        }BIT;                                 /*                  */
    }NCCRF;                                   /*                  */

    unsigned char dummy1[8];

    unsigned char NCNTFA0;                    /* NCNTFA0          */

    unsigned char NCRFA0;                     /* NCRFA0           */

    unsigned char NCNTFA1;                    /* NCNTFA1          */

    unsigned char NCRFA1;                     /* NCRFA1           */

    unsigned char NCNTFA2;                    /* NCNTFA2          */

    unsigned char NCRFA2;                     /* NCRFA2           */

    unsigned char NCNTFA3;                    /* NCNTFA3          */

    unsigned char NCRFA3;                     /* NCRFA3           */

    unsigned char NCNTFA4;                    /* NCNTFA4          */

    unsigned char NCRFA4;                     /* NCRFA4           */

    unsigned char NCNTFA5;                    /* NCNTFA5          */

    unsigned char NCRFA5;                     /* NCRFA5           */

    unsigned char NCNTFA6;                    /* NCNTFA6          */

    unsigned char NCRFA6;                     /* NCRFA6           */

    unsigned char NCNTFA7;                    /* NCNTFA7          */

    unsigned char NCRFA7;                     /* NCRFA7           */

    unsigned char NCNTFA8;                    /* NCNTFA8          */

    unsigned char NCRFA8;                     /* NCRFA8           */

    unsigned char NCNTFA9;                    /* NCNTFA9          */

    unsigned char NCRFA9;                     /* NCRFA9           */

    unsigned char NCNTFA10;                   /* NCNTFA10         */

    unsigned char NCRFA10;                    /* NCRFA10          */

    unsigned char NCNTFA11;                   /* NCNTFA11         */

    unsigned char NCRFA11;                    /* NCRFA11          */

    unsigned char NCNTFA12;                   /* NCNTFA12         */

    unsigned char NCRFA12;                    /* NCRFA12          */

    unsigned char NCNTFA13;                   /* NCNTFA13         */

    unsigned char NCRFA13;                    /* NCRFA13          */

    unsigned char NCNTFA14;                   /* NCNTFA14         */

    unsigned char NCRFA14;                    /* NCRFA14          */

    unsigned char NCNTFA15;                   /* NCNTFA15         */

    unsigned char NCRFA15;                    /* NCRFA15          */

    unsigned char NCNTFA16;                   /* NCNTFA16         */

    unsigned char NCRFA16;                    /* NCRFA16          */

    unsigned char NCNTFA17;                   /* NCNTFA17         */

    unsigned char NCRFA17;                    /* NCRFA17          */

    unsigned char NCNTFA18;                   /* NCNTFA18         */

    unsigned char NCRFA18;                    /* NCRFA18          */

    unsigned char NCNTFA19;                   /* NCNTFA19         */

    unsigned char NCRFA19;                    /* NCRFA19          */

    unsigned char dummy2[24];

    unsigned char NCNTFB0;                    /* NCNTFB0          */

    unsigned char NCRFB0;                     /* NCRFB0           */

    unsigned char NCNTFB1;                    /* NCNTFB1          */

    unsigned char NCRFB1;                     /* NCRFB1           */

    unsigned char NCNTFB2;                    /* NCNTFB2          */

    unsigned char NCRFB2;                     /* NCRFB2           */

    unsigned char dummy3[42];

    t_timerF_subblock SUBBLOCK[20];           /* Timer F Subblock */

};

typedef struct st_timerG_subblock
{
    union                                     /*                  */
    {                                         /* TCRG             */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved1:1;        /*   Reserved Bits  */
            unsigned char CKSELG   :3;        /*   CKSELG[2:0]    */
            unsigned char reserved2:2;        /*   Reserved Bits  */
            unsigned char CMPOEG   :1;        /*   CMPOEG         */
            unsigned char CMEG     :1;        /*   CMEG           */
        }BIT;                                 /*                  */
    }TCRG;                                    /*                  */

    union                                     /*                  */
    {                                         /* TSRG             */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved:6;         /*   Reserved Bits  */
            unsigned char OVFG    :1;         /*   OVFG           */
            unsigned char CMFG    :1;         /*   CMFG           */
        }BIT;                                 /*                  */
    }TSRG;                                    /*                  */

    unsigned char dummy1[2];

    unsigned short TCNTG;                     /* TCNTG            */

    unsigned short OCRG;                      /* OCRG             */

    unsigned char dummy2[8];

}t_timerG_subblock;


struct st_timerG
{
    unsigned char dummy1[1];

    union                                     /*                  */
    {                                         /* TSTRG            */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved:2;         /*   Reserved Bits  */
            unsigned char STRG5:1;            /*   STRG5          */
            unsigned char STRG4:1;            /*   STRG4          */
            unsigned char STRG3:1;            /*   STRG3          */
            unsigned char STRG2:1;            /*   STRG2          */
            unsigned char STRG1:1;            /*   STRG1          */
            unsigned char STRG0:1;            /*   STRG0          */
        }BIT;                                 /*                  */
    }TSTRG;                                   /*                  */

    unsigned char dummy2[(0xFFFFFE80u-0xFFFFFE01u-1)];

    t_timerG_subblock SUBBLOCK[6];    /* Timer G Subblock */

};

struct st_timerH
{
    union                                     /*                  */
    {                                         /* TCRH             */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved1:1;        /*   Reserved Bits  */
            unsigned char CKSELH:3;           /*   CKSELH[2:0]    */
            unsigned char reserved2:3;        /*   Reserved Bits  */
            unsigned char CMEH:1;             /*   CMEH           */
        }BIT;                                 /*                  */
    }TCRH;                                    /*                  */

    union                                     /*                  */
    {                                         /* TSRH             */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved:5;         /*   Reserved Bits  */
            unsigned char OVF2H:1;            /*   OVF2H          */
            unsigned char OVF1H:1;            /*   OVF1H          */
            unsigned char CMFH:1;             /*   CMFH           */
        }BIT;                                 /*                  */
    }TSRH;                                    /*                  */

    unsigned char dummy[2];

    unsigned short TCNT1H;                    /* TCNT1H           */

    unsigned short OCR1H;                     /* OCR1H            */

    unsigned long TCNT2H;                     /* TCNT2H           */

};

typedef struct st_timerJ_subblock
{
    union                                     /*                  */
    {                                         /* TCRJ             */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved1:1;        /*   Reserved Bits  */
            unsigned char CKSELJ   :3;        /*   CKSELJ[2:0]    */
            unsigned char reserved2:1;        /*   Reserved Bits  */
            unsigned char NCEJ     :1;        /*   NCEJ           */
            unsigned char IOJ      :2;        /*   IOJ[1:0]       */
        }BIT;                                 /*                  */
    }TCRJ;                                    /*                  */

    union                                     /*                  */
    {                                         /* FCRJ             */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char FIFOENJ  :1;        /*   FIFOENJ        */
            unsigned char reserved1:1;        /*   Reserved Bits  */
            unsigned char FVCRENJ  :1;        /*   FVCRENJ        */
            unsigned char FRSTJ    :1;        /*   FRSTJ          */
            unsigned char reserved2:2;        /*   Reserved Bits  */
            unsigned char FDFTRGJ  :2;        /*   FDFTRGJ[1:0]   */
        }BIT;                                 /*                  */
    }FCRJ;                                    /*                  */

    union                                     /*                  */
    {                                         /* TSRJ             */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved:3;         /*   Reserved Bits  */
            unsigned char FVLDFJ  :1;         /*   FVLDFJ         */
            unsigned char CMFJ    :1;         /*   CMFJ           */
            unsigned char OVFJ    :1;         /*   OVFJ           */
            unsigned char FDOVFJ  :1;         /*   FDOVFJ         */
            unsigned char FDFFJ   :1;         /*   FDFFJ          */
        }BIT;                                 /*                  */
    }TSRJ;                                    /*                  */

    unsigned char dummy1[1];

    union                                     /*                  */
    {                                         /* TIERJ            */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved:5;         /*   Reserved Bits  */
            unsigned char OVEJ    :1;         /*   OVEJ           */
            unsigned char FDOVEJ  :1;         /*   FDOVEJ         */
            unsigned char FDFEJ   :1;         /*   FDFEJ          */
        }BIT;                                 /*                  */
    }TIERJ;                                   /*                  */

    union                                     /*                  */
    {                                         /* FDNRJ            */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved:4;         /*   Reserved Bits  */
            unsigned char FDNJ    :4;         /*   FDNJ[3:0]      */
        }BIT;                                 /*                  */
    }FDNRJ;                                   /*                  */

    unsigned char NCNTJ;                      /* NCNTJ            */

    unsigned char NCRJ;                       /* NCRJ             */

    unsigned short TCNTJ;                     /* TCNTJ            */

    unsigned short OCRJ;                      /* OCRJ             */

    unsigned short FIFOJ;                     /* FIFOJ            */

    unsigned char dummy2[2];

}t_timerJ_subblock;

struct st_timerJ
{
    union                                     /*                  */
    {                                         /* TSTRJ            */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved:6;         /*   Reserved Bits  */
            unsigned char STRJ1:1;            /*   STRJ1          */
            unsigned char STRJ0:1;            /*   STRJ0          */
        }BIT;                                 /*                  */
    }TSTRJ;                                   /*                  */

    unsigned char dummy1[15];

    t_timerJ_subblock SUBBLOCK[2];

};

struct st_atuctrl                             /* struct ATU       */
{                                             /*                  */
    union                                     /*                  */
    {                                         /* ATUENR           */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved:6;         /*   Reserved Bits  */
            unsigned char TJE:1;              /*   TJE            */
            unsigned char THE:1;              /*   THE            */
            unsigned char TGE:1;              /*   TGE            */
            unsigned char TFE:1;              /*   TFE            */
            unsigned char TEE:1;              /*   TEE            */
            unsigned char TDE:1;              /*   TDE            */
            unsigned char TCE:1;              /*   TCE            */
            unsigned char TBE:1;              /*   TBE            */
            unsigned char TAE:1;              /*   TAE            */
            unsigned char PSCE:1;             /*   PSCE           */
        }BIT;                                 /*                  */
    }ATUENR;                                  /*                  */

    union                                     /*                  */
    {                                         /* CBCNT            */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved1:2;        /*   Reserved Bits  */
            unsigned char CB4EG:2;            /*   CB4EG[1:0]     */
            unsigned char reserved2:1;        /*   Reserved Bits  */
            unsigned char CB5SEL:1;           /*   CB5SEL         */
            unsigned char CB5EG:2;            /*   CB5EG[1:0]     */
        }BIT;                                 /*                  */
    }CBCNT;                                   /*                  */

    union                                     /*                  */
    {                                         /* NCMR             */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char NCCSEL:1;           /*   NCCSEL         */
            unsigned char reserved:3;         /*   Reserved Bits  */
            unsigned char NCMJ:1;             /*   NCMJ           */
            unsigned char NCMF:1;             /*   NCMF           */
            unsigned char NCMC:1;             /*   NCMC           */
            unsigned char NCMA:1;             /*   NCMA           */
        }BIT;                                 /*                  */
    }NCMR;                                    /*                  */

    unsigned char dummy1[(0xFFFFF100u-0xFFFFF003u-1)];

    union                                     /*                  */
    {                                         /* PSCR0            */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned short reserved:6;        /*   Reserved Bits  */
            unsigned short PSC0:10;           /*   PSC0[9:0]      */
        }BIT;                                 /*                  */
    }PSCR0;                                   /*                  */

    union                                     /*                  */
    {                                         /* PSCR1            */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned short reserved:6;        /*   Reserved Bits  */
            unsigned short PSC1:10;           /*   PSC1[9:0]      */
        }BIT;                                 /*                  */
    }PSCR1;                                   /*                  */

    union                                     /*                  */
    {                                         /* PSCR2            */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned short reserved:6;        /*   Reserved Bits  */
            unsigned short PSC2:10;           /*   PSC2[9:0]      */
        }BIT;                                 /*                  */
    }PSCR2;                                   /*                  */

    union                                     /*                  */
    {                                         /* PSCR3            */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned short reserved:6;        /*   Reserved Bits  */
            unsigned short PSC3:10;           /*   PSC3[9:0]      */
        }BIT;                                 /*                  */
    }PSCR3;                                   /*                  */
};

/***********************************************************************************
    Watchdog Timer (WDT)
***********************************************************************************/
struct st_wdt                                 /* struct WDT       */
{                                             /*                  */
    union                                     /*                  */
    {                                         /* WTCR             */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char TCRKEY:8;           /*   TCRKEY[7:0]    */
            unsigned char reserved1:1;        /*   Reserved Bits  */
            unsigned char WTIT:1;             /*   WT/IT          */
            unsigned char TME:1;              /*   TME            */
            unsigned char reserved2:2;        /*   Reserved Bits  */
            unsigned char CKS:3;              /*   CKS[2:0]       */
        }BIT;                                 /*                  */
    }WTCR;                                    /*                  */

    union                                     /*                  */
    {                                         /* WTCNT            */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char TCNTKEY:8;          /*   TCNTKEY[7:0]   */
            unsigned char TCNT:8;             /*   TCNT[7:0]      */
        }BIT;                                 /*                  */
    }WTCNT;                                   /*                  */

    union                                     /*                  */
    {                                         /* WTSR             */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char TSRKEY:8;           /*   TSRKEY[7:0]    */
            unsigned char WOVF:1;             /*   WOVF           */
            unsigned char reserved1:3;        /*   Reserved Bits  */
            unsigned char IOVF:1;             /*   IOVF           */
            unsigned char reserved2:3;        /*   Reserved Bits  */
        }BIT;                                 /*                  */
    }WTSR;                                    /*                  */

    union                                     /*                  */
    {                                         /* WRCR             */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char RCRKEY:8;           /*   RCRKEY[7:0]    */
            unsigned char RSTE:1;             /*   RSTE           */
            unsigned char reserved:7;         /*   Reserved Bits  */
        }BIT;                                 /*                  */
    }WRCR;                                    /*                  */
};

/***********************************************************************************
    Compare Match Timer ( CMT )
***********************************************************************************/
typedef struct st_CMT_Channel                 /* struct CMT       */
{
    union                                     /*                  */
    {                                         /* CMCR             */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved1:1;        /*   Reserved Bits  */
            unsigned char CMIE:1;             /*   CMIE           */
            unsigned char reserved2:4;        /*   Reserved Bits  */
            unsigned char CKS:2;              /*   CKS[1:0]       */
        }BIT;                                 /*                  */
    }CMCR;                                    /*                  */

    union                                     /*                  */
    {                                         /* CMSR             */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved:7;         /*   Reserved Bits  */
            unsigned char CMF:1;              /*   CMF            */
        }BIT;                                 /*                  */
    }CMSR;                                    /*                  */

    unsigned short CMCNT;                     /*  CMCNT           */

    unsigned short CMCOR;                     /*  CMCOR           */

    unsigned char dummy[10];

}t_CMT_Channel;

struct st_cmt                                 /* struct CMT       */
{                                             /*                  */
    union                                     /*                  */
    {                                         /* CMSTR            */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned short reserved:14;       /*   Reserved Bits  */
            unsigned short STR1:1;            /*   STR1           */
            unsigned short STR0:1;            /*   STR0           */
        }BIT;                                 /*                  */
    }CMSTR;                                   /*                  */

    unsigned char dummy1[14];

    t_CMT_Channel Channel[2];
};

/***********************************************************************************
    Serial Communication Interface (SCI)
***********************************************************************************/
struct st_sci                                 /* struct SCI       */
{                                             /*                  */
    union                                     /*                  */
    {                                         /* SCSMR1           */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char CA:1;               /*   CA             */
            unsigned char CHR:1;              /*   CHR            */
            unsigned char PE:1;               /*   PE             */
            unsigned char OE:1;               /*   OE             */
            unsigned char STOP:1;             /*   STOP           */
            unsigned char reserved:1;         /*   Reserved Bits  */
            unsigned char CKS:2;              /*   CKS[1:0]       */
        }BIT;                                 /*                  */
    }SCSMR1;                                  /*                  */

    unsigned char dummy1[3];

    unsigned char SCBRR1;                     /* SCBRR1           */

    unsigned char dummy2[3];

    union                                     /*                  */
    {                                         /* SCSCR1           */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char TIE:1;              /*   TIE            */
            unsigned char RIE:1;              /*   RIE            */
            unsigned char TE:1;               /*   TE             */
            unsigned char RE:1;               /*   RE             */
            unsigned char reserved1:1;        /*   Reserved Bits  */
            unsigned char TEIE:1;             /*   TEIE           */
            unsigned char CKE1:1;             /*   CKE1           */
            unsigned char reserved2:1;        /*   Reserved Bits  */
        }BIT;                                 /*                  */
    }SCSCR1 ;                                 /*                  */

    unsigned char dummy3[3];

    unsigned char SCTDR1;                     /* SCTDR1           */

    unsigned char dummy4[3];

    union                                     /*                  */
    {                                         /* SCSSR1           */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char TDRE:1;             /*   TDRE           */
            unsigned char RDRF:1;             /*   RDRF           */
            unsigned char ORER:1;             /*   ORER           */
            unsigned char FER:1;              /*   FER            */
            unsigned char PER:1;              /*   PER            */
            unsigned char TEND:1;             /*   TEND           */
            unsigned char reserved:2;         /*   Reserved Bits  */
        }BIT;                                 /*                  */
    }SCSSR1;                                  /*                  */

    unsigned char dummy5[3];

    unsigned char SCRDR1;                     /* SCRDR1           */
};


/***********************************************************************************
    Renesas Serial Peripheral Interface (RSPI)
***********************************************************************************/
struct st_rspi                                /* struct RSPI      */
{                                             /*                  */
    union                                     /*                  */
    {                                         /* SPCR             */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char SPRIE:1;            /*   SPRIE          */
            unsigned char SPE:1;              /*   SPE            */
            unsigned char SPTIE:1;            /*   SPTIE          */
            unsigned char SPEIE:1;            /*   SPEIE          */
            unsigned char MSTR:1;             /*   MSTR           */
            unsigned char MODFEN:1;           /*   MODFEN         */
            unsigned char reserved:2;         /*   Reserved Bits  */
        }BIT;                                 /*                  */
    }SPCR;                                    /*                  */

    union                                     /*                  */
    {                                         /* SSLP             */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char SSL7P:1;            /*   SSL7P          */
            unsigned char SSL6P:1;            /*   SSL6P          */
            unsigned char SSL5P:1;            /*   SSL5P          */
            unsigned char SSL4P:1;            /*   SSL4P          */
            unsigned char SSL3P:1;            /*   SSL3P          */
            unsigned char SSL2P:1;            /*   SSL2P          */
            unsigned char SSL1P:1;            /*   SSL1P          */
            unsigned char SSL0P:1;            /*   SSL0P          */
        }BIT;                                 /*                  */
    }SSLP;                                    /*                  */

    union                                     /*                  */
    {                                         /* SPPCR            */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved1:2;        /*   Reserved Bits  */
            unsigned char MOIFE:1;            /*   MOIFE          */
            unsigned char MOIFV:1;            /*   MOIFV          */
            unsigned char reserved2:1;        /*   Reserved Bits  */
            unsigned char SPOM:1;             /*   SPOM           */
            unsigned char reserved3:1;        /*   Reserved Bits  */
            unsigned char SPLP:1;             /*   SPLP           */
        }BIT;                                 /*                  */
    }SPPCR;                                   /*                  */

    union                                     /*                  */
    {                                         /* SPSR             */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char SPRF:1;             /*   SPRF           */
            unsigned char reserved1:1;        /*   Reserved Bits  */
            unsigned char SPTEF:1;            /*   SPTEF          */
            unsigned char reserved2:2;        /*   Reserved Bits  */
            unsigned char MODF:1;             /*   MODF           */
            unsigned char reserved3:1;        /*   Reserved Bits  */
            unsigned char OVRF:1;             /*   OVRF           */
        }BIT;                                 /*                  */
    }SPSR;                                    /*                  */

    unsigned short SPDR;                      /*  SPDR            */

    unsigned char dummy1[2];

    union                                     /*                  */
    {                                         /* SPSCR            */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved:5;         /*   Reserved Bits  */
            unsigned char SPSLN:3;            /*   SPSLN[2:0]     */
        }BIT;                                 /*                  */
    }SPSCR;                                   /*                  */

    union                                     /*                  */
    {                                         /* SPSSR            */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved1:1;        /*   Reserved Bits  */
            unsigned char SPECM:3;            /*   SPECM[2:0]     */
            unsigned char reserved2:1;        /*   Reserved Bits  */
            unsigned char SPCP:3;             /*   SPCP[2:0]      */
        }BIT;                                 /*                  */
    }SPSSR;                                   /*                  */

    unsigned char SPBR;                       /* SPBR             */

    unsigned char dummy2[1];

    union                                     /*                  */
    {                                         /* SPCKD            */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved:5;         /*   Reserved Bits  */
            unsigned char SCKDL:3;            /*   SCKDL[2:0]     */
        }BIT;                                 /*                  */
    }SPCKD;                                   /*                  */

    union                                     /*                  */
    {                                         /* SSLND            */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved:5;         /*   Reserved Bits  */
            unsigned char SLNDL:3;            /*   SLNDL[2:0]     */
        }BIT;                                 /*                  */
    }SSLND;                                   /*                  */

    union                                     /*                  */
    {                                         /* SPND             */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved:5;         /*   Reserved Bits  */
            unsigned char SPNDL:3;            /*   SPNDL[2:0]     */
        }BIT;                                 /*                  */
    }SPND;                                    /*                  */

    unsigned char dummy3[1];

    union                                     /*                  */
    {                                         /* SPCMD0           */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned short SCKDEN:1;          /*   SCKDEN         */
            unsigned short SLNDEN:1;          /*   SLNDEN         */
            unsigned short SPNDEN:1;          /*   SPNDEN         */
            unsigned short LSBF:1;            /*   LSBF           */
            unsigned short SPB:4;             /*   SPB[3:0]       */
            unsigned short SSLKP:1;           /*   SSLKP          */
            unsigned short SSLA:3;            /*   SSLA[2:0]      */
            unsigned short BRDV:2;            /*   BRDV[1:0]      */
            unsigned short CPOL:1;            /*   CPOL           */
            unsigned short CPHA:1;            /*   CPHA           */
        }BIT;                                 /*                  */
    }SPCMD0;                                  /*                  */

    union                                     /*                  */
    {                                         /* SPCMD1           */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned short SCKDEN:1;          /*   SCKDEN         */
            unsigned short SLNDEN:1;          /*   SLNDEN         */
            unsigned short SPNDEN:1;          /*   SPNDEN         */
            unsigned short LSBF:1;            /*   LSBF           */
            unsigned short SPB:4;             /*   SPB[3:0]       */
            unsigned short SSLKP:1;           /*   SSLKP          */
            unsigned short SSLA:3;            /*   SSLA[2:0]      */
            unsigned short BRDV:2;            /*   BRDV[1:0]      */
            unsigned short CPOL:1;            /*   CPOL           */
            unsigned short CPHA:1;            /*   CPHA           */
        }BIT;                                 /*                  */
    }SPCMD1;                                  /*                  */

    union                                     /*                  */
    {                                         /* SPCMD2           */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned short SCKDEN:1;          /*   SCKDEN         */
            unsigned short SLNDEN:1;          /*   SLNDEN         */
            unsigned short SPNDEN:1;          /*   SPNDEN         */
            unsigned short LSBF:1;            /*   LSBF           */
            unsigned short SPB:4;             /*   SPB[3:0]       */
            unsigned short SSLKP:1;           /*   SSLKP          */
            unsigned short SSLA:3;            /*   SSLA[2:0]      */
            unsigned short BRDV:2;            /*   BRDV[1:0]      */
            unsigned short CPOL:1;            /*   CPOL           */
            unsigned short CPHA:1;            /*   CPHA           */
        }BIT;                                 /*                  */
    }SPCMD2;                                  /*                  */

    union                                     /*                  */
    {                                         /* SPCMD3           */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned short SCKDEN:1;          /*   SCKDEN         */
            unsigned short SLNDEN:1;          /*   SLNDEN         */
            unsigned short SPNDEN:1;          /*   SPNDEN         */
            unsigned short LSBF:1;            /*   LSBF           */
            unsigned short SPB:4;             /*   SPB[3:0]       */
            unsigned short SSLKP:1;           /*   SSLKP          */
            unsigned short SSLA:3;            /*   SSLA[2:0]      */
            unsigned short BRDV:2;            /*   BRDV[1:0]      */
            unsigned short CPOL:1;            /*   CPOL           */
            unsigned short CPHA:1;            /*   CPHA           */
        }BIT;                                 /*                  */
    }SPCMD3;                                  /*                  */

    union                                     /*                  */
    {                                         /* SPCMD4           */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned short SCKDEN:1;          /*   SCKDEN         */
            unsigned short SLNDEN:1;          /*   SLNDEN         */
            unsigned short SPNDEN:1;          /*   SPNDEN         */
            unsigned short LSBF:1;            /*   LSBF           */
            unsigned short SPB:4;             /*   SPB[3:0]       */
            unsigned short SSLKP:1;           /*   SSLKP          */
            unsigned short SSLA:3;            /*   SSLA[2:0]      */
            unsigned short BRDV:2;            /*   BRDV[1:0]      */
            unsigned short CPOL:1;            /*   CPOL           */
            unsigned short CPHA:1;            /*   CPHA           */
        }BIT;                                 /*                  */
    }SPCMD4;                                  /*                  */

    union                                     /*                  */
    {                                         /* SPCMD5           */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned short SCKDEN:1;          /*   SCKDEN         */
            unsigned short SLNDEN:1;          /*   SLNDEN         */
            unsigned short SPNDEN:1;          /*   SPNDEN         */
            unsigned short LSBF:1;            /*   LSBF           */
            unsigned short SPB:4;             /*   SPB[3:0]       */
            unsigned short SSLKP:1;           /*   SSLKP          */
            unsigned short SSLA:3;            /*   SSLA[2:0]      */
            unsigned short BRDV:2;            /*   BRDV[1:0]      */
            unsigned short CPOL:1;            /*   CPOL           */
            unsigned short CPHA:1;            /*   CPHA           */
        }BIT;                                 /*                  */
    }SPCMD5;                                  /*                  */

    union                                     /*                  */
    {                                         /* SPCMD6           */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned short SCKDEN:1;          /*   SCKDEN         */
            unsigned short SLNDEN:1;          /*   SLNDEN         */
            unsigned short SPNDEN:1;          /*   SPNDEN         */
            unsigned short LSBF:1;            /*   LSBF           */
            unsigned short SPB:4;             /*   SPB[3:0]       */
            unsigned short SSLKP:1;           /*   SSLKP          */
            unsigned short SSLA:3;            /*   SSLA[2:0]      */
            unsigned short BRDV:2;            /*   BRDV[1:0]      */
            unsigned short CPOL:1;            /*   CPOL           */
            unsigned short CPHA:1;            /*   CPHA           */
        }BIT;                                 /*                  */
    }SPCMD6;                                  /*                  */

    union                                     /*                  */
    {                                         /* SPCMD7           */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned short SCKDEN:1;          /*   SCKDEN         */
            unsigned short SLNDEN:1;          /*   SLNDEN         */
            unsigned short SPNDEN:1;          /*   SPNDEN         */
            unsigned short LSBF:1;            /*   LSBF           */
            unsigned short SPB:4;             /*   SPB[3:0]       */
            unsigned short SSLKP:1;           /*   SSLKP          */
            unsigned short SSLA:3;            /*   SSLA[2:0]      */
            unsigned short BRDV:2;            /*   BRDV[1:0]      */
            unsigned short CPOL:1;            /*   CPOL           */
            unsigned short CPHA:1;            /*   CPHA           */
        }BIT;                                 /*                  */
    }SPCMD7;                                  /*                  */
};

/***********************************************************************************
    Controller Area Network (RCAN-TL1)
***********************************************************************************/
typedef struct st_CAN_message_buffer
{
    union                                     /*                  */
    {                                         /* CONTROL0         */
        unsigned long LONG;                   /*  Long Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned long IDE:1;              /*   IDE            */
            unsigned long RTR:1;              /*   RTR            */
            unsigned long reserved:1;         /*   Reserved Bits  */
            unsigned long STDID:11;           /*   STDID[10:0]    */
            unsigned long EXTID:18;           /*   EXTID[17:0]    */
        }BIT;                                 /*                  */
    }CONTROL0;                                /*                  */
                                              /*                  */
    union                                     /*                  */
    {                                         /* LAFM             */
        unsigned long LONG;                   /*  Long Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned long IDE_LAFM:1;         /*   IDE_LAFM       */
            unsigned long reserved:2;         /*   Reserved Bits  */
            unsigned long STDID_LAFM:11;      /* STDID_LAFM[10:0] */
            unsigned long EXTID_LAFM:18;      /* EXTID_LAFM[17:0] */
        }BIT;                                 /*                  */
    }LAFM;                                    /*                  */
                                              /*                  */
    union                                     /*                  */
    {                                         /* DATA             */
        unsigned long LONG[2];                /*   Long Access    */
        unsigned short WORD[4];               /*   Word Access    */
        unsigned char BYTE[8];                /*   Byte Access    */
    }DATA;                                    /*                  */
                                              /*                  */
    union                                     /*                  */
    {                                         /* CONTROL1         */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved1:2;        /*   Reserved Bits  */
            unsigned char NMC:1;              /*   NMC            */
            unsigned char ATX:1;              /*   ATX            */
            unsigned char DART:1;             /*   DART           */
            unsigned char MBC:3;              /*   MBC[2:0]       */
            unsigned char reserved3:4;        /*   Reserved Bits  */
            unsigned char DLC:4;              /*   DLC[3:0]       */
        }BIT;                                 /*                  */
    }CONTROL1;                                /*                  */
                                              /*                  */
    unsigned short Timestamp;                 /* Timestamp        */
                                              /*                  */
    unsigned short TTT;                       /* TTT              */
                                              /*                  */
    union                                     /*                  */
    {                                         /* TTW              */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned short TTW:2;             /*   TTW[1:0]       */
            unsigned short Offset:6;          /*   Offset[5:0]    */
            unsigned short reserved:5;        /*   Reserved Bits  */
            unsigned short rep_factor:3;      /*   rep_factor[2:0]*/
        }BIT;                                 /*                  */
    }TTW;                                     /*                  */
                                              /*                  */
    unsigned char dummy[8];                   /*                  */
} t_CAN_message_buffer;

struct st_rcan                                /* struct RCAN      */
{                                             /*                  */
    union                                     /*                  */
    {                                         /* MCR              */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned short MCR15:1;           /*   MCR15          */
            unsigned short MCR14:1;           /*   MCR14          */
            unsigned short reserved1:3;       /*   Reserved Bits  */
            unsigned short TST:3;             /*   TST[2:0]       */
            unsigned short MCR7:1;            /*   MCR7           */
            unsigned short MCR6:1;            /*   MCR6           */
            unsigned short MCR5:1;            /*   MCR5           */
            unsigned short reserved2:2;       /*   Reserved Bits  */
            unsigned short MCR2:1;            /*   MCR2           */
            unsigned short MCR1:1;            /*   MCR1           */
            unsigned short MCR0:1;            /*   MCR0           */
        }BIT;                                 /*                  */
    }MCR;                                     /*                  */

    union                                     /*                  */
    {                                         /* GSR              */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned short reserved:10;       /*   Reserved Bits  */
            unsigned short GSR5:1;            /*   GSR5           */
            unsigned short GSR4:1;            /*   GSR4           */
            unsigned short GSR3:1;            /*   GSR3           */
            unsigned short GSR2:1;            /*   GSR2           */
            unsigned short GSR1:1;            /*   GSR1           */
            unsigned short GSR0:1;            /*   GSR0           */
        }BIT;                                 /*                  */
    }GSR;                                     /*                  */

    union                                     /*                  */
    {                                         /* BCR1             */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned short TSG1:4;            /*   TSG1[3:0]      */
            unsigned short reserved1:1;       /*   Reserved Bits  */
            unsigned short TSG2:3;            /*   TSG2[2:0]      */
            unsigned short reserved2:2;       /*   Reserved Bits  */
            unsigned short SJW:2;             /*   SJW[1:0]       */
            unsigned short reserved3:3;       /*   Reserved Bits  */
            unsigned short BSP:1;             /*   BSP            */
        }BIT;                                 /*                  */
    }BCR1;                                    /*                  */

    union                                     /*                  */
    {                                         /* BCR0             */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned short reserved:8;        /*   Reserved Bits  */
            unsigned short BRP:8;             /*   BRP[7:0]       */
        }BIT;                                 /*                  */
    }BCR0;                                    /*                  */

    union                                     /*                  */
    {                                         /* IRR              */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned short IRR15:1;           /*   IRR15          */
            unsigned short IRR14:1;           /*   IRR14          */
            unsigned short IRR13:1;           /*   IRR13          */
            unsigned short IRR12:1;           /*   IRR12          */
            unsigned short IRR11:1;           /*   IRR11          */
            unsigned short IRR10:1;           /*   IRR10          */
            unsigned short IRR9:1;            /*   IRR9           */
            unsigned short IRR8:1;            /*   IRR8           */
            unsigned short IRR7:1;            /*   IRR7           */
            unsigned short IRR6:1;            /*   IRR6           */
            unsigned short IRR5:1;            /*   IRR5           */
            unsigned short IRR4:1;            /*   IRR4           */
            unsigned short IRR3:1;            /*   IRR3           */
            unsigned short IRR2:1;            /*   IRR2           */
            unsigned short IRR1:1;            /*   IRR1           */
            unsigned short IRR0:1;            /*   IRR0           */
        }BIT;                                 /*                  */
    }IRR;                                     /*                  */

    union                                     /*                  */
    {                                         /* IMR              */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned short IMR15:1;           /*   IMR15          */
            unsigned short IMR14:1;           /*   IMR14          */
            unsigned short IMR13:1;           /*   IMR13          */
            unsigned short IMR12:1;           /*   IMR12          */
            unsigned short IMR11:1;           /*   IMR11          */
            unsigned short IMR10:1;           /*   IMR10          */
            unsigned short IMR9:1;            /*   IMR9           */
            unsigned short IMR8:1;            /*   IMR8           */
            unsigned short IMR7:1;            /*   IMR7           */
            unsigned short IMR6:1;            /*   IMR6           */
            unsigned short IMR5:1;            /*   IMR5           */
            unsigned short IMR4:1;            /*   IMR4           */
            unsigned short IMR3:1;            /*   IMR3           */
            unsigned short IMR2:1;            /*   IMR2           */
            unsigned short IMR1:1;            /*   IMR1           */
            unsigned short IMR0:1;            /*   IMR0           */
        }BIT;                                 /*                  */
    }IMR;                                     /*                  */

    union                                     /*                  */
    {                                         /* TEC_REC          */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char TEC7:1;             /*   TEC7           */
            unsigned char TEC6:1;             /*   TEC6           */
            unsigned char TEC5:1;             /*   TEC5           */
            unsigned char TEC4:1;             /*   TEC4           */
            unsigned char TEC3:1;             /*   TEC3           */
            unsigned char TEC2:1;             /*   TEC2           */
            unsigned char TEC1:1;             /*   TEC1           */
            unsigned char TEC0:1;             /*   TEC0           */
            unsigned char REC7:1;             /*   REC7           */
            unsigned char REC6:1;             /*   REC6           */
            unsigned char REC5:1;             /*   REC5           */
            unsigned char REC4:1;             /*   REC4           */
            unsigned char REC3:1;             /*   REC3           */
            unsigned char REC2:1;             /*   REC2           */
            unsigned char REC1:1;             /*   REC1           */
            unsigned char REC0:1;             /*   REC0           */
        }BIT;                                 /*                  */
    }TEC_REC;                                 /*                  */

    unsigned char dummy1[18];

    union                                     /*                  */
    {                                         /* TXPR             */
        unsigned long LONG;                   /*  Long Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned long TXPR1_15:1;         /*   TXPR1_15       */
            unsigned long TXPR1_14:1;         /*   TXPR1_14       */
            unsigned long TXPR1_13:1;         /*   TXPR1_13       */
            unsigned long TXPR1_12:1;         /*   TXPR1_12       */
            unsigned long TXPR1_11:1;         /*   TXPR1_11       */
            unsigned long TXPR1_10:1;         /*   TXPR1_10       */
            unsigned long TXPR1_9:1;          /*   TXPR1_9        */
            unsigned long TXPR1_8:1;          /*   TXPR1_8        */
            unsigned long TXPR1_7:1;          /*   TXPR1_7        */
            unsigned long TXPR1_6:1;          /*   TXPR1_6        */
            unsigned long TXPR1_5:1;          /*   TXPR1_5        */
            unsigned long TXPR1_4:1;          /*   TXPR1_4        */
            unsigned long TXPR1_3:1;          /*   TXPR1_3        */
            unsigned long TXPR1_2:1;          /*   TXPR1_2        */
            unsigned long TXPR1_1:1;          /*   TXPR1_1        */
            unsigned long TXPR1_0:1;          /*   TXPR1_0        */
            unsigned long TXPR0_15:1;         /*   TXPR0_15       */
            unsigned long TXPR0_14:1;         /*   TXPR0_14       */
            unsigned long TXPR0_13:1;         /*   TXPR0_13       */
            unsigned long TXPR0_12:1;         /*   TXPR0_12       */
            unsigned long TXPR0_11:1;         /*   TXPR0_11       */
            unsigned long TXPR0_10:1;         /*   TXPR0_10       */
            unsigned long TXPR0_9:1;          /*   TXPR0_9        */
            unsigned long TXPR0_8:1;          /*   TXPR0_8        */
            unsigned long TXPR0_7:1;          /*   TXPR0_7        */
            unsigned long TXPR0_6:1;          /*   TXPR0_6        */
            unsigned long TXPR0_5:1;          /*   TXPR0_5        */
            unsigned long TXPR0_4:1;          /*   TXPR0_4        */
            unsigned long TXPR0_3:1;          /*   TXPR0_3        */
            unsigned long TXPR0_2:1;          /*   TXPR0_2        */
            unsigned long TXPR0_1:1;          /*   TXPR0_1        */
            unsigned long reserved:1;         /*   Reserved Bits  */
        }BIT;                                 /*                  */
    }TXPR;                                    /*                  */

    unsigned char dummy2[4];

    union                                     /*                  */
    {                                         /* TXCR             */
        unsigned long LONG;                   /*  Long Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned long TXCR1_15:1;         /*   TXCR1_15       */
            unsigned long TXCR1_14:1;         /*   TXCR1_14       */
            unsigned long TXCR1_13:1;         /*   TXCR1_13       */
            unsigned long TXCR1_12:1;         /*   TXCR1_12       */
            unsigned long TXCR1_11:1;         /*   TXCR1_11       */
            unsigned long TXCR1_10:1;         /*   TXCR1_10       */
            unsigned long TXCR1_9:1;          /*   TXCR1_9        */
            unsigned long TXCR1_8:1;          /*   TXCR1_8        */
            unsigned long TXCR1_7:1;          /*   TXCR1_7        */
            unsigned long TXCR1_6:1;          /*   TXCR1_6        */
            unsigned long TXCR1_5:1;          /*   TXCR1_5        */
            unsigned long TXCR1_4:1;          /*   TXCR1_4        */
            unsigned long TXCR1_3:1;          /*   TXCR1_3        */
            unsigned long TXCR1_2:1;          /*   TXCR1_2        */
            unsigned long TXCR1_1:1;          /*   TXCR1_1        */
            unsigned long TXCR1_0:1;          /*   TXCR1_0        */
            unsigned long TXCR0_15:1;         /*   TXCR0_15       */
            unsigned long TXCR0_14:1;         /*   TXCR0_14       */
            unsigned long TXCR0_13:1;         /*   TXCR0_13       */
            unsigned long TXCR0_12:1;         /*   TXCR0_12       */
            unsigned long TXCR0_11:1;         /*   TXCR0_11       */
            unsigned long TXCR0_10:1;         /*   TXCR0_10       */
            unsigned long TXCR0_9:1;          /*   TXCR0_9        */
            unsigned long TXCR0_8:1;          /*   TXCR0_8        */
            unsigned long TXCR0_7:1;          /*   TXCR0_7        */
            unsigned long TXCR0_6:1;          /*   TXCR0_6        */
            unsigned long TXCR0_5:1;          /*   TXCR0_5        */
            unsigned long TXCR0_4:1;          /*   TXCR0_4        */
            unsigned long TXCR0_3:1;          /*   TXCR0_3        */
            unsigned long TXCR0_2:1;          /*   TXCR0_2        */
            unsigned long TXCR0_1:1;          /*   TXCR0_1        */
            unsigned long reserved:1;         /*   Reserved Bits  */
        }BIT;                                 /*                  */
        struct                                /*                  */
        {                                     /*  Word Access     */
            unsigned short TXCR1;             /*   TXCR1          */
            unsigned short TXCR0;             /*   TXCR0          */
        }WORD;                                /*                  */
    }TXCR;                                    /*                  */

    unsigned char dummy3[4];

    union                                     /*                  */
    {                                         /* TXACK            */
        unsigned long LONG;                   /*  Long Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned long TXACK1_15:1;        /*   TXACK1_15      */
            unsigned long TXACK1_14:1;        /*   TXACK1_14      */
            unsigned long TXACK1_13:1;        /*   TXACK1_13      */
            unsigned long TXACK1_12:1;        /*   TXACK1_12      */
            unsigned long TXACK1_11:1;        /*   TXACK1_11      */
            unsigned long TXACK1_10:1;        /*   TXACK1_10      */
            unsigned long TXACK1_9:1;         /*   TXACK1_9       */
            unsigned long TXACK1_8:1;         /*   TXACK1_8       */
            unsigned long TXACK1_7:1;         /*   TXACK1_7       */
            unsigned long TXACK1_6:1;         /*   TXACK1_6       */
            unsigned long TXACK1_5:1;         /*   TXACK1_5       */
            unsigned long TXACK1_4:1;         /*   TXACK1_4       */
            unsigned long TXACK1_3:1;         /*   TXACK1_3       */
            unsigned long TXACK1_2:1;         /*   TXACK1_2       */
            unsigned long TXACK1_1:1;         /*   TXACK1_1       */
            unsigned long TXACK1_0:1;         /*   TXACK1_0       */
            unsigned long TXACK0_15:1;        /*   TXACK0_15      */
            unsigned long TXACK0_14:1;        /*   TXACK0_14      */
            unsigned long TXACK0_13:1;        /*   TXACK0_13      */
            unsigned long TXACK0_12:1;        /*   TXACK0_12      */
            unsigned long TXACK0_11:1;        /*   TXACK0_11      */
            unsigned long TXACK0_10:1;        /*   TXACK0_10      */
            unsigned long TXACK0_9:1;         /*   TXACK0_9       */
            unsigned long TXACK0_8:1;         /*   TXACK0_8       */
            unsigned long TXACK0_7:1;         /*   TXACK0_7       */
            unsigned long TXACK0_6:1;         /*   TXACK0_6       */
            unsigned long TXACK0_5:1;         /*   TXACK0_5       */
            unsigned long TXACK0_4:1;         /*   TXACK0_4       */
            unsigned long TXACK0_3:1;         /*   TXACK0_3       */
            unsigned long TXACK0_2:1;         /*   TXACK0_2       */
            unsigned long TXACK0_1:1;         /*   TXACK0_1       */
            unsigned long reserved:1;         /*   Reserved Bits  */
        }BIT;                                 /*                  */
        struct                                /*                  */
        {                                     /*  Word Access     */
            unsigned short TXACK1;            /*   TXACK1         */
            unsigned short TXACK0;            /*   TXACK0         */
        }WORD;                                /*                  */
    }TXACK;                                   /*                  */

    unsigned char dummy4[4];

    union                                     /*                  */
    {                                         /* ABACK            */
        unsigned long LONG;                   /*  Long Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned long ABACK1_15:1;        /*   ABACK1_15      */
            unsigned long ABACK1_14:1;        /*   ABACK1_14      */
            unsigned long ABACK1_13:1;        /*   ABACK1_13      */
            unsigned long ABACK1_12:1;        /*   ABACK1_12      */
            unsigned long ABACK1_11:1;        /*   ABACK1_11      */
            unsigned long ABACK1_10:1;        /*   ABACK1_10      */
            unsigned long ABACK1_9:1;         /*   ABACK1_9       */
            unsigned long ABACK1_8:1;         /*   ABACK1_8       */
            unsigned long ABACK1_7:1;         /*   ABACK1_7       */
            unsigned long ABACK1_6:1;         /*   ABACK1_6       */
            unsigned long ABACK1_5:1;         /*   ABACK1_5       */
            unsigned long ABACK1_4:1;         /*   ABACK1_4       */
            unsigned long ABACK1_3:1;         /*   ABACK1_3       */
            unsigned long ABACK1_2:1;         /*   ABACK1_2       */
            unsigned long ABACK1_1:1;         /*   ABACK1_1       */
            unsigned long ABACK1_0:1;         /*   ABACK1_0       */
            unsigned long ABACK0_15:1;        /*   ABACK0_15      */
            unsigned long ABACK0_14:1;        /*   ABACK0_14      */
            unsigned long ABACK0_13:1;        /*   ABACK0_13      */
            unsigned long ABACK0_12:1;        /*   ABACK0_12      */
            unsigned long ABACK0_11:1;        /*   ABACK0_11      */
            unsigned long ABACK0_10:1;        /*   ABACK0_10      */
            unsigned long ABACK0_9:1;         /*   ABACK0_9       */
            unsigned long ABACK0_8:1;         /*   ABACK0_8       */
            unsigned long ABACK0_7:1;         /*   ABACK0_7       */
            unsigned long ABACK0_6:1;         /*   ABACK0_6       */
            unsigned long ABACK0_5:1;         /*   ABACK0_5       */
            unsigned long ABACK0_4:1;         /*   ABACK0_4       */
            unsigned long ABACK0_3:1;         /*   ABACK0_3       */
            unsigned long ABACK0_2:1;         /*   ABACK0_2       */
            unsigned long ABACK0_1:1;         /*   ABACK0_1       */
            unsigned long reserved:1;         /*   Reserved Bits  */
        }BIT;                                 /*                  */
        struct                                /*                  */
        {                                     /*  Word Access     */
            unsigned short ABACK1;            /*   ABACK1         */
            unsigned short ABACK0;            /*   ABACK0         */
        }WORD;                                /*                  */
    }ABACK;                                   /*                  */

    unsigned char dummy5[4];

    union                                     /*                  */
    {                                         /* RXPR             */
        unsigned long LONG;                   /*  Long Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned long RXPR1_15:1;         /*   RXPR1_15       */
            unsigned long RXPR1_14:1;         /*   RXPR1_14       */
            unsigned long RXPR1_13:1;         /*   RXPR1_13       */
            unsigned long RXPR1_12:1;         /*   RXPR1_12       */
            unsigned long RXPR1_11:1;         /*   RXPR1_11       */
            unsigned long RXPR1_10:1;         /*   RXPR1_10       */
            unsigned long RXPR1_9:1;          /*   RXPR1_9        */
            unsigned long RXPR1_8:1;          /*   RXPR1_8        */
            unsigned long RXPR1_7:1;          /*   RXPR1_7        */
            unsigned long RXPR1_6:1;          /*   RXPR1_6        */
            unsigned long RXPR1_5:1;          /*   RXPR1_5        */
            unsigned long RXPR1_4:1;          /*   RXPR1_4        */
            unsigned long RXPR1_3:1;          /*   RXPR1_3        */
            unsigned long RXPR1_2:1;          /*   RXPR1_2        */
            unsigned long RXPR1_1:1;          /*   RXPR1_1        */
            unsigned long RXPR1_0:1;          /*   RXPR1_0        */
            unsigned long RXPR0_15:1;         /*   RXPR0_15       */
            unsigned long RXPR0_14:1;         /*   RXPR0_14       */
            unsigned long RXPR0_13:1;         /*   RXPR0_13       */
            unsigned long RXPR0_12:1;         /*   RXPR0_12       */
            unsigned long RXPR0_11:1;         /*   RXPR0_11       */
            unsigned long RXPR0_10:1;         /*   RXPR0_10       */
            unsigned long RXPR0_9:1;          /*   RXPR0_9        */
            unsigned long RXPR0_8:1;          /*   RXPR0_8        */
            unsigned long RXPR0_7:1;          /*   RXPR0_7        */
            unsigned long RXPR0_6:1;          /*   RXPR0_6        */
            unsigned long RXPR0_5:1;          /*   RXPR0_5        */
            unsigned long RXPR0_4:1;          /*   RXPR0_4        */
            unsigned long RXPR0_3:1;          /*   RXPR0_3        */
            unsigned long RXPR0_2:1;          /*   RXPR0_2        */
            unsigned long RXPR0_1:1;          /*   RXPR0_1        */
            unsigned long RXPR0_0:1;          /*   RXPR0_0        */
        }BIT;                                 /*                  */
        struct                                /*                  */
        {                                     /*  Word Access     */
            unsigned short RXPR1;             /*   RXPR1          */
            unsigned short RXPR0;             /*   RXPR0          */
        }WORD;                                /*                  */
    }RXPR;                                    /*                  */

    unsigned char dummy6[4];

    union                                     /*                  */
    {                                         /* RFPR             */
        unsigned long LONG;                   /*  Long Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned long RFPR1_15:1;         /*   RFPR1_15       */
            unsigned long RFPR1_14:1;         /*   RFPR1_14       */
            unsigned long RFPR1_13:1;         /*   RFPR1_13       */
            unsigned long RFPR1_12:1;         /*   RFPR1_12       */
            unsigned long RFPR1_11:1;         /*   RFPR1_11       */
            unsigned long RFPR1_10:1;         /*   RFPR1_10       */
            unsigned long RFPR1_9:1;          /*   RFPR1_9        */
            unsigned long RFPR1_8:1;          /*   RFPR1_8        */
            unsigned long RFPR1_7:1;          /*   RFPR1_7        */
            unsigned long RFPR1_6:1;          /*   RFPR1_6        */
            unsigned long RFPR1_5:1;          /*   RFPR1_5        */
            unsigned long RFPR1_4:1;          /*   RFPR1_4        */
            unsigned long RFPR1_3:1;          /*   RFPR1_3        */
            unsigned long RFPR1_2:1;          /*   RFPR1_2        */
            unsigned long RFPR1_1:1;          /*   RFPR1_1        */
            unsigned long RFPR1_0:1;          /*   RFPR1_0        */
            unsigned long RFPR0_15:1;         /*   RFPR0_15       */
            unsigned long RFPR0_14:1;         /*   RFPR0_14       */
            unsigned long RFPR0_13:1;         /*   RFPR0_13       */
            unsigned long RFPR0_12:1;         /*   RFPR0_12       */
            unsigned long RFPR0_11:1;         /*   RFPR0_11       */
            unsigned long RFPR0_10:1;         /*   RFPR0_10       */
            unsigned long RFPR0_9:1;          /*   RFPR0_9        */
            unsigned long RFPR0_8:1;          /*   RFPR0_8        */
            unsigned long RFPR0_7:1;          /*   RFPR0_7        */
            unsigned long RFPR0_6:1;          /*   RFPR0_6        */
            unsigned long RFPR0_5:1;          /*   RFPR0_5        */
            unsigned long RFPR0_4:1;          /*   RFPR0_4        */
            unsigned long RFPR0_3:1;          /*   RFPR0_3        */
            unsigned long RFPR0_2:1;          /*   RFPR0_2        */
            unsigned long RFPR0_1:1;          /*   RFPR0_1        */
            unsigned long RFPR0_0:1;          /*   RFPR0_0        */
        }BIT;                                 /*                  */
        struct                                /*                  */
        {                                     /*  Word Access     */
            unsigned short RFPR1;             /*   RFPR1          */
            unsigned short RFPR0;             /*   RFPR0          */
        }WORD;                                /*                  */
    }RFPR;                                    /*                  */

    unsigned char dummy7[4];

    union                                     /*                  */
    {                                         /* MBIMR            */
        unsigned long LONG;                   /*  Long Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned long MBIMR1_15:1;        /*   MBIMR1_15      */
            unsigned long MBIMR1_14:1;        /*   MBIMR1_14      */
            unsigned long MBIMR1_13:1;        /*   MBIMR1_13      */
            unsigned long MBIMR1_12:1;        /*   MBIMR1_12      */
            unsigned long MBIMR1_11:1;        /*   MBIMR1_11      */
            unsigned long MBIMR1_10:1;        /*   MBIMR1_10      */
            unsigned long MBIMR1_9:1;         /*   MBIMR1_9       */
            unsigned long MBIMR1_8:1;         /*   MBIMR1_8       */
            unsigned long MBIMR1_7:1;         /*   MBIMR1_7       */
            unsigned long MBIMR1_6:1;         /*   MBIMR1_6       */
            unsigned long MBIMR1_5:1;         /*   MBIMR1_5       */
            unsigned long MBIMR1_4:1;         /*   MBIMR1_4       */
            unsigned long MBIMR1_3:1;         /*   MBIMR1_3       */
            unsigned long MBIMR1_2:1;         /*   MBIMR1_2       */
            unsigned long MBIMR1_1:1;         /*   MBIMR1_1       */
            unsigned long MBIMR1_0:1;         /*   MBIMR1_0       */
            unsigned long MBIMR0_15:1;        /*   MBIMR0_15      */
            unsigned long MBIMR0_14:1;        /*   MBIMR0_14      */
            unsigned long MBIMR0_13:1;        /*   MBIMR0_13      */
            unsigned long MBIMR0_12:1;        /*   MBIMR0_12      */
            unsigned long MBIMR0_11:1;        /*   MBIMR0_11      */
            unsigned long MBIMR0_10:1;        /*   MBIMR0_10      */
            unsigned long MBIMR0_9:1;         /*   MBIMR0_9       */
            unsigned long MBIMR0_8:1;         /*   MBIMR0_8       */
            unsigned long MBIMR0_7:1;         /*   MBIMR0_7       */
            unsigned long MBIMR0_6:1;         /*   MBIMR0_6       */
            unsigned long MBIMR0_5:1;         /*   MBIMR0_5       */
            unsigned long MBIMR0_4:1;         /*   MBIMR0_4       */
            unsigned long MBIMR0_3:1;         /*   MBIMR0_3       */
            unsigned long MBIMR0_2:1;         /*   MBIMR0_2       */
            unsigned long MBIMR0_1:1;         /*   MBIMR0_1       */
            unsigned long MBIMR0_0:1;         /*   MBIMR0_0       */
        }BIT;                                 /*                  */
        struct                                /*                  */
        {                                     /*  Word Access     */
            unsigned short MBIMR1;            /*   MBIMR1         */
            unsigned short MBIMR0;            /*   MBIMR0         */
        }WORD;                                /*                  */
    }MBIMR;                                   /*                  */

    unsigned char dummy8[4];

    union                                     /*                  */
    {                                         /* UMSR             */
        unsigned long LONG;                   /*  Long Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned long UMSR1_15:1;         /*   UMSR1_15       */
            unsigned long UMSR1_14:1;         /*   UMSR1_14       */
            unsigned long UMSR1_13:1;         /*   UMSR1_13       */
            unsigned long UMSR1_12:1;         /*   UMSR1_12       */
            unsigned long UMSR1_11:1;         /*   UMSR1_11       */
            unsigned long UMSR1_10:1;         /*   UMSR1_10       */
            unsigned long UMSR1_9:1;          /*   UMSR1_9        */
            unsigned long UMSR1_8:1;          /*   UMSR1_8        */
            unsigned long UMSR1_7:1;          /*   UMSR1_7        */
            unsigned long UMSR1_6:1;          /*   UMSR1_6        */
            unsigned long UMSR1_5:1;          /*   UMSR1_5        */
            unsigned long UMSR1_4:1;          /*   UMSR1_4        */
            unsigned long UMSR1_3:1;          /*   UMSR1_3        */
            unsigned long UMSR1_2:1;          /*   UMSR1_2        */
            unsigned long UMSR1_1:1;          /*   UMSR1_1        */
            unsigned long UMSR1_0:1;          /*   UMSR1_0        */
            unsigned long UMSR0_15:1;         /*   UMSR0_15       */
            unsigned long UMSR0_14:1;         /*   UMSR0_14       */
            unsigned long UMSR0_13:1;         /*   UMSR0_13       */
            unsigned long UMSR0_12:1;         /*   UMSR0_12       */
            unsigned long UMSR0_11:1;         /*   UMSR0_11       */
            unsigned long UMSR0_10:1;         /*   UMSR0_10       */
            unsigned long UMSR0_9:1;          /*   UMSR0_9        */
            unsigned long UMSR0_8:1;          /*   UMSR0_8        */
            unsigned long UMSR0_7:1;          /*   UMSR0_7        */
            unsigned long UMSR0_6:1;          /*   UMSR0_6        */
            unsigned long UMSR0_5:1;          /*   UMSR0_5        */
            unsigned long UMSR0_4:1;          /*   UMSR0_4        */
            unsigned long UMSR0_3:1;          /*   UMSR0_3        */
            unsigned long UMSR0_2:1;          /*   UMSR0_2        */
            unsigned long UMSR0_1:1;          /*   UMSR0_1        */
            unsigned long UMSR0_0:1;          /*   UMSR0_0        */
        }BIT;                                 /*                  */
        struct                                /*                  */
        {                                     /*  Word Access     */
            unsigned short UMSR1;             /*   UMSR1          */
            unsigned short UMSR0;             /*   UMSR0          */
        }WORD;                                /*                  */
    }UMSR;                                    /*                  */

    unsigned char dummy9[36];

    union                                     /*                  */
    {                                         /* TTCR0            */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned short TCR15:1;           /*   TCR15          */
            unsigned short TCR14:1;           /*   TCR14          */
            unsigned short TCR13:1;           /*   TCR13          */
            unsigned short TCR12:1;           /*   TCR12          */
            unsigned short TCR11:1;           /*   TCR11          */
            unsigned short TCR10:1;           /*   TCR10          */
            unsigned short reserved:3;        /*   Reserved Bits  */
            unsigned short TCR6:1;            /*   TCR6           */
            unsigned short TPSC5:1;           /*   TPSC5          */
            unsigned short TPSC4:1;           /*   TPSC4          */
            unsigned short TPSC3:1;           /*   TPSC3          */
            unsigned short TPSC2:1;           /*   TPSC2          */
            unsigned short TPSC1:1;           /*   TPSC1          */
            unsigned short TPSC0:1;           /*   TPSC0          */
        }BIT;                                 /*                  */
    }TTCR0;                                   /*                  */

    unsigned char dummy10[2];

    union                                     /*                  */
    {                                         /* CMAX_TEW         */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned short reserved1:5;       /*   Reserved Bits  */
            unsigned short CMAX:3;            /*   CMAX[2:0]      */
            unsigned short reserved2:4;       /*   Reserved Bits  */
            unsigned short TEW:4;             /*   TEW[3:0]       */
        }BIT;                                 /*                  */
    }CMAX_TEW;                                /*                  */

    union                                     /*                  */
    {                                         /* RFTROFF          */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned short RFTROFF:8;         /*   RFTROFF[7:0]   */
            unsigned short reserved:8;        /*   Reserved Bits  */
        }BIT;                                 /*                  */
    }RFTROFF;                                 /*                  */

    union                                     /*                  */
    {                                         /* TSR              */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned short reserved:11;       /*   Reserved Bits  */
            unsigned short TSR4:1;            /*   TSR4           */
            unsigned short TSR3:1;            /*   TSR3           */
            unsigned short TSR2:1;            /*   TSR2           */
            unsigned short TSR1:1;            /*   TSR1           */
            unsigned short TSR0:1;            /*   TSR0           */
        }BIT;                                 /*                  */
    }TSR;                                     /*                  */

    union                                     /*                  */
    {                                         /* CCR              */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned short reserved:10;       /*   Reserved Bits  */
            unsigned short CCR:6;             /*   CCR[5:0]       */
        }BIT;                                 /*                  */
    }CCR;                                     /*                  */

    unsigned short TCNTR;                     /* TCNTR            */

    unsigned char dummy11[2];

    unsigned short CYCTR;                     /* CYCTR            */

    unsigned char dummy12[2];

    unsigned short RFMK;                      /* RFMK             */

    unsigned char dummy13[2];

    unsigned short TCMR0;                     /* TCMR0            */

    unsigned char dummy14[2];

    unsigned short TCMR1;                     /* TCMR1            */

    unsigned char dummy15[2];

    unsigned short TCMR2;                     /* TCMR2            */

    unsigned char dummy16[2];

    union                                     /*                  */
    {                                         /* TTTSEL           */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned short reserved1:1;       /*   Reserved Bits  */
            unsigned short TTTSEL14:1;        /*   TTTSEL14       */
            unsigned short TTTSEL13:1;        /*   TTTSEL13       */
            unsigned short TTTSEL12:1;        /*   TTTSEL12       */
            unsigned short TTTSEL11:1;        /*   TTTSEL11       */
            unsigned short TTTSEL10:1;        /*   TTTSEL10       */
            unsigned short TTTSEL9:1;         /*   TTTSEL9        */
            unsigned short TTTSEL8:1;         /*   TTTSEL8        */
            unsigned short reserved2:8;       /*   Reserved Bits  */
        }BIT;                                 /*                  */
    }TTTSEL;                                  /*                  */

    unsigned char dummy17[90];

    t_CAN_message_buffer MSG[32];             /* CAN msg buffers  */

	unsigned char dummy18[(0xFFFFD600u-0xFFFFD500u)];

	union                                     /*                  */
    {                                         /* MBESR            */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned short reserved:15;       /*   Reserved Bits  */
            unsigned short MBEF:1;            /*   MBEF           */
        }BIT;                                 /*                  */
    }MBESR;                                   /*                  */

	union                                     /*                  */
    {                                         /* MBECR            */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned short reserved:15;       /*   Reserved Bits  */
            unsigned short MBIM:1;            /*   MBIM           */
        }BIT;                                 /*                  */
    }MBECR;                                   /*                  */

};

/***********************************************************************************
    A/D Converter (ADC)
***********************************************************************************/
struct st_adca                                /* struct ADCA      */
{                                             /*                  */
    union                                     /*                  */
    {                                         /* ADCSR0           */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char ADST:1;             /*   ADST           */
            unsigned char ADCS:1;             /*   ADCS           */
            unsigned char reserved1:1;        /*   Reserved Bits  */
            unsigned char ADIE:1;             /*   ADIE           */
            unsigned char reserved2:2;        /*   Reserved Bits  */
            unsigned char TRGE:1;             /*   TRGE           */
            unsigned char EXTRG:1;            /*   EXTRG          */
        }BIT;                                 /*                  */
    }ADCSR0;                                  /*                  */

    unsigned char dummy1[1];

    union                                     /*                  */
    {                                         /* ADREF0           */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char ADSCACT:1;          /*   ADSCACT        */
            unsigned char ADITACT:1;          /*   ADITACT        */
            unsigned char reserved:5;         /*   Reserved Bits  */
            unsigned char ADF:1;              /*   ADF            */
        }BIT;                                 /*                  */
    }ADREF0;                                  /*                  */

    unsigned char dummy2[1];

    union                                     /*                  */
    {                                         /* ADTRE0           */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned short ADTRGE15:1;        /*   ADTRGE15       */
            unsigned short ADTRGE14:1;        /*   ADTRGE14       */
            unsigned short ADTRGE13:1;        /*   ADTRGE13       */
            unsigned short ADTRGE12:1;        /*   ADTRGE12       */
            unsigned short ADTRGE11:1;        /*   ADTRGE11       */
            unsigned short ADTRGE10:1;        /*   ADTRGE10       */
            unsigned short ADTRGE9:1;         /*   ADTRGE9        */
            unsigned short ADTRGE8:1;         /*   ADTRGE8        */
            unsigned short ADTRGE7:1;         /*   ADTRGE7        */
            unsigned short ADTRGE6:1;         /*   ADTRGE6        */
            unsigned short ADTRGE5:1;         /*   ADTRGE5        */
            unsigned short ADTRGE4:1;         /*   ADTRGE4        */
            unsigned short ADTRGE3:1;         /*   ADTRGE3        */
            unsigned short ADTRGE2:1;         /*   ADTRGE2        */
            unsigned short ADTRGE1:1;         /*   ADTRGE1        */
            unsigned short ADTRGE0:1;         /*   ADTRGE0        */
        }BIT;                                 /*                  */
    }ADTRE0;                                  /*                  */

    union                                     /*                  */
    {                                         /* ADTRF0           */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned short ADTF15:1;          /*   ADTF15         */
            unsigned short ADTF14:1;          /*   ADTF14         */
            unsigned short ADTF13:1;          /*   ADTF13         */
            unsigned short ADTF12:1;          /*   ADTF12         */
            unsigned short ADTF11:1;          /*   ADTF11         */
            unsigned short ADTF10:1;          /*   ADTF10         */
            unsigned short ADTF9:1;           /*   ADTF9          */
            unsigned short ADTF8:1;           /*   ADTF8          */
            unsigned short ADTF7:1;           /*   ADTF7          */
            unsigned short ADTF6:1;           /*   ADTF6          */
            unsigned short ADTF5:1;           /*   ADTF5          */
            unsigned short ADTF4:1;           /*   ADTF4          */
            unsigned short ADTF3:1;           /*   ADTF3          */
            unsigned short ADTF2:1;           /*   ADTF2          */
            unsigned short ADTF1:1;           /*   ADTF1          */
            unsigned short ADTF0:1;           /*   ADTF0          */
        }BIT;                                 /*                  */
    }ADTRF0;                                  /*                  */

    union                                     /*                  */
    {                                         /* ADTRS0           */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned short ADTRS15:1;         /*   ADTRS15        */
            unsigned short ADTRS14:1;         /*   ADTRS14        */
            unsigned short ADTRS13:1;         /*   ADTRS13        */
            unsigned short ADTRS12:1;         /*   ADTRS12        */
            unsigned short ADTRS11:1;         /*   ADTRS11        */
            unsigned short ADTRS10:1;         /*   ADTRS10        */
            unsigned short ADTRS9:1;          /*   ADTRS9         */
            unsigned short ADTRS8:1;          /*   ADTRS8         */
            unsigned short ADTRS7:1;          /*   ADTRS7         */
            unsigned short ADTRS6:1;          /*   ADTRS6         */
            unsigned short ADTRS5:1;          /*   ADTRS5         */
            unsigned short ADTRS4:1;          /*   ADTRS4         */
            unsigned short ADTRS3:1;          /*   ADTRS3         */
            unsigned short ADTRS2:1;          /*   ADTRS2         */
            unsigned short ADTRS1:1;          /*   ADTRS1         */
            unsigned short ADTRS0:1;          /*   ADTRS0         */
        }BIT;                                 /*                  */
    }ADTRS0;                                  /*                  */

    union                                     /*                  */
    {                                         /* ADSTRG0          */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned short ADSTRG15:1;        /*   ADSTRG15       */
            unsigned short ADSTRG14:1;        /*   ADSTRG14       */
            unsigned short ADSTRG13:1;        /*   ADSTRG13       */
            unsigned short ADSTRG12:1;        /*   ADSTRG12       */
            unsigned short ADSTRG11:1;        /*   ADSTRG11       */
            unsigned short ADSTRG10:1;        /*   ADSTRG10       */
            unsigned short ADSTRG9:1;         /*   ADSTRG9        */
            unsigned short ADSTRG8:1;         /*   ADSTRG8        */
            unsigned short ADSTRG7:1;         /*   ADSTRG7        */
            unsigned short ADSTRG6:1;         /*   ADSTRG6        */
            unsigned short ADSTRG5:1;         /*   ADSTRG5        */
            unsigned short ADSTRG4:1;         /*   ADSTRG4        */
            unsigned short ADSTRG3:1;         /*   ADSTRG3        */
            unsigned short ADSTRG2:1;         /*   ADSTRG2        */
            unsigned short ADSTRG1:1;         /*   ADSTRG1        */
            unsigned short ADSTRG0:1;         /*   ADSTRG0        */
        }BIT;                                 /*                  */
    }ADSTRG0;                                 /*                  */

    union                                     /*                  */
    {                                         /* ADTRD0           */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned short ADIDE15:1;         /*   ADIDE15        */
            unsigned short ADIDE14:1;         /*   ADIDE14        */
            unsigned short ADIDE13:1;         /*   ADIDE13        */
            unsigned short ADIDE12:1;         /*   ADIDE12        */
            unsigned short ADIDE11:1;         /*   ADIDE11        */
            unsigned short ADIDE10:1;         /*   ADIDE10        */
            unsigned short ADIDE9:1;          /*   ADIDE9         */
            unsigned short ADIDE8:1;          /*   ADIDE8         */
            unsigned short ADIDE7:1;          /*   ADIDE7         */
            unsigned short ADIDE6:1;          /*   ADIDE6         */
            unsigned short ADIDE5:1;          /*   ADIDE5         */
            unsigned short ADIDE4:1;          /*   ADIDE4         */
            unsigned short ADIDE3:1;          /*   ADIDE3         */
            unsigned short ADIDE2:1;          /*   ADIDE2         */
            unsigned short ADIDE1:1;          /*   ADIDE1         */
            unsigned short ADIDE0:1;          /*   ADIDE0         */
        }BIT;                                 /*                  */
    }ADTRD0;                                  /*                  */

    unsigned char dummy3[14];

    union                                     /*                  */
    {                                         /* ADADS0           */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char ADS7:1;             /*   ADS7           */
            unsigned char ADS6:1;             /*   ADS6           */
            unsigned char ADS5:1;             /*   ADS5           */
            unsigned char ADS4:1;             /*   ADS4           */
            unsigned char ADS3:1;             /*   ADS3           */
            unsigned char ADS2:1;             /*   ADS2           */
            unsigned char ADS1:1;             /*   ADS1           */
            unsigned char ADS0:1;             /*   ADS0           */
        }BIT;                                 /*                  */
    }ADADS0;                                  /*                  */

    unsigned char dummy4[1];

    union                                     /*                  */
    {                                         /* ADADC0           */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved:6;         /*   Reserved Bits  */
            unsigned char ADC:2;              /*   ADC[1:0]       */
        }BIT;                                 /*                  */
    }ADADC0;                                  /*                  */

    unsigned char dummy5[1];

    union                                     /*                  */
    {                                         /* ADANS0           */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned short ANS15:1;           /*   ANS15          */
            unsigned short ANS14:1;           /*   ANS14          */
            unsigned short ANS13:1;           /*   ANS13          */
            unsigned short ANS12:1;           /*   ANS12          */
            unsigned short ANS11:1;           /*   ANS11          */
            unsigned short ANS10:1;           /*   ANS10          */
            unsigned short ANS9:1;            /*   ANS9           */
            unsigned short ANS8:1;            /*   ANS8           */
            unsigned short ANS7:1;            /*   ANS7           */
            unsigned short ANS6:1;            /*   ANS6           */
            unsigned short ANS5:1;            /*   ANS5           */
            unsigned short ANS4:1;            /*   ANS4           */
            unsigned short ANS3:1;            /*   ANS3           */
            unsigned short ANS2:1;            /*   ANS2           */
            unsigned short ANS1:1;            /*   ANS1           */
            unsigned short ANS0:1;            /*   ANS0           */
        }BIT;                                 /*                  */
    }ADANS0;                                  /*                  */

    union                                     /*                  */
    {                                         /* ADANS1           */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned short reserved:9;        /*   Reserve Bits   */
            unsigned short ANS22:1;           /*   ANS22          */
            unsigned short ANS21:1;           /*   ANS21          */
            unsigned short ANS20:1;           /*   ANS20          */
            unsigned short ANS19:1;           /*   ANS19          */
            unsigned short ANS18:1;           /*   ANS18          */
            unsigned short ANS17:1;           /*   ANS17          */
            unsigned short ANS16:1;           /*   ANS16          */
        }BIT;                                 /*                  */
    }ADANS1;                                  /*                  */

    unsigned char dummy6[12];

    union                                     /*                  */
    {                                         /* ADCER0           */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned short ADRFMT:1;          /*   ADRFMT         */
            unsigned short reserved1:3;       /*   Reserved Bits  */
            unsigned short DIAGM:1;           /*   DIAGM          */
            unsigned short DIAGLD:1;          /*   DIAGLD         */
            unsigned short DIAGVAL:2;         /*   DIAGVAL[1:0]   */
            unsigned short CKS:1;             /*   CKS            */
            unsigned short reserved2:6;       /*   Reserved Bits  */
            unsigned short ITTRGS:1;          /*   ITTRGS         */
        }BIT;                                 /*                  */
    }ADCER0;                                  /*                  */

    unsigned char dummy7[12];

    unsigned short ADRD0;                     /*  ADRD0           */

    unsigned short ADR0;                      /*  ADR0            */

    unsigned short ADR1;                      /*  ADR1            */

    unsigned short ADR2;                      /*  ADR2            */

    unsigned short ADR3;                      /*  ADR3            */

    unsigned short ADR4;                      /*  ADR4            */

    unsigned short ADR5;                      /*  ADR5            */

    unsigned short ADR6;                      /*  ADR6            */

    unsigned short ADR7;                      /*  ADR7            */

    unsigned short ADR8;                      /*  ADR8            */

    unsigned short ADR9;                      /*  ADR9            */

    unsigned short ADR10;                     /*  ADR10           */

    unsigned short ADR11;                     /*  ADR11           */

    unsigned short ADR12;                     /*  ADR12           */

    unsigned short ADR13;                     /*  ADR13           */

    unsigned short ADR14;                     /*  ADR14           */

    unsigned short ADR15;                     /*  ADR15           */

    unsigned short ADR16;                     /*  ADR16           */

    unsigned short ADR17;                     /*  ADR17           */

    unsigned short ADR18;                     /*  ADR18           */

    unsigned short ADR19;                     /*  ADR19           */

    unsigned short ADR20;                     /*  ADR20           */

    unsigned short ADR21;                     /*  ADR21           */

    unsigned short ADR22;                     /*  ADR22           */
};

struct st_adcb
{
    union                                     /*                  */
    {                                         /* ADCSR1           */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char ADST:1;             /*   ADST           */
            unsigned char ADCS:1;             /*   ADCS           */
            unsigned char reserved1:1;        /*   Reserved Bits  */
            unsigned char ADIE:1;             /*   ADIE           */
            unsigned char reserved2:2;        /*   Reserved Bits  */
            unsigned char TRGE:1;             /*   TRGE           */
            unsigned char EXTRG:1;            /*   EXTRG          */
        }BIT;                                 /*                  */
    }ADCSR1;                                  /*                  */

    unsigned char dummy1[1];

    union                                     /*                  */
    {                                         /* ADREF1           */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char ADSCACT:1;          /*   ADSCACT        */
            unsigned char ADITACT:1;          /*   ADITACT        */
            unsigned char reserved:5;        /*   Reserved Bits  */
            unsigned char ADF:1;              /*   ADF            */
        }BIT;                                 /*                  */
    }ADREF1;                                  /*                  */

    unsigned char dummy2[13];

    union                                     /*                  */
    {                                         /* ADTRE1           */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char ADTRGE47:1;         /*   ADTRGE47       */
            unsigned char ADTRGE46:1;         /*   ADTRGE46       */
            unsigned char ADTRGE45:1;         /*   ADTRGE45       */
            unsigned char ADTRGE44:1;         /*   ADTRGE44       */
            unsigned char ADTRGE43:1;         /*   ADTRGE43       */
            unsigned char ADTRGE42:1;         /*   ADTRGE42       */
            unsigned char ADTRGE41:1;         /*   ADTRGE41       */
            unsigned char ADTRGE40:1;         /*   ADTRGE40       */
        }BIT;                                 /*                  */
    }ADTRE1;                                  /*                  */

    unsigned char dummy3[1];

    union                                     /*                  */
    {                                         /* ADTRF1           */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char ADTF47:1;           /*   ADTF47         */
            unsigned char ADTF46:1;           /*   ADTF46         */
            unsigned char ADTF45:1;           /*   ADTF45         */
            unsigned char ADTF44:1;           /*   ADTF44         */
            unsigned char ADTF43:1;           /*   ADTF43         */
            unsigned char ADTF42:1;           /*   ADTF42         */
            unsigned char ADTF41:1;           /*   ADTF41         */
            unsigned char ADTF40:1;           /*   ADTF40         */
        }BIT;                                 /*                  */
    }ADTRF1;                                  /*                  */

    unsigned char dummy4[1];

    union                                     /*                  */
    {                                         /* ADTRS1           */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char ADTRS47:1;          /*   ADTRS47        */
            unsigned char ADTRS46:1;          /*   ADTRS46        */
            unsigned char ADTRS45:1;          /*   ADTRS45        */
            unsigned char ADTRS44:1;          /*   ADTRS44        */
            unsigned char ADTRS43:1;          /*   ADTRS43        */
            unsigned char ADTRS42:1;          /*   ADTRS42        */
            unsigned char ADTRS41:1;          /*   ADTRS41        */
            unsigned char ADTRS40:1;          /*   ADTRS40        */
        }BIT;                                 /*                  */
    }ADTRS1;                                  /*                  */

    unsigned char dummy5[1];

    union                                     /*                  */
    {                                         /* ADSTRG1          */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char ADSTRG47:1;         /*   ADSTRG47       */
            unsigned char ADSTRG46:1;         /*   ADSTRG46       */
            unsigned char ADSTRG45:1;         /*   ADSTRG45       */
            unsigned char ADSTRG44:1;         /*   ADSTRG44       */
            unsigned char ADSTRG43:1;         /*   ADSTRG43       */
            unsigned char ADSTRG42:1;         /*   ADSTRG42       */
            unsigned char ADSTRG41:1;         /*   ADSTRG41       */
            unsigned char ADSTRG40:1;         /*   ADSTRG40       */
        }BIT;                                 /*                  */
    }ADSTRG1;                                 /*                  */

    unsigned char dummy6[1];

    union                                     /*                  */
    {                                         /* ADTRD1           */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char ADIDE47:1;          /*   ADIDE47        */
            unsigned char ADIDE46:1;          /*   ADIDE46        */
            unsigned char ADIDE45:1;          /*   ADIDE45        */
            unsigned char ADIDE44:1;          /*   ADIDE44        */
            unsigned char ADIDE43:1;          /*   ADIDE43        */
            unsigned char ADIDE42:1;          /*   ADIDE42        */
            unsigned char ADIDE41:1;          /*   ADIDE41        */
            unsigned char ADIDE40:1;          /*   ADIDE40        */
        }BIT;                                 /*                  */
    }ADTRD1;                                  /*                  */

    unsigned char dummy7[3];

    union                                     /*                  */
    {                                         /* ADADS1           */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char ADS47:1;            /*   ADS47          */
            unsigned char ADS46:1;            /*   ADS46          */
            unsigned char ADS45:1;            /*   ADS45          */
            unsigned char ADS44:1;            /*   ADS44          */
            unsigned char ADS43:1;            /*   ADS43          */
            unsigned char ADS42:1;            /*   ADS42          */
            unsigned char ADS41:1;            /*   ADS41          */
            unsigned char ADS40:1;            /*   ADS40          */
        }BIT;                                 /*                  */
    }ADADS1;                                  /*                  */

    unsigned char dummy8[1];

    union                                     /*                  */
    {                                         /* ADADC1           */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved:6;         /*   Reserved Bits  */
            unsigned char ADC:2;              /*   ADC[1:0]       */
        }BIT;                                 /*                  */
    }ADADC1;                                  /*                  */

    unsigned char dummy9[1];

    union                                     /*                  */
    {                                         /* ADANS3           */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned short reserved:7;        /*   Reserved Bits  */
            unsigned short ANS48:1;           /*   ANS48          */
            unsigned short ANS47:1;           /*   ANS47          */
            unsigned short ANS46:1;           /*   ANS46          */
            unsigned short ANS45:1;           /*   ANS45          */
            unsigned short ANS44:1;           /*   ANS44          */
            unsigned short ANS43:1;           /*   ANS43          */
            unsigned short ANS42:1;           /*   ANS42          */
            unsigned short ANS41:1;           /*   ANS41          */
            unsigned short ANS40:1;           /*   ANS40          */
        }BIT;                                 /*                  */
    }ADANS3;                                  /*                  */

    unsigned char dummy10[14];

    union                                     /*                  */
    {                                         /* ADCER1           */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned short ADRFMT:1;          /*   ADRFMT         */
            unsigned short reserved1:3;       /*   Reserved Bits  */
            unsigned short DIAGM:1;           /*   DIAGM          */
            unsigned short DIAGLD:1;          /*   DIAGLD         */
            unsigned short DIAGVAL:2;         /*   DIAGVAL[1:0]   */
            unsigned short CKS:1;             /*   CKS            */
            unsigned short reserved2:7;       /*   Reserved Bits  */
        }BIT;                                 /*                  */
    }ADCER1;                                  /*                  */

    unsigned char dummy11[12];

    unsigned short ADRD1;                     /*  ADRD1           */

    unsigned short ADR40;                     /*  ADR40           */

    unsigned short ADR41;                     /*  ADR41           */

    unsigned short ADR42;                     /*  ADR42           */

    unsigned short ADR43;                     /*  ADR43           */

    unsigned short ADR44;                     /*  ADR44           */

    unsigned short ADR45;                     /*  ADR45           */

    unsigned short ADR46;                     /*  ADR46           */

    unsigned short ADR47;                     /*  ADR47           */

    unsigned short ADR48;                     /*  ADR48           */
};

/***********************************************************************************
    Pin Function Controller (PFC)
    I/O Port
***********************************************************************************/
/***********************************************************
 * Port & PFC standard register definition typedefs        *
 **********************************************************/

typedef union                                 /*                  */
{                                             /* DR               */
    unsigned short WORD;                      /*  Word Access     */
    struct                                    /*                  */
    {                                         /*  Bit Access      */
        unsigned char DR15:1;                 /*     DR15         */
        unsigned char DR14:1;                 /*     DR14         */
        unsigned char DR13:1;                 /*     DR13         */
        unsigned char DR12:1;                 /*     DR12         */
        unsigned char DR11:1;                 /*     DR11         */
        unsigned char DR10:1;                 /*     DR10         */
        unsigned char DR9:1;                  /*     DR9          */
        unsigned char DR8:1;                  /*     DR8          */
        unsigned char DR7:1;                  /*     DR7          */
        unsigned char DR6:1;                  /*     DR6          */
        unsigned char DR5:1;                  /*     DR5          */
        unsigned char DR4:1;                  /*     DR4          */
        unsigned char DR3:1;                  /*     DR3          */
        unsigned char DR2:1;                  /*     DR2          */
        unsigned char DR1:1;                  /*     DR1          */
        unsigned char DR0:1;                  /*     DR0          */
    }BIT;                                     /*                  */
}t_PORT_DR;                                   /*                  */

typedef union                                 /*                  */
{                                             /* IOR              */
    unsigned short WORD;                      /*  Word Access     */
    struct                                    /*                  */
    {                                         /*  Bit Access      */
        unsigned char IOR15:1;                /*   IOR15          */
        unsigned char IOR14:1;                /*   IOR14          */
        unsigned char IOR13:1;                /*   IOR13          */
        unsigned char IOR12:1;                /*   IOR12          */
        unsigned char IOR11:1;                /*   IOR11          */
        unsigned char IOR10:1;                /*   IOR10          */
        unsigned char IOR9:1;                 /*   IOR9           */
        unsigned char IOR8:1;                 /*   IOR8           */
        unsigned char IOR7:1;                 /*   IOR7           */
        unsigned char IOR6:1;                 /*   IOR6           */
        unsigned char IOR5:1;                 /*   IOR5           */
        unsigned char IOR4:1;                 /*   IOR4           */
        unsigned char IOR3:1;                 /*   IOR3           */
        unsigned char IOR2:1;                 /*   IOR2           */
        unsigned char IOR1:1;                 /*   IOR1           */
        unsigned char IOR0:1;                 /*   IOR0           */
    }BIT;                                     /*                  */
}t_PORT_IOR;                                  /*                  */

typedef union                                 /*                  */
{                                             /* IR               */
    unsigned short WORD;                      /*  Word Access     */
    struct                                    /*                  */
    {                                         /*  Bit Access      */
        unsigned char IR15:1;                 /*   IR15           */
        unsigned char IR14:1;                 /*   IR14           */
        unsigned char IR13:1;                 /*   IR13           */
        unsigned char IR12:1;                 /*   IR12           */
        unsigned char IR11:1;                 /*   IR11           */
        unsigned char IR10:1;                 /*   IR10           */
        unsigned char IR9:1;                  /*   IR9            */
        unsigned char IR8:1;                  /*   IR8            */
        unsigned char IR7:1;                  /*   IR7            */
        unsigned char IR6:1;                  /*   IR6            */
        unsigned char IR5:1;                  /*   IR5            */
        unsigned char IR4:1;                  /*   IR4            */
        unsigned char IR3:1;                  /*   IR3            */
        unsigned char IR2:1;                  /*   IR2            */
        unsigned char IR1:1;                  /*   IR1            */
        unsigned char IR0:1;                  /*   IR0            */
    }BIT;                                     /*                  */
}t_PORT_IR;                                   /*                  */

typedef union                                 /*                  */
{                                             /* DSR              */
    unsigned short WORD;                      /*  Word Access     */
    struct                                    /*                  */
    {                                         /*  Bit Access      */
        unsigned char DSR15:1;                /*   DSR15          */
        unsigned char DSR14:1;                /*   DSR14          */
        unsigned char DSR13:1;                /*   DSR13          */
        unsigned char DSR12:1;                /*   DSR12          */
        unsigned char DSR11:1;                /*   DSR11          */
        unsigned char DSR10:1;                /*   DSR10          */
        unsigned char DSR9:1;                 /*   DSR9           */
        unsigned char DSR8:1;                 /*   DSR8           */
        unsigned char DSR7:1;                 /*   DSR7           */
        unsigned char DSR6:1;                 /*   DSR6           */
        unsigned char DSR5:1;                 /*   DSR5           */
        unsigned char DSR4:1;                 /*   DSR4           */
        unsigned char DSR3:1;                 /*   DSR3           */
        unsigned char DSR2:1;                 /*   DSR2           */
        unsigned char DSR1:1;                 /*   DSR1           */
        unsigned char DSR0:1;                 /*   DSR0           */
    }BIT;                                     /*                  */
}t_PORT_DSR;                                  /*                  */

typedef union                                 /*                  */
{                                             /* PSR              */
    unsigned short WORD;                      /*  Word Access     */
    struct                                    /*                  */
    {                                         /*  Bit Access      */
        unsigned char PSR15:1;                /*   PSR15          */
        unsigned char PSR14:1;                /*   PSR14          */
        unsigned char PSR13:1;                /*   PSR13          */
        unsigned char PSR12:1;                /*   PSR12          */
        unsigned char PSR11:1;                /*   PSR11          */
        unsigned char PSR10:1;                /*   PSR10          */
        unsigned char PSR9:1;                 /*   PSR9           */
        unsigned char PSR8:1;                 /*   PSR8           */
        unsigned char PSR7:1;                 /*   PSR7           */
        unsigned char PSR6:1;                 /*   PSR6           */
        unsigned char PSR5:1;                 /*   PSR5           */
        unsigned char PSR4:1;                 /*   PSR4           */
        unsigned char PSR3:1;                 /*   PSR3           */
        unsigned char PSR2:1;                 /*   PSR2           */
        unsigned char PSR1:1;                 /*   PSR1           */
        unsigned char PSR0:1;                 /*   PSR0           */
    }BIT;                                     /*                  */
}t_PORT_PSR;                                  /*                  */

typedef union                                 /*                  */
{                                             /* PR               */
    unsigned short WORD;                      /*  Word Access     */
    struct                                    /*                  */
    {                                         /*  Bit Access      */
        unsigned char PR15:1;                 /*   PR15           */
        unsigned char PR14:1;                 /*   PR14           */
        unsigned char PR13:1;                 /*   PR13           */
        unsigned char PR12:1;                 /*   PR12           */
        unsigned char PR11:1;                 /*   PR11           */
        unsigned char PR10:1;                 /*   PR10           */
        unsigned char PR9:1;                  /*   PR9            */
        unsigned char PR8:1;                  /*   PR8            */
        unsigned char PR7:1;                  /*   PR7            */
        unsigned char PR6:1;                  /*   PR6            */
        unsigned char PR5:1;                  /*   PR5            */
        unsigned char PR4:1;                  /*   PR4            */
        unsigned char PR3:1;                  /*   PR3            */
        unsigned char PR2:1;                  /*   PR2            */
        unsigned char PR1:1;                  /*   PR1            */
        unsigned char PR0:1;                  /*   PR0            */
    }BIT;                                     /*                  */
}t_PORT_PR;                                   /*                  */

typedef union                                 /*                  */
{                                             /* ER               */
    unsigned short WORD;                      /*  Word Access     */
    struct                                    /*                  */
    {                                         /*  Bit Access      */
        unsigned char reserved1:6;            /*   Reserved Bits  */
        unsigned char HES:2;                  /*   HES[1:0]       */
        unsigned char reserved2:6;            /*   Reserved Bits  */
        unsigned char LES:2;                  /*   LES[1:0]       */
    }BIT;                                     /*                  */
}t_PORT_ER;                                   /*                  */

/***********************************************************
 * Port A structure                                  *
 **********************************************************/

struct st_port_a                              /*                  */
{                                             /*                  */
    unsigned char dummy1[2];
                                              /*                  */
    t_PORT_DR DR;                             /* DR               */
                                              /*                  */
    unsigned char dummy2[2];
                                              /*                  */
    t_PORT_IOR IOR;                           /* IOR              */
                                              /*                  */
    unsigned char dummy3[8];
                                              /*                  */
    union                                     /*                  */
    {                                         /* CR4              */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved1:3;        /*   Reserved Bits  */
            unsigned char MD15:1;             /*   MD15           */
            unsigned char reserved2:3;        /*   Reserved Bits  */
            unsigned char MD14:1;             /*   MD14           */
            unsigned char reserved3:3;        /*   Reserved Bits  */
            unsigned char MD13:1;             /*   MD13           */
            unsigned char reserved4:3;        /*   Reserved Bits  */
            unsigned char MD12:1;             /*   MD12           */
        }BIT;                                 /*                  */
    }CR4;                                     /*                  */
                                              /*                  */
    union                                     /*                  */
    {                                         /* CR3              */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved1:3;        /*   Reserved Bits  */
            unsigned char MD11:1;             /*   MD11           */
            unsigned char reserved2:3;        /*   Reserved Bits  */
            unsigned char MD10:1;             /*   MD10           */
            unsigned char reserved3:3;        /*   Reserved Bits  */
            unsigned char MD9:1;              /*   MD9            */
            unsigned char reserved4:3;        /*   Reserved Bits  */
            unsigned char MD8:1;              /*   MD8            */
        }BIT;                                 /*                  */
    }CR3;                                     /*                  */
                                              /*                  */
    union                                     /*                  */
    {                                         /* CR2              */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved1:3;        /*   Reserved Bits  */
            unsigned char MD7:1;              /*   MD7            */
            unsigned char reserved2:3;        /*   Reserved Bits  */
            unsigned char MD6:1;              /*   MD6            */
            unsigned char reserved3:3;        /*   Reserved Bits  */
            unsigned char MD5:1;              /*   MD5            */
            unsigned char reserved4:3;        /*   Reserved Bits  */
            unsigned char MD4:1;              /*   MD4            */
        }BIT;                                 /*                  */
    }CR2;                                     /*                  */
                                              /*                  */
    union                                     /*                  */
    {                                         /* CR1              */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved1:3;        /*   Reserved Bits  */
            unsigned char MD3:1;              /*   MD3            */
            unsigned char reserved2:3;        /*   Reserved Bits  */
            unsigned char MD2:1;              /*   MD2            */
            unsigned char reserved3:3;        /*   Reserved Bits  */
            unsigned char MD1:1;              /*   MD1            */
            unsigned char reserved4:3;        /*   Reserved Bits  */
            unsigned char MD0:1;              /*   MD0            */
        }BIT;                                 /*                  */
    }CR1;                                     /*                  */

    t_PORT_IR IR;                             /* IR               */
                                              /*                  */
    unsigned char dummy4[4];                  /*                  */
                                              /*                  */
    t_PORT_PR PR;                             /* PR               */

    unsigned char dummy5[(0xFFFFCA00u-0xFFFE381Eu-2)];

    union                                     /*                  */
    {                                         /* CR4A             */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved1:3;        /*   Reserved Bits  */
            unsigned char MD15:1;             /*   MD15           */
            unsigned char reserved2:3;        /*   Reserved Bits  */
            unsigned char MD14:1;             /*   MD14           */
            unsigned char reserved3:3;        /*   Reserved Bits  */
            unsigned char MD13:1;             /*   MD13           */
            unsigned char reserved4:3;        /*   Reserved Bits  */
            unsigned char MD12:1;             /*   MD12           */
        }BIT;                                 /*                  */
    }CR4A;                                    /*                  */

    union                                     /*                  */
    {                                         /* CR3A             */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved1:3;        /*   Reserved Bits  */
            unsigned char MD11:1;             /*   MD11           */
            unsigned char reserved2:3;        /*   Reserved Bits  */
            unsigned char MD10:1;             /*   MD10           */
            unsigned char reserved3:3;        /*   Reserved Bits  */
            unsigned char MD9:1;              /*   MD9            */
            unsigned char reserved4:3;        /*   Reserved Bits  */
            unsigned char MD8:1;              /*   MD8            */
        }BIT;                                 /*                  */
    }CR3A;                                    /*                  */

    union                                     /*                  */
    {                                         /* CR2A             */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved1:3;        /*   Reserved Bits  */
            unsigned char MD7:1;              /*   MD7            */
            unsigned char reserved2:3;        /*   Reserved Bits  */
            unsigned char MD6:1;              /*   MD6            */
            unsigned char reserved3:3;        /*   Reserved Bits  */
            unsigned char MD5:1;              /*   MD5            */
            unsigned char reserved4:3;        /*   Reserved Bits  */
            unsigned char MD4:1;              /*   MD4            */
        }BIT;                                 /*                  */
    }CR2A;                                    /*                  */

    union                                     /*                  */
    {                                         /* CR1A             */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved1:3;        /*   Reserved Bits  */
            unsigned char MD3:1;              /*   MD3            */
            unsigned char reserved2:3;        /*   Reserved Bits  */
            unsigned char MD2:1;              /*   MD2            */
            unsigned char reserved3:3;        /*   Reserved Bits  */
            unsigned char MD1:1;              /*   MD1            */
            unsigned char reserved4:3;        /*   Reserved Bits  */
            unsigned char MD0:1;              /*   MD0            */
        }BIT;                                 /*                  */
    }CR1A;                                    /*                  */

};                                            /*                  */

/***********************************************************
 * Port B structure                                        *
 **********************************************************/

struct st_port_b                              /*                  */
{                                             /*                  */
    unsigned char dummy1[2];
                                              /*                  */
    t_PORT_DR DR;                             /* DR               */
                                              /*                  */
    unsigned char dummy2[2];
                                              /*                  */
    t_PORT_IOR IOR;                           /* IOR              */
                                              /*                  */
    unsigned char dummy3[8];
                                              /*                  */
    union                                     /*                  */
    {                                         /* CR4              */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved1:5;        /*   Reserved Bits  */
            unsigned char MD14:3;             /*   MD14[2:0]      */
            unsigned char reserved2:2;        /*   Reserved Bits  */
            unsigned char MD13:2;             /*   MD13[1:0]      */
            unsigned char reserved3:2;        /*   Reserved Bits  */
            unsigned char MD12:2;             /*   MD12[1:0]      */
        }BIT;                                 /*                  */
    }CR4;                                     /*                  */
                                              /*                  */
    union                                     /*                  */
    {                                         /* CR3              */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved1:2;        /*   Reserved Bits  */
            unsigned char MD11:2;             /*   MD11[1:0]      */
            unsigned char reserved2:3;        /*   Reserved Bits  */
            unsigned char MD10:1;             /*   MD10           */
            unsigned char reserved3:3;        /*   Reserved Bits  */
            unsigned char MD9:1;              /*   MD9            */
            unsigned char reserved4:2;        /*   Reserved Bits  */
            unsigned char MD8:2;              /*   MD8[1:0]       */
        }BIT;                                 /*                  */
    }CR3;                                     /*                  */
                                              /*                  */
    union                                     /*                  */
    {                                         /* CR2              */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved1:3;        /*   Reserved Bits  */
            unsigned char MD7:1;              /*   MD7            */
            unsigned char reserved2:3;        /*   Reserved Bits  */
            unsigned char MD6:1;              /*   MD6            */
            unsigned char reserved3:1;        /*   Reserved Bits  */
            unsigned char MD5:3;              /*   MD5[2:0]       */
            unsigned char reserved4:1;        /*   Reserved Bits  */
            unsigned char MD4:3;              /*   MD4[2:0]       */
        }BIT;                                 /*                  */
    }CR2;                                     /*                  */
                                              /*                  */
    union                                     /*                  */
    {                                         /* CR1              */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved1:2;        /*   Reserved Bits  */
            unsigned char MD3:2;              /*   MD3[1:0]       */
            unsigned char reserved2:2;        /*   Reserved Bits  */
            unsigned char MD2:2;              /*   MD2[1:0]       */
            unsigned char reserved3:2;        /*   Reserved Bits  */
            unsigned char MD1:2;              /*   MD1[1:0]       */
            unsigned char reserved4:2;        /*   Reserved Bits  */
            unsigned char MD0:2;              /*   MD0[1:0]       */
        }BIT;                                 /*                  */
    }CR1;                                     /*                  */
                                              /*                  */
    t_PORT_IR IR;                             /* IR               */
                                              /*                  */
    t_PORT_DSR DSR;                           /* DSR              */
                                              /*                  */
    t_PORT_PSR PSR;                           /* PSR              */
                                              /*                  */
    t_PORT_PR PR;                             /* PR               */

    unsigned char dummy4[(0xFFFFCA12u-0xFFFE389Eu-2)];

   union                                      /*                  */
    {                                         /* CR3A             */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved1:7;        /*   Reserved Bits  */
            unsigned char MD10:1;             /*   MD10           */
            unsigned char reserved2:3;        /*   Reserved Bits  */
            unsigned char MD9:1;              /*   MD9            */
            unsigned char reserved3:4;        /*   Reserved Bits  */
        }BIT;                                 /*                  */
    }CR3A;                                    /*                  */
                                              /*                  */
    union                                     /*                  */
    {                                         /* CR2A             */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved1:3;        /*   Reserved Bits  */
            unsigned char MD7:1;              /*   MD7            */
            unsigned char reserved2:3;        /*   Reserved Bits  */
            unsigned char MD6:1;              /*   MD6            */
            unsigned char reserved3:3;        /*   Reserved Bits  */
            unsigned char MD5:1;              /*   MD5            */
            unsigned char reserved4:3;        /*   Reserved Bits  */
            unsigned char MD4:1;              /*   MD4            */
        }BIT;                                 /*                  */
    }CR2A;                                    /*                  */

};                                            /*                  */

/***********************************************************
 * Port C structure                                  *
 **********************************************************/

struct st_port_c                              /*                  */
{                                             /*                  */
    unsigned char dummy1[2];
                                              /*                  */
    t_PORT_DR DR;                             /* DR               */
                                              /*                  */
    unsigned char dummy2[2];
                                              /*                  */
    t_PORT_IOR IOR;                           /* IOR              */
                                              /*                  */
    unsigned char dummy3[8];
                                              /*                  */
    union                                     /*                  */
    {                                         /* CR4              */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved1:3;        /*   Reserved Bits  */
            unsigned char MD15:1;             /*   MD15           */
            unsigned char reserved2:3;        /*   Reserved Bits  */
            unsigned char MD14:1;             /*   MD14           */
            unsigned char reserved3:3;        /*   Reserved Bits  */
            unsigned char MD13:1;             /*   MD13           */
            unsigned char reserved4:3;        /*   Reserved Bits  */
            unsigned char MD12:1;             /*   MD12           */
        }BIT;                                 /*                  */
    }CR4;                                     /*                  */
                                              /*                  */
    union                                     /*                  */
    {                                         /* CR3              */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved1:3;        /*   Reserved Bits  */
            unsigned char MD11:1;             /*   MD11           */
            unsigned char reserved2:3;        /*   Reserved Bits  */
            unsigned char MD10:1;             /*   MD10           */
            unsigned char reserved3:3;        /*   Reserved Bits  */
            unsigned char MD9:1;              /*   MD9            */
            unsigned char reserved4:3;        /*   Reserved Bits  */
            unsigned char MD8:1;              /*   MD8            */
        }BIT;                                 /*                  */
    }CR3;                                     /*                  */
                                              /*                  */
    union                                     /*                  */
    {                                         /* CR2              */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved1:3;        /*   Reserved Bits  */
            unsigned char MD7:1;              /*   MD7            */
            unsigned char reserved2:3;        /*   Reserved Bits  */
            unsigned char MD6:1;              /*   MD6            */
            unsigned char reserved3:3;        /*   Reserved Bits  */
            unsigned char MD5:1;              /*   MD5            */
            unsigned char reserved4:3;        /*   Reserved Bits  */
            unsigned char MD4:1;              /*   MD4            */
        }BIT;                                 /*                  */
    }CR2;                                     /*                  */
                                              /*                  */
    union                                     /*                  */
    {                                         /* CR1              */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved1:3;        /*   Reserved Bits  */
            unsigned char MD3:1;              /*   MD3            */
            unsigned char reserved2:3;        /*   Reserved Bits  */
            unsigned char MD2:1;              /*   MD2            */
            unsigned char reserved3:3;        /*   Reserved Bits  */
            unsigned char MD1:1;              /*   MD1            */
            unsigned char reserved4:3;        /*   Reserved Bits  */
            unsigned char MD0:1;              /*   MD0            */
        }BIT;                                 /*                  */
    }CR1;                                     /*                  */
                                              /*                  */
    t_PORT_IR IR;                             /* IR               */
                                              /*                  */
    t_PORT_DSR DSR;                           /* DSR              */
                                              /*                  */
    unsigned char dummy4[2];
                                              /*                  */
    t_PORT_PR PR;                             /* PR               */

    unsigned char dummy5[(0xFFFFCA20u-0xFFFE391Eu-2)];

    union                                     /*                  */
    {                                         /* CR4A             */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved1:3;        /*   Reserved Bits  */
            unsigned char MD15:1;             /*   MD15           */
            unsigned char reserved2:3;        /*   Reserved Bits  */
            unsigned char MD14:1;             /*   MD14           */
            unsigned char reserved3:3;        /*   Reserved Bits  */
            unsigned char MD13:1;             /*   MD13           */
            unsigned char reserved4:3;        /*   Reserved Bits  */
            unsigned char MD12:1;             /*   MD12           */
        }BIT;                                 /*                  */
    }CR4A;                                    /*                  */

    union                                     /*                  */
    {                                         /* CR3A             */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved1:3;        /*   Reserved Bits  */
            unsigned char MD11:1;             /*   MD11           */
            unsigned char reserved2:3;        /*   Reserved Bits  */
            unsigned char MD10:1;             /*   MD10           */
            unsigned char reserved3:3;        /*   Reserved Bits  */
            unsigned char MD9:1;              /*   MD9            */
            unsigned char reserved4:3;        /*   Reserved Bits  */
            unsigned char MD8:1;              /*   MD8            */
        }BIT;                                 /*                  */
    }CR3A;                                    /*                  */

    union                                     /*                  */
    {                                         /* CR2A             */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved1:3;        /*   Reserved Bits  */
            unsigned char MD7:1;              /*   MD7            */
            unsigned char reserved2:3;        /*   Reserved Bits  */
            unsigned char MD6:1;              /*   MD6            */
            unsigned char reserved3:3;        /*   Reserved Bits  */
            unsigned char MD5:1;              /*   MD5            */
            unsigned char reserved4:3;        /*   Reserved Bits  */
            unsigned char MD4:1;              /*   MD4            */
        }BIT;                                 /*                  */
    }CR2A;                                    /*                  */

    union                                     /*                  */
    {                                         /* CR1A             */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved1:3;        /*   Reserved Bits  */
            unsigned char MD3:1;              /*   MD3            */
            unsigned char reserved2:3;        /*   Reserved Bits  */
            unsigned char MD2:1;              /*   MD2            */
            unsigned char reserved3:3;        /*   Reserved Bits  */
            unsigned char MD1:1;              /*   MD1            */
            unsigned char reserved4:3;        /*   Reserved Bits  */
            unsigned char MD0:1;              /*   MD0            */
        }BIT;                                 /*                  */
    }CR1A;                                    /*                  */

};                                            /*                  */

/***********************************************************
 * Port F structure                                        *
 **********************************************************/

struct st_port_f                              /*                  */
{                                             /*                  */
    t_PORT_DR DR;                             /* DR               */
                                              /*                  */
    t_PORT_PR PR;                             /* PR               */
                                              /*                  */
    t_PORT_IR IR;                             /* IR               */
                                              /*                  */
    t_PORT_DSR DSR;                           /* DSR              */
                                              /*                  */
    t_PORT_PSR PSR;                           /* PSR              */
                                              /*                  */
    t_PORT_IOR IOR;                           /* IOR              */
                                              /*                  */
    union                                     /*                  */
    {                                         /* CR2              */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char MD15:2;             /*   MD15[1:0]      */
            unsigned char MD14:2;             /*   MD14[1:0]      */
            unsigned char MD13:2;             /*   MD13[1:0]      */
            unsigned char MD12:2;             /*   MD12[1:0]      */
            unsigned char MD11:2;             /*   MD11[1:0]      */
            unsigned char MD10:2;             /*   MD10[1:0]      */
            unsigned char MD9:2;              /*   MD9[1:0]       */
            unsigned char MD8:2;              /*   MD8[1:0]       */
        }BIT;                                 /*                  */
    }CR2;                                     /*                  */
                                              /*                  */
    union                                     /*                  */
    {                                         /* CR1              */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char MD7:2;              /*   MD7[1:0]       */
            unsigned char MD6:2;              /*   MD6[1:0]       */
            unsigned char MD5:2;              /*   MD5[1:0]       */
            unsigned char MD4:2;              /*   MD4[1:0]       */
            unsigned char MD3:2;              /*   MD3[1:0]       */
            unsigned char MD2:2;              /*   MD2[1:0]       */
            unsigned char MD1:2;              /*   MD1[1:0]       */
            unsigned char MD0:2;              /*   MD0[1:0]       */
        }BIT;                                 /*                  */
    }CR1;                                     /*                  */

    unsigned char dummy[(0xFFFFCA50u-0xFFFFC82Eu-2)];

    union                                     /*                  */
    {                                         /* CR4A             */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved1:3;        /*   Reserved Bits  */
            unsigned char MD15:1;             /*   MD15           */
            unsigned char reserved2:3;        /*   Reserved Bits  */
            unsigned char MD14:1;             /*   MD14           */
            unsigned char reserved3:3;        /*   Reserved Bits  */
            unsigned char MD13:1;             /*   MD13           */
            unsigned char reserved4:3;        /*   Reserved Bits  */
            unsigned char MD12:1;             /*   MD12           */
        }BIT;                                 /*                  */
    }CR4A;                                    /*                  */

    union                                     /*                  */
    {                                         /* CR3A             */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved1:3;        /*   Reserved Bits  */
            unsigned char MD11:1;             /*   MD11           */
            unsigned char reserved2:3;        /*   Reserved Bits  */
            unsigned char MD10:1;             /*   MD10           */
            unsigned char reserved3:3;        /*   Reserved Bits  */
            unsigned char MD9:1;              /*   MD9            */
            unsigned char reserved4:3;        /*   Reserved Bits  */
            unsigned char MD8:1;              /*   MD8            */
        }BIT;                                 /*                  */
    }CR3A;                                    /*                  */

    union                                     /*                  */
    {                                         /* CR2A             */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved1:3;        /*   Reserved Bits  */
            unsigned char MD7:1;              /*   MD7            */
            unsigned char reserved2:3;        /*   Reserved Bits  */
            unsigned char MD6:1;              /*   MD6            */
            unsigned char reserved3:8;        /*   Reserved Bits  */
        }BIT;                                 /*                  */
    }CR2A;                                    /*                  */

    union                                     /*                  */
    {                                         /* CR1A             */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved1:3;        /*   Reserved Bits  */
            unsigned char MD3:1;              /*   MD3            */
            unsigned char reserved2:3;        /*   Reserved Bits  */
            unsigned char MD2:1;              /*   MD2            */
            unsigned char reserved3:3;        /*   Reserved Bits  */
            unsigned char MD1:1;              /*   MD1            */
            unsigned char reserved4:3;        /*   Reserved Bits  */
            unsigned char MD0:1;              /*   MD0            */
        }BIT;                                 /*                  */
    }CR1A;                                    /*                  */

};                                            /*                  */

/***********************************************************
 * Port G structure                                  *
 **********************************************************/

struct st_port_g                              /*                  */
{                                             /*                  */
    t_PORT_DR DR;                             /* DR               */
                                              /*                  */
    t_PORT_PR PR;                             /* PR               */
                                              /*                  */
    t_PORT_IR IR;                             /* IR               */
                                              /*                  */
    t_PORT_DSR DSR;                           /* DSR              */
                                              /*                  */
    t_PORT_ER ER;                             /* ER               */
                                              /*                  */
    t_PORT_PSR PSR;                           /* PSR              */
                                              /*                  */
    t_PORT_IOR IOR;                           /* IOR              */
                                              /*                  */
    unsigned char dummy1[2];
                                              /*                  */
    union                                     /*                  */
    {                                         /* CR2              */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char MD15:2;             /*   MD15[1:0]      */
            unsigned char MD14:2;             /*   MD14[1:0]      */
            unsigned char MD13:2;             /*   MD13[1:0]      */
            unsigned char MD12:2;             /*   MD12[1:0]      */
            unsigned char MD11:2;             /*   MD11[1:0]      */
            unsigned char MD10:2;             /*   MD10[1:0]      */
            unsigned char MD9:2;              /*   MD9[1:0]       */
            unsigned char MD8:2;              /*   MD8[1:0]       */
        }BIT;                                 /*                  */
    }CR2;                                     /*                  */
                                              /*                  */
    union                                     /*                  */
    {                                         /* CR1              */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char MD7:2;              /*   MD7[1:0]       */
            unsigned char MD6:2;              /*   MD6[1:0]       */
            unsigned char MD5:2;              /*   MD5[1:0]       */
            unsigned char MD4:2;              /*   MD4[1:0]       */
            unsigned char MD3:2;              /*   MD3[1:0]       */
            unsigned char MD2:2;              /*   MD2[1:0]       */
            unsigned char MD1:2;              /*   MD1[1:0]       */
            unsigned char MD0:2;              /*   MD0[1:0]       */
        }BIT;                                 /*                  */
    }CR1;                                     /*                  */

    unsigned char dummy2[(0xFFFFCA60u-0xFFFFC842u-2)];

    union                                     /*                  */
    {                                         /* CR4A             */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved1:3;        /*   Reserved Bits  */
            unsigned char MD15:1;             /*   MD15           */
            unsigned char reserved2:3;        /*   Reserved Bits  */
            unsigned char MD14:1;             /*   MD14           */
            unsigned char reserved3:3;        /*   Reserved Bits  */
            unsigned char MD13:1;             /*   MD13           */
            unsigned char reserved4:3;        /*   Reserved Bits  */
            unsigned char MD12:1;             /*   MD12           */
        }BIT;                                 /*                  */
    }CR4A;                                    /*                  */

    union                                     /*                  */
    {                                         /* CR3A             */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved1:3;        /*   Reserved Bits  */
            unsigned char MD11:1;             /*   MD11           */
            unsigned char reserved2:3;        /*   Reserved Bits  */
            unsigned char MD10:1;             /*   MD10           */
            unsigned char reserved3:3;        /*   Reserved Bits  */
            unsigned char MD9:1;              /*   MD9            */
            unsigned char reserved4:3;        /*   Reserved Bits  */
            unsigned char MD8:1;              /*   MD8            */
        }BIT;                                 /*                  */
    }CR3A;                                    /*                  */

    union                                     /*                  */
    {                                         /* CR2A             */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved1:8;        /*   Reserved Bits  */
	        unsigned char reserved2:3;        /*   Reserved Bits  */
            unsigned char MD5:1;              /*   MD5            */
            unsigned char reserved3:3;        /*   Reserved Bits  */
            unsigned char MD4:1;              /*   MD4            */
        }BIT;                                 /*                  */
    }CR2A;                                    /*                  */

    union                                     /*                  */
    {                                         /* CR1A             */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved1:3;        /*   Reserved Bits  */
            unsigned char MD3:1;              /*   MD3            */
            unsigned char reserved2:3;        /*   Reserved Bits  */
            unsigned char MD2:1;              /*   MD2            */
            unsigned char reserved3:3;        /*   Reserved Bits  */
            unsigned char MD1:1;              /*   MD1            */
            unsigned char reserved4:3;        /*   Reserved Bits  */
            unsigned char MD0:1;              /*   MD0            */
        }BIT;                                 /*                  */
    }CR1A;                                    /*                  */

};                                            /*                  */

/***********************************************************
 * Port J structure                                        *
 **********************************************************/

struct st_port_j                              /*                  */
{                                             /*                  */
    t_PORT_DR DR;                             /* DR               */
                                              /*                  */
    t_PORT_PR PR;                             /* PR               */
                                              /*                  */
    t_PORT_IR IR;                             /* IR               */
                                              /*                  */
    t_PORT_DSR DSR;                           /* DSR              */
                                              /*                  */
    t_PORT_PSR PSR;                           /* PSR              */
                                              /*                  */
    unsigned char dummy1[2];
                                              /*                  */
    t_PORT_IOR IOR;                           /* IOR              */
                                              /*                  */
    unsigned char dummy2[2];
                                              /*                  */
    union                                     /*                  */
    {                                         /* CR2              */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved1:8;        /*   Reserved bits  */
            unsigned char reserved2:5;        /*   Reserved bits  */
            unsigned char MD9:1;              /*   MD9            */
            unsigned char reserved3:1;        /*   Reserved bits  */
            unsigned char MD8:1;              /*   MD8            */
        }BIT;                                 /*                  */
    }CR2;                                     /*                  */
                                              /*                  */
    union                                     /*                  */
    {                                         /* CR1              */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char MD7:2;              /*   MD7[1:0]       */
            unsigned char reserved1:1;        /*   Reserved bits  */
            unsigned char MD6:1;              /*   MD6            */
            unsigned char reserved2:1;        /*   Reserved bits  */
            unsigned char MD5:1;              /*   MD5            */
            unsigned char MD4:2;              /*   MD4[1:0]       */
            unsigned char MD3:2;              /*   MD3[1:0]       */
            unsigned char MD2:2;              /*   MD2[1:0]       */
            unsigned char MD1:2;              /*   MD1[1:0]       */
            unsigned char MD0:2;              /*   MD0[1:0]       */
        }BIT;                                 /*                  */
    }CR1;                                     /*                  */

    unsigned char dummy3[(0xFFFCA82u-0xFFFC872u-2)];

    union                                     /*                  */
    {                                         /* CR3A             */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved1:8;        /*   Reserved Bits  */
            unsigned char reserved2:3;        /*   Reserved Bits  */
            unsigned char MD9:1;              /*   MD9            */
            unsigned char reserved3:3;        /*   Reserved Bits  */
            unsigned char MD8:1;              /*   MD8            */
        }BIT;                                 /*                  */
    }CR3A;                                    /*                  */

    union                                     /*                  */
    {                                         /* CR2A             */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved1:3;        /*   Reserved Bits  */
            unsigned char MD7:1;              /*   MD7            */
            unsigned char reserved2:3;        /*   Reserved Bits  */
            unsigned char MD6:1;              /*   MD6            */
            unsigned char reserved3:3;        /*   Reserved Bits  */
            unsigned char MD5:1;              /*   MD5            */
            unsigned char reserved4:3;        /*   Reserved Bits  */
            unsigned char MD4:1;              /*   MD4            */
        }BIT;                                 /*                  */
    }CR2A;                                    /*                  */

    union                                     /*                  */
    {                                         /* CR1A             */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved1:3;        /*   Reserved Bits  */
            unsigned char MD3:1;              /*   MD3            */
            unsigned char reserved2:3;        /*   Reserved Bits  */
            unsigned char MD2:1;              /*   MD2            */
            unsigned char reserved3:8;        /*   Reserved Bits  */
        }BIT;                                 /*                  */
    }CR1A;                                    /*                  */

};                                            /*                  */

/***********************************************************
 * Port S structure                                        *
 **********************************************************/

struct st_port_s                              /*                  */
{                                             /*                  */
    unsigned char dummy1[2];
                                              /*                  */
    t_PORT_PR PR;                             /* PR               */
                                              /*                  */
    unsigned char dummy2[12];
                                              /*                  */
    union                                     /*                  */
    {                                         /* CR4              */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved1:1;        /*   Reserved Bits  */
            unsigned char MD15_2:1;           /*   MD15_2         */
            unsigned char reserved2:1;        /*   Reserved Bits  */
            unsigned char MD15_0:1;           /*   MD15_0         */
            unsigned char reserved3:1;        /*   Reserved Bits  */
            unsigned char MD14_2:1;           /*   MD14_2         */
            unsigned char reserved4:1;        /*   Reserved Bits  */
            unsigned char MD14_0:1;           /*   MD14_0         */
            unsigned char reserved5:1;        /*   Reserved Bits  */
            unsigned char MD13_2:1;           /*   MD13_2         */
            unsigned char reserved6:1;        /*   Reserved Bits  */
            unsigned char MD13_0:1;           /*   MD13_0         */
            unsigned char reserved7:1;        /*   Reserved Bits  */
            unsigned char MD12_2:1;           /*   MD12_2         */
            unsigned char reserved8:1;        /*   Reserved Bits  */
            unsigned char MD12_0:1;           /*   MD12_0         */
        }BIT;                                 /*                  */
    }CR4;                                     /*                  */
                                              /*                  */
    union                                     /*                  */
    {                                         /* CR3              */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved1:1;        /*   Reserved Bits  */
            unsigned char MD11_2:1;           /*   MD11_2         */
            unsigned char reserved2:1;        /*   Reserved Bits  */
            unsigned char MD11_0:1;           /*   MD11_0         */
            unsigned char reserved3:1;        /*   Reserved Bits  */
            unsigned char MD10_2:1;           /*   MD10_2         */
            unsigned char reserved4:1;        /*   Reserved Bits  */
            unsigned char MD10_0:1;           /*   MD10_0         */
            unsigned char reserved5:1;        /*   Reserved Bits  */
            unsigned char MD9_2:1;            /*   MD9_2          */
            unsigned char reserved6:1;        /*   Reserved Bits  */
            unsigned char MD9_0:1;            /*   MD9_0          */
            unsigned char reserved7:1;        /*   Reserved Bits  */
            unsigned char MD8_2:1;            /*   MD8_2          */
            unsigned char reserved8:1;        /*   Reserved Bits  */
            unsigned char MD8_0:1;            /*   MD8_0          */
        }BIT;                                 /*                  */
    }CR3;                                     /*                  */

    union                                     /*                  */
    {                                         /* CR2              */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved1:1;        /*   Reserved Bits  */
            unsigned char MD7_2:1;            /*   MD7_2          */
            unsigned char reserved2:1;        /*   Reserved Bits  */
            unsigned char MD7_0:1;            /*   MD7_0          */
            unsigned char reserved3:1;        /*   Reserved Bits  */
            unsigned char MD6_2:1;            /*   MD6_2          */
            unsigned char reserved4:1;        /*   Reserved Bits  */
            unsigned char MD6_0:1;            /*   MD6_0          */
            unsigned char reserved5:1;        /*   Reserved Bits  */
            unsigned char MD5_2:1;            /*   MD5_2          */
            unsigned char reserved6:1;        /*   Reserved Bits  */
            unsigned char MD5_0:1;            /*   MD5_0          */
            unsigned char reserved7:1;        /*   Reserved Bits  */
            unsigned char MD4_2:1;            /*   MD4_2          */
            unsigned char reserved8:1;        /*   Reserved Bits  */
            unsigned char MD4_0:1;            /*   MD4_0          */
        }BIT;                                 /*                  */
    }CR2;                                     /*                  */
                                              /*                  */
    union                                     /*                  */
    {                                         /* CR1              */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved1:1;        /*   Reserved Bits  */
            unsigned char MD3_2:1;            /*   MD3_2          */
            unsigned char reserved2:1;        /*   Reserved Bits  */
            unsigned char MD3_0:1;            /*   MD3_0          */
            unsigned char reserved3:1;        /*   Reserved Bits  */
            unsigned char MD2_2:1;            /*   MD2_2          */
            unsigned char reserved4:1;        /*   Reserved Bits  */
            unsigned char MD2_0:1;            /*   MD2_0          */
            unsigned char reserved5:1;        /*   Reserved Bits  */
            unsigned char MD1_2:1;            /*   MD1_2          */
            unsigned char reserved6:1;        /*   Reserved Bits  */
            unsigned char MD1_0:1;            /*   MD1_0          */
            unsigned char reserved7:1;        /*   Reserved Bits  */
            unsigned char MD0_2:1;            /*   MD0_2          */
            unsigned char reserved8:1;        /*   Reserved Bits  */
            unsigned char MD0_0:1;            /*   MD0_0          */
        }BIT;                                 /*                  */
    }CR1;                                     /*                  */

};                                            /*                  */


/***********************************************************
 * Port T structure                                        *
 **********************************************************/

struct st_port_t                              /*                  */
{                                             /*                  */
    unsigned char dummy1[2];
                                              /*                  */
    t_PORT_PR PR;                             /* PR               */
                                              /*                  */
    unsigned char dummy2[16];
                                              /*                  */

    union                                     /*                  */
    {                                         /*  CR2             */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved1:5;        /*   Reserved Bits  */
            unsigned char MD6_2:1;            /*   MD6_2          */
            unsigned char reserved2:1;        /*   Reserved Bits  */
            unsigned char MD6_0:1;            /*   MD6_0          */
            unsigned char reserved3:1;        /*   Reserved Bits  */
            unsigned char MD5_2:1;            /*   MD5_2          */
            unsigned char reserved4:1;        /*   Reserved Bits  */
            unsigned char MD5_0:1;            /*   MD5_0          */
            unsigned char reserved5:1;        /*   Reserved Bits  */
            unsigned char MD4_2:1;            /*   MD4_2          */
            unsigned char reserved6:1;        /*   Reserved Bits  */
            unsigned char MD4_0:1;            /*   MD4_0          */
        }BIT;                                 /*                  */
    }CR2;                                     /*                  */
                                              /*                  */
    union                                     /*                  */
    {                                         /*  CR1             */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved1:1;        /*   Reserved Bits  */
            unsigned char MD3_2:1;            /*   MD3_2          */
            unsigned char reserved2:1;        /*   Reserved Bits  */
            unsigned char MD3_0:1;            /*   MD3_0          */
            unsigned char reserved3:1;        /*   Reserved Bits  */
            unsigned char MD2_2:1;            /*   MD2_2          */
            unsigned char reserved4:1;        /*   Reserved Bits  */
            unsigned char MD2_0:1;            /*   MD2_0          */
            unsigned char reserved5:1;        /*   Reserved Bits  */
            unsigned char MD1_2:1;            /*   MD1_2          */
            unsigned char reserved6:1;        /*   Reserved Bits  */
            unsigned char MD1_0:1;            /*   MD1_0          */
            unsigned char reserved7:1;        /*   Reserved Bits  */
            unsigned char MD0_2:1;            /*   MD0_2          */
            unsigned char reserved8:1;        /*   Reserved Bits  */
            unsigned char MD0_0:1;            /*   MD0_0          */
        }BIT;                                 /*                  */
    }CR1;                                     /*                  */

};                                            /*                  */

/***********************************************************
 * Port CKCR Register                                      *
 **********************************************************/

struct st_portctrl                            /*                  */
{                                             /*                  */
    union                                     /* CKCR             */
    {                                         /*                  */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved1:8;        /*   Reserved Bits  */
            unsigned char reserved2:7;        /*   Reserved Bits  */
            unsigned char CKOE:1;             /*   CKOE           */
        }BIT;                                 /*                  */
    }CKCR;                                    /*                  */

};                                            /*                  */


/***********************************************************************************
    Multi-Input Signature Generator (MISG)
***********************************************************************************/
struct st_misg                                /* struct MISG      */
{                                             /*                  */
    union                                     /*                  */
    {                                         /* MISRCR           */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved:7;         /*   Reserved Bits  */
            unsigned char MISREN:1;           /*   MISREN         */
        }BIT;                                 /*                  */
    }MISRCR;                                  /*                  */

    unsigned char dummy[3];

    unsigned long MISR;                       /*  MISR            */
};

/***********************************************************************************
    ROM
***********************************************************************************/
struct st_rom                                 /* struct ROM        */
{                                             /*                   */
    union                                     /*                   */
    {                                         /* FPMON             */
        unsigned char BYTE;                   /*  Byte Access      */
        struct                                /*                   */
        {                                     /*  Bit Access       */
            unsigned char MDA     :1;         /*   MDA             */
            unsigned char reserved:7;         /*   Reserved Bits   */
        }BIT;                                 /*                   */
    }FPMON;                                   /*                   */

    unsigned char dummy1[1];

    union                                     /*                   */
    {                                         /* FMODR             */
        unsigned char BYTE;                   /*  Byte Access      */
        struct                                /*                   */
        {                                     /*  Bit Access       */
            unsigned char reserved1:3;        /*   Reserved Bits   */
            unsigned char FRDMD   :1;         /*   FRDMD           */
            unsigned char reserved2:4;        /*   Reserved Bits   */
        }BIT;                                 /*                   */
    }FMODR;                                   /*                   */

    unsigned char dummy2[13];

    union                                     /*                   */
    {                                         /* FASTAT            */
        unsigned char BYTE;                   /*  Byte Access      */
        struct                                /*                   */
        {                                     /*  Bit Access       */
            unsigned char ROMAE   :1;         /*   ROMAE           */
            unsigned char reserved:2;         /*   Reserved Bits   */
            unsigned char CMDLK   :1;         /*   CMDLK           */
            unsigned char EEPAE   :1;         /*   EEPAE           */
            unsigned char EEPIFE  :1;         /*   EEPIFE          */
            unsigned char EEPRPE  :1;         /*   EEPRPE          */
            unsigned char EEPWPE  :1;         /*   EEPWPE          */
        }BIT;                                 /*                   */
    }FASTAT;                                  /*                   */

    union                                     /*                   */
    {                                         /* FAEINT            */
        unsigned char BYTE;                   /*  Byte Access      */
        struct                                /*                   */
        {                                     /*  Bit Access       */
            unsigned char ROMAEIE :1;         /*   ROMAEIE         */
            unsigned char reserved:2;         /*   Reserved Bits   */
            unsigned char CMDLKIE :1;         /*   CMDLKIE         */
            unsigned char EEPAEIE :1;         /*   EEPAEIE         */
            unsigned char EEPIFEIE:1;         /*   EEPIFEIE        */
            unsigned char EEPRPEIE:1;         /*   EEPRPEIE        */
            unsigned char EEPWPEIE:1;         /*   EEPWPEIE        */
        }BIT;                                 /*                   */
    }FAEINT;                                  /*                   */

    unsigned char dummy3[14];

    union                                     /*                   */
    {                                         /* ROMMAT            */
        unsigned short WORD;                  /*  Word Access      */
        struct                                /*                   */
        {                                     /*  Bit Access       */
            unsigned short KEY     :8;        /*   KEY[15:8]       */
            unsigned short reserved:7;        /*   Reserved Bits   */
            unsigned short ROMSEL  :1;        /*   ROMSEL          */
        }BIT;                                 /*                   */
    }ROMMAT;                                  /*                   */

    unsigned char dummy4[50];

    union                                     /*                   */
    {                                         /* FCURAME           */
        unsigned short WORD;                  /*  Word Access      */
        struct                                /*                   */
        {                                     /*  Bit Access       */
            unsigned short KEY     :8;        /*   KEY[15:8]       */
            unsigned short reserved:7;        /*   Reserved Bits   */
            unsigned short FCRME   :1;        /*   FCRME           */
        }BIT;                                 /*                   */
    }FCURAME;                                 /*                   */

    unsigned char dummy5[(0xFFFFA900u-0xFFFFA854u-2)];

    union                                     /*                   */
    {                                         /* FSTATR0           */
        unsigned char BYTE;                   /*  Byte Access      */
        struct                                /*                   */
        {                                     /*  Bit Access       */
            unsigned char FRDY    :1;         /*   FRDY            */
            unsigned char ILGLERR :1;         /*   ILGLERR         */
            unsigned char ERSERR  :1;         /*   ERSERR          */
            unsigned char PRGERR  :1;         /*   PRGERR          */
            unsigned char SUSRDY  :1;         /*   SUSRDY          */
            unsigned char reserved:1;         /*   Reserved Bits   */
            unsigned char ERSSPD  :1;         /*   ERSSPD          */
            unsigned char PRGSPD  :1;         /*   PRGSPD          */
        }BIT;                                 /*                   */
    }FSTATR0;                                 /*                   */

    union                                     /*                   */
    {                                         /* FSTATR1           */
        unsigned char BYTE;                   /*  Byte Access      */
        struct                                /*                   */
        {                                     /*  Bit Access       */
            unsigned char FCUERR   :1;        /*   FCUERR          */
            unsigned char reserved1:2;        /*   Reserved Bits   */
            unsigned char FLOCKST  :1;        /*   FLOCKST         */
            unsigned char reserved2:2;        /*   Reserved Bits   */
            unsigned char FRDTCT   :1;        /*   FRDTCT          */
            unsigned char FRCRCT   :1;        /*   FRCRCT          */
        }BIT;                                 /*                   */
    }FSTATR1;                                 /*                   */

    union                                     /*                   */
    {                                         /* FENTRYR           */
        unsigned short WORD;                  /*  Word Access      */
        struct                                /*                   */
        {                                     /*  Bit Access       */
            unsigned short FEKEY   :8;        /*   FEKEY[15:8]     */
            unsigned short FENTRYD :1;        /*   FENTRYD         */
/*            unsigned short reserved1:3;  */ /*   Reserved Bits   */
/*            unsigned short FENTRY3 :1;   */ /*   FENTRY3         */
/*            unsigned short reserved2:2;  */ /*   Reserved Bits   */
            unsigned short reserved1:5;       /*   Reserved Bits[6:2]   */
            unsigned short FENTRY1 :1;        /*   FENTRY1         */
            unsigned short FENTRY0 :1;        /*   FENTRY0         */
        }BIT;                                 /*                   */
    }FENTRYR;                                 /*                   */

    union                                     /*                   */
    {                                         /* FPROTR            */
        unsigned short WORD;                  /*  Word Access      */
        struct                                /*                   */
        {                                     /*  Bit Access       */
            unsigned short FPKEY   :8;        /*   FPKEY[15:8]     */
            unsigned short reserved:7;        /*   Reserved Bits   */
            unsigned short FPROTCN :1;        /*   FPROTCN         */
        }BIT;                                 /*                   */
    }FPROTR;                                  /*                   */

    union                                     /*                   */
    {                                         /* FRESETR           */
        unsigned short WORD;                  /*  Word Access      */
        struct                                /*                   */
        {                                     /*  Bit Access       */
            unsigned short FRKEY   :8;        /*   FRKEY[15:8]     */
            unsigned short reserved:7;        /*   Reserved Bits   */
            unsigned short FRESET  :1;        /*   FRESET          */
        }BIT;                                 /*                   */
    }FRESETR;                                 /*                   */

    unsigned char dummy6[2];

    union                                     /*                   */
    {                                         /* FCMDR             */
        unsigned short WORD;                  /*  Word Access      */
        struct                                /*                   */
        {                                     /*  Bit Access       */
            unsigned short CMDR :8;           /*   CMDR            */
            unsigned short PCMDR:8;           /*   PCMDR           */
        }BIT;                                 /*                   */
    }FCMDR;                                   /*                   */

    union                                     /*                   */
    {                                         /* FRAMECCR          */
        unsigned char BYTE;                   /*  BYTE Access      */
        struct                                /*                   */
        {                                     /*  Bit Access       */
            unsigned char reserved :6;        /*  Reserved Bits    */
            unsigned char FRDCLE:1;           /*   FRDCLE          */
            unsigned char FRCCLE:1;           /*   FRCCLE          */
        }BIT;                                 /*                   */
    }FRAMECCR;                                /*                   */

    unsigned char dummy7[11];

    union                                     /*                   */
    {                                         /* FCPSR             */
        unsigned short WORD;                  /*  Word Access      */
        struct                                /*                   */
        {                                     /*  Bit Access       */
            unsigned short reserved:15;       /*   Reserved Bits   */
            unsigned short ESUSPMD :1;        /*   ESUSPMD         */
        }BIT;                                 /*                   */
    }FCPSR;                                   /*                   */

    unsigned char dummy8[2];

    union                                     /*                   */
    {                                         /* FPESTAT           */
        unsigned short WORD;                  /*  Word Access      */
        struct                                /*                   */
        {                                     /*  Bit Access       */
            unsigned short reserved:8;        /*   Reserved Bits   */
            unsigned short PEERRST :8;        /*   PEERRST[7:0]    */
        }BIT;                                 /*                   */
    }FPESTAT;                                 /*                   */
};

/***********************************************************************************
    EEPROM
***********************************************************************************/
struct st_eeprom                              /* struct EEPROM     */
{                                             /*                   */
    union                                     /*                   */
    {                                         /* EEPRE0            */
        unsigned short WORD;                  /*  Word Access      */
        struct                                /*                   */
        {                                     /*  Bit Access       */
            unsigned short KEY:8;             /*   KEY[15:8]       */
            unsigned short reserved:4;        /*   Reserved Bits   */
            unsigned short DBRE03:1;          /*   DBRE03          */
            unsigned short DBRE02:1;          /*   DBRE02          */
            unsigned short DBRE01:1;          /*   DBRE01          */
            unsigned short DBRE00:1;          /*   DBRE00          */
        }BIT;                                 /*                   */
    }EEPRE0;                                  /*                   */

    unsigned char dummy1[14];

    union                                     /*                   */
    {                                         /* EEPWE0            */
        unsigned short WORD;                  /*  Word Access      */
        struct                                /*                   */
        {                                     /*  Bit Access       */
            unsigned short KEY:8;             /*   KEY[15:8]       */
            unsigned short reserved:4;        /*   Reserved Bits   */
            unsigned short DBWE03:1;          /*   DBWE03          */
            unsigned short DBWE02:1;          /*   DBWE02          */
            unsigned short DBWE01:1;          /*   DBWE01          */
            unsigned short DBWE00:1;          /*   DBWE00          */
        }BIT;                                 /*                   */
    }EEPWE0;                                  /*                   */

    unsigned char dummy2[(0xFFFFA91Au-0xFFFFA850u-2)];

    union                                     /*                   */
    {                                         /* EEPBCCNT          */
        unsigned short WORD;                  /*  Word Access      */
        struct                                /*                   */
        {                                     /*  Bit Access       */
            unsigned short reserved1:3;       /*   Reserved Bits   */
            unsigned short BCADR    :10;      /*   BCADR[9:0]      */
            unsigned short reserved2:2;       /*   Reserved Bits   */
            unsigned short BCSIZE   :1;       /*   BCSIZE          */
        }BIT;                                 /*                   */
    }EEPBCCNT;                                /*                   */

    unsigned char dummy3[2];

    union                                     /*                   */
    {                                         /* EEPBCSTAT         */
        unsigned short WORD;                  /*  Word Access      */
        struct                                /*                   */
        {                                     /*  Bit Access       */
            unsigned short reserved:15;       /*   Reserved Bits   */
            unsigned short BCST     :1;       /*   BCST            */
        }BIT;                                 /*                   */
    }EEPBCSTAT;                               /*                   */

    unsigned char dummy4[(0xFFFFAB00u-0xFFFFA91Eu-2)];

    union                                     /*                   */
    {                                         /* EEPMAT            */
        unsigned short WORD;                  /*  Word Access      */
        struct                                /*                   */
        {                                     /*  Bit Access       */
            unsigned short KEY      :8;       /*   KEY[15:8]       */
            unsigned short reserved :7;       /*   Reserved Bits   */
            unsigned short EEPSEL   :1;       /*   EEPSEL          */
        }BIT;                                 /*                   */
    }EEPMAT;                                  /*                   */

	unsigned char dummy5[7758];

    union {
        unsigned short WORD;
        struct {
            unsigned short KEY      :8;
            unsigned short reserved :7;
            unsigned short FCUSEL   :1;
        } BIT;
    } FCUAREA;

};

/***********************************************************************************
    ROM CACHE (ROMC)
***********************************************************************************/
struct st_romc                                /* struct ROMC      */
{                                             /*                  */
    union                                     /*                  */
    {                                         /* RCCR             */
        unsigned long LONG;                   /*  Long Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned long reserved:28;        /*   Reserved Bits  */
            unsigned long RCF:1;              /*   RCF            */
            unsigned long RCFI:1;             /*   RCFI           */
            unsigned long RCFD:1;             /*   RCFD           */
            unsigned long RCE:1;              /*   RCE            */
        }BIT;                                 /*                  */
    }RCCR;                                    /*                  */

    unsigned char dummy[4];

    union                                     /*                  */
    {                                         /* RCCR2            */
        unsigned long LONG;                   /*  Long Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned long reserved1:24;       /*   Reserved Bits  */
            unsigned long PFECB:1;            /*   PFECB          */
            unsigned long PFENB:1;            /*   PFENB          */
            unsigned long PFECF:1;            /*   PFECF          */
            unsigned long PFE:1;              /*   PFE            */
            unsigned long reserved2:1;        /*   Reserved Bits  */
            unsigned long PCE2:1;             /*   PCE2           */
            unsigned long reserved3:1;        /*   Reserved Bits  */
            unsigned long PCE0:1;             /*   PCE0           */
        }BIT;                                 /*                  */
    }RCCR2;                                   /*                  */
};

/***********************************************************************************
    RAM
***********************************************************************************/
struct st_ram                                 /* struct RAM       */
{                                             /*                  */
    union                                     /*                  */
    {                                         /* RAMEN            */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned short RNKEY:8;           /*   RNKEY[7:0]     */
            unsigned short reserved:2;        /*   Reserved Bits  */
            unsigned short RAME5:1;           /*   RAME5          */
            unsigned short RAME4:1;           /*   RAME4          */
            unsigned short RAME3:1;           /*   RAME3          */
            unsigned short RAME2:1;           /*   RAME2          */
            unsigned short RAME1:1;           /*   RAME1          */
            unsigned short RAME0:1;           /*   RAME0          */
        }BIT;                                 /*                  */
    }RAMEN;                                   /*                  */

    union                                     /*                  */
    {                                         /* RAMWEN           */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned short RWNKEY:8;          /*   RWNKEY[7:0]    */
            unsigned short reserved:2;        /*   Reserved Bits  */
            unsigned short RAMWE5:1;          /*   RAMWE5         */
            unsigned short RAMWE4:1;          /*   RAMWE4         */
            unsigned short RAMWE3:1;          /*   RAMWE3         */
            unsigned short RAMWE2:1;          /*   RAMWE2         */
            unsigned short RAMWE1:1;          /*   RAMWE1         */
            unsigned short RAMWE0:1;          /*   RAMWE0         */
        }BIT;                                 /*                  */
    }RAMWEN;                                  /*                  */

    union                                     /*                  */
    {                                         /* RAMECC           */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned short REKEY:8;           /*   REKEY[7:0]     */
            unsigned short reserved:7;        /*   Reserved Bits  */
            unsigned short RECCA:1;           /*   RECCA          */
        }BIT;                                 /*                  */
    }RAMECC;                                  /*                  */

    union                                     /*                  */
    {                                         /* RAMERR           */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved1:3;        /*   Reserved Bits  */
	        unsigned char RPARI:1;            /*   RPARI          */
            unsigned char reserved2:2;        /*   Reserved Bits  */
            unsigned char RDTCT:1;            /*   RDTCT          */
            unsigned char RCRCT:1;            /*   RCRCT          */
        }BIT;                                 /*                  */
    }RAMERR;                                  /*                  */

    unsigned char dummy1[9];

    union                                     /*                  */
    {                                         /* RAMINT           */
        unsigned char BYTE;                   /*  Byte Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned char reserved1:3;        /*   Reserved Bits  */
            unsigned char RPEIE:1;            /*   RPEIE          */
            unsigned char reserved2:2;        /*   Reserved Bits  */
            unsigned char REDIE:1;            /*   REDIE          */
            unsigned char RECIE:1;            /*   RECIE          */
        }BIT;                                 /*                  */
    }RAMINT;                                  /*                  */

    unsigned char dummy2[1];

    union                                     /*                  */
    {                                         /* RAMACYC          */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned short RAKEY:8;           /*   RAKEY[7:0]     */
            unsigned short reserved1:2;       /*   Reserved Bits  */
            unsigned short WRCYC:2;           /*   WRCYC[1:0]     */
            unsigned short reserved2:3;       /*   Reserved Bits  */
            unsigned short RDCYC:1;           /*   RDCYC          */
        }BIT;                                 /*                  */
    }RAMACYC;                                 /*                  */
};

/***********************************************************************************
    Power-Down Modes
***********************************************************************************/
struct st_stby                                /* struct STBY      */
{                                             /*                  */
    union                                     /*                  */
    {                                         /* STBCR            */
        unsigned short WORD;                  /*  Word Access     */
        struct                                /*                  */
        {                                     /*  Bit Access      */
            unsigned short STBCRKEY:8;        /*   STBCRKEY[7:0]  */
            unsigned short reserved:3;        /*   Reserved Bits  */
            unsigned short MSTP4:1;           /*   MSTP4          */
            unsigned short MSTP3:1;           /*   MSTP3          */
            unsigned short MSTP2:1;           /*   MSTP2          */
            unsigned short MSTP1:1;           /*   MSTP1          */
            unsigned short MSTP0:1;           /*   MSTP0          */
        }BIT;                                 /*                  */
    }STBCR;                                   /*                  */
};


/***********************************************************************************
    Defines
***********************************************************************************/

#define INTC   (*(volatile struct st_intc *)0xFFFE0800u)       /* Interrupt Controller                         */

#define UBC    (*(volatile struct st_ubc *)0xFFFC0400u)        /* User Break Controller                        */

#define BSC    (*(volatile struct st_bsc *)0xFFFC0004u)        /* Bus State Controller                         */

#define DMAC0 (*(volatile struct st_dmac03 *)0xFFFE1000u)      /* Direct Memory Access Controller Channel 0    */
#define DMAC1 (*(volatile struct st_dmac03 *)0xFFFE1010u)      /* Direct Memory Access Controller Channel 1    */
#define DMAC2 (*(volatile struct st_dmac03 *)0xFFFE1020u)      /* Direct Memory Access Controller Channel 2    */
#define DMAC3 (*(volatile struct st_dmac03 *)0xFFFE1030u)      /* Direct Memory Access Controller Channel 3    */
#define DMAC4 (*(volatile struct st_dmac47 *)0xFFFE1040u)      /* Direct Memory Access Controller Channel 4    */
#define DMAC5 (*(volatile struct st_dmac47 *)0xFFFE1050u)      /* Direct Memory Access Controller Channel 5    */
#define DMAC6 (*(volatile struct st_dmac47 *)0xFFFE1060u)      /* Direct Memory Access Controller Channel 6    */
#define DMAC7 (*(volatile struct st_dmac47 *)0xFFFE1070u)      /* Direct Memory Access Controller Channel 7    */
#define DMACCOM (*(volatile struct st_dmaccom *)0xFFFE1200u )  /* Direct Memory Access Controller Control      */

#define ADMAC  (*(volatile struct st_admac  *)0xFFFE6000u)     /* Automotive Direct Memory Access Controller   */

#define ATUCTRL (*(volatile struct st_atuctrl *)0xFFFFF000u)   /* ATU Overall                                  */
#define ATUA (*(volatile struct st_timerA *)0xFFFFF200u)       /* ATU Timer A module                           */
#define ATUB (*(volatile struct st_timerB *)0xFFFFF300u)       /* ATU Timer B module                           */
#define ATUC (*(volatile struct st_timerC *)0xFFFFF400u)       /* ATU Timer C module                           */
#define ATUD (*(volatile struct st_timerD *)0xFFFFF500u)       /* ATU Timer D module                           */
#define ATUE (*(volatile struct st_timerE *)0xFFFFF700u)       /* ATU Timer E module                           */
#define ATUF (*(volatile struct st_timerF *)0xFFFFFA00u)       /* ATU Timer F module                           */
#define ATUG (*(volatile struct st_timerG *)0xFFFFFE00u)       /* ATU Timer G module                           */
#define ATUH (*(volatile struct st_timerH *)0xFFFFFF40u)       /* ATU Timer H module                           */
#define ATUJ (*(volatile struct st_timerJ *)0xFFFFFF80u)       /* ATU Timer J module                           */

#define WDT    (*(volatile struct st_wdt    *)0xFFFE0000u)     /* Watchdog Timer                               */

#define CMT    (*(volatile struct st_cmt    *)0xFFFEC000u)     /* Compare Match Timer                          */

#define SCIA   (*(volatile struct st_sci    *)0xFFFF8000u)     /* Serial Communication Interface Module A      */
#define SCIB   (*(volatile struct st_sci    *)0xFFFF8800u)     /* Serial Communication Interface Module B      */
#define SCIC   (*(volatile struct st_sci    *)0xFFFF9000u)     /* Serial Communication Interface Module C      */

#define RSPIA  (*(volatile struct st_rspi   *)0xFFFFB000u)     /* Renesas Serial Peripheral Interface Module A */
#define RSPIB  (*(volatile struct st_rspi   *)0xFFFFB800u)     /* Renesas Serial Peripheral Interface Module B */
#define RSPIC  (*(volatile struct st_rspi   *)0xFFFFC000u)     /* Renesas Serial Peripheral Interface Module C */

#define RCANA  (*(volatile struct st_rcan   *)0xFFFFD000u)     /* Renesas Controller Area Network Module A     */
#define RCANB  (*(volatile struct st_rcan   *)0xFFFFD800u)     /* Renesas Controller Area Network Module B     */
#define RCANC  (*(volatile struct st_rcan   *)0xFFFFE000u)     /* Renesas Controller Area Network Module C     */

#define ADCA (*(volatile struct st_adca *)0xFFFFE800u)         /* ADC Converter A                              */
#define ADCB (*(volatile struct st_adcb *)0xFFFFEC00u)         /* ADC Converter B                              */

#define PORTA (*(volatile struct st_port_a  *) 0xFFFE3800u)    /* PORT A (PORT and PFC Structures).            */
#define PORTB (*(volatile struct st_port_b  *) 0xFFFE3880u)    /* PORT B (PORT and PFC Structures).            */
#define PORTC (*(volatile struct st_port_c  *) 0xFFFE3900u)    /* PORT C (PORT and PFC Structures).            */
#define PORTD (*(volatile struct st_port_d  *) 0xFFFFC800u)    /* PORT D (PORT and PFC Structures).            */
#define PORTE (*(volatile struct st_port_e  *) 0xFFFFC810u)    /* PORT E (PORT and PFC Structures).            */
#define PORTF (*(volatile struct st_port_f  *) 0xFFFFC820u)    /* PORT F (PORT and PFC Structures).            */
#define PORTG (*(volatile struct st_port_g  *) 0xFFFFC830u)    /* PORT G (PORT and PFC Structures).            */
#define PORTJ (*(volatile struct st_port_j  *) 0xFFFFC860u)    /* PORT J (PORT and PFC Structures).            */
#define PORTS (*(volatile struct st_port_s  *) 0xFFFFCB00u)    /* PORT S (PORT and PFC Structures).            */
#define PORTT (*(volatile struct st_port_t  *) 0xFFFFCB20u)    /* PORT T (PORT and PFC Structures).            */
#define PORTCTRL (*(volatile struct st_portctrl *) 0xFFFFC920u)/* Port CK Control Register                     */

#define MISRCDR (*(volatile unsigned long *)0xFFF7FFFCu)       /* Multi-Input Signature Generator MISRCDR      */
#define MISG    (*(volatile struct st_misg *)0xFFFC1C00u)      /* Multi-Input Signature Generator              */

#define ROMC   (*(volatile struct st_romc   *)0xFFFC1400u)     /* Read-Only Memory Cache                       */

#define RAM    (*(volatile struct st_ram    *)0xFFFF0800u)     /* Random-Access Memory                         */

#define ROM    (*(volatile struct st_rom    *)0xFFFFA800u)     /* Read-Only Memory                             */

#define EEPROM (*(volatile struct st_eeprom *)0xFFFFA840u)     /* Electrical Erase/Program Read Only Memory    */

#define STBY   (*(volatile struct st_stby   *)0xFFFE0400u)     /* Power-Down Modes                             */

/***********************************************************************************/


 #endif   /* _SH7253_H */

/***********************************************************************************
 * $History: SH7253.h $
 ************************ Version 1.11 *************************
 *
 * chenge SH72533 -> SH7253
 *
 ************************ Version 1.1 *************************
 *
 * chenge IPRxx bit name -> Add "IPL_"
 *
 *  1.DMAC0~DMAC7-> IPL_DMAC0~IPL_DMAC7
 *  2.WDT -> IPL_WDT
 *  3.SCIA~C -> IPL_SCIA~IPL_SCIC
 *  4.RSPIA -> IPL_RSPIA~IPL_RSPIC
 *  5.RCANA -> IPL_RCANA~IPL_RCANC
 *
 *
 ************************ Version 1.0 *************************
 *
 * chenge IPRxx bit name -> Add "IPL_"
 *
 ************************ Version 0.9 *************************
 *
 * Add bit "RAMEN.RAME5"
 * Add bit "RAMEN.RAME4"
 * Add bit "RAMWEN.RAMWE5"
 * Add bit "RAMWEN.RAMWE4"
 *
 ************************ Version 0.8 *************************
 * SH72531 -> SH72533
 *
 *
 * Modify register "FENTRY"
 *
 *
 * *********************** Version 0.7 *************************
 * Add Register number in ATU-III Register
 * Add Register number in ROM/EEPROM Register
 *
 * *********************** Version 0.6 *************************
 *                                              Date: 04/12/2008
 * Modify Comment
 * Removed "IPL" in INT Register
 * Add Register number in ADC Register
 * Removed ADMATCR60,ADMATCR61
 * Removed BRCR Upper bit
 *
 * *********************** Version 0.5 *************************
 * Restructing of register definitions to include smaller
 * structure sizes.
 * Released to Customer 09/11/02
 *
 * End of file $Workfile: SH72531.h $
 ***********************************************************************************/
