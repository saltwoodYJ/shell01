/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yenam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 10:29:09 by yenam             #+#    #+#             */
/*   Updated: 2022/02/09 11:44:41 by yejinam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_alphabet(char c)
{
	if ('a' <= c && c <= 'z')
		return (1);
	if ('A' <= c && c <= 'Z')
		return (2);
	if ('0' <= c && c <= '9')
		return (3);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int		flag;
	char	*tmp;

	tmp = str;
	flag = 1;
	while (*str)
	{
		if (is_alphabet(*str))
		{
			if (flag == 0 && is_alphabet(*str) == 2)
				*str += 32;
			else if (flag == 1 && is_alphabet(*str) == 1)
				*str -= 32;
			flag = 0;
		}
		else
			flag = 1;
		str++;
	}
	return (tmp);
}
