/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmatch_wcomments.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amendelo <amendelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 16:09:56 by amendelo          #+#    #+#             */
/*   Updated: 2018/11/13 15:02:45 by amendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/*
** The aim of this function is to count the amount of times two strings match.
** When we have two or more stars, multiple string combinations can be suitable.
** nmatch calculates the total amount of combinations.
** Here are some examples :
**		 "abcbd" & "*b*" match twice : ("a","cbd") and ("abc", "d")
*		 "abc" & "a**" match 3 times : (nothing,"bc"), ("b", "c") and ("bc", nothing)
*/

int		nmatch(char *s1, char *s2)
{
	// if reached the end of both strings, or both strings are empty
	//		to begin with, return a match
	if (*s1 == '\0' && *s2 == '\0')
		return (1);
	// if at the end of s1 but not s2...
	if (*s1 == '\0')
	{
		// ...if current place of s2 is a *...
		if (*s2 == '*')
			// ...iterate s2 forward one place. Otherwise...
			return (nmatch(s1, ++s2));
		else
			// ...the strings do not match.
			return (0);
	}
	// if we're in the middle of s1 and current place of s2 is a *...
	if (*s2 == '*')
		// pass through iterating through s2 and iterating through s1.
		//		• first, we iterate through s1. this will tell us how many
		//		  "matches" we can make with that one star.
		//		• then, we iterate through s2, to see if the 
		//		  remainder of s1 matches s2, ignoring all stars.
		//			- if we get past the stars and they don't match,
		//			  this will return 0.
		return (nmatch(s1 + 1, s2) + nmatch(s1, s2 + 1));
	// if both places of the string are equal, go to the next place.
	if (*s1 == *s2)
		return (nmatch(++s1, ++s2));
	return (0);
}
