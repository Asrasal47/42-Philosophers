/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 06:02:21 by arasal            #+#    #+#             */
/*   Updated: 2022/12/30 01:15:18 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H
# include <semaphore.h>
# include <pthread.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>
# include <signal.h>
# include <fcntl.h>

typedef long long	t_msec;

typedef struct s_philo_p
{
	int			numofphilo;
	t_msec		timetodie;
	t_msec		timetoeat;
	t_msec		timetosleep;
	t_msec		timeatstart;
	int			numtoeat;
}	t_philo_p;

typedef struct s_philo_m
{
	t_philo_p			*p;
	int					id;
	t_msec				die_time;
	sem_t				*forks;
	sem_t				*finished;
	sem_t				*dead;
	sem_t				*times_eaten_s;
	int					times_eaten;
	sem_t				*pr;
}	t_philo_m;

enum	e_print {
	e_fork = 0,
	e_eating = 1,
	e_sleeping = 2,
	e_thinking = 3,
	e_dead = 4
};

//time.c
t_msec	philo_get_time(void);
void	u_wait(t_msec waiting_time);
//my_atoi.c
int		my_atoi(const char *str, int *n);
int		check_int(int sign, int *n);
//my_atoll.c
int		my_atoll(const char *str, t_msec *n);
int		check_ll(int sign, t_msec *n);
//philo_utils.c
void	init_philos(t_philo_m *philos, t_philo_p *inpparams, int i);
int		philo_r_init(t_philo_m *philos, t_philo_p *inpparams);
void	ft_printing(t_philo_m *m, enum e_print print);
int		is_finished(t_philo_m *m);
//philo_run.c
int		ft_table(t_philo_m *m);
void	*philo_routine(t_philo_m *m);
void	philo_r_create(t_philo_m *philos, t_philo_p *inpparams);
void	philo_r_wait(t_philo_p *inpparams);
void	*check_death(void *m);
//philo_actions.c
void	ft_eating(t_philo_m *m);
void	ft_sleeping(t_philo_m *m);
void	ft_thinking(t_philo_m *m);
void	ft_dying(t_philo_m *m);

#endif