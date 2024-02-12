#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <elf.h>
#include <sys/stat.h>
#include <sys/types.h>

void validate_elf_file(unsigned char *magic_numbers);
void display_magic_numbers(unsigned char *magic_numbers);
void display_file_class(unsigned char *magic_numbers);
void display_data_encoding(unsigned char *magic_numbers);
void display_version(unsigned char *magic_numbers);
void display_osabi(unsigned char *magic_numbers);
void display_abi_version(unsigned char *magic_numbers);
void display_file_type(unsigned int file_type, unsigned char *magic_numbers);
void display_entry_point(unsigned long int entry_point, unsigned char *magic_numbers);
void close_file(int fd);

/**
 * validate_elf_file - Checks if a file is an ELF file.
 * @magic_numbers: A pointer to an array containing the ELF magic numbers.
 *
 * Description: If the file is not an ELF file, exit with code 98.
 */
void validate_elf_file(unsigned char *magic_numbers)
{
	for (int i = 0; i < 4; i++)
	{
		if (magic_numbers[i] != 127 &&
			magic_numbers[i] != 'E' &&
			magic_numbers[i] != 'L' &&
			magic_numbers[i] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * display_magic_numbers - Displays the magic numbers of an ELF header.
 * @magic_numbers: A pointer to an array containing the ELF magic numbers.
 *
 * Description: Magic numbers are separated by spaces.
 */
void display_magic_numbers(unsigned char *magic_numbers)
{
	printf("  Magic:   ");

	for (int i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x", magic_numbers[i]);

		if (i == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * display_file_class - Displays the class of an ELF header.
 * @magic_numbers: A pointer to an array containing the ELF class.
 */
void display_file_class(unsigned char *magic_numbers)
{
	printf("  Class:                             ");

	switch (magic_numbers[EI_CLASS])
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
			printf("<unknown: %x>\n", magic_numbers[EI_CLASS]);
	}
}

/**
 * display_data_encoding - Displays the data encoding of an ELF header.
 * @magic_numbers: A pointer to an array containing the ELF class.
 */
void display_data_encoding(unsigned char *magic_numbers)
{
	printf("  Data:                              ");

	switch (magic_numbers[EI_DATA])
	{
		case ELFDATANONE:
			printf("none\n");
			break;
		case ELFDATA2LSB:
			printf("2's complement, little endian\n");
			break;
		case ELFDATA2MSB:
			printf("2's complement, big endian\n");
			break;
		default:
			printf("<unknown: %x>\n", magic_numbers[EI_CLASS]);
	}
}

/**
 * display_version - Displays the version of an ELF header.
 * @magic_numbers: A pointer to an array containing the ELF version.
 */
void display_version(unsigned char *magic_numbers)
{
	printf("  Version:                           %d", magic_numbers[EI_VERSION]);

	switch (magic_numbers[EI_VERSION])
	{
		case EV_CURRENT:
			printf(" (current)\n");
			break;
		default:
			printf("\n");
			break;
	}
}

/**
 * display_osabi - Displays the OS/ABI of an ELF header.
 * @magic_numbers: A pointer to an array containing the ELF version.
 */
void display_osabi(unsigned char *magic_numbers)
{
	printf("  OS/ABI:                            ");

	switch (magic_numbers[EI_OSABI])
	{
		case ELFOSABI_NONE:
			printf("UNIX - System V\n");
			break;
		case ELFOSABI_HPUX:
			printf("UNIX - HP-UX\n");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD\n");
			break;
		case ELFOSABI_LINUX:
			printf("UNIX - Linux\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris\n");
			break;
		case ELFOSABI_IRIX:
			printf("UNIX - IRIX\n");
			break;
		case ELFOSABI_FREEBSD:
			printf("UNIX - FreeBSD\n");
			break;
		case ELFOSABI_TRU64:
			printf("UNIX - TRU64\n");
			break;
		case ELFOSABI_ARM:
			printf("ARM\n");
			break;
		case ELFOSABI_STANDALONE:
			printf("Standalone App\n");
			break;
		default:
			printf("<unknown: %x>\n", magic_numbers[EI_OSABI]);
	}
}

/**
 * display_abi_version - Displays the ABI version of an ELF header.
 * @magic_numbers: A pointer to an array containing the ELF ABI version.
 */
void display_abi_version(unsigned char *magic_numbers)
{
	printf("  ABI Version:                       %d\n", magic_numbers[EI_ABIVERSION]);
}

/**
 * display_file_type - Displays the type of an ELF header.
 * @file_type: The ELF type.
 * @magic_numbers: A pointer to an array containing the ELF class.
 */
void display_file_type(unsigned int file_type, unsigned char *magic_numbers)
{
	if (magic_numbers[EI_DATA] == ELFDATA2MSB)
		file_type >>= 8;

	printf("  Type:                              ");

	switch (file_type)
	{
		case ET_NONE:
			printf("NONE (None)\n");
			break;
		case ET_REL:
			printf("REL (Relocatable file)\n");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file)\n");
			break;
		case ET_DYN:
			printf("DYN (Shared object file)\n");
			break;
		case ET_CORE:
			printf("CORE (Core file)\n");
			break;
		default:
			printf("<unknown: %x>\n", file_type);
	}
}

/**
 * display_entry_point - Displays the entry point of an ELF header.
 * @entry_point: The address of the ELF entry point.
 * @magic_numbers: A pointer to an array containing the ELF class.
 */
void display_entry_point(unsigned long int entry_point, unsigned char *magic_numbers)
{
	printf("  Entry point address:               ");

	if (magic_numbers[EI_DATA] == ELFDATA2MSB)
	{
		entry_point = ((entry_point << 8) & 0xFF00FF00) |
			((entry_point >> 8) & 0xFF00FF);
		entry_point = (entry_point << 16) | (entry_point >> 16);
	}

	if (magic_numbers[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)entry_point);
	else
		printf("%#lx\n", entry_point);
}

/**
 * close_file - Closes a file.
 * @fd: The file descriptor of the file to be closed.
 *
 * Description: If the file cannot be closed, exit with code 98.
 */
void close_file(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(98);
	}
}

/**
 * main - Displays the information contained in the
 *        ELF header at the start of an ELF file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the file is not an ELF file or
 *              the function fails, exit with code 98.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int file_descriptor, read_result;

	file_descriptor = open(argv[1], O_RDONLY);
	if (file_descriptor == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}

	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_file(file_descriptor);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}

	read_result = read(file_descriptor, header, sizeof(Elf64_Ehdr));
	if (read_result == -1)
	{
		free(header);
		close_file(file_descriptor);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	validate_elf_file(header->e_ident);
	printf("ELF Header:\n");
	display_magic_numbers(header->e_ident);
	display_file_class(header->e_ident);
	display_data_encoding(header->e_ident);
	display_version(header->e_ident);
	display_osabi(header->e_ident);
	display_abi_version(header->e_ident);
	display_file_type(header->e_type, header->e_ident);
	display_entry_point(header->e_entry, header->e_ident);

	free(header);
	close_file(file_descriptor);
	return (0);
}
