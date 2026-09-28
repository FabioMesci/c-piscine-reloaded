/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesci <fmesci@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 11:35:43 by fmesci            #+#    #+#             */
/*   Updated: 2026/09/23 13:49:21 by fmesci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	file_process(int file)
{
	char	bytes[1024];
	int		flag;
	int		size;

	flag = 1;
	while (flag == 1)
	{
		size = read(file, bytes, sizeof(bytes));
		if (size > 0)
			write(1, bytes, size);
		else if (size <= 0)
			flag = 0;
	}
	close(file);
}

int	main(int argc, char **argv)
{
	int	file;

	if (argc == 1)
	{
		write(2, "File name missing.\n", 19);
		return (1);
	}
	else if (argc > 2)
	{
		write(2, "Too many arguments.\n", 20);
		return (1);
	}
	file = open(argv[1], O_RDONLY);
	if (file == -1)
	{
		write(2, "Cannot read file.\n", 18);
		return (1);
	}
	file_process(file);
}
