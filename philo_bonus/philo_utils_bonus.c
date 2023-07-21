/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 01:17:07 by arasal            #+#    #+#             */
/*   Updated: 2022/12/30 01:29:15 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	init_philos(t_philo_m *philos, t_philo_p *inpparams, int i)
{
	philos->id = i;
	philos->times_eaten = 0;
	philos->p = inpparams;
}

int	philo_r_init(t_philo_m *philos, t_philo_p *inpparams)
{
	sem_unlink("/forks");
	sem_unlink("/pr");
	sem_unlink("/dead");
	sem_unlink("/times_eaten_s");
	sem_unlink("/finished");
	philos->forks = sem_open("/forks", O_CREAT, 0644, inpparams->numofphilo);
	philos->times_eaten_s = sem_open("/times_eaten_s", O_CREAT, 0644, 1);
	philos->dead = sem_open("/dead", O_CREAT, 0644, 1);
	philos->pr = sem_open("/pr", O_CREAT, 0644, 1);
	sem_unlink("/forks");
	sem_unlink("/pr");
	sem_unlink("/dead");
	sem_unlink("/times_eaten_s");
	return (0);
}

void	ft_printing(t_philo_m *m, enum e_print print)
{
	const char	*msg[] = {
		"has taken a fork", "is eating", "is sleeping",
		"is thinking", "died"};

	if (is_finished(m))
		return ;
	sem_wait(m->dead);
	if (print == 4)
		m->finished = sem_open("/finished", O_CREAT, 0644, 9999);
	sem_post(m->dead);
	sem_wait(m->pr);
	printf("%lld %d %s\n", philo_get_time() - m->p->timeatstart, m->id + 1,
		msg[(int)print]);
	sem_post(m->pr);
}

int	is_finished(t_philo_m *m)
{
	sem_t	*finished;

	sem_wait(m->dead);
	finished = sem_open("/finished", 0);
	if (finished == SEM_FAILED)
	{
		sem_post(m->dead);
		return (0);
	}
	sem_close(finished);
	sem_post(m->dead);
	return (1);
}
