/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_run_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:56:32 by arasal            #+#    #+#             */
/*   Updated: 2022/12/30 01:13:49 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_table(t_philo_m *m)
{
	if (is_finished(m))
		return (0);
	sem_wait(m->forks);
	if (philo_get_time() <= m->die_time
		&& (m->times_eaten < m->p->numtoeat || m->p->numtoeat == -1))
		ft_eating(m);
	else
	{
		sem_post(m->forks);
		if (philo_get_time() + m->p->timetoeat > m->die_time)
			ft_dying(m);
		return (0);
	}
	if (is_finished(m))
		return (0);
	if (philo_get_time() + m->p->timetosleep > m->die_time)
	{
		m->die_time -= m->p->timetoeat;
		ft_dying(m);
		return (0);
	}
	else
		ft_sleeping(m);
	ft_thinking(m);
	return (1);
}

void	*philo_routine(t_philo_m *m)
{
	pthread_t	thread;

	pthread_create(&thread, NULL, check_death, (void *)m);
	m->die_time = m->p->timeatstart + m->p->timetodie;
	if (m->id % 2 == 0)
		u_wait(philo_get_time() + m->p->timetoeat);
	while (ft_table(m) != 0)
		;
	pthread_join(thread, NULL);
	return (NULL);
}

void	philo_r_create(t_philo_m *philos, t_philo_p *inpparams)
{
	int			i;
	pid_t		id;

	i = 0;
	while (i < inpparams->numofphilo)
	{
		id = fork();
		if (id == 0)
		{
			init_philos(philos, inpparams, i);
			philo_routine(philos);
			return ;
		}
		if (id != -1)
			i++;
	}
	if (id != 0)
		philo_r_wait(inpparams);
	sem_close(philos->dead);
	sem_close(philos->pr);
	sem_close(philos->forks);
	sem_close(philos->finished);
}

void	philo_r_wait(t_philo_p *inpparams)
{
	int	i;

	i = 0;
	while (i < inpparams->numofphilo)
	{
		waitpid(-1, NULL, 0);
		i++;
	}
}

void	*check_death(void *m)
{
	t_philo_m	*philos;

	philos = (t_philo_m *)m;
	while (1)
	{
		if (is_finished(m))
		{
			sem_unlink("/finished");
			kill(0, SIGKILL);
			return (NULL);
		}
		else
		{
			sem_wait(philos->times_eaten_s);
			if (philos->times_eaten == philos->p->numtoeat)
			{
				sem_post(philos->times_eaten_s);
				return (NULL);
			}
			sem_post(philos->times_eaten_s);
		}
	}
}
