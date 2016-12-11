#ifndef __ASM_ARM_IO_H
#define __ASM_ARM_IO_H


/*
 * Generic virtual read/write.  Note that we don't support half-word
 * read/writes.  We define __arch_*[bl] here, and leave __arch_*w
 * to the architecture specific code.
 */
#define __arch_getb(a)			(*(volatile unsigned char *)(a))
#define __arch_getw(a)			(*(volatile unsigned short *)(a))
#define __arch_getl(a)			(*(volatile unsigned int *)(a))

#define __arch_putb(v,a)		(*(volatile unsigned char *)(a) = (v))
#define __arch_putw(v,a)		(*(volatile unsigned short *)(a) = (v))
#define __arch_putl(v,a)		(*(volatile unsigned int *)(a) = (v))


#define __raw_writeb(v,a)		__arch_putb(v,a)
#define __raw_writew(v,a)		__arch_putw(v,a)
#define __raw_writel(v,a)		__arch_putl(v,a)

#define __raw_readb(a)			__arch_getb(a)
#define __raw_readw(a)			__arch_getw(a)
#define __raw_readl(a)			__arch_getl(a)

#define writeb(v,a)			__arch_putb(v,a)
#define writew(v,a)			__arch_putw(v,a)
#define writel(v,a)			__arch_putl(v,a)

#define readb(a)			__arch_getb(a)
#define readw(a)			__arch_getw(a)
#define readl(a)			__arch_getl(a)

#ifdef __io
#define outb(v,p)			__raw_writeb(v,__io(p))
#define outw(v,p)			__raw_writew(cpu_to_le16(v),__io(p))
#define outl(v,p)			__raw_writel(cpu_to_le32(v),__io(p))

#define inb(p)	({ unsigned int __v = __raw_readb(__io(p)); __v; })
#define inw(p)	({ unsigned int __v = le16_to_cpu(__raw_readw(__io(p))); __v; })
#define inl(p)	({ unsigned int __v = le32_to_cpu(__raw_readl(__io(p))); __v; })

#define outsb(p,d,l)			__raw_writesb(__io(p),d,l)
#define outsw(p,d,l)			__raw_writesw(__io(p),d,l)
#define outsl(p,d,l)			__raw_writesl(__io(p),d,l)

#define insb(p,d,l)			__raw_readsb(__io(p),d,l)
#define insw(p,d,l)			__raw_readsw(__io(p),d,l)
#define insl(p,d,l)			__raw_readsl(__io(p),d,l)
#endif

#define outb_p(val,port)		outb((val),(port))
#define outw_p(val,port)		outw((val),(port))
#define outl_p(val,port)		outl((val),(port))
#define inb_p(port)			inb((port))
#define inw_p(port)			inw((port))
#define inl_p(port)			inl((port))

#define outsb_p(port,from,len)		outsb(port,from,len)
#define outsw_p(port,from,len)		outsw(port,from,len)
#define outsl_p(port,from,len)		outsl(port,from,len)
#define insb_p(port,to,len)		insb(port,to,len)
#define insw_p(port,to,len)		insw(port,to,len)
#define insl_p(port,to,len)		insl(port,to,len)

#ifdef __mem_pci

#define readb(c) ({ unsigned int __v = __raw_readb(__mem_pci(c)); __v; })
#define readw(c) ({ unsigned int __v = le16_to_cpu(__raw_readw(__mem_pci(c))); __v; })
#define readl(c) ({ unsigned int __v = le32_to_cpu(__raw_readl(__mem_pci(c))); __v; })

#define writeb(v,c)		__raw_writeb(v,__mem_pci(c))
#define writew(v,c)		__raw_writew(cpu_to_le16(v),__mem_pci(c))
#define writel(v,c)		__raw_writel(cpu_to_le32(v),__mem_pci(c))

#define memset_io(c,v,l)		_memset_io(__mem_pci(c),(v),(l))
#define memcpy_fromio(a,c,l)		_memcpy_fromio((a),__mem_pci(c),(l))
#define memcpy_toio(c,a,l)		_memcpy_toio(__mem_pci(c),(a),(l))
#elif !defined(readb)

#define readb(addr)			(__readwrite_bug("readb"),0)
#define readw(addr)			(__readwrite_bug("readw"),0)
#define readl(addr)			(__readwrite_bug("readl"),0)
#define writeb(v,addr)			__readwrite_bug("writeb")
#define writew(v,addr)			__readwrite_bug("writew")
#define writel(v,addr)			__readwrite_bug("writel")

#endif

#endif	/* __ASM_ARM_IO_H */
