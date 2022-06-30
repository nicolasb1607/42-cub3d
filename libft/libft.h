/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:37:34 by nburat-d          #+#    #+#             */
/*   Updated: 2022/06/30 09:53:46 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_dlist
{
	void			*content;
	struct s_dlist	*prev;
	struct s_dlist	*next;
}					t_dlist;

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_is_int(char *str);
int		ft_isprint(int c);
int		ft_containchar(char c, char *str);
size_t	ft_strlen(const char *s);
int		ft_tablen(char **tab);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memset_char(void *s, char c, size_t n);
void	*ft_memset_char_bis(void *s, char c, int n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strncpy(char *str, int n);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strcmp(char *s1, char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *to_search, const char *to_find, size_t len);
int		ft_atoi(const char *nptr);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *s);
char	*ft_strdup_no_nl(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_charjoin(char *str, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr(int n);
void	ft_putnbr_fd(int n, int fd);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **alst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void*));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void	ft_lstrev(t_list **alst);
void	ft_dlstadd_back(t_dlist **alst, t_dlist *new);
void	ft_dlstadd_front(t_dlist **alst, t_dlist *new);
t_dlist	*ft_dlstlast(t_dlist *lst);
t_dlist	*ft_dlstnew(void *content);
int		ft_dlstsize(t_dlist *lst);
void	ft_dlstclear(t_dlist **lst, void (*del)(void*));
void	ft_dlstdelone(t_dlist *lst, void (*del)(void*));
void	ft_dlstiter(t_dlist *lst, void (*f)(void *));
int		ft_is_sp_or_tab(char c);
int		ft_is_space(char c);
void	free_tab(char **tab);
#endif
