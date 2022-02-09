/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejinam <yejinam@42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 12:10:24 by yejinam           #+#    #+#             */
/*   Updated: 2022/02/09 13:11:31 by yejinam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	char	*strtmp;
	char	*tftmp;

	tftmp = to_find;
	while(*str)
	{
		if(!*to)
		while(*str != *to_find)
			str++;
		tmp = str;
		while(*str && *to_find)
		{
			if (*str != *to_find)
				break;
			str++;
			to_find++;
		}
		if(!*str && !*to_find)
			break;
		str = tmp + 1;
		to_find = tftmp;
	}
	if(!*str && *to_find)
		return (NULL);
	return (strtmp);
}
