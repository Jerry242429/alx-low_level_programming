#include <elf.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>


void check_elf(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_abi(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_type(unsigned int e_type, unsigned char *e_ident);
void close_elf(int elf);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);

/** 
 * main - printd ELF header information
 * @argc: argument count varibale
 * @argv: argument vector variable
 * Return: if it is on Success 0
 *
 */

int main(int __attribute__((__unused__))argc, char  *argv[])
{
	Elf64_Ehdr *header;
	int c, a;

	c = open(argv[1], O_RDONLY);
	if (c == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_elf(c);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	a = read(c, header, sizeof(Elf64_Ehdr));
	if (a == -1)
	{
		free(header);
		close_elf(c);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	check_elf(header->e_ident);
	printf("ELF Header:\n");
	print_magic(header->e_ident);
	print_data(header->e_ident);
	print_version(header->e_ident);
	print_osabi(header->e_ident);
	print_abi(header->e_ident);
	print_class(header->e_ident);
	print_type(header->e_type, header->e_ident);
	print_entry(header->e_entry, header->e_ident);

	free(header);
	close_elf(c);
	return (0);

}	
/**
 * check_elf - it checks whether the file is ELF or not
 * @e_ident: an ELF magic number
 */

void check_elf(unsigned char *e_ident)
{
	int i = 0;

	while (i < 4)
	{
		if (e_ident[i] != 127 &&
			e_ident[i] != 'F' &&	
			e_ident[i] != 'L' &&
			e_ident[i] != 'E')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}

		i++;		
	}
}

/**
 * print_data - a function that prints data of ELF
 * @e_ident: that contains an Elf class
 */

void print_data(unsigned char *e_ident)
{
	printf("Data:");

	if (e_ident[EI_DATA] == ELFDATANONE)
		printf("none\n");
	else if (e_ident[EI_DATA] == ELFDATA2LSB)
		printf("2's complement, little endian\n");
	else if (e_ident[EI_DATA] == ELFDATA2MSB)
		printf("2's complement, big endian\n");
	else
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
}

/**
 * print_version - function prints version of ELF
 * @e_ident: that contains ELF version.
 */

void print_version(unsigned char *e_ident)
{
	printf("Version: %d", e_ident[EI_VERSION]);
	if (e_ident[EI_VERSION] == EV_CURRENT)
	{
		printf("(current)\n");
	}
	else
		printf("\n");
}

/**
 * print_abi - prints ELF header in ABI vesrion
 * @e_ident: pointer array ELABI version
 */
void print_abi(unsigned char *e_ident)
{
	printf("ABI version: %d\n", e_ident[EI_ABIVERSION]);
}

/**
 * print_osabi -  This function returns the OS/ABI of an ELF header.
 * @e_ident: an ELF version pointer array
 */
void print_osabi(unsigned char *e_ident)
{
	printf(" OS/ABI:");

	if (e_ident[EI_OSABI] == ELFOSABI_NONE)
	{
		printf("UNIX - System V\n");
	}
	else if (e_ident[EI_OSABI] == ELFOSABI_HPUX)
	{
		printf("UNIX - HP-UX\n");
	}
	else if (e_ident[EI_OSABI] == ELFOSABI_NETBSD)
	{
		printf("UNIX - NetBSD\n");
	}
	else if (e_ident[EI_OSABI] == ELFOSABI_LINUX)
	{
		printf("UNIX - Linux\n");
	}
	else if (e_ident[EI_OSABI] == ELFOSABI_SOLARIS)
	{
		printf("UNIX - Solaris\n");
	}
	else if (e_ident[EI_OSABI] == ELFOSABI_IRIX)	
	{
		printf("UNIX - IRIX\n");
	}
	else if (e_ident[EI_OSABI] == ELFOSABI_FREEBSD)
	{
		printf("UNIX - FreeBSD\n");	
	}
	else if (e_ident[EI_OSABI] == ELFOSABI_TRU64)
	{
		printf("UNIX - TRU64\n");
	}
	else if (e_ident[EI_OSABI] == ELFOSABI_ARM)
	{
		printf("ARM\n");
	}
	else if (e_ident[EI_OSABI] == ELFOSABI_STANDALONE)
	{
		printf("Standalone App\n");
	}
	else
		printf("<unknown: %x>\n", e_ident[EI_OSABI]);
}

/**
 * print_magic - Prints the ELF header's magic numbers.
 * @e_ident: elf magic number of array pointer
 */

void print_magic(unsigned char *e_ident)
{
	unsigned int m;

	printf("magic: ");
	
	while (m < EI_NIDENT)
	{
		printf("%02x", e_ident[m]);
		if (m == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
		m++;
	}
}

/** 
 * print_class - This function returns the class of an ELF header.
 * @e_ident: an anrray pointer that contain ELF class
 */

void print_class(unsigned char *e_ident)
{
	printf(" Class: ");

	switch (e_ident[EI_CLASS])
	{
		case ELFCLASSNONE:
			printf("none\n");
			break;
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");	
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * print_type - prints type of an ELF header
 * @e_type: type of ELF 
 * @e_ident: an array pointer that contains the ELf class
 */

void print_type(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;
	printf(" Type: ");

	if (e_type == ET_NONE)
	{
		printf("NONE(None)\n");
	}
	else if (e_type == ET_REL)	
	{
		printf("REL(Relocatable file)\n");	
	}
	else if (e_type == ET_EXEC)
	{	
		printf("EXEC(Executable file)\n");
	}
	else if (e_type == ET_DYN)
	{	
		printf("DYN(shared object file)\n");
	}
	else if (e_type == ET_CORE)
	{
		printf("CORE(Core file)\n");
	}
	else

		printf("<unknown: %x>\n", e_type);
}

/**
 * print_entry - that prints enty point of ELF
 * @e_ident: an array pointer that contain ELF class
 * @e_entry: an adress of ELF enty point in the func
 */

void print_entry(unsigned long int e_entry, unsigned char *e_ident)
{
	printf(" Entry point address: ");
	
	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
			((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}
	if (e_ident[EI_CLASS] == ELFCLASS32)
	{
		printf("%#x\n", (unsigned int)e_entry);
	}
	else
	{
		printf("%#lx\n", e_entry);
	}
}

/**
 * close_elf - a function that close ELF file
 * @elf: an ELF file descriptor
 */
void close_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", elf)
;
		exit(98);
	}
}


