/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 06:08:53 by arasal            #+#    #+#             */
/*   Updated: 2022/12/29 21:48:54 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	usage(void)
{
	printf("Invalid Argument\nUsage: program_name number_of_philosophers "
		"time_to_die time_to_eat time_to_sleep"
		" [number_of_times_each_philosopher_must_eat]\n");
}

int	save_variables(int argc, char **argv, t_philo_p *inpparams)
{
	inpparams->numtoeat = -1;
	if (argc != 6 && argc != 5)
		return (1);
	if (my_atoi(argv[1], &inpparams->numofphilo))
		return (1);
	if (my_atoll(argv[2], &inpparams->timetodie))
		return (1);
	if (my_atoll(argv[3], &inpparams->timetoeat))
		return (1);
	if (my_atoll(argv[4], &inpparams->timetosleep))
		return (1);
	if (argc == 6)
	{
		if (my_atoi(argv[5], &inpparams->numtoeat))
			return (1);
	}
	if (inpparams->numofphilo == 0 || inpparams->numtoeat == 0)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_philo_p	inpparams;
	t_philo_m	philos;

	if (save_variables(argc, argv, &inpparams))
	{
		usage();
		return (0);
	}
	inpparams.timeatstart = philo_get_time();
	philo_r_init(&philos, &inpparams);
	if (inpparams.numofphilo == 1)
	{
		printf("%lld %d %s\n", (long long)0, 1, "has taken a fork");
		u_wait(inpparams.timeatstart + inpparams.timetodie);
		printf("%lld %d died\n", philo_get_time() - inpparams.timeatstart, 1);
		return (0);
	}
	philo_r_create(&philos, &inpparams);
	sem_unlink("/forks");
	sem_unlink("/pr");
	sem_unlink("/dead");
	sem_unlink("/finished");
	return (0);
}
